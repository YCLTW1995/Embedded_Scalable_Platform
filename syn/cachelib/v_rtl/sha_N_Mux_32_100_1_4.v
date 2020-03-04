`timescale 1ps / 1ps
/*****************************************************************************
    Verilog RTL Description
    
    Generated at: 15:36:42 EST (-0500), Wednesday 04 March 2020
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

module sha_N_Mux_32_100_1_4 (
	in101,
	in100,
	in99,
	in98,
	in97,
	in96,
	in95,
	in94,
	in93,
	in92,
	in91,
	in90,
	in89,
	in88,
	in87,
	in86,
	in85,
	in84,
	in83,
	in82,
	in81,
	in80,
	in79,
	in78,
	in77,
	in76,
	in75,
	in74,
	in73,
	in72,
	in71,
	in70,
	in69,
	in68,
	in67,
	in66,
	in65,
	in64,
	in63,
	in62,
	in61,
	in60,
	in59,
	in58,
	in57,
	in56,
	in55,
	in54,
	in53,
	in52,
	in51,
	in50,
	in49,
	in48,
	in47,
	in46,
	in45,
	in44,
	in43,
	in42,
	in41,
	in40,
	in39,
	in38,
	in37,
	in36,
	in35,
	in34,
	in33,
	in32,
	in31,
	in30,
	in29,
	in28,
	in27,
	in26,
	in25,
	in24,
	in23,
	in22,
	in21,
	in20,
	in19,
	in18,
	in17,
	in16,
	in15,
	in14,
	in13,
	in12,
	in11,
	in10,
	in9,
	in8,
	in7,
	in6,
	in5,
	in4,
	in3,
	in2,
	ctrl1,
	out1
	); /* architecture "behavioural" */ 
input [31:0] in101,
	in100,
	in99,
	in98,
	in97,
	in96,
	in95,
	in94,
	in93,
	in92,
	in91,
	in90,
	in89,
	in88,
	in87,
	in86,
	in85,
	in84,
	in83,
	in82,
	in81,
	in80,
	in79,
	in78,
	in77,
	in76,
	in75,
	in74,
	in73,
	in72,
	in71,
	in70,
	in69,
	in68,
	in67,
	in66,
	in65,
	in64,
	in63,
	in62,
	in61,
	in60,
	in59,
	in58,
	in57,
	in56,
	in55,
	in54,
	in53,
	in52,
	in51,
	in50,
	in49,
	in48,
	in47,
	in46,
	in45,
	in44,
	in43,
	in42,
	in41,
	in40,
	in39,
	in38,
	in37,
	in36,
	in35,
	in34,
	in33,
	in32,
	in31,
	in30,
	in29,
	in28,
	in27,
	in26,
	in25,
	in24,
	in23,
	in22,
	in21,
	in20,
	in19,
	in18,
	in17,
	in16,
	in15,
	in14,
	in13,
	in12,
	in11,
	in10,
	in9,
	in8,
	in7,
	in6,
	in5,
	in4,
	in3,
	in2;
input [6:0] ctrl1;
output [31:0] out1;
wire [31:0] asc001;

reg [31:0] asc001_tmp_0;
assign asc001 = asc001_tmp_0;
always @ (ctrl1 or in100 or in99 or in98 or in97 or in96 or in95 or in94 or in93 or in92 or in91 or in90
    or in89 or in88 or in87 or in86 or in85 or in84 or in83 or in82 or in81 or in80 or in79 or in78 or in77
    or in76 or in75 or in74 or in73 or in72 or in71 or in70 or in69 or in68 or in67 or in66 or in65 or in64
    or in63 or in62 or in61 or in60 or in59 or in58 or in57 or in56 or in55 or in54 or in53 or in52 or in51
    or in50 or in49 or in48 or in47 or in46 or in45 or in44 or in43 or in42 or in41 or in40 or in39 or in38
    or in37 or in36 or in35 or in34 or in33 or in32 or in31 or in30 or in29 or in28 or in27 or in26 or in25
    or in24 or in23 or in22 or in21 or in20 or in19 or in18 or in17 or in16 or in15 or in14 or in13 or in12
    or in11 or in10 or in9 or in8 or in7 or in6 or in5 or in4 or in3 or in2 or in101) begin
	case (ctrl1)
		7'B1100010 : asc001_tmp_0 = in100 ;
		7'B1100001 : asc001_tmp_0 = in99 ;
		7'B1100000 : asc001_tmp_0 = in98 ;
		7'B1011111 : asc001_tmp_0 = in97 ;
		7'B1011110 : asc001_tmp_0 = in96 ;
		7'B1011101 : asc001_tmp_0 = in95 ;
		7'B1011100 : asc001_tmp_0 = in94 ;
		7'B1011011 : asc001_tmp_0 = in93 ;
		7'B1011010 : asc001_tmp_0 = in92 ;
		7'B1011001 : asc001_tmp_0 = in91 ;
		7'B1011000 : asc001_tmp_0 = in90 ;
		7'B1010111 : asc001_tmp_0 = in89 ;
		7'B1010110 : asc001_tmp_0 = in88 ;
		7'B1010101 : asc001_tmp_0 = in87 ;
		7'B1010100 : asc001_tmp_0 = in86 ;
		7'B1010011 : asc001_tmp_0 = in85 ;
		7'B1010010 : asc001_tmp_0 = in84 ;
		7'B1010001 : asc001_tmp_0 = in83 ;
		7'B1010000 : asc001_tmp_0 = in82 ;
		7'B1001111 : asc001_tmp_0 = in81 ;
		7'B1001110 : asc001_tmp_0 = in80 ;
		7'B1001101 : asc001_tmp_0 = in79 ;
		7'B1001100 : asc001_tmp_0 = in78 ;
		7'B1001011 : asc001_tmp_0 = in77 ;
		7'B1001010 : asc001_tmp_0 = in76 ;
		7'B1001001 : asc001_tmp_0 = in75 ;
		7'B1001000 : asc001_tmp_0 = in74 ;
		7'B1000111 : asc001_tmp_0 = in73 ;
		7'B1000110 : asc001_tmp_0 = in72 ;
		7'B1000101 : asc001_tmp_0 = in71 ;
		7'B1000100 : asc001_tmp_0 = in70 ;
		7'B1000011 : asc001_tmp_0 = in69 ;
		7'B1000010 : asc001_tmp_0 = in68 ;
		7'B1000001 : asc001_tmp_0 = in67 ;
		7'B1000000 : asc001_tmp_0 = in66 ;
		7'B0111111 : asc001_tmp_0 = in65 ;
		7'B0111110 : asc001_tmp_0 = in64 ;
		7'B0111101 : asc001_tmp_0 = in63 ;
		7'B0111100 : asc001_tmp_0 = in62 ;
		7'B0111011 : asc001_tmp_0 = in61 ;
		7'B0111010 : asc001_tmp_0 = in60 ;
		7'B0111001 : asc001_tmp_0 = in59 ;
		7'B0111000 : asc001_tmp_0 = in58 ;
		7'B0110111 : asc001_tmp_0 = in57 ;
		7'B0110110 : asc001_tmp_0 = in56 ;
		7'B0110101 : asc001_tmp_0 = in55 ;
		7'B0110100 : asc001_tmp_0 = in54 ;
		7'B0110011 : asc001_tmp_0 = in53 ;
		7'B0110010 : asc001_tmp_0 = in52 ;
		7'B0110001 : asc001_tmp_0 = in51 ;
		7'B0110000 : asc001_tmp_0 = in50 ;
		7'B0101111 : asc001_tmp_0 = in49 ;
		7'B0101110 : asc001_tmp_0 = in48 ;
		7'B0101101 : asc001_tmp_0 = in47 ;
		7'B0101100 : asc001_tmp_0 = in46 ;
		7'B0101011 : asc001_tmp_0 = in45 ;
		7'B0101010 : asc001_tmp_0 = in44 ;
		7'B0101001 : asc001_tmp_0 = in43 ;
		7'B0101000 : asc001_tmp_0 = in42 ;
		7'B0100111 : asc001_tmp_0 = in41 ;
		7'B0100110 : asc001_tmp_0 = in40 ;
		7'B0100101 : asc001_tmp_0 = in39 ;
		7'B0100100 : asc001_tmp_0 = in38 ;
		7'B0100011 : asc001_tmp_0 = in37 ;
		7'B0100010 : asc001_tmp_0 = in36 ;
		7'B0100001 : asc001_tmp_0 = in35 ;
		7'B0100000 : asc001_tmp_0 = in34 ;
		7'B0011111 : asc001_tmp_0 = in33 ;
		7'B0011110 : asc001_tmp_0 = in32 ;
		7'B0011101 : asc001_tmp_0 = in31 ;
		7'B0011100 : asc001_tmp_0 = in30 ;
		7'B0011011 : asc001_tmp_0 = in29 ;
		7'B0011010 : asc001_tmp_0 = in28 ;
		7'B0011001 : asc001_tmp_0 = in27 ;
		7'B0011000 : asc001_tmp_0 = in26 ;
		7'B0010111 : asc001_tmp_0 = in25 ;
		7'B0010110 : asc001_tmp_0 = in24 ;
		7'B0010101 : asc001_tmp_0 = in23 ;
		7'B0010100 : asc001_tmp_0 = in22 ;
		7'B0010011 : asc001_tmp_0 = in21 ;
		7'B0010010 : asc001_tmp_0 = in20 ;
		7'B0010001 : asc001_tmp_0 = in19 ;
		7'B0010000 : asc001_tmp_0 = in18 ;
		7'B0001111 : asc001_tmp_0 = in17 ;
		7'B0001110 : asc001_tmp_0 = in16 ;
		7'B0001101 : asc001_tmp_0 = in15 ;
		7'B0001100 : asc001_tmp_0 = in14 ;
		7'B0001011 : asc001_tmp_0 = in13 ;
		7'B0001010 : asc001_tmp_0 = in12 ;
		7'B0001001 : asc001_tmp_0 = in11 ;
		7'B0001000 : asc001_tmp_0 = in10 ;
		7'B0000111 : asc001_tmp_0 = in9 ;
		7'B0000110 : asc001_tmp_0 = in8 ;
		7'B0000101 : asc001_tmp_0 = in7 ;
		7'B0000100 : asc001_tmp_0 = in6 ;
		7'B0000011 : asc001_tmp_0 = in5 ;
		7'B0000010 : asc001_tmp_0 = in4 ;
		7'B0000001 : asc001_tmp_0 = in3 ;
		7'B0000000 : asc001_tmp_0 = in2 ;
		default : asc001_tmp_0 = in101 ;
	endcase
end

assign out1 = asc001;
endmodule

/* CADENCE  vrj3TAHW : u9/ySgnYtBlWxVDRUQkU4ug= ** DO NOT EDIT THIS LINE ******/


