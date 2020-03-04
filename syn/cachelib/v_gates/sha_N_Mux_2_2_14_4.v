// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2018.2 (lin64) Build 2258646 Thu Jun 14 20:02:38 MDT 2018
// Date        : Wed Mar  4 15:36:20 2020
// Host        : socp04 running 64-bit CentOS Linux release 7.5.1804 (Core)
// Command     : write_verilog -cell inst_0 -force
//               /home/esp2020/yl4337/SHA/SystemC/Embedded_Scalable_Platform/syn/bdw_work/modules/sha/BASIC/v_gates/sha_N_Mux_2_2_14_4.v
// Design      : sha_N_Mux_2_2_14_4
// Purpose     : This is a Verilog netlist of the current design or from a specific cell of the design. The output is an
//               IEEE 1364-2001 compliant Verilog HDL file that contains netlist information obtained from the input
//               design files.
// Device      : xczu9eg-ffvb1156-2-e
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* STRUCTURAL_NETLIST = "yes" *)
module sha_N_Mux_2_2_14_4
   (in3,
    in2,
    ctrl1,
    out1);
  input [1:0]in3;
  input [1:0]in2;
  input ctrl1;
  output [1:0]out1;

  wire ctrl1;
  wire [1:0]in2;
  wire [1:0]in3;
  wire [1:0]out1;

  (* SOFT_HLUTNM = "soft_lutpair0" *) 
  LUT3 #(
    .INIT(8'hB8)) 
    \out1[0]_INST_0 
       (.I0(in2[0]),
        .I1(ctrl1),
        .I2(in3[0]),
        .O(out1[0]));
  (* SOFT_HLUTNM = "soft_lutpair0" *) 
  LUT3 #(
    .INIT(8'hD8)) 
    \out1[1]_INST_0 
       (.I0(ctrl1),
        .I1(in2[1]),
        .I2(in3[1]),
        .O(out1[1]));
endmodule

