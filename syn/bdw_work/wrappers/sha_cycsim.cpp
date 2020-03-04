/****************************************************************************
*
*  Copyright (c) 2015, Cadence Design Systems. All Rights Reserved.
*
*  This file contains confidential information that may not be
*  distributed under any circumstances without the written permision
*  of Cadence Design Systems.
*
****************************************************************************/

#ifdef NCSC
#include <string>
typedef std::string sc_string;
#define SYSTEMC_VERSION 20070314
#endif

#include "sha_cycsim.h"
#include "esc_catrace.h"
#include "verilated.h"
#include "Vsha_rtl.h"


class Vsha_rtl;

class sha_cycsimV : public sha_cycsim
{
    // Port declarations inherited from parent class

    // These signals are used to connect ports that need type conversion to the RTL ports
    sc_signal< uint32_t > reg_target_AWADDR_I;
    sc_signal< uint32_t > reg_target_AWPROT_I;
    sc_signal< uint32_t > reg_target_WSTRB_I;
    sc_signal< uint32_t > reg_target_WDATA_I;
    sc_signal< uint32_t > reg_target_BRESP_O;
    sc_signal< uint32_t > reg_target_ARADDR_I;
    sc_signal< uint32_t > reg_target_ARPROT_I;
    sc_signal< uint32_t > reg_target_RDATA_O;
    sc_signal< uint32_t > reg_target_RRESP_O;
    sc_signal< uint32_t > dma_initiator_AWLEN_O;
    sc_signal< uint32_t > dma_initiator_AWSIZE_O;
    sc_signal< uint32_t > dma_initiator_AWBURST_O;
    sc_signal< uint32_t > dma_initiator_AWID_O;
    sc_signal< uint32_t > dma_initiator_AWADDR_O;
    sc_signal< bool > dma_initiator_AWLOCK_O;
    sc_signal< uint32_t > dma_initiator_AWCACHE_O;
    sc_signal< uint32_t > dma_initiator_AWPROT_O;
    sc_signal< uint32_t > dma_initiator_AWQOS_O;
    sc_signal< uint32_t > dma_initiator_AWREGION_O;
    sc_signal< uint32_t > dma_initiator_WSTRB_O;
    sc_signal< uint32_t > dma_initiator_WDATA_O;
    sc_signal< uint32_t > dma_initiator_BID_I;
    sc_signal< uint32_t > dma_initiator_BRESP_I;
    sc_signal< uint32_t > dma_initiator_ARLEN_O;
    sc_signal< uint32_t > dma_initiator_ARSIZE_O;
    sc_signal< uint32_t > dma_initiator_ARBURST_O;
    sc_signal< uint32_t > dma_initiator_ARID_O;
    sc_signal< uint32_t > dma_initiator_ARADDR_O;
    sc_signal< bool > dma_initiator_ARLOCK_O;
    sc_signal< uint32_t > dma_initiator_ARCACHE_O;
    sc_signal< uint32_t > dma_initiator_ARPROT_O;
    sc_signal< uint32_t > dma_initiator_ARQOS_O;
    sc_signal< uint32_t > dma_initiator_ARREGION_O;
    sc_signal< uint32_t > dma_initiator_RID_I;
    sc_signal< uint32_t > dma_initiator_RDATA_I;
    sc_signal< uint32_t > dma_initiator_RRESP_I;


