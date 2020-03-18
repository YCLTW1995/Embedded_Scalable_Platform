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

#if defined(CYNTHVLG)


#ifndef BDW_PORTS_ONLY
#define BDW_PORTS_ONLY 1
#endif


#include	"sha_rtl.cpp"

#else 

#if defined(BDW_HUB)

#include "esc.h"

#if defined(BDW_RTL) || defined(COWARE_RTL_sha)

#define BDW_AUTO_KNOWN 1 


#ifndef BDW_PORTS_ONLY
#define BDW_PORTS_ONLY 1
#endif


#undef sha
#define sha sha_rtl
#	include	"sha_rtl.cpp"
#undef sha


#ifdef BDW_PORTS_ONLY
#undef BDW_PORTS_ONLY
#endif



#elif defined(BDW_HOIST) 
#else

#endif
#ifdef BDW_COWARE
#include	"sha_coware.h"
#else
#include	"sha_cosim.h"
#endif

// include for cycle-accurate verilator simulation
#include    "sha_cycsim.h"



// Include the source for the behavioral model so it will be compiled.
#include	"../src/sha.cpp"


#define		sha_INTERNAL


#include	"sha_wrap.h"

// this global pointer indicates whether or not the Verilator cycsim wrapper is present
sha_cycsim* (*sha_cycsim_factory_p)() = 0;

#define MAX_SIMCONFIG_LENGTH 128

#if BDW_WRITEFSDB == 1

#if defined(NC_SYSTEMC) && defined(BDW_NCSC_VER) && BDW_NCSC_VER > 102
#include "fsdb_nc_mix.h"
#else
#include "fsdb_trace_file.h"
#endif 
#if BDW_USE_SCV
#include "scv.h"
#include "scv_tr_fsdb.h"
#endif

#endif /* BDW_WRITEFSDB */

inline void esc_open_fsdb_trace( const char *file_name = "systemc" );
inline void esc_close_fsdb_trace();
inline void esc_close_fsdb_scv_trace();

// The following threads are used to connect structured ports to the actual
// RTL ports

const char * sha_wrapper::simConfigName()
{
	static char defineBuf[MAX_SIMCONFIG_LENGTH];
	const char *simConfig = NULL;
	if ( qbhGetDefine( "BDW_SIM_CONFIG", defineBuf, MAX_SIMCONFIG_LENGTH ) == qbhOK )
	{
		simConfig = defineBuf;
	}
	else
	{
		simConfig = getenv( "BDW_SIM_CONFIG" );
	}

	if ( simConfig == NULL )
	{
		esc_report_error( esc_fatal, "BDW_SIM_CONFIG needs to be set" );
	}

	return simConfig;
}

enum sha_wrapper::Representation sha_wrapper::lookupRepresentation( const char* instName )
{
	const char *simConfig = simConfigName();

	if ( simConfig == NULL )
		return BDWRep_None;

	Representation result;

	qbhProjectHandle hProj;
	qbhError err = qbhGetCurrentProject( &hProj );
	if ( err == qbhErrorNoProject )
	{
		err = qbhOpenProject( "project.tcl", &hProj );

		if ( err != qbhOK )
		{
			esc_report_error( esc_fatal, "could not open project file %s",
							  "project.tcl" );
			return BDWRep_None;
		}
	}

	int iresult = 0;
	err = qbhGetRepresentation(hProj, "sha", simConfig, instName, &iresult );
	result = (Representation)iresult;

	if ( err == qbhOK )
		return result;

	// If this module isn't mentioned in the simConfig, assume it's behavioral.
	if ( err == qbhErrorNotFound ) {
		return BDWRep_Behavioral;
	} else if ( err == qbhErrorBadInstName ) {
		if (instName && *instName) {
			const char* leaf = strrchr( instName, '.' ) + 1;
			esc_report_error( esc_warning, "Instance names were specified for module '%s' in simConfig '%s', but they did not "
			                    "match the actal instance names in the RTL.  Try '%s' or '%s'. Simulating '%s' as BEH.\n",
								 "sha", simConfig, instName, leaf,  "sha" );
		}
		return BDWRep_Behavioral;
	}

    // If we couldn't get a license, then just exit.
    if ( err == qbhErrorNoLicense )
        exit(1);

	return BDWRep_None;
}

