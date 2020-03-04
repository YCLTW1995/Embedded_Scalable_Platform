// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2018.2 (lin64) Build 2258646 Thu Jun 14 20:02:38 MDT 2018
// Date        : Wed Mar  4 15:36:25 2020
// Host        : socp04 running 64-bit CentOS Linux release 7.5.1804 (Core)
// Command     : write_verilog -cell inst_7 -force
//               /home/esp2020/yl4337/SHA/SystemC/Embedded_Scalable_Platform/syn/bdw_work/modules/sha/BASIC/v_gates/sha_OrReduction_32U_1U_4.v
// Design      : sha_OrReduction_32U_1U_4
// Purpose     : This is a Verilog netlist of the current design or from a specific cell of the design. The output is an
//               IEEE 1364-2001 compliant Verilog HDL file that contains netlist information obtained from the input
//               design files.
// Device      : xczu9eg-ffvb1156-2-e
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* STRUCTURAL_NETLIST = "yes" *)
module sha_OrReduction_32U_1U_4
   (in1,
    out1);
  input [31:0]in1;
  output out1;

  wire [31:0]in1;
  wire out1;
  wire out1_INST_0_i_1_n_0;
  wire out1_INST_0_i_2_n_0;
  wire out1_INST_0_i_3_n_0;
  wire out1_INST_0_i_4_n_0;
  wire out1_INST_0_i_5_n_0;
  wire out1_INST_0_i_6_n_0;

  LUT6 #(
    .INIT(64'hFFFFFFFFFFFFFFFE)) 
    out1_INST_0
       (.I0(out1_INST_0_i_1_n_0),
        .I1(out1_INST_0_i_2_n_0),
        .I2(out1_INST_0_i_3_n_0),
        .I3(out1_INST_0_i_4_n_0),
        .I4(out1_INST_0_i_5_n_0),
        .I5(out1_INST_0_i_6_n_0),
        .O(out1));
  LUT6 #(
    .INIT(64'hFFFFFFFFFFFFFFFE)) 
    out1_INST_0_i_1
       (.I0(in1[12]),
        .I1(in1[13]),
        .I2(in1[10]),
        .I3(in1[11]),
        .I4(in1[9]),
        .I5(in1[8]),
        .O(out1_INST_0_i_1_n_0));
  LUT6 #(
    .INIT(64'hFFFFFFFFFFFFFFFE)) 
    out1_INST_0_i_2
       (.I0(in1[18]),
        .I1(in1[19]),
        .I2(in1[16]),
        .I3(in1[17]),
        .I4(in1[15]),
        .I5(in1[14]),
        .O(out1_INST_0_i_2_n_0));
  LUT6 #(
    .INIT(64'hFFFFFFFFFFFFFFFE)) 
    out1_INST_0_i_3
       (.I0(in1[30]),
        .I1(in1[31]),
        .I2(in1[28]),
        .I3(in1[29]),
        .I4(in1[27]),
        .I5(in1[26]),
        .O(out1_INST_0_i_3_n_0));
  LUT6 #(
    .INIT(64'hFFFFFFFFFFFFFFFE)) 
    out1_INST_0_i_4
       (.I0(in1[24]),
        .I1(in1[25]),
        .I2(in1[22]),
        .I3(in1[23]),
        .I4(in1[21]),
        .I5(in1[20]),
        .O(out1_INST_0_i_4_n_0));
  LUT2 #(
    .INIT(4'hE)) 
    out1_INST_0_i_5
       (.I0(in1[0]),
        .I1(in1[1]),
        .O(out1_INST_0_i_5_n_0));
  LUT6 #(
    .INIT(64'hFFFFFFFFFFFFFFFE)) 
    out1_INST_0_i_6
       (.I0(in1[6]),
        .I1(in1[7]),
        .I2(in1[4]),
        .I3(in1[5]),
        .I4(in1[3]),
        .I5(in1[2]),
        .O(out1_INST_0_i_6_n_0));
endmodule