    // The following threads are used to do the type conversion.
    inline void thread_reg_target_AWADDR_I() {
        reg_target_AWADDR_I = (sc_uint<32>)reg_target_AWADDR.read();
    };
    inline void thread_reg_target_AWPROT_I() {
        reg_target_AWPROT_I = (sc_uint<3>)reg_target_AWPROT.read();
    };
    inline void thread_reg_target_WSTRB_I() {
        reg_target_WSTRB_I = (sc_uint<4>)reg_target_WSTRB.read();
    };
    inline void thread_reg_target_WDATA_I() {
        reg_target_WDATA_I = (sc_uint<32>)reg_target_WDATA.read();
    };
    inline void thread_reg_target_BRESP_O() {
        reg_target_BRESP = reg_target_BRESP_O.read();
    };
    inline void thread_reg_target_ARADDR_I() {
        reg_target_ARADDR_I = (sc_uint<32>)reg_target_ARADDR.read();
    };
    inline void thread_reg_target_ARPROT_I() {
        reg_target_ARPROT_I = (sc_uint<3>)reg_target_ARPROT.read();
    };
    inline void thread_reg_target_RDATA_O() {
        reg_target_RDATA = reg_target_RDATA_O.read();
    };
    inline void thread_reg_target_RRESP_O() {
        reg_target_RRESP = reg_target_RRESP_O.read();
    };
    inline void thread_dma_initiator_AWLEN_O() {
        dma_initiator_AWLEN = dma_initiator_AWLEN_O.read();
    };
    inline void thread_dma_initiator_AWSIZE_O() {
        dma_initiator_AWSIZE = dma_initiator_AWSIZE_O.read();
    };
    inline void thread_dma_initiator_AWBURST_O() {
        dma_initiator_AWBURST = dma_initiator_AWBURST_O.read();
    };
    inline void thread_dma_initiator_AWID_O() {
        dma_initiator_AWID = dma_initiator_AWID_O.read();
    };
    inline void thread_dma_initiator_AWADDR_O() {
        dma_initiator_AWADDR = dma_initiator_AWADDR_O.read();
    };
    inline void thread_dma_initiator_AWLOCK_O() {
        dma_initiator_AWLOCK = dma_initiator_AWLOCK_O.read();
    };
    inline void thread_dma_initiator_AWCACHE_O() {
        dma_initiator_AWCACHE = dma_initiator_AWCACHE_O.read();
    };
    inline void thread_dma_initiator_AWPROT_O() {
        dma_initiator_AWPROT = dma_initiator_AWPROT_O.read();
    };
    inline void thread_dma_initiator_AWQOS_O() {
        dma_initiator_AWQOS = dma_initiator_AWQOS_O.read();
    };
    inline void thread_dma_initiator_AWREGION_O() {
        dma_initiator_AWREGION = dma_initiator_AWREGION_O.read();
    };
    inline void thread_dma_initiator_WSTRB_O() {
        dma_initiator_WSTRB = dma_initiator_WSTRB_O.read();
    };
    inline void thread_dma_initiator_WDATA_O() {
        dma_initiator_WDATA = dma_initiator_WDATA_O.read();
    };
    inline void thread_dma_initiator_BID_I() {
        dma_initiator_BID_I = (sc_uint<6>)dma_initiator_BID.read();
    };
    inline void thread_dma_initiator_BRESP_I() {
        dma_initiator_BRESP_I = (sc_uint<2>)dma_initiator_BRESP.read();
    };
    inline void thread_dma_initiator_ARLEN_O() {
        dma_initiator_ARLEN = dma_initiator_ARLEN_O.read();
    };
    inline void thread_dma_initiator_ARSIZE_O() {
        dma_initiator_ARSIZE = dma_initiator_ARSIZE_O.read();
    };
    inline void thread_dma_initiator_ARBURST_O() {
        dma_initiator_ARBURST = dma_initiator_ARBURST_O.read();
    };
    inline void thread_dma_initiator_ARID_O() {
        dma_initiator_ARID = dma_initiator_ARID_O.read();
    };
    inline void thread_dma_initiator_ARADDR_O() {
        dma_initiator_ARADDR = dma_initiator_ARADDR_O.read();
    };
    inline void thread_dma_initiator_ARLOCK_O() {
        dma_initiator_ARLOCK = dma_initiator_ARLOCK_O.read();
    };
    inline void thread_dma_initiator_ARCACHE_O() {
        dma_initiator_ARCACHE = dma_initiator_ARCACHE_O.read();
    };
    inline void thread_dma_initiator_ARPROT_O() {
        dma_initiator_ARPROT = dma_initiator_ARPROT_O.read();
    };
    inline void thread_dma_initiator_ARQOS_O() {
        dma_initiator_ARQOS = dma_initiator_ARQOS_O.read();
    };
    inline void thread_dma_initiator_ARREGION_O() {
        dma_initiator_ARREGION = dma_initiator_ARREGION_O.read();
    };
    inline void thread_dma_initiator_RID_I() {
        dma_initiator_RID_I = (sc_uint<6>)dma_initiator_RID.read();
    };
    inline void thread_dma_initiator_RDATA_I() {
        dma_initiator_RDATA_I = (sc_uint<32>)dma_initiator_RDATA.read();
    };
    inline void thread_dma_initiator_RRESP_I() {
        dma_initiator_RRESP_I = (sc_uint<2>)dma_initiator_RRESP.read();
    };