void sha_wrapper::InitInstances(  )
{
    enum sha_wrapper::Representation rep =
		sha_wrapper::lookupRepresentation( name() );

	esc_log_wrapper_inst( "sha" );
	esc_log_representation( "sha", name(), rep );

	

	switch ( rep )
	{
		case BDWRep_Gates:
		    sha_cosim0 = new sha_cosim( "sha" );

		    sha_cosim0->clk(clk);
		    sha_cosim0->rst(rst);
		    sha_cosim0->irq(irq);
		    sha_cosim0->reg_target_AWVALID(reg_target.AWVALID);
		    sha_cosim0->reg_target_AWADDR(reg_target.AWADDR);
		    sha_cosim0->reg_target_AWREADY(reg_target.AWREADY);
		    sha_cosim0->reg_target_AWPROT(reg_target.AWPROT);
		    sha_cosim0->reg_target_WVALID(reg_target.WVALID);
		    sha_cosim0->reg_target_WSTRB(reg_target.WSTRB);
		    sha_cosim0->reg_target_WDATA(reg_target.WDATA);
		    sha_cosim0->reg_target_WREADY(reg_target.WREADY);
		    sha_cosim0->reg_target_BREADY(reg_target.BREADY);
		    sha_cosim0->reg_target_BVALID(reg_target.BVALID);
		    sha_cosim0->reg_target_BRESP(reg_target.BRESP);
		    sha_cosim0->reg_target_ARVALID(reg_target.ARVALID);
		    sha_cosim0->reg_target_ARADDR(reg_target.ARADDR);
		    sha_cosim0->reg_target_ARREADY(reg_target.ARREADY);
		    sha_cosim0->reg_target_ARPROT(reg_target.ARPROT);
		    sha_cosim0->reg_target_RREADY(reg_target.RREADY);
		    sha_cosim0->reg_target_RVALID(reg_target.RVALID);
		    sha_cosim0->reg_target_RDATA(reg_target.RDATA);
		    sha_cosim0->reg_target_RRESP(reg_target.RRESP);
		    sha_cosim0->dma_initiator_AWVALID(dma_initiator.AWVALID);
		    sha_cosim0->dma_initiator_AWLEN(dma_initiator.AWLEN);
		    sha_cosim0->dma_initiator_AWSIZE(dma_initiator.AWSIZE);
		    sha_cosim0->dma_initiator_AWBURST(dma_initiator.AWBURST);
		    sha_cosim0->dma_initiator_AWID(dma_initiator.AWID);
		    sha_cosim0->dma_initiator_AWADDR(dma_initiator.AWADDR);
		    sha_cosim0->dma_initiator_AWREADY(dma_initiator.AWREADY);
		    sha_cosim0->dma_initiator_AWLOCK(dma_initiator.AWLOCK);
		    sha_cosim0->dma_initiator_AWCACHE(dma_initiator.AWCACHE);
		    sha_cosim0->dma_initiator_AWPROT(dma_initiator.AWPROT);
		    sha_cosim0->dma_initiator_AWQOS(dma_initiator.AWQOS);
		    sha_cosim0->dma_initiator_AWREGION(dma_initiator.AWREGION);
		    sha_cosim0->dma_initiator_WVALID(dma_initiator.WVALID);
		    sha_cosim0->dma_initiator_WSTRB(dma_initiator.WSTRB);
		    sha_cosim0->dma_initiator_WDATA(dma_initiator.WDATA);
		    sha_cosim0->dma_initiator_WLAST(dma_initiator.WLAST);
		    sha_cosim0->dma_initiator_WREADY(dma_initiator.WREADY);
		    sha_cosim0->dma_initiator_BREADY(dma_initiator.BREADY);
		    sha_cosim0->dma_initiator_BID(dma_initiator.BID);
		    sha_cosim0->dma_initiator_BVALID(dma_initiator.BVALID);
		    sha_cosim0->dma_initiator_BRESP(dma_initiator.BRESP);
		    sha_cosim0->dma_initiator_ARVALID(dma_initiator.ARVALID);
		    sha_cosim0->dma_initiator_ARLEN(dma_initiator.ARLEN);
		    sha_cosim0->dma_initiator_ARSIZE(dma_initiator.ARSIZE);
		    sha_cosim0->dma_initiator_ARBURST(dma_initiator.ARBURST);
		    sha_cosim0->dma_initiator_ARID(dma_initiator.ARID);
		    sha_cosim0->dma_initiator_ARADDR(dma_initiator.ARADDR);
		    sha_cosim0->dma_initiator_ARREADY(dma_initiator.ARREADY);
		    sha_cosim0->dma_initiator_ARLOCK(dma_initiator.ARLOCK);
		    sha_cosim0->dma_initiator_ARCACHE(dma_initiator.ARCACHE);
		    sha_cosim0->dma_initiator_ARPROT(dma_initiator.ARPROT);
		    sha_cosim0->dma_initiator_ARQOS(dma_initiator.ARQOS);
		    sha_cosim0->dma_initiator_ARREGION(dma_initiator.ARREGION);
		    sha_cosim0->dma_initiator_RREADY(dma_initiator.RREADY);
		    sha_cosim0->dma_initiator_RVALID(dma_initiator.RVALID);
		    sha_cosim0->dma_initiator_RID(dma_initiator.RID);
		    sha_cosim0->dma_initiator_RDATA(dma_initiator.RDATA);
		    sha_cosim0->dma_initiator_RRESP(dma_initiator.RRESP);
		    sha_cosim0->dma_initiator_RLAST(dma_initiator.RLAST);

			break;
		case BDWRep_RTL_HDL:
		    sha_cosim0 = new sha_cosim( "sha" );

		    sha_cosim0->clk(clk);
		    sha_cosim0->rst(rst);
		    sha_cosim0->irq(irq);
		    sha_cosim0->reg_target_AWVALID(reg_target.AWVALID);
		    sha_cosim0->reg_target_AWADDR(reg_target.AWADDR);
		    sha_cosim0->reg_target_AWREADY(reg_target.AWREADY);
		    sha_cosim0->reg_target_AWPROT(reg_target.AWPROT);
		    sha_cosim0->reg_target_WVALID(reg_target.WVALID);
		    sha_cosim0->reg_target_WSTRB(reg_target.WSTRB);
		    sha_cosim0->reg_target_WDATA(reg_target.WDATA);
		    sha_cosim0->reg_target_WREADY(reg_target.WREADY);
		    sha_cosim0->reg_target_BREADY(reg_target.BREADY);
		    sha_cosim0->reg_target_BVALID(reg_target.BVALID);
		    sha_cosim0->reg_target_BRESP(reg_target.BRESP);
		    sha_cosim0->reg_target_ARVALID(reg_target.ARVALID);
		    sha_cosim0->reg_target_ARADDR(reg_target.ARADDR);
		    sha_cosim0->reg_target_ARREADY(reg_target.ARREADY);
		    sha_cosim0->reg_target_ARPROT(reg_target.ARPROT);
		    sha_cosim0->reg_target_RREADY(reg_target.RREADY);
		    sha_cosim0->reg_target_RVALID(reg_target.RVALID);
		    sha_cosim0->reg_target_RDATA(reg_target.RDATA);
		    sha_cosim0->reg_target_RRESP(reg_target.RRESP);
		    sha_cosim0->dma_initiator_AWVALID(dma_initiator.AWVALID);
		    sha_cosim0->dma_initiator_AWLEN(dma_initiator.AWLEN);
		    sha_cosim0->dma_initiator_AWSIZE(dma_initiator.AWSIZE);
		    sha_cosim0->dma_initiator_AWBURST(dma_initiator.AWBURST);
		    sha_cosim0->dma_initiator_AWID(dma_initiator.AWID);
		    sha_cosim0->dma_initiator_AWADDR(dma_initiator.AWADDR);
		    sha_cosim0->dma_initiator_AWREADY(dma_initiator.AWREADY);
		    sha_cosim0->dma_initiator_AWLOCK(dma_initiator.AWLOCK);
		    sha_cosim0->dma_initiator_AWCACHE(dma_initiator.AWCACHE);
		    sha_cosim0->dma_initiator_AWPROT(dma_initiator.AWPROT);
		    sha_cosim0->dma_initiator_AWQOS(dma_initiator.AWQOS);
		    sha_cosim0->dma_initiator_AWREGION(dma_initiator.AWREGION);
		    sha_cosim0->dma_initiator_WVALID(dma_initiator.WVALID);
		    sha_cosim0->dma_initiator_WSTRB(dma_initiator.WSTRB);
		    sha_cosim0->dma_initiator_WDATA(dma_initiator.WDATA);
		    sha_cosim0->dma_initiator_WLAST(dma_initiator.WLAST);
		    sha_cosim0->dma_initiator_WREADY(dma_initiator.WREADY);
		    sha_cosim0->dma_initiator_BREADY(dma_initiator.BREADY);
		    sha_cosim0->dma_initiator_BID(dma_initiator.BID);
		    sha_cosim0->dma_initiator_BVALID(dma_initiator.BVALID);
		    sha_cosim0->dma_initiator_BRESP(dma_initiator.BRESP);
		    sha_cosim0->dma_initiator_ARVALID(dma_initiator.ARVALID);
		    sha_cosim0->dma_initiator_ARLEN(dma_initiator.ARLEN);
		    sha_cosim0->dma_initiator_ARSIZE(dma_initiator.ARSIZE);
		    sha_cosim0->dma_initiator_ARBURST(dma_initiator.ARBURST);
		    sha_cosim0->dma_initiator_ARID(dma_initiator.ARID);
		    sha_cosim0->dma_initiator_ARADDR(dma_initiator.ARADDR);
		    sha_cosim0->dma_initiator_ARREADY(dma_initiator.ARREADY);
		    sha_cosim0->dma_initiator_ARLOCK(dma_initiator.ARLOCK);
		    sha_cosim0->dma_initiator_ARCACHE(dma_initiator.ARCACHE);
		    sha_cosim0->dma_initiator_ARPROT(dma_initiator.ARPROT);
		    sha_cosim0->dma_initiator_ARQOS(dma_initiator.ARQOS);
		    sha_cosim0->dma_initiator_ARREGION(dma_initiator.ARREGION);
		    sha_cosim0->dma_initiator_RREADY(dma_initiator.RREADY);
		    sha_cosim0->dma_initiator_RVALID(dma_initiator.RVALID);
		    sha_cosim0->dma_initiator_RID(dma_initiator.RID);
		    sha_cosim0->dma_initiator_RDATA(dma_initiator.RDATA);
		    sha_cosim0->dma_initiator_RRESP(dma_initiator.RRESP);
		    sha_cosim0->dma_initiator_RLAST(dma_initiator.RLAST);

			break;
        case BDWRep_CYC_HDL:
            if ( sha_cycsim_factory_p )
                sha_cycsim0 = sha_cycsim_factory_p();
            else
            {
                esc_report_error( esc_fatal, "verilator_produced files not available for module sha");
                return;
            }

            esc_report_error( esc_note, " using verilator model for module \"sha\"");

		    sha_cycsim0->clk(clk);
		    sha_cycsim0->rst(rst);
		    sha_cycsim0->irq(irq);
		    sha_cycsim0->reg_target_AWVALID(reg_target.AWVALID);
		    sha_cycsim0->reg_target_AWADDR(reg_target.AWADDR);
		    sha_cycsim0->reg_target_AWREADY(reg_target.AWREADY);
		    sha_cycsim0->reg_target_AWPROT(reg_target.AWPROT);
		    sha_cycsim0->reg_target_WVALID(reg_target.WVALID);
		    sha_cycsim0->reg_target_WSTRB(reg_target.WSTRB);
		    sha_cycsim0->reg_target_WDATA(reg_target.WDATA);
		    sha_cycsim0->reg_target_WREADY(reg_target.WREADY);
		    sha_cycsim0->reg_target_BREADY(reg_target.BREADY);
		    sha_cycsim0->reg_target_BVALID(reg_target.BVALID);
		    sha_cycsim0->reg_target_BRESP(reg_target.BRESP);
		    sha_cycsim0->reg_target_ARVALID(reg_target.ARVALID);
		    sha_cycsim0->reg_target_ARADDR(reg_target.ARADDR);
		    sha_cycsim0->reg_target_ARREADY(reg_target.ARREADY);
		    sha_cycsim0->reg_target_ARPROT(reg_target.ARPROT);
		    sha_cycsim0->reg_target_RREADY(reg_target.RREADY);
		    sha_cycsim0->reg_target_RVALID(reg_target.RVALID);
		    sha_cycsim0->reg_target_RDATA(reg_target.RDATA);
		    sha_cycsim0->reg_target_RRESP(reg_target.RRESP);
		    sha_cycsim0->dma_initiator_AWVALID(dma_initiator.AWVALID);
		    sha_cycsim0->dma_initiator_AWLEN(dma_initiator.AWLEN);
		    sha_cycsim0->dma_initiator_AWSIZE(dma_initiator.AWSIZE);
		    sha_cycsim0->dma_initiator_AWBURST(dma_initiator.AWBURST);
		    sha_cycsim0->dma_initiator_AWID(dma_initiator.AWID);
		    sha_cycsim0->dma_initiator_AWADDR(dma_initiator.AWADDR);
		    sha_cycsim0->dma_initiator_AWREADY(dma_initiator.AWREADY);
		    sha_cycsim0->dma_initiator_AWLOCK(dma_initiator.AWLOCK);
		    sha_cycsim0->dma_initiator_AWCACHE(dma_initiator.AWCACHE);
		    sha_cycsim0->dma_initiator_AWPROT(dma_initiator.AWPROT);
		    sha_cycsim0->dma_initiator_AWQOS(dma_initiator.AWQOS);
		    sha_cycsim0->dma_initiator_AWREGION(dma_initiator.AWREGION);
		    sha_cycsim0->dma_initiator_WVALID(dma_initiator.WVALID);
		    sha_cycsim0->dma_initiator_WSTRB(dma_initiator.WSTRB);
		    sha_cycsim0->dma_initiator_WDATA(dma_initiator.WDATA);
		    sha_cycsim0->dma_initiator_WLAST(dma_initiator.WLAST);
		    sha_cycsim0->dma_initiator_WREADY(dma_initiator.WREADY);
		    sha_cycsim0->dma_initiator_BREADY(dma_initiator.BREADY);
		    sha_cycsim0->dma_initiator_BID(dma_initiator.BID);
		    sha_cycsim0->dma_initiator_BVALID(dma_initiator.BVALID);
		    sha_cycsim0->dma_initiator_BRESP(dma_initiator.BRESP);
		    sha_cycsim0->dma_initiator_ARVALID(dma_initiator.ARVALID);
		    sha_cycsim0->dma_initiator_ARLEN(dma_initiator.ARLEN);
		    sha_cycsim0->dma_initiator_ARSIZE(dma_initiator.ARSIZE);
		    sha_cycsim0->dma_initiator_ARBURST(dma_initiator.ARBURST);
		    sha_cycsim0->dma_initiator_ARID(dma_initiator.ARID);
		    sha_cycsim0->dma_initiator_ARADDR(dma_initiator.ARADDR);
		    sha_cycsim0->dma_initiator_ARREADY(dma_initiator.ARREADY);
		    sha_cycsim0->dma_initiator_ARLOCK(dma_initiator.ARLOCK);
		    sha_cycsim0->dma_initiator_ARCACHE(dma_initiator.ARCACHE);
		    sha_cycsim0->dma_initiator_ARPROT(dma_initiator.ARPROT);
		    sha_cycsim0->dma_initiator_ARQOS(dma_initiator.ARQOS);
		    sha_cycsim0->dma_initiator_ARREGION(dma_initiator.ARREGION);
		    sha_cycsim0->dma_initiator_RREADY(dma_initiator.RREADY);
		    sha_cycsim0->dma_initiator_RVALID(dma_initiator.RVALID);
		    sha_cycsim0->dma_initiator_RID(dma_initiator.RID);
		    sha_cycsim0->dma_initiator_RDATA(dma_initiator.RDATA);
		    sha_cycsim0->dma_initiator_RRESP(dma_initiator.RRESP);
		    sha_cycsim0->dma_initiator_RLAST(dma_initiator.RLAST);

			break;
#if defined(BDW_RTL) || defined(COWARE_RTL_sha)
		case BDWRep_RTL_C:
		    sha_rtl0 = new sha_rtl( "sha" );

		    sha_rtl0->clk(clk);
		    sha_rtl0->rst(rst);
		    sha_rtl0->irq(irq);
		    sha_rtl0->reg_target_AWVALID(reg_target.AWVALID);
		    sha_rtl0->reg_target_AWADDR(reg_target.AWADDR);
		    sha_rtl0->reg_target_AWREADY(reg_target.AWREADY);
		    sha_rtl0->reg_target_AWPROT(reg_target.AWPROT);
		    sha_rtl0->reg_target_WVALID(reg_target.WVALID);
		    sha_rtl0->reg_target_WSTRB(reg_target.WSTRB);
		    sha_rtl0->reg_target_WDATA(reg_target.WDATA);
		    sha_rtl0->reg_target_WREADY(reg_target.WREADY);
		    sha_rtl0->reg_target_BREADY(reg_target.BREADY);
		    sha_rtl0->reg_target_BVALID(reg_target.BVALID);
		    sha_rtl0->reg_target_BRESP(reg_target.BRESP);
		    sha_rtl0->reg_target_ARVALID(reg_target.ARVALID);
		    sha_rtl0->reg_target_ARADDR(reg_target.ARADDR);
		    sha_rtl0->reg_target_ARREADY(reg_target.ARREADY);
		    sha_rtl0->reg_target_ARPROT(reg_target.ARPROT);
		    sha_rtl0->reg_target_RREADY(reg_target.RREADY);
		    sha_rtl0->reg_target_RVALID(reg_target.RVALID);
		    sha_rtl0->reg_target_RDATA(reg_target.RDATA);
		    sha_rtl0->reg_target_RRESP(reg_target.RRESP);
		    sha_rtl0->dma_initiator_AWVALID(dma_initiator.AWVALID);
		    sha_rtl0->dma_initiator_AWLEN(dma_initiator.AWLEN);
		    sha_rtl0->dma_initiator_AWSIZE(dma_initiator.AWSIZE);
		    sha_rtl0->dma_initiator_AWBURST(dma_initiator.AWBURST);
		    sha_rtl0->dma_initiator_AWID(dma_initiator.AWID);
		    sha_rtl0->dma_initiator_AWADDR(dma_initiator.AWADDR);
		    sha_rtl0->dma_initiator_AWREADY(dma_initiator.AWREADY);
		    sha_rtl0->dma_initiator_AWLOCK(dma_initiator.AWLOCK);
		    sha_rtl0->dma_initiator_AWCACHE(dma_initiator.AWCACHE);
		    sha_rtl0->dma_initiator_AWPROT(dma_initiator.AWPROT);
		    sha_rtl0->dma_initiator_AWQOS(dma_initiator.AWQOS);
		    sha_rtl0->dma_initiator_AWREGION(dma_initiator.AWREGION);
		    sha_rtl0->dma_initiator_WVALID(dma_initiator.WVALID);
		    sha_rtl0->dma_initiator_WSTRB(dma_initiator.WSTRB);
		    sha_rtl0->dma_initiator_WDATA(dma_initiator.WDATA);
		    sha_rtl0->dma_initiator_WLAST(dma_initiator.WLAST);
		    sha_rtl0->dma_initiator_WREADY(dma_initiator.WREADY);
		    sha_rtl0->dma_initiator_BREADY(dma_initiator.BREADY);
		    sha_rtl0->dma_initiator_BID(dma_initiator.BID);
		    sha_rtl0->dma_initiator_BVALID(dma_initiator.BVALID);
		    sha_rtl0->dma_initiator_BRESP(dma_initiator.BRESP);
		    sha_rtl0->dma_initiator_ARVALID(dma_initiator.ARVALID);
		    sha_rtl0->dma_initiator_ARLEN(dma_initiator.ARLEN);
		    sha_rtl0->dma_initiator_ARSIZE(dma_initiator.ARSIZE);
		    sha_rtl0->dma_initiator_ARBURST(dma_initiator.ARBURST);
		    sha_rtl0->dma_initiator_ARID(dma_initiator.ARID);
		    sha_rtl0->dma_initiator_ARADDR(dma_initiator.ARADDR);
		    sha_rtl0->dma_initiator_ARREADY(dma_initiator.ARREADY);
		    sha_rtl0->dma_initiator_ARLOCK(dma_initiator.ARLOCK);
		    sha_rtl0->dma_initiator_ARCACHE(dma_initiator.ARCACHE);
		    sha_rtl0->dma_initiator_ARPROT(dma_initiator.ARPROT);
		    sha_rtl0->dma_initiator_ARQOS(dma_initiator.ARQOS);
		    sha_rtl0->dma_initiator_ARREGION(dma_initiator.ARREGION);
		    sha_rtl0->dma_initiator_RREADY(dma_initiator.RREADY);
		    sha_rtl0->dma_initiator_RVALID(dma_initiator.RVALID);
		    sha_rtl0->dma_initiator_RID(dma_initiator.RID);
		    sha_rtl0->dma_initiator_RDATA(dma_initiator.RDATA);
		    sha_rtl0->dma_initiator_RRESP(dma_initiator.RRESP);
		    sha_rtl0->dma_initiator_RLAST(dma_initiator.RLAST);


			{
			const char *simConfig = sha_wrapper::simConfigName();
			
			if ( simConfig != NULL )
				{
				qbhProjectHandle hProj;
				qbhError err = qbhGetCurrentProject( &hProj );
				if ( err == qbhErrorNoProject )
				{
					err = qbhOpenProject( "project.tcl", &hProj );
			
					if ( err != qbhOK )
					{
						esc_report_error( esc_fatal, "could not open project file %s",
											  "project.tcl" );
							return;
					}
				}
			
				if ( esc_trace_is_enabled( esc_trace_vcd ) ) {
					esc_get_vcd_trace_file();
				}
				if ( esc_trace_is_enabled( esc_trace_fsdb ) ) {
					esc_get_fsdb_trace_file();
				}
				}
			}

			break;
#endif
		case BDWRep_Behavioral:
		    sha0 = new sha( "sha" );

		    sha0->clk(clk);
		    sha0->rst(rst);
		    sha0->irq(irq);
		    sha0->reg_target.AWVALID(reg_target.AWVALID);
		    sha0->reg_target.AWADDR(reg_target.AWADDR);
		    sha0->reg_target.AWREADY(reg_target.AWREADY);
		    sha0->reg_target.AWPROT(reg_target.AWPROT);
		    sha0->reg_target.WVALID(reg_target.WVALID);
		    sha0->reg_target.WSTRB(reg_target.WSTRB);
		    sha0->reg_target.WDATA(reg_target.WDATA);
		    sha0->reg_target.WREADY(reg_target.WREADY);
		    sha0->reg_target.BREADY(reg_target.BREADY);
		    sha0->reg_target.BVALID(reg_target.BVALID);
		    sha0->reg_target.BRESP(reg_target.BRESP);
		    sha0->reg_target.ARVALID(reg_target.ARVALID);
		    sha0->reg_target.ARADDR(reg_target.ARADDR);
		    sha0->reg_target.ARREADY(reg_target.ARREADY);
		    sha0->reg_target.ARPROT(reg_target.ARPROT);
		    sha0->reg_target.RREADY(reg_target.RREADY);
		    sha0->reg_target.RVALID(reg_target.RVALID);
		    sha0->reg_target.RDATA(reg_target.RDATA);
		    sha0->reg_target.RRESP(reg_target.RRESP);
		    sha0->dma_initiator.AWVALID(dma_initiator.AWVALID);
		    sha0->dma_initiator.AWLEN(dma_initiator.AWLEN);
		    sha0->dma_initiator.AWSIZE(dma_initiator.AWSIZE);
		    sha0->dma_initiator.AWBURST(dma_initiator.AWBURST);
		    sha0->dma_initiator.AWID(dma_initiator.AWID);
		    sha0->dma_initiator.AWADDR(dma_initiator.AWADDR);
		    sha0->dma_initiator.AWREADY(dma_initiator.AWREADY);
		    sha0->dma_initiator.AWLOCK(dma_initiator.AWLOCK);
		    sha0->dma_initiator.AWCACHE(dma_initiator.AWCACHE);
		    sha0->dma_initiator.AWPROT(dma_initiator.AWPROT);
		    sha0->dma_initiator.AWQOS(dma_initiator.AWQOS);
		    sha0->dma_initiator.AWREGION(dma_initiator.AWREGION);
		    sha0->dma_initiator.WVALID(dma_initiator.WVALID);
		    sha0->dma_initiator.WSTRB(dma_initiator.WSTRB);
		    sha0->dma_initiator.WDATA(dma_initiator.WDATA);
		    sha0->dma_initiator.WLAST(dma_initiator.WLAST);
		    sha0->dma_initiator.WREADY(dma_initiator.WREADY);
		    sha0->dma_initiator.BREADY(dma_initiator.BREADY);
		    sha0->dma_initiator.BID(dma_initiator.BID);
		    sha0->dma_initiator.BVALID(dma_initiator.BVALID);
		    sha0->dma_initiator.BRESP(dma_initiator.BRESP);
		    sha0->dma_initiator.ARVALID(dma_initiator.ARVALID);
		    sha0->dma_initiator.ARLEN(dma_initiator.ARLEN);
		    sha0->dma_initiator.ARSIZE(dma_initiator.ARSIZE);
		    sha0->dma_initiator.ARBURST(dma_initiator.ARBURST);
		    sha0->dma_initiator.ARID(dma_initiator.ARID);
		    sha0->dma_initiator.ARADDR(dma_initiator.ARADDR);
		    sha0->dma_initiator.ARREADY(dma_initiator.ARREADY);
		    sha0->dma_initiator.ARLOCK(dma_initiator.ARLOCK);
		    sha0->dma_initiator.ARCACHE(dma_initiator.ARCACHE);
		    sha0->dma_initiator.ARPROT(dma_initiator.ARPROT);
		    sha0->dma_initiator.ARQOS(dma_initiator.ARQOS);
		    sha0->dma_initiator.ARREGION(dma_initiator.ARREGION);
		    sha0->dma_initiator.RREADY(dma_initiator.RREADY);
		    sha0->dma_initiator.RVALID(dma_initiator.RVALID);
		    sha0->dma_initiator.RID(dma_initiator.RID);
		    sha0->dma_initiator.RDATA(dma_initiator.RDATA);
		    sha0->dma_initiator.RRESP(dma_initiator.RRESP);
		    sha0->dma_initiator.RLAST(dma_initiator.RLAST);


			{
			const char *simConfig = sha_wrapper::simConfigName();
			
			if ( simConfig != NULL )
				{
				qbhProjectHandle hProj;
				qbhError err = qbhGetCurrentProject( &hProj );
				if ( err == qbhErrorNoProject )
				{
					err = qbhOpenProject( "project.tcl", &hProj );
			
					if ( err != qbhOK )
					{
						esc_report_error( esc_fatal, "could not open project file %s",
											  "project.tcl" );
							return;
					}
				}
			
				if ( esc_trace_is_enabled( esc_trace_vcd ) ) {
					esc_get_vcd_trace_file();
				}
				if ( esc_trace_is_enabled( esc_trace_fsdb ) ) {
					esc_get_fsdb_trace_file();
				}
				}
			}

			break;
		case BDWRep_None:
		default:
			esc_report_error( esc_error, "No representation could be determined for simulating instance %s. Please make sure that you used the right name string in the module constructor",
							  name() );
			break;
	}
}

