/* Copyright 2019 Columbia University SLD Group */

#include "register_map.hpp"

#ifndef __SHA_UTILS_HPP__
#define __SHA_UTILS_HPP__

inline void sha::load_compute_handshake(void)
{
    {
        HLS_DEFINE_PROTOCOL("load-compute-handshake");

        input_ready.req.req();
    }
}

inline void sha::compute_load_handshake(void)
{
    {
        HLS_DEFINE_PROTOCOL("compute-load-handshake");

        input_ready.ack.ack();
    }
}

inline void sha::compute_store_handshake(void)
{
    {
        HLS_DEFINE_PROTOCOL("compute-store-handshake");

        output_ready.req.req();
    }
}

inline void sha::store_compute_handshake(void)
{
    {
        HLS_DEFINE_PROTOCOL("store-compute-handshake");

        output_ready.ack.ack();
    }
}

void sha::wait_for_config(void)
{
    while (!config_ok_sig.read())
        wait();
}

void sha::clear_irq(void)
{
    do { wait(); }
    while (cmd_sig.read() != ACCELERATOR_CMD_CLEARIRQ);

    irq.write(false);
}

void sha::set_irq(void)
{
}


void sha::process_done(void)
{
    while (true)
        wait();
}

#define AXI4_BURST_MAX_LEN 16

void sha::load_data(int32_t array[100], uint32_t mem_base)
{

    

    // Load in_data
    // TODO Implement this function
    dma_initiator_t::archan_t archan;
    archan.burst = axi4::AXI_INCR_ADDR_BURST;
    uint32_t index = 0 ;
    uint32_t beat_id = 1 ;
    uint32_t mem_off = mem_base ;
    uint32_t plm_index = 0 ;
    uint32_t size = 100 ;
    index = size ;
    while(index>0 ){
        HLS_DEFINE_PROTOCOL("load-data-protocol");
        uint32_t beats ;
        if(index < AXI4_BURST_MAX_LEN) beats = index ;
        else beats = AXI4_BURST_MAX_LEN ;
        archan.tid = beat_id;
        archan.len = beats - 1;
        archan.addr = mem_off;
        while (!dma_initiator.archan->nb_put(archan)) { wait(); }
        for(uint32_t j = 0 ; j < beats ; ++j){
            dma_initiator_t::rchan_t rchan;
            while (!dma_initiator.rchan->nb_get(rchan)) { wait(); }
            array[ plm_index + j ] = rchan.data ;
            wait(); /// NOT SURE IF WE NEED THIS WAIT OR NOT
        }

        mem_off += beats * (DATA_WIDTH / 8);
        index -= beats;
        plm_index += beats ;
        ++beat_id;

        wait();
    }
}


void sha::store_data(int32_t array[100], uint32_t mem_base)
{

    dma_initiator_t::awchan_t awchan;
    awchan.burst = axi4::AXI_INCR_ADDR_BURST;
    uint32_t index = 0 ;
    uint32_t beat_id = 1 ;
    uint32_t mem_off = mem_base ;
    uint32_t plm_index = 0 ;
    uint32_t size = 100 ;
    index = size ;
    while( index>0 ){
        HLS_DEFINE_PROTOCOL("write-data-protocol");
        uint32_t beats ;
        if(index < AXI4_BURST_MAX_LEN) beats = index ;
        else beats = AXI4_BURST_MAX_LEN ;
        awchan.tid = beat_id;
        awchan.len = beats - 1;
        awchan.addr = mem_off;
        while (!dma_initiator.awchan->nb_put(awchan)) { wait(); }
        for(uint32_t j = 0 ; j < beats ; ++j ){
            dma_initiator_t::wchan_t wchan;
            wait() ;
            wchan.data = array[plm_index + j];
            wchan.last = (j == beats - 1);
            wchan.tid = awchan.tid;
            while(!dma_initiator.wchan->nb_put(wchan)) { wait(); }

            wait();
        }
        dma_initiator_t::bchan_t bchan;

        while (!dma_initiator.bchan->nb_get(bchan)) { wait(); }
        mem_off += (beats  * (DATA_WIDTH / 8));
        index -= beats;
        ++beat_id ; 
        plm_index += beats ; 
        wait() ;
    }
}

#endif // __MAC_UTILS_HPP__