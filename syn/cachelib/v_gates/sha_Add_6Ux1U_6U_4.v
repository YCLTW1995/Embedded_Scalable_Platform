// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2018.2 (lin64) Build 2258646 Thu Jun 14 20:02:38 MDT 2018
// Date        : Wed Mar  4 15:51:55 2020
// Host        : socp04 running 64-bit CentOS Linux release 7.5.1804 (Core)
// Command     : write_verilog -cell inst_2 -force
//               /home/esp2020/yl4337/SHA/SystemC/Embedded_Scalable_Platform/syn/bdw_work/modules/sha/BASIC/v_gates/sha_Add_6Ux1U_6U_4.v
// Design      : sha_Add_6Ux1U_6U_4
// Purpose     : This is a Verilog netlist of the current design or from a specific cell of the design. The output is an
//               IEEE 1364-2001 compliant Verilog HDL file that contains netlist information obtained from the input
//               design files.
// Device      : xczu9eg-ffvb1156-2-e
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* STRUCTURAL_NETLIST = "yes" *)
module sha_Add_6Ux1U_6U_4
   (in2,
    in1,
    out1);
  input [5:0]in2;
  input in1;
  output [5:0]out1;

  wire in1;
  wire [5:0]in2;
  wire [5:0]out1;
  wire \out1[5]_INST_0_i_1_n_0 ;

  LUT2 #(
    .INIT(4'h6)) 
    \out1[0]_INST_0 
       (.I0(in2[0]),
        .I1(in1),
        .O(out1[0]));
  (* SOFT_HLUTNM = "soft_lutpair6" *) 
  LUT3 #(
    .INIT(8'h78)) 
    \out1[1]_INST_0 
       (.I0(in1),
        .I1(in2[0]),
        .I2(in2[1]),
        .O(out1[1]));
  (* SOFT_HLUTNM = "soft_lutpair6" *) 
  LUT4 #(
    .INIT(16'h7F80)) 
    \out1[2]_INST_0 
       (.I0(in1),
        .I1(in2[0]),
        .I2(in2[1]),
        .I3(in2[2]),
        .O(out1[2]));
  (* SOFT_HLUTNM = "soft_lutpair5" *) 
  LUT5 #(
    .INIT(32'h7FFF8000)) 
    \out1[3]_INST_0 
       (.I0(in2[1]),
        .I1(in2[0]),
        .I2(in1),
        .I3(in2[2]),
        .I4(in2[3]),
        .O(out1[3]));
  LUT6 #(
    .INIT(64'h7FFFFFFF80000000)) 
    \out1[4]_INST_0 
       (.I0(in2[2]),
        .I1(in1),
        .I2(in2[0]),
        .I3(in2[1]),
        .I4(in2[3]),
        .I5(in2[4]),
        .O(out1[4]));
  LUT3 #(
    .INIT(8'h78)) 
    \out1[5]_INST_0 
       (.I0(\out1[5]_INST_0_i_1_n_0 ),
        .I1(in2[4]),
        .I2(in2[5]),
        .O(out1[5]));
  (* SOFT_HLUTNM = "soft_lutpair5" *) 
  LUT5 #(
    .INIT(32'h80000000)) 
    \out1[5]_INST_0_i_1 
       (.I0(in2[1]),
        .I1(in2[0]),
        .I2(in1),
        .I3(in2[2]),
        .I4(in2[3]),
        .O(\out1[5]_INST_0_i_1_n_0 ));
endmodule

