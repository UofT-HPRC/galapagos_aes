-- ==============================================================
-- RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
-- Version: 2019.1
-- Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
-- 
-- ===========================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity galapagos_bridge is
port (
    g2N_input_TDATA : IN STD_LOGIC_VECTOR (511 downto 0);
    g2N_input_TDEST : IN STD_LOGIC_VECTOR (7 downto 0);
    g2N_input_TLAST : IN STD_LOGIC_VECTOR (0 downto 0);
    g2N_input_TID : IN STD_LOGIC_VECTOR (7 downto 0);
    g2N_input_TUSER : IN STD_LOGIC_VECTOR (15 downto 0);
    g2N_input_TKEEP : IN STD_LOGIC_VECTOR (63 downto 0);
    g2N_output_TDATA : OUT STD_LOGIC_VECTOR (511 downto 0);
    g2N_output_TKEEP : OUT STD_LOGIC_VECTOR (63 downto 0);
    g2N_output_TLAST : OUT STD_LOGIC_VECTOR (0 downto 0);
    g2N_output_TUSER : OUT STD_LOGIC_VECTOR (15 downto 0);
    n2G_input_TDATA : IN STD_LOGIC_VECTOR (511 downto 0);
    n2G_input_TKEEP : IN STD_LOGIC_VECTOR (63 downto 0);
    n2G_input_TLAST : IN STD_LOGIC_VECTOR (0 downto 0);
    n2G_input_TUSER : IN STD_LOGIC_VECTOR (15 downto 0);
    n2G_output_TDATA : OUT STD_LOGIC_VECTOR (511 downto 0);
    n2G_output_TDEST : OUT STD_LOGIC_VECTOR (7 downto 0);
    n2G_output_TLAST : OUT STD_LOGIC_VECTOR (0 downto 0);
    n2G_output_TID : OUT STD_LOGIC_VECTOR (7 downto 0);
    n2G_output_TUSER : OUT STD_LOGIC_VECTOR (15 downto 0);
    n2G_output_TKEEP : OUT STD_LOGIC_VECTOR (63 downto 0);
    ap_clk : IN STD_LOGIC;
    ap_rst_n : IN STD_LOGIC;
    g2N_input_TVALID : IN STD_LOGIC;
    g2N_input_TREADY : OUT STD_LOGIC;
    g2N_output_TVALID : OUT STD_LOGIC;
    g2N_output_TREADY : IN STD_LOGIC;
    n2G_input_TVALID : IN STD_LOGIC;
    n2G_input_TREADY : OUT STD_LOGIC;
    n2G_output_TVALID : OUT STD_LOGIC;
    n2G_output_TREADY : IN STD_LOGIC );
end;


