// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2018.2 (lin64) Build 2258646 Thu Jun 14 20:02:38 MDT 2018
// Date        : Wed Mar  4 15:36:38 2020
// Host        : socp04 running 64-bit CentOS Linux release 7.5.1804 (Core)
// Command     : write_verilog -cell inst_30 -force
//               /home/esp2020/yl4337/SHA/SystemC/Embedded_Scalable_Platform/syn/bdw_work/modules/sha/BASIC/v_gates/sha_Add_7Ux2S_7S_4.v
// Design      : sha_Add_7Ux2S_7S_4
// Purpose     : This is a Verilog netlist of the current design or from a specific cell of the design. The output is an
//               IEEE 1364-2001 compliant Verilog HDL file that contains netlist information obtained from the input
//               design files.
// Device      : xczu9eg-ffvb1156-2-e
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* STRUCTURAL_NETLIST = "yes" *)
module sha_Add_7Ux2S_7S_4
   (in2,
    in1,
    out1);
  input [6:0]in2;
  input [1:0]in1;
  output [6:0]out1;

  wire [1:0]in1;
  wire [6:0]in2;
  wire [6:0]out1;
  wire \out1[6]_INST_0_i_1_n_0 ;

  LUT2 #(
    .INIT(4'h6)) 
    \out1[0]_INST_0 
       (.I0(in2[0]),
        .I1(in1[0]),
        .O(out1[0]));
  (* SOFT_HLUTNM = "soft_lutpair56" *) 
  LUT4 #(
    .INIT(16'h956A)) 
    \out1[1]_INST_0 
       (.I0(in2[1]),
        .I1(in2[0]),
        .I2(in1[0]),
        .I3(in1[1]),
        .O(out1[1]));
  (* SOFT_HLUTNM = "soft_lutpair56" *) 
  LUT5 #(
    .INIT(32'hEA157F80)) 
    \out1[2]_INST_0 
       (.I0(in2[1]),
        .I1(in2[0]),
        .I2(in1[0]),
        .I3(in2[2]),
        .I4(in1[1]),
        .O(out1[2]));
  LUT6 #(
    .INIT(64'hBFFF4000FDDD0222)) 
    \out1[3]_INST_0 
       (.I0(in1[1]),
        .I1(in2[1]),
        .I2(in2[0]),
        .I3(in1[0]),
        .I4(in2[3]),
        .I5(in2[2]),
        .O(out1[3]));
  LUT3 #(
    .INIT(8'h69)) 
    \out1[4]_INST_0 
       (.I0(\out1[6]_INST_0_i_1_n_0 ),
        .I1(in2[4]),
        .I2(in2[3]),
        .O(out1[4]));
  (* SOFT_HLUTNM = "soft_lutpair55" *) 
  LUT4 #(
    .INIT(16'h7E81)) 
    \out1[5]_INST_0 
       (.I0(in2[4]),
        .I1(in2[3]),
        .I2(\out1[6]_INST_0_i_1_n_0 ),
        .I3(in2[5]),
        .O(out1[5]));
  (* SOFT_HLUTNM = "soft_lutpair55" *) 
  LUT5 #(
    .INIT(32'h7F80FE01)) 
    \out1[6]_INST_0 
       (.I0(in2[4]),
        .I1(in2[3]),
        .I2(\out1[6]_INST_0_i_1_n_0 ),
        .I3(in2[6]),
        .I4(in2[5]),
        .O(out1[6]));
  LUT6 #(
    .INIT(64'h0080FFFF0000F8FF)) 
    \out1[6]_INST_0_i_1 
       (.I0(in1[0]),
        .I1(in2[0]),
        .I2(in2[1]),
        .I3(in1[1]),
        .I4(in2[3]),
        .I5(in2[2]),
        .O(\out1[6]_INST_0_i_1_n_0 ));
endmodule

