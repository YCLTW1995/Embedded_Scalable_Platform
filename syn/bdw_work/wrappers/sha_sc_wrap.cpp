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
* This file is used to wrap the three different versions of the DUT
* block called "sha". By default, it will include the behavioral
* model. Otherwise, it will include the RTL C++ or the RTL Verilog
* depending on the definition of either of "RTL" or "COSIM".
*
****************************************************************************/


#include	"sha_sc_wrap.h"
#include	"sha_sc_foreign.h"

// The following threads are used to connect structured ports to the actual
// RTL ports

void sha_wrapper::InitInstances(  )
{
	
            
    sha0 = new sha( "sha" );

    sha0->clk(clk);
    sha0->rst(rst);
    sha0->irq(irq);
    sha0->reg_target_AWVALID(reg_target.AWVALID);
    sha0->reg_target_AWADDR(reg_target.AWADDR);
    sha0->reg_target_AWREADY(reg_target.AWREADY);
    sha0->reg_target_AWPROT(reg_target.AWPROT);
    sha0->reg_target_WVALID(reg_target.WVALID);
    sha0->reg_target_WSTRB(reg_target.WSTRB);
    sha0->reg_target_WDATA(reg_target.WDATA);
    sha0->reg_target_WREADY(reg_target.WREADY);
    sha0->reg_target_BREADY(reg_target.BREADY);
    sha0->reg_target_BVALID(reg_target.BVALID);
    sha0->reg_target_BRESP(reg_target.BRESP);
    sha0->reg_target_ARVALID(reg_target.ARVALID);
    sha0->reg_target_ARADDR(reg_target.ARADDR);
    sha0->reg_target_ARREADY(reg_target.ARREADY);
    sha0->reg_target_ARPROT(reg_target.ARPROT);
    sha0->reg_target_RREADY(reg_target.RREADY);
    sha0->reg_target_RVALID(reg_target.RVALID);
    sha0->reg_target_RDATA(reg_target.RDATA);
    sha0->reg_target_RRESP(reg_target.RRESP);
    sha0->dma_initiator_AWVALID(dma_initiator.AWVALID);
    sha0->dma_initiator_AWLEN(dma_initiator.AWLEN);
    sha0->dma_initiator_AWSIZE(dma_initiator.AWSIZE);
    sha0->dma_initiator_AWBURST(dma_initiator.AWBURST);
    sha0->dma_initiator_AWID(dma_initiator.AWID);
    sha0->dma_initiator_AWADDR(dma_initiator.AWADDR);
    sha0->dma_initiator_AWREADY(dma_initiator.AWREADY);
    sha0->dma_initiator_AWLOCK(dma_initiator.AWLOCK);
    sha0->dma_initiator_AWCACHE(dma_initiator.AWCACHE);
    sha0->dma_initiator_AWPROT(dma_initiator.AWPROT);
    sha0->dma_initiator_AWQOS(dma_initiator.AWQOS);
    sha0->dma_initiator_AWREGION(dma_initiator.AWREGION);
    sha0->dma_initiator_WVALID(dma_initiator.WVALID);
    sha0->dma_initiator_WSTRB(dma_initiator.WSTRB);
    sha0->dma_initiator_WDATA(dma_initiator.WDATA);
    sha0->dma_initiator_WLAST(dma_initiator.WLAST);
    sha0->dma_initiator_WREADY(dma_initiator.WREADY);
    sha0->dma_initiator_BREADY(dma_initiator.BREADY);
    sha0->dma_initiator_BID(dma_initiator.BID);
    sha0->dma_initiator_BVALID(dma_initiator.BVALID);
    sha0->dma_initiator_BRESP(dma_initiator.BRESP);
    sha0->dma_initiator_ARVALID(dma_initiator.ARVALID);
    sha0->dma_initiator_ARLEN(dma_initiator.ARLEN);
    sha0->dma_initiator_ARSIZE(dma_initiator.ARSIZE);
    sha0->dma_initiator_ARBURST(dma_initiator.ARBURST);
    sha0->dma_initiator_ARID(dma_initiator.ARID);
    sha0->dma_initiator_ARADDR(dma_initiator.ARADDR);
    sha0->dma_initiator_ARREADY(dma_initiator.ARREADY);
    sha0->dma_initiator_ARLOCK(dma_initiator.ARLOCK);
    sha0->dma_initiator_ARCACHE(dma_initiator.ARCACHE);
    sha0->dma_initiator_ARPROT(dma_initiator.ARPROT);
    sha0->dma_initiator_ARQOS(dma_initiator.ARQOS);
    sha0->dma_initiator_ARREGION(dma_initiator.ARREGION);
    sha0->dma_initiator_RREADY(dma_initiator.RREADY);
    sha0->dma_initiator_RVALID(dma_initiator.RVALID);
    sha0->dma_initiator_RID(dma_initiator.RID);
    sha0->dma_initiator_RDATA(dma_initiator.RDATA);
    sha0->dma_initiator_RRESP(dma_initiator.RRESP);
    sha0->dma_initiator_RLAST(dma_initiator.RLAST);

}

void sha_wrapper::InitThreads()
{
    
}

void sha_wrapper::DeleteInstances()
{
    if (sha0)
    {
        delete sha0;
        sha0 = 0;
    }
}

