/****************************************************************************
*
*  Copyright (c) 2015, Cadence Design Systems. All Rights Reserved.
*
*  This file contains confidential information that may not be
*  distributed under any circumstances without the written permision
*  of Cadence Design Systems.
*
****************************************************************************/


#ifndef _SHA_WRAP_INCLUDED_
#define _SHA_WRAP_INCLUDED_

#if !defined(ioConfig_IOCFG_32)
#if defined(_p_ioConfig_IOCFG_32)
#define ioConfig_IOCFG_32 1
#endif
#endif


/* Save ioConfig define values for parent module and define those for this module's ioConfigs. */
#if defined(ioConfig_IOCFG_32)
#if defined(ioConfig) && defined(_wrap_ioConfig) && !defined(_local_ioConfig)
#undef ioConfig
#define ioConfig _local_ioConfig
#define _local_ioConfig IOCFG_32
#endif
#if defined(ID_WIDTH) && defined(_wrap_ID_WIDTH) && !defined(_local_ID_WIDTH)
#undef ID_WIDTH
#define ID_WIDTH _local_ID_WIDTH
#define _local_ID_WIDTH 6
#endif
#if defined(ADDR_WIDTH) && defined(_wrap_ADDR_WIDTH) && !defined(_local_ADDR_WIDTH)
#undef ADDR_WIDTH
#define ADDR_WIDTH _local_ADDR_WIDTH
#define _local_ADDR_WIDTH 32
#endif
#if defined(DATA_WIDTH) && defined(_wrap_DATA_WIDTH) && !defined(_local_DATA_WIDTH)
#undef DATA_WIDTH
#define DATA_WIDTH _local_DATA_WIDTH
#define _local_DATA_WIDTH 32
#endif
#if defined(CLOCK_PERIOD) && defined(_wrap_CLOCK_PERIOD) && !defined(_local_CLOCK_PERIOD)
#undef CLOCK_PERIOD
#define CLOCK_PERIOD _local_CLOCK_PERIOD
#define _local_CLOCK_PERIOD 10.0
#endif
#if defined(RESET_PERIOD) && defined(_wrap_RESET_PERIOD) && !defined(_local_RESET_PERIOD)
#undef RESET_PERIOD
#define RESET_PERIOD _local_RESET_PERIOD
#define _local_RESET_PERIOD 300.0
#endif
#if defined(MAX_SAMPLES) && defined(_wrap_MAX_SAMPLES) && !defined(_local_MAX_SAMPLES)
#undef MAX_SAMPLES
#define MAX_SAMPLES _local_MAX_SAMPLES
#define _local_MAX_SAMPLES 32
#endif
#if defined(NSAMPLES) && defined(_wrap_NSAMPLES) && !defined(_local_NSAMPLES)
#undef NSAMPLES
#define NSAMPLES _local_NSAMPLES
#define _local_NSAMPLES 16
#endif
#if defined(NITERS) && defined(_wrap_NITERS) && !defined(_local_NITERS)
#undef NITERS
#define NITERS _local_NITERS
#define _local_NITERS 4
#endif
#if defined(DEBUG) && defined(_wrap_DEBUG) && !defined(_local_DEBUG)
#undef DEBUG
#define DEBUG _local_DEBUG
#define _local_DEBUG 
#endif
#endif


#if defined(CYNTHVLG) 

#include <systemc.h>

#define sha_wrapper sha

/* This is the section that is seen during processing by cynthVLG of a module
 * that instantiates the module defined by this wrapper.
 */
SC_MODULE(sha)
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

	SC_CTOR(sha);
};

#elif defined(CYNTHHL) || defined(BDW_EXTRACT)

/* This is the section seen during processing by cynthHL or bdw_extract of a module 
 * that instantiates the module defined by this wrapper.
 */
#include <systemc.h>

#include "cynw_bus_interfaces/axi4_lite/axi4_lite_ports.h"
#include "cynw_bus_interfaces/axi4_lite/axi4_lite_traits.h"
#include "cynw_bus_interfaces/axi4/axi4_ports.h"
#include "cynw_bus_interfaces/axi4/axi4_traits.h"


#define sha_wrapper sha

/* Only port declarations are required for nested modules.
 */