architecture behav of galapagos_bridge is 
    attribute CORE_GENERATION_INFO : STRING;
    attribute CORE_GENERATION_INFO of behav : architecture is
    "galapagos_bridge,hls_ip_2019_1,{HLS_INPUT_TYPE=cxx,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xczu19eg-ffvc1760-2-i,HLS_INPUT_CLOCK=3.103000,HLS_INPUT_ARCH=dataflow,HLS_SYN_CLOCK=1.102000,HLS_SYN_LAT=-1,HLS_SYN_TPT=-1,HLS_SYN_MEM=0,HLS_SYN_DSP=0,HLS_SYN_FF=6044,HLS_SYN_LUT=972,HLS_VERSION=2019_1}";
    constant ap_const_lv512_lc_1 : STD_LOGIC_VECTOR (511 downto 0) := "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
    constant ap_const_lv64_0 : STD_LOGIC_VECTOR (63 downto 0) := "0000000000000000000000000000000000000000000000000000000000000000";
    constant ap_const_lv1_0 : STD_LOGIC_VECTOR (0 downto 0) := "0";
    constant ap_const_lv16_0 : STD_LOGIC_VECTOR (15 downto 0) := "0000000000000000";
    constant ap_const_lv8_0 : STD_LOGIC_VECTOR (7 downto 0) := "00000000";
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_const_logic_0 : STD_LOGIC := '0';

    signal ap_rst_n_inv : STD_LOGIC;
    signal g2N_U0_ap_start : STD_LOGIC;
    signal g2N_U0_ap_done : STD_LOGIC;
    signal g2N_U0_ap_continue : STD_LOGIC;
    signal g2N_U0_ap_idle : STD_LOGIC;
    signal g2N_U0_ap_ready : STD_LOGIC;
    signal g2N_U0_g2N_input_TREADY : STD_LOGIC;
    signal g2N_U0_g2N_output_TDATA : STD_LOGIC_VECTOR (511 downto 0);
    signal g2N_U0_g2N_output_TVALID : STD_LOGIC;
    signal g2N_U0_g2N_output_TKEEP : STD_LOGIC_VECTOR (63 downto 0);
    signal g2N_U0_g2N_output_TLAST : STD_LOGIC_VECTOR (0 downto 0);
    signal g2N_U0_g2N_output_TUSER : STD_LOGIC_VECTOR (15 downto 0);
    signal ap_sync_continue : STD_LOGIC;
    signal n2G_U0_ap_start : STD_LOGIC;
    signal n2G_U0_ap_done : STD_LOGIC;
    signal n2G_U0_ap_continue : STD_LOGIC;
    signal n2G_U0_ap_idle : STD_LOGIC;
    signal n2G_U0_ap_ready : STD_LOGIC;
    signal n2G_U0_n2G_input_TREADY : STD_LOGIC;
    signal n2G_U0_n2G_output_TDATA : STD_LOGIC_VECTOR (511 downto 0);
    signal n2G_U0_n2G_output_TVALID : STD_LOGIC;
    signal n2G_U0_n2G_output_TDEST : STD_LOGIC_VECTOR (7 downto 0);
    signal n2G_U0_n2G_output_TLAST : STD_LOGIC_VECTOR (0 downto 0);
    signal n2G_U0_n2G_output_TID : STD_LOGIC_VECTOR (7 downto 0);
    signal n2G_U0_n2G_output_TUSER : STD_LOGIC_VECTOR (15 downto 0);
    signal n2G_U0_n2G_output_TKEEP : STD_LOGIC_VECTOR (63 downto 0);
    signal g2N_U0_start_full_n : STD_LOGIC;
    signal g2N_U0_start_write : STD_LOGIC;
    signal n2G_U0_start_full_n : STD_LOGIC;
    signal n2G_U0_start_write : STD_LOGIC;

    component g2N IS
    port (
        ap_clk : IN STD_LOGIC;
        ap_rst : IN STD_LOGIC;
        ap_start : IN STD_LOGIC;
        ap_done : OUT STD_LOGIC;
        ap_continue : IN STD_LOGIC;
        ap_idle : OUT STD_LOGIC;
        ap_ready : OUT STD_LOGIC;
        g2N_input_TDATA : IN STD_LOGIC_VECTOR (511 downto 0);
        g2N_input_TVALID : IN STD_LOGIC;
        g2N_input_TREADY : OUT STD_LOGIC;
        g2N_input_TDEST : IN STD_LOGIC_VECTOR (7 downto 0);
        g2N_input_TLAST : IN STD_LOGIC_VECTOR (0 downto 0);
        g2N_input_TID : IN STD_LOGIC_VECTOR (7 downto 0);
        g2N_input_TUSER : IN STD_LOGIC_VECTOR (15 downto 0);
        g2N_input_TKEEP : IN STD_LOGIC_VECTOR (63 downto 0);
        g2N_output_TDATA : OUT STD_LOGIC_VECTOR (511 downto 0);
        g2N_output_TVALID : OUT STD_LOGIC;
        g2N_output_TREADY : IN STD_LOGIC;
        g2N_output_TKEEP : OUT STD_LOGIC_VECTOR (63 downto 0);
        g2N_output_TLAST : OUT STD_LOGIC_VECTOR (0 downto 0);
        g2N_output_TUSER : OUT STD_LOGIC_VECTOR (15 downto 0) );
    end component;


    component n2G IS
    port (
        ap_clk : IN STD_LOGIC;
        ap_rst : IN STD_LOGIC;
        ap_start : IN STD_LOGIC;
        ap_done : OUT STD_LOGIC;
        ap_continue : IN STD_LOGIC;
        ap_idle : OUT STD_LOGIC;
        ap_ready : OUT STD_LOGIC;
        n2G_input_TDATA : IN STD_LOGIC_VECTOR (511 downto 0);
        n2G_input_TVALID : IN STD_LOGIC;
        n2G_input_TREADY : OUT STD_LOGIC;
        n2G_input_TKEEP : IN STD_LOGIC_VECTOR (63 downto 0);
        n2G_input_TLAST : IN STD_LOGIC_VECTOR (0 downto 0);
        n2G_input_TUSER : IN STD_LOGIC_VECTOR (15 downto 0);
        n2G_output_TDATA : OUT STD_LOGIC_VECTOR (511 downto 0);
        n2G_output_TVALID : OUT STD_LOGIC;
        n2G_output_TREADY : IN STD_LOGIC;
        n2G_output_TDEST : OUT STD_LOGIC_VECTOR (7 downto 0);
        n2G_output_TLAST : OUT STD_LOGIC_VECTOR (0 downto 0);
        n2G_output_TID : OUT STD_LOGIC_VECTOR (7 downto 0);
        n2G_output_TUSER : OUT STD_LOGIC_VECTOR (15 downto 0);
        n2G_output_TKEEP : OUT STD_LOGIC_VECTOR (63 downto 0) );
    end component;



