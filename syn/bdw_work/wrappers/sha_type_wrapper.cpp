/****************************************************************************
*
*  Copyright (c) 2015, Cadence Design Systems. All Rights Reserved.
*
*  This file contains confidential information that may not be
*  distributed under any circumstances without the written permision
*  of Cadence Design Systems.
*
****************************************************************************/
/****************************************************************************
*
* This file contains the sha_type_wrapper module
* for use in the verilog verification wrapper sha_vlwrapper.v
* It creats an instance of the sha module and has threads
* for converting the BEH ports to RTL level ports on the wrapper.
*
****************************************************************************/

#include "sha_type_wrapper.h"


SC_MODULE_EXPORT(sha_type_wrapper)

// The following threads are used to connect RTL ports to the actual
// structured ports

void sha_type_wrapper::InitInstances()
{
    sha0 = new sha( "sha" );

    sha0->clk(clk);
    sha0->rst(rst);
    sha0->irq(irq);
    sha0->reg_target.AWVALID(reg_target_AWVALID);
    sha0->reg_target.AWADDR(reg_target_AWADDR);
    sha0->reg_target.AWREADY(reg_target_AWREADY);
    sha0->reg_target.AWPROT(reg_target_AWPROT);
    sha0->reg_target.WVALID(reg_target_WVALID);
    sha0->reg_target.WSTRB(reg_target_WSTRB);
    sha0->reg_target.WDATA(reg_target_WDATA);
    sha0->reg_target.WREADY(reg_target_WREADY);
    sha0->reg_target.BREADY(reg_target_BREADY);
    sha0->reg_target.BVALID(reg_target_BVALID);
    sha0->reg_target.BRESP(reg_target_BRESP);
    sha0->reg_target.ARVALID(reg_target_ARVALID);
    sha0->reg_target.ARADDR(reg_target_ARADDR);
    sha0->reg_target.ARREADY(reg_target_ARREADY);
    sha0->reg_target.ARPROT(reg_target_ARPROT);
    sha0->reg_target.RREADY(reg_target_RREADY);
    sha0->reg_target.RVALID(reg_target_RVALID);
    sha0->reg_target.RDATA(reg_target_RDATA);
    sha0->reg_target.RRESP(reg_target_RRESP);
    sha0->dma_initiator.AWVALID(dma_initiator_AWVALID);
    sha0->dma_initiator.AWLEN(dma_initiator_AWLEN);
    sha0->dma_initiator.AWSIZE(dma_initiator_AWSIZE);
    sha0->dma_initiator.AWBURST(dma_initiator_AWBURST);
    sha0->dma_initiator.AWID(dma_initiator_AWID);
    sha0->dma_initiator.AWADDR(dma_initiator_AWADDR);
    sha0->dma_initiator.AWREADY(dma_initiator_AWREADY);
    sha0->dma_initiator.AWLOCK(dma_initiator_AWLOCK);
    sha0->dma_initiator.AWCACHE(dma_initiator_AWCACHE);
    sha0->dma_initiator.AWPROT(dma_initiator_AWPROT);
    sha0->dma_initiator.AWQOS(dma_initiator_AWQOS);
    sha0->dma_initiator.AWREGION(dma_initiator_AWREGION);
    sha0->dma_initiator.WVALID(dma_initiator_WVALID);
    sha0->dma_initiator.WSTRB(dma_initiator_WSTRB);
    sha0->dma_initiator.WDATA(dma_initiator_WDATA);
    sha0->dma_initiator.WLAST(dma_initiator_WLAST);
    sha0->dma_initiator.WREADY(dma_initiator_WREADY);
    sha0->dma_initiator.BREADY(dma_initiator_BREADY);
    sha0->dma_initiator.BID(dma_initiator_BID);
    sha0->dma_initiator.BVALID(dma_initiator_BVALID);
    sha0->dma_initiator.BRESP(dma_initiator_BRESP);
    sha0->dma_initiator.ARVALID(dma_initiator_ARVALID);
    sha0->dma_initiator.ARLEN(dma_initiator_ARLEN);
    sha0->dma_initiator.ARSIZE(dma_initiator_ARSIZE);
    sha0->dma_initiator.ARBURST(dma_initiator_ARBURST);
    sha0->dma_initiator.ARID(dma_initiator_ARID);
    sha0->dma_initiator.ARADDR(dma_initiator_ARADDR);
    sha0->dma_initiator.ARREADY(dma_initiator_ARREADY);
    sha0->dma_initiator.ARLOCK(dma_initiator_ARLOCK);
    sha0->dma_initiator.ARCACHE(dma_initiator_ARCACHE);
    sha0->dma_initiator.ARPROT(dma_initiator_ARPROT);
    sha0->dma_initiator.ARQOS(dma_initiator_ARQOS);
    sha0->dma_initiator.ARREGION(dma_initiator_ARREGION);
    sha0->dma_initiator.RREADY(dma_initiator_RREADY);
    sha0->dma_initiator.RVALID(dma_initiator_RVALID);
    sha0->dma_initiator.RID(dma_initiator_RID);
    sha0->dma_initiator.RDATA(dma_initiator_RDATA);
    sha0->dma_initiator.RRESP(dma_initiator_RRESP);
    sha0->dma_initiator.RLAST(dma_initiator_RLAST);

}

void sha_type_wrapper::InitThreads()
{
    
}

void sha_type_wrapper::DeleteInstances()
{
        delete sha0;
        sha0 = 0;
}

