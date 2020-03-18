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


#ifndef _SHA_TYPE_WRAP_INCLUDED_
#define _SHA_TYPE_WRAP_INCLUDED_

#if !defined(ioConfig_IOCFG_32)
#if defined(_p_ioConfig_IOCFG_32)
#define ioConfig_IOCFG_32 1
#endif
#endif


#include <systemc.h>
#include "sha.hpp"


// Declaration of wrapper with RTL level ports

SC_MODULE(sha_type_wrapper)
{
public:

	sc_in< bool > clk;
	sc_in< bool > rst;
	sc_out< bool > irq;
	sc_in< bool > reg_target_AWVALID;
	sc_in< sc_uint< 32 > > reg_target_AWADDR;
	sc_out< bool > reg_target_AWREADY;
	sc_in< sc_uint< 3 > > reg_target_AWPROT;
	sc_in< bool > reg_target_WVALID;
	sc_in< sc_uint< 4 > > reg_target_WSTRB;
	sc_in< sc_uint< 32 > > reg_target_WDATA;
	sc_out< bool > reg_target_WREADY;
	sc_in< bool > reg_target_BREADY;
	sc_out< bool > reg_target_BVALID;
	sc_out< sc_uint< 2 > > reg_target_BRESP;
	sc_in< bool > reg_target_ARVALID;
	sc_in< sc_uint< 32 > > reg_target_ARADDR;
	sc_out< bool > reg_target_ARREADY;
	sc_in< sc_uint< 3 > > reg_target_ARPROT;
	sc_in< bool > reg_target_RREADY;
	sc_out< bool > reg_target_RVALID;
	sc_out< sc_uint< 32 > > reg_target_RDATA;
	sc_out< sc_uint< 2 > > reg_target_RRESP;
	sc_out< bool > dma_initiator_AWVALID;
	sc_out< sc_uint< 8 > > dma_initiator_AWLEN;
	sc_out< sc_uint< 3 > > dma_initiator_AWSIZE;
	sc_out< sc_uint< 2 > > dma_initiator_AWBURST;
	sc_out< sc_uint< 6 > > dma_initiator_AWID;
	sc_out< sc_uint< 32 > > dma_initiator_AWADDR;
	sc_in< bool > dma_initiator_AWREADY;
	sc_out< sc_uint< 1 > > dma_initiator_AWLOCK;
	sc_out< sc_uint< 4 > > dma_initiator_AWCACHE;
	sc_out< sc_uint< 3 > > dma_initiator_AWPROT;
	sc_out< sc_uint< 4 > > dma_initiator_AWQOS;
	sc_out< sc_uint< 4 > > dma_initiator_AWREGION;
	sc_out< bool > dma_initiator_WVALID;
	sc_out< sc_uint< 4 > > dma_initiator_WSTRB;
	sc_out< sc_uint< 32 > > dma_initiator_WDATA;
	sc_out< bool > dma_initiator_WLAST;
	sc_in< bool > dma_initiator_WREADY;
	sc_out< bool > dma_initiator_BREADY;
	sc_in< sc_uint< 6 > > dma_initiator_BID;
	sc_in< bool > dma_initiator_BVALID;
	sc_in< sc_uint< 2 > > dma_initiator_BRESP;
	sc_out< bool > dma_initiator_ARVALID;
	sc_out< sc_uint< 8 > > dma_initiator_ARLEN;
	sc_out< sc_uint< 3 > > dma_initiator_ARSIZE;
	sc_out< sc_uint< 2 > > dma_initiator_ARBURST;
	sc_out< sc_uint< 6 > > dma_initiator_ARID;
	sc_out< sc_uint< 32 > > dma_initiator_ARADDR;
	sc_in< bool > dma_initiator_ARREADY;
	sc_out< sc_uint< 1 > > dma_initiator_ARLOCK;
	sc_out< sc_uint< 4 > > dma_initiator_ARCACHE;
	sc_out< sc_uint< 3 > > dma_initiator_ARPROT;
	sc_out< sc_uint< 4 > > dma_initiator_ARQOS;
	sc_out< sc_uint< 4 > > dma_initiator_ARREGION;
	sc_out< bool > dma_initiator_RREADY;
	sc_in< bool > dma_initiator_RVALID;
	sc_in< sc_uint< 6 > > dma_initiator_RID;
	sc_in< sc_uint< 32 > > dma_initiator_RDATA;
	sc_in< sc_uint< 2 > > dma_initiator_RRESP;
	sc_in< bool > dma_initiator_RLAST;

    
    // These signals are used to connect structured ports or ports that need
    // type conversion to the RTL ports.
    
    

	// create the netlist
    void InitInstances();
    void InitThreads();

    // delete the netlist
    void DeleteInstances();

    // The following threads are used to connect structured ports to the actual
    // RTL ports.
    

	SC_HAS_PROCESS(sha_type_wrapper);

	sha_type_wrapper( sc_module_name name = sc_module_name( sc_gen_unique_name("sha")) )
		: sc_module(name)
		  ,clk("clk")
		  	,rst("rst")
		  	,irq("irq")
		  	,reg_target_AWVALID("reg_target_AWVALID")
		  	,reg_target_AWADDR("reg_target_AWADDR")
		  	,reg_target_AWREADY("reg_target_AWREADY")
		  	,reg_target_AWPROT("reg_target_AWPROT")
		  	,reg_target_WVALID("reg_target_WVALID")
		  	,reg_target_WSTRB("reg_target_WSTRB")
		  	,reg_target_WDATA("reg_target_WDATA")
		  	,reg_target_WREADY("reg_target_WREADY")
		  	,reg_target_BREADY("reg_target_BREADY")
		  	,reg_target_BVALID("reg_target_BVALID")
		  	,reg_target_BRESP("reg_target_BRESP")
		  	,reg_target_ARVALID("reg_target_ARVALID")
		  	,reg_target_ARADDR("reg_target_ARADDR")
		  	,reg_target_ARREADY("reg_target_ARREADY")
		  	,reg_target_ARPROT("reg_target_ARPROT")
		  	,reg_target_RREADY("reg_target_RREADY")
		  	,reg_target_RVALID("reg_target_RVALID")
		  	,reg_target_RDATA("reg_target_RDATA")
		  	,reg_target_RRESP("reg_target_RRESP")
		  	,dma_initiator_AWVALID("dma_initiator_AWVALID")
		  	,dma_initiator_AWLEN("dma_initiator_AWLEN")
		  	,dma_initiator_AWSIZE("dma_initiator_AWSIZE")
		  	,dma_initiator_AWBURST("dma_initiator_AWBURST")
		  	,dma_initiator_AWID("dma_initiator_AWID")
		  	,dma_initiator_AWADDR("dma_initiator_AWADDR")
		  	,dma_initiator_AWREADY("dma_initiator_AWREADY")
		  	,dma_initiator_AWLOCK("dma_initiator_AWLOCK")
		  	,dma_initiator_AWCACHE("dma_initiator_AWCACHE")
		  	,dma_initiator_AWPROT("dma_initiator_AWPROT")
		  	,dma_initiator_AWQOS("dma_initiator_AWQOS")
		  	,dma_initiator_AWREGION("dma_initiator_AWREGION")
		  	,dma_initiator_WVALID("dma_initiator_WVALID")
		  	,dma_initiator_WSTRB("dma_initiator_WSTRB")
		  	,dma_initiator_WDATA("dma_initiator_WDATA")
		  	,dma_initiator_WLAST("dma_initiator_WLAST")
		  	,dma_initiator_WREADY("dma_initiator_WREADY")
		  	,dma_initiator_BREADY("dma_initiator_BREADY")
		  	,dma_initiator_BID("dma_initiator_BID")
		  	,dma_initiator_BVALID("dma_initiator_BVALID")
		  	,dma_initiator_BRESP("dma_initiator_BRESP")
		  	,dma_initiator_ARVALID("dma_initiator_ARVALID")
		  	,dma_initiator_ARLEN("dma_initiator_ARLEN")
		  	,dma_initiator_ARSIZE("dma_initiator_ARSIZE")
		  	,dma_initiator_ARBURST("dma_initiator_ARBURST")
		  	,dma_initiator_ARID("dma_initiator_ARID")
		  	,dma_initiator_ARADDR("dma_initiator_ARADDR")
		  	,dma_initiator_ARREADY("dma_initiator_ARREADY")
		  	,dma_initiator_ARLOCK("dma_initiator_ARLOCK")
		  	,dma_initiator_ARCACHE("dma_initiator_ARCACHE")
		  	,dma_initiator_ARPROT("dma_initiator_ARPROT")
		  	,dma_initiator_ARQOS("dma_initiator_ARQOS")
		  	,dma_initiator_ARREGION("dma_initiator_ARREGION")
		  	,dma_initiator_RREADY("dma_initiator_RREADY")
		  	,dma_initiator_RVALID("dma_initiator_RVALID")
		  	,dma_initiator_RID("dma_initiator_RID")
		  	,dma_initiator_RDATA("dma_initiator_RDATA")
		  	,dma_initiator_RRESP("dma_initiator_RRESP")
		  	,dma_initiator_RLAST("dma_initiator_RLAST")
		  	

		  ,sha0(0)
		

    {
        InitInstances();
        InitThreads();
		end_module();
    }


    // destructor
    ~sha_type_wrapper()
    {
        DeleteInstances();
    }


protected:
	sha* sha0;
};

#endif /*  */
