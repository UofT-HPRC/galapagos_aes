-- ==============================================================
-- RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
-- Version: 2019.1
-- Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
-- 
-- ===========================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity network_bridge_udp_100g is
port (
    rxGalapagosBridge_TDATA : IN STD_LOGIC_VECTOR (511 downto 0);
    rxGalapagosBridge_TKEEP : IN STD_LOGIC_VECTOR (15 downto 0);
    rxGalapagosBridge_TLAST : IN STD_LOGIC_VECTOR (0 downto 0);
    lbRxDataIn_TDATA : IN STD_LOGIC_VECTOR (511 downto 0);
    lbRxDataIn_TKEEP : IN STD_LOGIC_VECTOR (15 downto 0);
    lbRxDataIn_TLAST : IN STD_LOGIC_VECTOR (0 downto 0);
    lbTxDataOut_TDATA : OUT STD_LOGIC_VECTOR (511 downto 0);
    lbTxDataOut_TKEEP : OUT STD_LOGIC_VECTOR (15 downto 0);
    lbTxDataOut_TLAST : OUT STD_LOGIC_VECTOR (0 downto 0);
    txGalapagosBridge_TDATA : OUT STD_LOGIC_VECTOR (511 downto 0);
    txGalapagosBridge_TKEEP : OUT STD_LOGIC_VECTOR (15 downto 0);
    txGalapagosBridge_TLAST : OUT STD_LOGIC_VECTOR (0 downto 0);
    remote_ip_tx_V : OUT STD_LOGIC_VECTOR (31 downto 0);
    tx_state_V : OUT STD_LOGIC_VECTOR (3 downto 0);
    arp_status_V : IN STD_LOGIC_VECTOR (1 downto 0);
    ip_table_V_Addr_A : OUT STD_LOGIC_VECTOR (31 downto 0);
    ip_table_V_EN_A : OUT STD_LOGIC;
    ip_table_V_Din_A : OUT STD_LOGIC_VECTOR (31 downto 0);
    ip_table_V_Dout_A : IN STD_LOGIC_VECTOR (31 downto 0);
    ip_table_V_WEN_A : OUT STD_LOGIC_VECTOR (3 downto 0);
    ip_table_V_Clk_A : OUT STD_LOGIC;
    ap_clk : IN STD_LOGIC;
    ip_table_V_Rst_A : OUT STD_LOGIC;
    ap_rst_n : IN STD_LOGIC;
    ip_table_V_Addr_B : OUT STD_LOGIC_VECTOR (31 downto 0);
    ip_table_V_EN_B : OUT STD_LOGIC;
    ip_table_V_Din_B : OUT STD_LOGIC_VECTOR (31 downto 0);
    ip_table_V_Dout_B : IN STD_LOGIC_VECTOR (31 downto 0);
    ip_table_V_WEN_B : OUT STD_LOGIC_VECTOR (3 downto 0);
    ip_table_V_Clk_B : OUT STD_LOGIC;
    ip_table_V_Rst_B : OUT STD_LOGIC;
    id_V : OUT STD_LOGIC_VECTOR (7 downto 0);
    dest_V : OUT STD_LOGIC_VECTOR (7 downto 0);
    size_V : OUT STD_LOGIC_VECTOR (15 downto 0);
    lbRxDataIn_TVALID : IN STD_LOGIC;
    lbRxDataIn_TREADY : OUT STD_LOGIC;
    txGalapagosBridge_TVALID : OUT STD_LOGIC;
    txGalapagosBridge_TREADY : IN STD_LOGIC;
    id_V_ap_vld : OUT STD_LOGIC;
    dest_V_ap_vld : OUT STD_LOGIC;
    size_V_ap_vld : OUT STD_LOGIC;
    rxGalapagosBridge_TVALID : IN STD_LOGIC;
    rxGalapagosBridge_TREADY : OUT STD_LOGIC;
    lbTxDataOut_TVALID : OUT STD_LOGIC;
    lbTxDataOut_TREADY : IN STD_LOGIC;
    tx_state_V_ap_vld : OUT STD_LOGIC );
end;