void sha_wrapper::InitThreads()
{
	if ( !isBEH() )
	{
		
	}
}

void sha_wrapper::start_of_simulation()
{

#include <sha_trace.h>

    esc_multiple_writers_warning();
}

void sha_wrapper::CloseTrace()
{
	if ( esc_trace_is_enabled( esc_trace_vcd ) ) {
	esc_close_vcd_trace();
	}
	if ( esc_trace_is_enabled( esc_trace_fsdb ) ) {
		esc_close_fsdb_trace();
		if ( esc_trace_is_enabled( esc_trace_scv ) ) {
			esc_close_fsdb_scv_trace();
		}
	}
}

void sha_wrapper::end_of_simulation()
{
	CloseTrace();
}



void sha_wrapper::DeleteInstances()
{
    if (sha0)
    {
        delete sha0;
        sha0 = 0;
    }
    if (sha_cosim0)
    {
        delete sha_cosim0;
        sha_cosim0 = 0;
    }
    if (sha_cycsim0)
    {
        delete sha_cycsim0;
        sha_cycsim0 = 0;
    }
#if defined(BDW_RTL) || defined(COWARE_RTL_sha)
    if (sha_rtl0)
    {
        delete sha_rtl0;
        sha_rtl0 = 0;
    }
#endif
}

