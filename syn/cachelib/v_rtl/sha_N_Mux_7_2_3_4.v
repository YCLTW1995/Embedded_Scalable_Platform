`timescale 1ps / 1ps
/*****************************************************************************
    Verilog RTL Description
    
    Generated at: 15:51:55 EST (-0500), Wednesday 04 March 2020
    Generated on: socp04
    Generated by: yl4337 ()
    
    Created by: Stratus DpOpt 2017.1.02 
    Copyright (c) 2014-2015 Cadence Design Systems. All rights reserved worldwide.
    
    Cadence Design Systems proprietary and confidential
    ===================================================
    
    May contain information that incorporates Cadence Design Systems CellMath
    and other inventions claimed in Pending U.S. Patents.
    
    May contain Cadence Design Systems Trade Secrets of which use, disclosure or
    reproduction is contractually restricted or prohibited.  For more
    information, contact your legal department before any use, disclosure or
    reproduction.
*******************************************************************************/

module sha_N_Mux_7_2_3_4 (
	in2,
	ctrl1,
	out1
	); /* architecture "behavioural" */ 
input [6:0] in2;
input  ctrl1;
output [6:0] out1;
wire [6:0] asc001;

reg [6:0] asc001_tmp_0;
assign asc001 = asc001_tmp_0;
always @ (ctrl1 or in2) begin
	case (ctrl1)
		1'B1 : asc001_tmp_0 = in2 ;
		default : asc001_tmp_0 = 7'B0000000 ;
	endcase
end

assign out1 = asc001;
endmodule

/* CADENCE  uLL0Qw8= : u9/ySgnYtBlWxVDRUQkU4ug= ** DO NOT EDIT THIS LINE ******/


