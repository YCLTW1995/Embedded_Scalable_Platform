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
* Verilog Verification wrapper module for the sha module.
*
* This module contains the followng items:
*	- A foreign module definition for use in instantiatin the type_wrapper module
*      which contains the BEH module instance.
*	- An instance of the type_wrapper foreign module.
*   - alwyas blocks each type_wrapper output.
*
****************************************************************************/

`timescale 1 ps / 1 ps

module sha_vlwrapper(
      `ifdef ioConfig_IOCFG_32
      
      clk,
       rst,
       irq,
       reg_target_AWVALID,
       reg_target_AWADDR,
       reg_target_AWREADY,
       reg_target_AWPROT,
       reg_target_WVALID,
       reg_target_WSTRB,
       reg_target_WDATA,
       reg_target_WREADY,
       reg_target_BREADY,
       reg_target_BVALID,
       reg_target_BRESP,
       reg_target_ARVALID,
       reg_target_ARADDR,
       reg_target_ARREADY,
       reg_target_ARPROT,
       reg_target_RREADY,
       reg_target_RVALID,
       reg_target_RDATA,
       reg_target_RRESP,
       dma_initiator_AWVALID,
       dma_initiator_AWLEN,
       dma_initiator_AWSIZE,
       dma_initiator_AWBURST,
       dma_initiator_AWID,
       dma_initiator_AWADDR,
       dma_initiator_AWREADY,
       dma_initiator_AWLOCK,
       dma_initiator_AWCACHE,
       dma_initiator_AWPROT,
       dma_initiator_AWQOS,
       dma_initiator_AWREGION,
       dma_initiator_WVALID,
       dma_initiator_WSTRB,
       dma_initiator_WDATA,
       dma_initiator_WLAST,
       dma_initiator_WREADY,
       dma_initiator_BREADY,
       dma_initiator_BID,
       dma_initiator_BVALID,
       dma_initiator_BRESP,
       dma_initiator_ARVALID,
       dma_initiator_ARLEN,
       dma_initiator_ARSIZE,
       dma_initiator_ARBURST,
       dma_initiator_ARID,
       dma_initiator_ARADDR,
       dma_initiator_ARREADY,
       dma_initiator_ARLOCK,
       dma_initiator_ARCACHE,
       dma_initiator_ARPROT,
       dma_initiator_ARQOS,
       dma_initiator_ARREGION,
       dma_initiator_RREADY,
       dma_initiator_RVALID,
       dma_initiator_RID,
       dma_initiator_RDATA,
       dma_initiator_RRESP,
       dma_initiator_RLAST
      `endif

    );

	`ifdef ioConfig_IOCFG_32
	
	input clk;
	input rst;
	output irq;
	reg irq;
	wire m_irq;
	input reg_target_AWVALID;
	input [31:0] reg_target_AWADDR;
	output reg_target_AWREADY;
	reg reg_target_AWREADY;
	wire m_reg_target_AWREADY;
	input [2:0] reg_target_AWPROT;
	input reg_target_WVALID;
	input [3:0] reg_target_WSTRB;
	input [31:0] reg_target_WDATA;
	output reg_target_WREADY;
	reg reg_target_WREADY;
	wire m_reg_target_WREADY;
	input reg_target_BREADY;
	output reg_target_BVALID;
	reg reg_target_BVALID;
	wire m_reg_target_BVALID;
	output [1:0] reg_target_BRESP;
	reg[1:0] reg_target_BRESP;
	wire [1:0] m_reg_target_BRESP;
	input reg_target_ARVALID;
	input [31:0] reg_target_ARADDR;
	output reg_target_ARREADY;
	reg reg_target_ARREADY;
	wire m_reg_target_ARREADY;
	input [2:0] reg_target_ARPROT;
	input reg_target_RREADY;
	output reg_target_RVALID;
	reg reg_target_RVALID;
	wire m_reg_target_RVALID;
	output [31:0] reg_target_RDATA;
	reg[31:0] reg_target_RDATA;
	wire [31:0] m_reg_target_RDATA;
	output [1:0] reg_target_RRESP;
	reg[1:0] reg_target_RRESP;
	wire [1:0] m_reg_target_RRESP;
	output dma_initiator_AWVALID;
	reg dma_initiator_AWVALID;
	wire m_dma_initiator_AWVALID;
	output [7:0] dma_initiator_AWLEN;
	reg[7:0] dma_initiator_AWLEN;
	wire [7:0] m_dma_initiator_AWLEN;
	output [2:0] dma_initiator_AWSIZE;
	reg[2:0] dma_initiator_AWSIZE;
	wire [2:0] m_dma_initiator_AWSIZE;
	output [1:0] dma_initiator_AWBURST;
	reg[1:0] dma_initiator_AWBURST;
	wire [1:0] m_dma_initiator_AWBURST;
	output [5:0] dma_initiator_AWID;
	reg[5:0] dma_initiator_AWID;
	wire [5:0] m_dma_initiator_AWID;
	output [31:0] dma_initiator_AWADDR;
	reg[31:0] dma_initiator_AWADDR;
	wire [31:0] m_dma_initiator_AWADDR;
	input dma_initiator_AWREADY;
	output dma_initiator_AWLOCK;
	reg dma_initiator_AWLOCK;
	wire m_dma_initiator_AWLOCK;
	output [3:0] dma_initiator_AWCACHE;
	reg[3:0] dma_initiator_AWCACHE;
	wire [3:0] m_dma_initiator_AWCACHE;
	output [2:0] dma_initiator_AWPROT;
	reg[2:0] dma_initiator_AWPROT;
	wire [2:0] m_dma_initiator_AWPROT;
	output [3:0] dma_initiator_AWQOS;
	reg[3:0] dma_initiator_AWQOS;
	wire [3:0] m_dma_initiator_AWQOS;
	output [3:0] dma_initiator_AWREGION;
	reg[3:0] dma_initiator_AWREGION;
	wire [3:0] m_dma_initiator_AWREGION;
	output dma_initiator_WVALID;
	reg dma_initiator_WVALID;
	wire m_dma_initiator_WVALID;
	output [3:0] dma_initiator_WSTRB;
	reg[3:0] dma_initiator_WSTRB;
	wire [3:0] m_dma_initiator_WSTRB;
	output [31:0] dma_initiator_WDATA;
	reg[31:0] dma_initiator_WDATA;
	wire [31:0] m_dma_initiator_WDATA;
	output dma_initiator_WLAST;
	reg dma_initiator_WLAST;
	wire m_dma_initiator_WLAST;
	input dma_initiator_WREADY;
	output dma_initiator_BREADY;
	reg dma_initiator_BREADY;
	wire m_dma_initiator_BREADY;
	input [5:0] dma_initiator_BID;
	input dma_initiator_BVALID;
	input [1:0] dma_initiator_BRESP;
	output dma_initiator_ARVALID;
	reg dma_initiator_ARVALID;
	wire m_dma_initiator_ARVALID;
	output [7:0] dma_initiator_ARLEN;
	reg[7:0] dma_initiator_ARLEN;
	wire [7:0] m_dma_initiator_ARLEN;
	output [2:0] dma_initiator_ARSIZE;
	reg[2:0] dma_initiator_ARSIZE;
	wire [2:0] m_dma_initiator_ARSIZE;
	output [1:0] dma_initiator_ARBURST;
	reg[1:0] dma_initiator_ARBURST;
	wire [1:0] m_dma_initiator_ARBURST;
	output [5:0] dma_initiator_ARID;
	reg[5:0] dma_initiator_ARID;
	wire [5:0] m_dma_initiator_ARID;
	output [31:0] dma_initiator_ARADDR;
	reg[31:0] dma_initiator_ARADDR;
	wire [31:0] m_dma_initiator_ARADDR;
	input dma_initiator_ARREADY;
	output dma_initiator_ARLOCK;
	reg dma_initiator_ARLOCK;
	wire m_dma_initiator_ARLOCK;
	output [3:0] dma_initiator_ARCACHE;
	reg[3:0] dma_initiator_ARCACHE;
	wire [3:0] m_dma_initiator_ARCACHE;
	output [2:0] dma_initiator_ARPROT;
	reg[2:0] dma_initiator_ARPROT;
	wire [2:0] m_dma_initiator_ARPROT;
	output [3:0] dma_initiator_ARQOS;
	reg[3:0] dma_initiator_ARQOS;
	wire [3:0] m_dma_initiator_ARQOS;
	output [3:0] dma_initiator_ARREGION;
	reg[3:0] dma_initiator_ARREGION;
	wire [3:0] m_dma_initiator_ARREGION;
	output dma_initiator_RREADY;
	reg dma_initiator_RREADY;
	wire m_dma_initiator_RREADY;
	input dma_initiator_RVALID;
	input [5:0] dma_initiator_RID;
	input [31:0] dma_initiator_RDATA;
	input [1:0] dma_initiator_RRESP;
	input dma_initiator_RLAST;
	
	`endif


    // Instantiate the Verilog module that instantiates the SystemC module
    sha_type_wrapper sha_sc(
        `ifdef ioConfig_IOCFG_32
        
        .clk(clk),
         .rst(rst),
         .irq(m_irq),
         .reg_target_AWVALID(reg_target_AWVALID),
         .reg_target_AWADDR(reg_target_AWADDR),
         .reg_target_AWREADY(m_reg_target_AWREADY),
         .reg_target_AWPROT(reg_target_AWPROT),
         .reg_target_WVALID(reg_target_WVALID),
         .reg_target_WSTRB(reg_target_WSTRB),
         .reg_target_WDATA(reg_target_WDATA),
         .reg_target_WREADY(m_reg_target_WREADY),
         .reg_target_BREADY(reg_target_BREADY),
         .reg_target_BVALID(m_reg_target_BVALID),
         .reg_target_BRESP(m_reg_target_BRESP),
         .reg_target_ARVALID(reg_target_ARVALID),
         .reg_target_ARADDR(reg_target_ARADDR),
         .reg_target_ARREADY(m_reg_target_ARREADY),
         .reg_target_ARPROT(reg_target_ARPROT),
         .reg_target_RREADY(reg_target_RREADY),
         .reg_target_RVALID(m_reg_target_RVALID),
         .reg_target_RDATA(m_reg_target_RDATA),
         .reg_target_RRESP(m_reg_target_RRESP),
         .dma_initiator_AWVALID(m_dma_initiator_AWVALID),
         .dma_initiator_AWLEN(m_dma_initiator_AWLEN),
         .dma_initiator_AWSIZE(m_dma_initiator_AWSIZE),
         .dma_initiator_AWBURST(m_dma_initiator_AWBURST),
         .dma_initiator_AWID(m_dma_initiator_AWID),
         .dma_initiator_AWADDR(m_dma_initiator_AWADDR),
         .dma_initiator_AWREADY(dma_initiator_AWREADY),
         .dma_initiator_AWLOCK(m_dma_initiator_AWLOCK),
         .dma_initiator_AWCACHE(m_dma_initiator_AWCACHE),
         .dma_initiator_AWPROT(m_dma_initiator_AWPROT),
         .dma_initiator_AWQOS(m_dma_initiator_AWQOS),
         .dma_initiator_AWREGION(m_dma_initiator_AWREGION),
         .dma_initiator_WVALID(m_dma_initiator_WVALID),
         .dma_initiator_WSTRB(m_dma_initiator_WSTRB),
         .dma_initiator_WDATA(m_dma_initiator_WDATA),
         .dma_initiator_WLAST(m_dma_initiator_WLAST),
         .dma_initiator_WREADY(dma_initiator_WREADY),
         .dma_initiator_BREADY(m_dma_initiator_BREADY),
         .dma_initiator_BID(dma_initiator_BID),
         .dma_initiator_BVALID(dma_initiator_BVALID),
         .dma_initiator_BRESP(dma_initiator_BRESP),
         .dma_initiator_ARVALID(m_dma_initiator_ARVALID),
         .dma_initiator_ARLEN(m_dma_initiator_ARLEN),
         .dma_initiator_ARSIZE(m_dma_initiator_ARSIZE),
         .dma_initiator_ARBURST(m_dma_initiator_ARBURST),
         .dma_initiator_ARID(m_dma_initiator_ARID),
         .dma_initiator_ARADDR(m_dma_initiator_ARADDR),
         .dma_initiator_ARREADY(dma_initiator_ARREADY),
         .dma_initiator_ARLOCK(m_dma_initiator_ARLOCK),
         .dma_initiator_ARCACHE(m_dma_initiator_ARCACHE),
         .dma_initiator_ARPROT(m_dma_initiator_ARPROT),
         .dma_initiator_ARQOS(m_dma_initiator_ARQOS),
         .dma_initiator_ARREGION(m_dma_initiator_ARREGION),
         .dma_initiator_RREADY(m_dma_initiator_RREADY),
         .dma_initiator_RVALID(dma_initiator_RVALID),
         .dma_initiator_RID(dma_initiator_RID),
         .dma_initiator_RDATA(dma_initiator_RDATA),
         .dma_initiator_RRESP(dma_initiator_RRESP),
         .dma_initiator_RLAST(dma_initiator_RLAST)
        `endif

    );

    // Always blocks for non-blocking assignments of type_wrapper outputs to
    // Verilog Verificatoin wrapper outputs.

    `ifdef ioConfig_IOCFG_32
    
    always @(m_irq)
     begin
      irq <= m_irq;
     end
    always @(m_reg_target_AWREADY)
     begin
      reg_target_AWREADY <= m_reg_target_AWREADY;
     end
    always @(m_reg_target_WREADY)
     begin
      reg_target_WREADY <= m_reg_target_WREADY;
     end
    always @(m_reg_target_BVALID)
     begin
      reg_target_BVALID <= m_reg_target_BVALID;
     end
    always @(m_reg_target_BRESP)
     begin
      reg_target_BRESP <= m_reg_target_BRESP;
     end
    always @(m_reg_target_ARREADY)
     begin
      reg_target_ARREADY <= m_reg_target_ARREADY;
     end
    always @(m_reg_target_RVALID)
     begin
      reg_target_RVALID <= m_reg_target_RVALID;
     end
    always @(m_reg_target_RDATA)
     begin
      reg_target_RDATA <= m_reg_target_RDATA;
     end
    always @(m_reg_target_RRESP)
     begin
      reg_target_RRESP <= m_reg_target_RRESP;
     end
    always @(m_dma_initiator_AWVALID)
     begin
      dma_initiator_AWVALID <= m_dma_initiator_AWVALID;
     end
    always @(m_dma_initiator_AWLEN)
     begin
      dma_initiator_AWLEN <= m_dma_initiator_AWLEN;
     end
    always @(m_dma_initiator_AWSIZE)
     begin
      dma_initiator_AWSIZE <= m_dma_initiator_AWSIZE;
     end
    always @(m_dma_initiator_AWBURST)
     begin
      dma_initiator_AWBURST <= m_dma_initiator_AWBURST;
     end
    always @(m_dma_initiator_AWID)
     begin
      dma_initiator_AWID <= m_dma_initiator_AWID;
     end
    always @(m_dma_initiator_AWADDR)
     begin
      dma_initiator_AWADDR <= m_dma_initiator_AWADDR;
     end
    always @(m_dma_initiator_AWLOCK)
     begin
      dma_initiator_AWLOCK <= m_dma_initiator_AWLOCK;
     end
    always @(m_dma_initiator_AWCACHE)
     begin
      dma_initiator_AWCACHE <= m_dma_initiator_AWCACHE;
     end
    always @(m_dma_initiator_AWPROT)
     begin
      dma_initiator_AWPROT <= m_dma_initiator_AWPROT;
     end
    always @(m_dma_initiator_AWQOS)
     begin
      dma_initiator_AWQOS <= m_dma_initiator_AWQOS;
     end
    always @(m_dma_initiator_AWREGION)
     begin
      dma_initiator_AWREGION <= m_dma_initiator_AWREGION;
     end
    always @(m_dma_initiator_WVALID)
     begin
      dma_initiator_WVALID <= m_dma_initiator_WVALID;
     end
    always @(m_dma_initiator_WSTRB)
     begin
      dma_initiator_WSTRB <= m_dma_initiator_WSTRB;
     end
    always @(m_dma_initiator_WDATA)
     begin
      dma_initiator_WDATA <= m_dma_initiator_WDATA;
     end
    always @(m_dma_initiator_WLAST)
     begin
      dma_initiator_WLAST <= m_dma_initiator_WLAST;
     end
    always @(m_dma_initiator_BREADY)
     begin
      dma_initiator_BREADY <= m_dma_initiator_BREADY;
     end
    always @(m_dma_initiator_ARVALID)
     begin
      dma_initiator_ARVALID <= m_dma_initiator_ARVALID;
     end
    always @(m_dma_initiator_ARLEN)
     begin
      dma_initiator_ARLEN <= m_dma_initiator_ARLEN;
     end
    always @(m_dma_initiator_ARSIZE)
     begin
      dma_initiator_ARSIZE <= m_dma_initiator_ARSIZE;
     end
    always @(m_dma_initiator_ARBURST)
     begin
      dma_initiator_ARBURST <= m_dma_initiator_ARBURST;
     end
    always @(m_dma_initiator_ARID)
     begin
      dma_initiator_ARID <= m_dma_initiator_ARID;
     end
    always @(m_dma_initiator_ARADDR)
     begin
      dma_initiator_ARADDR <= m_dma_initiator_ARADDR;
     end
    always @(m_dma_initiator_ARLOCK)
     begin
      dma_initiator_ARLOCK <= m_dma_initiator_ARLOCK;
     end
    always @(m_dma_initiator_ARCACHE)
     begin
      dma_initiator_ARCACHE <= m_dma_initiator_ARCACHE;
     end
    always @(m_dma_initiator_ARPROT)
     begin
      dma_initiator_ARPROT <= m_dma_initiator_ARPROT;
     end
    always @(m_dma_initiator_ARQOS)
     begin
      dma_initiator_ARQOS <= m_dma_initiator_ARQOS;
     end
    always @(m_dma_initiator_ARREGION)
     begin
      dma_initiator_ARREGION <= m_dma_initiator_ARREGION;
     end
    always @(m_dma_initiator_RREADY)
     begin
      dma_initiator_RREADY <= m_dma_initiator_RREADY;
     end
    
    `endif


endmodule

// This is an internal module that instantiates the user's SystemC input module
// using the Incisive foreign module instantiation feature.
// The name of the module and the names of the inputs and outputs must match
// with those defined in the SystemC type_wrapper module
module sha_type_wrapper(
      `ifdef ioConfig_IOCFG_32
      
      clk,
       rst,
       irq,
       reg_target_AWVALID,
       reg_target_AWADDR,
       reg_target_AWREADY,
       reg_target_AWPROT,
       reg_target_WVALID,
       reg_target_WSTRB,
       reg_target_WDATA,
       reg_target_WREADY,
       reg_target_BREADY,
       reg_target_BVALID,
       reg_target_BRESP,
       reg_target_ARVALID,
       reg_target_ARADDR,
       reg_target_ARREADY,
       reg_target_ARPROT,
       reg_target_RREADY,
       reg_target_RVALID,
       reg_target_RDATA,
       reg_target_RRESP,
       dma_initiator_AWVALID,
       dma_initiator_AWLEN,
       dma_initiator_AWSIZE,
       dma_initiator_AWBURST,
       dma_initiator_AWID,
       dma_initiator_AWADDR,
       dma_initiator_AWREADY,
       dma_initiator_AWLOCK,
       dma_initiator_AWCACHE,
       dma_initiator_AWPROT,
       dma_initiator_AWQOS,
       dma_initiator_AWREGION,
       dma_initiator_WVALID,
       dma_initiator_WSTRB,
       dma_initiator_WDATA,
       dma_initiator_WLAST,
       dma_initiator_WREADY,
       dma_initiator_BREADY,
       dma_initiator_BID,
       dma_initiator_BVALID,
       dma_initiator_BRESP,
       dma_initiator_ARVALID,
       dma_initiator_ARLEN,
       dma_initiator_ARSIZE,
       dma_initiator_ARBURST,
       dma_initiator_ARID,
       dma_initiator_ARADDR,
       dma_initiator_ARREADY,
       dma_initiator_ARLOCK,
       dma_initiator_ARCACHE,
       dma_initiator_ARPROT,
       dma_initiator_ARQOS,
       dma_initiator_ARREGION,
       dma_initiator_RREADY,
       dma_initiator_RVALID,
       dma_initiator_RID,
       dma_initiator_RDATA,
       dma_initiator_RRESP,
       dma_initiator_RLAST
      `endif

    ) (* integer foreign = "SystemC";
    *);

	`ifdef ioConfig_IOCFG_32
	
	input clk;
	input rst;
	output irq;
	input reg_target_AWVALID;
	input [31:0] reg_target_AWADDR;
	output reg_target_AWREADY;
	input [2:0] reg_target_AWPROT;
	input reg_target_WVALID;
	input [3:0] reg_target_WSTRB;
	input [31:0] reg_target_WDATA;
	output reg_target_WREADY;
	input reg_target_BREADY;
	output reg_target_BVALID;
	output [1:0] reg_target_BRESP;
	input reg_target_ARVALID;
	input [31:0] reg_target_ARADDR;
	output reg_target_ARREADY;
	input [2:0] reg_target_ARPROT;
	input reg_target_RREADY;
	output reg_target_RVALID;
	output [31:0] reg_target_RDATA;
	output [1:0] reg_target_RRESP;
	output dma_initiator_AWVALID;
	output [7:0] dma_initiator_AWLEN;
	output [2:0] dma_initiator_AWSIZE;
	output [1:0] dma_initiator_AWBURST;
	output [5:0] dma_initiator_AWID;
	output [31:0] dma_initiator_AWADDR;
	input dma_initiator_AWREADY;
	output dma_initiator_AWLOCK;
	output [3:0] dma_initiator_AWCACHE;
	output [2:0] dma_initiator_AWPROT;
	output [3:0] dma_initiator_AWQOS;
	output [3:0] dma_initiator_AWREGION;
	output dma_initiator_WVALID;
	output [3:0] dma_initiator_WSTRB;
	output [31:0] dma_initiator_WDATA;
	output dma_initiator_WLAST;
	input dma_initiator_WREADY;
	output dma_initiator_BREADY;
	input [5:0] dma_initiator_BID;
	input dma_initiator_BVALID;
	input [1:0] dma_initiator_BRESP;
	output dma_initiator_ARVALID;
	output [7:0] dma_initiator_ARLEN;
	output [2:0] dma_initiator_ARSIZE;
	output [1:0] dma_initiator_ARBURST;
	output [5:0] dma_initiator_ARID;
	output [31:0] dma_initiator_ARADDR;
	input dma_initiator_ARREADY;
	output dma_initiator_ARLOCK;
	output [3:0] dma_initiator_ARCACHE;
	output [2:0] dma_initiator_ARPROT;
	output [3:0] dma_initiator_ARQOS;
	output [3:0] dma_initiator_ARREGION;
	output dma_initiator_RREADY;
	input dma_initiator_RVALID;
	input [5:0] dma_initiator_RID;
	input [31:0] dma_initiator_RDATA;
	input [1:0] dma_initiator_RRESP;
	input dma_initiator_RLAST;
	
	`endif


endmodule
