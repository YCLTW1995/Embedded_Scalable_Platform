// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2018.2 (lin64) Build 2258646 Thu Jun 14 20:02:38 MDT 2018
// Date        : Wed Mar  4 15:36:24 2020
// Host        : socp04 running 64-bit CentOS Linux release 7.5.1804 (Core)
// Command     : write_verilog -cell inst_6 -force
//               /home/esp2020/yl4337/SHA/SystemC/Embedded_Scalable_Platform/syn/bdw_work/modules/sha/BASIC/v_gates/sha_N_Mux_1_3_8_4.v
// Design      : sha_N_Mux_1_3_8_4
// Purpose     : This is a Verilog netlist of the current design or from a specific cell of the design. The output is an
//               IEEE 1364-2001 compliant Verilog HDL file that contains netlist information obtained from the input
//               design files.
// Device      : xczu9eg-ffvb1156-2-e
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* STRUCTURAL_NETLIST = "yes" *)
module sha_N_Mux_1_3_8_4
   (ctrl1,
    out1);
  input [31:0]ctrl1;
  output out1;

  wire [31:0]ctrl1;
  wire out1;
  wire out1_INST_0_i_1_n_0;
  wire out1_INST_0_i_2_n_0;
  wire out1_INST_0_i_3_n_0;
  wire out1_INST_0_i_4_n_0;
  wire out1_INST_0_i_5_n_0;

  LUT6 #(
    .INIT(64'hFFFFFFFFFFFFFFFE)) 
    out1_INST_0
       (.I0(out1_INST_0_i_1_n_0),
        .I1(ctrl1[1]),
        .I2(out1_INST_0_i_2_n_0),
        .I3(out1_INST_0_i_3_n_0),
        .I4(out1_INST_0_i_4_n_0),
        .I5(out1_INST_0_i_5_n_0),
        .O(out1));
  LUT6 #(
    .INIT(64'hFFFFFFFFFFFFFFFE)) 
    out1_INST_0_i_1
       (.I0(ctrl1[3]),
        .I1(ctrl1[2]),
        .I2(ctrl1[5]),
        .I3(ctrl1[4]),
        .I4(ctrl1[6]),
        .I5(ctrl1[7]),
        .O(out1_INST_0_i_1_n_0));
  LUT6 #(
    .INIT(64'hFFFFFFFFFFFFFFFE)) 
    out1_INST_0_i_2
       (.I0(ctrl1[15]),
        .I1(ctrl1[14]),
        .I2(ctrl1[17]),
        .I3(ctrl1[16]),
        .I4(ctrl1[18]),
        .I5(ctrl1[19]),
        .O(out1_INST_0_i_2_n_0));
  LUT6 #(
    .INIT(64'hFFFFFFFFFFFFFFFE)) 
    out1_INST_0_i_3
       (.I0(ctrl1[9]),
        .I1(ctrl1[8]),
        .I2(ctrl1[11]),
        .I3(ctrl1[10]),
        .I4(ctrl1[12]),
        .I5(ctrl1[13]),
        .O(out1_INST_0_i_3_n_0));
  LUT6 #(
    .INIT(64'hFFFFFFFFFFFFFFFE)) 
    out1_INST_0_i_4
       (.I0(ctrl1[21]),
        .I1(ctrl1[20]),
        .I2(ctrl1[23]),
        .I3(ctrl1[22]),
        .I4(ctrl1[24]),
        .I5(ctrl1[25]),
        .O(out1_INST_0_i_4_n_0));
  LUT6 #(
    .INIT(64'hFFFFFFFFFFFFFFFE)) 
    out1_INST_0_i_5
       (.I0(ctrl1[27]),
        .I1(ctrl1[26]),
        .I2(ctrl1[29]),
        .I3(ctrl1[28]),
        .I4(ctrl1[30]),
        .I5(ctrl1[31]),
        .O(out1_INST_0_i_5_n_0));
endmodule

