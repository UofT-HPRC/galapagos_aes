// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2019.1
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

(* CORE_GENERATION_INFO="GMI_data_width_64_512,hls_ip_2019_1,{HLS_INPUT_TYPE=cxx,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xczu19eg-ffvc1760-2-i,HLS_INPUT_CLOCK=10.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=0.000000,HLS_SYN_LAT=-1,HLS_SYN_TPT=none,HLS_SYN_MEM=0,HLS_SYN_DSP=0,HLS_SYN_FF=108,HLS_SYN_LUT=41,HLS_VERSION=2019_1}" *)

module GMI_data_width_64_512 (
        ap_clk,
        ap_rst_n,
        in_r_TDATA,
        in_r_TVALID,
        in_r_TREADY,
        in_r_TDEST,
        in_r_TLAST,
        in_r_TID,
        in_r_TUSER,
        in_r_TKEEP,
        out_r_TDATA,
        out_r_TVALID,
        out_r_TREADY,
        out_r_TDEST,
        out_r_TLAST,
        out_r_TID,
        out_r_TUSER,
        out_r_TKEEP
);

parameter    ap_ST_fsm_state1 = 2'd1;
parameter    ap_ST_fsm_state2 = 2'd2;

input   ap_clk;
input   ap_rst_n;
input  [63:0] in_r_TDATA;
input   in_r_TVALID;
output   in_r_TREADY;
input  [7:0] in_r_TDEST;
input  [0:0] in_r_TLAST;
input  [7:0] in_r_TID;
input  [15:0] in_r_TUSER;
input  [7:0] in_r_TKEEP;
output  [511:0] out_r_TDATA;
output   out_r_TVALID;
input   out_r_TREADY;
output  [7:0] out_r_TDEST;
output  [0:0] out_r_TLAST;
output  [7:0] out_r_TID;
output  [15:0] out_r_TUSER;
output  [63:0] out_r_TKEEP;

reg in_r_TREADY;
reg out_r_TVALID;

 reg    ap_rst_n_inv;
reg    in_r_TDATA_blk_n;
(* fsm_encoding = "none" *) reg   [1:0] ap_CS_fsm;
wire    ap_CS_fsm_state1;
wire   [0:0] tmp_nbreadreq_fu_60_p8;
reg    out_r_TDATA_blk_n;
wire    ap_CS_fsm_state2;
reg   [0:0] tmp_reg_174;
wire   [0:0] tmp_1_nbwritereq_fu_94_p8;
reg    ap_block_state1;
reg   [7:0] tmp_dest_V_reg_178;
reg   [0:0] tmp_last_V_reg_183;
reg   [7:0] tmp_id_V_reg_188;
reg   [15:0] tmp_user_V_reg_193;
wire   [511:0] p_Result_s_fu_158_p3;
reg   [511:0] p_Result_s_reg_198;
wire   [63:0] p_Result_1_fu_166_p3;
reg   [63:0] p_Result_1_reg_203;
reg    ap_predicate_op33_write_state2;
reg    ap_block_state2_io;
reg   [1:0] ap_NS_fsm;

// power-on initialization
initial begin
#0 ap_CS_fsm = 2'd1;
end

