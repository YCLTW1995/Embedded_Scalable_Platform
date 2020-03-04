/* Copyright 2019 Columbia University SLD Group */

#include "utils.hpp"
#include "register_map.hpp"

#ifndef __SHA_REGS_HPP__
#define __SHA_REGS_HPP__

// -- Functions (reg)

void sha::reset_single_read(void)
{
    // Nothing to do
}

void sha::single_read(reg_target_t::archan_t &archan,
                      reg_target_t::rchan_t &rchan)
{
    rchan.resp = axi4_lite::AXI_OK_RESPONSE;

    switch (archan.addr)
    {
        // -- Pointers to memory

    case IN_DATA_BASE_ADDR_REG:
        REPORT_DEBUG("IN_DATA_BASE_ADDR_REG: 0x%08x", in_data_base_addr_sig.read());
        rchan.data = in_data_base_addr_sig.read();
        break;
/*
    case IN_COEFF_BASE_ADDR_REG:
        REPORT_DEBUG("IN_COEFF_BASE_ADDR_REG: 0x%08x", in_coeff_base_addr_sig.read());
        rchan.data = in_coeff_base_addr_sig.read();
        break;

    case OUT_DATA_BASE_ADDR_REG:
        REPORT_DEBUG("OUT_DATA_BASE_ADDR_REG: 0x%08x", out_data_base_addr_sig.read());
        rchan.data = out_data_base_addr_sig.read();
        break;
*/
        // -- Configuration parameter
/*
    case NSAMPLES_REG:
        REPORT_DEBUG("NSAMPLES_REG: 0x%08x", nsamples_sig.read());
        rchan.data = nsamples_sig.read();
        break;
*/
        // -- Status and command registers

    case CMD_REG:
        rchan.data = cmd_sig.read();
        break;

    default:
        REPORT_DEBUG("REGISTER NOT MAPPED");
        rchan.resp = axi4_lite::AXI_SLVERR_RESPONSE;
        break;
    }
}

bool sha::can_single_read(void) const
{
    return true;
}

void sha::reset_single_write(void)
{
    this->config_ok_sig.write(false);

    this->cmd_sig.write(0);
    this->in_data_base_addr_sig.write(0);
    //this->in_coeff_base_addr_sig.write(0);
    //this->out_data_base_addr_sig.write(0);
    //this->nsamples_sig.write(0);
    //this->niters_sig.write(0);
}

#define ALIGNMENT_MASK ((DATA_WIDTH / 8) - 1)

void sha::single_write(reg_target_t::awchan_t &awchan, const
                       reg_target_t::wchan_t &wchan, reg_target_t::bchan_t &bchan)
{
    bchan.resp = axi4_lite::AXI_OK_RESPONSE;

    const uint32_t wdata = wchan.data.to_uint();
    const bool aligned = (wdata & ALIGNMENT_MASK) ? false : true;

    switch (awchan.addr)
    {

    // -- Pointers to memory

    case IN_DATA_BASE_ADDR_REG:
        // We force aligned transactions over the bus
        if (!aligned) {
            REPORT_DEBUG("INVALID ARGUMENT: address is not aligned (w)");
            bchan.resp = axi4_lite::AXI_SLVERR_RESPONSE;
        } else {
            in_data_base_addr_sig = wdata;
            REPORT_DEBUG("IN_DATA_BASE_ADDR_REG: 0x%08x (w)", wdata);
        }
        break;
/*
    case IN_COEFF_BASE_ADDR_REG:
        if (!aligned) {
            REPORT_DEBUG("INVALID ARGUMENT: address is not aligned (w)");
            bchan.resp = axi4_lite::AXI_SLVERR_RESPONSE;
        } else {
            in_coeff_base_addr_sig = wdata;
            REPORT_DEBUG("IN_COEFF_BASE_ADDR_REG: 0x%08x (w)", wdata);
        }
        break;

    case OUT_DATA_BASE_ADDR_REG:
        if (!aligned) {
            REPORT_DEBUG("INVALID ARGUMENT: address is not aligned (w)");
            bchan.resp = axi4_lite::AXI_SLVERR_RESPONSE;
        } else {
            out_data_base_addr_sig = wdata;
            REPORT_DEBUG("OUT_DATA_BASE_ADDR_REG: 0x%08x (w)", wdata);
        }
        break;

*/
    // -- Configuration parameters
/*
    case NSAMPLES_REG:
        if (wdata > MAX_SAMPLES) {
            // PLM cannot store more than MAX_SAMPLES
            REPORT_DEBUG("INVALID ARGUMENT: MAX_SAMPLES is %d (w)", MAX_SAMPLES);
            bchan.resp = axi4_lite::AXI_SLVERR_RESPONSE;
        } else if (wdata % (DATA_WIDTH / 16)) {
            // We force aligned transactions over the bus
            // Note that the input coefficient is a short.
            // Hence one beat on the AXI bus transfers two
            // coefficiets when DATA_WIDTH is 32.
            REPORT_DEBUG("INVALID ARGUMENT: setting nsamples to %u would incur misaligned transactions (w)", wdata);
            bchan.resp = axi4_lite::AXI_SLVERR_RESPONSE;
        } else if (wdata == 0) {
            REPORT_DEBUG("INVALID ARGUMENT: nsamples cannot be 0 (w)");
            bchan.resp = axi4_lite::AXI_SLVERR_RESPONSE;
        } else {
            nsamples_sig = wdata;
            REPORT_DEBUG("NSAMPLES_REG: 0x%08x (w)", wdata);
            if (niters_sig.read() != 0)
                this->config_ok_sig.write(true);
        }
        break;

    case NITERS_REG:
        if (wdata == 0) {
            REPORT_DEBUG("INVALID ARGUMENT: niters cannot be 0 (w)");
            bchan.resp = axi4_lite::AXI_SLVERR_RESPONSE;
        } else {
            niters_sig = wdata;
            REPORT_DEBUG("NITERS_REG: 0x%08x (w)", wdata);
            if (nsamples_sig.read() != 0)
                this->config_ok_sig.write(true);
        }
        break;
*/

    // -- Status and command registers

    case CMD_REG:
        if (wdata == ACCELERATOR_CMD_CLEARIRQ) {
            REPORT_DEBUG("CMD_REG:  0x%08x (w)", wdata);
            this->config_ok_sig.write(false);
            this->cmd_sig.write(wdata);
        } else if (wdata == ACCELERATOR_CMD_GO) {
            REPORT_DEBUG("CMD_REG:  0x%08x (w)", wdata);
            this->config_ok_sig.write(false);
            this->cmd_sig.write(wdata);
        } else {
            REPORT_DEBUG("INVALID COMMAND OR ACCELERATOR NOT IDLE (w)");
            bchan.resp = axi4_lite::AXI_SLVERR_RESPONSE;
        }
        break;

    default:
        REPORT_DEBUG("REGISTER NOT MAPPED (w)");
        bchan.resp = axi4_lite::AXI_SLVERR_RESPONSE;
        break;
    }
}

bool sha::can_single_write(void) const
{
    return true;
}

#endif /* __MAC_REGS_HPP__ */