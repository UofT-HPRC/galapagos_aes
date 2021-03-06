-- ==============================================================
-- RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
-- Version: 2019.1
-- Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
-- 
-- ===========================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity mul_bytes is
port (
    ap_ready : OUT STD_LOGIC;
    a_V : IN STD_LOGIC_VECTOR (4 downto 0);
    b_V : IN STD_LOGIC_VECTOR (7 downto 0);
    ap_return : OUT STD_LOGIC_VECTOR (7 downto 0) );
end;


architecture behav of mul_bytes is 
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_const_boolean_1 : BOOLEAN := true;
    constant ap_const_lv4_0 : STD_LOGIC_VECTOR (3 downto 0) := "0000";
    constant ap_const_lv5_1 : STD_LOGIC_VECTOR (4 downto 0) := "00001";
    constant ap_const_lv32_1 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000001";
    constant ap_const_lv5_0 : STD_LOGIC_VECTOR (4 downto 0) := "00000";
    constant ap_const_lv2_0 : STD_LOGIC_VECTOR (1 downto 0) := "00";
    constant ap_const_lv32_2 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000010";
    constant ap_const_lv6_0 : STD_LOGIC_VECTOR (5 downto 0) := "000000";
    constant ap_const_lv3_0 : STD_LOGIC_VECTOR (2 downto 0) := "000";
    constant ap_const_lv32_3 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000011";
    constant ap_const_lv7_0 : STD_LOGIC_VECTOR (6 downto 0) := "0000000";
    constant ap_const_lv32_4 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000100";
    constant ap_const_lv8_0 : STD_LOGIC_VECTOR (7 downto 0) := "00000000";
    constant ap_const_lv8_1B : STD_LOGIC_VECTOR (7 downto 0) := "00011011";
    constant ap_const_lv32_5 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000101";
    constant ap_const_lv8_1 : STD_LOGIC_VECTOR (7 downto 0) := "00000001";
    constant ap_const_lv32_7 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000111";
    constant ap_const_lv32_6 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000110";
    constant ap_const_logic_0 : STD_LOGIC := '0';

    signal trunc_ln19_fu_66_p1 : STD_LOGIC_VECTOR (0 downto 0);
    signal trunc_ln19_1_fu_70_p1 : STD_LOGIC_VECTOR (3 downto 0);
    signal select_ln19_fu_74_p3 : STD_LOGIC_VECTOR (3 downto 0);
    signal tmp_fu_92_p3 : STD_LOGIC_VECTOR (0 downto 0);
    signal shl_ln841_fu_86_p2 : STD_LOGIC_VECTOR (4 downto 0);
    signal tmp_1_fu_116_p3 : STD_LOGIC_VECTOR (0 downto 0);
    signal shl_ln841_1_fu_108_p3 : STD_LOGIC_VECTOR (5 downto 0);
    signal select_ln19_2_fu_124_p3 : STD_LOGIC_VECTOR (5 downto 0);
    signal tmp_2_fu_144_p3 : STD_LOGIC_VECTOR (0 downto 0);
    signal shl_ln841_2_fu_136_p3 : STD_LOGIC_VECTOR (6 downto 0);
    signal tmp_3_fu_168_p3 : STD_LOGIC_VECTOR (0 downto 0);
    signal shl_ln841_3_fu_160_p3 : STD_LOGIC_VECTOR (7 downto 0);
    signal trunc_ln841_fu_184_p1 : STD_LOGIC_VECTOR (2 downto 0);
    signal shl_ln841_4_fu_188_p3 : STD_LOGIC_VECTOR (7 downto 0);
    signal tmp_4_fu_196_p3 : STD_LOGIC_VECTOR (0 downto 0);
    signal or_ln719_fu_204_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal tmp_5_fu_218_p3 : STD_LOGIC_VECTOR (0 downto 0);
    signal select_ln25_fu_210_p3 : STD_LOGIC_VECTOR (7 downto 0);
    signal shl_ln841_5_fu_234_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal tmp_6_fu_240_p3 : STD_LOGIC_VECTOR (0 downto 0);
    signal xor_ln719_fu_248_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal tmp_7_fu_262_p3 : STD_LOGIC_VECTOR (0 downto 0);
    signal select_ln25_1_fu_254_p3 : STD_LOGIC_VECTOR (7 downto 0);
    signal shl_ln841_6_fu_278_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal tmp_8_fu_284_p3 : STD_LOGIC_VECTOR (0 downto 0);
    signal xor_ln719_1_fu_292_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal tmp_9_fu_306_p3 : STD_LOGIC_VECTOR (0 downto 0);
    signal select_ln25_2_fu_298_p3 : STD_LOGIC_VECTOR (7 downto 0);
    signal zext_ln19_fu_82_p1 : STD_LOGIC_VECTOR (4 downto 0);
    signal select_ln19_1_fu_100_p3 : STD_LOGIC_VECTOR (4 downto 0);
    signal xor_ln19_fu_322_p2 : STD_LOGIC_VECTOR (4 downto 0);
    signal zext_ln19_1_fu_132_p1 : STD_LOGIC_VECTOR (6 downto 0);
    signal select_ln19_3_fu_152_p3 : STD_LOGIC_VECTOR (6 downto 0);
    signal xor_ln19_1_fu_332_p2 : STD_LOGIC_VECTOR (6 downto 0);
    signal zext_ln19_2_fu_328_p1 : STD_LOGIC_VECTOR (6 downto 0);
    signal xor_ln19_2_fu_338_p2 : STD_LOGIC_VECTOR (6 downto 0);
    signal select_ln19_4_fu_176_p3 : STD_LOGIC_VECTOR (7 downto 0);
    signal select_ln19_5_fu_226_p3 : STD_LOGIC_VECTOR (7 downto 0);
    signal select_ln19_6_fu_270_p3 : STD_LOGIC_VECTOR (7 downto 0);
    signal select_ln19_7_fu_314_p3 : STD_LOGIC_VECTOR (7 downto 0);
    signal xor_ln19_4_fu_354_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal xor_ln19_3_fu_348_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal xor_ln19_5_fu_360_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal zext_ln19_3_fu_344_p1 : STD_LOGIC_VECTOR (7 downto 0);


