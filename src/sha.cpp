/* Copyright 2018 Columbia University SLD Group */

#include "sha.hpp"

// -- Functions (regs)

#include "sha_regs.hpp"

// -- Functions (utils)

#include "sha_utils.hpp"

// -- Functions (kernel)

#include "sha_functions.hpp"

// -- Processes

void sha::load_input(void)
{
    bool ping_pong;
    //uint32_t niters;

    // Reset
    {
        HLS_DEFINE_PROTOCOL("load-input-reset");

        dma_initiator.archan->reset_put();
        dma_initiator.rchan->reset_get();

        input_ready.req.reset_req();

        ping_pong = false;

        wait();
    }

    // Config
    {
        HLS_DEFINE_PROTOCOL("load-input-config");

        wait_for_config(); // memory-mapped regs

        //niters = niters_sig.read();
    }

    { // LOAD 
        printf("SHA.CPP LOADING INPUT\n");
        int index = 0 ;
        int num_w_cols = 1 ;
        for (uint32_t i = 0; i < 100; i++) {

            // Load
            if(ping_pong){
                load_data(in_data_buf_1,index);
            }
            else {
                load_data(in_data_buf_2,index);
            }
            

            // Handshake with compute
            load_compute_handshake();

            // Update pingpong var
            ping_pong = !ping_pong;
            // update mem address 
            index += (num_w_cols) << 2 ;
        }
    }
    // Conclude
    {
        HLS_DEFINE_PROTOCOL("load-input-done");

        process_done();
    }

}

void sha::compute_kernel(void)
{
    bool ping_pong;
    //uint32_t niters;

    // Reset
    {
        HLS_DEFINE_PROTOCOL("compute-kernel-reset");

        input_ready.ack.reset_ack();
        output_ready.req.reset_req();

        ping_pong = false;

        wait();
    }

    // Config
    {
        HLS_DEFINE_PROTOCOL("compute-kernel-config");

        wait_for_config(); // memory-mapped regs

        //niters = niters_sig.read();
    }

    // Compute
    for (uint32_t i = 0; i < 100; i++) {

        // Handshake with load_input
        compute_load_handshake();

        // Execute the computational kernel
        printf("@@@@@@IN SHA.CPP BEFORE RUN DO_SHA\n");
        do_sha(ping_pong);
        printf("@@@@@@IN SHA.CPP BEFORE RUN DO_SHA\n");
        // Update pingpong var
        ping_pong = !ping_pong;

        // Handshake with store_output
        compute_store_handshake();
    }

    // Conclude
    {
        HLS_DEFINE_PROTOCOL("compute-kernel-done");

        process_done();
    }

}

void sha::store_output(void)
{
    bool ping_pong;
    //uint32_t niters;

    // Reset
    {
        HLS_DEFINE_PROTOCOL("store-output-reset");

        dma_initiator.awchan->reset_put();
        dma_initiator.wchan->reset_put();
        dma_initiator.bchan->reset_get();

        output_ready.ack.reset_ack();

        ping_pong = false;

        irq.write(false);

        wait();
    }

    // Config
    {
        HLS_DEFINE_PROTOCOL("store-output-config");

        wait_for_config(); // memory-mapped regs

        //niters = niters_sig.read();
    }

    // Store
    {
        // TODO: Handshake with compute
        store_compute_handshake();
        // TODO: Store the data
       uint32_t out_base_addr = 0 ;
       uint32_t out_size = 0 ; // use signal read in future 
        store_data(output,out_base_addr) ;
    }

    // Conclude
    {
        HLS_DEFINE_PROTOCOL("store-output-done");

        // Set IRQ
        irq.write(true);

        // Wait for IRQ clear
        clear_irq();

        process_done();
    }

}