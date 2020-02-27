/* Copyright 2019 Columbia University SLD Group */

#ifndef __DRIVER_HPP__
#define __DRIVER_HPP__

// Forward declaration
class system_t;

#include "axi_traits.hpp"

class driver_t : public sc_module
{
public:

    // -- Input ports

    // TODO: Define the input ports
    sc_in <bool> clk ;
    sc_in <bool> rst ;
    sc_in <bool> irq ;

    // -- Communication channels

    // TODO: Define the reg AXI channel
    reg_initiator_t reg_initiator;
    // -- References to other modules

    // To call the system functions
    system_t *system_ref;

    // -- Module constructor

    SC_HAS_PROCESS(driver_t);
    driver_t(sc_module_name name)
        : sc_module(name)
        // TODO: Initialize other ports and member variables
        ,clk("clk")
        ,rst("rst")
        ,irq("irq")
        ,reg_initiator("reg_initiator")
    {
        // TODO: CTHREAD to handle the requests
        // Configure it to match register traits
        SC_THREAD_CLOCK_RESET_TRAITS(driver_thread, clk, rst, reg_if_traits::put_get_traits);
        // TODO: Binding the clock and reset
        reg_initiator.clk_rst(clk, rst);
    }

    // -- Processes

    // To handle read and write requests
    void driver_thread(void);

    // -- Functions (read)

    // To read a particular register
    bool do_read(reg_initiator_t::addr_t addr, reg_initiator_t::data_t &data);

    // -- Functions (write)

    // To write a particular register
    bool do_write(reg_initiator_t::addr_t addr, reg_initiator_t::data_t data);
};

#endif /* __DRIVER_HPP__ */