// The following threads are used to connect RTL ports to the actual
// structured ports

const char * sha_wrapper_r::simConfigName()
{
	static char defineBuf[MAX_SIMCONFIG_LENGTH];
	const char *simConfig = NULL;
	if ( qbhGetDefine( "BDW_SIM_CONFIG", defineBuf, MAX_SIMCONFIG_LENGTH ) == qbhOK )
	{
		simConfig = defineBuf;
	}
	else
	{
		simConfig = getenv( "BDW_SIM_CONFIG" );
	}

	if ( simConfig == NULL )
	{
		esc_report_error( esc_fatal, "BDW_SIM_CONFIG needs to be set" );
	}

	return simConfig;
}

enum sha_wrapper_r::Representation sha_wrapper_r::lookupRepresentation( const char* instName )
{
	const char *simConfig = simConfigName();

	if ( simConfig == NULL )
		return BDWRep_None;

	Representation result;

	qbhProjectHandle hProj;
	qbhError err = qbhGetCurrentProject( &hProj );
	if ( err == qbhErrorNoProject )
	{
		err = qbhOpenProject( "project.tcl", &hProj );

		if ( err != qbhOK )
		{
			esc_report_error( esc_fatal, "could not open project file %s",
							  "project.tcl" );
			return BDWRep_None;
		}
	}