SC_MODULE(sha)
{
public:
	sc_in< bool > clk;
	sc_in< bool > rst;
	sc_out< bool > irq;
	cynw::axi4_lite::axi4_lite_target_ports_imp <cynw::axi4_lite::axi4_lite_traits_template <reg_if_width_traits, true >::tlm_traits, (unsigned int)0 > reg_target;
	cynw::simple_bus::axi4_initiator_ports_imp <cynw::axi4::axi4_traits_template <dma_if_width_traits, cynw::axi4::axi4_def_userw_traits, true >::tlm_traits, (cynw::axi4::axi_rw_mode)0 > dma_initiator;


	SC_HAS_PROCESS(sha);
    	sha_wrapper( sc_module_name name = sc_module_name( sc_gen_unique_name("sha")) );
};

#else

#include <esc.h>


/* This is the section seen during processing by gcc either when the module
 * itself is compiled, or when a module that instantiates it is compiled.
 */

struct sha;
struct sha_cosim;
struct sha_cycsim;
struct sha_rtl;

#ifdef BDW_COWARE
#include	"sha_coware.h"
#endif

#include "cynw_bus_interfaces/axi4_lite/axi4_lite_ports.h"
#include "cynw_bus_interfaces/axi4_lite/axi4_lite_traits.h"
#include "cynw_bus_interfaces/axi4/axi4_ports.h"
#include "cynw_bus_interfaces/axi4/axi4_traits.h"


// Declaration of wrapper with BEH level ports

SC_MODULE(sha_wrapper)
{
public:

	sc_in< bool > clk;
	sc_in< bool > rst;
	sc_out< bool > irq;
	cynw::axi4_lite::axi4_lite_target_ports_imp <cynw::axi4_lite::axi4_lite_traits_template <reg_if_width_traits, true >::tlm_traits, (unsigned int)0 > reg_target;
	cynw::simple_bus::axi4_initiator_ports_imp <cynw::axi4::axi4_traits_template <dma_if_width_traits, cynw::axi4::axi4_def_userw_traits, true >::tlm_traits, (cynw::axi4::axi_rw_mode)0 > dma_initiator;

    
    // These signals are used to connect structured ports or ports that need
    // type conversion to the RTL ports.
    
    
	enum Representation { BDWRep_None, BDWRep_Behavioral, BDWRep_RTL_C, BDWRep_RTL_HDL, BDWRep_Gates, BDWRep_CYC_HDL };
	static const char * simConfigName();
	static Representation lookupRepresentation( const char* instName );
	// create the netlist
    void InitInstances( );
    void InitThreads();

    // delete the netlist
    void DeleteInstances();

	void CloseTrace();
	void start_of_simulation();
	void end_of_simulation();


    // The following threads are used to connect structured ports to the actual
    // RTL ports.
    

	SC_HAS_PROCESS(sha_wrapper);

    	sha_wrapper( sc_module_name name = sc_module_name( sc_gen_unique_name("sha")) )
		: sc_module(name)
		  ,clk("clk")
		  	,rst("rst")
		  	,irq("irq")
		  	,reg_target("reg_target")
		  	,dma_initiator("dma_initiator")
		  	

		  ,sha0(0), sha_cosim0(0), sha_rtl0(0), sha_cycsim0(0)
		

    {
        InitInstances( );
		InitThreads();
    }


    // destructor
    ~sha_wrapper()
    {
        DeleteInstances();

		CloseTrace();
    }

    bool isBEH() { return ( sha_wrapper::lookupRepresentation( name() ) == BDWRep_Behavioral ); }
    bool isRTL_C() { return ( sha_wrapper::lookupRepresentation( name() ) == BDWRep_RTL_C ); }
    bool isRTL_V() { return ( sha_wrapper::lookupRepresentation( name() ) == BDWRep_RTL_HDL ); }
    bool isGATES_V() { return ( sha_wrapper::lookupRepresentation( name() ) == BDWRep_Gates ); }
	bool isCosim() { return ( isRTL_V() || isGATES_V() ); }
    bool isCycsim() { return ( sha_wrapper::lookupRepresentation( name() ) == BDWRep_CYC_HDL ); }

	sha* behModule() { return sha0; }
	sha_cosim* cosimModule() { return sha_cosim0; }
	sha_cycsim* cycsimModule() { return sha_cycsim0; }
	sha_rtl* rtlModule() { return sha_rtl0; }

	sha* sha0;
	sha_cosim* sha_cosim0;
	sha_rtl* sha_rtl0;
	sha_cycsim* sha_cycsim0;
};

// Declaration of wrapper with RTL level ports

