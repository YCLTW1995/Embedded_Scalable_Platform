#include "system.hpp"

#include "register_map.hpp"
#include "sha_pv.c"
// -- Functions

void system_t::load_regs(void)
{
    // -- Pointers to the memory

    // Set address in bytes (assuming memory->data is 32-bits word addressed)
    assert(driver->do_write(IN_DATA_BASE_ADDR_REG, in_data_addr * 4));
   // assert(driver->do_write(IN_COEFF_BASE_ADDR_REG, in_coeff_addr * 4));
   // assert(driver->do_write(OUT_DATA_BASE_ADDR_REG, out_data_addr * 4));

    // -- Configuration parameters
   // assert(driver->do_write(NSAMPLES_REG, NSAMPLES));
   // assert(driver->do_write(NITERS_REG, NITERS));

}
void system_t::load_original_data(void)
{
    //Allocate Memory 
    uint32_t in_data_addr = 0 ;
    uint32_t in_data_size = 100 ;
    uint32_t mem_size = in_data_size ;
    memory->data = new sc_dt::sc_bv<32>[mem_size];
    //Generate Sample Test input and send it to memory
    //!!!!!THIS IS ONLY TEST ON IF SYSTEMC WORKS 
    for (int i = 0; i < in_data_size; i++) {
        uint32_t mem_addr = in_data_addr + i;
        int32_t tmpData = rand();
        memory->data[mem_addr] = tmpData;
    }
}
void system_t::load_memory(void)
{
    // ======================   ^
    // |     input_data     |   | NSAMPLES * NITERS * sizeof(int32_t)
    // ======================   -
    // |     input coeff    |   | NSAMPLES * NITERS * sizeof(int16_t)
    // ======================   -
    // |     output data    |   | NITERS * sizeof(int64_t)
    // ======================   v

    run_programmer_view(); 

    // -- Compute golden output



    //wait();
    REPORT_INFO("Load memory completed");
}

void system_t::dump_memory(void)
{

    REPORT_INFO("Dump memory completed");
}

void system_t::validate(void)
{

    REPORT_INFO("SHA Validate");
}

void system_t::clean_up(void)
{
    delete[] memory->data;
}