architecture behav of network_bridge_udp_100g is 
    attribute CORE_GENERATION_INFO : STRING;
    attribute CORE_GENERATION_INFO of behav : architecture is
    "network_bridge_udp_100g,hls_ip_2019_1,{HLS_INPUT_TYPE=cxx,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=1,HLS_INPUT_PART=xczu19eg-ffvc1760-2-i,HLS_INPUT_CLOCK=3.103000,HLS_INPUT_ARCH=dataflow,HLS_SYN_CLOCK=2.715125,HLS_SYN_LAT=3,HLS_SYN_TPT=2,HLS_SYN_MEM=0,HLS_SYN_DSP=0,HLS_SYN_FF=3860,HLS_SYN_LUT=627,HLS_VERSION=2019_1}";
    constant ap_const_lv512_lc_1 : STD_LOGIC_VECTOR (511 downto 0) := "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
    constant ap_const_lv16_0 : STD_LOGIC_VECTOR (15 downto 0) := "0000000000000000";
    constant ap_const_lv1_0 : STD_LOGIC_VECTOR (0 downto 0) := "0";
    constant ap_const_lv32_0 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000000";
    constant ap_const_lv4_0 : STD_LOGIC_VECTOR (3 downto 0) := "0000";
    constant ap_const_logic_0 : STD_LOGIC := '0';
    constant ap_const_lv8_0 : STD_LOGIC_VECTOR (7 downto 0) := "00000000";
    constant ap_const_logic_1 : STD_LOGIC := '1';

    signal ap_rst_n_inv : STD_LOGIC;
    signal network_bridge_udp_1_2_U0_ap_start : STD_LOGIC;
    signal network_bridge_udp_1_2_U0_ap_done : STD_LOGIC;
    signal network_bridge_udp_1_2_U0_ap_continue : STD_LOGIC;
    signal network_bridge_udp_1_2_U0_ap_idle : STD_LOGIC;
    signal network_bridge_udp_1_2_U0_ap_ready : STD_LOGIC;
    signal network_bridge_udp_1_2_U0_start_out : STD_LOGIC;
    signal network_bridge_udp_1_2_U0_start_write : STD_LOGIC;
    signal network_bridge_udp_1_2_U0_arp_status_V_out_din : STD_LOGIC_VECTOR (1 downto 0);
    signal network_bridge_udp_1_2_U0_arp_status_V_out_write : STD_LOGIC;
    signal network_bridge_udp_1_1_U0_ap_start : STD_LOGIC;
    signal network_bridge_udp_1_1_U0_ap_done : STD_LOGIC;
    signal network_bridge_udp_1_1_U0_ap_continue : STD_LOGIC;
    signal network_bridge_udp_1_1_U0_ap_idle : STD_LOGIC;
    signal network_bridge_udp_1_1_U0_ap_ready : STD_LOGIC;
    signal network_bridge_udp_1_1_U0_arp_status_V_read : STD_LOGIC;
    signal network_bridge_udp_1_1_U0_arp_status_V_out_din : STD_LOGIC_VECTOR (1 downto 0);
    signal network_bridge_udp_1_1_U0_arp_status_V_out_write : STD_LOGIC;
    signal rxPath_U0_ap_start : STD_LOGIC;
    signal rxPath_U0_ap_done : STD_LOGIC;
    signal rxPath_U0_ap_continue : STD_LOGIC;
    signal rxPath_U0_ap_idle : STD_LOGIC;
    signal rxPath_U0_ap_ready : STD_LOGIC;
    signal rxPath_U0_lbRxDataIn_TREADY : STD_LOGIC;
    signal rxPath_U0_txGalapagosBridge_TDATA : STD_LOGIC_VECTOR (511 downto 0);
    signal rxPath_U0_txGalapagosBridge_TVALID : STD_LOGIC;
    signal rxPath_U0_txGalapagosBridge_TKEEP : STD_LOGIC_VECTOR (15 downto 0);
    signal rxPath_U0_txGalapagosBridge_TLAST : STD_LOGIC_VECTOR (0 downto 0);
    signal rxPath_U0_id_V : STD_LOGIC_VECTOR (7 downto 0);
    signal rxPath_U0_id_V_ap_vld : STD_LOGIC;
    signal rxPath_U0_dest_V : STD_LOGIC_VECTOR (7 downto 0);
    signal rxPath_U0_dest_V_ap_vld : STD_LOGIC;
    signal rxPath_U0_size_V : STD_LOGIC_VECTOR (15 downto 0);
    signal rxPath_U0_size_V_ap_vld : STD_LOGIC;
    signal ap_sync_continue : STD_LOGIC;
    signal txPath_U0_ap_start : STD_LOGIC;
    signal txPath_U0_ap_done : STD_LOGIC;
    signal txPath_U0_ap_continue : STD_LOGIC;
    signal txPath_U0_ap_idle : STD_LOGIC;
    signal txPath_U0_ap_ready : STD_LOGIC;
    signal txPath_U0_arp_status_V_read : STD_LOGIC;
    signal txPath_U0_rxGalapagosBridge_TREADY : STD_LOGIC;
    signal txPath_U0_lbTxDataOut_TDATA : STD_LOGIC_VECTOR (511 downto 0);
    signal txPath_U0_lbTxDataOut_TVALID : STD_LOGIC;
    signal txPath_U0_lbTxDataOut_TKEEP : STD_LOGIC_VECTOR (15 downto 0);
    signal txPath_U0_lbTxDataOut_TLAST : STD_LOGIC_VECTOR (0 downto 0);
    signal txPath_U0_remote_ip_tx_V : STD_LOGIC_VECTOR (31 downto 0);
    signal txPath_U0_remote_ip_tx_V_ap_vld : STD_LOGIC;
    signal txPath_U0_tx_state_V : STD_LOGIC_VECTOR (3 downto 0);
    signal txPath_U0_tx_state_V_ap_vld : STD_LOGIC;
    signal txPath_U0_ip_table_V_Addr_A : STD_LOGIC_VECTOR (31 downto 0);
    signal txPath_U0_ip_table_V_EN_A : STD_LOGIC;
    signal txPath_U0_ip_table_V_WEN_A : STD_LOGIC_VECTOR (3 downto 0);
    signal txPath_U0_ip_table_V_Din_A : STD_LOGIC_VECTOR (31 downto 0);
    signal arp_status_V_c1_full_n : STD_LOGIC;
    signal arp_status_V_c1_dout : STD_LOGIC_VECTOR (1 downto 0);
    signal arp_status_V_c1_empty_n : STD_LOGIC;
    signal arp_status_V_c_full_n : STD_LOGIC;
    signal arp_status_V_c_dout : STD_LOGIC_VECTOR (1 downto 0);
    signal arp_status_V_c_empty_n : STD_LOGIC;
    signal start_for_network_bridge_udp_1_1_U0_din : STD_LOGIC_VECTOR (0 downto 0);
    signal start_for_network_bridge_udp_1_1_U0_full_n : STD_LOGIC;
    signal start_for_network_bridge_udp_1_1_U0_dout : STD_LOGIC_VECTOR (0 downto 0);
    signal start_for_network_bridge_udp_1_1_U0_empty_n : STD_LOGIC;
    signal network_bridge_udp_1_1_U0_start_full_n : STD_LOGIC;
    signal network_bridge_udp_1_1_U0_start_write : STD_LOGIC;
    signal rxPath_U0_start_full_n : STD_LOGIC;
    signal rxPath_U0_start_write : STD_LOGIC;
    signal txPath_U0_start_full_n : STD_LOGIC;
    signal txPath_U0_start_write : STD_LOGIC;

    component network_bridge_udp_1_2 IS
    port (
        ap_clk : IN STD_LOGIC;
        ap_rst : IN STD_LOGIC;
        ap_start : IN STD_LOGIC;
        start_full_n : IN STD_LOGIC;
        ap_done : OUT STD_LOGIC;
        ap_continue : IN STD_LOGIC;
        ap_idle : OUT STD_LOGIC;
        ap_ready : OUT STD_LOGIC;
        start_out : OUT STD_LOGIC;
        start_write : OUT STD_LOGIC;
        arp_status_V : IN STD_LOGIC_VECTOR (1 downto 0);
        arp_status_V_out_din : OUT STD_LOGIC_VECTOR (1 downto 0);
        arp_status_V_out_full_n : IN STD_LOGIC;
        arp_status_V_out_write : OUT STD_LOGIC );
    end component;


    component network_bridge_udp_1_1 IS
    port (
        ap_clk : IN STD_LOGIC;
        ap_rst : IN STD_LOGIC;
        ap_start : IN STD_LOGIC;
        ap_done : OUT STD_LOGIC;
        ap_continue : IN STD_LOGIC;
        ap_idle : OUT STD_LOGIC;
        ap_ready : OUT STD_LOGIC;
        arp_status_V_dout : IN STD_LOGIC_VECTOR (1 downto 0);
        arp_status_V_empty_n : IN STD_LOGIC;
        arp_status_V_read : OUT STD_LOGIC;
        arp_status_V_out_din : OUT STD_LOGIC_VECTOR (1 downto 0);
        arp_status_V_out_full_n : IN STD_LOGIC;
        arp_status_V_out_write : OUT STD_LOGIC );
    end component;


    component rxPath IS
    port (
        ap_clk : IN STD_LOGIC;
        ap_rst : IN STD_LOGIC;
        ap_start : IN STD_LOGIC;
        ap_done : OUT STD_LOGIC;
        ap_continue : IN STD_LOGIC;
        ap_idle : OUT STD_LOGIC;
        ap_ready : OUT STD_LOGIC;
        lbRxDataIn_TVALID : IN STD_LOGIC;
        txGalapagosBridge_TREADY : IN STD_LOGIC;
        lbRxDataIn_TDATA : IN STD_LOGIC_VECTOR (511 downto 0);
        lbRxDataIn_TREADY : OUT STD_LOGIC;
        lbRxDataIn_TKEEP : IN STD_LOGIC_VECTOR (15 downto 0);
        lbRxDataIn_TLAST : IN STD_LOGIC_VECTOR (0 downto 0);
        txGalapagosBridge_TDATA : OUT STD_LOGIC_VECTOR (511 downto 0);
        txGalapagosBridge_TVALID : OUT STD_LOGIC;
        txGalapagosBridge_TKEEP : OUT STD_LOGIC_VECTOR (15 downto 0);
        txGalapagosBridge_TLAST : OUT STD_LOGIC_VECTOR (0 downto 0);
        id_V : OUT STD_LOGIC_VECTOR (7 downto 0);
        id_V_ap_vld : OUT STD_LOGIC;
        dest_V : OUT STD_LOGIC_VECTOR (7 downto 0);
        dest_V_ap_vld : OUT STD_LOGIC;
        size_V : OUT STD_LOGIC_VECTOR (15 downto 0);
        size_V_ap_vld : OUT STD_LOGIC );
    end component;


    component txPath IS
    port (
        ap_clk : IN STD_LOGIC;
        ap_rst : IN STD_LOGIC;
        ap_start : IN STD_LOGIC;
        ap_done : OUT STD_LOGIC;
        ap_continue : IN STD_LOGIC;
        ap_idle : OUT STD_LOGIC;
        ap_ready : OUT STD_LOGIC;
        arp_status_V_dout : IN STD_LOGIC_VECTOR (1 downto 0);
        arp_status_V_empty_n : IN STD_LOGIC;
        arp_status_V_read : OUT STD_LOGIC;
        rxGalapagosBridge_TVALID : IN STD_LOGIC;
        lbTxDataOut_TREADY : IN STD_LOGIC;
        rxGalapagosBridge_TDATA : IN STD_LOGIC_VECTOR (511 downto 0);
        rxGalapagosBridge_TREADY : OUT STD_LOGIC;
        rxGalapagosBridge_TKEEP : IN STD_LOGIC_VECTOR (15 downto 0);
        rxGalapagosBridge_TLAST : IN STD_LOGIC_VECTOR (0 downto 0);
        lbTxDataOut_TDATA : OUT STD_LOGIC_VECTOR (511 downto 0);
        lbTxDataOut_TVALID : OUT STD_LOGIC;
        lbTxDataOut_TKEEP : OUT STD_LOGIC_VECTOR (15 downto 0);
        lbTxDataOut_TLAST : OUT STD_LOGIC_VECTOR (0 downto 0);
        remote_ip_tx_V : OUT STD_LOGIC_VECTOR (31 downto 0);
        remote_ip_tx_V_ap_vld : OUT STD_LOGIC;
        tx_state_V : OUT STD_LOGIC_VECTOR (3 downto 0);
        tx_state_V_ap_vld : OUT STD_LOGIC;
        ip_table_V_Addr_A : OUT STD_LOGIC_VECTOR (31 downto 0);
        ip_table_V_EN_A : OUT STD_LOGIC;
        ip_table_V_WEN_A : OUT STD_LOGIC_VECTOR (3 downto 0);
        ip_table_V_Din_A : OUT STD_LOGIC_VECTOR (31 downto 0);
        ip_table_V_Dout_A : IN STD_LOGIC_VECTOR (31 downto 0) );
    end component;


    component fifo_w2_d2_A IS
    port (
        clk : IN STD_LOGIC;
        reset : IN STD_LOGIC;
        if_read_ce : IN STD_LOGIC;
        if_write_ce : IN STD_LOGIC;
        if_din : IN STD_LOGIC_VECTOR (1 downto 0);
        if_full_n : OUT STD_LOGIC;
        if_write : IN STD_LOGIC;
        if_dout : OUT STD_LOGIC_VECTOR (1 downto 0);
        if_empty_n : OUT STD_LOGIC;
        if_read : IN STD_LOGIC );
    end component;


    component start_for_network_bridge_udp_1_1_U0 IS
    port (
        clk : IN STD_LOGIC;
        reset : IN STD_LOGIC;
        if_read_ce : IN STD_LOGIC;
        if_write_ce : IN STD_LOGIC;
        if_din : IN STD_LOGIC_VECTOR (0 downto 0);
        if_full_n : OUT STD_LOGIC;
        if_write : IN STD_LOGIC;
        if_dout : OUT STD_LOGIC_VECTOR (0 downto 0);
        if_empty_n : OUT STD_LOGIC;
        if_read : IN STD_LOGIC );
    end component;