SC_MODULE(sha_wrapper_r)
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
    
    
	enum Representation { BDWRep_None, BDWRep_Behavioral, BDWRep_RTL_C, BDWRep_RTL_HDL, BDWRep_Gates, BDWRep_CYC_HDL };

	static const char * simConfigName();
	static Representation lookupRepresentation( const char* instName );
	// create the netlist
    void InitInstances();
    void InitThreads();

    // delete the netlist
    void DeleteInstances();

	void CloseTrace();
	void start_of_simulation();
	void end_of_simulation();


    // The following threads are used to connect structured ports to the actual
    // RTL ports.
    

	SC_HAS_PROCESS(sha_wrapper_r);

	sha_wrapper_r( sc_module_name name = sc_module_name( sc_gen_unique_name("sha")) )
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
		  	

		  ,sha0(0), sha_cosim0(0), sha_rtl0(0), sha_cycsim0(0)
		

    {
        InitInstances();
        InitThreads();
		end_module();
    }


    // destructor
    ~sha_wrapper_r()
    {
        DeleteInstances();

		CloseTrace();
    }

    bool isBEH() { return ( sha_wrapper_r::lookupRepresentation( name() ) == BDWRep_Behavioral ); }
    bool isRTL_C() { return ( sha_wrapper_r::lookupRepresentation( name() ) == BDWRep_RTL_C ); }
    bool isRTL_V() { return ( sha_wrapper_r::lookupRepresentation( name() ) == BDWRep_RTL_HDL ); }
    bool isGATES_V() { return ( sha_wrapper_r::lookupRepresentation( name() ) == BDWRep_Gates ); }
	bool isCosim() { return ( isRTL_V() || isGATES_V() ); }
    bool isCycsim() { return ( sha_wrapper_r::lookupRepresentation( name() ) == BDWRep_CYC_HDL ); }

	sha* behModule() { return sha0; }
	sha_cosim* cosimModule() { return sha_cosim0; }
	sha_cycsim* cycsimModule() { return sha_cycsim0; }
	sha_rtl* rtlModule() { return sha_rtl0; }

protected:
	sha* sha0;
	sha_cosim* sha_cosim0;
	sha_rtl* sha_rtl0;
	sha_cycsim* sha_cycsim0;
};

#endif

/* Restore ioConfig define values for parent module. */
#if defined(ioConfig_IOCFG_32)
#if defined(ioConfig) && defined(_wrap_ioConfig) && defined(_local_ioConfig)
#undef _local_ioConfig
#undef ioConfig
#define ioConfig _wrap_ioConfig
#endif
#if defined(ID_WIDTH) && defined(_wrap_ID_WIDTH) && defined(_local_ID_WIDTH)
#undef _local_ID_WIDTH
#undef ID_WIDTH
#define ID_WIDTH _wrap_ID_WIDTH
#endif
#if defined(ADDR_WIDTH) && defined(_wrap_ADDR_WIDTH) && defined(_local_ADDR_WIDTH)
#undef _local_ADDR_WIDTH
#undef ADDR_WIDTH
#define ADDR_WIDTH _wrap_ADDR_WIDTH
#endif
#if defined(DATA_WIDTH) && defined(_wrap_DATA_WIDTH) && defined(_local_DATA_WIDTH)
#undef _local_DATA_WIDTH
#undef DATA_WIDTH
#define DATA_WIDTH _wrap_DATA_WIDTH
#endif
#if defined(CLOCK_PERIOD) && defined(_wrap_CLOCK_PERIOD) && defined(_local_CLOCK_PERIOD)
#undef _local_CLOCK_PERIOD
#undef CLOCK_PERIOD
#define CLOCK_PERIOD _wrap_CLOCK_PERIOD
#endif
#if defined(RESET_PERIOD) && defined(_wrap_RESET_PERIOD) && defined(_local_RESET_PERIOD)
#undef _local_RESET_PERIOD
#undef RESET_PERIOD
#define RESET_PERIOD _wrap_RESET_PERIOD
#endif
#if defined(MAX_SAMPLES) && defined(_wrap_MAX_SAMPLES) && defined(_local_MAX_SAMPLES)
#undef _local_MAX_SAMPLES
#undef MAX_SAMPLES
#define MAX_SAMPLES _wrap_MAX_SAMPLES
#endif
#if defined(NSAMPLES) && defined(_wrap_NSAMPLES) && defined(_local_NSAMPLES)
#undef _local_NSAMPLES
#undef NSAMPLES
#define NSAMPLES _wrap_NSAMPLES
#endif
#if defined(NITERS) && defined(_wrap_NITERS) && defined(_local_NITERS)
#undef _local_NITERS
#undef NITERS
#define NITERS _wrap_NITERS
#endif
#if defined(DEBUG) && defined(_wrap_DEBUG) && defined(_local_DEBUG)
#undef _local_DEBUG
#undef DEBUG
#define DEBUG _wrap_DEBUG
#endif
#endif

#endif /*  */
