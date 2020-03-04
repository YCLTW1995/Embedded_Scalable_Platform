// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2018.2 (lin64) Build 2258646 Thu Jun 14 20:02:38 MDT 2018
// Date        : Wed Mar  4 15:36:27 2020
// Host        : socp04 running 64-bit CentOS Linux release 7.5.1804 (Core)
// Command     : write_verilog -cell inst_9 -force
//               /home/esp2020/yl4337/SHA/SystemC/Embedded_Scalable_Platform/syn/bdw_work/modules/sha/BASIC/v_gates/sha_NotEQ_32Ux3U_1U_4.v
// Design      : sha_NotEQ_32Ux3U_1U_4
// Purpose     : This is a Verilog netlist of the current design or from a specific cell of the design. The output is an
//               IEEE 1364-2001 compliant Verilog HDL file that contains netlist information obtained from the input
//               design files.
// Device      : xczu9eg-ffvb1156-2-e
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* STRUCTURAL_NETLIST = "yes" *)
module sha_NotEQ_32Ux3U_1U_4
   (in2,
    in1,
    out1);
  input [31:0]in2;
  input [2:0]in1;
  output out1;

  wire \<const0> ;
  wire \<const1> ;
  wire GND_2;
  wire [2:0]in1;
  wire [31:0]in2;
  wire out1;
  wire out1_INST_0_i_10_n_0;
  wire out1_INST_0_i_11_n_0;
  wire out1_INST_0_i_12_n_0;
  wire out1_INST_0_i_1_n_0;
  wire out1_INST_0_i_1_n_1;
  wire out1_INST_0_i_1_n_2;
  wire out1_INST_0_i_1_n_3;
  wire out1_INST_0_i_1_n_5;
  wire out1_INST_0_i_1_n_6;
  wire out1_INST_0_i_1_n_7;
  wire out1_INST_0_i_2_n_0;
  wire out1_INST_0_i_3_n_0;
  wire out1_INST_0_i_4_n_0;
  wire out1_INST_0_i_5_n_0;
  wire out1_INST_0_i_6_n_0;
  wire out1_INST_0_i_7_n_0;
  wire out1_INST_0_i_8_n_0;
  wire out1_INST_0_i_9_n_0;
  wire out1_INST_0_n_6;
  wire out1_INST_0_n_7;
  wire [7:0]NLW_out1_INST_0_i_1_CO_UNCONNECTED;

  GND GND
       (.G(\<const0> ));
  GND GND_1
       (.G(GND_2));
  VCC VCC
       (.P(\<const1> ));
  CARRY8 out1_INST_0
       (.CI(out1_INST_0_i_1_n_0),
        .CI_TOP(GND_2),
        .CO({out1,out1_INST_0_n_6,out1_INST_0_n_7}),
        .DI({\<const0> ,\<const0> ,\<const0> ,\<const0> ,\<const0> ,\<const1> ,\<const1> ,\<const1> }),
        .S({\<const0> ,\<const0> ,\<const0> ,\<const0> ,\<const0> ,out1_INST_0_i_2_n_0,out1_INST_0_i_3_n_0,out1_INST_0_i_4_n_0}));
  CARRY8 out1_INST_0_i_1
       (.CI(\<const0> ),
        .CI_TOP(GND_2),
        .CO({out1_INST_0_i_1_n_0,out1_INST_0_i_1_n_1,out1_INST_0_i_1_n_2,out1_INST_0_i_1_n_3,NLW_out1_INST_0_i_1_CO_UNCONNECTED[3],out1_INST_0_i_1_n_5,out1_INST_0_i_1_n_6,out1_INST_0_i_1_n_7}),
        .DI({\<const1> ,\<const1> ,\<const1> ,\<const1> ,\<const1> ,\<const1> ,\<const1> ,\<const1> }),
        .S({out1_INST_0_i_5_n_0,out1_INST_0_i_6_n_0,out1_INST_0_i_7_n_0,out1_INST_0_i_8_n_0,out1_INST_0_i_9_n_0,out1_INST_0_i_10_n_0,out1_INST_0_i_11_n_0,out1_INST_0_i_12_n_0}));
  LUT3 #(
    .INIT(8'h01)) 
    out1_INST_0_i_10
       (.I0(in2[8]),
        .I1(in2[7]),
        .I2(in2[6]),
        .O(out1_INST_0_i_10_n_0));
  LUT3 #(
    .INIT(8'h01)) 
    out1_INST_0_i_11
       (.I0(in2[5]),
        .I1(in2[4]),
        .I2(in2[3]),
        .O(out1_INST_0_i_11_n_0));
  LUT6 #(
    .INIT(64'h9009000000009009)) 
    out1_INST_0_i_12
       (.I0(in1[0]),
        .I1(in2[0]),
        .I2(in2[2]),
        .I3(in1[2]),
        .I4(in2[1]),
        .I5(in1[1]),
        .O(out1_INST_0_i_12_n_0));
  LUT2 #(
    .INIT(4'h1)) 
    out1_INST_0_i_2
       (.I0(in2[30]),
        .I1(in2[31]),
        .O(out1_INST_0_i_2_n_0));
  LUT3 #(
    .INIT(8'h01)) 
    out1_INST_0_i_3
       (.I0(in2[29]),
        .I1(in2[28]),
        .I2(in2[27]),
        .O(out1_INST_0_i_3_n_0));
  LUT3 #(
    .INIT(8'h01)) 
    out1_INST_0_i_4
       (.I0(in2[26]),
        .I1(in2[25]),
        .I2(in2[24]),
        .O(out1_INST_0_i_4_n_0));
  LUT3 #(
    .INIT(8'h01)) 
    out1_INST_0_i_5
       (.I0(in2[23]),
        .I1(in2[22]),
        .I2(in2[21]),
        .O(out1_INST_0_i_5_n_0));
  LUT3 #(
    .INIT(8'h01)) 
    out1_INST_0_i_6
       (.I0(in2[20]),
        .I1(in2[19]),
        .I2(in2[18]),
        .O(out1_INST_0_i_6_n_0));
  LUT3 #(
    .INIT(8'h01)) 
    out1_INST_0_i_7
       (.I0(in2[17]),
        .I1(in2[16]),
        .I2(in2[15]),
        .O(out1_INST_0_i_7_n_0));
  LUT3 #(
    .INIT(8'h01)) 
    out1_INST_0_i_8
       (.I0(in2[14]),
        .I1(in2[13]),
        .I2(in2[12]),
        .O(out1_INST_0_i_8_n_0));
  LUT3 #(
    .INIT(8'h01)) 
    out1_INST_0_i_9
       (.I0(in2[11]),
        .I1(in2[10]),
        .I2(in2[9]),
        .O(out1_INST_0_i_9_n_0));
endmodule

