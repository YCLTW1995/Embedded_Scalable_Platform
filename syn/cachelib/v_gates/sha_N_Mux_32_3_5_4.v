// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2018.2 (lin64) Build 2258646 Thu Jun 14 20:02:38 MDT 2018
// Date        : Wed Mar  4 15:36:29 2020
// Host        : socp04 running 64-bit CentOS Linux release 7.5.1804 (Core)
// Command     : write_verilog -cell inst_12 -force
//               /home/esp2020/yl4337/SHA/SystemC/Embedded_Scalable_Platform/syn/bdw_work/modules/sha/BASIC/v_gates/sha_N_Mux_32_3_5_4.v
// Design      : sha_N_Mux_32_3_5_4
// Purpose     : This is a Verilog netlist of the current design or from a specific cell of the design. The output is an
//               IEEE 1364-2001 compliant Verilog HDL file that contains netlist information obtained from the input
//               design files.
// Device      : xczu9eg-ffvb1156-2-e
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* STRUCTURAL_NETLIST = "yes" *)
module sha_N_Mux_32_3_5_4
   (in3,
    in2,
    ctrl1,
    out1);
  input [31:0]in3;
  input [31:0]in2;
  input [31:0]ctrl1;
  output [31:0]out1;

  wire [31:0]ctrl1;
  wire [31:0]in2;
  wire [31:0]in3;
  wire [31:0]out1;
  wire \out1[31]_INST_0_i_1_n_0 ;
  wire \out1[31]_INST_0_i_2_n_0 ;
  wire \out1[31]_INST_0_i_3_n_0 ;
  wire \out1[31]_INST_0_i_4_n_0 ;
  wire \out1[31]_INST_0_i_5_n_0 ;
  wire \out1[31]_INST_0_i_6_n_0 ;
  wire \out1[31]_INST_0_i_7_n_0 ;
  wire \out1[31]_INST_0_i_8_n_0 ;

  LUT6 #(
    .INIT(64'hA0000000C0000000)) 
    \out1[0]_INST_0 
       (.I0(in3[0]),
        .I1(in2[0]),
        .I2(\out1[31]_INST_0_i_1_n_0 ),
        .I3(\out1[31]_INST_0_i_2_n_0 ),
        .I4(\out1[31]_INST_0_i_3_n_0 ),
        .I5(ctrl1[2]),
        .O(out1[0]));
  LUT6 #(
    .INIT(64'hA0000000C0000000)) 
    \out1[10]_INST_0 
       (.I0(in3[10]),
        .I1(in2[10]),
        .I2(\out1[31]_INST_0_i_1_n_0 ),
        .I3(\out1[31]_INST_0_i_2_n_0 ),
        .I4(\out1[31]_INST_0_i_3_n_0 ),
        .I5(ctrl1[2]),
        .O(out1[10]));
  LUT6 #(
    .INIT(64'hA0000000C0000000)) 
    \out1[11]_INST_0 
       (.I0(in3[11]),
        .I1(in2[11]),
        .I2(\out1[31]_INST_0_i_1_n_0 ),
        .I3(\out1[31]_INST_0_i_2_n_0 ),
        .I4(\out1[31]_INST_0_i_3_n_0 ),
        .I5(ctrl1[2]),
        .O(out1[11]));
  LUT6 #(
    .INIT(64'hA0000000C0000000)) 
    \out1[12]_INST_0 
       (.I0(in3[12]),
        .I1(in2[12]),
        .I2(\out1[31]_INST_0_i_1_n_0 ),
        .I3(\out1[31]_INST_0_i_2_n_0 ),
        .I4(\out1[31]_INST_0_i_3_n_0 ),
        .I5(ctrl1[2]),
        .O(out1[12]));
  LUT6 #(
    .INIT(64'hA0000000C0000000)) 
    \out1[13]_INST_0 
       (.I0(in3[13]),
        .I1(in2[13]),
        .I2(\out1[31]_INST_0_i_1_n_0 ),
        .I3(\out1[31]_INST_0_i_2_n_0 ),
        .I4(\out1[31]_INST_0_i_3_n_0 ),
        .I5(ctrl1[2]),
        .O(out1[13]));
  LUT6 #(
    .INIT(64'hA0000000C0000000)) 
    \out1[14]_INST_0 
       (.I0(in3[14]),
        .I1(in2[14]),
        .I2(\out1[31]_INST_0_i_1_n_0 ),
        .I3(\out1[31]_INST_0_i_2_n_0 ),
        .I4(\out1[31]_INST_0_i_3_n_0 ),
        .I5(ctrl1[2]),
        .O(out1[14]));
  LUT6 #(
    .INIT(64'hA0000000C0000000)) 
    \out1[15]_INST_0 
       (.I0(in3[15]),
        .I1(in2[15]),
        .I2(\out1[31]_INST_0_i_1_n_0 ),
        .I3(\out1[31]_INST_0_i_2_n_0 ),
        .I4(\out1[31]_INST_0_i_3_n_0 ),
        .I5(ctrl1[2]),
        .O(out1[15]));
  LUT6 #(
    .INIT(64'hA0000000C0000000)) 
    \out1[16]_INST_0 
       (.I0(in3[16]),
        .I1(in2[16]),
        .I2(\out1[31]_INST_0_i_1_n_0 ),
        .I3(\out1[31]_INST_0_i_2_n_0 ),
        .I4(\out1[31]_INST_0_i_3_n_0 ),
        .I5(ctrl1[2]),
        .O(out1[16]));
  LUT6 #(
    .INIT(64'hA0000000C0000000)) 
    \out1[17]_INST_0 
       (.I0(in3[17]),
        .I1(in2[17]),
        .I2(\out1[31]_INST_0_i_1_n_0 ),
        .I3(\out1[31]_INST_0_i_2_n_0 ),
        .I4(\out1[31]_INST_0_i_3_n_0 ),
        .I5(ctrl1[2]),
        .O(out1[17]));
  LUT6 #(
    .INIT(64'hA0000000C0000000)) 
    \out1[18]_INST_0 
       (.I0(in3[18]),
        .I1(in2[18]),
        .I2(\out1[31]_INST_0_i_1_n_0 ),
        .I3(\out1[31]_INST_0_i_2_n_0 ),
        .I4(\out1[31]_INST_0_i_3_n_0 ),
        .I5(ctrl1[2]),
        .O(out1[18]));
  LUT6 #(
    .INIT(64'hA0000000C0000000)) 
    \out1[19]_INST_0 
       (.I0(in3[19]),
        .I1(in2[19]),
        .I2(\out1[31]_INST_0_i_1_n_0 ),
        .I3(\out1[31]_INST_0_i_2_n_0 ),
        .I4(\out1[31]_INST_0_i_3_n_0 ),
        .I5(ctrl1[2]),
        .O(out1[19]));
  LUT6 #(
    .INIT(64'hA0000000C0000000)) 
    \out1[1]_INST_0 
       (.I0(in3[1]),
        .I1(in2[1]),
        .I2(\out1[31]_INST_0_i_1_n_0 ),
        .I3(\out1[31]_INST_0_i_2_n_0 ),
        .I4(\out1[31]_INST_0_i_3_n_0 ),
        .I5(ctrl1[2]),
        .O(out1[1]));
  LUT6 #(
    .INIT(64'hA0000000C0000000)) 
    \out1[20]_INST_0 
       (.I0(in3[20]),
        .I1(in2[20]),
        .I2(\out1[31]_INST_0_i_1_n_0 ),
        .I3(\out1[31]_INST_0_i_2_n_0 ),
        .I4(\out1[31]_INST_0_i_3_n_0 ),
        .I5(ctrl1[2]),
        .O(out1[20]));
  LUT6 #(
    .INIT(64'hA0000000C0000000)) 
    \out1[21]_INST_0 
       (.I0(in3[21]),
        .I1(in2[21]),
        .I2(\out1[31]_INST_0_i_1_n_0 ),
        .I3(\out1[31]_INST_0_i_2_n_0 ),
        .I4(\out1[31]_INST_0_i_3_n_0 ),
        .I5(ctrl1[2]),
        .O(out1[21]));
  LUT6 #(
    .INIT(64'hA0000000C0000000)) 
    \out1[22]_INST_0 
       (.I0(in3[22]),
        .I1(in2[22]),
        .I2(\out1[31]_INST_0_i_1_n_0 ),
        .I3(\out1[31]_INST_0_i_2_n_0 ),
        .I4(\out1[31]_INST_0_i_3_n_0 ),
        .I5(ctrl1[2]),
        .O(out1[22]));
  LUT6 #(
    .INIT(64'hA0000000C0000000)) 
    \out1[23]_INST_0 
       (.I0(in3[23]),
        .I1(in2[23]),
        .I2(\out1[31]_INST_0_i_1_n_0 ),
        .I3(\out1[31]_INST_0_i_2_n_0 ),
        .I4(\out1[31]_INST_0_i_3_n_0 ),
        .I5(ctrl1[2]),
        .O(out1[23]));
  LUT6 #(
    .INIT(64'hA0000000C0000000)) 
    \out1[24]_INST_0 
       (.I0(in3[24]),
        .I1(in2[24]),
        .I2(\out1[31]_INST_0_i_1_n_0 ),
        .I3(\out1[31]_INST_0_i_2_n_0 ),
        .I4(\out1[31]_INST_0_i_3_n_0 ),
        .I5(ctrl1[2]),
        .O(out1[24]));
  LUT6 #(
    .INIT(64'hA0000000C0000000)) 
    \out1[25]_INST_0 
       (.I0(in3[25]),
        .I1(in2[25]),
        .I2(\out1[31]_INST_0_i_1_n_0 ),
        .I3(\out1[31]_INST_0_i_2_n_0 ),
        .I4(\out1[31]_INST_0_i_3_n_0 ),
        .I5(ctrl1[2]),
        .O(out1[25]));
  LUT6 #(
    .INIT(64'hA0000000C0000000)) 
    \out1[26]_INST_0 
       (.I0(in3[26]),
        .I1(in2[26]),
        .I2(\out1[31]_INST_0_i_1_n_0 ),
        .I3(\out1[31]_INST_0_i_2_n_0 ),
        .I4(\out1[31]_INST_0_i_3_n_0 ),
        .I5(ctrl1[2]),
        .O(out1[26]));
  LUT6 #(
    .INIT(64'hA0000000C0000000)) 
    \out1[27]_INST_0 
       (.I0(in3[27]),
        .I1(in2[27]),
        .I2(\out1[31]_INST_0_i_1_n_0 ),
        .I3(\out1[31]_INST_0_i_2_n_0 ),
        .I4(\out1[31]_INST_0_i_3_n_0 ),
        .I5(ctrl1[2]),
        .O(out1[27]));
  LUT6 #(
    .INIT(64'hA0000000C0000000)) 
    \out1[28]_INST_0 
       (.I0(in3[28]),
        .I1(in2[28]),
        .I2(\out1[31]_INST_0_i_1_n_0 ),
        .I3(\out1[31]_INST_0_i_2_n_0 ),
        .I4(\out1[31]_INST_0_i_3_n_0 ),
        .I5(ctrl1[2]),
        .O(out1[28]));
  LUT6 #(
    .INIT(64'hA0000000C0000000)) 
    \out1[29]_INST_0 
       (.I0(in3[29]),
        .I1(in2[29]),
        .I2(\out1[31]_INST_0_i_1_n_0 ),
        .I3(\out1[31]_INST_0_i_2_n_0 ),
        .I4(\out1[31]_INST_0_i_3_n_0 ),
        .I5(ctrl1[2]),
        .O(out1[29]));
  LUT6 #(
    .INIT(64'hA0000000C0000000)) 
    \out1[2]_INST_0 
       (.I0(in3[2]),
        .I1(in2[2]),
        .I2(\out1[31]_INST_0_i_1_n_0 ),
        .I3(\out1[31]_INST_0_i_2_n_0 ),
        .I4(\out1[31]_INST_0_i_3_n_0 ),
        .I5(ctrl1[2]),
        .O(out1[2]));
  LUT6 #(
    .INIT(64'hA0000000C0000000)) 
    \out1[30]_INST_0 
       (.I0(in3[30]),
        .I1(in2[30]),
        .I2(\out1[31]_INST_0_i_1_n_0 ),
        .I3(\out1[31]_INST_0_i_2_n_0 ),
        .I4(\out1[31]_INST_0_i_3_n_0 ),
        .I5(ctrl1[2]),
        .O(out1[30]));
  LUT6 #(
    .INIT(64'hA0000000C0000000)) 
    \out1[31]_INST_0 
       (.I0(in3[31]),
        .I1(in2[31]),
        .I2(\out1[31]_INST_0_i_1_n_0 ),
        .I3(\out1[31]_INST_0_i_2_n_0 ),
        .I4(\out1[31]_INST_0_i_3_n_0 ),
        .I5(ctrl1[2]),
        .O(out1[31]));
  LUT5 #(
    .INIT(32'h00010000)) 
    \out1[31]_INST_0_i_1 
       (.I0(ctrl1[23]),
        .I1(ctrl1[24]),
        .I2(ctrl1[25]),
        .I3(ctrl1[26]),
        .I4(\out1[31]_INST_0_i_4_n_0 ),
        .O(\out1[31]_INST_0_i_1_n_0 ));
  LUT5 #(
    .INIT(32'h00010000)) 
    \out1[31]_INST_0_i_2 
       (.I0(ctrl1[15]),
        .I1(ctrl1[16]),
        .I2(ctrl1[17]),
        .I3(ctrl1[18]),
        .I4(\out1[31]_INST_0_i_5_n_0 ),
        .O(\out1[31]_INST_0_i_2_n_0 ));
  LUT6 #(
    .INIT(64'h0000000000000080)) 
    \out1[31]_INST_0_i_3 
       (.I0(\out1[31]_INST_0_i_6_n_0 ),
        .I1(\out1[31]_INST_0_i_7_n_0 ),
        .I2(\out1[31]_INST_0_i_8_n_0 ),
        .I3(ctrl1[1]),
        .I4(ctrl1[0]),
        .I5(ctrl1[31]),
        .O(\out1[31]_INST_0_i_3_n_0 ));
  LUT4 #(
    .INIT(16'h0001)) 
    \out1[31]_INST_0_i_4 
       (.I0(ctrl1[30]),
        .I1(ctrl1[29]),
        .I2(ctrl1[28]),
        .I3(ctrl1[27]),
        .O(\out1[31]_INST_0_i_4_n_0 ));
  LUT4 #(
    .INIT(16'h0001)) 
    \out1[31]_INST_0_i_5 
       (.I0(ctrl1[22]),
        .I1(ctrl1[21]),
        .I2(ctrl1[20]),
        .I3(ctrl1[19]),
        .O(\out1[31]_INST_0_i_5_n_0 ));
  LUT4 #(
    .INIT(16'h0001)) 
    \out1[31]_INST_0_i_6 
       (.I0(ctrl1[14]),
        .I1(ctrl1[13]),
        .I2(ctrl1[12]),
        .I3(ctrl1[11]),
        .O(\out1[31]_INST_0_i_6_n_0 ));
  LUT4 #(
    .INIT(16'h0001)) 
    \out1[31]_INST_0_i_7 
       (.I0(ctrl1[10]),
        .I1(ctrl1[9]),
        .I2(ctrl1[8]),
        .I3(ctrl1[7]),
        .O(\out1[31]_INST_0_i_7_n_0 ));
  LUT4 #(
    .INIT(16'h0001)) 
    \out1[31]_INST_0_i_8 
       (.I0(ctrl1[6]),
        .I1(ctrl1[5]),
        .I2(ctrl1[4]),
        .I3(ctrl1[3]),
        .O(\out1[31]_INST_0_i_8_n_0 ));
  LUT6 #(
    .INIT(64'hA0000000C0000000)) 
    \out1[3]_INST_0 
       (.I0(in3[3]),
        .I1(in2[3]),
        .I2(\out1[31]_INST_0_i_1_n_0 ),
        .I3(\out1[31]_INST_0_i_2_n_0 ),
        .I4(\out1[31]_INST_0_i_3_n_0 ),
        .I5(ctrl1[2]),
        .O(out1[3]));
  LUT6 #(
    .INIT(64'hA0000000C0000000)) 
    \out1[4]_INST_0 
       (.I0(in3[4]),
        .I1(in2[4]),
        .I2(\out1[31]_INST_0_i_1_n_0 ),
        .I3(\out1[31]_INST_0_i_2_n_0 ),
        .I4(\out1[31]_INST_0_i_3_n_0 ),
        .I5(ctrl1[2]),
        .O(out1[4]));
  LUT6 #(
    .INIT(64'hA0000000C0000000)) 
    \out1[5]_INST_0 
       (.I0(in3[5]),
        .I1(in2[5]),
        .I2(\out1[31]_INST_0_i_1_n_0 ),
        .I3(\out1[31]_INST_0_i_2_n_0 ),
        .I4(\out1[31]_INST_0_i_3_n_0 ),
        .I5(ctrl1[2]),
        .O(out1[5]));
  LUT6 #(
    .INIT(64'hA0000000C0000000)) 
    \out1[6]_INST_0 
       (.I0(in3[6]),
        .I1(in2[6]),
        .I2(\out1[31]_INST_0_i_1_n_0 ),
        .I3(\out1[31]_INST_0_i_2_n_0 ),
        .I4(\out1[31]_INST_0_i_3_n_0 ),
        .I5(ctrl1[2]),
        .O(out1[6]));
  LUT6 #(
    .INIT(64'hA0000000C0000000)) 
    \out1[7]_INST_0 
       (.I0(in3[7]),
        .I1(in2[7]),
        .I2(\out1[31]_INST_0_i_1_n_0 ),
        .I3(\out1[31]_INST_0_i_2_n_0 ),
        .I4(\out1[31]_INST_0_i_3_n_0 ),
        .I5(ctrl1[2]),
        .O(out1[7]));
  LUT6 #(
    .INIT(64'hA0000000C0000000)) 
    \out1[8]_INST_0 
       (.I0(in3[8]),
        .I1(in2[8]),
        .I2(\out1[31]_INST_0_i_1_n_0 ),
        .I3(\out1[31]_INST_0_i_2_n_0 ),
        .I4(\out1[31]_INST_0_i_3_n_0 ),
        .I5(ctrl1[2]),
        .O(out1[8]));
  LUT6 #(
    .INIT(64'hA0000000C0000000)) 
    \out1[9]_INST_0 
       (.I0(in3[9]),
        .I1(in2[9]),
        .I2(\out1[31]_INST_0_i_1_n_0 ),
        .I3(\out1[31]_INST_0_i_2_n_0 ),
        .I4(\out1[31]_INST_0_i_3_n_0 ),
        .I5(ctrl1[2]),
        .O(out1[9]));
endmodule

