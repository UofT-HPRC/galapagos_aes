// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2019.1
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

module rxPath (
        ap_clk,
        ap_rst,
        ap_start,
        ap_done,
        ap_continue,
        ap_idle,
        ap_ready,
        lbRxDataIn_TVALID,
        txGalapagosBridge_TREADY,
        lbRxDataIn_TDATA,
        lbRxDataIn_TREADY,
        lbRxDataIn_TKEEP,
        lbRxDataIn_TLAST,
        txGalapagosBridge_TDATA,
        txGalapagosBridge_TVALID,
        txGalapagosBridge_TKEEP,
        txGalapagosBridge_TLAST,
        id_V,
        id_V_ap_vld,
        dest_V,
        dest_V_ap_vld,
        size_V,
        size_V_ap_vld
);

parameter    ap_ST_fsm_pp0_stage0 = 1'd1;

input   ap_clk;
input   ap_rst;
input   ap_start;
output   ap_done;
input   ap_continue;
output   ap_idle;
output   ap_ready;
input   lbRxDataIn_TVALID;
input   txGalapagosBridge_TREADY;
input  [511:0] lbRxDataIn_TDATA;
output   lbRxDataIn_TREADY;
input  [15:0] lbRxDataIn_TKEEP;
input  [0:0] lbRxDataIn_TLAST;
output  [511:0] txGalapagosBridge_TDATA;
output   txGalapagosBridge_TVALID;
output  [15:0] txGalapagosBridge_TKEEP;
output  [0:0] txGalapagosBridge_TLAST;
output  [7:0] id_V;
output   id_V_ap_vld;
output  [7:0] dest_V;
output   dest_V_ap_vld;
output  [15:0] size_V;
output   size_V_ap_vld;

reg ap_done;
reg ap_idle;
reg ap_ready;
reg lbRxDataIn_TREADY;
reg[7:0] id_V;
reg id_V_ap_vld;
reg[7:0] dest_V;
reg dest_V_ap_vld;
reg[15:0] size_V;
reg size_V_ap_vld;

reg    ap_done_reg;
(* fsm_encoding = "none" *) reg   [0:0] ap_CS_fsm;
wire    ap_CS_fsm_pp0_stage0;
wire    ap_enable_reg_pp0_iter0;
reg    ap_enable_reg_pp0_iter1;
reg    ap_enable_reg_pp0_iter2;
reg    ap_idle_pp0;
wire   [0:0] tmp_nbreadreq_fu_52_p5;
reg    ap_block_state1_pp0_stage0_iter0;
wire    ap_block_state2_pp0_stage0_iter1;
wire    txGalapagosBridge_V_data_V_1_ack_in;
reg   [0:0] tmp_reg_147;
reg    ap_block_state2_io;
wire    txGalapagosBridge_V_data_V_1_ack_out;
reg   [1:0] txGalapagosBridge_V_data_V_1_state;
wire    txGalapagosBridge_V_keep_V_1_ack_out;
reg   [1:0] txGalapagosBridge_V_keep_V_1_state;
wire    txGalapagosBridge_V_last_V_1_ack_out;
reg   [1:0] txGalapagosBridge_V_last_V_1_state;
reg    ap_block_state3_pp0_stage0_iter2;
reg   [0:0] tmp_reg_147_pp0_iter1_reg;
reg    ap_block_state3_io;
reg    ap_block_pp0_stage0_11001;
reg   [511:0] txGalapagosBridge_V_data_V_1_data_out;
reg    txGalapagosBridge_V_data_V_1_vld_in;
wire    txGalapagosBridge_V_data_V_1_vld_out;
reg   [511:0] txGalapagosBridge_V_data_V_1_payload_A;
reg   [511:0] txGalapagosBridge_V_data_V_1_payload_B;
reg    txGalapagosBridge_V_data_V_1_sel_rd;
reg    txGalapagosBridge_V_data_V_1_sel_wr;
wire    txGalapagosBridge_V_data_V_1_sel;
wire    txGalapagosBridge_V_data_V_1_load_A;
wire    txGalapagosBridge_V_data_V_1_load_B;
wire    txGalapagosBridge_V_data_V_1_state_cmp_full;
reg   [15:0] txGalapagosBridge_V_keep_V_1_data_out;
reg    txGalapagosBridge_V_keep_V_1_vld_in;
wire    txGalapagosBridge_V_keep_V_1_vld_out;
wire    txGalapagosBridge_V_keep_V_1_ack_in;
reg   [15:0] txGalapagosBridge_V_keep_V_1_payload_A;
reg   [15:0] txGalapagosBridge_V_keep_V_1_payload_B;
reg    txGalapagosBridge_V_keep_V_1_sel_rd;
reg    txGalapagosBridge_V_keep_V_1_sel_wr;
wire    txGalapagosBridge_V_keep_V_1_sel;
wire    txGalapagosBridge_V_keep_V_1_load_A;
wire    txGalapagosBridge_V_keep_V_1_load_B;
wire    txGalapagosBridge_V_keep_V_1_state_cmp_full;
reg   [0:0] txGalapagosBridge_V_last_V_1_data_out;
reg    txGalapagosBridge_V_last_V_1_vld_in;
wire    txGalapagosBridge_V_last_V_1_vld_out;
wire    txGalapagosBridge_V_last_V_1_ack_in;
reg   [0:0] txGalapagosBridge_V_last_V_1_payload_A;
reg   [0:0] txGalapagosBridge_V_last_V_1_payload_B;
reg    txGalapagosBridge_V_last_V_1_sel_rd;
reg    txGalapagosBridge_V_last_V_1_sel_wr;
wire    txGalapagosBridge_V_last_V_1_sel;
wire    txGalapagosBridge_V_last_V_1_load_A;
wire    txGalapagosBridge_V_last_V_1_load_B;
wire    txGalapagosBridge_V_last_V_1_state_cmp_full;
reg    lbRxDataIn_TDATA_blk_n;
wire    ap_block_pp0_stage0;
reg    txGalapagosBridge_TDATA_blk_n;
reg   [511:0] tmp_data_V_reg_151;
reg   [15:0] tmp_keep_V_reg_156;
reg   [0:0] tmp_last_V_reg_161;
reg    ap_block_pp0_stage0_subdone;
reg   [7:0] id_V_preg;
reg    ap_block_pp0_stage0_01001;
reg   [7:0] dest_V_preg;
wire   [15:0] trunc_ln647_fu_142_p1;
reg   [15:0] size_V_preg;
reg   [0:0] ap_NS_fsm;
reg    ap_idle_pp0_0to1;
reg    ap_reset_idle_pp0;
wire    ap_enable_pp0;

