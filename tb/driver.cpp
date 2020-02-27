/* Copyright 2019 Columbia University SLD Group */

#include "utils.hpp"
#include "driver.hpp"
#include "system.hpp"

#include "register_map.hpp"

// -- Processes

void driver_t::driver_thread(void)
{
    // Reset

    {
        // TODO: Reset the AXI channels
        reg_initiator.awchan->reset_put();
        reg_initiator.archan->reset_put();
        reg_initiator.wchan->reset_put();
        reg_initiator.rchan->reset_get();
        reg_initiator.bchan->reset_get();
        wait();
    }

    const reg_initiator_t::addr_t addr_cmd = CMD_REG;
    const reg_initiator_t::data_t clearirq = ACCELERATOR_CMD_CLEARIRQ;
    const reg_initiator_t::data_t go = ACCELERATOR_CMD_GO;

    // Configure

    {
        // TODO: Load the memory
        //  -- call a function with system_ref
        system_ref->load_memory();
        // TODO: Load the registers
        //  -- call a function with system_ref
        system_ref->load_regs();
        assert(do_write(addr_cmd, go));

        wait();
    }

    // Computation

    {
        sc_time e_begin_time = sc_time_stamp();
        reg_initiator_t::data_t rdata;
        REPORT_TIME(e_begin_time, "BEGIN - fc_layer");

        // TODO: Wait for the accelerator to finish
        do { wait(); } while (!irq.read());
        assert(do_read(addr_cmd, rdata));
        assert(rdata == go);
        do_write(addr_cmd, clearirq);


        sc_time e_end_time = sc_time_stamp();
        REPORT_TIME(e_end_time, "END - fc_layer");

        // TODO: Dump the memory
        //  -- call a function with system_ref
        system_ref->dump_memory();
        system_ref->validate();
        
        // Validate the results 
        system_ref->validate();
    }

    // Conclude

    {
        system_ref->clean_up();

        sc_stop();
    }
}

// -- Functions (read)

bool driver_t::do_read(reg_initiator_t::addr_t addr, reg_initiator_t::data_t &data)
{
    data = 0;
    reg_initiator_t::archan_t archan;
    reg_initiator_t::rchan_t rchan;

    archan.addr = addr;

    while (!reg_initiator.archan->nb_put(archan)) { wait(); }

    wait(); // To avoid error nb_get called multiple times

    while (!reg_initiator.rchan->nb_get(rchan)) { wait(); }

    data = rchan.data;

    return (rchan.resp == axi4_lite::AXI_OK_RESPONSE);
}

// -- Functions (write)

bool driver_t::do_write(reg_initiator_t::addr_t addr, reg_initiator_t::data_t data)
{
    reg_initiator_t::awchan_t awchan;
    reg_initiator_t::wchan_t wchan;
    reg_initiator_t::bchan_t bchan;

    awchan.addr = addr;

    while (!reg_initiator.awchan->nb_put(awchan)) { wait(); }

    wchan.data = data;

    while (!reg_initiator.wchan->nb_put(wchan)) { wait(); }

    do
    {
        wait();
    } while (!reg_initiator.bchan->nb_get(bchan));

    return (bchan.resp == axi4_lite::AXI_OK_RESPONSE);
}