// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2018.2 (lin64) Build 2258646 Thu Jun 14 20:02:38 MDT 2018
// Date        : Wed Mar  4 15:36:38 2020
// Host        : socp04 running 64-bit CentOS Linux release 7.5.1804 (Core)
// Command     : write_verilog -cell inst_29 -force
//               /home/esp2020/yl4337/SHA/SystemC/Embedded_Scalable_Platform/syn/bdw_work/modules/sha/BASIC/v_gates/sha_LessThan_7Ux7U_1U_4.v
// Design      : sha_LessThan_7Ux7U_1U_4
// Purpose     : This is a Verilog netlist of the current design or from a specific cell of the design. The output is an
//               IEEE 1364-2001 compliant Verilog HDL file that contains netlist information obtained from the input
//               design files.
// Device      : xczu9eg-ffvb1156-2-e
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* STRUCTURAL_NETLIST = "yes" *)
module sha_LessThan_7Ux7U_1U_4
   (in2,
    in1,
    out1);
  input [6:0]in2;
  input [6:0]in1;
  output out1;

  wire \<const0> ;
  wire GND_2;
  wire [6:0]in1;
  wire [6:0]in2;
  wire out1;
  wire out1_INST_0_i_1_n_0;
  wire out1_INST_0_i_2_n_0;
  wire out1_INST_0_i_3_n_0;
  wire out1_INST_0_i_4_n_0;
  wire out1_INST_0_i_5_n_0;
  wire out1_INST_0_i_6_n_0;
  wire out1_INST_0_i_7_n_0;
  wire out1_INST_0_i_8_n_0;
  wire out1_INST_0_n_5;
  wire out1_INST_0_n_6;
  wire out1_INST_0_n_7;

  GND GND
       (.G(\<const0> ));
  GND GND_1
       (.G(GND_2));
  CARRY8 out1_INST_0
       (.CI(\<const0> ),
        .CI_TOP(GND_2),
        .CO({out1,out1_INST_0_n_5,out1_INST_0_n_6,out1_INST_0_n_7}),
        .DI({\<const0> ,\<const0> ,\<const0> ,\<const0> ,out1_INST_0_i_1_n_0,out1_INST_0_i_2_n_0,out1_INST_0_i_3_n_0,out1_INST_0_i_4_n_0}),
        .S({\<const0> ,\<const0> ,\<const0> ,\<const0> ,out1_INST_0_i_5_n_0,out1_INST_0_i_6_n_0,out1_INST_0_i_7_n_0,out1_INST_0_i_8_n_0}));
  LUT2 #(
    .INIT(4'h2)) 
    out1_INST_0_i_1
       (.I0(in1[6]),
        .I1(in2[6]),
        .O(out1_INST_0_i_1_n_0));
  LUT4 #(
    .INIT(16'h2F02)) 
    out1_INST_0_i_2
       (.I0(in1[4]),
        .I1(in2[4]),
        .I2(in2[5]),
        .I3(in1[5]),
        .O(out1_INST_0_i_2_n_0));
  LUT4 #(
    .INIT(16'h2F02)) 
    out1_INST_0_i_3
       (.I0(in1[2]),
        .I1(in2[2]),
        .I2(in2[3]),
        .I3(in1[3]),
        .O(out1_INST_0_i_3_n_0));
  LUT4 #(
    .INIT(16'h2F02)) 
    out1_INST_0_i_4
       (.I0(in1[0]),
        .I1(in2[0]),
        .I2(in2[1]),
        .I3(in1[1]),
        .O(out1_INST_0_i_4_n_0));
  LUT2 #(
    .INIT(4'h9)) 
    out1_INST_0_i_5
       (.I0(in2[6]),
        .I1(in1[6]),
        .O(out1_INST_0_i_5_n_0));
  LUT4 #(
    .INIT(16'h9009)) 
    out1_INST_0_i_6
       (.I0(in1[4]),
        .I1(in2[4]),
        .I2(in1[5]),
        .I3(in2[5]),
        .O(out1_INST_0_i_6_n_0));
  LUT4 #(
    .INIT(16'h9009)) 
    out1_INST_0_i_7
       (.I0(in1[2]),
        .I1(in2[2]),
        .I2(in1[3]),
        .I3(in2[3]),
        .O(out1_INST_0_i_7_n_0));
  LUT4 #(
    .INIT(16'h9009)) 
    out1_INST_0_i_8
       (.I0(in1[0]),
        .I1(in2[0]),
        .I2(in1[1]),
        .I3(in2[1]),
        .O(out1_INST_0_i_8_n_0));
endmodule