begin
    network_bridge_udp_1_2_U0 : component network_bridge_udp_1_2
    port map (
        ap_clk => ap_clk,
        ap_rst => ap_rst_n_inv,
        ap_start => network_bridge_udp_1_2_U0_ap_start,
        start_full_n => start_for_network_bridge_udp_1_1_U0_full_n,
        ap_done => network_bridge_udp_1_2_U0_ap_done,
        ap_continue => network_bridge_udp_1_2_U0_ap_continue,
        ap_idle => network_bridge_udp_1_2_U0_ap_idle,
        ap_ready => network_bridge_udp_1_2_U0_ap_ready,
        start_out => network_bridge_udp_1_2_U0_start_out,
        start_write => network_bridge_udp_1_2_U0_start_write,
        arp_status_V => arp_status_V,
        arp_status_V_out_din => network_bridge_udp_1_2_U0_arp_status_V_out_din,
        arp_status_V_out_full_n => arp_status_V_c1_full_n,
        arp_status_V_out_write => network_bridge_udp_1_2_U0_arp_status_V_out_write);

    network_bridge_udp_1_1_U0 : component network_bridge_udp_1_1
    port map (
        ap_clk => ap_clk,
        ap_rst => ap_rst_n_inv,
        ap_start => network_bridge_udp_1_1_U0_ap_start,
        ap_done => network_bridge_udp_1_1_U0_ap_done,
        ap_continue => network_bridge_udp_1_1_U0_ap_continue,
        ap_idle => network_bridge_udp_1_1_U0_ap_idle,
        ap_ready => network_bridge_udp_1_1_U0_ap_ready,
        arp_status_V_dout => arp_status_V_c1_dout,
        arp_status_V_empty_n => arp_status_V_c1_empty_n,
        arp_status_V_read => network_bridge_udp_1_1_U0_arp_status_V_read,
        arp_status_V_out_din => network_bridge_udp_1_1_U0_arp_status_V_out_din,
        arp_status_V_out_full_n => arp_status_V_c_full_n,
        arp_status_V_out_write => network_bridge_udp_1_1_U0_arp_status_V_out_write);

    rxPath_U0 : component rxPath
    port map (
        ap_clk => ap_clk,
        ap_rst => ap_rst_n_inv,
        ap_start => rxPath_U0_ap_start,
        ap_done => rxPath_U0_ap_done,
        ap_continue => rxPath_U0_ap_continue,
        ap_idle => rxPath_U0_ap_idle,
        ap_ready => rxPath_U0_ap_ready,
        lbRxDataIn_TVALID => lbRxDataIn_TVALID,
        txGalapagosBridge_TREADY => txGalapagosBridge_TREADY,
        lbRxDataIn_TDATA => lbRxDataIn_TDATA,
        lbRxDataIn_TREADY => rxPath_U0_lbRxDataIn_TREADY,
        lbRxDataIn_TKEEP => lbRxDataIn_TKEEP,
        lbRxDataIn_TLAST => lbRxDataIn_TLAST,
        txGalapagosBridge_TDATA => rxPath_U0_txGalapagosBridge_TDATA,
        txGalapagosBridge_TVALID => rxPath_U0_txGalapagosBridge_TVALID,
        txGalapagosBridge_TKEEP => rxPath_U0_txGalapagosBridge_TKEEP,
        txGalapagosBridge_TLAST => rxPath_U0_txGalapagosBridge_TLAST,
        id_V => rxPath_U0_id_V,
        id_V_ap_vld => rxPath_U0_id_V_ap_vld,
        dest_V => rxPath_U0_dest_V,
        dest_V_ap_vld => rxPath_U0_dest_V_ap_vld,
        size_V => rxPath_U0_size_V,
        size_V_ap_vld => rxPath_U0_size_V_ap_vld);

    txPath_U0 : component txPath
    port map (
        ap_clk => ap_clk,
        ap_rst => ap_rst_n_inv,
        ap_start => txPath_U0_ap_start,
        ap_done => txPath_U0_ap_done,
        ap_continue => txPath_U0_ap_continue,
        ap_idle => txPath_U0_ap_idle,
        ap_ready => txPath_U0_ap_ready,
        arp_status_V_dout => arp_status_V_c_dout,
        arp_status_V_empty_n => arp_status_V_c_empty_n,
        arp_status_V_read => txPath_U0_arp_status_V_read,
        rxGalapagosBridge_TVALID => rxGalapagosBridge_TVALID,
        lbTxDataOut_TREADY => lbTxDataOut_TREADY,
        rxGalapagosBridge_TDATA => rxGalapagosBridge_TDATA,
        rxGalapagosBridge_TREADY => txPath_U0_rxGalapagosBridge_TREADY,
        rxGalapagosBridge_TKEEP => rxGalapagosBridge_TKEEP,
        rxGalapagosBridge_TLAST => rxGalapagosBridge_TLAST,
        lbTxDataOut_TDATA => txPath_U0_lbTxDataOut_TDATA,
        lbTxDataOut_TVALID => txPath_U0_lbTxDataOut_TVALID,
        lbTxDataOut_TKEEP => txPath_U0_lbTxDataOut_TKEEP,
        lbTxDataOut_TLAST => txPath_U0_lbTxDataOut_TLAST,
        remote_ip_tx_V => txPath_U0_remote_ip_tx_V,
        remote_ip_tx_V_ap_vld => txPath_U0_remote_ip_tx_V_ap_vld,
        tx_state_V => txPath_U0_tx_state_V,
        tx_state_V_ap_vld => txPath_U0_tx_state_V_ap_vld,
        ip_table_V_Addr_A => txPath_U0_ip_table_V_Addr_A,
        ip_table_V_EN_A => txPath_U0_ip_table_V_EN_A,
        ip_table_V_WEN_A => txPath_U0_ip_table_V_WEN_A,
        ip_table_V_Din_A => txPath_U0_ip_table_V_Din_A,
        ip_table_V_Dout_A => ip_table_V_Dout_A);

    arp_status_V_c1_U : component fifo_w2_d2_A
    port map (
        clk => ap_clk,
        reset => ap_rst_n_inv,
        if_read_ce => ap_const_logic_1,
        if_write_ce => ap_const_logic_1,
        if_din => network_bridge_udp_1_2_U0_arp_status_V_out_din,
        if_full_n => arp_status_V_c1_full_n,
        if_write => network_bridge_udp_1_2_U0_arp_status_V_out_write,
        if_dout => arp_status_V_c1_dout,
        if_empty_n => arp_status_V_c1_empty_n,
        if_read => network_bridge_udp_1_1_U0_arp_status_V_read);

    arp_status_V_c_U : component fifo_w2_d2_A
    port map (
        clk => ap_clk,
        reset => ap_rst_n_inv,
        if_read_ce => ap_const_logic_1,
        if_write_ce => ap_const_logic_1,
        if_din => network_bridge_udp_1_1_U0_arp_status_V_out_din,
        if_full_n => arp_status_V_c_full_n,
        if_write => network_bridge_udp_1_1_U0_arp_status_V_out_write,
        if_dout => arp_status_V_c_dout,
        if_empty_n => arp_status_V_c_empty_n,
        if_read => txPath_U0_arp_status_V_read);

    start_for_network_bridge_udp_1_1_U0_U : component start_for_network_bridge_udp_1_1_U0
    port map (
        clk => ap_clk,
        reset => ap_rst_n_inv,
        if_read_ce => ap_const_logic_1,
        if_write_ce => ap_const_logic_1,
        if_din => start_for_network_bridge_udp_1_1_U0_din,
        if_full_n => start_for_network_bridge_udp_1_1_U0_full_n,
        if_write => network_bridge_udp_1_2_U0_start_write,
        if_dout => start_for_network_bridge_udp_1_1_U0_dout,
        if_empty_n => start_for_network_bridge_udp_1_1_U0_empty_n,
        if_read => network_bridge_udp_1_1_U0_ap_ready);





    ap_rst_n_inv_assign_proc : process(ap_rst_n)
    begin
                ap_rst_n_inv <= not(ap_rst_n);
    end process;

    ap_sync_continue <= ap_const_logic_0;
    dest_V <= rxPath_U0_dest_V;
    dest_V_ap_vld <= rxPath_U0_dest_V_ap_vld;
    id_V <= rxPath_U0_id_V;
    id_V_ap_vld <= rxPath_U0_id_V_ap_vld;
    ip_table_V_Addr_A <= txPath_U0_ip_table_V_Addr_A;
    ip_table_V_Addr_B <= ap_const_lv32_0;
    ip_table_V_Clk_A <= ap_clk;
    ip_table_V_Clk_B <= ap_clk;
    ip_table_V_Din_A <= ap_const_lv32_0;
    ip_table_V_Din_B <= ap_const_lv32_0;
    ip_table_V_EN_A <= txPath_U0_ip_table_V_EN_A;
    ip_table_V_EN_B <= ap_const_logic_0;
    ip_table_V_Rst_A <= ap_rst_n_inv;
    ip_table_V_Rst_B <= ap_rst_n_inv;
    ip_table_V_WEN_A <= (0=>ap_const_logic_0, others=>'-');
    ip_table_V_WEN_B <= (0=>ap_const_logic_0, others=>'-');
    lbRxDataIn_TREADY <= rxPath_U0_lbRxDataIn_TREADY;
    lbTxDataOut_TDATA <= txPath_U0_lbTxDataOut_TDATA;
    lbTxDataOut_TKEEP <= txPath_U0_lbTxDataOut_TKEEP;
    lbTxDataOut_TLAST <= txPath_U0_lbTxDataOut_TLAST;
    lbTxDataOut_TVALID <= txPath_U0_lbTxDataOut_TVALID;
    network_bridge_udp_1_1_U0_ap_continue <= ap_const_logic_1;
    network_bridge_udp_1_1_U0_ap_start <= start_for_network_bridge_udp_1_1_U0_empty_n;
    network_bridge_udp_1_1_U0_start_full_n <= ap_const_logic_1;
    network_bridge_udp_1_1_U0_start_write <= ap_const_logic_0;
    network_bridge_udp_1_2_U0_ap_continue <= ap_const_logic_1;
    network_bridge_udp_1_2_U0_ap_start <= ap_const_logic_1;
    remote_ip_tx_V <= txPath_U0_remote_ip_tx_V;
    rxGalapagosBridge_TREADY <= txPath_U0_rxGalapagosBridge_TREADY;
    rxPath_U0_ap_continue <= ap_const_logic_1;
    rxPath_U0_ap_start <= ap_const_logic_1;
    rxPath_U0_start_full_n <= ap_const_logic_1;
    rxPath_U0_start_write <= ap_const_logic_0;
    size_V <= rxPath_U0_size_V;
    size_V_ap_vld <= rxPath_U0_size_V_ap_vld;
    start_for_network_bridge_udp_1_1_U0_din <= (0=>ap_const_logic_1, others=>'-');
    txGalapagosBridge_TDATA <= rxPath_U0_txGalapagosBridge_TDATA;
    txGalapagosBridge_TKEEP <= rxPath_U0_txGalapagosBridge_TKEEP;
    txGalapagosBridge_TLAST <= rxPath_U0_txGalapagosBridge_TLAST;
    txGalapagosBridge_TVALID <= rxPath_U0_txGalapagosBridge_TVALID;
    txPath_U0_ap_continue <= ap_const_logic_1;
    txPath_U0_ap_start <= ap_const_logic_1;
    txPath_U0_start_full_n <= ap_const_logic_1;
    txPath_U0_start_write <= ap_const_logic_0;
    tx_state_V <= txPath_U0_tx_state_V;
    tx_state_V_ap_vld <= txPath_U0_tx_state_V_ap_vld;
end behav;
