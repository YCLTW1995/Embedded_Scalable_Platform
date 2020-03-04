`timescale 1ps / 1ps
/*****************************************************************************
    Verilog RTL Description
    
    Generated at: 15:36:24 EST (-0500), Wednesday 04 March 2020
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

module sha_N_Mux_1_3_8_4 (
	ctrl1,
	out1
	); /* architecture "behavioural" */ 
input [31:0] ctrl1;
output  out1;
wire  asc001;

assign asc001 = 
	-{ctrl1 == 32'B00000000000000000000000000000001} & 1'B0 |
	-{ctrl1 == 32'B00000000000000000000000000000000} & 1'B0 |
	-{ctrl1[1] == 1'B1} & 1'B1 |
	-{ctrl1[2] == 1'B1} & 1'B1 |
	-{ctrl1[3] == 1'B1} & 1'B1 |
	-{ctrl1[4] == 1'B1} & 1'B1 |
	-{ctrl1[5] == 1'B1} & 1'B1 |
	-{ctrl1[6] == 1'B1} & 1'B1 |
	-{ctrl1[7] == 1'B1} & 1'B1 |
	-{ctrl1[8] == 1'B1} & 1'B1 |
	-{ctrl1[9] == 1'B1} & 1'B1 |
	-{ctrl1[10] == 1'B1} & 1'B1 |
	-{ctrl1[11] == 1'B1} & 1'B1 |
	-{ctrl1[12] == 1'B1} & 1'B1 |
	-{ctrl1[13] == 1'B1} & 1'B1 |
	-{ctrl1[14] == 1'B1} & 1'B1 |
	-{ctrl1[15] == 1'B1} & 1'B1 |
	-{ctrl1[16] == 1'B1} & 1'B1 |
	-{ctrl1[17] == 1'B1} & 1'B1 |
	-{ctrl1[18] == 1'B1} & 1'B1 |
	-{ctrl1[19] == 1'B1} & 1'B1 |
	-{ctrl1[20] == 1'B1} & 1'B1 |
	-{ctrl1[21] == 1'B1} & 1'B1 |
	-{ctrl1[22] == 1'B1} & 1'B1 |
	-{ctrl1[23] == 1'B1} & 1'B1 |
	-{ctrl1[24] == 1'B1} & 1'B1 |
	-{ctrl1[25] == 1'B1} & 1'B1 |
	-{ctrl1[26] == 1'B1} & 1'B1 |
	-{ctrl1[27] == 1'B1} & 1'B1 |
	-{ctrl1[28] == 1'B1} & 1'B1 |
	-{ctrl1[29] == 1'B1} & 1'B1 |
	-{ctrl1[30] == 1'B1} & 1'B1 |
	-{ctrl1[31] == 1'B1} & 1'B1 ;

assign out1 = asc001;
endmodule

/* CADENCE  urLyTwzf : u9/ySgnYtBlWxVDRUQkU4ug= ** DO NOT EDIT THIS LINE ******/