// power-on initialization
initial begin
#0 ap_done_reg = 1'b0;
#0 ap_CS_fsm = 1'd1;
#0 ap_enable_reg_pp0_iter1 = 1'b0;
#0 ap_enable_reg_pp0_iter2 = 1'b0;
#0 txGalapagosBridge_V_data_V_1_state = 2'd0;
#0 txGalapagosBridge_V_keep_V_1_state = 2'd0;
#0 txGalapagosBridge_V_last_V_1_state = 2'd0;
#0 txGalapagosBridge_V_data_V_1_sel_rd = 1'b0;
#0 txGalapagosBridge_V_data_V_1_sel_wr = 1'b0;
#0 txGalapagosBridge_V_keep_V_1_sel_rd = 1'b0;
#0 txGalapagosBridge_V_keep_V_1_sel_wr = 1'b0;
#0 txGalapagosBridge_V_last_V_1_sel_rd = 1'b0;
#0 txGalapagosBridge_V_last_V_1_sel_wr = 1'b0;
#0 id_V_preg = 8'd0;
#0 dest_V_preg = 8'd0;
#0 size_V_preg = 16'd0;
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_pp0_stage0;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_done_reg <= 1'b0;
    end else begin
        if ((ap_continue == 1'b1)) begin
            ap_done_reg <= 1'b0;
        end else if (((ap_enable_reg_pp0_iter2 == 1'b1) & (1'b0 == ap_block_pp0_stage0_11001))) begin
            ap_done_reg <= 1'b1;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_enable_reg_pp0_iter1 <= 1'b0;
    end else begin
        if (((1'b0 == ap_block_pp0_stage0_subdone) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
            ap_enable_reg_pp0_iter1 <= ap_start;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_enable_reg_pp0_iter2 <= 1'b0;
    end else begin
        if ((1'b0 == ap_block_pp0_stage0_subdone)) begin
            ap_enable_reg_pp0_iter2 <= ap_enable_reg_pp0_iter1;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        dest_V_preg <= 8'd0;
    end else begin
        if (((tmp_nbreadreq_fu_52_p5 == 1'd1) & (1'b0 == ap_block_pp0_stage0_01001) & (ap_start == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
            dest_V_preg <= {{lbRxDataIn_TDATA[31:24]}};
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        id_V_preg <= 8'd0;
    end else begin
        if (((tmp_nbreadreq_fu_52_p5 == 1'd1) & (1'b0 == ap_block_pp0_stage0_01001) & (ap_start == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
            id_V_preg <= {{lbRxDataIn_TDATA[23:16]}};
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        size_V_preg <= 16'd0;
    end else begin
        if (((tmp_nbreadreq_fu_52_p5 == 1'd1) & (1'b0 == ap_block_pp0_stage0_01001) & (ap_start == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
            size_V_preg <= trunc_ln647_fu_142_p1;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        txGalapagosBridge_V_data_V_1_sel_rd <= 1'b0;
    end else begin
        if (((txGalapagosBridge_V_data_V_1_ack_out == 1'b1) & (txGalapagosBridge_V_data_V_1_vld_out == 1'b1))) begin
            txGalapagosBridge_V_data_V_1_sel_rd <= ~txGalapagosBridge_V_data_V_1_sel_rd;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        txGalapagosBridge_V_data_V_1_sel_wr <= 1'b0;
    end else begin
        if (((txGalapagosBridge_V_data_V_1_ack_in == 1'b1) & (txGalapagosBridge_V_data_V_1_vld_in == 1'b1))) begin
            txGalapagosBridge_V_data_V_1_sel_wr <= ~txGalapagosBridge_V_data_V_1_sel_wr;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        txGalapagosBridge_V_data_V_1_state <= 2'd0;
    end else begin
        if ((((txGalapagosBridge_V_data_V_1_state == 2'd3) & (txGalapagosBridge_V_data_V_1_vld_in == 1'b0) & (txGalapagosBridge_V_data_V_1_ack_out == 1'b1)) | ((txGalapagosBridge_V_data_V_1_state == 2'd2) & (txGalapagosBridge_V_data_V_1_vld_in == 1'b0)))) begin
            txGalapagosBridge_V_data_V_1_state <= 2'd2;
        end else if ((((txGalapagosBridge_V_data_V_1_state == 2'd1) & (txGalapagosBridge_TREADY == 1'b0)) | ((txGalapagosBridge_V_data_V_1_state == 2'd3) & (txGalapagosBridge_TREADY == 1'b0) & (txGalapagosBridge_V_data_V_1_vld_in == 1'b1)))) begin
            txGalapagosBridge_V_data_V_1_state <= 2'd1;
        end else if ((((txGalapagosBridge_V_data_V_1_state == 2'd1) & (txGalapagosBridge_V_data_V_1_ack_out == 1'b1)) | (~((txGalapagosBridge_V_data_V_1_vld_in == 1'b0) & (txGalapagosBridge_V_data_V_1_ack_out == 1'b1)) & ~((txGalapagosBridge_TREADY == 1'b0) & (txGalapagosBridge_V_data_V_1_vld_in == 1'b1)) & (txGalapagosBridge_V_data_V_1_state == 2'd3)) | ((txGalapagosBridge_V_data_V_1_state == 2'd2) & (txGalapagosBridge_V_data_V_1_vld_in == 1'b1)))) begin
            txGalapagosBridge_V_data_V_1_state <= 2'd3;
        end else begin
            txGalapagosBridge_V_data_V_1_state <= 2'd2;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        txGalapagosBridge_V_keep_V_1_sel_rd <= 1'b0;
    end else begin
        if (((txGalapagosBridge_V_keep_V_1_ack_out == 1'b1) & (txGalapagosBridge_V_keep_V_1_vld_out == 1'b1))) begin
            txGalapagosBridge_V_keep_V_1_sel_rd <= ~txGalapagosBridge_V_keep_V_1_sel_rd;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        txGalapagosBridge_V_keep_V_1_sel_wr <= 1'b0;
    end else begin
        if (((txGalapagosBridge_V_keep_V_1_ack_in == 1'b1) & (txGalapagosBridge_V_keep_V_1_vld_in == 1'b1))) begin
            txGalapagosBridge_V_keep_V_1_sel_wr <= ~txGalapagosBridge_V_keep_V_1_sel_wr;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        txGalapagosBridge_V_keep_V_1_state <= 2'd0;
    end else begin
        if ((((txGalapagosBridge_V_keep_V_1_state == 2'd3) & (txGalapagosBridge_V_keep_V_1_vld_in == 1'b0) & (txGalapagosBridge_V_keep_V_1_ack_out == 1'b1)) | ((txGalapagosBridge_V_keep_V_1_state == 2'd2) & (txGalapagosBridge_V_keep_V_1_vld_in == 1'b0)))) begin
            txGalapagosBridge_V_keep_V_1_state <= 2'd2;
        end else if ((((txGalapagosBridge_V_keep_V_1_state == 2'd1) & (txGalapagosBridge_TREADY == 1'b0)) | ((txGalapagosBridge_V_keep_V_1_state == 2'd3) & (txGalapagosBridge_TREADY == 1'b0) & (txGalapagosBridge_V_keep_V_1_vld_in == 1'b1)))) begin
            txGalapagosBridge_V_keep_V_1_state <= 2'd1;
        end else if ((((txGalapagosBridge_V_keep_V_1_state == 2'd1) & (txGalapagosBridge_V_keep_V_1_ack_out == 1'b1)) | (~((txGalapagosBridge_V_keep_V_1_vld_in == 1'b0) & (txGalapagosBridge_V_keep_V_1_ack_out == 1'b1)) & ~((txGalapagosBridge_TREADY == 1'b0) & (txGalapagosBridge_V_keep_V_1_vld_in == 1'b1)) & (txGalapagosBridge_V_keep_V_1_state == 2'd3)) | ((txGalapagosBridge_V_keep_V_1_state == 2'd2) & (txGalapagosBridge_V_keep_V_1_vld_in == 1'b1)))) begin
            txGalapagosBridge_V_keep_V_1_state <= 2'd3;
        end else begin
            txGalapagosBridge_V_keep_V_1_state <= 2'd2;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        txGalapagosBridge_V_last_V_1_sel_rd <= 1'b0;
    end else begin
        if (((txGalapagosBridge_V_last_V_1_ack_out == 1'b1) & (txGalapagosBridge_V_last_V_1_vld_out == 1'b1))) begin
            txGalapagosBridge_V_last_V_1_sel_rd <= ~txGalapagosBridge_V_last_V_1_sel_rd;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        txGalapagosBridge_V_last_V_1_sel_wr <= 1'b0;
    end else begin
        if (((txGalapagosBridge_V_last_V_1_ack_in == 1'b1) & (txGalapagosBridge_V_last_V_1_vld_in == 1'b1))) begin
            txGalapagosBridge_V_last_V_1_sel_wr <= ~txGalapagosBridge_V_last_V_1_sel_wr;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        txGalapagosBridge_V_last_V_1_state <= 2'd0;
    end else begin
        if ((((txGalapagosBridge_V_last_V_1_state == 2'd3) & (txGalapagosBridge_V_last_V_1_vld_in == 1'b0) & (txGalapagosBridge_V_last_V_1_ack_out == 1'b1)) | ((txGalapagosBridge_V_last_V_1_state == 2'd2) & (txGalapagosBridge_V_last_V_1_vld_in == 1'b0)))) begin
            txGalapagosBridge_V_last_V_1_state <= 2'd2;
        end else if ((((txGalapagosBridge_V_last_V_1_state == 2'd1) & (txGalapagosBridge_TREADY == 1'b0)) | ((txGalapagosBridge_V_last_V_1_state == 2'd3) & (txGalapagosBridge_TREADY == 1'b0) & (txGalapagosBridge_V_last_V_1_vld_in == 1'b1)))) begin
            txGalapagosBridge_V_last_V_1_state <= 2'd1;
        end else if ((((txGalapagosBridge_V_last_V_1_state == 2'd1) & (txGalapagosBridge_V_last_V_1_ack_out == 1'b1)) | (~((txGalapagosBridge_V_last_V_1_vld_in == 1'b0) & (txGalapagosBridge_V_last_V_1_ack_out == 1'b1)) & ~((txGalapagosBridge_TREADY == 1'b0) & (txGalapagosBridge_V_last_V_1_vld_in == 1'b1)) & (txGalapagosBridge_V_last_V_1_state == 2'd3)) | ((txGalapagosBridge_V_last_V_1_state == 2'd2) & (txGalapagosBridge_V_last_V_1_vld_in == 1'b1)))) begin
            txGalapagosBridge_V_last_V_1_state <= 2'd3;
        end else begin
            txGalapagosBridge_V_last_V_1_state <= 2'd2;
        end
    end
end

always @ (posedge ap_clk) begin
    if (((tmp_nbreadreq_fu_52_p5 == 1'd1) & (1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        tmp_data_V_reg_151 <= lbRxDataIn_TDATA;
        tmp_keep_V_reg_156 <= lbRxDataIn_TKEEP;
        tmp_last_V_reg_161 <= lbRxDataIn_TLAST;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        tmp_reg_147 <= tmp_nbreadreq_fu_52_p5;
        tmp_reg_147_pp0_iter1_reg <= tmp_reg_147;
    end
end

always @ (posedge ap_clk) begin
    if ((txGalapagosBridge_V_data_V_1_load_A == 1'b1)) begin
        txGalapagosBridge_V_data_V_1_payload_A <= tmp_data_V_reg_151;
    end
end

always @ (posedge ap_clk) begin
    if ((txGalapagosBridge_V_data_V_1_load_B == 1'b1)) begin
        txGalapagosBridge_V_data_V_1_payload_B <= tmp_data_V_reg_151;
    end
end

always @ (posedge ap_clk) begin
    if ((txGalapagosBridge_V_keep_V_1_load_A == 1'b1)) begin
        txGalapagosBridge_V_keep_V_1_payload_A <= tmp_keep_V_reg_156;
    end
end

always @ (posedge ap_clk) begin
    if ((txGalapagosBridge_V_keep_V_1_load_B == 1'b1)) begin
        txGalapagosBridge_V_keep_V_1_payload_B <= tmp_keep_V_reg_156;
    end
end

always @ (posedge ap_clk) begin
    if ((txGalapagosBridge_V_last_V_1_load_A == 1'b1)) begin
        txGalapagosBridge_V_last_V_1_payload_A <= tmp_last_V_reg_161;
    end
end

always @ (posedge ap_clk) begin
    if ((txGalapagosBridge_V_last_V_1_load_B == 1'b1)) begin
        txGalapagosBridge_V_last_V_1_payload_B <= tmp_last_V_reg_161;
    end
end

always @ (*) begin
    if (((ap_enable_reg_pp0_iter2 == 1'b1) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        ap_done = 1'b1;
    end else begin
        ap_done = ap_done_reg;
    end
end

always @ (*) begin
    if (((ap_start == 1'b0) & (ap_idle_pp0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        ap_idle = 1'b1;
    end else begin
        ap_idle = 1'b0;
    end
end

always @ (*) begin
    if (((ap_enable_reg_pp0_iter2 == 1'b0) & (ap_enable_reg_pp0_iter1 == 1'b0) & (ap_enable_reg_pp0_iter0 == 1'b0))) begin
        ap_idle_pp0 = 1'b1;
    end else begin
        ap_idle_pp0 = 1'b0;
    end
end

always @ (*) begin
    if (((ap_enable_reg_pp0_iter1 == 1'b0) & (ap_enable_reg_pp0_iter0 == 1'b0))) begin
        ap_idle_pp0_0to1 = 1'b1;
    end else begin
        ap_idle_pp0_0to1 = 1'b0;
    end
end

always @ (*) begin
    if (((ap_start == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        ap_ready = 1'b1;
    end else begin
        ap_ready = 1'b0;
    end
end

always @ (*) begin
    if (((ap_start == 1'b0) & (ap_idle_pp0_0to1 == 1'b1))) begin
        ap_reset_idle_pp0 = 1'b1;
    end else begin
        ap_reset_idle_pp0 = 1'b0;
    end
end

always @ (*) begin
    if (((tmp_nbreadreq_fu_52_p5 == 1'd1) & (1'b0 == ap_block_pp0_stage0_01001) & (ap_start == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        dest_V = {{lbRxDataIn_TDATA[31:24]}};
    end else begin
        dest_V = dest_V_preg;
    end
end

always @ (*) begin
    if (((tmp_nbreadreq_fu_52_p5 == 1'd1) & (ap_start == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        dest_V_ap_vld = 1'b1;
    end else begin
        dest_V_ap_vld = 1'b0;
    end
end

always @ (*) begin
    if (((tmp_nbreadreq_fu_52_p5 == 1'd1) & (1'b0 == ap_block_pp0_stage0_01001) & (ap_start == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        id_V = {{lbRxDataIn_TDATA[23:16]}};
    end else begin
        id_V = id_V_preg;
    end
end

always @ (*) begin
    if (((tmp_nbreadreq_fu_52_p5 == 1'd1) & (ap_start == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        id_V_ap_vld = 1'b1;
    end else begin
        id_V_ap_vld = 1'b0;
    end
end

always @ (*) begin
    if ((~((ap_start == 1'b0) | (ap_done_reg == 1'b1)) & (tmp_nbreadreq_fu_52_p5 == 1'd1) & (1'b0 == ap_block_pp0_stage0) & (ap_start == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        lbRxDataIn_TDATA_blk_n = lbRxDataIn_TVALID;
    end else begin
        lbRxDataIn_TDATA_blk_n = 1'b1;
    end
end

always @ (*) begin
    if (((tmp_nbreadreq_fu_52_p5 == 1'd1) & (ap_start == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        lbRxDataIn_TREADY = 1'b1;
    end else begin
        lbRxDataIn_TREADY = 1'b0;
    end
end

always @ (*) begin
    if (((tmp_nbreadreq_fu_52_p5 == 1'd1) & (1'b0 == ap_block_pp0_stage0_01001) & (ap_start == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        size_V = trunc_ln647_fu_142_p1;
    end else begin
        size_V = size_V_preg;
    end
end

always @ (*) begin
    if (((tmp_nbreadreq_fu_52_p5 == 1'd1) & (ap_start == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        size_V_ap_vld = 1'b1;
    end else begin
        size_V_ap_vld = 1'b0;
    end
end

always @ (*) begin
    if ((((tmp_reg_147_pp0_iter1_reg == 1'd1) & (1'b0 == ap_block_pp0_stage0) & (ap_enable_reg_pp0_iter2 == 1'b1)) | ((tmp_reg_147 == 1'd1) & (1'b0 == ap_block_pp0_stage0) & (ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0)))) begin
        txGalapagosBridge_TDATA_blk_n = txGalapagosBridge_V_data_V_1_state[1'd1];
    end else begin
        txGalapagosBridge_TDATA_blk_n = 1'b1;
    end
end

always @ (*) begin
    if ((txGalapagosBridge_V_data_V_1_sel == 1'b1)) begin
        txGalapagosBridge_V_data_V_1_data_out = txGalapagosBridge_V_data_V_1_payload_B;
    end else begin
        txGalapagosBridge_V_data_V_1_data_out = txGalapagosBridge_V_data_V_1_payload_A;
    end
end

always @ (*) begin
    if (((tmp_reg_147 == 1'd1) & (ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        txGalapagosBridge_V_data_V_1_vld_in = 1'b1;
    end else begin
        txGalapagosBridge_V_data_V_1_vld_in = 1'b0;
    end
end

always @ (*) begin
    if ((txGalapagosBridge_V_keep_V_1_sel == 1'b1)) begin
        txGalapagosBridge_V_keep_V_1_data_out = txGalapagosBridge_V_keep_V_1_payload_B;
    end else begin
        txGalapagosBridge_V_keep_V_1_data_out = txGalapagosBridge_V_keep_V_1_payload_A;
    end
end

always @ (*) begin
    if (((tmp_reg_147 == 1'd1) & (ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        txGalapagosBridge_V_keep_V_1_vld_in = 1'b1;
    end else begin
        txGalapagosBridge_V_keep_V_1_vld_in = 1'b0;
    end
end

always @ (*) begin
    if ((txGalapagosBridge_V_last_V_1_sel == 1'b1)) begin
        txGalapagosBridge_V_last_V_1_data_out = txGalapagosBridge_V_last_V_1_payload_B;
    end else begin
        txGalapagosBridge_V_last_V_1_data_out = txGalapagosBridge_V_last_V_1_payload_A;
    end
end

always @ (*) begin
    if (((tmp_reg_147 == 1'd1) & (ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        txGalapagosBridge_V_last_V_1_vld_in = 1'b1;
    end else begin
        txGalapagosBridge_V_last_V_1_vld_in = 1'b0;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_pp0_stage0 : begin
            ap_NS_fsm = ap_ST_fsm_pp0_stage0;
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign ap_CS_fsm_pp0_stage0 = ap_CS_fsm[32'd0];

assign ap_block_pp0_stage0 = ~(1'b1 == 1'b1);

always @ (*) begin
    ap_block_pp0_stage0_01001 = ((ap_done_reg == 1'b1) | ((ap_enable_reg_pp0_iter2 == 1'b1) & ((txGalapagosBridge_V_last_V_1_state == 2'd1) | (txGalapagosBridge_V_keep_V_1_state == 2'd1) | (txGalapagosBridge_V_data_V_1_state == 2'd1) | ((txGalapagosBridge_V_last_V_1_state == 2'd3) & (txGalapagosBridge_TREADY == 1'b0)) | ((txGalapagosBridge_V_keep_V_1_state == 2'd3) & (txGalapagosBridge_TREADY == 1'b0)) | ((txGalapagosBridge_V_data_V_1_state == 2'd3) & (txGalapagosBridge_TREADY == 1'b0)))) | ((ap_start == 1'b1) & ((ap_start == 1'b0) | (ap_done_reg == 1'b1) | ((tmp_nbreadreq_fu_52_p5 == 1'd1) & (lbRxDataIn_TVALID == 1'b0)))));
end

always @ (*) begin
    ap_block_pp0_stage0_11001 = ((ap_done_reg == 1'b1) | ((ap_enable_reg_pp0_iter2 == 1'b1) & ((txGalapagosBridge_V_last_V_1_state == 2'd1) | (txGalapagosBridge_V_keep_V_1_state == 2'd1) | (txGalapagosBridge_V_data_V_1_state == 2'd1) | (1'b1 == ap_block_state3_io) | ((txGalapagosBridge_V_last_V_1_state == 2'd3) & (txGalapagosBridge_TREADY == 1'b0)) | ((txGalapagosBridge_V_keep_V_1_state == 2'd3) & (txGalapagosBridge_TREADY == 1'b0)) | ((txGalapagosBridge_V_data_V_1_state == 2'd3) & (txGalapagosBridge_TREADY == 1'b0)))) | ((ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_block_state2_io)) | ((ap_start == 1'b1) & ((ap_start == 1'b0) | (ap_done_reg == 1'b1) | ((tmp_nbreadreq_fu_52_p5 == 1'd1) & (lbRxDataIn_TVALID == 1'b0)))));
end

always @ (*) begin
    ap_block_pp0_stage0_subdone = ((ap_done_reg == 1'b1) | ((ap_enable_reg_pp0_iter2 == 1'b1) & ((txGalapagosBridge_V_last_V_1_state == 2'd1) | (txGalapagosBridge_V_keep_V_1_state == 2'd1) | (txGalapagosBridge_V_data_V_1_state == 2'd1) | (1'b1 == ap_block_state3_io) | ((txGalapagosBridge_V_last_V_1_state == 2'd3) & (txGalapagosBridge_TREADY == 1'b0)) | ((txGalapagosBridge_V_keep_V_1_state == 2'd3) & (txGalapagosBridge_TREADY == 1'b0)) | ((txGalapagosBridge_V_data_V_1_state == 2'd3) & (txGalapagosBridge_TREADY == 1'b0)))) | ((ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_block_state2_io)) | ((ap_start == 1'b1) & ((ap_start == 1'b0) | (ap_done_reg == 1'b1) | ((tmp_nbreadreq_fu_52_p5 == 1'd1) & (lbRxDataIn_TVALID == 1'b0)))));
end

always @ (*) begin
    ap_block_state1_pp0_stage0_iter0 = ((ap_start == 1'b0) | (ap_done_reg == 1'b1) | ((tmp_nbreadreq_fu_52_p5 == 1'd1) & (lbRxDataIn_TVALID == 1'b0)));
end

always @ (*) begin
    ap_block_state2_io = ((tmp_reg_147 == 1'd1) & (txGalapagosBridge_V_data_V_1_ack_in == 1'b0));
end

assign ap_block_state2_pp0_stage0_iter1 = ~(1'b1 == 1'b1);

always @ (*) begin
    ap_block_state3_io = ((tmp_reg_147_pp0_iter1_reg == 1'd1) & (txGalapagosBridge_V_data_V_1_ack_in == 1'b0));
end

always @ (*) begin
    ap_block_state3_pp0_stage0_iter2 = ((txGalapagosBridge_V_last_V_1_state == 2'd1) | (txGalapagosBridge_V_keep_V_1_state == 2'd1) | (txGalapagosBridge_V_data_V_1_state == 2'd1) | ((txGalapagosBridge_V_last_V_1_state == 2'd3) & (txGalapagosBridge_TREADY == 1'b0)) | ((txGalapagosBridge_V_keep_V_1_state == 2'd3) & (txGalapagosBridge_TREADY == 1'b0)) | ((txGalapagosBridge_V_data_V_1_state == 2'd3) & (txGalapagosBridge_TREADY == 1'b0)));
end

assign ap_enable_pp0 = (ap_idle_pp0 ^ 1'b1);

assign ap_enable_reg_pp0_iter0 = ap_start;

assign tmp_nbreadreq_fu_52_p5 = lbRxDataIn_TVALID;

assign trunc_ln647_fu_142_p1 = lbRxDataIn_TDATA[15:0];

assign txGalapagosBridge_TDATA = txGalapagosBridge_V_data_V_1_data_out;

assign txGalapagosBridge_TKEEP = txGalapagosBridge_V_keep_V_1_data_out;

assign txGalapagosBridge_TLAST = txGalapagosBridge_V_last_V_1_data_out;

assign txGalapagosBridge_TVALID = txGalapagosBridge_V_last_V_1_state[1'd0];

assign txGalapagosBridge_V_data_V_1_ack_in = txGalapagosBridge_V_data_V_1_state[1'd1];

assign txGalapagosBridge_V_data_V_1_ack_out = txGalapagosBridge_TREADY;

assign txGalapagosBridge_V_data_V_1_load_A = (txGalapagosBridge_V_data_V_1_state_cmp_full & ~txGalapagosBridge_V_data_V_1_sel_wr);

assign txGalapagosBridge_V_data_V_1_load_B = (txGalapagosBridge_V_data_V_1_state_cmp_full & txGalapagosBridge_V_data_V_1_sel_wr);

assign txGalapagosBridge_V_data_V_1_sel = txGalapagosBridge_V_data_V_1_sel_rd;

assign txGalapagosBridge_V_data_V_1_state_cmp_full = ((txGalapagosBridge_V_data_V_1_state != 2'd1) ? 1'b1 : 1'b0);

assign txGalapagosBridge_V_data_V_1_vld_out = txGalapagosBridge_V_data_V_1_state[1'd0];

assign txGalapagosBridge_V_keep_V_1_ack_in = txGalapagosBridge_V_keep_V_1_state[1'd1];

assign txGalapagosBridge_V_keep_V_1_ack_out = txGalapagosBridge_TREADY;

assign txGalapagosBridge_V_keep_V_1_load_A = (txGalapagosBridge_V_keep_V_1_state_cmp_full & ~txGalapagosBridge_V_keep_V_1_sel_wr);

assign txGalapagosBridge_V_keep_V_1_load_B = (txGalapagosBridge_V_keep_V_1_state_cmp_full & txGalapagosBridge_V_keep_V_1_sel_wr);

assign txGalapagosBridge_V_keep_V_1_sel = txGalapagosBridge_V_keep_V_1_sel_rd;

assign txGalapagosBridge_V_keep_V_1_state_cmp_full = ((txGalapagosBridge_V_keep_V_1_state != 2'd1) ? 1'b1 : 1'b0);

assign txGalapagosBridge_V_keep_V_1_vld_out = txGalapagosBridge_V_keep_V_1_state[1'd0];

assign txGalapagosBridge_V_last_V_1_ack_in = txGalapagosBridge_V_last_V_1_state[1'd1];

assign txGalapagosBridge_V_last_V_1_ack_out = txGalapagosBridge_TREADY;

assign txGalapagosBridge_V_last_V_1_load_A = (txGalapagosBridge_V_last_V_1_state_cmp_full & ~txGalapagosBridge_V_last_V_1_sel_wr);

assign txGalapagosBridge_V_last_V_1_load_B = (txGalapagosBridge_V_last_V_1_state_cmp_full & txGalapagosBridge_V_last_V_1_sel_wr);

assign txGalapagosBridge_V_last_V_1_sel = txGalapagosBridge_V_last_V_1_sel_rd;

assign txGalapagosBridge_V_last_V_1_state_cmp_full = ((txGalapagosBridge_V_last_V_1_state != 2'd1) ? 1'b1 : 1'b0);

assign txGalapagosBridge_V_last_V_1_vld_out = txGalapagosBridge_V_last_V_1_state[1'd0];

endmodule //rxPath