	int iresult = 0;
	err = qbhGetRepresentation(hProj, "sha", simConfig, instName, &iresult );
	result = (Representation)iresult;

	if ( err == qbhOK )
		return result;

	// If this module isn't mentioned in the simConfig, assume it's behavioral.
	if ( err == qbhErrorNotFound )
		return BDWRep_Behavioral;

    // If we couldn't get a license, then just exit.
    if ( err == qbhErrorNoLicense )
        exit(1);

	return BDWRep_None;
}

void sha_wrapper_r::InitInstances()
{
    enum sha_wrapper_r::Representation rep =
		sha_wrapper_r::lookupRepresentation( name() );

	esc_log_wrapper_inst( "sha" );
	esc_log_representation( "sha", name(), rep );

	switch ( rep )
	{
		case BDWRep_Gates:
		    sha_cosim0 = new sha_cosim( "sha" );

		    sha_cosim0->clk(clk);
		    sha_cosim0->rst(rst);
		    sha_cosim0->irq(irq);
		    sha_cosim0->reg_target_AWVALID(reg_target_AWVALID);
		    sha_cosim0->reg_target_AWADDR(reg_target_AWADDR);
		    sha_cosim0->reg_target_AWREADY(reg_target_AWREADY);
		    sha_cosim0->reg_target_AWPROT(reg_target_AWPROT);
		    sha_cosim0->reg_target_WVALID(reg_target_WVALID);
		    sha_cosim0->reg_target_WSTRB(reg_target_WSTRB);
		    sha_cosim0->reg_target_WDATA(reg_target_WDATA);
		    sha_cosim0->reg_target_WREADY(reg_target_WREADY);
		    sha_cosim0->reg_target_BREADY(reg_target_BREADY);
		    sha_cosim0->reg_target_BVALID(reg_target_BVALID);
		    sha_cosim0->reg_target_BRESP(reg_target_BRESP);
		    sha_cosim0->reg_target_ARVALID(reg_target_ARVALID);
		    sha_cosim0->reg_target_ARADDR(reg_target_ARADDR);
		    sha_cosim0->reg_target_ARREADY(reg_target_ARREADY);
		    sha_cosim0->reg_target_ARPROT(reg_target_ARPROT);
		    sha_cosim0->reg_target_RREADY(reg_target_RREADY);
		    sha_cosim0->reg_target_RVALID(reg_target_RVALID);
		    sha_cosim0->reg_target_RDATA(reg_target_RDATA);
		    sha_cosim0->reg_target_RRESP(reg_target_RRESP);
		    sha_cosim0->dma_initiator_AWVALID(dma_initiator_AWVALID);
		    sha_cosim0->dma_initiator_AWLEN(dma_initiator_AWLEN);
		    sha_cosim0->dma_initiator_AWSIZE(dma_initiator_AWSIZE);
		    sha_cosim0->dma_initiator_AWBURST(dma_initiator_AWBURST);
		    sha_cosim0->dma_initiator_AWID(dma_initiator_AWID);
		    sha_cosim0->dma_initiator_AWADDR(dma_initiator_AWADDR);
		    sha_cosim0->dma_initiator_AWREADY(dma_initiator_AWREADY);
		    sha_cosim0->dma_initiator_AWLOCK(dma_initiator_AWLOCK);
		    sha_cosim0->dma_initiator_AWCACHE(dma_initiator_AWCACHE);
		    sha_cosim0->dma_initiator_AWPROT(dma_initiator_AWPROT);
		    sha_cosim0->dma_initiator_AWQOS(dma_initiator_AWQOS);
		    sha_cosim0->dma_initiator_AWREGION(dma_initiator_AWREGION);
		    sha_cosim0->dma_initiator_WVALID(dma_initiator_WVALID);
		    sha_cosim0->dma_initiator_WSTRB(dma_initiator_WSTRB);
		    sha_cosim0->dma_initiator_WDATA(dma_initiator_WDATA);
		    sha_cosim0->dma_initiator_WLAST(dma_initiator_WLAST);
		    sha_cosim0->dma_initiator_WREADY(dma_initiator_WREADY);
		    sha_cosim0->dma_initiator_BREADY(dma_initiator_BREADY);
		    sha_cosim0->dma_initiator_BID(dma_initiator_BID);
		    sha_cosim0->dma_initiator_BVALID(dma_initiator_BVALID);
		    sha_cosim0->dma_initiator_BRESP(dma_initiator_BRESP);
		    sha_cosim0->dma_initiator_ARVALID(dma_initiator_ARVALID);
		    sha_cosim0->dma_initiator_ARLEN(dma_initiator_ARLEN);
		    sha_cosim0->dma_initiator_ARSIZE(dma_initiator_ARSIZE);
		    sha_cosim0->dma_initiator_ARBURST(dma_initiator_ARBURST);
		    sha_cosim0->dma_initiator_ARID(dma_initiator_ARID);
		    sha_cosim0->dma_initiator_ARADDR(dma_initiator_ARADDR);
		    sha_cosim0->dma_initiator_ARREADY(dma_initiator_ARREADY);
		    sha_cosim0->dma_initiator_ARLOCK(dma_initiator_ARLOCK);
		    sha_cosim0->dma_initiator_ARCACHE(dma_initiator_ARCACHE);
		    sha_cosim0->dma_initiator_ARPROT(dma_initiator_ARPROT);
		    sha_cosim0->dma_initiator_ARQOS(dma_initiator_ARQOS);
		    sha_cosim0->dma_initiator_ARREGION(dma_initiator_ARREGION);
		    sha_cosim0->dma_initiator_RREADY(dma_initiator_RREADY);
		    sha_cosim0->dma_initiator_RVALID(dma_initiator_RVALID);
		    sha_cosim0->dma_initiator_RID(dma_initiator_RID);
		    sha_cosim0->dma_initiator_RDATA(dma_initiator_RDATA);
		    sha_cosim0->dma_initiator_RRESP(dma_initiator_RRESP);
		    sha_cosim0->dma_initiator_RLAST(dma_initiator_RLAST);

			break;
		case BDWRep_RTL_HDL:
		    sha_cosim0 = new sha_cosim( "sha" );

		    sha_cosim0->clk(clk);
		    sha_cosim0->rst(rst);
		    sha_cosim0->irq(irq);
		    sha_cosim0->reg_target_AWVALID(reg_target_AWVALID);
		    sha_cosim0->reg_target_AWADDR(reg_target_AWADDR);
		    sha_cosim0->reg_target_AWREADY(reg_target_AWREADY);
		    sha_cosim0->reg_target_AWPROT(reg_target_AWPROT);
		    sha_cosim0->reg_target_WVALID(reg_target_WVALID);
		    sha_cosim0->reg_target_WSTRB(reg_target_WSTRB);
		    sha_cosim0->reg_target_WDATA(reg_target_WDATA);
		    sha_cosim0->reg_target_WREADY(reg_target_WREADY);
		    sha_cosim0->reg_target_BREADY(reg_target_BREADY);
		    sha_cosim0->reg_target_BVALID(reg_target_BVALID);
		    sha_cosim0->reg_target_BRESP(reg_target_BRESP);
		    sha_cosim0->reg_target_ARVALID(reg_target_ARVALID);
		    sha_cosim0->reg_target_ARADDR(reg_target_ARADDR);
		    sha_cosim0->reg_target_ARREADY(reg_target_ARREADY);
		    sha_cosim0->reg_target_ARPROT(reg_target_ARPROT);
		    sha_cosim0->reg_target_RREADY(reg_target_RREADY);
		    sha_cosim0->reg_target_RVALID(reg_target_RVALID);
		    sha_cosim0->reg_target_RDATA(reg_target_RDATA);
		    sha_cosim0->reg_target_RRESP(reg_target_RRESP);
		    sha_cosim0->dma_initiator_AWVALID(dma_initiator_AWVALID);
		    sha_cosim0->dma_initiator_AWLEN(dma_initiator_AWLEN);
		    sha_cosim0->dma_initiator_AWSIZE(dma_initiator_AWSIZE);
		    sha_cosim0->dma_initiator_AWBURST(dma_initiator_AWBURST);
		    sha_cosim0->dma_initiator_AWID(dma_initiator_AWID);
		    sha_cosim0->dma_initiator_AWADDR(dma_initiator_AWADDR);
		    sha_cosim0->dma_initiator_AWREADY(dma_initiator_AWREADY);
		    sha_cosim0->dma_initiator_AWLOCK(dma_initiator_AWLOCK);
		    sha_cosim0->dma_initiator_AWCACHE(dma_initiator_AWCACHE);
		    sha_cosim0->dma_initiator_AWPROT(dma_initiator_AWPROT);
		    sha_cosim0->dma_initiator_AWQOS(dma_initiator_AWQOS);
		    sha_cosim0->dma_initiator_AWREGION(dma_initiator_AWREGION);
		    sha_cosim0->dma_initiator_WVALID(dma_initiator_WVALID);
		    sha_cosim0->dma_initiator_WSTRB(dma_initiator_WSTRB);
		    sha_cosim0->dma_initiator_WDATA(dma_initiator_WDATA);
		    sha_cosim0->dma_initiator_WLAST(dma_initiator_WLAST);
		    sha_cosim0->dma_initiator_WREADY(dma_initiator_WREADY);
		    sha_cosim0->dma_initiator_BREADY(dma_initiator_BREADY);
		    sha_cosim0->dma_initiator_BID(dma_initiator_BID);
		    sha_cosim0->dma_initiator_BVALID(dma_initiator_BVALID);
		    sha_cosim0->dma_initiator_BRESP(dma_initiator_BRESP);
		    sha_cosim0->dma_initiator_ARVALID(dma_initiator_ARVALID);
		    sha_cosim0->dma_initiator_ARLEN(dma_initiator_ARLEN);
		    sha_cosim0->dma_initiator_ARSIZE(dma_initiator_ARSIZE);
		    sha_cosim0->dma_initiator_ARBURST(dma_initiator_ARBURST);
		    sha_cosim0->dma_initiator_ARID(dma_initiator_ARID);
		    sha_cosim0->dma_initiator_ARADDR(dma_initiator_ARADDR);
		    sha_cosim0->dma_initiator_ARREADY(dma_initiator_ARREADY);
		    sha_cosim0->dma_initiator_ARLOCK(dma_initiator_ARLOCK);
		    sha_cosim0->dma_initiator_ARCACHE(dma_initiator_ARCACHE);
		    sha_cosim0->dma_initiator_ARPROT(dma_initiator_ARPROT);
		    sha_cosim0->dma_initiator_ARQOS(dma_initiator_ARQOS);
		    sha_cosim0->dma_initiator_ARREGION(dma_initiator_ARREGION);
		    sha_cosim0->dma_initiator_RREADY(dma_initiator_RREADY);
		    sha_cosim0->dma_initiator_RVALID(dma_initiator_RVALID);
		    sha_cosim0->dma_initiator_RID(dma_initiator_RID);
		    sha_cosim0->dma_initiator_RDATA(dma_initiator_RDATA);
		    sha_cosim0->dma_initiator_RRESP(dma_initiator_RRESP);
		    sha_cosim0->dma_initiator_RLAST(dma_initiator_RLAST);

			break;
        case BDWRep_CYC_HDL:
            if ( sha_cycsim_factory_p )
                sha_cycsim0 = sha_cycsim_factory_p();
            else
            {
                esc_report_error( esc_fatal, "verilator_produced files not available for module sha");
                return;
            }

            esc_report_error( esc_note, " using verilator model for module \"sha\"");

		    sha_cycsim0->clk(clk);
		    sha_cycsim0->rst(rst);
		    sha_cycsim0->irq(irq);
		    sha_cycsim0->reg_target_AWVALID(reg_target_AWVALID);
		    sha_cycsim0->reg_target_AWADDR(reg_target_AWADDR);
		    sha_cycsim0->reg_target_AWREADY(reg_target_AWREADY);
		    sha_cycsim0->reg_target_AWPROT(reg_target_AWPROT);
		    sha_cycsim0->reg_target_WVALID(reg_target_WVALID);
		    sha_cycsim0->reg_target_WSTRB(reg_target_WSTRB);
		    sha_cycsim0->reg_target_WDATA(reg_target_WDATA);
		    sha_cycsim0->reg_target_WREADY(reg_target_WREADY);
		    sha_cycsim0->reg_target_BREADY(reg_target_BREADY);
		    sha_cycsim0->reg_target_BVALID(reg_target_BVALID);
		    sha_cycsim0->reg_target_BRESP(reg_target_BRESP);
		    sha_cycsim0->reg_target_ARVALID(reg_target_ARVALID);
		    sha_cycsim0->reg_target_ARADDR(reg_target_ARADDR);
		    sha_cycsim0->reg_target_ARREADY(reg_target_ARREADY);
		    sha_cycsim0->reg_target_ARPROT(reg_target_ARPROT);
		    sha_cycsim0->reg_target_RREADY(reg_target_RREADY);
		    sha_cycsim0->reg_target_RVALID(reg_target_RVALID);
		    sha_cycsim0->reg_target_RDATA(reg_target_RDATA);
		    sha_cycsim0->reg_target_RRESP(reg_target_RRESP);
		    sha_cycsim0->dma_initiator_AWVALID(dma_initiator_AWVALID);
		    sha_cycsim0->dma_initiator_AWLEN(dma_initiator_AWLEN);
		    sha_cycsim0->dma_initiator_AWSIZE(dma_initiator_AWSIZE);
		    sha_cycsim0->dma_initiator_AWBURST(dma_initiator_AWBURST);
		    sha_cycsim0->dma_initiator_AWID(dma_initiator_AWID);
		    sha_cycsim0->dma_initiator_AWADDR(dma_initiator_AWADDR);
		    sha_cycsim0->dma_initiator_AWREADY(dma_initiator_AWREADY);
		    sha_cycsim0->dma_initiator_AWLOCK(dma_initiator_AWLOCK);
		    sha_cycsim0->dma_initiator_AWCACHE(dma_initiator_AWCACHE);
		    sha_cycsim0->dma_initiator_AWPROT(dma_initiator_AWPROT);
		    sha_cycsim0->dma_initiator_AWQOS(dma_initiator_AWQOS);
		    sha_cycsim0->dma_initiator_AWREGION(dma_initiator_AWREGION);
		    sha_cycsim0->dma_initiator_WVALID(dma_initiator_WVALID);
		    sha_cycsim0->dma_initiator_WSTRB(dma_initiator_WSTRB);
		    sha_cycsim0->dma_initiator_WDATA(dma_initiator_WDATA);
		    sha_cycsim0->dma_initiator_WLAST(dma_initiator_WLAST);
		    sha_cycsim0->dma_initiator_WREADY(dma_initiator_WREADY);
		    sha_cycsim0->dma_initiator_BREADY(dma_initiator_BREADY);
		    sha_cycsim0->dma_initiator_BID(dma_initiator_BID);
		    sha_cycsim0->dma_initiator_BVALID(dma_initiator_BVALID);
		    sha_cycsim0->dma_initiator_BRESP(dma_initiator_BRESP);
		    sha_cycsim0->dma_initiator_ARVALID(dma_initiator_ARVALID);
		    sha_cycsim0->dma_initiator_ARLEN(dma_initiator_ARLEN);
		    sha_cycsim0->dma_initiator_ARSIZE(dma_initiator_ARSIZE);
		    sha_cycsim0->dma_initiator_ARBURST(dma_initiator_ARBURST);
		    sha_cycsim0->dma_initiator_ARID(dma_initiator_ARID);
		    sha_cycsim0->dma_initiator_ARADDR(dma_initiator_ARADDR);
		    sha_cycsim0->dma_initiator_ARREADY(dma_initiator_ARREADY);
		    sha_cycsim0->dma_initiator_ARLOCK(dma_initiator_ARLOCK);
		    sha_cycsim0->dma_initiator_ARCACHE(dma_initiator_ARCACHE);
		    sha_cycsim0->dma_initiator_ARPROT(dma_initiator_ARPROT);
		    sha_cycsim0->dma_initiator_ARQOS(dma_initiator_ARQOS);
		    sha_cycsim0->dma_initiator_ARREGION(dma_initiator_ARREGION);
		    sha_cycsim0->dma_initiator_RREADY(dma_initiator_RREADY);
		    sha_cycsim0->dma_initiator_RVALID(dma_initiator_RVALID);
		    sha_cycsim0->dma_initiator_RID(dma_initiator_RID);
		    sha_cycsim0->dma_initiator_RDATA(dma_initiator_RDATA);
		    sha_cycsim0->dma_initiator_RRESP(dma_initiator_RRESP);
		    sha_cycsim0->dma_initiator_RLAST(dma_initiator_RLAST);

			break;
#if defined(BDW_RTL) || defined(COWARE_RTL_sha)
		case BDWRep_RTL_C:
		    sha_rtl0 = new sha_rtl( "sha" );

		    sha_rtl0->clk(clk);
		    sha_rtl0->rst(rst);
		    sha_rtl0->irq(irq);
		    sha_rtl0->reg_target_AWVALID(reg_target_AWVALID);
		    sha_rtl0->reg_target_AWADDR(reg_target_AWADDR);
		    sha_rtl0->reg_target_AWREADY(reg_target_AWREADY);
		    sha_rtl0->reg_target_AWPROT(reg_target_AWPROT);
		    sha_rtl0->reg_target_WVALID(reg_target_WVALID);
		    sha_rtl0->reg_target_WSTRB(reg_target_WSTRB);
		    sha_rtl0->reg_target_WDATA(reg_target_WDATA);
		    sha_rtl0->reg_target_WREADY(reg_target_WREADY);
		    sha_rtl0->reg_target_BREADY(reg_target_BREADY);
		    sha_rtl0->reg_target_BVALID(reg_target_BVALID);
		    sha_rtl0->reg_target_BRESP(reg_target_BRESP);
		    sha_rtl0->reg_target_ARVALID(reg_target_ARVALID);
		    sha_rtl0->reg_target_ARADDR(reg_target_ARADDR);
		    sha_rtl0->reg_target_ARREADY(reg_target_ARREADY);
		    sha_rtl0->reg_target_ARPROT(reg_target_ARPROT);
		    sha_rtl0->reg_target_RREADY(reg_target_RREADY);
		    sha_rtl0->reg_target_RVALID(reg_target_RVALID);
		    sha_rtl0->reg_target_RDATA(reg_target_RDATA);
		    sha_rtl0->reg_target_RRESP(reg_target_RRESP);
		    sha_rtl0->dma_initiator_AWVALID(dma_initiator_AWVALID);
		    sha_rtl0->dma_initiator_AWLEN(dma_initiator_AWLEN);
		    sha_rtl0->dma_initiator_AWSIZE(dma_initiator_AWSIZE);
		    sha_rtl0->dma_initiator_AWBURST(dma_initiator_AWBURST);
		    sha_rtl0->dma_initiator_AWID(dma_initiator_AWID);
		    sha_rtl0->dma_initiator_AWADDR(dma_initiator_AWADDR);
		    sha_rtl0->dma_initiator_AWREADY(dma_initiator_AWREADY);
		    sha_rtl0->dma_initiator_AWLOCK(dma_initiator_AWLOCK);
		    sha_rtl0->dma_initiator_AWCACHE(dma_initiator_AWCACHE);
		    sha_rtl0->dma_initiator_AWPROT(dma_initiator_AWPROT);
		    sha_rtl0->dma_initiator_AWQOS(dma_initiator_AWQOS);
		    sha_rtl0->dma_initiator_AWREGION(dma_initiator_AWREGION);
		    sha_rtl0->dma_initiator_WVALID(dma_initiator_WVALID);
		    sha_rtl0->dma_initiator_WSTRB(dma_initiator_WSTRB);
		    sha_rtl0->dma_initiator_WDATA(dma_initiator_WDATA);
		    sha_rtl0->dma_initiator_WLAST(dma_initiator_WLAST);
		    sha_rtl0->dma_initiator_WREADY(dma_initiator_WREADY);
		    sha_rtl0->dma_initiator_BREADY(dma_initiator_BREADY);
		    sha_rtl0->dma_initiator_BID(dma_initiator_BID);
		    sha_rtl0->dma_initiator_BVALID(dma_initiator_BVALID);
		    sha_rtl0->dma_initiator_BRESP(dma_initiator_BRESP);
		    sha_rtl0->dma_initiator_ARVALID(dma_initiator_ARVALID);
		    sha_rtl0->dma_initiator_ARLEN(dma_initiator_ARLEN);
		    sha_rtl0->dma_initiator_ARSIZE(dma_initiator_ARSIZE);
		    sha_rtl0->dma_initiator_ARBURST(dma_initiator_ARBURST);
		    sha_rtl0->dma_initiator_ARID(dma_initiator_ARID);
		    sha_rtl0->dma_initiator_ARADDR(dma_initiator_ARADDR);
		    sha_rtl0->dma_initiator_ARREADY(dma_initiator_ARREADY);
		    sha_rtl0->dma_initiator_ARLOCK(dma_initiator_ARLOCK);
		    sha_rtl0->dma_initiator_ARCACHE(dma_initiator_ARCACHE);
		    sha_rtl0->dma_initiator_ARPROT(dma_initiator_ARPROT);
		    sha_rtl0->dma_initiator_ARQOS(dma_initiator_ARQOS);
		    sha_rtl0->dma_initiator_ARREGION(dma_initiator_ARREGION);
		    sha_rtl0->dma_initiator_RREADY(dma_initiator_RREADY);
		    sha_rtl0->dma_initiator_RVALID(dma_initiator_RVALID);
		    sha_rtl0->dma_initiator_RID(dma_initiator_RID);
		    sha_rtl0->dma_initiator_RDATA(dma_initiator_RDATA);
		    sha_rtl0->dma_initiator_RRESP(dma_initiator_RRESP);
		    sha_rtl0->dma_initiator_RLAST(dma_initiator_RLAST);


			{
			const char *simConfig = sha_wrapper::simConfigName();
			
			if ( simConfig != NULL )
				{
				qbhProjectHandle hProj;
				qbhError err = qbhGetCurrentProject( &hProj );
				if ( err == qbhErrorNoProject )
				{
					err = qbhOpenProject( "project.tcl", &hProj );
			
					if ( err != qbhOK )
					{
						esc_report_error( esc_fatal, "could not open project file %s",
											  "project.tcl" );
							return;
					}
				}
			
				if ( esc_trace_is_enabled( esc_trace_vcd ) ) {
					esc_get_vcd_trace_file();
				}
				if ( esc_trace_is_enabled( esc_trace_fsdb ) ) {
					esc_get_fsdb_trace_file();
				}
				}
			}

			break;
#endif
		case BDWRep_Behavioral:
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


			{
			const char *simConfig = sha_wrapper::simConfigName();
			
			if ( simConfig != NULL )
				{
				qbhProjectHandle hProj;
				qbhError err = qbhGetCurrentProject( &hProj );
				if ( err == qbhErrorNoProject )
				{
					err = qbhOpenProject( "project.tcl", &hProj );
			
					if ( err != qbhOK )
					{
						esc_report_error( esc_fatal, "could not open project file %s",
											  "project.tcl" );
							return;
					}
				}
			
				if ( esc_trace_is_enabled( esc_trace_vcd ) ) {
					esc_get_vcd_trace_file();
				}
				if ( esc_trace_is_enabled( esc_trace_fsdb ) ) {
					esc_get_fsdb_trace_file();
				}
				}
			}

			break;
		case BDWRep_None:
		default:
			esc_report_error( esc_error, "No representation could be determined for simulating instance %s. Please make sure that you used the right name string in the module constructor",
							  name() );
			break;
	}
}