begin



    ap_ready <= ap_const_logic_1;
    ap_return <= (zext_ln19_3_fu_344_p1 xor xor_ln19_5_fu_360_p2);
    or_ln719_fu_204_p2 <= (shl_ln841_4_fu_188_p3 or ap_const_lv8_1B);
    select_ln19_1_fu_100_p3 <= 
        shl_ln841_fu_86_p2 when (tmp_fu_92_p3(0) = '1') else 
        ap_const_lv5_0;
    select_ln19_2_fu_124_p3 <= 
        shl_ln841_1_fu_108_p3 when (tmp_1_fu_116_p3(0) = '1') else 
        ap_const_lv6_0;
    select_ln19_3_fu_152_p3 <= 
        shl_ln841_2_fu_136_p3 when (tmp_2_fu_144_p3(0) = '1') else 
        ap_const_lv7_0;
    select_ln19_4_fu_176_p3 <= 
        shl_ln841_3_fu_160_p3 when (tmp_3_fu_168_p3(0) = '1') else 
        ap_const_lv8_0;
    select_ln19_5_fu_226_p3 <= 
        select_ln25_fu_210_p3 when (tmp_5_fu_218_p3(0) = '1') else 
        ap_const_lv8_0;
    select_ln19_6_fu_270_p3 <= 
        select_ln25_1_fu_254_p3 when (tmp_7_fu_262_p3(0) = '1') else 
        ap_const_lv8_0;
    select_ln19_7_fu_314_p3 <= 
        select_ln25_2_fu_298_p3 when (tmp_9_fu_306_p3(0) = '1') else 
        ap_const_lv8_0;
    select_ln19_fu_74_p3 <= 
        trunc_ln19_1_fu_70_p1 when (trunc_ln19_fu_66_p1(0) = '1') else 
        ap_const_lv4_0;
    select_ln25_1_fu_254_p3 <= 
        xor_ln719_fu_248_p2 when (tmp_6_fu_240_p3(0) = '1') else 
        shl_ln841_5_fu_234_p2;
    select_ln25_2_fu_298_p3 <= 
        xor_ln719_1_fu_292_p2 when (tmp_8_fu_284_p3(0) = '1') else 
        shl_ln841_6_fu_278_p2;
    select_ln25_fu_210_p3 <= 
        or_ln719_fu_204_p2 when (tmp_4_fu_196_p3(0) = '1') else 
        shl_ln841_4_fu_188_p3;
    shl_ln841_1_fu_108_p3 <= (trunc_ln19_1_fu_70_p1 & ap_const_lv2_0);
    shl_ln841_2_fu_136_p3 <= (trunc_ln19_1_fu_70_p1 & ap_const_lv3_0);
    shl_ln841_3_fu_160_p3 <= (trunc_ln19_1_fu_70_p1 & ap_const_lv4_0);
    shl_ln841_4_fu_188_p3 <= (trunc_ln841_fu_184_p1 & ap_const_lv5_0);
    shl_ln841_5_fu_234_p2 <= std_logic_vector(shift_left(unsigned(select_ln25_fu_210_p3),to_integer(unsigned('0' & ap_const_lv8_1(8-1 downto 0)))));
    shl_ln841_6_fu_278_p2 <= std_logic_vector(shift_left(unsigned(select_ln25_1_fu_254_p3),to_integer(unsigned('0' & ap_const_lv8_1(8-1 downto 0)))));
    shl_ln841_fu_86_p2 <= std_logic_vector(shift_left(unsigned(a_V),to_integer(unsigned('0' & ap_const_lv5_1(5-1 downto 0)))));
    tmp_1_fu_116_p3 <= b_V(2 downto 2);
    tmp_2_fu_144_p3 <= b_V(3 downto 3);
    tmp_3_fu_168_p3 <= b_V(4 downto 4);
    tmp_4_fu_196_p3 <= a_V(3 downto 3);
    tmp_5_fu_218_p3 <= b_V(5 downto 5);
    tmp_6_fu_240_p3 <= select_ln25_fu_210_p3(7 downto 7);
    tmp_7_fu_262_p3 <= b_V(6 downto 6);
    tmp_8_fu_284_p3 <= select_ln25_1_fu_254_p3(7 downto 7);
    tmp_9_fu_306_p3 <= b_V(7 downto 7);
    tmp_fu_92_p3 <= b_V(1 downto 1);
    trunc_ln19_1_fu_70_p1 <= a_V(4 - 1 downto 0);
    trunc_ln19_fu_66_p1 <= b_V(1 - 1 downto 0);
    trunc_ln841_fu_184_p1 <= a_V(3 - 1 downto 0);
    xor_ln19_1_fu_332_p2 <= (zext_ln19_1_fu_132_p1 xor select_ln19_3_fu_152_p3);
    xor_ln19_2_fu_338_p2 <= (zext_ln19_2_fu_328_p1 xor xor_ln19_1_fu_332_p2);
    xor_ln19_3_fu_348_p2 <= (select_ln19_5_fu_226_p3 xor select_ln19_4_fu_176_p3);
    xor_ln19_4_fu_354_p2 <= (select_ln19_7_fu_314_p3 xor select_ln19_6_fu_270_p3);
    xor_ln19_5_fu_360_p2 <= (xor_ln19_4_fu_354_p2 xor xor_ln19_3_fu_348_p2);
    xor_ln19_fu_322_p2 <= (zext_ln19_fu_82_p1 xor select_ln19_1_fu_100_p3);
    xor_ln719_1_fu_292_p2 <= (shl_ln841_6_fu_278_p2 xor ap_const_lv8_1B);
    xor_ln719_fu_248_p2 <= (shl_ln841_5_fu_234_p2 xor ap_const_lv8_1B);
    zext_ln19_1_fu_132_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(select_ln19_2_fu_124_p3),7));
    zext_ln19_2_fu_328_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(xor_ln19_fu_322_p2),7));
    zext_ln19_3_fu_344_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(xor_ln19_2_fu_338_p2),8));
    zext_ln19_fu_82_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(select_ln19_fu_74_p3),5));
end behav;