always @ (posedge ap_clk) begin
    if (ap_rst_n_inv == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_state1;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if ((~((tmp_nbreadreq_fu_60_p8 == 1'd1) & (in_r_TVALID == 1'b0)) & (tmp_nbreadreq_fu_60_p8 == 1'd1) & (1'b1 == ap_CS_fsm_state1))) begin
        p_Result_1_reg_203[7 : 0] <= p_Result_1_fu_166_p3[7 : 0];
        p_Result_s_reg_198[63 : 0] <= p_Result_s_fu_158_p3[63 : 0];
        tmp_dest_V_reg_178 <= in_r_TDEST;
        tmp_id_V_reg_188 <= in_r_TID;
        tmp_last_V_reg_183 <= in_r_TLAST;
        tmp_user_V_reg_193 <= in_r_TUSER;
    end
end

always @ (posedge ap_clk) begin
    if ((~((tmp_nbreadreq_fu_60_p8 == 1'd1) & (in_r_TVALID == 1'b0)) & (1'b1 == ap_CS_fsm_state1))) begin
        tmp_reg_174 <= tmp_nbreadreq_fu_60_p8;
    end
end

always @ (*) begin
    if (((tmp_nbreadreq_fu_60_p8 == 1'd1) & (1'b1 == ap_CS_fsm_state1))) begin
        in_r_TDATA_blk_n = in_r_TVALID;
    end else begin
        in_r_TDATA_blk_n = 1'b1;
    end
end

always @ (*) begin
    if ((~((tmp_nbreadreq_fu_60_p8 == 1'd1) & (in_r_TVALID == 1'b0)) & (tmp_nbreadreq_fu_60_p8 == 1'd1) & (1'b1 == ap_CS_fsm_state1))) begin
        in_r_TREADY = 1'b1;
    end else begin
        in_r_TREADY = 1'b0;
    end
end

always @ (*) begin
    if (((tmp_1_nbwritereq_fu_94_p8 == 1'd1) & (tmp_reg_174 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
        out_r_TDATA_blk_n = out_r_TREADY;
    end else begin
        out_r_TDATA_blk_n = 1'b1;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_state2_io) & (ap_predicate_op33_write_state2 == 1'b1) & (1'b1 == ap_CS_fsm_state2))) begin
        out_r_TVALID = 1'b1;
    end else begin
        out_r_TVALID = 1'b0;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_state1 : begin
            if ((~((tmp_nbreadreq_fu_60_p8 == 1'd1) & (in_r_TVALID == 1'b0)) & (1'b1 == ap_CS_fsm_state1))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end
        end
        ap_ST_fsm_state2 : begin
            if (((1'b0 == ap_block_state2_io) & (1'b1 == ap_CS_fsm_state2) & ((tmp_reg_174 == 1'd0) | (tmp_1_nbwritereq_fu_94_p8 == 1'd1)))) begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end else if (((1'b0 == ap_block_state2_io) & (tmp_1_nbwritereq_fu_94_p8 == 1'd0) & (tmp_reg_174 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign ap_CS_fsm_state1 = ap_CS_fsm[32'd0];

assign ap_CS_fsm_state2 = ap_CS_fsm[32'd1];

always @ (*) begin
    ap_block_state1 = ((tmp_nbreadreq_fu_60_p8 == 1'd1) & (in_r_TVALID == 1'b0));
end

always @ (*) begin
    ap_block_state2_io = ((out_r_TREADY == 1'b0) & (ap_predicate_op33_write_state2 == 1'b1));
end

always @ (*) begin
    ap_predicate_op33_write_state2 = ((tmp_1_nbwritereq_fu_94_p8 == 1'd1) & (tmp_reg_174 == 1'd1));
end

always @ (*) begin
    ap_rst_n_inv = ~ap_rst_n;
end

assign out_r_TDATA = p_Result_s_reg_198;

assign out_r_TDEST = tmp_dest_V_reg_178;

assign out_r_TID = tmp_id_V_reg_188;

assign out_r_TKEEP = p_Result_1_reg_203;

assign out_r_TLAST = tmp_last_V_reg_183;

assign out_r_TUSER = tmp_user_V_reg_193;

assign p_Result_1_fu_166_p3 = {{56'd72057594037927935}, {in_r_TKEEP}};

assign p_Result_s_fu_158_p3 = {{448'd0}, {in_r_TDATA}};

assign tmp_1_nbwritereq_fu_94_p8 = out_r_TREADY;

assign tmp_nbreadreq_fu_60_p8 = in_r_TVALID;

always @ (posedge ap_clk) begin
    p_Result_s_reg_198[511:64] <= 448'b0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000;
    p_Result_1_reg_203[63:8] <= 56'b11111111111111111111111111111111111111111111111111111111;
end

endmodule //GMI_data_width_64_512
