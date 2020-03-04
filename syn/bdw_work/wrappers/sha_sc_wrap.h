/****************************************************************************
*
*  Copyright (c) 2017, Cadence Design Systems. All Rights Reserved.
*
*  This file contains confidential information that may not be
*  distributed under any circumstances without the written permision
*  of Cadence Design Systems.
*
****************************************************************************/


#ifndef _SHA_SC_WRAP_INCLUDED_
#define _SHA_SC_WRAP_INCLUDED_

#include <systemc.h>

struct sha;

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
    
    
	// create the netlist
    void InitInstances( );
    void InitThreads();

    // delete the netlist
    void DeleteInstances();

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
		  	

		  ,sha0(0)

    {
        InitInstances( );
		InitThreads();
    }

    // destructor
    ~sha_wrapper()
    {
        DeleteInstances();
    }

	sha* sha0;
};

#endif /* _SHA_SC_WRAP_INCLUDED_ */
