// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2018.2 (lin64) Build 2258646 Thu Jun 14 20:02:38 MDT 2018
// Date        : Wed Mar  4 15:51:54 2020
// Host        : socp04 running 64-bit CentOS Linux release 7.5.1804 (Core)
// Command     : write_verilog -cell inst_1 -force
//               /home/esp2020/yl4337/SHA/SystemC/Embedded_Scalable_Platform/syn/bdw_work/modules/sha/BASIC/v_gates/sha_N_Mux_7_2_3_4.v
// Design      : sha_N_Mux_7_2_3_4
// Purpose     : This is a Verilog netlist of the current design or from a specific cell of the design. The output is an
//               IEEE 1364-2001 compliant Verilog HDL file that contains netlist information obtained from the input
//               design files.
// Device      : xczu9eg-ffvb1156-2-e
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* STRUCTURAL_NETLIST = "yes" *)
module sha_N_Mux_7_2_3_4
   (in2,
    ctrl1,
    out1);
  input [6:0]in2;
  input ctrl1;
  output [6:0]out1;

  wire ctrl1;
  wire [6:0]in2;
  wire [6:0]out1;

  (* SOFT_HLUTNM = "soft_lutpair2" *) 
  LUT2 #(
    .INIT(4'h8)) 
    \out1[0]_INST_0 
       (.I0(ctrl1),
        .I1(in2[0]),
        .O(out1[0]));
  (* SOFT_HLUTNM = "soft_lutpair2" *) 
  LUT2 #(
    .INIT(4'h8)) 
    \out1[1]_INST_0 
       (.I0(ctrl1),
        .I1(in2[1]),
        .O(out1[1]));
  (* SOFT_HLUTNM = "soft_lutpair3" *) 
  LUT2 #(
    .INIT(4'h8)) 
    \out1[2]_INST_0 
       (.I0(ctrl1),
        .I1(in2[2]),
        .O(out1[2]));
  (* SOFT_HLUTNM = "soft_lutpair3" *) 
  LUT2 #(
    .INIT(4'h8)) 
    \out1[3]_INST_0 
       (.I0(ctrl1),
        .I1(in2[3]),
        .O(out1[3]));
  (* SOFT_HLUTNM = "soft_lutpair4" *) 
  LUT2 #(
    .INIT(4'h8)) 
    \out1[4]_INST_0 
       (.I0(ctrl1),
        .I1(in2[4]),
        .O(out1[4]));
  (* SOFT_HLUTNM = "soft_lutpair4" *) 
  LUT2 #(
    .INIT(4'h8)) 
    \out1[5]_INST_0 
       (.I0(ctrl1),
        .I1(in2[5]),
        .O(out1[5]));
  LUT2 #(
    .INIT(4'h8)) 
    \out1[6]_INST_0 
       (.I0(ctrl1),
        .I1(in2[6]),
        .O(out1[6]));
endmodule