void sha_wrapper_r::InitThreads()
{
	if ( isBEH() ) 
	{
		
	}
}

void sha_wrapper_r::start_of_simulation()
{

#include <sha_trace.h>

    esc_multiple_writers_warning();
}

void sha_wrapper_r::CloseTrace()
{
	if ( esc_trace_is_enabled( esc_trace_vcd ) ) {
	esc_close_vcd_trace();
	}
	if ( esc_trace_is_enabled( esc_trace_fsdb ) ) {
		esc_close_fsdb_trace();
		if ( esc_trace_is_enabled( esc_trace_scv ) ) {
			esc_close_fsdb_scv_trace();
		}
	}
}

void sha_wrapper_r::end_of_simulation()
{
	CloseTrace();
}



void sha_wrapper_r::DeleteInstances()
{
    if (sha0)
    {
        delete sha0;
        sha0 = 0;
    }
    if (sha_cosim0)
    {
        delete sha_cosim0;
        sha_cosim0 = 0;
    }
    if (sha_cycsim0)
    {
        delete sha_cycsim0;
        sha_cycsim0 = 0;
    }
#if defined(BDW_RTL) || defined(COWARE_RTL_sha)
    if (sha_rtl0)
    {
        delete sha_rtl0;
        sha_rtl0 = 0;
    }
#endif
}

