// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2018.2 (lin64) Build 2258646 Thu Jun 14 20:02:38 MDT 2018
// Date        : Wed Mar  4 15:36:33 2020
// Host        : socp04 running 64-bit CentOS Linux release 7.5.1804 (Core)
// Command     : write_verilog -cell inst_19 -force
//               /home/esp2020/yl4337/SHA/SystemC/Embedded_Scalable_Platform/syn/bdw_work/modules/sha/BASIC/v_gates/sha_OrReduction_7U_1U_4.v
// Design      : sha_OrReduction_7U_1U_4
// Purpose     : This is a Verilog netlist of the current design or from a specific cell of the design. The output is an
//               IEEE 1364-2001 compliant Verilog HDL file that contains netlist information obtained from the input
//               design files.
// Device      : xczu9eg-ffvb1156-2-e
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* STRUCTURAL_NETLIST = "yes" *)
module sha_OrReduction_7U_1U_4
   (in1,
    out1);
  input [6:0]in1;
  output out1;

  wire [6:0]in1;
  wire out1;
  wire out1_INST_0_i_1_n_0;

  LUT4 #(
    .INIT(16'hFFFE)) 
    out1_INST_0
       (.I0(in1[1]),
        .I1(in1[2]),
        .I2(in1[0]),
        .I3(out1_INST_0_i_1_n_0),
        .O(out1));
  LUT4 #(
    .INIT(16'hFFFE)) 
    out1_INST_0_i_1
       (.I0(in1[4]),
        .I1(in1[3]),
        .I2(in1[6]),
        .I3(in1[5]),
        .O(out1_INST_0_i_1_n_0));
endmodule
