#include "libesp.h"
#include "cfg.h"

static unsigned in_words_adj;
static unsigned out_words_adj;
static unsigned in_len;
static unsigned out_len;
static unsigned in_size;
static unsigned out_size;
static unsigned out_offset;
static unsigned size;

/* User-defined code */


static int validate_buffer(token_t *out, token_t *gold)
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


/* User-defined code */
static void init_buffer(token_t *in, token_t * gold)
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
	printf("Input length is %d\n", in[16383]);
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


/* User-defined code */
static void init_parameters()
{
	if (DMA_WORD_PER_BEAT(sizeof(token_t)) == 0) {
		in_words_adj = input_v_size * input_size;
		out_words_adj = 5;
	} else {
		in_words_adj = round_up(input_v_size * input_size, DMA_WORD_PER_BEAT(sizeof(token_t)));
		out_words_adj = round_up(5, DMA_WORD_PER_BEAT(sizeof(token_t)));
	}
	in_len = in_words_adj * (1);
	out_len =  out_words_adj * (1);
	in_size = in_len * sizeof(token_t);
	out_size = out_len * sizeof(token_t);
	out_offset = in_len;
	size = (out_offset * sizeof(token_t)) + out_size;
}


int main(int argc, char **argv)
{
	int errors;

	token_t *gold;
	token_t *buf;

	init_parameters();

	buf = (token_t *) esp_alloc(size);
	gold = malloc(out_size);

	init_buffer(buf, gold);

	printf("\n====== %s ======\n\n", cfg_000[0].devname);
	/* <<--print-params-->> */
	printf("  .input_size = %d\n", input_size);
	printf("  .input_v_size = %d\n", input_v_size);
	printf("\n  ** START **\n");

	esp_run(cfg_000, NACC);

	printf("\n  ** DONE **\n");

	errors = validate_buffer(&buf[out_offset], gold);

	free(gold);
	esp_cleanup();

	if (!errors)
		printf("+ Test PASSED\n");
	else
		printf("+ Test FAILED\n");

	printf("\n====== %s ======\n\n", cfg_000[0].devname);

	return errors;
}
