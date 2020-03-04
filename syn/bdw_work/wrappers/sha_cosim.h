/****************************************************************************
 *
 *  Copyright (c) 2015, Cadence Design Systems. All Rights Reserved.
 *
 *  This file contains confidential information that may not be
 *  distributed under any circumstances without the written permision
 *  of Cadence Design Systems.
 *
 ***************************************************************************/

#ifndef _SHA_COSIM_INCLUDED_
#define _SHA_COSIM_INCLUDED_

#include "systemc.h"
#include "cynthhl.h"
#include "esc.h"
#if __GNUC__ < 3
#include <ostream.h>
#else
#include <ostream>

#endif

#ifdef NC_SYSTEMC
struct sha_cosim : public ncsc_foreign_module
#else
SC_MODULE(sha_cosim)
#endif
{
	struct StringPair {
		const char* simConfigName;
		const char* instanceName;
		bool linked;
	};

	// Instance number used during elaboration-time SystemC-to-HDL signal linkage.
	static int numLinked;
	static StringPair instanceNames[];

	static int numInstanceNames( const char* simConfigName ) {
		int nin = 0;
		for ( int i = 0; instanceNames[i].simConfigName != NULL; ++i )
			if ( strcmp( instanceNames[i].simConfigName, simConfigName ) == 0 )
				++nin;
		return nin;
	}

	// Port declarations.
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

    void end_of_elaboration()
    {
#if __GNUC__ < 3
		strstream s;
#else
		std::ostringstream s;
#endif


		s << "top/";

		const char* scName = getenv("BDW_SIM_CONFIG");
		if (!scName) 
			scName = "?";

		int nin = numInstanceNames(scName);
		if ( nin == 0 )
		{
			if ( numLinked > 0 ) 
			{
				esc_report_error( esc_fatal, 
					"More than one instance of module sha is being simulated in Verilog,\n"
					"but no instance names have been specified in simConfig %s.\n"
					"Additional instances can be specified using the following syntax:\n\n"
					"    simConfig <config_name> { <module> RTL_V <config> <inst1> <inst2> ...}\n\n"
					"where <inst1> and <inst2> are the leaf names of instances of sha in SystemC\n", 
					scName );
				return;
			} else {
				s << "sha0" << std::ends;
			}
		}
		else
		{
			StringPair *instPair = &instanceNames[ numLinked ];
			while ( instPair->instanceName != NULL )
			{
				if ( ( ! instPair->linked )
					 && ( ! strcmp( instPair->simConfigName, scName ) ) )
				{
					const char *instName = instPair->instanceName;

					// Hierarchical SystemC instance names must be escaped for Verilog.
					if ( strchr( instName, '.' ) != NULL )
						s << '\\' << instName << ' ' << std::ends;
					else
						s << instName << std::ends;

					instPair->linked = true;
					break;
				}

				++instPair;
			}

			if ( instPair->instanceName == NULL )
			{
				esc_report_error( esc_fatal, 
								  "More than %d instance(s) of module sha are being simulated in Verilog,\n"
								  "but only %d instance name(s) have been specified in simConfig %s.\n",
								  nin, nin, scName );
				return;
			}
		}
		numLinked++;


#if __GNUC__ < 3
		char *c = s.str();
#else
		char *c = (char *)strdup( s.str().c_str() );
#endif

        link_signals(c, "verilog");
#if __GNUC__ < 3
		delete c;
#else
		free( c );
#endif
    }

    void link_signals(const char *module_path, const char *sim_domain)
    {
#ifndef NC_SYSTEMC
        int registeredClocks = 0;

		double inputDelay = 0.0;
		const char* scName = getenv("BDW_SIM_CONFIG");
		if (!scName) scName = "?";
		if ( qbhVerilogInputDelay( qbhEmptyHandle, scName, &inputDelay ) != qbhOK )
			inputDelay = 0.0;

		// Try to register the boolean input ports as clocks.
		int clk_is_clock = esc_link_clockgen( &clk, sc_time( 0, SC_NS ), module_path, sim_domain, "clk" );
		int rst_is_clock = esc_link_clockgen( &rst, sc_time( 0, SC_NS ), module_path, sim_domain, "rst" );
		int reg_target_AWVALID_is_clock = esc_link_clockgen( &reg_target_AWVALID, sc_time( 0, SC_NS ), module_path, sim_domain, "reg_target_AWVALID" );
		int reg_target_WVALID_is_clock = esc_link_clockgen( &reg_target_WVALID, sc_time( 0, SC_NS ), module_path, sim_domain, "reg_target_WVALID" );
		int reg_target_BREADY_is_clock = esc_link_clockgen( &reg_target_BREADY, sc_time( 0, SC_NS ), module_path, sim_domain, "reg_target_BREADY" );
		int reg_target_ARVALID_is_clock = esc_link_clockgen( &reg_target_ARVALID, sc_time( 0, SC_NS ), module_path, sim_domain, "reg_target_ARVALID" );
		int reg_target_RREADY_is_clock = esc_link_clockgen( &reg_target_RREADY, sc_time( 0, SC_NS ), module_path, sim_domain, "reg_target_RREADY" );
		int dma_initiator_AWREADY_is_clock = esc_link_clockgen( &dma_initiator_AWREADY, sc_time( 0, SC_NS ), module_path, sim_domain, "dma_initiator_AWREADY" );
		int dma_initiator_WREADY_is_clock = esc_link_clockgen( &dma_initiator_WREADY, sc_time( 0, SC_NS ), module_path, sim_domain, "dma_initiator_WREADY" );
		int dma_initiator_BVALID_is_clock = esc_link_clockgen( &dma_initiator_BVALID, sc_time( 0, SC_NS ), module_path, sim_domain, "dma_initiator_BVALID" );
		int dma_initiator_ARREADY_is_clock = esc_link_clockgen( &dma_initiator_ARREADY, sc_time( 0, SC_NS ), module_path, sim_domain, "dma_initiator_ARREADY" );
		int dma_initiator_RVALID_is_clock = esc_link_clockgen( &dma_initiator_RVALID, sc_time( 0, SC_NS ), module_path, sim_domain, "dma_initiator_RVALID" );
		int dma_initiator_RLAST_is_clock = esc_link_clockgen( &dma_initiator_RLAST, sc_time( 0, SC_NS ), module_path, sim_domain, "dma_initiator_RLAST" );

		esc_link_signals( &rst, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &irq, module_path, sim_domain, true );
		esc_link_signals( &reg_target_AWVALID, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &reg_target_AWADDR, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &reg_target_AWREADY, module_path, sim_domain, true );
		esc_link_signals( &reg_target_AWPROT, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &reg_target_WVALID, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &reg_target_WSTRB, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &reg_target_WDATA, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &reg_target_WREADY, module_path, sim_domain, true );
		esc_link_signals( &reg_target_BREADY, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &reg_target_BVALID, module_path, sim_domain, true );
		esc_link_signals( &reg_target_BRESP, module_path, sim_domain, true );
		esc_link_signals( &reg_target_ARVALID, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &reg_target_ARADDR, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &reg_target_ARREADY, module_path, sim_domain, true );
		esc_link_signals( &reg_target_ARPROT, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &reg_target_RREADY, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &reg_target_RVALID, module_path, sim_domain, true );
		esc_link_signals( &reg_target_RDATA, module_path, sim_domain, true );
		esc_link_signals( &reg_target_RRESP, module_path, sim_domain, true );
		esc_link_signals( &dma_initiator_AWVALID, module_path, sim_domain, true );
		esc_link_signals( &dma_initiator_AWLEN, module_path, sim_domain, true );
		esc_link_signals( &dma_initiator_AWSIZE, module_path, sim_domain, true );
		esc_link_signals( &dma_initiator_AWBURST, module_path, sim_domain, true );
		esc_link_signals( &dma_initiator_AWID, module_path, sim_domain, true );
		esc_link_signals( &dma_initiator_AWADDR, module_path, sim_domain, true );
		esc_link_signals( &dma_initiator_AWREADY, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &dma_initiator_AWLOCK, module_path, sim_domain, true );
		esc_link_signals( &dma_initiator_AWCACHE, module_path, sim_domain, true );
		esc_link_signals( &dma_initiator_AWPROT, module_path, sim_domain, true );
		esc_link_signals( &dma_initiator_AWQOS, module_path, sim_domain, true );
		esc_link_signals( &dma_initiator_AWREGION, module_path, sim_domain, true );
		esc_link_signals( &dma_initiator_WVALID, module_path, sim_domain, true );
		esc_link_signals( &dma_initiator_WSTRB, module_path, sim_domain, true );
		esc_link_signals( &dma_initiator_WDATA, module_path, sim_domain, true );
		esc_link_signals( &dma_initiator_WLAST, module_path, sim_domain, true );
		esc_link_signals( &dma_initiator_WREADY, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &dma_initiator_BREADY, module_path, sim_domain, true );
		esc_link_signals( &dma_initiator_BID, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &dma_initiator_BVALID, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &dma_initiator_BRESP, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &dma_initiator_ARVALID, module_path, sim_domain, true );
		esc_link_signals( &dma_initiator_ARLEN, module_path, sim_domain, true );
		esc_link_signals( &dma_initiator_ARSIZE, module_path, sim_domain, true );
		esc_link_signals( &dma_initiator_ARBURST, module_path, sim_domain, true );
		esc_link_signals( &dma_initiator_ARID, module_path, sim_domain, true );
		esc_link_signals( &dma_initiator_ARADDR, module_path, sim_domain, true );
		esc_link_signals( &dma_initiator_ARREADY, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &dma_initiator_ARLOCK, module_path, sim_domain, true );
		esc_link_signals( &dma_initiator_ARCACHE, module_path, sim_domain, true );
		esc_link_signals( &dma_initiator_ARPROT, module_path, sim_domain, true );
		esc_link_signals( &dma_initiator_ARQOS, module_path, sim_domain, true );
		esc_link_signals( &dma_initiator_ARREGION, module_path, sim_domain, true );
		esc_link_signals( &dma_initiator_RREADY, module_path, sim_domain, true );
		esc_link_signals( &dma_initiator_RVALID, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &dma_initiator_RID, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &dma_initiator_RDATA, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &dma_initiator_RRESP, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &dma_initiator_RLAST, module_path, sim_domain, true, inputDelay );
		

		if ( clk_is_clock )
		{
			sc_signal_in_if< bool > *clock_inif = clk[0];
			sc_clock *clock_module = dynamic_cast<sc_clock*>(clock_inif);
			esc_hub_register_clock( clock_module, esc_alledge, 0, module_path, sim_domain, clk.basename() );
			++registeredClocks;
		} else if ( qbhGetPortUsedAsClock( qbhEmptyHandle, "sha", "clk", scName ) ) {
			esc_report_error( esc_error, "The port 'clk' on module 'sha'\n\tis used as a clock in the design,\n\tbut is not connected to an sc_clock");
		}
		if ( rst_is_clock )
		{
			sc_signal_in_if< bool > *clock_inif = rst[0];
			sc_clock *clock_module = dynamic_cast<sc_clock*>(clock_inif);
			esc_hub_register_clock( clock_module, esc_alledge, 0, module_path, sim_domain, rst.basename() );
			++registeredClocks;
		} else if ( qbhGetPortUsedAsClock( qbhEmptyHandle, "sha", "rst", scName ) ) {
			esc_report_error( esc_error, "The port 'rst' on module 'sha'\n\tis used as a clock in the design,\n\tbut is not connected to an sc_clock");
		}
		if ( reg_target_AWVALID_is_clock )
		{
			sc_signal_in_if< bool > *clock_inif = reg_target_AWVALID[0];
			sc_clock *clock_module = dynamic_cast<sc_clock*>(clock_inif);
			esc_hub_register_clock( clock_module, esc_alledge, 0, module_path, sim_domain, reg_target_AWVALID.basename() );
			++registeredClocks;
		} else if ( qbhGetPortUsedAsClock( qbhEmptyHandle, "sha", "AWVALID", scName ) ) {
			esc_report_error( esc_error, "The port 'AWVALID' on module 'sha'\n\tis used as a clock in the design,\n\tbut is not connected to an sc_clock");
		}
		if ( reg_target_WVALID_is_clock )
		{
			sc_signal_in_if< bool > *clock_inif = reg_target_WVALID[0];
			sc_clock *clock_module = dynamic_cast<sc_clock*>(clock_inif);
			esc_hub_register_clock( clock_module, esc_alledge, 0, module_path, sim_domain, reg_target_WVALID.basename() );
			++registeredClocks;
		} else if ( qbhGetPortUsedAsClock( qbhEmptyHandle, "sha", "WVALID", scName ) ) {
			esc_report_error( esc_error, "The port 'WVALID' on module 'sha'\n\tis used as a clock in the design,\n\tbut is not connected to an sc_clock");
		}
		if ( reg_target_BREADY_is_clock )
		{
			sc_signal_in_if< bool > *clock_inif = reg_target_BREADY[0];
			sc_clock *clock_module = dynamic_cast<sc_clock*>(clock_inif);
			esc_hub_register_clock( clock_module, esc_alledge, 0, module_path, sim_domain, reg_target_BREADY.basename() );
			++registeredClocks;
		} else if ( qbhGetPortUsedAsClock( qbhEmptyHandle, "sha", "BREADY", scName ) ) {
			esc_report_error( esc_error, "The port 'BREADY' on module 'sha'\n\tis used as a clock in the design,\n\tbut is not connected to an sc_clock");
		}
		if ( reg_target_ARVALID_is_clock )
		{
			sc_signal_in_if< bool > *clock_inif = reg_target_ARVALID[0];
			sc_clock *clock_module = dynamic_cast<sc_clock*>(clock_inif);
			esc_hub_register_clock( clock_module, esc_alledge, 0, module_path, sim_domain, reg_target_ARVALID.basename() );
			++registeredClocks;
		} else if ( qbhGetPortUsedAsClock( qbhEmptyHandle, "sha", "ARVALID", scName ) ) {
			esc_report_error( esc_error, "The port 'ARVALID' on module 'sha'\n\tis used as a clock in the design,\n\tbut is not connected to an sc_clock");
		}
		if ( reg_target_RREADY_is_clock )
		{
			sc_signal_in_if< bool > *clock_inif = reg_target_RREADY[0];
			sc_clock *clock_module = dynamic_cast<sc_clock*>(clock_inif);
			esc_hub_register_clock( clock_module, esc_alledge, 0, module_path, sim_domain, reg_target_RREADY.basename() );
			++registeredClocks;
		} else if ( qbhGetPortUsedAsClock( qbhEmptyHandle, "sha", "RREADY", scName ) ) {
			esc_report_error( esc_error, "The port 'RREADY' on module 'sha'\n\tis used as a clock in the design,\n\tbut is not connected to an sc_clock");
		}
		if ( dma_initiator_AWREADY_is_clock )
		{
			sc_signal_in_if< bool > *clock_inif = dma_initiator_AWREADY[0];
			sc_clock *clock_module = dynamic_cast<sc_clock*>(clock_inif);
			esc_hub_register_clock( clock_module, esc_alledge, 0, module_path, sim_domain, dma_initiator_AWREADY.basename() );
			++registeredClocks;
		} else if ( qbhGetPortUsedAsClock( qbhEmptyHandle, "sha", "AWREADY", scName ) ) {
			esc_report_error( esc_error, "The port 'AWREADY' on module 'sha'\n\tis used as a clock in the design,\n\tbut is not connected to an sc_clock");
		}
		if ( dma_initiator_WREADY_is_clock )
		{
			sc_signal_in_if< bool > *clock_inif = dma_initiator_WREADY[0];
			sc_clock *clock_module = dynamic_cast<sc_clock*>(clock_inif);
			esc_hub_register_clock( clock_module, esc_alledge, 0, module_path, sim_domain, dma_initiator_WREADY.basename() );
			++registeredClocks;
		} else if ( qbhGetPortUsedAsClock( qbhEmptyHandle, "sha", "WREADY", scName ) ) {
			esc_report_error( esc_error, "The port 'WREADY' on module 'sha'\n\tis used as a clock in the design,\n\tbut is not connected to an sc_clock");
		}
		if ( dma_initiator_BVALID_is_clock )
		{
			sc_signal_in_if< bool > *clock_inif = dma_initiator_BVALID[0];
			sc_clock *clock_module = dynamic_cast<sc_clock*>(clock_inif);
			esc_hub_register_clock( clock_module, esc_alledge, 0, module_path, sim_domain, dma_initiator_BVALID.basename() );
			++registeredClocks;
		} else if ( qbhGetPortUsedAsClock( qbhEmptyHandle, "sha", "BVALID", scName ) ) {
			esc_report_error( esc_error, "The port 'BVALID' on module 'sha'\n\tis used as a clock in the design,\n\tbut is not connected to an sc_clock");
		}
		if ( dma_initiator_ARREADY_is_clock )
		{
			sc_signal_in_if< bool > *clock_inif = dma_initiator_ARREADY[0];
			sc_clock *clock_module = dynamic_cast<sc_clock*>(clock_inif);
			esc_hub_register_clock( clock_module, esc_alledge, 0, module_path, sim_domain, dma_initiator_ARREADY.basename() );
			++registeredClocks;
		} else if ( qbhGetPortUsedAsClock( qbhEmptyHandle, "sha", "ARREADY", scName ) ) {
			esc_report_error( esc_error, "The port 'ARREADY' on module 'sha'\n\tis used as a clock in the design,\n\tbut is not connected to an sc_clock");
		}
		if ( dma_initiator_RVALID_is_clock )
		{
			sc_signal_in_if< bool > *clock_inif = dma_initiator_RVALID[0];
			sc_clock *clock_module = dynamic_cast<sc_clock*>(clock_inif);
			esc_hub_register_clock( clock_module, esc_alledge, 0, module_path, sim_domain, dma_initiator_RVALID.basename() );
			++registeredClocks;
		} else if ( qbhGetPortUsedAsClock( qbhEmptyHandle, "sha", "RVALID", scName ) ) {
			esc_report_error( esc_error, "The port 'RVALID' on module 'sha'\n\tis used as a clock in the design,\n\tbut is not connected to an sc_clock");
		}
		if ( dma_initiator_RLAST_is_clock )
		{
			sc_signal_in_if< bool > *clock_inif = dma_initiator_RLAST[0];
			sc_clock *clock_module = dynamic_cast<sc_clock*>(clock_inif);
			esc_hub_register_clock( clock_module, esc_alledge, 0, module_path, sim_domain, dma_initiator_RLAST.basename() );
			++registeredClocks;
		} else if ( qbhGetPortUsedAsClock( qbhEmptyHandle, "sha", "RLAST", scName ) ) {
			esc_report_error( esc_error, "The port 'RLAST' on module 'sha'\n\tis used as a clock in the design,\n\tbut is not connected to an sc_clock");
		}


        if ( registeredClocks == 0 )
		{
			esc_report_error( esc_fatal, 
				"The clock port in module sha must have\n"
				"an sc_clock bound to it to make cosimulation work" );
		}
#endif
    }

#ifdef NC_SYSTEMC
    const char* hdl_name() const { return "sha_nc_cosim"; } 
    sha_cosim( sc_module_name name )
        : ncsc_foreign_module(name)
#else
	sha_cosim( sc_module_name in_name=sc_module_name(sc_gen_unique_name(" sha") ) )
		: sc_module(in_name)
#endif
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
		  	

    {
    };
};

int sha_cosim::numLinked = 0;
sha_cosim::StringPair sha_cosim::instanceNames[] = {
	{ NULL, NULL, false } };

#endif
