/* Copyright 2019 Columbia University SLD Group */

#ifndef __SYSTEM_HPP__
#define __SYSTEM_HPP__

#include <stdlib.h>
#include <string.h>

#include "utils.hpp"

#include "driver.hpp"
#include "memory.hpp"

#include "axi_traits.hpp"

#include "sha_wrap.h"

class system_t : public sc_module
{
public:

    // -- Modules

    // Memory's model
    memory_t *memory;

    // Driver's model
    driver_t *driver;

    // Accelerator's wrapper
    sha_wrapper *acc;

    // -- Input ports

    // Clock signal
    sc_in<bool> clk;

    // Reset signal
    sc_in<bool> rst;

    // -- Output ports

    // Interrupt signals
    sc_signal<bool> irq;

    // -- Internal Channels

    // Channels to handle the DMA transactions
    axi4::axi4_channel<dma_if_traits> dma_channel;

    // Channels to handle the write/read reqs for the registers
    axi4_lite::axi4_lite_channel<reg_if_traits> reg_channel;

    // -- Constructor

    SC_HAS_PROCESS(system_t);
    system_t(sc_module_name name)
        : sc_module(name)
        , clk("clk")
        , rst("rst")
        , irq("irq")
        , reg_channel("reg_channel")
        , dma_channel("dma_channel")
    {
        // Instantiate the driver's model
        driver = new driver_t("driver");

        // Instantiate the memory's model
        memory = new memory_t("memory");

        // Instantiate the accelerator
        acc = new sha_wrapper("sha");

        // Binding the driver's model
        driver->clk(clk);
        driver->rst(rst);
        driver->irq(irq);
        driver->system_ref = this;
        driver->reg_initiator(reg_channel);

        // Binding the memory's model
        memory->clk(clk);
        memory->rst(rst);
        dma_channel(memory->dma_target);

        // Binding the acceleratorr
        acc->clk(clk);
        acc->rst(rst);
        acc->irq(irq);
        reg_channel(acc->reg_target);
        acc->dma_initiator(dma_channel);
    }

    // -- Functions

    void load_original_data(void) ;

    // Load the value of the registers
    void load_regs(void);

    // Load the input values in memory
    void load_memory(void);

    // Read the output values from memory
    void dump_memory(void);

    // Verify that the results are correct
    void validate(void);

    // Optionally free resources (arrays)
    void clean_up(void);


    // -- Private data

    // Base addresses
    uint32_t in_data_size;
    //uint32_t in_coeff_size;
    //uint32_t out_data_size;

    uint32_t in_data_addr;
    //uint32_t in_coeff_addr;
    //uint32_t out_data_addr;

    uint32_t mem_size; // = sum of all data_size

    uint32_t test[100] ;
};

#endif /* __SYSTEM_HPP__ */