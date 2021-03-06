/* Copyright (c) 2011-2019 Columbia University, System Level Design Group */
/* SPDX-License-Identifier: Apache-2.0 */

#ifndef __riscv
#include <stdio.h>
#include <stdlib.h>
#endif
#include <esp_accelerator.h>
#include <esp_probe.h>
#include <stdio.h>
#include <stdlib.h>
typedef int32_t token_t;

static unsigned DMA_WORD_PER_BEAT(unsigned _st)
{
        return (sizeof(void *) / _st);
}



#define SLD_SHA 0x18A
#define DEV_NAME "sld,sha"

/* <<--params-->> */
const int32_t input_size = 8192;
const int32_t input_v_size = 2;

static unsigned in_words_adj;
static unsigned out_words_adj;
static unsigned in_len;
static unsigned out_len;
static unsigned in_size;
static unsigned out_size;
static unsigned out_offset;
static unsigned mem_size;

/* Size of the contiguous chunks for scatter/gather */
#define CHUNK_SHIFT 20
#define CHUNK_SIZE BIT(CHUNK_SHIFT)
#define NCHUNK(_sz) ((_sz % CHUNK_SIZE == 0) ?		\
			(_sz / CHUNK_SIZE) :		\
			(_sz / CHUNK_SIZE) + 1)

/* User defined registers */
/* <<--regs-->> */
#define SHA_INPUT_SIZE_REG 0x44
#define SHA_INPUT_V_SIZE_REG 0x40


static int validate_buf(token_t *out, token_t *gold)
{
	int i;
	int j;
	unsigned errors = 0;

	for (i = 0; i < 1; i++)
		for (j = 0; j < 5; j++){
			printf("OUT is %d. GOLD OUT IS %d\n ",out[i * out_words_adj + j],gold[i * out_words_adj + j] );
			if (gold[i * out_words_adj + j] != out[i * out_words_adj + j])
				errors++;
		}

	return errors;
}


static void init_buf (token_t *in, token_t * gold)
{
	int i;
	int j;
/*
	for (i = 0; i < 1; i++)
		for (j = 0; j < input_v_size * input_size; j++)
			in[i * in_words_adj + j] = (token_t) j;

	for (i = 0; i < 1; i++)
		for (j = 0; j < 5; j++)
			gold[i * out_words_adj + j] = (token_t) j;
*/
	#include "data.h"
	printf("INPUT LEN IS %d\n", in[16383]) ;
	/*
	gold[0] = 1360898830;
	gold[1] = 2497166986;
	gold[2] = 999726678;
	gold[3] = 82730304;
	gold[4] = 1431995291;
*//*
	gold[0] = -1399952850;
	gold[1] = 1983227773.;
	gold[2] = 593847421.;
	gold[3] = -954275403;
	gold[4] = -999732414;
	*/
}



