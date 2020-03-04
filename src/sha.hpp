/* Copyright 2018 Columbia University SLD Group */

#include "utils.hpp"
#include "handshake.hpp"
#include "axi_traits.hpp"

#ifndef __SHA_HPP__
#define __SHA_HPP__

class sha
    : public sc_module
    , public axi4_lite::axi4_lite_single_rw_if<reg_if_traits>
{

public:

    // -- Input ports

    // Clock signal
    sc_in<bool> clk;

    // Reset signal
    sc_in<bool> rst;


    // -- Output ports

    // Interrupt signal
    sc_out<bool> irq;


    // -- Handshakes

    // The input is loaded
    handshake_t input_ready;

    // The output is ready
    handshake_t output_ready;


    // -- AXI (see axi_traits.hpp)

    // Target for the regs
    reg_target_t reg_target;

    // Adaptor for the target
    reg_adaptor_t srw_adaptor;

    // Initiator for dma r/w transactions
    dma_initiator_t dma_initiator;

    // -- Constructor

    SC_HAS_PROCESS(sha);
    sha(sc_module_name name)
        : sc_module(name)
        , clk("clk")
        , rst("rst")
        , irq("irq")
        , input_ready("input_ready")
        , output_ready("output_ready")
        , reg_target("reg_target")
        , srw_adaptor("srw_adaptor")
        , dma_initiator("dma_initiator")
        , config_ok_sig("config_ok_sig")
        , cmd_sig("cmd_sig")
        , status_sig("status_sig")
        , in_data_base_addr_sig("in_data_base_addr_sig")
        
    {
        // Process to read the input data
        // Configure it to match dma traits
        SC_THREAD_CLOCK_RESET_TRAITS(load_input, clk, rst, dma_if_traits::put_get_traits);

        // Process to encrypt the input data
        SC_CTHREAD(compute_kernel, clk.pos());
        reset_signal_is(rst, false);

        // Process to store the output data
        SC_THREAD_CLOCK_RESET_TRAITS(store_output, clk, rst, dma_if_traits::put_get_traits);

        // Bind the clock and reset signals
        reg_target.clk_rst(clk, rst);
        dma_initiator.clk_rst(clk, rst);

        // Bind the adaptor to the target
        reg_target.target_port(srw_adaptor);
        srw_adaptor.target_port(*this);

        // Map arrays to registers (flatten)
        HLS_FLATTEN_ARRAY(in_data_buf_1);
        HLS_FLATTEN_ARRAY(in_data_buf_2);
        
    }

    // -- Processes

    // Load input from memory
    void load_input(void);

    // Perform the computation
    void compute_kernel(void);

    // Store output in memory
    void store_output(void);

    // -- Functions (kernel)
    void do_sha(bool ping_pong);


    // -- Functions (utils)

    // Wait for configuration
    inline void wait_for_config(void);

    // The accelerator is done
    inline void set_irq(void);

    // Wait for IRQ to be cleard
    inline void clear_irq(void);

    // Process has complete. Wait for reset.
    inline void process_done(void);

    // Handshake callable by load_input
    inline void load_compute_handshake(void);

    // Handshake callable by compute_kernel
    inline void compute_load_handshake(void);

    // Handshake callable by compute_kernel
    inline void compute_store_handshake(void);

    // Handshake callable by store_output
    inline void store_compute_handshake(void);

    // To read the input data
    void load_data(int32_t arr[100], uint32_t mem_base);

    // To store the output data
    void store_data(int32_t arr[100], uint32_t mem_base);


    // -- Functions (registers)

    // To reset the read side
    virtual void reset_single_read(void);

    // To read a register
    virtual void single_read(reg_target_t::archan_t &archan,
                             reg_target_t::rchan_t &rchan);

    // To know if we support single read
    virtual bool can_single_read(void) const;

    // To reset the write side
    virtual void reset_single_write(void);

    // To write a register
    virtual void single_write(reg_target_t::awchan_t &awchan,
                              const reg_target_t::wchan_t &wchan,
                              reg_target_t::bchan_t &bchan);

    // To know if we support single write
    virtual bool can_single_write(void) const;


    // -- Private memories

    int32_t in_data_buf_1[100] ; // testing on if SystemC works 
    int32_t in_data_buf_2[100] ;
    int32_t output[100] ;
    //int32_t in_data_buf[2][MAX_SAMPLES];
    //int16_t in_coeff_buf[2][MAX_SAMPLES];


    // -- Private registers

    //int64_t accumulation[2];
    sc_signal<bool> config_ok_sig;


    // -- Configuration registers

    sc_signal<uint32_t> cmd_sig;
    sc_signal<uint32_t> status_sig;
    sc_signal<uint32_t> in_data_base_addr_sig;
    //sc_signal<uint32_t> in_coeff_base_addr_sig;
    //sc_signal<uint32_t> out_data_base_addr_sig;
    //sc_signal<uint32_t> nsamples_sig;
    //sc_signal<uint32_t> niters_sig;
};

#endif /* __MAC_HPP__ */