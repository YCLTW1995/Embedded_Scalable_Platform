//
// Verilog co-simulation wrapper module for the sha module.

// This module contains the followng items:
//	- An instance of the verilog RTL module created by cynthVLG.
//	- Wires and reg's connected to the ports of the RTL module.
//	- A clock generator using the project's clock frequency and connected to
//    the RTL module's clock port.
//
// The wires and reg's will be connected to sc_signals in the SystemC simulaton
// by esc_link_signals calls in the proxy module found in the sha_cosim.h 
// file.

`timescale 1 ps / 1 ps

module sha_cosim;

	`ifdef ioConfig_IOCFG_32
	
	reg clk;
	reg rst;
	wire irq;
	reg reg_target_AWVALID;
	reg[31:0] reg_target_AWADDR;
	wire reg_target_AWREADY;
	reg[2:0] reg_target_AWPROT;
	reg reg_target_WVALID;
	reg[3:0] reg_target_WSTRB;
	reg[31:0] reg_target_WDATA;
	wire reg_target_WREADY;
	reg reg_target_BREADY;
	wire reg_target_BVALID;
	wire[1:0] reg_target_BRESP;
	reg reg_target_ARVALID;
	reg[31:0] reg_target_ARADDR;
	wire reg_target_ARREADY;
	reg[2:0] reg_target_ARPROT;
	reg reg_target_RREADY;
	wire reg_target_RVALID;
	wire[31:0] reg_target_RDATA;
	wire[1:0] reg_target_RRESP;
	wire dma_initiator_AWVALID;
	wire[7:0] dma_initiator_AWLEN;
	wire[2:0] dma_initiator_AWSIZE;
	wire[1:0] dma_initiator_AWBURST;
	wire[5:0] dma_initiator_AWID;
	wire[31:0] dma_initiator_AWADDR;
	reg dma_initiator_AWREADY;
	wire dma_initiator_AWLOCK;
	wire[3:0] dma_initiator_AWCACHE;
	wire[2:0] dma_initiator_AWPROT;
	wire[3:0] dma_initiator_AWQOS;
	wire[3:0] dma_initiator_AWREGION;
	wire dma_initiator_WVALID;
	wire[3:0] dma_initiator_WSTRB;
	wire[31:0] dma_initiator_WDATA;
	wire dma_initiator_WLAST;
	reg dma_initiator_WREADY;
	wire dma_initiator_BREADY;
	reg[5:0] dma_initiator_BID;
	reg dma_initiator_BVALID;
	reg[1:0] dma_initiator_BRESP;
	wire dma_initiator_ARVALID;
	wire[7:0] dma_initiator_ARLEN;
	wire[2:0] dma_initiator_ARSIZE;
	wire[1:0] dma_initiator_ARBURST;
	wire[5:0] dma_initiator_ARID;
	wire[31:0] dma_initiator_ARADDR;
	reg dma_initiator_ARREADY;
	wire dma_initiator_ARLOCK;
	wire[3:0] dma_initiator_ARCACHE;
	wire[2:0] dma_initiator_ARPROT;
	wire[3:0] dma_initiator_ARQOS;
	wire[3:0] dma_initiator_ARREGION;
	wire dma_initiator_RREADY;
	reg dma_initiator_RVALID;
	reg[5:0] dma_initiator_RID;
	reg[31:0] dma_initiator_RDATA;
	reg[1:0] dma_initiator_RRESP;
	reg dma_initiator_RLAST;
	
	`endif


	`include "hub.v"

	sha sha0( `ifdef ioConfig_IOCFG_32
	
	.clk(clk),
	 .rst(rst),
	 .irq(irq),
	 .reg_target_AWVALID(reg_target_AWVALID),
	 .reg_target_AWADDR(reg_target_AWADDR),
	 .reg_target_AWREADY(reg_target_AWREADY),
	 .reg_target_AWPROT(reg_target_AWPROT),
	 .reg_target_WVALID(reg_target_WVALID),
	 .reg_target_WSTRB(reg_target_WSTRB),
	 .reg_target_WDATA(reg_target_WDATA),
	 .reg_target_WREADY(reg_target_WREADY),
	 .reg_target_BREADY(reg_target_BREADY),
	 .reg_target_BVALID(reg_target_BVALID),
	 .reg_target_BRESP(reg_target_BRESP),
	 .reg_target_ARVALID(reg_target_ARVALID),
	 .reg_target_ARADDR(reg_target_ARADDR),
	 .reg_target_ARREADY(reg_target_ARREADY),
	 .reg_target_ARPROT(reg_target_ARPROT),
	 .reg_target_RREADY(reg_target_RREADY),
	 .reg_target_RVALID(reg_target_RVALID),
	 .reg_target_RDATA(reg_target_RDATA),
	 .reg_target_RRESP(reg_target_RRESP),
	 .dma_initiator_AWVALID(dma_initiator_AWVALID),
	 .dma_initiator_AWLEN(dma_initiator_AWLEN),
	 .dma_initiator_AWSIZE(dma_initiator_AWSIZE),
	 .dma_initiator_AWBURST(dma_initiator_AWBURST),
	 .dma_initiator_AWID(dma_initiator_AWID),
	 .dma_initiator_AWADDR(dma_initiator_AWADDR),
	 .dma_initiator_AWREADY(dma_initiator_AWREADY),
	 .dma_initiator_AWLOCK(dma_initiator_AWLOCK),
	 .dma_initiator_AWCACHE(dma_initiator_AWCACHE),
	 .dma_initiator_AWPROT(dma_initiator_AWPROT),
	 .dma_initiator_AWQOS(dma_initiator_AWQOS),
	 .dma_initiator_AWREGION(dma_initiator_AWREGION),
	 .dma_initiator_WVALID(dma_initiator_WVALID),
	 .dma_initiator_WSTRB(dma_initiator_WSTRB),
	 .dma_initiator_WDATA(dma_initiator_WDATA),
	 .dma_initiator_WLAST(dma_initiator_WLAST),
	 .dma_initiator_WREADY(dma_initiator_WREADY),
	 .dma_initiator_BREADY(dma_initiator_BREADY),
	 .dma_initiator_BID(dma_initiator_BID),
	 .dma_initiator_BVALID(dma_initiator_BVALID),
	 .dma_initiator_BRESP(dma_initiator_BRESP),
	 .dma_initiator_ARVALID(dma_initiator_ARVALID),
	 .dma_initiator_ARLEN(dma_initiator_ARLEN),
	 .dma_initiator_ARSIZE(dma_initiator_ARSIZE),
	 .dma_initiator_ARBURST(dma_initiator_ARBURST),
	 .dma_initiator_ARID(dma_initiator_ARID),
	 .dma_initiator_ARADDR(dma_initiator_ARADDR),
	 .dma_initiator_ARREADY(dma_initiator_ARREADY),
	 .dma_initiator_ARLOCK(dma_initiator_ARLOCK),
	 .dma_initiator_ARCACHE(dma_initiator_ARCACHE),
	 .dma_initiator_ARPROT(dma_initiator_ARPROT),
	 .dma_initiator_ARQOS(dma_initiator_ARQOS),
	 .dma_initiator_ARREGION(dma_initiator_ARREGION),
	 .dma_initiator_RREADY(dma_initiator_RREADY),
	 .dma_initiator_RVALID(dma_initiator_RVALID),
	 .dma_initiator_RID(dma_initiator_RID),
	 .dma_initiator_RDATA(dma_initiator_RDATA),
	 .dma_initiator_RRESP(dma_initiator_RRESP),
	 .dma_initiator_RLAST(dma_initiator_RLAST)
	`endif
	 );


	`ifdef ioConfig_IOCFG_32
	
	// Variables that can be set externally
	reg clk_firstEdge;
	reg clk_initialized;
	reg clk_started;
	real clk_startTime;
	real clk_firstHalf;
	real clk_secondHalf;
	
	initial begin
	
	    // Only send values from SystemC to the simulator at clock edges.
	    hubSetOption("cycleOnly=1");
	
	    // Default values for config variables.  Values come from static clock.
	    clk_firstEdge = 1'b1;
	    clk_startTime = 0.000;		// Offset from time 0 to first edge.
	    clk_firstHalf = 5.000;	// Delay for first half of cycle.
	    clk_secondHalf = 5.000;	// Second half of cycle less offset value.
	
	    // Make sure that we detect the transition on clk_initalized.
	    hubScheduleDelayedAssignments;
	
	    while ( clk_initialized !== 1'b1 )
	        @( clk_initialized );
	
	    if ( clk_startTime > 0.0 ) begin
	        clk_started = #clk_startTime 1;
	    end
	    else begin
	        clk_started = 1;
	    end
	end
	
	// Make sure that we process delayed assignments after the clock edge.
	always @( sha0.clk ) begin
	    if ( clk_started === 1'b1 ) begin
	        if ($time == top.cur_time) top.n_cur_time=top.n_cur_time-1;
	        else top.n_cur_time=0;
	        if (top.n_cur_time==0) begin
	            hubScheduleDelayedAssignments;
	        end
	    end
	end
	
	always begin
	    // Make sure our delays are non-zero before starting simulation.
	    while ( clk_started !== 1'b1 )
	        @( clk_started );
	
	    clk <= clk_firstEdge;
	    if ( clk_firstHalf > 0.0 ) begin
	        #clk_firstHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	        clk = ~clk_firstEdge;
	    end
	    else begin
	        clk = ~clk_firstEdge;
	    end
	    if ( clk_secondHalf > 0.0 ) begin
	        #clk_secondHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	    end
	end
	// Variables that can be set externally
	reg rst_firstEdge;
	reg rst_initialized;
	reg rst_started;
	real rst_startTime;
	real rst_firstHalf;
	real rst_secondHalf;
	
	initial begin
	
	    // Only send values from SystemC to the simulator at clock edges.
	    hubSetOption("cycleOnly=1");
	
	    // Default values for config variables.  Values come from static clock.
	    rst_firstEdge = 1'b1;
	    rst_startTime = 0.000;		// Offset from time 0 to first edge.
	    rst_firstHalf = 5.000;	// Delay for first half of cycle.
	    rst_secondHalf = 5.000;	// Second half of cycle less offset value.
	
	    // Make sure that we detect the transition on rst_initalized.
	    hubScheduleDelayedAssignments;
	
	    while ( rst_initialized !== 1'b1 )
	        @( rst_initialized );
	
	    if ( rst_startTime > 0.0 ) begin
	        rst_started = #rst_startTime 1;
	    end
	    else begin
	        rst_started = 1;
	    end
	end
	
	// Make sure that we process delayed assignments after the clock edge.
	always @( sha0.rst ) begin
	    if ( rst_started === 1'b1 ) begin
	        if ($time == top.cur_time) top.n_cur_time=top.n_cur_time-1;
	        else top.n_cur_time=0;
	        if (top.n_cur_time==0) begin
	            hubScheduleDelayedAssignments;
	        end
	    end
	end
	
	always begin
	    // Make sure our delays are non-zero before starting simulation.
	    while ( rst_started !== 1'b1 )
	        @( rst_started );
	
	    rst <= rst_firstEdge;
	    if ( rst_firstHalf > 0.0 ) begin
	        #rst_firstHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	        rst = ~rst_firstEdge;
	    end
	    else begin
	        rst = ~rst_firstEdge;
	    end
	    if ( rst_secondHalf > 0.0 ) begin
	        #rst_secondHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	    end
	end
	// Variables that can be set externally
	reg reg_target_AWVALID_firstEdge;
	reg reg_target_AWVALID_initialized;
	reg reg_target_AWVALID_started;
	real reg_target_AWVALID_startTime;
	real reg_target_AWVALID_firstHalf;
	real reg_target_AWVALID_secondHalf;
	
	initial begin
	
	    // Only send values from SystemC to the simulator at clock edges.
	    hubSetOption("cycleOnly=1");
	
	    // Default values for config variables.  Values come from static clock.
	    reg_target_AWVALID_firstEdge = 1'b1;
	    reg_target_AWVALID_startTime = 0.000;		// Offset from time 0 to first edge.
	    reg_target_AWVALID_firstHalf = 5.000;	// Delay for first half of cycle.
	    reg_target_AWVALID_secondHalf = 5.000;	// Second half of cycle less offset value.
	
	    // Make sure that we detect the transition on reg_target_AWVALID_initalized.
	    hubScheduleDelayedAssignments;
	
	    while ( reg_target_AWVALID_initialized !== 1'b1 )
	        @( reg_target_AWVALID_initialized );
	
	    if ( reg_target_AWVALID_startTime > 0.0 ) begin
	        reg_target_AWVALID_started = #reg_target_AWVALID_startTime 1;
	    end
	    else begin
	        reg_target_AWVALID_started = 1;
	    end
	end
	
	// Make sure that we process delayed assignments after the clock edge.
	always @( sha0.reg_target_AWVALID ) begin
	    if ( reg_target_AWVALID_started === 1'b1 ) begin
	        if ($time == top.cur_time) top.n_cur_time=top.n_cur_time-1;
	        else top.n_cur_time=0;
	        if (top.n_cur_time==0) begin
	            hubScheduleDelayedAssignments;
	        end
	    end
	end
	
	always begin
	    // Make sure our delays are non-zero before starting simulation.
	    while ( reg_target_AWVALID_started !== 1'b1 )
	        @( reg_target_AWVALID_started );
	
	    reg_target_AWVALID <= reg_target_AWVALID_firstEdge;
	    if ( reg_target_AWVALID_firstHalf > 0.0 ) begin
	        #reg_target_AWVALID_firstHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	        reg_target_AWVALID = ~reg_target_AWVALID_firstEdge;
	    end
	    else begin
	        reg_target_AWVALID = ~reg_target_AWVALID_firstEdge;
	    end
	    if ( reg_target_AWVALID_secondHalf > 0.0 ) begin
	        #reg_target_AWVALID_secondHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	    end
	end
	// Variables that can be set externally
	reg reg_target_WVALID_firstEdge;
	reg reg_target_WVALID_initialized;
	reg reg_target_WVALID_started;
	real reg_target_WVALID_startTime;
	real reg_target_WVALID_firstHalf;
	real reg_target_WVALID_secondHalf;
	
	initial begin
	
	    // Only send values from SystemC to the simulator at clock edges.
	    hubSetOption("cycleOnly=1");
	
	    // Default values for config variables.  Values come from static clock.
	    reg_target_WVALID_firstEdge = 1'b1;
	    reg_target_WVALID_startTime = 0.000;		// Offset from time 0 to first edge.
	    reg_target_WVALID_firstHalf = 5.000;	// Delay for first half of cycle.
	    reg_target_WVALID_secondHalf = 5.000;	// Second half of cycle less offset value.
	
	    // Make sure that we detect the transition on reg_target_WVALID_initalized.
	    hubScheduleDelayedAssignments;
	
	    while ( reg_target_WVALID_initialized !== 1'b1 )
	        @( reg_target_WVALID_initialized );
	
	    if ( reg_target_WVALID_startTime > 0.0 ) begin
	        reg_target_WVALID_started = #reg_target_WVALID_startTime 1;
	    end
	    else begin
	        reg_target_WVALID_started = 1;
	    end
	end
	
	// Make sure that we process delayed assignments after the clock edge.
	always @( sha0.reg_target_WVALID ) begin
	    if ( reg_target_WVALID_started === 1'b1 ) begin
	        if ($time == top.cur_time) top.n_cur_time=top.n_cur_time-1;
	        else top.n_cur_time=0;
	        if (top.n_cur_time==0) begin
	            hubScheduleDelayedAssignments;
	        end
	    end
	end
	
	always begin
	    // Make sure our delays are non-zero before starting simulation.
	    while ( reg_target_WVALID_started !== 1'b1 )
	        @( reg_target_WVALID_started );
	
	    reg_target_WVALID <= reg_target_WVALID_firstEdge;
	    if ( reg_target_WVALID_firstHalf > 0.0 ) begin
	        #reg_target_WVALID_firstHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	        reg_target_WVALID = ~reg_target_WVALID_firstEdge;
	    end
	    else begin
	        reg_target_WVALID = ~reg_target_WVALID_firstEdge;
	    end
	    if ( reg_target_WVALID_secondHalf > 0.0 ) begin
	        #reg_target_WVALID_secondHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	    end
	end
	// Variables that can be set externally
	reg reg_target_BREADY_firstEdge;
	reg reg_target_BREADY_initialized;
	reg reg_target_BREADY_started;
	real reg_target_BREADY_startTime;
	real reg_target_BREADY_firstHalf;
	real reg_target_BREADY_secondHalf;
	
	initial begin
	
	    // Only send values from SystemC to the simulator at clock edges.
	    hubSetOption("cycleOnly=1");
	
	    // Default values for config variables.  Values come from static clock.
	    reg_target_BREADY_firstEdge = 1'b1;
	    reg_target_BREADY_startTime = 0.000;		// Offset from time 0 to first edge.
	    reg_target_BREADY_firstHalf = 5.000;	// Delay for first half of cycle.
	    reg_target_BREADY_secondHalf = 5.000;	// Second half of cycle less offset value.
	
	    // Make sure that we detect the transition on reg_target_BREADY_initalized.
	    hubScheduleDelayedAssignments;
	
	    while ( reg_target_BREADY_initialized !== 1'b1 )
	        @( reg_target_BREADY_initialized );
	
	    if ( reg_target_BREADY_startTime > 0.0 ) begin
	        reg_target_BREADY_started = #reg_target_BREADY_startTime 1;
	    end
	    else begin
	        reg_target_BREADY_started = 1;
	    end
	end
	
	// Make sure that we process delayed assignments after the clock edge.
	always @( sha0.reg_target_BREADY ) begin
	    if ( reg_target_BREADY_started === 1'b1 ) begin
	        if ($time == top.cur_time) top.n_cur_time=top.n_cur_time-1;
	        else top.n_cur_time=0;
	        if (top.n_cur_time==0) begin
	            hubScheduleDelayedAssignments;
	        end
	    end
	end
	
	always begin
	    // Make sure our delays are non-zero before starting simulation.
	    while ( reg_target_BREADY_started !== 1'b1 )
	        @( reg_target_BREADY_started );
	
	    reg_target_BREADY <= reg_target_BREADY_firstEdge;
	    if ( reg_target_BREADY_firstHalf > 0.0 ) begin
	        #reg_target_BREADY_firstHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	        reg_target_BREADY = ~reg_target_BREADY_firstEdge;
	    end
	    else begin
	        reg_target_BREADY = ~reg_target_BREADY_firstEdge;
	    end
	    if ( reg_target_BREADY_secondHalf > 0.0 ) begin
	        #reg_target_BREADY_secondHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	    end
	end
	// Variables that can be set externally
	reg reg_target_ARVALID_firstEdge;
	reg reg_target_ARVALID_initialized;
	reg reg_target_ARVALID_started;
	real reg_target_ARVALID_startTime;
	real reg_target_ARVALID_firstHalf;
	real reg_target_ARVALID_secondHalf;
	
	initial begin
	
	    // Only send values from SystemC to the simulator at clock edges.
	    hubSetOption("cycleOnly=1");
	
	    // Default values for config variables.  Values come from static clock.
	    reg_target_ARVALID_firstEdge = 1'b1;
	    reg_target_ARVALID_startTime = 0.000;		// Offset from time 0 to first edge.
	    reg_target_ARVALID_firstHalf = 5.000;	// Delay for first half of cycle.
	    reg_target_ARVALID_secondHalf = 5.000;	// Second half of cycle less offset value.
	
	    // Make sure that we detect the transition on reg_target_ARVALID_initalized.
	    hubScheduleDelayedAssignments;
	
	    while ( reg_target_ARVALID_initialized !== 1'b1 )
	        @( reg_target_ARVALID_initialized );
	
	    if ( reg_target_ARVALID_startTime > 0.0 ) begin
	        reg_target_ARVALID_started = #reg_target_ARVALID_startTime 1;
	    end
	    else begin
	        reg_target_ARVALID_started = 1;
	    end
	end
	
	// Make sure that we process delayed assignments after the clock edge.
	always @( sha0.reg_target_ARVALID ) begin
	    if ( reg_target_ARVALID_started === 1'b1 ) begin
	        if ($time == top.cur_time) top.n_cur_time=top.n_cur_time-1;
	        else top.n_cur_time=0;
	        if (top.n_cur_time==0) begin
	            hubScheduleDelayedAssignments;
	        end
	    end
	end
	
	always begin
	    // Make sure our delays are non-zero before starting simulation.
	    while ( reg_target_ARVALID_started !== 1'b1 )
	        @( reg_target_ARVALID_started );
	
	    reg_target_ARVALID <= reg_target_ARVALID_firstEdge;
	    if ( reg_target_ARVALID_firstHalf > 0.0 ) begin
	        #reg_target_ARVALID_firstHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	        reg_target_ARVALID = ~reg_target_ARVALID_firstEdge;
	    end
	    else begin
	        reg_target_ARVALID = ~reg_target_ARVALID_firstEdge;
	    end
	    if ( reg_target_ARVALID_secondHalf > 0.0 ) begin
	        #reg_target_ARVALID_secondHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	    end
	end
	// Variables that can be set externally
	reg reg_target_RREADY_firstEdge;
	reg reg_target_RREADY_initialized;
	reg reg_target_RREADY_started;
	real reg_target_RREADY_startTime;
	real reg_target_RREADY_firstHalf;
	real reg_target_RREADY_secondHalf;
	
	initial begin
	
	    // Only send values from SystemC to the simulator at clock edges.
	    hubSetOption("cycleOnly=1");
	
	    // Default values for config variables.  Values come from static clock.
	    reg_target_RREADY_firstEdge = 1'b1;
	    reg_target_RREADY_startTime = 0.000;		// Offset from time 0 to first edge.
	    reg_target_RREADY_firstHalf = 5.000;	// Delay for first half of cycle.
	    reg_target_RREADY_secondHalf = 5.000;	// Second half of cycle less offset value.
	
	    // Make sure that we detect the transition on reg_target_RREADY_initalized.
	    hubScheduleDelayedAssignments;
	
	    while ( reg_target_RREADY_initialized !== 1'b1 )
	        @( reg_target_RREADY_initialized );
	
	    if ( reg_target_RREADY_startTime > 0.0 ) begin
	        reg_target_RREADY_started = #reg_target_RREADY_startTime 1;
	    end
	    else begin
	        reg_target_RREADY_started = 1;
	    end
	end
	
	// Make sure that we process delayed assignments after the clock edge.
	always @( sha0.reg_target_RREADY ) begin
	    if ( reg_target_RREADY_started === 1'b1 ) begin
	        if ($time == top.cur_time) top.n_cur_time=top.n_cur_time-1;
	        else top.n_cur_time=0;
	        if (top.n_cur_time==0) begin
	            hubScheduleDelayedAssignments;
	        end
	    end
	end
	
	always begin
	    // Make sure our delays are non-zero before starting simulation.
	    while ( reg_target_RREADY_started !== 1'b1 )
	        @( reg_target_RREADY_started );
	
	    reg_target_RREADY <= reg_target_RREADY_firstEdge;
	    if ( reg_target_RREADY_firstHalf > 0.0 ) begin
	        #reg_target_RREADY_firstHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	        reg_target_RREADY = ~reg_target_RREADY_firstEdge;
	    end
	    else begin
	        reg_target_RREADY = ~reg_target_RREADY_firstEdge;
	    end
	    if ( reg_target_RREADY_secondHalf > 0.0 ) begin
	        #reg_target_RREADY_secondHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	    end
	end
	// Variables that can be set externally
	reg dma_initiator_AWREADY_firstEdge;
	reg dma_initiator_AWREADY_initialized;
	reg dma_initiator_AWREADY_started;
	real dma_initiator_AWREADY_startTime;
	real dma_initiator_AWREADY_firstHalf;
	real dma_initiator_AWREADY_secondHalf;
	
	initial begin
	
	    // Only send values from SystemC to the simulator at clock edges.
	    hubSetOption("cycleOnly=1");
	
	    // Default values for config variables.  Values come from static clock.
	    dma_initiator_AWREADY_firstEdge = 1'b1;
	    dma_initiator_AWREADY_startTime = 0.000;		// Offset from time 0 to first edge.
	    dma_initiator_AWREADY_firstHalf = 5.000;	// Delay for first half of cycle.
	    dma_initiator_AWREADY_secondHalf = 5.000;	// Second half of cycle less offset value.
	
	    // Make sure that we detect the transition on dma_initiator_AWREADY_initalized.
	    hubScheduleDelayedAssignments;
	
	    while ( dma_initiator_AWREADY_initialized !== 1'b1 )
	        @( dma_initiator_AWREADY_initialized );
	
	    if ( dma_initiator_AWREADY_startTime > 0.0 ) begin
	        dma_initiator_AWREADY_started = #dma_initiator_AWREADY_startTime 1;
	    end
	    else begin
	        dma_initiator_AWREADY_started = 1;
	    end
	end
	
	// Make sure that we process delayed assignments after the clock edge.
	always @( sha0.dma_initiator_AWREADY ) begin
	    if ( dma_initiator_AWREADY_started === 1'b1 ) begin
	        if ($time == top.cur_time) top.n_cur_time=top.n_cur_time-1;
	        else top.n_cur_time=0;
	        if (top.n_cur_time==0) begin
	            hubScheduleDelayedAssignments;
	        end
	    end
	end
	
	always begin
	    // Make sure our delays are non-zero before starting simulation.
	    while ( dma_initiator_AWREADY_started !== 1'b1 )
	        @( dma_initiator_AWREADY_started );
	
	    dma_initiator_AWREADY <= dma_initiator_AWREADY_firstEdge;
	    if ( dma_initiator_AWREADY_firstHalf > 0.0 ) begin
	        #dma_initiator_AWREADY_firstHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	        dma_initiator_AWREADY = ~dma_initiator_AWREADY_firstEdge;
	    end
	    else begin
	        dma_initiator_AWREADY = ~dma_initiator_AWREADY_firstEdge;
	    end
	    if ( dma_initiator_AWREADY_secondHalf > 0.0 ) begin
	        #dma_initiator_AWREADY_secondHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	    end
	end
	// Variables that can be set externally
	reg dma_initiator_WREADY_firstEdge;
	reg dma_initiator_WREADY_initialized;
	reg dma_initiator_WREADY_started;
	real dma_initiator_WREADY_startTime;
	real dma_initiator_WREADY_firstHalf;
	real dma_initiator_WREADY_secondHalf;
	
	initial begin
	
	    // Only send values from SystemC to the simulator at clock edges.
	    hubSetOption("cycleOnly=1");
	
	    // Default values for config variables.  Values come from static clock.
	    dma_initiator_WREADY_firstEdge = 1'b1;
	    dma_initiator_WREADY_startTime = 0.000;		// Offset from time 0 to first edge.
	    dma_initiator_WREADY_firstHalf = 5.000;	// Delay for first half of cycle.
	    dma_initiator_WREADY_secondHalf = 5.000;	// Second half of cycle less offset value.
	
	    // Make sure that we detect the transition on dma_initiator_WREADY_initalized.
	    hubScheduleDelayedAssignments;
	
	    while ( dma_initiator_WREADY_initialized !== 1'b1 )
	        @( dma_initiator_WREADY_initialized );
	
	    if ( dma_initiator_WREADY_startTime > 0.0 ) begin
	        dma_initiator_WREADY_started = #dma_initiator_WREADY_startTime 1;
	    end
	    else begin
	        dma_initiator_WREADY_started = 1;
	    end
	end
	
	// Make sure that we process delayed assignments after the clock edge.
	always @( sha0.dma_initiator_WREADY ) begin
	    if ( dma_initiator_WREADY_started === 1'b1 ) begin
	        if ($time == top.cur_time) top.n_cur_time=top.n_cur_time-1;
	        else top.n_cur_time=0;
	        if (top.n_cur_time==0) begin
	            hubScheduleDelayedAssignments;
	        end
	    end
	end
	
	always begin
	    // Make sure our delays are non-zero before starting simulation.
	    while ( dma_initiator_WREADY_started !== 1'b1 )
	        @( dma_initiator_WREADY_started );
	
	    dma_initiator_WREADY <= dma_initiator_WREADY_firstEdge;
	    if ( dma_initiator_WREADY_firstHalf > 0.0 ) begin
	        #dma_initiator_WREADY_firstHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	        dma_initiator_WREADY = ~dma_initiator_WREADY_firstEdge;
	    end
	    else begin
	        dma_initiator_WREADY = ~dma_initiator_WREADY_firstEdge;
	    end
	    if ( dma_initiator_WREADY_secondHalf > 0.0 ) begin
	        #dma_initiator_WREADY_secondHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	    end
	end
	// Variables that can be set externally
	reg dma_initiator_BVALID_firstEdge;
	reg dma_initiator_BVALID_initialized;
	reg dma_initiator_BVALID_started;
	real dma_initiator_BVALID_startTime;
	real dma_initiator_BVALID_firstHalf;
	real dma_initiator_BVALID_secondHalf;
	
	initial begin
	
	    // Only send values from SystemC to the simulator at clock edges.
	    hubSetOption("cycleOnly=1");
	
	    // Default values for config variables.  Values come from static clock.
	    dma_initiator_BVALID_firstEdge = 1'b1;
	    dma_initiator_BVALID_startTime = 0.000;		// Offset from time 0 to first edge.
	    dma_initiator_BVALID_firstHalf = 5.000;	// Delay for first half of cycle.
	    dma_initiator_BVALID_secondHalf = 5.000;	// Second half of cycle less offset value.
	
	    // Make sure that we detect the transition on dma_initiator_BVALID_initalized.
	    hubScheduleDelayedAssignments;
	
	    while ( dma_initiator_BVALID_initialized !== 1'b1 )
	        @( dma_initiator_BVALID_initialized );
	
	    if ( dma_initiator_BVALID_startTime > 0.0 ) begin
	        dma_initiator_BVALID_started = #dma_initiator_BVALID_startTime 1;
	    end
	    else begin
	        dma_initiator_BVALID_started = 1;
	    end
	end
	
	// Make sure that we process delayed assignments after the clock edge.
	always @( sha0.dma_initiator_BVALID ) begin
	    if ( dma_initiator_BVALID_started === 1'b1 ) begin
	        if ($time == top.cur_time) top.n_cur_time=top.n_cur_time-1;
	        else top.n_cur_time=0;
	        if (top.n_cur_time==0) begin
	            hubScheduleDelayedAssignments;
	        end
	    end
	end
	
	always begin
	    // Make sure our delays are non-zero before starting simulation.
	    while ( dma_initiator_BVALID_started !== 1'b1 )
	        @( dma_initiator_BVALID_started );
	
	    dma_initiator_BVALID <= dma_initiator_BVALID_firstEdge;
	    if ( dma_initiator_BVALID_firstHalf > 0.0 ) begin
	        #dma_initiator_BVALID_firstHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	        dma_initiator_BVALID = ~dma_initiator_BVALID_firstEdge;
	    end
	    else begin
	        dma_initiator_BVALID = ~dma_initiator_BVALID_firstEdge;
	    end
	    if ( dma_initiator_BVALID_secondHalf > 0.0 ) begin
	        #dma_initiator_BVALID_secondHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	    end
	end
	// Variables that can be set externally
	reg dma_initiator_ARREADY_firstEdge;
	reg dma_initiator_ARREADY_initialized;
	reg dma_initiator_ARREADY_started;
	real dma_initiator_ARREADY_startTime;
	real dma_initiator_ARREADY_firstHalf;
	real dma_initiator_ARREADY_secondHalf;
	
	initial begin
	
	    // Only send values from SystemC to the simulator at clock edges.
	    hubSetOption("cycleOnly=1");
	
	    // Default values for config variables.  Values come from static clock.
	    dma_initiator_ARREADY_firstEdge = 1'b1;
	    dma_initiator_ARREADY_startTime = 0.000;		// Offset from time 0 to first edge.
	    dma_initiator_ARREADY_firstHalf = 5.000;	// Delay for first half of cycle.
	    dma_initiator_ARREADY_secondHalf = 5.000;	// Second half of cycle less offset value.
	
	    // Make sure that we detect the transition on dma_initiator_ARREADY_initalized.
	    hubScheduleDelayedAssignments;
	
	    while ( dma_initiator_ARREADY_initialized !== 1'b1 )
	        @( dma_initiator_ARREADY_initialized );
	
	    if ( dma_initiator_ARREADY_startTime > 0.0 ) begin
	        dma_initiator_ARREADY_started = #dma_initiator_ARREADY_startTime 1;
	    end
	    else begin
	        dma_initiator_ARREADY_started = 1;
	    end
	end
	
	// Make sure that we process delayed assignments after the clock edge.
	always @( sha0.dma_initiator_ARREADY ) begin
	    if ( dma_initiator_ARREADY_started === 1'b1 ) begin
	        if ($time == top.cur_time) top.n_cur_time=top.n_cur_time-1;
	        else top.n_cur_time=0;
	        if (top.n_cur_time==0) begin
	            hubScheduleDelayedAssignments;
	        end
	    end
	end
	
	always begin
	    // Make sure our delays are non-zero before starting simulation.
	    while ( dma_initiator_ARREADY_started !== 1'b1 )
	        @( dma_initiator_ARREADY_started );
	
	    dma_initiator_ARREADY <= dma_initiator_ARREADY_firstEdge;
	    if ( dma_initiator_ARREADY_firstHalf > 0.0 ) begin
	        #dma_initiator_ARREADY_firstHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	        dma_initiator_ARREADY = ~dma_initiator_ARREADY_firstEdge;
	    end
	    else begin
	        dma_initiator_ARREADY = ~dma_initiator_ARREADY_firstEdge;
	    end
	    if ( dma_initiator_ARREADY_secondHalf > 0.0 ) begin
	        #dma_initiator_ARREADY_secondHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	    end
	end
	// Variables that can be set externally
	reg dma_initiator_RVALID_firstEdge;
	reg dma_initiator_RVALID_initialized;
	reg dma_initiator_RVALID_started;
	real dma_initiator_RVALID_startTime;
	real dma_initiator_RVALID_firstHalf;
	real dma_initiator_RVALID_secondHalf;
	
	initial begin
	
	    // Only send values from SystemC to the simulator at clock edges.
	    hubSetOption("cycleOnly=1");
	
	    // Default values for config variables.  Values come from static clock.
	    dma_initiator_RVALID_firstEdge = 1'b1;
	    dma_initiator_RVALID_startTime = 0.000;		// Offset from time 0 to first edge.
	    dma_initiator_RVALID_firstHalf = 5.000;	// Delay for first half of cycle.
	    dma_initiator_RVALID_secondHalf = 5.000;	// Second half of cycle less offset value.
	
	    // Make sure that we detect the transition on dma_initiator_RVALID_initalized.
	    hubScheduleDelayedAssignments;
	
	    while ( dma_initiator_RVALID_initialized !== 1'b1 )
	        @( dma_initiator_RVALID_initialized );
	
	    if ( dma_initiator_RVALID_startTime > 0.0 ) begin
	        dma_initiator_RVALID_started = #dma_initiator_RVALID_startTime 1;
	    end
	    else begin
	        dma_initiator_RVALID_started = 1;
	    end
	end
	
	// Make sure that we process delayed assignments after the clock edge.
	always @( sha0.dma_initiator_RVALID ) begin
	    if ( dma_initiator_RVALID_started === 1'b1 ) begin
	        if ($time == top.cur_time) top.n_cur_time=top.n_cur_time-1;
	        else top.n_cur_time=0;
	        if (top.n_cur_time==0) begin
	            hubScheduleDelayedAssignments;
	        end
	    end
	end
	
	always begin
	    // Make sure our delays are non-zero before starting simulation.
	    while ( dma_initiator_RVALID_started !== 1'b1 )
	        @( dma_initiator_RVALID_started );
	
	    dma_initiator_RVALID <= dma_initiator_RVALID_firstEdge;
	    if ( dma_initiator_RVALID_firstHalf > 0.0 ) begin
	        #dma_initiator_RVALID_firstHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	        dma_initiator_RVALID = ~dma_initiator_RVALID_firstEdge;
	    end
	    else begin
	        dma_initiator_RVALID = ~dma_initiator_RVALID_firstEdge;
	    end
	    if ( dma_initiator_RVALID_secondHalf > 0.0 ) begin
	        #dma_initiator_RVALID_secondHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	    end
	end
	// Variables that can be set externally
	reg dma_initiator_RLAST_firstEdge;
	reg dma_initiator_RLAST_initialized;
	reg dma_initiator_RLAST_started;
	real dma_initiator_RLAST_startTime;
	real dma_initiator_RLAST_firstHalf;
	real dma_initiator_RLAST_secondHalf;
	
	initial begin
	
	    // Only send values from SystemC to the simulator at clock edges.
	    hubSetOption("cycleOnly=1");
	
	    // Default values for config variables.  Values come from static clock.
	    dma_initiator_RLAST_firstEdge = 1'b1;
	    dma_initiator_RLAST_startTime = 0.000;		// Offset from time 0 to first edge.
	    dma_initiator_RLAST_firstHalf = 5.000;	// Delay for first half of cycle.
	    dma_initiator_RLAST_secondHalf = 5.000;	// Second half of cycle less offset value.
	
	    // Make sure that we detect the transition on dma_initiator_RLAST_initalized.
	    hubScheduleDelayedAssignments;
	
	    while ( dma_initiator_RLAST_initialized !== 1'b1 )
	        @( dma_initiator_RLAST_initialized );
	
	    if ( dma_initiator_RLAST_startTime > 0.0 ) begin
	        dma_initiator_RLAST_started = #dma_initiator_RLAST_startTime 1;
	    end
	    else begin
	        dma_initiator_RLAST_started = 1;
	    end
	end
	
	// Make sure that we process delayed assignments after the clock edge.
	always @( sha0.dma_initiator_RLAST ) begin
	    if ( dma_initiator_RLAST_started === 1'b1 ) begin
	        if ($time == top.cur_time) top.n_cur_time=top.n_cur_time-1;
	        else top.n_cur_time=0;
	        if (top.n_cur_time==0) begin
	            hubScheduleDelayedAssignments;
	        end
	    end
	end
	
	always begin
	    // Make sure our delays are non-zero before starting simulation.
	    while ( dma_initiator_RLAST_started !== 1'b1 )
	        @( dma_initiator_RLAST_started );
	
	    dma_initiator_RLAST <= dma_initiator_RLAST_firstEdge;
	    if ( dma_initiator_RLAST_firstHalf > 0.0 ) begin
	        #dma_initiator_RLAST_firstHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	        dma_initiator_RLAST = ~dma_initiator_RLAST_firstEdge;
	    end
	    else begin
	        dma_initiator_RLAST = ~dma_initiator_RLAST_firstEdge;
	    end
	    if ( dma_initiator_RLAST_secondHalf > 0.0 ) begin
	        #dma_initiator_RLAST_secondHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	    end
	end
	
	`endif


endmodule
