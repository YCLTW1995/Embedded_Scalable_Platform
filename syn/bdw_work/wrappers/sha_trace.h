#ifdef ioConfig_IOCFG_32
	if ( esc_trace_is_enabled( esc_trace_vcd ) ) {
		if ( sha0 != NULL ) {
			esc_trace_signal( &sha0->clk, ( std::string(name()) + std::string( ".sha.clk" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->rst, ( std::string(name()) + std::string( ".sha.rst" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->irq, ( std::string(name()) + std::string( ".sha.irq" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->reg_target.AWVALID, ( std::string(name()) + std::string( ".sha.reg_target.AWVALID" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->reg_target.AWADDR, ( std::string(name()) + std::string( ".sha.reg_target.AWADDR" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->reg_target.AWREADY, ( std::string(name()) + std::string( ".sha.reg_target.AWREADY" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->reg_target.AWPROT, ( std::string(name()) + std::string( ".sha.reg_target.AWPROT" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->reg_target.WVALID, ( std::string(name()) + std::string( ".sha.reg_target.WVALID" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->reg_target.WSTRB, ( std::string(name()) + std::string( ".sha.reg_target.WSTRB" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->reg_target.WDATA, ( std::string(name()) + std::string( ".sha.reg_target.WDATA" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->reg_target.WREADY, ( std::string(name()) + std::string( ".sha.reg_target.WREADY" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->reg_target.BREADY, ( std::string(name()) + std::string( ".sha.reg_target.BREADY" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->reg_target.BVALID, ( std::string(name()) + std::string( ".sha.reg_target.BVALID" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->reg_target.BRESP, ( std::string(name()) + std::string( ".sha.reg_target.BRESP" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->reg_target.ARVALID, ( std::string(name()) + std::string( ".sha.reg_target.ARVALID" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->reg_target.ARADDR, ( std::string(name()) + std::string( ".sha.reg_target.ARADDR" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->reg_target.ARREADY, ( std::string(name()) + std::string( ".sha.reg_target.ARREADY" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->reg_target.ARPROT, ( std::string(name()) + std::string( ".sha.reg_target.ARPROT" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->reg_target.RREADY, ( std::string(name()) + std::string( ".sha.reg_target.RREADY" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->reg_target.RVALID, ( std::string(name()) + std::string( ".sha.reg_target.RVALID" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->reg_target.RDATA, ( std::string(name()) + std::string( ".sha.reg_target.RDATA" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->reg_target.RRESP, ( std::string(name()) + std::string( ".sha.reg_target.RRESP" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->dma_initiator.AWVALID, ( std::string(name()) + std::string( ".sha.dma_initiator.AWVALID" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->dma_initiator.AWLEN, ( std::string(name()) + std::string( ".sha.dma_initiator.AWLEN" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->dma_initiator.AWSIZE, ( std::string(name()) + std::string( ".sha.dma_initiator.AWSIZE" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->dma_initiator.AWBURST, ( std::string(name()) + std::string( ".sha.dma_initiator.AWBURST" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->dma_initiator.AWID, ( std::string(name()) + std::string( ".sha.dma_initiator.AWID" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->dma_initiator.AWADDR, ( std::string(name()) + std::string( ".sha.dma_initiator.AWADDR" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->dma_initiator.AWREADY, ( std::string(name()) + std::string( ".sha.dma_initiator.AWREADY" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->dma_initiator.AWLOCK, ( std::string(name()) + std::string( ".sha.dma_initiator.AWLOCK" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->dma_initiator.AWCACHE, ( std::string(name()) + std::string( ".sha.dma_initiator.AWCACHE" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->dma_initiator.AWPROT, ( std::string(name()) + std::string( ".sha.dma_initiator.AWPROT" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->dma_initiator.AWQOS, ( std::string(name()) + std::string( ".sha.dma_initiator.AWQOS" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->dma_initiator.AWREGION, ( std::string(name()) + std::string( ".sha.dma_initiator.AWREGION" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->dma_initiator.WVALID, ( std::string(name()) + std::string( ".sha.dma_initiator.WVALID" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->dma_initiator.WSTRB, ( std::string(name()) + std::string( ".sha.dma_initiator.WSTRB" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->dma_initiator.WDATA, ( std::string(name()) + std::string( ".sha.dma_initiator.WDATA" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->dma_initiator.WLAST, ( std::string(name()) + std::string( ".sha.dma_initiator.WLAST" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->dma_initiator.WREADY, ( std::string(name()) + std::string( ".sha.dma_initiator.WREADY" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->dma_initiator.BREADY, ( std::string(name()) + std::string( ".sha.dma_initiator.BREADY" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->dma_initiator.BID, ( std::string(name()) + std::string( ".sha.dma_initiator.BID" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->dma_initiator.BVALID, ( std::string(name()) + std::string( ".sha.dma_initiator.BVALID" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->dma_initiator.BRESP, ( std::string(name()) + std::string( ".sha.dma_initiator.BRESP" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->dma_initiator.ARVALID, ( std::string(name()) + std::string( ".sha.dma_initiator.ARVALID" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->dma_initiator.ARLEN, ( std::string(name()) + std::string( ".sha.dma_initiator.ARLEN" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->dma_initiator.ARSIZE, ( std::string(name()) + std::string( ".sha.dma_initiator.ARSIZE" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->dma_initiator.ARBURST, ( std::string(name()) + std::string( ".sha.dma_initiator.ARBURST" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->dma_initiator.ARID, ( std::string(name()) + std::string( ".sha.dma_initiator.ARID" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->dma_initiator.ARADDR, ( std::string(name()) + std::string( ".sha.dma_initiator.ARADDR" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->dma_initiator.ARREADY, ( std::string(name()) + std::string( ".sha.dma_initiator.ARREADY" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->dma_initiator.ARLOCK, ( std::string(name()) + std::string( ".sha.dma_initiator.ARLOCK" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->dma_initiator.ARCACHE, ( std::string(name()) + std::string( ".sha.dma_initiator.ARCACHE" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->dma_initiator.ARPROT, ( std::string(name()) + std::string( ".sha.dma_initiator.ARPROT" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->dma_initiator.ARQOS, ( std::string(name()) + std::string( ".sha.dma_initiator.ARQOS" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->dma_initiator.ARREGION, ( std::string(name()) + std::string( ".sha.dma_initiator.ARREGION" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->dma_initiator.RREADY, ( std::string(name()) + std::string( ".sha.dma_initiator.RREADY" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->dma_initiator.RVALID, ( std::string(name()) + std::string( ".sha.dma_initiator.RVALID" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->dma_initiator.RID, ( std::string(name()) + std::string( ".sha.dma_initiator.RID" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->dma_initiator.RDATA, ( std::string(name()) + std::string( ".sha.dma_initiator.RDATA" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->dma_initiator.RRESP, ( std::string(name()) + std::string( ".sha.dma_initiator.RRESP" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->dma_initiator.RLAST, ( std::string(name()) + std::string( ".sha.dma_initiator.RLAST" ) ).c_str(), esc_trace_vcd );
			#if !BDW_RTL && !BDW_CC_SPEC
			esc_trace_signal( &sha0->config_ok_sig, ( std::string(name()) + std::string( ".sha.config_ok_sig" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->cmd_sig, ( std::string(name()) + std::string( ".sha.cmd_sig" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->status_sig, ( std::string(name()) + std::string( ".sha.status_sig" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &sha0->in_data_base_addr_sig, ( std::string(name()) + std::string( ".sha.in_data_base_addr_sig" ) ).c_str(), esc_trace_vcd );
			#endif
		}
	}
	if ( esc_trace_is_enabled( esc_trace_fsdb ) ) {
		if ( sha0 != NULL ) {
			esc_trace_signal( &sha0->clk, ( std::string(name()) + std::string( ".sha.clk" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->rst, ( std::string(name()) + std::string( ".sha.rst" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->irq, ( std::string(name()) + std::string( ".sha.irq" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->reg_target.AWVALID, ( std::string(name()) + std::string( ".sha.reg_target.AWVALID" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->reg_target.AWADDR, ( std::string(name()) + std::string( ".sha.reg_target.AWADDR" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->reg_target.AWREADY, ( std::string(name()) + std::string( ".sha.reg_target.AWREADY" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->reg_target.AWPROT, ( std::string(name()) + std::string( ".sha.reg_target.AWPROT" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->reg_target.WVALID, ( std::string(name()) + std::string( ".sha.reg_target.WVALID" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->reg_target.WSTRB, ( std::string(name()) + std::string( ".sha.reg_target.WSTRB" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->reg_target.WDATA, ( std::string(name()) + std::string( ".sha.reg_target.WDATA" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->reg_target.WREADY, ( std::string(name()) + std::string( ".sha.reg_target.WREADY" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->reg_target.BREADY, ( std::string(name()) + std::string( ".sha.reg_target.BREADY" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->reg_target.BVALID, ( std::string(name()) + std::string( ".sha.reg_target.BVALID" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->reg_target.BRESP, ( std::string(name()) + std::string( ".sha.reg_target.BRESP" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->reg_target.ARVALID, ( std::string(name()) + std::string( ".sha.reg_target.ARVALID" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->reg_target.ARADDR, ( std::string(name()) + std::string( ".sha.reg_target.ARADDR" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->reg_target.ARREADY, ( std::string(name()) + std::string( ".sha.reg_target.ARREADY" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->reg_target.ARPROT, ( std::string(name()) + std::string( ".sha.reg_target.ARPROT" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->reg_target.RREADY, ( std::string(name()) + std::string( ".sha.reg_target.RREADY" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->reg_target.RVALID, ( std::string(name()) + std::string( ".sha.reg_target.RVALID" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->reg_target.RDATA, ( std::string(name()) + std::string( ".sha.reg_target.RDATA" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->reg_target.RRESP, ( std::string(name()) + std::string( ".sha.reg_target.RRESP" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->dma_initiator.AWVALID, ( std::string(name()) + std::string( ".sha.dma_initiator.AWVALID" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->dma_initiator.AWLEN, ( std::string(name()) + std::string( ".sha.dma_initiator.AWLEN" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->dma_initiator.AWSIZE, ( std::string(name()) + std::string( ".sha.dma_initiator.AWSIZE" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->dma_initiator.AWBURST, ( std::string(name()) + std::string( ".sha.dma_initiator.AWBURST" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->dma_initiator.AWID, ( std::string(name()) + std::string( ".sha.dma_initiator.AWID" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->dma_initiator.AWADDR, ( std::string(name()) + std::string( ".sha.dma_initiator.AWADDR" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->dma_initiator.AWREADY, ( std::string(name()) + std::string( ".sha.dma_initiator.AWREADY" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->dma_initiator.AWLOCK, ( std::string(name()) + std::string( ".sha.dma_initiator.AWLOCK" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->dma_initiator.AWCACHE, ( std::string(name()) + std::string( ".sha.dma_initiator.AWCACHE" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->dma_initiator.AWPROT, ( std::string(name()) + std::string( ".sha.dma_initiator.AWPROT" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->dma_initiator.AWQOS, ( std::string(name()) + std::string( ".sha.dma_initiator.AWQOS" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->dma_initiator.AWREGION, ( std::string(name()) + std::string( ".sha.dma_initiator.AWREGION" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->dma_initiator.WVALID, ( std::string(name()) + std::string( ".sha.dma_initiator.WVALID" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->dma_initiator.WSTRB, ( std::string(name()) + std::string( ".sha.dma_initiator.WSTRB" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->dma_initiator.WDATA, ( std::string(name()) + std::string( ".sha.dma_initiator.WDATA" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->dma_initiator.WLAST, ( std::string(name()) + std::string( ".sha.dma_initiator.WLAST" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->dma_initiator.WREADY, ( std::string(name()) + std::string( ".sha.dma_initiator.WREADY" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->dma_initiator.BREADY, ( std::string(name()) + std::string( ".sha.dma_initiator.BREADY" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->dma_initiator.BID, ( std::string(name()) + std::string( ".sha.dma_initiator.BID" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->dma_initiator.BVALID, ( std::string(name()) + std::string( ".sha.dma_initiator.BVALID" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->dma_initiator.BRESP, ( std::string(name()) + std::string( ".sha.dma_initiator.BRESP" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->dma_initiator.ARVALID, ( std::string(name()) + std::string( ".sha.dma_initiator.ARVALID" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->dma_initiator.ARLEN, ( std::string(name()) + std::string( ".sha.dma_initiator.ARLEN" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->dma_initiator.ARSIZE, ( std::string(name()) + std::string( ".sha.dma_initiator.ARSIZE" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->dma_initiator.ARBURST, ( std::string(name()) + std::string( ".sha.dma_initiator.ARBURST" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->dma_initiator.ARID, ( std::string(name()) + std::string( ".sha.dma_initiator.ARID" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->dma_initiator.ARADDR, ( std::string(name()) + std::string( ".sha.dma_initiator.ARADDR" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->dma_initiator.ARREADY, ( std::string(name()) + std::string( ".sha.dma_initiator.ARREADY" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->dma_initiator.ARLOCK, ( std::string(name()) + std::string( ".sha.dma_initiator.ARLOCK" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->dma_initiator.ARCACHE, ( std::string(name()) + std::string( ".sha.dma_initiator.ARCACHE" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->dma_initiator.ARPROT, ( std::string(name()) + std::string( ".sha.dma_initiator.ARPROT" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->dma_initiator.ARQOS, ( std::string(name()) + std::string( ".sha.dma_initiator.ARQOS" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->dma_initiator.ARREGION, ( std::string(name()) + std::string( ".sha.dma_initiator.ARREGION" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->dma_initiator.RREADY, ( std::string(name()) + std::string( ".sha.dma_initiator.RREADY" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->dma_initiator.RVALID, ( std::string(name()) + std::string( ".sha.dma_initiator.RVALID" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->dma_initiator.RID, ( std::string(name()) + std::string( ".sha.dma_initiator.RID" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->dma_initiator.RDATA, ( std::string(name()) + std::string( ".sha.dma_initiator.RDATA" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->dma_initiator.RRESP, ( std::string(name()) + std::string( ".sha.dma_initiator.RRESP" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->dma_initiator.RLAST, ( std::string(name()) + std::string( ".sha.dma_initiator.RLAST" ) ).c_str(), esc_trace_fsdb );
			#if !BDW_RTL && !BDW_CC_SPEC
			esc_trace_signal( &sha0->config_ok_sig, ( std::string(name()) + std::string( ".sha.config_ok_sig" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->cmd_sig, ( std::string(name()) + std::string( ".sha.cmd_sig" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->status_sig, ( std::string(name()) + std::string( ".sha.status_sig" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &sha0->in_data_base_addr_sig, ( std::string(name()) + std::string( ".sha.in_data_base_addr_sig" ) ).c_str(), esc_trace_fsdb );
			#endif
		}
	}
#endif

