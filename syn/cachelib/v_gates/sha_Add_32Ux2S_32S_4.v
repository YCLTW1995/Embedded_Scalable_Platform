// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2018.2 (lin64) Build 2258646 Thu Jun 14 20:02:38 MDT 2018
// Date        : Wed Mar  4 15:36:45 2020
// Host        : socp04 running 64-bit CentOS Linux release 7.5.1804 (Core)
// Command     : write_verilog -cell inst_43 -force
//               /home/esp2020/yl4337/SHA/SystemC/Embedded_Scalable_Platform/syn/bdw_work/modules/sha/BASIC/v_gates/sha_Add_32Ux2S_32S_4.v
// Design      : sha_Add_32Ux2S_32S_4
// Purpose     : This is a Verilog netlist of the current design or from a specific cell of the design. The output is an
//               IEEE 1364-2001 compliant Verilog HDL file that contains netlist information obtained from the input
//               design files.
// Device      : xczu9eg-ffvb1156-2-e
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* STRUCTURAL_NETLIST = "yes" *)
module sha_Add_32Ux2S_32S_4
   (in2,
    in1,
    out1);
  input [31:0]in2;
  input [1:0]in1;
  output [31:0]out1;

  wire \<const0> ;
  wire GND_2;
  wire [1:0]in1;
  wire [31:0]in2;
  wire [31:0]out1;
  wire \out1[0]_INST_0_i_1_n_0 ;
  wire \out1[0]_INST_0_i_2_n_0 ;
  wire \out1[0]_INST_0_i_3_n_0 ;
  wire \out1[0]_INST_0_i_4_n_0 ;
  wire \out1[0]_INST_0_i_5_n_0 ;
  wire \out1[0]_INST_0_i_6_n_0 ;
  wire \out1[0]_INST_0_i_7_n_0 ;
  wire \out1[0]_INST_0_i_8_n_0 ;
  wire \out1[0]_INST_0_i_9_n_0 ;
  wire \out1[0]_INST_0_n_0 ;
  wire \out1[0]_INST_0_n_1 ;
  wire \out1[0]_INST_0_n_2 ;
  wire \out1[0]_INST_0_n_3 ;
  wire \out1[0]_INST_0_n_5 ;
  wire \out1[0]_INST_0_n_6 ;
  wire \out1[0]_INST_0_n_7 ;
  wire \out1[16]_INST_0_i_1_n_0 ;
  wire \out1[16]_INST_0_i_2_n_0 ;
  wire \out1[16]_INST_0_i_3_n_0 ;
  wire \out1[16]_INST_0_i_4_n_0 ;
  wire \out1[16]_INST_0_i_5_n_0 ;
  wire \out1[16]_INST_0_i_6_n_0 ;
  wire \out1[16]_INST_0_i_7_n_0 ;
  wire \out1[16]_INST_0_i_8_n_0 ;
  wire \out1[16]_INST_0_n_0 ;
  wire \out1[16]_INST_0_n_1 ;
  wire \out1[16]_INST_0_n_2 ;
  wire \out1[16]_INST_0_n_3 ;
  wire \out1[16]_INST_0_n_5 ;
  wire \out1[16]_INST_0_n_6 ;
  wire \out1[16]_INST_0_n_7 ;
  wire \out1[24]_INST_0_i_1_n_0 ;
  wire \out1[24]_INST_0_i_2_n_0 ;
  wire \out1[24]_INST_0_i_3_n_0 ;
  wire \out1[24]_INST_0_i_4_n_0 ;
  wire \out1[24]_INST_0_i_5_n_0 ;
  wire \out1[24]_INST_0_i_6_n_0 ;
  wire \out1[24]_INST_0_i_7_n_0 ;
  wire \out1[24]_INST_0_i_8_n_0 ;
  wire \out1[24]_INST_0_n_1 ;
  wire \out1[24]_INST_0_n_2 ;
  wire \out1[24]_INST_0_n_3 ;
  wire \out1[24]_INST_0_n_5 ;
  wire \out1[24]_INST_0_n_6 ;
  wire \out1[24]_INST_0_n_7 ;
  wire \out1[8]_INST_0_i_1_n_0 ;
  wire \out1[8]_INST_0_i_2_n_0 ;
  wire \out1[8]_INST_0_i_3_n_0 ;
  wire \out1[8]_INST_0_i_4_n_0 ;
  wire \out1[8]_INST_0_i_5_n_0 ;
  wire \out1[8]_INST_0_i_6_n_0 ;
  wire \out1[8]_INST_0_i_7_n_0 ;
  wire \out1[8]_INST_0_i_8_n_0 ;
  wire \out1[8]_INST_0_n_0 ;
  wire \out1[8]_INST_0_n_1 ;
  wire \out1[8]_INST_0_n_2 ;
  wire \out1[8]_INST_0_n_3 ;
  wire \out1[8]_INST_0_n_5 ;
  wire \out1[8]_INST_0_n_6 ;
  wire \out1[8]_INST_0_n_7 ;
  wire [7:0]\NLW_out1[0]_INST_0_CO_UNCONNECTED ;
  wire [7:0]\NLW_out1[16]_INST_0_CO_UNCONNECTED ;
  wire [7:0]\NLW_out1[24]_INST_0_CO_UNCONNECTED ;
  wire [7:0]\NLW_out1[8]_INST_0_CO_UNCONNECTED ;

  GND GND
       (.G(\<const0> ));
  GND GND_1
       (.G(GND_2));
  CARRY8 \out1[0]_INST_0 
       (.CI(\<const0> ),
        .CI_TOP(GND_2),
        .CO({\out1[0]_INST_0_n_0 ,\out1[0]_INST_0_n_1 ,\out1[0]_INST_0_n_2 ,\out1[0]_INST_0_n_3 ,\NLW_out1[0]_INST_0_CO_UNCONNECTED [3],\out1[0]_INST_0_n_5 ,\out1[0]_INST_0_n_6 ,\out1[0]_INST_0_n_7 }),
        .DI({in2[6:2],\out1[0]_INST_0_i_1_n_0 ,in1[1],in2[0]}),
        .O(out1[7:0]),
        .S({\out1[0]_INST_0_i_2_n_0 ,\out1[0]_INST_0_i_3_n_0 ,\out1[0]_INST_0_i_4_n_0 ,\out1[0]_INST_0_i_5_n_0 ,\out1[0]_INST_0_i_6_n_0 ,\out1[0]_INST_0_i_7_n_0 ,\out1[0]_INST_0_i_8_n_0 ,\out1[0]_INST_0_i_9_n_0 }));
  LUT1 #(
    .INIT(2'h1)) 
    \out1[0]_INST_0_i_1 
       (.I0(in1[1]),
        .O(\out1[0]_INST_0_i_1_n_0 ));
  LUT2 #(
    .INIT(4'h9)) 
    \out1[0]_INST_0_i_2 
       (.I0(in2[6]),
        .I1(in2[7]),
        .O(\out1[0]_INST_0_i_2_n_0 ));
  LUT2 #(
    .INIT(4'h9)) 
    \out1[0]_INST_0_i_3 
       (.I0(in2[5]),
        .I1(in2[6]),
        .O(\out1[0]_INST_0_i_3_n_0 ));
  LUT2 #(
    .INIT(4'h9)) 
    \out1[0]_INST_0_i_4 
       (.I0(in2[4]),
        .I1(in2[5]),
        .O(\out1[0]_INST_0_i_4_n_0 ));
  LUT2 #(
    .INIT(4'h9)) 
    \out1[0]_INST_0_i_5 
       (.I0(in2[3]),
        .I1(in2[4]),
        .O(\out1[0]_INST_0_i_5_n_0 ));
  LUT2 #(
    .INIT(4'h9)) 
    \out1[0]_INST_0_i_6 
       (.I0(in2[2]),
        .I1(in2[3]),
        .O(\out1[0]_INST_0_i_6_n_0 ));
  LUT2 #(
    .INIT(4'h6)) 
    \out1[0]_INST_0_i_7 
       (.I0(in1[1]),
        .I1(in2[2]),
        .O(\out1[0]_INST_0_i_7_n_0 ));
  LUT2 #(
    .INIT(4'h6)) 
    \out1[0]_INST_0_i_8 
       (.I0(in1[1]),
        .I1(in2[1]),
        .O(\out1[0]_INST_0_i_8_n_0 ));
  LUT2 #(
    .INIT(4'h6)) 
    \out1[0]_INST_0_i_9 
       (.I0(in2[0]),
        .I1(in1[0]),
        .O(\out1[0]_INST_0_i_9_n_0 ));
  CARRY8 \out1[16]_INST_0 
       (.CI(\out1[8]_INST_0_n_0 ),
        .CI_TOP(GND_2),
        .CO({\out1[16]_INST_0_n_0 ,\out1[16]_INST_0_n_1 ,\out1[16]_INST_0_n_2 ,\out1[16]_INST_0_n_3 ,\NLW_out1[16]_INST_0_CO_UNCONNECTED [3],\out1[16]_INST_0_n_5 ,\out1[16]_INST_0_n_6 ,\out1[16]_INST_0_n_7 }),
        .DI(in2[22:15]),
        .O(out1[23:16]),
        .S({\out1[16]_INST_0_i_1_n_0 ,\out1[16]_INST_0_i_2_n_0 ,\out1[16]_INST_0_i_3_n_0 ,\out1[16]_INST_0_i_4_n_0 ,\out1[16]_INST_0_i_5_n_0 ,\out1[16]_INST_0_i_6_n_0 ,\out1[16]_INST_0_i_7_n_0 ,\out1[16]_INST_0_i_8_n_0 }));
  LUT2 #(
    .INIT(4'h9)) 
    \out1[16]_INST_0_i_1 
       (.I0(in2[22]),
        .I1(in2[23]),
        .O(\out1[16]_INST_0_i_1_n_0 ));
  LUT2 #(
    .INIT(4'h9)) 
    \out1[16]_INST_0_i_2 
       (.I0(in2[21]),
        .I1(in2[22]),
        .O(\out1[16]_INST_0_i_2_n_0 ));
  LUT2 #(
    .INIT(4'h9)) 
    \out1[16]_INST_0_i_3 
       (.I0(in2[20]),
        .I1(in2[21]),
        .O(\out1[16]_INST_0_i_3_n_0 ));
  LUT2 #(
    .INIT(4'h9)) 
    \out1[16]_INST_0_i_4 
       (.I0(in2[19]),
        .I1(in2[20]),
        .O(\out1[16]_INST_0_i_4_n_0 ));
  LUT2 #(
    .INIT(4'h9)) 
    \out1[16]_INST_0_i_5 
       (.I0(in2[18]),
        .I1(in2[19]),
        .O(\out1[16]_INST_0_i_5_n_0 ));
  LUT2 #(
    .INIT(4'h9)) 
    \out1[16]_INST_0_i_6 
       (.I0(in2[17]),
        .I1(in2[18]),
        .O(\out1[16]_INST_0_i_6_n_0 ));
  LUT2 #(
    .INIT(4'h9)) 
    \out1[16]_INST_0_i_7 
       (.I0(in2[16]),
        .I1(in2[17]),
        .O(\out1[16]_INST_0_i_7_n_0 ));
  LUT2 #(
    .INIT(4'h9)) 
    \out1[16]_INST_0_i_8 
       (.I0(in2[15]),
        .I1(in2[16]),
        .O(\out1[16]_INST_0_i_8_n_0 ));
  CARRY8 \out1[24]_INST_0 
       (.CI(\out1[16]_INST_0_n_0 ),
        .CI_TOP(GND_2),
        .CO({\out1[24]_INST_0_n_1 ,\out1[24]_INST_0_n_2 ,\out1[24]_INST_0_n_3 ,\NLW_out1[24]_INST_0_CO_UNCONNECTED [3],\out1[24]_INST_0_n_5 ,\out1[24]_INST_0_n_6 ,\out1[24]_INST_0_n_7 }),
        .DI({\<const0> ,in2[29:23]}),
        .O(out1[31:24]),
        .S({\out1[24]_INST_0_i_1_n_0 ,\out1[24]_INST_0_i_2_n_0 ,\out1[24]_INST_0_i_3_n_0 ,\out1[24]_INST_0_i_4_n_0 ,\out1[24]_INST_0_i_5_n_0 ,\out1[24]_INST_0_i_6_n_0 ,\out1[24]_INST_0_i_7_n_0 ,\out1[24]_INST_0_i_8_n_0 }));
  LUT2 #(
    .INIT(4'h9)) 
    \out1[24]_INST_0_i_1 
       (.I0(in2[30]),
        .I1(in2[31]),
        .O(\out1[24]_INST_0_i_1_n_0 ));
  LUT2 #(
    .INIT(4'h9)) 
    \out1[24]_INST_0_i_2 
       (.I0(in2[29]),
        .I1(in2[30]),
        .O(\out1[24]_INST_0_i_2_n_0 ));
  LUT2 #(
    .INIT(4'h9)) 
    \out1[24]_INST_0_i_3 
       (.I0(in2[28]),
        .I1(in2[29]),
        .O(\out1[24]_INST_0_i_3_n_0 ));
  LUT2 #(
    .INIT(4'h9)) 
    \out1[24]_INST_0_i_4 
       (.I0(in2[27]),
        .I1(in2[28]),
        .O(\out1[24]_INST_0_i_4_n_0 ));
  LUT2 #(
    .INIT(4'h9)) 
    \out1[24]_INST_0_i_5 
       (.I0(in2[26]),
        .I1(in2[27]),
        .O(\out1[24]_INST_0_i_5_n_0 ));
  LUT2 #(
    .INIT(4'h9)) 
    \out1[24]_INST_0_i_6 
       (.I0(in2[25]),
        .I1(in2[26]),
        .O(\out1[24]_INST_0_i_6_n_0 ));
  LUT2 #(
    .INIT(4'h9)) 
    \out1[24]_INST_0_i_7 
       (.I0(in2[24]),
        .I1(in2[25]),
        .O(\out1[24]_INST_0_i_7_n_0 ));
  LUT2 #(
    .INIT(4'h9)) 
    \out1[24]_INST_0_i_8 
       (.I0(in2[23]),
        .I1(in2[24]),
        .O(\out1[24]_INST_0_i_8_n_0 ));
  CARRY8 \out1[8]_INST_0 
       (.CI(\out1[0]_INST_0_n_0 ),
        .CI_TOP(GND_2),
        .CO({\out1[8]_INST_0_n_0 ,\out1[8]_INST_0_n_1 ,\out1[8]_INST_0_n_2 ,\out1[8]_INST_0_n_3 ,\NLW_out1[8]_INST_0_CO_UNCONNECTED [3],\out1[8]_INST_0_n_5 ,\out1[8]_INST_0_n_6 ,\out1[8]_INST_0_n_7 }),
        .DI(in2[14:7]),
        .O(out1[15:8]),
        .S({\out1[8]_INST_0_i_1_n_0 ,\out1[8]_INST_0_i_2_n_0 ,\out1[8]_INST_0_i_3_n_0 ,\out1[8]_INST_0_i_4_n_0 ,\out1[8]_INST_0_i_5_n_0 ,\out1[8]_INST_0_i_6_n_0 ,\out1[8]_INST_0_i_7_n_0 ,\out1[8]_INST_0_i_8_n_0 }));
  LUT2 #(
    .INIT(4'h9)) 
    \out1[8]_INST_0_i_1 
       (.I0(in2[14]),
        .I1(in2[15]),
        .O(\out1[8]_INST_0_i_1_n_0 ));
  LUT2 #(
    .INIT(4'h9)) 
    \out1[8]_INST_0_i_2 
       (.I0(in2[13]),
        .I1(in2[14]),
        .O(\out1[8]_INST_0_i_2_n_0 ));
  LUT2 #(
    .INIT(4'h9)) 
    \out1[8]_INST_0_i_3 
       (.I0(in2[12]),
        .I1(in2[13]),
        .O(\out1[8]_INST_0_i_3_n_0 ));
  LUT2 #(
    .INIT(4'h9)) 
    \out1[8]_INST_0_i_4 
       (.I0(in2[11]),
        .I1(in2[12]),
        .O(\out1[8]_INST_0_i_4_n_0 ));
  LUT2 #(
    .INIT(4'h9)) 
    \out1[8]_INST_0_i_5 
       (.I0(in2[10]),
        .I1(in2[11]),
        .O(\out1[8]_INST_0_i_5_n_0 ));
  LUT2 #(
    .INIT(4'h9)) 
    \out1[8]_INST_0_i_6 
       (.I0(in2[9]),
        .I1(in2[10]),
        .O(\out1[8]_INST_0_i_6_n_0 ));
  LUT2 #(
    .INIT(4'h9)) 
    \out1[8]_INST_0_i_7 
       (.I0(in2[8]),
        .I1(in2[9]),
        .O(\out1[8]_INST_0_i_7_n_0 ));
  LUT2 #(
    .INIT(4'h9)) 
    \out1[8]_INST_0_i_8 
       (.I0(in2[7]),
        .I1(in2[8]),
        .O(\out1[8]_INST_0_i_8_n_0 ));
endmodule