begin
    g2N_U0 : component g2N
    port map (
        ap_clk => ap_clk,
        ap_rst => ap_rst_n_inv,
        ap_start => g2N_U0_ap_start,
        ap_done => g2N_U0_ap_done,
        ap_continue => g2N_U0_ap_continue,
        ap_idle => g2N_U0_ap_idle,
        ap_ready => g2N_U0_ap_ready,
        g2N_input_TDATA => g2N_input_TDATA,
        g2N_input_TVALID => g2N_input_TVALID,
        g2N_input_TREADY => g2N_U0_g2N_input_TREADY,
        g2N_input_TDEST => g2N_input_TDEST,
        g2N_input_TLAST => g2N_input_TLAST,
        g2N_input_TID => g2N_input_TID,
        g2N_input_TUSER => g2N_input_TUSER,
        g2N_input_TKEEP => g2N_input_TKEEP,
        g2N_output_TDATA => g2N_U0_g2N_output_TDATA,
        g2N_output_TVALID => g2N_U0_g2N_output_TVALID,
        g2N_output_TREADY => g2N_output_TREADY,
        g2N_output_TKEEP => g2N_U0_g2N_output_TKEEP,
        g2N_output_TLAST => g2N_U0_g2N_output_TLAST,
        g2N_output_TUSER => g2N_U0_g2N_output_TUSER);

    n2G_U0 : component n2G
    port map (
        ap_clk => ap_clk,
        ap_rst => ap_rst_n_inv,
        ap_start => n2G_U0_ap_start,
        ap_done => n2G_U0_ap_done,
        ap_continue => n2G_U0_ap_continue,
        ap_idle => n2G_U0_ap_idle,
        ap_ready => n2G_U0_ap_ready,
        n2G_input_TDATA => n2G_input_TDATA,
        n2G_input_TVALID => n2G_input_TVALID,
        n2G_input_TREADY => n2G_U0_n2G_input_TREADY,
        n2G_input_TKEEP => n2G_input_TKEEP,
        n2G_input_TLAST => n2G_input_TLAST,
        n2G_input_TUSER => n2G_input_TUSER,
        n2G_output_TDATA => n2G_U0_n2G_output_TDATA,
        n2G_output_TVALID => n2G_U0_n2G_output_TVALID,
        n2G_output_TREADY => n2G_output_TREADY,
        n2G_output_TDEST => n2G_U0_n2G_output_TDEST,
        n2G_output_TLAST => n2G_U0_n2G_output_TLAST,
        n2G_output_TID => n2G_U0_n2G_output_TID,
        n2G_output_TUSER => n2G_U0_n2G_output_TUSER,
        n2G_output_TKEEP => n2G_U0_n2G_output_TKEEP);





    ap_rst_n_inv_assign_proc : process(ap_rst_n)
    begin
                ap_rst_n_inv <= not(ap_rst_n);
    end process;

    ap_sync_continue <= ap_const_logic_0;
    g2N_U0_ap_continue <= ap_const_logic_1;
    g2N_U0_ap_start <= ap_const_logic_1;
    g2N_U0_start_full_n <= ap_const_logic_1;
    g2N_U0_start_write <= ap_const_logic_0;
    g2N_input_TREADY <= g2N_U0_g2N_input_TREADY;
    g2N_output_TDATA <= g2N_U0_g2N_output_TDATA;
    g2N_output_TKEEP <= g2N_U0_g2N_output_TKEEP;
    g2N_output_TLAST <= g2N_U0_g2N_output_TLAST;
    g2N_output_TUSER <= g2N_U0_g2N_output_TUSER;
    g2N_output_TVALID <= g2N_U0_g2N_output_TVALID;
    n2G_U0_ap_continue <= ap_const_logic_1;
    n2G_U0_ap_start <= ap_const_logic_1;
    n2G_U0_start_full_n <= ap_const_logic_1;
    n2G_U0_start_write <= ap_const_logic_0;
    n2G_input_TREADY <= n2G_U0_n2G_input_TREADY;
    n2G_output_TDATA <= n2G_U0_n2G_output_TDATA;
    n2G_output_TDEST <= n2G_U0_n2G_output_TDEST;
    n2G_output_TID <= n2G_U0_n2G_output_TID;
    n2G_output_TKEEP <= n2G_U0_n2G_output_TKEEP;
    n2G_output_TLAST <= n2G_U0_n2G_output_TLAST;
    n2G_output_TUSER <= n2G_U0_n2G_output_TUSER;
    n2G_output_TVALID <= n2G_U0_n2G_output_TVALID;
end behav;