#if BDW_WRITEFSDB == 1

inline void esc_open_fsdb_trace( const char *file_name  )
{
#if defined(NC_SYSTEMC) && defined(BDW_NCSC_VER) && BDW_NCSC_VER > 102
    fsdbDumpfile(file_name);
# else
	sc_trace_file *fsdb_file;

	// SystemC suffixes .fsdb to filenames automatically. Make sure
	// that doesn't get tacked onto a filename that already has the suffix.
	if ( strrchr( file_name, '.' ) != NULL )
	{
		char *trunc_file_name = new char[strlen(file_name)+1];
		strcpy( trunc_file_name, file_name );

		fsdb_file = new fsdb_trace_file( trunc_file_name );
		esc_set_trace_file( fsdb_file, esc_trace_fsdb );

		delete trunc_file_name;
	}
	else
	{
		fsdb_file = new fsdb_trace_file( file_name );
		esc_set_trace_file( fsdb_file, esc_trace_fsdb );
	}
#endif

//
// Novas's SystemC wrapper doesn't have a way to set the time unit as of SystemC 2.1v1.
//
//		((fsdb_trace_file*)fsdb_file)->sc_set_fsdb_time_unit( -12 );
}

inline void esc_close_fsdb_trace()
{
#if ! defined(NC_SYSTEMC) | ! defined(BDW_NCSC_VER) | BDW_NCSC_VER <= 102
	fsdb_trace_file * fsdb_file =
		(fsdb_trace_file *)esc_trace_file( esc_trace_fsdb );

	if ( fsdb_file != NULL )
	{
		fsdb_file->CloseFile();
		delete fsdb_file;
		esc_set_trace_file( NULL, esc_trace_fsdb );
	}
#endif
}

