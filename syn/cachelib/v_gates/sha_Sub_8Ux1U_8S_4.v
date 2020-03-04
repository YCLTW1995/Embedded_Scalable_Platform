// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2018.2 (lin64) Build 2258646 Thu Jun 14 20:02:38 MDT 2018
// Date        : Wed Mar  4 15:36:48 2020
// Host        : socp04 running 64-bit CentOS Linux release 7.5.1804 (Core)
// Command     : write_verilog -cell inst_48 -force
//               /home/esp2020/yl4337/SHA/SystemC/Embedded_Scalable_Platform/syn/bdw_work/modules/sha/BASIC/v_gates/sha_Sub_8Ux1U_8S_4.v
// Design      : sha_Sub_8Ux1U_8S_4
// Purpose     : This is a Verilog netlist of the current design or from a specific cell of the design. The output is an
//               IEEE 1364-2001 compliant Verilog HDL file that contains netlist information obtained from the input
//               design files.
// Device      : xczu9eg-ffvb1156-2-e
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* STRUCTURAL_NETLIST = "yes" *)
module sha_Sub_8Ux1U_8S_4
   (in2,
    in1,
    out1);
  input [7:0]in2;
  input in1;
  output [7:0]out1;

  wire in1;
  wire [7:0]in2;
  wire [7:0]out1;
  wire \out1[7]_INST_0_i_1_n_0 ;

  (* SOFT_HLUTNM = "soft_lutpair69" *) 
  LUT2 #(
    .INIT(4'h6)) 
    \out1[0]_INST_0 
       (.I0(in1),
        .I1(in2[0]),
        .O(out1[0]));
  (* SOFT_HLUTNM = "soft_lutpair69" *) 
  LUT3 #(
    .INIT(8'hD2)) 
    \out1[1]_INST_0 
       (.I0(in1),
        .I1(in2[0]),
        .I2(in2[1]),
        .O(out1[1]));
  (* SOFT_HLUTNM = "soft_lutpair67" *) 
  LUT4 #(
    .INIT(16'hAAA6)) 
    \out1[2]_INST_0 
       (.I0(in2[2]),
        .I1(in1),
        .I2(in2[0]),
        .I3(in2[1]),
        .O(out1[2]));
  (* SOFT_HLUTNM = "soft_lutpair67" *) 
  LUT5 #(
    .INIT(32'hFFFB0004)) 
    \out1[3]_INST_0 
       (.I0(in2[2]),
        .I1(in1),
        .I2(in2[0]),
        .I3(in2[1]),
        .I4(in2[3]),
        .O(out1[3]));
  LUT6 #(
    .INIT(64'hFFFFFEFF00000100)) 
    \out1[4]_INST_0 
       (.I0(in2[3]),
        .I1(in2[1]),
        .I2(in2[0]),
        .I3(in1),
        .I4(in2[2]),
        .I5(in2[4]),
        .O(out1[4]));
  LUT2 #(
    .INIT(4'h9)) 
    \out1[5]_INST_0 
       (.I0(\out1[7]_INST_0_i_1_n_0 ),
        .I1(in2[5]),
        .O(out1[5]));
  (* SOFT_HLUTNM = "soft_lutpair68" *) 
  LUT3 #(
    .INIT(8'hA9)) 
    \out1[6]_INST_0 
       (.I0(in2[6]),
        .I1(\out1[7]_INST_0_i_1_n_0 ),
        .I2(in2[5]),
        .O(out1[6]));
  (* SOFT_HLUTNM = "soft_lutpair68" *) 
  LUT4 #(
    .INIT(16'hFE01)) 
    \out1[7]_INST_0 
       (.I0(in2[6]),
        .I1(\out1[7]_INST_0_i_1_n_0 ),
        .I2(in2[5]),
        .I3(in2[7]),
        .O(out1[7]));
  LUT6 #(
    .INIT(64'hFFFFFFFFFFFFFEFF)) 
    \out1[7]_INST_0_i_1 
       (.I0(in2[3]),
        .I1(in2[1]),
        .I2(in2[0]),
        .I3(in1),
        .I4(in2[2]),
        .I5(in2[4]),
        .O(\out1[7]_INST_0_i_1_n_0 ));
endmodule

