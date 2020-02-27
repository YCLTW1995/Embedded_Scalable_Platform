/* Copyright 2019 Columbia University SLD Group */

#ifndef __MEMORY_HPP__
#define __MEMORY_HPP__

#include "axi_traits.hpp"

class memory_t : public sc_module,
    axi4::axi4_multi_rw_if< dma_if_traits >
{

    public:

        // -- Input ports

        // TODO: Define the input ports
        sc_in <bool> clk ;
        sc_in <bool> rst ;
        // -- Communication channels

        // TODO: Define the AXI channel
        dma_target_t dma_target;
        // TODO: Define the AXI adaptor
        dma_adaptor_t mrw_adaptor;
        // -- Constructor

        SC_HAS_PROCESS(memory_t);
        memory_t(sc_module_name name)
            : sc_module(name)
            // TODO: Initialize other ports and member variables
            , clk("clk")
            , rst("rst")
            , dma_target("dma_target")
            , mrw_adaptor("mrw_adaptor")
        {
            // TODO: Binding the communication channels
            dma_target.target_port(mrw_adaptor);
            mrw_adaptor.target_port(*this);
            // TODO: Binding the clock and reset
            dma_target.clk_rst(clk, rst);
        }

        // -- Functions (read)

        // To reset the read side
        virtual void reset_multi_read();

        // To actually perform the read
        bool do_read(dma_target_t::data_t &val, unsigned index);

        // To read the data from memory
        virtual void multi_read(archan_t &archan, dma_target_t::rchan_t
                                &rchan, bool &buresetn_done);

        // To know if we support multiple read
        virtual bool can_multi_read() const;

        // -- Functions (write)

        // To reset the write side
        virtual void reset_multi_write();

        // To actually perform the write
        bool do_write(dma_target_t::data_t val, unsigned index);

        // To write the data to memory
        virtual void multi_write(dma_target_t::awchan_t &awchan, const
                                 dma_target_t::wchan_t &wchan, dma_target_t::bchan_t
                                 &bchan, bool &buresetn_done);

        // To know if we support multiple write
        virtual bool can_multi_write() const;

        // -- Private data

        // Internal model of the main memory
        sc_dt::sc_bv<32> *data;
};

#endif /* __MEMORY_HPP__ */