#else

inline void esc_open_fsdb_trace( const char *file_name )
{
}

inline void esc_close_fsdb_trace()
{
}

#endif

#if BDW_USE_SCV && BDW_WRITEFSDB == 1
static scv_tr_db* local_fsdb_scv_db = 0;

inline void esc_open_fsdb_scv_trace( const char *file_name  )
{
	// Start SCV logging to FSDB if there is not already a database setup.
    if (!esc_get_scv_tr_db() && esc_trace_is_enabled(esc_trace_scv) )
	{
		scv_startup();
		scv_tr_fsdb_init();

		char* scv_file_name = new char[strlen(file_name) + 1];
		strcpy( scv_file_name, file_name );
		char* fsdb_suffix = strstr( scv_file_name, ".fsdb" );
		if (fsdb_suffix)
			*fsdb_suffix = 0;
		local_fsdb_scv_db = new scv_tr_db(scv_file_name);

		delete [] scv_file_name;
		esc_set_scv_tr_db(local_fsdb_scv_db);
		scv_tr_db::set_default_db(local_fsdb_scv_db);
		local_fsdb_scv_db->set_recording(true);
	}
}

inline void esc_close_fsdb_scv_trace()
{
    if ( local_fsdb_scv_db && (local_fsdb_scv_db == esc_get_scv_tr_db() ) ) 
	{
		delete local_fsdb_scv_db;
		local_fsdb_scv_db = 0;
		esc_set_scv_tr_db(0);
	}
}
#else 
inline void esc_open_fsdb_scv_trace( const char *file_name  )
{
}

inline void esc_close_fsdb_scv_trace()
{
}

#endif

class sha_wrapper_fsdb_opener {
public:
	sha_wrapper_fsdb_opener() {
		esc_set_open_fsdb_trace( esc_open_fsdb_trace );
		esc_set_open_fsdb_scv_trace( esc_open_fsdb_scv_trace );
	}
};

static sha_wrapper_fsdb_opener
  sha_wrapper_fsdb_opener_inst;

#else

// Visible to uses of the wrapper outside of the BDW environment.
// Only behavioral SystemC simulation is supported.


// Include the source for the behavioral model so it will be compiled.
#include	"../src/sha.cpp"

#define		sha_INTERNAL


#include	"sha_wrap.h"

const char * sha_wrapper::simConfigName()
{
  return "";
}

enum sha_wrapper::Representation sha_wrapper::lookupRepresentation( const char* instName )
{
  return BDWRep_Behavioral;
}

void sha_wrapper::InitInstances( sc_core::sc_module_name name )
{
	sha0 = new sha( "sha" );

	sha0->clk(clk);
	sha0->rst(rst);
	sha0->irq(irq);
	sha0->reg_target.AWVALID(reg_target.AWVALID);
	sha0->reg_target.AWADDR(reg_target.AWADDR);
	sha0->reg_target.AWREADY(reg_target.AWREADY);
	sha0->reg_target.AWPROT(reg_target.AWPROT);
	sha0->reg_target.WVALID(reg_target.WVALID);
	sha0->reg_target.WSTRB(reg_target.WSTRB);
	sha0->reg_target.WDATA(reg_target.WDATA);
	sha0->reg_target.WREADY(reg_target.WREADY);
	sha0->reg_target.BREADY(reg_target.BREADY);
	sha0->reg_target.BVALID(reg_target.BVALID);
	sha0->reg_target.BRESP(reg_target.BRESP);
	sha0->reg_target.ARVALID(reg_target.ARVALID);
	sha0->reg_target.ARADDR(reg_target.ARADDR);
	sha0->reg_target.ARREADY(reg_target.ARREADY);
	sha0->reg_target.ARPROT(reg_target.ARPROT);
	sha0->reg_target.RREADY(reg_target.RREADY);
	sha0->reg_target.RVALID(reg_target.RVALID);
	sha0->reg_target.RDATA(reg_target.RDATA);
	sha0->reg_target.RRESP(reg_target.RRESP);
	sha0->dma_initiator.AWVALID(dma_initiator.AWVALID);
	sha0->dma_initiator.AWLEN(dma_initiator.AWLEN);
	sha0->dma_initiator.AWSIZE(dma_initiator.AWSIZE);
	sha0->dma_initiator.AWBURST(dma_initiator.AWBURST);
	sha0->dma_initiator.AWID(dma_initiator.AWID);
	sha0->dma_initiator.AWADDR(dma_initiator.AWADDR);
	sha0->dma_initiator.AWREADY(dma_initiator.AWREADY);
	sha0->dma_initiator.AWLOCK(dma_initiator.AWLOCK);
	sha0->dma_initiator.AWCACHE(dma_initiator.AWCACHE);
	sha0->dma_initiator.AWPROT(dma_initiator.AWPROT);
	sha0->dma_initiator.AWQOS(dma_initiator.AWQOS);
	sha0->dma_initiator.AWREGION(dma_initiator.AWREGION);
	sha0->dma_initiator.WVALID(dma_initiator.WVALID);
	sha0->dma_initiator.WSTRB(dma_initiator.WSTRB);
	sha0->dma_initiator.WDATA(dma_initiator.WDATA);
	sha0->dma_initiator.WLAST(dma_initiator.WLAST);
	sha0->dma_initiator.WREADY(dma_initiator.WREADY);
	sha0->dma_initiator.BREADY(dma_initiator.BREADY);
	sha0->dma_initiator.BID(dma_initiator.BID);
	sha0->dma_initiator.BVALID(dma_initiator.BVALID);
	sha0->dma_initiator.BRESP(dma_initiator.BRESP);
	sha0->dma_initiator.ARVALID(dma_initiator.ARVALID);
	sha0->dma_initiator.ARLEN(dma_initiator.ARLEN);
	sha0->dma_initiator.ARSIZE(dma_initiator.ARSIZE);
	sha0->dma_initiator.ARBURST(dma_initiator.ARBURST);
	sha0->dma_initiator.ARID(dma_initiator.ARID);
	sha0->dma_initiator.ARADDR(dma_initiator.ARADDR);
	sha0->dma_initiator.ARREADY(dma_initiator.ARREADY);
	sha0->dma_initiator.ARLOCK(dma_initiator.ARLOCK);
	sha0->dma_initiator.ARCACHE(dma_initiator.ARCACHE);
	sha0->dma_initiator.ARPROT(dma_initiator.ARPROT);
	sha0->dma_initiator.ARQOS(dma_initiator.ARQOS);
	sha0->dma_initiator.ARREGION(dma_initiator.ARREGION);
	sha0->dma_initiator.RREADY(dma_initiator.RREADY);
	sha0->dma_initiator.RVALID(dma_initiator.RVALID);
	sha0->dma_initiator.RID(dma_initiator.RID);
	sha0->dma_initiator.RDATA(dma_initiator.RDATA);
	sha0->dma_initiator.RRESP(dma_initiator.RRESP);
	sha0->dma_initiator.RLAST(dma_initiator.RLAST);

}

void sha_wrapper::InitThreads()
{
}

void sha_wrapper::CloseTrace()
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

void sha_wrapper::start_of_simulation()
{
}

void sha_wrapper::end_of_simulation()
{
}



inline void esc_open_fsdb_trace( const char *file_name )
{
}

inline void esc_close_fsdb_trace()
{
}


inline void esc_open_fsdb_scv_trace( const char *file_name  )
{
}

inline void esc_close_fsdb_scv_trace()
{
}

class sha_wrapper_fsdb_opener {
public:
	sha_wrapper_fsdb_opener() {
	}
};

static sha_wrapper_fsdb_opener
  sha_wrapper_fsdb_opener_inst;

#endif

#endif
