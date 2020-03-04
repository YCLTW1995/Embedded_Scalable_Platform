// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2018.2 (lin64) Build 2258646 Thu Jun 14 20:02:38 MDT 2018
// Date        : Wed Mar  4 15:36:36 2020
// Host        : socp04 running 64-bit CentOS Linux release 7.5.1804 (Core)
// Command     : write_verilog -cell inst_26 -force
//               /home/esp2020/yl4337/SHA/SystemC/Embedded_Scalable_Platform/syn/bdw_work/modules/sha/BASIC/v_gates/sha_And_1Ux1U_1U_4.v
// Design      : sha_And_1Ux1U_1U_4
// Purpose     : This is a Verilog netlist of the current design or from a specific cell of the design. The output is an
//               IEEE 1364-2001 compliant Verilog HDL file that contains netlist information obtained from the input
//               design files.
// Device      : xczu9eg-ffvb1156-2-e
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* STRUCTURAL_NETLIST = "yes" *)
module sha_And_1Ux1U_1U_4
   (in2,
    in1,
    out1);
  input in2;
  input in1;
  output out1;

  wire in1;
  wire in2;
  wire out1;

  LUT2 #(
    .INIT(4'h8)) 
    out1_INST_0
       (.I0(in2),
        .I1(in1),
        .O(out1));
endmodule

