`timescale 1ps / 1ps
/*****************************************************************************
    Verilog RTL Description
    
    Generated at: 15:36:49 EST (-0500), Wednesday 04 March 2020
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

module sha_OrReduction_28U_1U_4 (
	in1,
	out1
	); /* architecture "behavioural" */ 
input [27:0] in1;
output  out1;
wire  asc001;

assign asc001 = 
	(|in1);

assign out1 = asc001;
endmodule

/* CADENCE  urXwQgs= : u9/ySgnYtBlWxVDRUQkU4ug= ** DO NOT EDIT THIS LINE ******/