int main(int argc, char * argv[])
{
	int i;
	int n;
	int ndev;
	struct esp_device *espdevs;
	struct esp_device *dev;
	unsigned done;
	unsigned **ptable;
	token_t *mem;
	token_t *gold;
	unsigned errors = 0;

	if (DMA_WORD_PER_BEAT(sizeof(token_t)) == 0) {
		in_words_adj = input_v_size * input_size;
		out_words_adj = 5;
	} else {
		in_words_adj = round_up(input_v_size * input_size, DMA_WORD_PER_BEAT(sizeof(token_t)));
		out_words_adj = round_up(5, DMA_WORD_PER_BEAT(sizeof(token_t)));
	}
	in_len = in_words_adj * (1);
	out_len = out_words_adj * (1);
	in_size = in_len * sizeof(token_t);
	out_size = out_len * sizeof(token_t);
	out_offset  = in_len;
	mem_size = (out_offset * sizeof(token_t)) + out_size;


	// Search for the device
#ifndef __riscv
	printf("Scanning device tree... \n");
#else
	print_uart("Scanning device tree... \n");
#endif

	ndev = probe(&espdevs, SLD_SHA, DEV_NAME);
	if (ndev == 0) {
#ifndef __riscv
		printf("sha not found\n");
#else
		print_uart("sha not found\n");
#endif
		return 0;
	}

	for (n = 0; n < ndev; n++) {

		dev = &espdevs[n];

		// Check DMA capabilities
		if (ioread32(dev, PT_NCHUNK_MAX_REG) == 0) {
#ifndef __riscv
			printf("  -> scatter-gather DMA is disabled. Abort.\n");
#else
			print_uart("  -> scatter-gather DMA is disabled. Abort.\n");
#endif
			return 0;
		}

		if (ioread32(dev, PT_NCHUNK_MAX_REG) < NCHUNK(mem_size)) {
#ifndef __riscv
			printf("  -> Not enough TLB entries available. Abort.\n");
#else
			print_uart("  -> Not enough TLB entries available. Abort.\n");
#endif
			return 0;
		}

		// Allocate memory
		gold = aligned_malloc(out_size);
		mem = aligned_malloc(mem_size);
#ifndef __riscv
		printf("  memory buffer base-address = %p\n", mem);
#else
		print_uart("  memory buffer base-address = "); print_uart_addr((uintptr_t) mem); print_uart("\n");
#endif
		// Alocate and populate page table
		ptable = aligned_malloc(NCHUNK(mem_size) * sizeof(unsigned *));
		for (i = 0; i < NCHUNK(mem_size); i++)
			ptable[i] = (unsigned *) &mem[i * (CHUNK_SIZE / sizeof(token_t))];
#ifndef __riscv
		printf("  ptable = %p\n", ptable);
		printf("  nchunk = %lu\n", NCHUNK(mem_size));
#else
		print_uart("  ptable = "); print_uart_addr((uintptr_t) ptable); print_uart("\n");
		print_uart("  nchunk = "); print_uart_int(NCHUNK(mem_size)); print_uart("\n");
#endif

#ifndef __riscv
		printf("  Generate input...\n");
#else
		print_uart("  Generate input...\n");
#endif
		init_buf(mem, gold);

		// Pass common configuration parameters
		printf("  IOWRITE SELEC_REG\n");
		iowrite32(dev, SELECT_REG, ioread32(dev, DEVID_REG));
		printf("  IOWRITE COHERENCE_REG\n");
		iowrite32(dev, COHERENCE_REG, ACC_COH_NONE);
		printf("  IOWRITE PT_ADDRESS_REG\n");
#ifndef __sparc
		iowrite32(dev, PT_ADDRESS_REG, (unsigned long long) ptable);
#else
		iowrite32(dev, PT_ADDRESS_REG, (unsigned) ptable);
#endif
		printf("  IOWRITE PT_NCHUNK_REG\n");
		iowrite32(dev, PT_NCHUNK_REG, NCHUNK(mem_size));
		printf("  IOWRITE PT_SHIFT_REG\n");
		iowrite32(dev, PT_SHIFT_REG, CHUNK_SHIFT);

		// Use the following if input and output data are not allocated at the default offsets
		printf("  IOWRITE SRC_OFFSET_REG\n");
		iowrite32(dev, SRC_OFFSET_REG, 0x0);
		printf("  IOWRITE DST_OFFSET_REG\n");
		iowrite32(dev, DST_OFFSET_REG, 0x0);

		// Pass accelerator-specific configuration parameters
		/* <<--regs-config-->> */
		printf("  IOWRITE SHA_INPUT_SIZE_REG\n");
		iowrite32(dev, SHA_INPUT_SIZE_REG, input_size);
		printf("  IOWRITE SHA_INPUT_V_SIZE_REG\n");
		iowrite32(dev, SHA_INPUT_V_SIZE_REG, input_v_size);

		// Flush (customize coherence model here)
		printf("  ESP_FLUSH ACC_COH_NONE\n");
		esp_flush(ACC_COH_NONE);

		// Start accelerators
#ifndef __riscv
		printf("  Start...\n");
#else
		print_uart("  Start...\n");
#endif
		iowrite32(dev, CMD_REG, CMD_MASK_START);

		// Wait for completion
		done = 0;
		while (!done) {
			done = ioread32(dev, STATUS_REG);
			done &= STATUS_MASK_DONE;
		}
		iowrite32(dev, CMD_REG, 0x0);

#ifndef __riscv
		printf("  Done\n");
		printf("  validating...\n");
#else
		print_uart("  Done\n");
		print_uart("  validating...\n");
#endif

		/* Validation */
		errors = validate_buf(&mem[out_offset], gold);
#ifndef __riscv
		if (errors)
			printf("  ... FAIL\n");
		else
			printf("  ... PASS\n");
#else
		if (errors)
			print_uart("  ... FAIL\n");
		else
			print_uart("  ... PASS\n");
#endif

		aligned_free(ptable);
		aligned_free(mem);
		aligned_free(gold);
	}

	return 0;
}
