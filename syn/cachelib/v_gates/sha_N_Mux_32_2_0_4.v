// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2018.2 (lin64) Build 2258646 Thu Jun 14 20:02:38 MDT 2018
// Date        : Wed Mar  4 15:36:48 2020
// Host        : socp04 running 64-bit CentOS Linux release 7.5.1804 (Core)
// Command     : write_verilog -cell inst_49 -force
//               /home/esp2020/yl4337/SHA/SystemC/Embedded_Scalable_Platform/syn/bdw_work/modules/sha/BASIC/v_gates/sha_N_Mux_32_2_0_4.v
// Design      : sha_N_Mux_32_2_0_4
// Purpose     : This is a Verilog netlist of the current design or from a specific cell of the design. The output is an
//               IEEE 1364-2001 compliant Verilog HDL file that contains netlist information obtained from the input
//               design files.
// Device      : xczu9eg-ffvb1156-2-e
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* STRUCTURAL_NETLIST = "yes" *)
module sha_N_Mux_32_2_0_4
   (in2,
    ctrl1,
    out1);
  input [31:0]in2;
  input ctrl1;
  output [31:0]out1;

  wire ctrl1;
  wire [31:0]in2;
  wire [31:0]out1;

  (* SOFT_HLUTNM = "soft_lutpair85" *) 
  LUT2 #(
    .INIT(4'h4)) 
    \out1[0]_INST_0 
       (.I0(ctrl1),
        .I1(in2[0]),
        .O(out1[0]));
  (* SOFT_HLUTNM = "soft_lutpair81" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \out1[10]_INST_0 
       (.I0(in2[10]),
        .I1(ctrl1),
        .O(out1[10]));
  (* SOFT_HLUTNM = "soft_lutpair80" *) 
  LUT2 #(
    .INIT(4'h4)) 
    \out1[11]_INST_0 
       (.I0(ctrl1),
        .I1(in2[11]),
        .O(out1[11]));
  (* SOFT_HLUTNM = "soft_lutpair80" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \out1[12]_INST_0 
       (.I0(in2[12]),
        .I1(ctrl1),
        .O(out1[12]));
  (* SOFT_HLUTNM = "soft_lutpair79" *) 
  LUT2 #(
    .INIT(4'h4)) 
    \out1[13]_INST_0 
       (.I0(ctrl1),
        .I1(in2[13]),
        .O(out1[13]));
  (* SOFT_HLUTNM = "soft_lutpair79" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \out1[14]_INST_0 
       (.I0(in2[14]),
        .I1(ctrl1),
        .O(out1[14]));
  (* SOFT_HLUTNM = "soft_lutpair78" *) 
  LUT2 #(
    .INIT(4'h4)) 
    \out1[15]_INST_0 
       (.I0(ctrl1),
        .I1(in2[15]),
        .O(out1[15]));
  (* SOFT_HLUTNM = "soft_lutpair78" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \out1[16]_INST_0 
       (.I0(in2[16]),
        .I1(ctrl1),
        .O(out1[16]));
  (* SOFT_HLUTNM = "soft_lutpair77" *) 
  LUT2 #(
    .INIT(4'h4)) 
    \out1[17]_INST_0 
       (.I0(ctrl1),
        .I1(in2[17]),
        .O(out1[17]));
  (* SOFT_HLUTNM = "soft_lutpair77" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \out1[18]_INST_0 
       (.I0(in2[18]),
        .I1(ctrl1),
        .O(out1[18]));
  (* SOFT_HLUTNM = "soft_lutpair76" *) 
  LUT2 #(
    .INIT(4'h4)) 
    \out1[19]_INST_0 
       (.I0(ctrl1),
        .I1(in2[19]),
        .O(out1[19]));
  (* SOFT_HLUTNM = "soft_lutpair85" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \out1[1]_INST_0 
       (.I0(in2[1]),
        .I1(ctrl1),
        .O(out1[1]));
  (* SOFT_HLUTNM = "soft_lutpair76" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \out1[20]_INST_0 
       (.I0(in2[20]),
        .I1(ctrl1),
        .O(out1[20]));
  (* SOFT_HLUTNM = "soft_lutpair75" *) 
  LUT2 #(
    .INIT(4'h4)) 
    \out1[21]_INST_0 
       (.I0(ctrl1),
        .I1(in2[21]),
        .O(out1[21]));
  (* SOFT_HLUTNM = "soft_lutpair75" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \out1[22]_INST_0 
       (.I0(in2[22]),
        .I1(ctrl1),
        .O(out1[22]));
  (* SOFT_HLUTNM = "soft_lutpair74" *) 
  LUT2 #(
    .INIT(4'h4)) 
    \out1[23]_INST_0 
       (.I0(ctrl1),
        .I1(in2[23]),
        .O(out1[23]));
  (* SOFT_HLUTNM = "soft_lutpair74" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \out1[24]_INST_0 
       (.I0(in2[24]),
        .I1(ctrl1),
        .O(out1[24]));
  (* SOFT_HLUTNM = "soft_lutpair73" *) 
  LUT2 #(
    .INIT(4'h4)) 
    \out1[25]_INST_0 
       (.I0(ctrl1),
        .I1(in2[25]),
        .O(out1[25]));
  (* SOFT_HLUTNM = "soft_lutpair73" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \out1[26]_INST_0 
       (.I0(in2[26]),
        .I1(ctrl1),
        .O(out1[26]));
  (* SOFT_HLUTNM = "soft_lutpair72" *) 
  LUT2 #(
    .INIT(4'h4)) 
    \out1[27]_INST_0 
       (.I0(ctrl1),
        .I1(in2[27]),
        .O(out1[27]));
  (* SOFT_HLUTNM = "soft_lutpair72" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \out1[28]_INST_0 
       (.I0(in2[28]),
        .I1(ctrl1),
        .O(out1[28]));
  (* SOFT_HLUTNM = "soft_lutpair71" *) 
  LUT2 #(
    .INIT(4'h4)) 
    \out1[29]_INST_0 
       (.I0(ctrl1),
        .I1(in2[29]),
        .O(out1[29]));
  (* SOFT_HLUTNM = "soft_lutpair84" *) 
  LUT2 #(
    .INIT(4'h4)) 
    \out1[2]_INST_0 
       (.I0(ctrl1),
        .I1(in2[2]),
        .O(out1[2]));
  (* SOFT_HLUTNM = "soft_lutpair71" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \out1[30]_INST_0 
       (.I0(in2[30]),
        .I1(ctrl1),
        .O(out1[30]));
  (* SOFT_HLUTNM = "soft_lutpair70" *) 
  LUT2 #(
    .INIT(4'h4)) 
    \out1[31]_INST_0 
       (.I0(ctrl1),
        .I1(in2[31]),
        .O(out1[31]));
  (* SOFT_HLUTNM = "soft_lutpair84" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \out1[3]_INST_0 
       (.I0(in2[3]),
        .I1(ctrl1),
        .O(out1[3]));
  (* SOFT_HLUTNM = "soft_lutpair70" *) 
  LUT2 #(
    .INIT(4'hE)) 
    \out1[4]_INST_0 
       (.I0(ctrl1),
        .I1(in2[4]),
        .O(out1[4]));
  (* SOFT_HLUTNM = "soft_lutpair83" *) 
  LUT2 #(
    .INIT(4'h4)) 
    \out1[5]_INST_0 
       (.I0(ctrl1),
        .I1(in2[5]),
        .O(out1[5]));
  (* SOFT_HLUTNM = "soft_lutpair83" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \out1[6]_INST_0 
       (.I0(in2[6]),
        .I1(ctrl1),
        .O(out1[6]));
  (* SOFT_HLUTNM = "soft_lutpair82" *) 
  LUT2 #(
    .INIT(4'h4)) 
    \out1[7]_INST_0 
       (.I0(ctrl1),
        .I1(in2[7]),
        .O(out1[7]));
  (* SOFT_HLUTNM = "soft_lutpair82" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \out1[8]_INST_0 
       (.I0(in2[8]),
        .I1(ctrl1),
        .O(out1[8]));
  (* SOFT_HLUTNM = "soft_lutpair81" *) 
  LUT2 #(
    .INIT(4'h4)) 
    \out1[9]_INST_0 
       (.I0(ctrl1),
        .I1(in2[9]),
        .O(out1[9]));
endmodule