    SC_HAS_PROCESS(sha_cycsimV);

public:

    sha_cycsimV( sc_module_name in_name=sc_module_name(sc_gen_unique_name(" sha") ) )
        : sha_cycsim(in_name)
    {
        // instantiate the verilated module
        sha_cyc0 = new Vsha_rtl( "Vsha" );
        // generate port connections
        sha_cyc0->clk(clk);
        sha_cyc0->rst(rst);
        sha_cyc0->irq(irq);
        sha_cyc0->reg_target_AWVALID(reg_target_AWVALID);
        sha_cyc0->reg_target_AWADDR(reg_target_AWADDR_I);
        sha_cyc0->reg_target_AWREADY(reg_target_AWREADY);
        sha_cyc0->reg_target_AWPROT(reg_target_AWPROT_I);
        sha_cyc0->reg_target_WVALID(reg_target_WVALID);
        sha_cyc0->reg_target_WSTRB(reg_target_WSTRB_I);
        sha_cyc0->reg_target_WDATA(reg_target_WDATA_I);
        sha_cyc0->reg_target_WREADY(reg_target_WREADY);
        sha_cyc0->reg_target_BREADY(reg_target_BREADY);
        sha_cyc0->reg_target_BVALID(reg_target_BVALID);
        sha_cyc0->reg_target_BRESP(reg_target_BRESP_O);
        sha_cyc0->reg_target_ARVALID(reg_target_ARVALID);
        sha_cyc0->reg_target_ARADDR(reg_target_ARADDR_I);
        sha_cyc0->reg_target_ARREADY(reg_target_ARREADY);
        sha_cyc0->reg_target_ARPROT(reg_target_ARPROT_I);
        sha_cyc0->reg_target_RREADY(reg_target_RREADY);
        sha_cyc0->reg_target_RVALID(reg_target_RVALID);
        sha_cyc0->reg_target_RDATA(reg_target_RDATA_O);
        sha_cyc0->reg_target_RRESP(reg_target_RRESP_O);
        sha_cyc0->dma_initiator_AWVALID(dma_initiator_AWVALID);
        sha_cyc0->dma_initiator_AWLEN(dma_initiator_AWLEN_O);
        sha_cyc0->dma_initiator_AWSIZE(dma_initiator_AWSIZE_O);
        sha_cyc0->dma_initiator_AWBURST(dma_initiator_AWBURST_O);
        sha_cyc0->dma_initiator_AWID(dma_initiator_AWID_O);
        sha_cyc0->dma_initiator_AWADDR(dma_initiator_AWADDR_O);
        sha_cyc0->dma_initiator_AWREADY(dma_initiator_AWREADY);
        sha_cyc0->dma_initiator_AWLOCK(dma_initiator_AWLOCK_O);
        sha_cyc0->dma_initiator_AWCACHE(dma_initiator_AWCACHE_O);
        sha_cyc0->dma_initiator_AWPROT(dma_initiator_AWPROT_O);
        sha_cyc0->dma_initiator_AWQOS(dma_initiator_AWQOS_O);
        sha_cyc0->dma_initiator_AWREGION(dma_initiator_AWREGION_O);
        sha_cyc0->dma_initiator_WVALID(dma_initiator_WVALID);
        sha_cyc0->dma_initiator_WSTRB(dma_initiator_WSTRB_O);
        sha_cyc0->dma_initiator_WDATA(dma_initiator_WDATA_O);
        sha_cyc0->dma_initiator_WLAST(dma_initiator_WLAST);
        sha_cyc0->dma_initiator_WREADY(dma_initiator_WREADY);
        sha_cyc0->dma_initiator_BREADY(dma_initiator_BREADY);
        sha_cyc0->dma_initiator_BID(dma_initiator_BID_I);
        sha_cyc0->dma_initiator_BVALID(dma_initiator_BVALID);
        sha_cyc0->dma_initiator_BRESP(dma_initiator_BRESP_I);
        sha_cyc0->dma_initiator_ARVALID(dma_initiator_ARVALID);
        sha_cyc0->dma_initiator_ARLEN(dma_initiator_ARLEN_O);
        sha_cyc0->dma_initiator_ARSIZE(dma_initiator_ARSIZE_O);
        sha_cyc0->dma_initiator_ARBURST(dma_initiator_ARBURST_O);
        sha_cyc0->dma_initiator_ARID(dma_initiator_ARID_O);
        sha_cyc0->dma_initiator_ARADDR(dma_initiator_ARADDR_O);
        sha_cyc0->dma_initiator_ARREADY(dma_initiator_ARREADY);
        sha_cyc0->dma_initiator_ARLOCK(dma_initiator_ARLOCK_O);
        sha_cyc0->dma_initiator_ARCACHE(dma_initiator_ARCACHE_O);
        sha_cyc0->dma_initiator_ARPROT(dma_initiator_ARPROT_O);
        sha_cyc0->dma_initiator_ARQOS(dma_initiator_ARQOS_O);
        sha_cyc0->dma_initiator_ARREGION(dma_initiator_ARREGION_O);
        sha_cyc0->dma_initiator_RREADY(dma_initiator_RREADY);
        sha_cyc0->dma_initiator_RVALID(dma_initiator_RVALID);
        sha_cyc0->dma_initiator_RID(dma_initiator_RID_I);
        sha_cyc0->dma_initiator_RDATA(dma_initiator_RDATA_I);
        sha_cyc0->dma_initiator_RRESP(dma_initiator_RRESP_I);
        sha_cyc0->dma_initiator_RLAST(dma_initiator_RLAST);


        // setup the type conversion threads
        SC_METHOD( thread_reg_target_AWADDR_I);
            sensitive << reg_target_AWADDR;
        SC_METHOD( thread_reg_target_AWPROT_I);
            sensitive << reg_target_AWPROT;
        SC_METHOD( thread_reg_target_WSTRB_I);
            sensitive << reg_target_WSTRB;
        SC_METHOD( thread_reg_target_WDATA_I);
            sensitive << reg_target_WDATA;
        SC_METHOD( thread_reg_target_BRESP_O);
            sensitive << reg_target_BRESP_O;
        SC_METHOD( thread_reg_target_ARADDR_I);
            sensitive << reg_target_ARADDR;
        SC_METHOD( thread_reg_target_ARPROT_I);
            sensitive << reg_target_ARPROT;
        SC_METHOD( thread_reg_target_RDATA_O);
            sensitive << reg_target_RDATA_O;
        SC_METHOD( thread_reg_target_RRESP_O);
            sensitive << reg_target_RRESP_O;
        SC_METHOD( thread_dma_initiator_AWLEN_O);
            sensitive << dma_initiator_AWLEN_O;
        SC_METHOD( thread_dma_initiator_AWSIZE_O);
            sensitive << dma_initiator_AWSIZE_O;
        SC_METHOD( thread_dma_initiator_AWBURST_O);
            sensitive << dma_initiator_AWBURST_O;
        SC_METHOD( thread_dma_initiator_AWID_O);
            sensitive << dma_initiator_AWID_O;
        SC_METHOD( thread_dma_initiator_AWADDR_O);
            sensitive << dma_initiator_AWADDR_O;
        SC_METHOD( thread_dma_initiator_AWLOCK_O);
            sensitive << dma_initiator_AWLOCK_O;
        SC_METHOD( thread_dma_initiator_AWCACHE_O);
            sensitive << dma_initiator_AWCACHE_O;
        SC_METHOD( thread_dma_initiator_AWPROT_O);
            sensitive << dma_initiator_AWPROT_O;
        SC_METHOD( thread_dma_initiator_AWQOS_O);
            sensitive << dma_initiator_AWQOS_O;
        SC_METHOD( thread_dma_initiator_AWREGION_O);
            sensitive << dma_initiator_AWREGION_O;
        SC_METHOD( thread_dma_initiator_WSTRB_O);
            sensitive << dma_initiator_WSTRB_O;
        SC_METHOD( thread_dma_initiator_WDATA_O);
            sensitive << dma_initiator_WDATA_O;
        SC_METHOD( thread_dma_initiator_BID_I);
            sensitive << dma_initiator_BID;
        SC_METHOD( thread_dma_initiator_BRESP_I);
            sensitive << dma_initiator_BRESP;
        SC_METHOD( thread_dma_initiator_ARLEN_O);
            sensitive << dma_initiator_ARLEN_O;
        SC_METHOD( thread_dma_initiator_ARSIZE_O);
            sensitive << dma_initiator_ARSIZE_O;
        SC_METHOD( thread_dma_initiator_ARBURST_O);
            sensitive << dma_initiator_ARBURST_O;
        SC_METHOD( thread_dma_initiator_ARID_O);
            sensitive << dma_initiator_ARID_O;
        SC_METHOD( thread_dma_initiator_ARADDR_O);
            sensitive << dma_initiator_ARADDR_O;
        SC_METHOD( thread_dma_initiator_ARLOCK_O);
            sensitive << dma_initiator_ARLOCK_O;
        SC_METHOD( thread_dma_initiator_ARCACHE_O);
            sensitive << dma_initiator_ARCACHE_O;
        SC_METHOD( thread_dma_initiator_ARPROT_O);
            sensitive << dma_initiator_ARPROT_O;
        SC_METHOD( thread_dma_initiator_ARQOS_O);
            sensitive << dma_initiator_ARQOS_O;
        SC_METHOD( thread_dma_initiator_ARREGION_O);
            sensitive << dma_initiator_ARREGION_O;
        SC_METHOD( thread_dma_initiator_RID_I);
            sensitive << dma_initiator_RID;
        SC_METHOD( thread_dma_initiator_RDATA_I);
            sensitive << dma_initiator_RDATA;
        SC_METHOD( thread_dma_initiator_RRESP_I);
            sensitive << dma_initiator_RRESP;


        TraceFileType* tfp = esc_get_ca_trace_file();
        if ( tfp )
        {
            sha_cyc0->trace(tfp,99);
        }
    };

    ~sha_cycsimV()
    {
        delete sha_cyc0;
    }

    void end_of_elaboration()
    {
        esc_open_ca_trace_file();
    }

    void end_of_simulation()
    {
        esc_close_ca_trace_file();
    }

protected:
    Vsha_rtl* sha_cyc0;
};

sha_cycsim* sha_cycsim_factory()
{
    return new sha_cycsimV("sha");
}

class sha_linkup
{
public:
    sha_linkup() {
        extern sha_cycsim* (*sha_cycsim_factory_p)();
        sha_cycsim_factory_p = &sha_cycsim_factory;
    }
};

// Create the one instance of the factory for this verilated model.
sha_linkup sha_cycsimV_link;


