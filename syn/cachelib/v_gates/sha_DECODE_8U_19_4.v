// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2018.2 (lin64) Build 2258646 Thu Jun 14 20:02:38 MDT 2018
// Date        : Wed Mar  4 15:52:36 2020
// Host        : socp04 running 64-bit CentOS Linux release 7.5.1804 (Core)
// Command     : write_verilog -cell inst_2 -force
//               /home/esp2020/yl4337/SHA/SystemC/Embedded_Scalable_Platform/syn/bdw_work/modules/sha/BASIC/v_gates/sha_DECODE_8U_19_4.v
// Design      : sha_DECODE_8U_19_4
// Purpose     : This is a Verilog netlist of the current design or from a specific cell of the design. The output is an
//               IEEE 1364-2001 compliant Verilog HDL file that contains netlist information obtained from the input
//               design files.
// Device      : xczu9eg-ffvb1156-2-e
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* STRUCTURAL_NETLIST = "yes" *)
module sha_DECODE_8U_19_4
   (in1,
    out1);
  input [2:0]in1;
  output [7:0]out1;

  wire [2:0]in1;
  wire [7:0]out1;

  (* SOFT_HLUTNM = "soft_lutpair2056" *) 
  LUT3 #(
    .INIT(8'h01)) 
    \out1[0]_INST_0 
       (.I0(in1[2]),
        .I1(in1[0]),
        .I2(in1[1]),
        .O(out1[0]));
  (* SOFT_HLUTNM = "soft_lutpair2057" *) 
  LUT3 #(
    .INIT(8'h04)) 
    \out1[1]_INST_0 
       (.I0(in1[2]),
        .I1(in1[0]),
        .I2(in1[1]),
        .O(out1[1]));
  (* SOFT_HLUTNM = "soft_lutpair2057" *) 
  LUT3 #(
    .INIT(8'h10)) 
    \out1[2]_INST_0 
       (.I0(in1[2]),
        .I1(in1[0]),
        .I2(in1[1]),
        .O(out1[2]));
  (* SOFT_HLUTNM = "soft_lutpair2056" *) 
  LUT3 #(
    .INIT(8'h40)) 
    \out1[3]_INST_0 
       (.I0(in1[2]),
        .I1(in1[0]),
        .I2(in1[1]),
        .O(out1[3]));
  (* SOFT_HLUTNM = "soft_lutpair2059" *) 
  LUT3 #(
    .INIT(8'h02)) 
    \out1[4]_INST_0 
       (.I0(in1[2]),
        .I1(in1[0]),
        .I2(in1[1]),
        .O(out1[4]));
  (* SOFT_HLUTNM = "soft_lutpair2059" *) 
  LUT3 #(
    .INIT(8'h08)) 
    \out1[5]_INST_0 
       (.I0(in1[2]),
        .I1(in1[0]),
        .I2(in1[1]),
        .O(out1[5]));
  (* SOFT_HLUTNM = "soft_lutpair2058" *) 
  LUT3 #(
    .INIT(8'h20)) 
    \out1[6]_INST_0 
       (.I0(in1[2]),
        .I1(in1[0]),
        .I2(in1[1]),
        .O(out1[6]));
  (* SOFT_HLUTNM = "soft_lutpair2058" *) 
  LUT3 #(
    .INIT(8'h80)) 
    \out1[7]_INST_0 
       (.I0(in1[2]),
        .I1(in1[0]),
        .I2(in1[1]),
        .O(out1[7]));
endmodule

