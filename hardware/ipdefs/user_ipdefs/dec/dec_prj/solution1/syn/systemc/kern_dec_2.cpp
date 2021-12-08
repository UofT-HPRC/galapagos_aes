#include "kern_dec.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

void kern_dec::thread_ap_clk_no_reset_() {
    if ( ap_rst_n_inv.read() == ap_const_logic_1) {
        ap_CS_fsm = ap_ST_fsm_state1;
    } else {
        ap_CS_fsm = ap_NS_fsm.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state11.read())) {
        cipherT_V = ap_const_lv128_lc_1;
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_1, icmp_ln100_fu_2639_p2.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_1, tmp_nbreadreq_fu_344_p8.read()) && 
                !(esl_seteq<1,1,1>(ap_const_logic_0, in_r_TVALID.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op98_read_state1.read())) && 
                esl_seteq<1,1,1>(ap_const_lv1_1, icmp_ln108_fu_2955_p2.read()))) {
        cipherT_V = trunc_ln209_fu_2961_p1.read();
    }
    if (esl_seteq<1,1,1>(ap_condition_670.read(), ap_const_boolean_1)) {
        if (esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln108_fu_2955_p2.read())) {
            flag_flag_0_reg_2139 = ap_const_lv1_0;
        } else if (esl_seteq<1,1,1>(ap_const_lv1_1, icmp_ln108_fu_2955_p2.read())) {
            flag_flag_0_reg_2139 = ap_const_lv1_1;
        }
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
         !(esl_seteq<1,1,1>(ap_const_logic_0, in_r_TVALID.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op98_read_state1.read())) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln100_fu_2639_p2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln166_fu_2645_p2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln430_fu_2661_p2.read()))) {
        flag_flag_3_reg_2087 = ap_const_lv1_0;
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state22.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln100_reg_9896.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_1, icmp_ln166_reg_9900.read()) && 
                !(esl_seteq<1,2,2>(out_V_data_V_1_state.read(), ap_const_lv2_1) || esl_seteq<1,2,2>(ap_const_lv2_1, out_V_dest_V_1_state.read()) || esl_seteq<1,2,2>(ap_const_lv2_1, out_V_last_V_1_state.read()) || esl_seteq<1,2,2>(ap_const_lv2_1, out_V_id_V_1_state.read()) || esl_seteq<1,2,2>(ap_const_lv2_1, out_V_user_V_1_state.read()) || esl_seteq<1,2,2>(ap_const_lv2_1, out_V_keep_V_1_state.read()) || (esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
  esl_seteq<1,2,2>(out_V_data_V_1_state.read(), ap_const_lv2_3)) || (esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_3, out_V_dest_V_1_state.read())) || (esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_3, out_V_last_V_1_state.read())) || (esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_3, out_V_id_V_1_state.read())) || (esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_3, out_V_user_V_1_state.read())) || (esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_3, out_V_keep_V_1_state.read())) || esl_seteq<1,1,1>(ap_const_boolean_1, ap_block_state22_io.read())))) {
        flag_flag_3_reg_2087 = ap_const_lv1_1;
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state23.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln144_reg_10036.read()))) {
        flag_flag_4_reg_2099 = flag_flag_0_reg_2139.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state23.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_1, icmp_ln144_reg_10036.read()))) {
        flag_flag_4_reg_2099 = ap_const_lv1_1;
    } else if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
                 !(esl_seteq<1,1,1>(ap_const_logic_0, in_r_TVALID.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op98_read_state1.read())) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln100_fu_2639_p2.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln166_fu_2645_p2.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_1, icmp_ln430_fu_2661_p2.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_1, icmp_ln100_fu_2639_p2.read()) && 
                 !(esl_seteq<1,1,1>(ap_const_logic_0, in_r_TVALID.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op98_read_state1.read())) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, tmp_nbreadreq_fu_344_p8.read())))) {
        flag_flag_4_reg_2099 = ap_const_lv1_0;
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state22.read()) && 
                !(esl_seteq<1,2,2>(out_V_data_V_1_state.read(), ap_const_lv2_1) || esl_seteq<1,2,2>(ap_const_lv2_1, out_V_dest_V_1_state.read()) || esl_seteq<1,2,2>(ap_const_lv2_1, out_V_last_V_1_state.read()) || esl_seteq<1,2,2>(ap_const_lv2_1, out_V_id_V_1_state.read()) || esl_seteq<1,2,2>(ap_const_lv2_1, out_V_user_V_1_state.read()) || esl_seteq<1,2,2>(ap_const_lv2_1, out_V_keep_V_1_state.read()) || (esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
  esl_seteq<1,2,2>(out_V_data_V_1_state.read(), ap_const_lv2_3)) || (esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_3, out_V_dest_V_1_state.read())) || (esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_3, out_V_last_V_1_state.read())) || (esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_3, out_V_id_V_1_state.read())) || (esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_3, out_V_user_V_1_state.read())) || (esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_3, out_V_keep_V_1_state.read())) || esl_seteq<1,1,1>(ap_const_boolean_1, ap_block_state22_io.read())) && 
                ((esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln100_reg_9896.read()) && 
                  esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln430_reg_9904.read())) || 
                 (esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln100_reg_9896.read()) && 
                  esl_seteq<1,1,1>(ap_const_lv1_1, icmp_ln166_reg_9900.read()))))) {
        flag_flag_4_reg_2099 = ap_phi_mux_flag_flag_3_phi_fu_2091_p4.read();
    }
    if (esl_seteq<1,1,1>(ap_condition_670.read(), ap_const_boolean_1)) {
        if (esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln108_fu_2955_p2.read())) {
            flag_load_2_reg_2154 = flag.read();
        } else if (esl_seteq<1,1,1>(ap_const_lv1_1, icmp_ln108_fu_2955_p2.read())) {
            flag_load_2_reg_2154 = add_ln142_fu_2971_p2.read();
        }
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state23.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln144_reg_10036.read()))) {
        flag_new_4_reg_2120 = flag_load_2_reg_2154.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state23.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_1, icmp_ln144_reg_10036.read()))) {
        flag_new_4_reg_2120 = add_ln162_fu_9885_p2.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state22.read()) && 
                !(esl_seteq<1,2,2>(out_V_data_V_1_state.read(), ap_const_lv2_1) || esl_seteq<1,2,2>(ap_const_lv2_1, out_V_dest_V_1_state.read()) || esl_seteq<1,2,2>(ap_const_lv2_1, out_V_last_V_1_state.read()) || esl_seteq<1,2,2>(ap_const_lv2_1, out_V_id_V_1_state.read()) || esl_seteq<1,2,2>(ap_const_lv2_1, out_V_user_V_1_state.read()) || esl_seteq<1,2,2>(ap_const_lv2_1, out_V_keep_V_1_state.read()) || (esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
  esl_seteq<1,2,2>(out_V_data_V_1_state.read(), ap_const_lv2_3)) || (esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_3, out_V_dest_V_1_state.read())) || (esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_3, out_V_last_V_1_state.read())) || (esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_3, out_V_id_V_1_state.read())) || (esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_3, out_V_user_V_1_state.read())) || (esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_3, out_V_keep_V_1_state.read())) || esl_seteq<1,1,1>(ap_const_boolean_1, ap_block_state22_io.read())) && 
                ((esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln100_reg_9896.read()) && 
                  esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln430_reg_9904.read())) || 
                 (esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln100_reg_9896.read()) && 
                  esl_seteq<1,1,1>(ap_const_lv1_1, icmp_ln166_reg_9900.read()))))) {
        flag_new_4_reg_2120 = ap_const_lv32_18;
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state23.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, icmp_ln144_reg_10036.read()))) {
        keyT_V = trunc_ln209_1_fu_9876_p1.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
                !(esl_seteq<1,1,1>(ap_const_logic_0, in_r_TVALID.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op98_read_state1.read())) && 
                esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln100_fu_2639_p2.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_1, icmp_ln166_fu_2645_p2.read()))) {
        keyT_V = ap_const_lv128_lc_1;
    }
    if ( ap_rst_n_inv.read() == ap_const_logic_1) {
        out_V_data_V_1_sel_rd = ap_const_logic_0;
    } else {
        if ((esl_seteq<1,1,1>(ap_const_logic_1, out_V_data_V_1_ack_out.read()) && 
             esl_seteq<1,1,1>(ap_const_logic_1, out_V_data_V_1_vld_out.read()))) {
            out_V_data_V_1_sel_rd =  (sc_logic) (~out_V_data_V_1_sel_rd.read());
        }
    }
    if ( ap_rst_n_inv.read() == ap_const_logic_1) {
        out_V_data_V_1_sel_wr = ap_const_logic_0;
    } else {
        if ((esl_seteq<1,1,1>(ap_const_logic_1, out_V_data_V_1_vld_in.read()) && 
             esl_seteq<1,1,1>(ap_const_logic_1, out_V_data_V_1_ack_in.read()))) {
            out_V_data_V_1_sel_wr =  (sc_logic) (~out_V_data_V_1_sel_wr.read());
        }
    }
    if ( ap_rst_n_inv.read() == ap_const_logic_1) {
        out_V_data_V_1_state = ap_const_lv2_0;
    } else {
        if (((esl_seteq<1,1,1>(ap_const_logic_0, out_V_data_V_1_vld_in.read()) && 
              esl_seteq<1,1,1>(ap_const_logic_1, out_V_data_V_1_ack_out.read()) && 
              esl_seteq<1,2,2>(out_V_data_V_1_state.read(), ap_const_lv2_3)) || 
             (esl_seteq<1,1,1>(ap_const_logic_0, out_V_data_V_1_vld_in.read()) && 
              esl_seteq<1,2,2>(out_V_data_V_1_state.read(), ap_const_lv2_2)))) {
            out_V_data_V_1_state = ap_const_lv2_2;
        } else if (((esl_seteq<1,1,1>(ap_const_logic_1, out_V_data_V_1_vld_in.read()) && 
                     esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
                     esl_seteq<1,2,2>(out_V_data_V_1_state.read(), ap_const_lv2_3)) || 
                    (esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
                     esl_seteq<1,2,2>(out_V_data_V_1_state.read(), ap_const_lv2_1)))) {
            out_V_data_V_1_state = ap_const_lv2_1;
        } else if (((esl_seteq<1,1,1>(ap_const_logic_1, out_V_data_V_1_vld_in.read()) && 
                     esl_seteq<1,2,2>(out_V_data_V_1_state.read(), ap_const_lv2_2)) || 
                    (esl_seteq<1,1,1>(ap_const_logic_1, out_V_data_V_1_ack_out.read()) && 
                     esl_seteq<1,2,2>(out_V_data_V_1_state.read(), ap_const_lv2_1)) || 
                    (esl_seteq<1,2,2>(out_V_data_V_1_state.read(), ap_const_lv2_3) && 
                     !(esl_seteq<1,1,1>(ap_const_logic_1, out_V_data_V_1_vld_in.read()) && esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read())) && 
                     !(esl_seteq<1,1,1>(ap_const_logic_0, out_V_data_V_1_vld_in.read()) && esl_seteq<1,1,1>(ap_const_logic_1, out_V_data_V_1_ack_out.read()))))) {
            out_V_data_V_1_state = ap_const_lv2_3;
        } else {
            out_V_data_V_1_state = ap_const_lv2_2;
        }
    }
    if ( ap_rst_n_inv.read() == ap_const_logic_1) {
        out_V_dest_V_1_sel_rd = ap_const_logic_0;
    } else {
        if ((esl_seteq<1,1,1>(ap_const_logic_1, out_V_dest_V_1_ack_out.read()) && 
             esl_seteq<1,1,1>(ap_const_logic_1, out_V_dest_V_1_vld_out.read()))) {
            out_V_dest_V_1_sel_rd =  (sc_logic) (~out_V_dest_V_1_sel_rd.read());
        }
    }
    if ( ap_rst_n_inv.read() == ap_const_logic_1) {
        out_V_dest_V_1_state = ap_const_lv2_0;
    } else {
        if (((esl_seteq<1,1,1>(ap_const_logic_0, out_V_dest_V_1_vld_in.read()) && 
              esl_seteq<1,1,1>(ap_const_logic_1, out_V_dest_V_1_ack_out.read()) && 
              esl_seteq<1,2,2>(ap_const_lv2_3, out_V_dest_V_1_state.read())) || 
             (esl_seteq<1,1,1>(ap_const_logic_0, out_V_dest_V_1_vld_in.read()) && 
              esl_seteq<1,2,2>(ap_const_lv2_2, out_V_dest_V_1_state.read())))) {
            out_V_dest_V_1_state = ap_const_lv2_2;
        } else if (((esl_seteq<1,1,1>(ap_const_logic_1, out_V_dest_V_1_vld_in.read()) && 
                     esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
                     esl_seteq<1,2,2>(ap_const_lv2_3, out_V_dest_V_1_state.read())) || 
                    (esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
                     esl_seteq<1,2,2>(ap_const_lv2_1, out_V_dest_V_1_state.read())))) {
            out_V_dest_V_1_state = ap_const_lv2_1;
        } else if (((esl_seteq<1,1,1>(ap_const_logic_1, out_V_dest_V_1_vld_in.read()) && 
                     esl_seteq<1,2,2>(ap_const_lv2_2, out_V_dest_V_1_state.read())) || 
                    (esl_seteq<1,1,1>(ap_const_logic_1, out_V_dest_V_1_ack_out.read()) && 
                     esl_seteq<1,2,2>(ap_const_lv2_1, out_V_dest_V_1_state.read())) || 
                    (esl_seteq<1,2,2>(ap_const_lv2_3, out_V_dest_V_1_state.read()) && 
                     !(esl_seteq<1,1,1>(ap_const_logic_1, out_V_dest_V_1_vld_in.read()) && esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read())) && 
                     !(esl_seteq<1,1,1>(ap_const_logic_0, out_V_dest_V_1_vld_in.read()) && esl_seteq<1,1,1>(ap_const_logic_1, out_V_dest_V_1_ack_out.read()))))) {
            out_V_dest_V_1_state = ap_const_lv2_3;
        } else {
            out_V_dest_V_1_state = ap_const_lv2_2;
        }
    }
    if ( ap_rst_n_inv.read() == ap_const_logic_1) {
        out_V_id_V_1_sel_rd = ap_const_logic_0;
    } else {
        if ((esl_seteq<1,1,1>(ap_const_logic_1, out_V_id_V_1_ack_out.read()) && 
             esl_seteq<1,1,1>(ap_const_logic_1, out_V_id_V_1_vld_out.read()))) {
            out_V_id_V_1_sel_rd =  (sc_logic) (~out_V_id_V_1_sel_rd.read());
        }
    }
    if ( ap_rst_n_inv.read() == ap_const_logic_1) {
        out_V_id_V_1_state = ap_const_lv2_0;
    } else {
        if (((esl_seteq<1,1,1>(ap_const_logic_0, out_V_id_V_1_vld_in.read()) && 
              esl_seteq<1,1,1>(ap_const_logic_1, out_V_id_V_1_ack_out.read()) && 
              esl_seteq<1,2,2>(ap_const_lv2_3, out_V_id_V_1_state.read())) || 
             (esl_seteq<1,1,1>(ap_const_logic_0, out_V_id_V_1_vld_in.read()) && 
              esl_seteq<1,2,2>(ap_const_lv2_2, out_V_id_V_1_state.read())))) {
            out_V_id_V_1_state = ap_const_lv2_2;
        } else if (((esl_seteq<1,1,1>(ap_const_logic_1, out_V_id_V_1_vld_in.read()) && 
                     esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
                     esl_seteq<1,2,2>(ap_const_lv2_3, out_V_id_V_1_state.read())) || 
                    (esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
                     esl_seteq<1,2,2>(ap_const_lv2_1, out_V_id_V_1_state.read())))) {
            out_V_id_V_1_state = ap_const_lv2_1;
        } else if (((esl_seteq<1,1,1>(ap_const_logic_1, out_V_id_V_1_vld_in.read()) && 
                     esl_seteq<1,2,2>(ap_const_lv2_2, out_V_id_V_1_state.read())) || 
                    (esl_seteq<1,1,1>(ap_const_logic_1, out_V_id_V_1_ack_out.read()) && 
                     esl_seteq<1,2,2>(ap_const_lv2_1, out_V_id_V_1_state.read())) || 
                    (esl_seteq<1,2,2>(ap_const_lv2_3, out_V_id_V_1_state.read()) && 
                     !(esl_seteq<1,1,1>(ap_const_logic_1, out_V_id_V_1_vld_in.read()) && esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read())) && 
                     !(esl_seteq<1,1,1>(ap_const_logic_0, out_V_id_V_1_vld_in.read()) && esl_seteq<1,1,1>(ap_const_logic_1, out_V_id_V_1_ack_out.read()))))) {
            out_V_id_V_1_state = ap_const_lv2_3;
        } else {
            out_V_id_V_1_state = ap_const_lv2_2;
        }
    }
    if ( ap_rst_n_inv.read() == ap_const_logic_1) {
        out_V_keep_V_1_sel_rd = ap_const_logic_0;
    } else {
        if ((esl_seteq<1,1,1>(ap_const_logic_1, out_V_keep_V_1_ack_out.read()) && 
             esl_seteq<1,1,1>(ap_const_logic_1, out_V_keep_V_1_vld_out.read()))) {
            out_V_keep_V_1_sel_rd =  (sc_logic) (~out_V_keep_V_1_sel_rd.read());
        }
    }
    if ( ap_rst_n_inv.read() == ap_const_logic_1) {
        out_V_keep_V_1_state = ap_const_lv2_0;
    } else {
        if (((esl_seteq<1,1,1>(ap_const_logic_0, out_V_keep_V_1_vld_in.read()) && 
              esl_seteq<1,1,1>(ap_const_logic_1, out_V_keep_V_1_ack_out.read()) && 
              esl_seteq<1,2,2>(ap_const_lv2_3, out_V_keep_V_1_state.read())) || 
             (esl_seteq<1,1,1>(ap_const_logic_0, out_V_keep_V_1_vld_in.read()) && 
              esl_seteq<1,2,2>(ap_const_lv2_2, out_V_keep_V_1_state.read())))) {
            out_V_keep_V_1_state = ap_const_lv2_2;
        } else if (((esl_seteq<1,1,1>(ap_const_logic_1, out_V_keep_V_1_vld_in.read()) && 
                     esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
                     esl_seteq<1,2,2>(ap_const_lv2_3, out_V_keep_V_1_state.read())) || 
                    (esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
                     esl_seteq<1,2,2>(ap_const_lv2_1, out_V_keep_V_1_state.read())))) {
            out_V_keep_V_1_state = ap_const_lv2_1;
        } else if (((esl_seteq<1,1,1>(ap_const_logic_1, out_V_keep_V_1_vld_in.read()) && 
                     esl_seteq<1,2,2>(ap_const_lv2_2, out_V_keep_V_1_state.read())) || 
                    (esl_seteq<1,1,1>(ap_const_logic_1, out_V_keep_V_1_ack_out.read()) && 
                     esl_seteq<1,2,2>(ap_const_lv2_1, out_V_keep_V_1_state.read())) || 
                    (esl_seteq<1,2,2>(ap_const_lv2_3, out_V_keep_V_1_state.read()) && 
                     !(esl_seteq<1,1,1>(ap_const_logic_1, out_V_keep_V_1_vld_in.read()) && esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read())) && 
                     !(esl_seteq<1,1,1>(ap_const_logic_0, out_V_keep_V_1_vld_in.read()) && esl_seteq<1,1,1>(ap_const_logic_1, out_V_keep_V_1_ack_out.read()))))) {
            out_V_keep_V_1_state = ap_const_lv2_3;
        } else {
            out_V_keep_V_1_state = ap_const_lv2_2;
        }
    }
    if ( ap_rst_n_inv.read() == ap_const_logic_1) {
        out_V_last_V_1_sel_rd = ap_const_logic_0;
    } else {
        if ((esl_seteq<1,1,1>(ap_const_logic_1, out_V_last_V_1_ack_out.read()) && 
             esl_seteq<1,1,1>(ap_const_logic_1, out_V_last_V_1_vld_out.read()))) {
            out_V_last_V_1_sel_rd =  (sc_logic) (~out_V_last_V_1_sel_rd.read());
        }
    }
    if ( ap_rst_n_inv.read() == ap_const_logic_1) {
        out_V_last_V_1_state = ap_const_lv2_0;
    } else {
        if (((esl_seteq<1,1,1>(ap_const_logic_0, out_V_last_V_1_vld_in.read()) && 
              esl_seteq<1,1,1>(ap_const_logic_1, out_V_last_V_1_ack_out.read()) && 
              esl_seteq<1,2,2>(ap_const_lv2_3, out_V_last_V_1_state.read())) || 
             (esl_seteq<1,1,1>(ap_const_logic_0, out_V_last_V_1_vld_in.read()) && 
              esl_seteq<1,2,2>(ap_const_lv2_2, out_V_last_V_1_state.read())))) {
            out_V_last_V_1_state = ap_const_lv2_2;
        } else if (((esl_seteq<1,1,1>(ap_const_logic_1, out_V_last_V_1_vld_in.read()) && 
                     esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
                     esl_seteq<1,2,2>(ap_const_lv2_3, out_V_last_V_1_state.read())) || 
                    (esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
                     esl_seteq<1,2,2>(ap_const_lv2_1, out_V_last_V_1_state.read())))) {
            out_V_last_V_1_state = ap_const_lv2_1;
        } else if (((esl_seteq<1,1,1>(ap_const_logic_1, out_V_last_V_1_vld_in.read()) && 
                     esl_seteq<1,2,2>(ap_const_lv2_2, out_V_last_V_1_state.read())) || 
                    (esl_seteq<1,1,1>(ap_const_logic_1, out_V_last_V_1_ack_out.read()) && 
                     esl_seteq<1,2,2>(ap_const_lv2_1, out_V_last_V_1_state.read())) || 
                    (esl_seteq<1,2,2>(ap_const_lv2_3, out_V_last_V_1_state.read()) && 
                     !(esl_seteq<1,1,1>(ap_const_logic_1, out_V_last_V_1_vld_in.read()) && esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read())) && 
                     !(esl_seteq<1,1,1>(ap_const_logic_0, out_V_last_V_1_vld_in.read()) && esl_seteq<1,1,1>(ap_const_logic_1, out_V_last_V_1_ack_out.read()))))) {
            out_V_last_V_1_state = ap_const_lv2_3;
        } else {
            out_V_last_V_1_state = ap_const_lv2_2;
        }
    }
    if ( ap_rst_n_inv.read() == ap_const_logic_1) {
        out_V_user_V_1_sel_rd = ap_const_logic_0;
    } else {
        if ((esl_seteq<1,1,1>(ap_const_logic_1, out_V_user_V_1_ack_out.read()) && 
             esl_seteq<1,1,1>(ap_const_logic_1, out_V_user_V_1_vld_out.read()))) {
            out_V_user_V_1_sel_rd =  (sc_logic) (~out_V_user_V_1_sel_rd.read());
        }
    }
    if ( ap_rst_n_inv.read() == ap_const_logic_1) {
        out_V_user_V_1_state = ap_const_lv2_0;
    } else {
        if (((esl_seteq<1,1,1>(ap_const_logic_0, out_V_user_V_1_vld_in.read()) && 
              esl_seteq<1,1,1>(ap_const_logic_1, out_V_user_V_1_ack_out.read()) && 
              esl_seteq<1,2,2>(ap_const_lv2_3, out_V_user_V_1_state.read())) || 
             (esl_seteq<1,1,1>(ap_const_logic_0, out_V_user_V_1_vld_in.read()) && 
              esl_seteq<1,2,2>(ap_const_lv2_2, out_V_user_V_1_state.read())))) {
            out_V_user_V_1_state = ap_const_lv2_2;
        } else if (((esl_seteq<1,1,1>(ap_const_logic_1, out_V_user_V_1_vld_in.read()) && 
                     esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
                     esl_seteq<1,2,2>(ap_const_lv2_3, out_V_user_V_1_state.read())) || 
                    (esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
                     esl_seteq<1,2,2>(ap_const_lv2_1, out_V_user_V_1_state.read())))) {
            out_V_user_V_1_state = ap_const_lv2_1;
        } else if (((esl_seteq<1,1,1>(ap_const_logic_1, out_V_user_V_1_vld_in.read()) && 
                     esl_seteq<1,2,2>(ap_const_lv2_2, out_V_user_V_1_state.read())) || 
                    (esl_seteq<1,1,1>(ap_const_logic_1, out_V_user_V_1_ack_out.read()) && 
                     esl_seteq<1,2,2>(ap_const_lv2_1, out_V_user_V_1_state.read())) || 
                    (esl_seteq<1,2,2>(ap_const_lv2_3, out_V_user_V_1_state.read()) && 
                     !(esl_seteq<1,1,1>(ap_const_logic_1, out_V_user_V_1_vld_in.read()) && esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read())) && 
                     !(esl_seteq<1,1,1>(ap_const_logic_0, out_V_user_V_1_vld_in.read()) && esl_seteq<1,1,1>(ap_const_logic_1, out_V_user_V_1_ack_out.read()))))) {
            out_V_user_V_1_state = ap_const_lv2_3;
        } else {
            out_V_user_V_1_state = ap_const_lv2_2;
        }
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state22.read()) && !(esl_seteq<1,2,2>(out_V_data_V_1_state.read(), ap_const_lv2_1) || esl_seteq<1,2,2>(ap_const_lv2_1, out_V_dest_V_1_state.read()) || esl_seteq<1,2,2>(ap_const_lv2_1, out_V_last_V_1_state.read()) || esl_seteq<1,2,2>(ap_const_lv2_1, out_V_id_V_1_state.read()) || esl_seteq<1,2,2>(ap_const_lv2_1, out_V_user_V_1_state.read()) || esl_seteq<1,2,2>(ap_const_lv2_1, out_V_keep_V_1_state.read()) || (esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
  esl_seteq<1,2,2>(out_V_data_V_1_state.read(), ap_const_lv2_3)) || (esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_3, out_V_dest_V_1_state.read())) || (esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_3, out_V_last_V_1_state.read())) || (esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_3, out_V_id_V_1_state.read())) || (esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_3, out_V_user_V_1_state.read())) || (esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_3, out_V_keep_V_1_state.read())) || esl_seteq<1,1,1>(ap_const_boolean_1, ap_block_state22_io.read())) && esl_seteq<1,1,1>(ap_const_lv1_1, ap_phi_mux_flag_flag_4_phi_fu_2104_p10.read()))) {
        flag = ap_phi_mux_flag_new_4_phi_fu_2124_p10.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && !(esl_seteq<1,1,1>(ap_const_logic_0, in_r_TVALID.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op98_read_state1.read())))) {
        icmp_ln100_reg_9896 = icmp_ln100_fu_2639_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && esl_seteq<1,1,1>(ap_const_lv1_1, icmp_ln100_fu_2639_p2.read()) && esl_seteq<1,1,1>(ap_const_lv1_1, tmp_nbreadreq_fu_344_p8.read()) && !(esl_seteq<1,1,1>(ap_const_logic_0, in_r_TVALID.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op98_read_state1.read())))) {
        icmp_ln144_reg_10036 = icmp_ln144_fu_2977_p2.read();
        tmp_data_V_reg_10023 = in_r_TDATA.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && !(esl_seteq<1,1,1>(ap_const_logic_0, in_r_TVALID.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op98_read_state1.read())) && esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln100_fu_2639_p2.read()))) {
        icmp_ln166_reg_9900 = icmp_ln166_fu_2645_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && !(esl_seteq<1,1,1>(ap_const_logic_0, in_r_TVALID.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op98_read_state1.read())) && esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln100_fu_2639_p2.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln166_fu_2645_p2.read()))) {
        icmp_ln430_reg_9904 = icmp_ln430_fu_2661_p2.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state5.read())) {
        inv_keys_V_100 = xor_ln1357_52_fu_3563_p2.read();
        inv_keys_V_101 = xor_ln1357_53_fu_3568_p2.read();
        inv_keys_V_102 = xor_ln1357_54_fu_3573_p2.read();
        inv_keys_V_103 = xor_ln1357_55_fu_3578_p2.read();
        inv_keys_V_104 = xor_ln1357_56_fu_3583_p2.read();
        inv_keys_V_105 = xor_ln1357_57_fu_3588_p2.read();
        inv_keys_V_106 = xor_ln1357_58_fu_3593_p2.read();
        inv_keys_V_107 = xor_ln1357_59_fu_3598_p2.read();
        inv_keys_V_108 = xor_ln1357_60_fu_3603_p2.read();
        inv_keys_V_109 = xor_ln1357_61_fu_3608_p2.read();
        inv_keys_V_110 = xor_ln1357_62_fu_3613_p2.read();
        inv_keys_V_111 = xor_ln1357_63_fu_3618_p2.read();
        inv_keys_V_112 = xor_ln1357_32_reg_10188.read();
        inv_keys_V_113 = xor_ln1357_33_reg_10195.read();
        inv_keys_V_114 = xor_ln1357_34_reg_10202.read();
        inv_keys_V_115 = xor_ln1357_35_reg_10209.read();
        inv_keys_V_116 = xor_ln1357_36_fu_3521_p2.read();
        inv_keys_V_117 = xor_ln1357_37_fu_3525_p2.read();
        inv_keys_V_118 = xor_ln1357_38_fu_3529_p2.read();
        inv_keys_V_119 = xor_ln1357_39_fu_3533_p2.read();
        xor_ln1357_48_reg_10260 = xor_ln1357_48_fu_3543_p2.read();
        xor_ln1357_49_reg_10266 = xor_ln1357_49_fu_3548_p2.read();
        xor_ln1357_50_reg_10272 = xor_ln1357_50_fu_3553_p2.read();
        xor_ln1357_51_reg_10278 = xor_ln1357_51_fu_3558_p2.read();
        xor_ln1357_52_reg_10284 = xor_ln1357_52_fu_3563_p2.read();
        xor_ln1357_53_reg_10290 = xor_ln1357_53_fu_3568_p2.read();
        xor_ln1357_54_reg_10296 = xor_ln1357_54_fu_3573_p2.read();
        xor_ln1357_55_reg_10302 = xor_ln1357_55_fu_3578_p2.read();
        xor_ln1357_60_reg_10308 = xor_ln1357_60_fu_3603_p2.read();
        xor_ln1357_61_reg_10315 = xor_ln1357_61_fu_3608_p2.read();
        xor_ln1357_62_reg_10322 = xor_ln1357_62_fu_3613_p2.read();
        xor_ln1357_63_reg_10329 = xor_ln1357_63_fu_3618_p2.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read())) {
        inv_keys_V_120 = xor_ln1357_40_fu_3413_p2.read();
        inv_keys_V_121 = xor_ln1357_41_fu_3418_p2.read();
        inv_keys_V_122 = xor_ln1357_42_fu_3423_p2.read();
        inv_keys_V_123 = xor_ln1357_43_fu_3428_p2.read();
        inv_keys_V_124 = xor_ln1357_44_fu_3433_p2.read();
        inv_keys_V_125 = xor_ln1357_45_fu_3438_p2.read();
        inv_keys_V_126 = xor_ln1357_46_fu_3443_p2.read();
        inv_keys_V_127 = xor_ln1357_47_fu_3448_p2.read();
        xor_ln1357_32_reg_10188 = xor_ln1357_32_fu_3392_p2.read();
        xor_ln1357_33_reg_10195 = xor_ln1357_33_fu_3398_p2.read();
        xor_ln1357_34_reg_10202 = xor_ln1357_34_fu_3403_p2.read();
        xor_ln1357_35_reg_10209 = xor_ln1357_35_fu_3408_p2.read();
        xor_ln1357_40_reg_10216 = xor_ln1357_40_fu_3413_p2.read();
        xor_ln1357_41_reg_10222 = xor_ln1357_41_fu_3418_p2.read();
        xor_ln1357_42_reg_10228 = xor_ln1357_42_fu_3423_p2.read();
        xor_ln1357_43_reg_10234 = xor_ln1357_43_fu_3428_p2.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read())) {
        inv_keys_V_128 = xor_ln1357_16_fu_3191_p2.read();
        inv_keys_V_129 = xor_ln1357_17_fu_3196_p2.read();
        inv_keys_V_130 = xor_ln1357_18_fu_3201_p2.read();
        inv_keys_V_131 = xor_ln1357_19_fu_3206_p2.read();
        inv_keys_V_132 = xor_ln1357_20_fu_3211_p2.read();
        inv_keys_V_133 = xor_ln1357_21_fu_3216_p2.read();
        inv_keys_V_134 = xor_ln1357_22_fu_3221_p2.read();
        inv_keys_V_135 = xor_ln1357_23_fu_3226_p2.read();
        inv_keys_V_136 = xor_ln1357_24_fu_3231_p2.read();
        inv_keys_V_137 = xor_ln1357_25_fu_3236_p2.read();
        inv_keys_V_138 = xor_ln1357_26_fu_3241_p2.read();
        inv_keys_V_139 = xor_ln1357_27_fu_3246_p2.read();
        inv_keys_V_140 = xor_ln1357_28_fu_3251_p2.read();
        inv_keys_V_141 = xor_ln1357_29_fu_3256_p2.read();
        inv_keys_V_142 = xor_ln1357_30_fu_3261_p2.read();
        inv_keys_V_143 = xor_ln1357_31_fu_3266_p2.read();
        xor_ln1357_16_reg_10104 = xor_ln1357_16_fu_3191_p2.read();
        xor_ln1357_17_reg_10109 = xor_ln1357_17_fu_3196_p2.read();
        xor_ln1357_18_reg_10114 = xor_ln1357_18_fu_3201_p2.read();
        xor_ln1357_19_reg_10119 = xor_ln1357_19_fu_3206_p2.read();
        xor_ln1357_20_reg_10124 = xor_ln1357_20_fu_3211_p2.read();
        xor_ln1357_21_reg_10130 = xor_ln1357_21_fu_3216_p2.read();
        xor_ln1357_22_reg_10136 = xor_ln1357_22_fu_3221_p2.read();
        xor_ln1357_23_reg_10142 = xor_ln1357_23_fu_3226_p2.read();
        xor_ln1357_28_reg_10148 = xor_ln1357_28_fu_3251_p2.read();
        xor_ln1357_29_reg_10153 = xor_ln1357_29_fu_3256_p2.read();
        xor_ln1357_30_reg_10158 = xor_ln1357_30_fu_3261_p2.read();
        xor_ln1357_31_reg_10163 = xor_ln1357_31_fu_3266_p2.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read())) {
        inv_keys_V_144 = xor_ln1357_fu_2988_p2.read();
        inv_keys_V_145 = xor_ln1357_1_fu_2994_p2.read();
        inv_keys_V_146 = xor_ln1357_2_fu_2999_p2.read();
        inv_keys_V_147 = xor_ln1357_3_fu_3004_p2.read();
        inv_keys_V_148 = xor_ln1357_4_fu_3009_p2.read();
        inv_keys_V_149 = xor_ln1357_5_fu_3014_p2.read();
        inv_keys_V_150 = xor_ln1357_6_fu_3019_p2.read();
        inv_keys_V_151 = xor_ln1357_7_fu_3024_p2.read();
        inv_keys_V_152 = xor_ln1357_8_fu_3029_p2.read();
        inv_keys_V_153 = xor_ln1357_9_fu_3034_p2.read();
        inv_keys_V_154 = xor_ln1357_10_fu_3039_p2.read();
        inv_keys_V_155 = xor_ln1357_11_fu_3044_p2.read();
        inv_keys_V_156 = xor_ln1357_12_fu_3049_p2.read();
        inv_keys_V_157 = xor_ln1357_13_fu_3054_p2.read();
        inv_keys_V_158 = xor_ln1357_14_fu_3059_p2.read();
        inv_keys_V_159 = xor_ln1357_15_fu_3064_p2.read();
        xor_ln1357_10_reg_10072 = xor_ln1357_10_fu_3039_p2.read();
        xor_ln1357_11_reg_10078 = xor_ln1357_11_fu_3044_p2.read();
        xor_ln1357_1_reg_10045 = xor_ln1357_1_fu_2994_p2.read();
        xor_ln1357_2_reg_10050 = xor_ln1357_2_fu_2999_p2.read();
        xor_ln1357_3_reg_10055 = xor_ln1357_3_fu_3004_p2.read();
        xor_ln1357_8_reg_10060 = xor_ln1357_8_fu_3029_p2.read();
        xor_ln1357_9_reg_10066 = xor_ln1357_9_fu_3034_p2.read();
        xor_ln1357_reg_10040 = xor_ln1357_fu_2988_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && !(esl_seteq<1,1,1>(ap_const_logic_0, in_r_TVALID.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op98_read_state1.read())) && esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln100_fu_2639_p2.read()) && esl_seteq<1,1,1>(ap_const_lv1_1, icmp_ln166_fu_2645_p2.read()))) {
        inv_keys_V_160 = keyT_V.read().range(127, 120);
        inv_keys_V_161 = keyT_V.read().range(119, 112);
        inv_keys_V_162 = keyT_V.read().range(111, 104);
        inv_keys_V_163 = keyT_V.read().range(103, 96);
        inv_keys_V_164 = keyT_V.read().range(95, 88);
        inv_keys_V_165 = keyT_V.read().range(87, 80);
        inv_keys_V_166 = keyT_V.read().range(79, 72);
        inv_keys_V_167 = keyT_V.read().range(71, 64);
        inv_keys_V_168 = keyT_V.read().range(63, 56);
        inv_keys_V_169 = keyT_V.read().range(55, 48);
        inv_keys_V_170 = keyT_V.read().range(47, 40);
        inv_keys_V_171 = keyT_V.read().range(39, 32);
        inv_keys_V_172 = keyT_V.read().range(31, 24);
        inv_keys_V_173 = keyT_V.read().range(23, 16);
        inv_keys_V_174 = keyT_V.read().range(15, 8);
        inv_keys_V_175 = keys_15_V_fu_2671_p1.read();
        keys_10_V_reg_9941 = keyT_V.read().range(47, 40);
        keys_11_V_reg_9936 = keyT_V.read().range(39, 32);
        keys_12_V_reg_9929 = keyT_V.read().range(31, 24);
        keys_13_V_reg_9922 = keyT_V.read().range(23, 16);
        keys_14_V_reg_9915 = keyT_V.read().range(15, 8);
        keys_15_V_reg_9908 = keys_15_V_fu_2671_p1.read();
        keys_9_V_reg_9946 = keyT_V.read().range(55, 48);
        trunc_ln214_1_reg_9956 = keyT_V.read().range(71, 64);
        trunc_ln214_2_reg_9962 = keyT_V.read().range(79, 72);
        trunc_ln214_3_reg_9968 = keyT_V.read().range(87, 80);
        trunc_ln214_4_reg_9974 = keyT_V.read().range(95, 88);
        trunc_ln214_5_reg_9980 = keyT_V.read().range(103, 96);
        trunc_ln214_6_reg_9985 = keyT_V.read().range(111, 104);
        trunc_ln214_7_reg_9990 = keyT_V.read().range(119, 112);
        trunc_ln214_8_reg_9995 = keyT_V.read().range(127, 120);
        trunc_ln_reg_9951 = keyT_V.read().range(63, 56);
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state6.read())) {
        inv_keys_V_96 = xor_ln1357_48_reg_10260.read();
        inv_keys_V_97 = xor_ln1357_49_reg_10266.read();
        inv_keys_V_98 = xor_ln1357_50_reg_10272.read();
        inv_keys_V_99 = xor_ln1357_51_reg_10278.read();
        xor_ln1357_64_reg_10356 = xor_ln1357_64_fu_3764_p2.read();
        xor_ln1357_65_reg_10363 = xor_ln1357_65_fu_3770_p2.read();
        xor_ln1357_66_reg_10370 = xor_ln1357_66_fu_3775_p2.read();
        xor_ln1357_67_reg_10377 = xor_ln1357_67_fu_3780_p2.read();
        xor_ln1357_71_reg_10384 = xor_ln1357_71_fu_3785_p2.read();
        xor_ln1357_72_reg_10391 = xor_ln1357_72_fu_3790_p2.read();
        xor_ln1357_73_reg_10398 = xor_ln1357_73_fu_3795_p2.read();
        xor_ln1357_74_reg_10405 = xor_ln1357_74_fu_3800_p2.read();
        xor_ln1357_75_reg_10412 = xor_ln1357_75_fu_3805_p2.read();
        xor_ln1357_76_reg_10417 = xor_ln1357_76_fu_3810_p2.read();
        xor_ln1357_77_reg_10422 = xor_ln1357_77_fu_3815_p2.read();
        xor_ln1357_78_reg_10427 = xor_ln1357_78_fu_3820_p2.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, out_V_data_V_1_load_A.read())) {
        out_V_data_V_1_payload_A = data_data_V_fu_9865_p1.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, out_V_data_V_1_load_B.read())) {
        out_V_data_V_1_payload_B = data_data_V_fu_9865_p1.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state7.read()) || esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state9.read()))) {
        reg_2613 = SBOX_V_q0.read();
        reg_2617 = SBOX_V_q2.read();
        reg_2621 = SBOX_V_q3.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state8.read())) {
        xor_ln1357_100_reg_10609 = xor_ln1357_100_fu_4000_p2.read();
        xor_ln1357_101_reg_10614 = xor_ln1357_101_fu_4005_p2.read();
        xor_ln1357_102_reg_10619 = xor_ln1357_102_fu_4010_p2.read();
        xor_ln1357_103_reg_10624 = xor_ln1357_103_fu_4015_p2.read();
        xor_ln1357_79_reg_10533 = xor_ln1357_79_fu_3931_p2.read();
        xor_ln1357_80_reg_10538 = xor_ln1357_80_fu_3935_p2.read();
        xor_ln1357_81_reg_10543 = xor_ln1357_81_fu_3940_p2.read();
        xor_ln1357_82_reg_10548 = xor_ln1357_82_fu_3945_p2.read();
        xor_ln1357_92_reg_10553 = xor_ln1357_92_fu_3956_p2.read();
        xor_ln1357_93_reg_10560 = xor_ln1357_93_fu_3962_p2.read();
        xor_ln1357_94_reg_10567 = xor_ln1357_94_fu_3968_p2.read();
        xor_ln1357_95_reg_10574 = xor_ln1357_95_fu_3974_p2.read();
        xor_ln1357_96_reg_10581 = xor_ln1357_96_fu_3980_p2.read();
        xor_ln1357_97_reg_10588 = xor_ln1357_97_fu_3985_p2.read();
        xor_ln1357_98_reg_10595 = xor_ln1357_98_fu_3990_p2.read();
        xor_ln1357_99_reg_10602 = xor_ln1357_99_fu_3995_p2.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state10.read())) {
        xor_ln1357_104_reg_10703 = xor_ln1357_104_fu_4086_p2.read();
        xor_ln1357_105_reg_10708 = xor_ln1357_105_fu_4090_p2.read();
        xor_ln1357_106_reg_10713 = xor_ln1357_106_fu_4095_p2.read();
        xor_ln1357_107_reg_10718 = xor_ln1357_107_fu_4100_p2.read();
        xor_ln1357_109_reg_10723 = xor_ln1357_109_fu_4105_p2.read();
        xor_ln1357_110_reg_10731 = xor_ln1357_110_fu_4110_p2.read();
        xor_ln1357_111_reg_10739 = xor_ln1357_111_fu_4115_p2.read();
        xor_ln1357_117_reg_10747 = xor_ln1357_117_fu_4126_p2.read();
        xor_ln1357_118_reg_10754 = xor_ln1357_118_fu_4132_p2.read();
        xor_ln1357_119_reg_10761 = xor_ln1357_119_fu_4138_p2.read();
        xor_ln1357_120_reg_10768 = xor_ln1357_120_fu_4144_p2.read();
        xor_ln1357_121_reg_10775 = xor_ln1357_121_fu_4150_p2.read();
        xor_ln1357_122_reg_10781 = xor_ln1357_122_fu_4155_p2.read();
        xor_ln1357_123_reg_10787 = xor_ln1357_123_fu_4160_p2.read();
        xor_ln1357_124_reg_10793 = xor_ln1357_124_fu_4165_p2.read();
        xor_ln1357_125_reg_10799 = xor_ln1357_125_fu_4170_p2.read();
        xor_ln1357_126_reg_10804 = xor_ln1357_126_fu_4175_p2.read();
        xor_ln1357_127_reg_10809 = xor_ln1357_127_fu_4180_p2.read();
        xor_ln1357_128_reg_10814 = xor_ln1357_128_fu_4185_p2.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state11.read())) {
        xor_ln1357_108_reg_10839 = xor_ln1357_108_fu_4210_p2.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state9.read())) {
        xor_ln1357_112_reg_10655 = xor_ln1357_112_fu_4046_p2.read();
        xor_ln1357_113_reg_10662 = xor_ln1357_113_fu_4051_p2.read();
        xor_ln1357_114_reg_10669 = xor_ln1357_114_fu_4056_p2.read();
        xor_ln1357_115_reg_10676 = xor_ln1357_115_fu_4061_p2.read();
        xor_ln719_4_reg_10649 = xor_ln719_4_fu_4040_p2.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state7.read())) {
        xor_ln1357_83_reg_10457 = xor_ln1357_83_fu_3871_p2.read();
        xor_ln1357_84_reg_10465 = xor_ln1357_84_fu_3876_p2.read();
        xor_ln1357_85_reg_10473 = xor_ln1357_85_fu_3881_p2.read();
        xor_ln1357_86_reg_10481 = xor_ln1357_86_fu_3886_p2.read();
        xor_ln1357_87_reg_10489 = xor_ln1357_87_fu_3891_p2.read();
        xor_ln1357_88_reg_10495 = xor_ln1357_88_fu_3896_p2.read();
        xor_ln1357_89_reg_10501 = xor_ln1357_89_fu_3901_p2.read();
        xor_ln1357_90_reg_10507 = xor_ln1357_90_fu_3906_p2.read();
        xor_ln719_3_reg_10452 = xor_ln719_3_fu_3865_p2.read();
    }
}

void kern_dec::thread_ap_NS_fsm() {
    switch (ap_CS_fsm.read().to_uint64()) {
        case 1 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && esl_seteq<1,1,1>(ap_const_lv1_1, icmp_ln100_fu_2639_p2.read()) && esl_seteq<1,1,1>(ap_const_lv1_1, tmp_nbreadreq_fu_344_p8.read()) && !(esl_seteq<1,1,1>(ap_const_logic_0, in_r_TVALID.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op98_read_state1.read())))) {
                ap_NS_fsm = ap_ST_fsm_state23;
            } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && !(esl_seteq<1,1,1>(ap_const_logic_0, in_r_TVALID.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op98_read_state1.read())) && ((esl_seteq<1,1,1>(ap_const_lv1_1, icmp_ln100_fu_2639_p2.read()) && 
   esl_seteq<1,1,1>(ap_const_lv1_0, tmp_nbreadreq_fu_344_p8.read())) || 
  (esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln100_fu_2639_p2.read()) && 
   esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln166_fu_2645_p2.read()))))) {
                ap_NS_fsm = ap_ST_fsm_state22;
            } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && !(esl_seteq<1,1,1>(ap_const_logic_0, in_r_TVALID.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op98_read_state1.read())) && esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln100_fu_2639_p2.read()) && esl_seteq<1,1,1>(ap_const_lv1_1, icmp_ln166_fu_2645_p2.read()))) {
                ap_NS_fsm = ap_ST_fsm_state2;
            } else {
                ap_NS_fsm = ap_ST_fsm_state1;
            }
            break;
        case 2 : 
            ap_NS_fsm = ap_ST_fsm_state3;
            break;
        case 4 : 
            ap_NS_fsm = ap_ST_fsm_state4;
            break;
        case 8 : 
            ap_NS_fsm = ap_ST_fsm_state5;
            break;
        case 16 : 
            ap_NS_fsm = ap_ST_fsm_state6;
            break;
        case 32 : 
            ap_NS_fsm = ap_ST_fsm_state7;
            break;
        case 64 : 
            ap_NS_fsm = ap_ST_fsm_state8;
            break;
        case 128 : 
            ap_NS_fsm = ap_ST_fsm_state9;
            break;
        case 256 : 
            ap_NS_fsm = ap_ST_fsm_state10;
            break;
        case 512 : 
            ap_NS_fsm = ap_ST_fsm_state11;
            break;
        case 1024 : 
            ap_NS_fsm = ap_ST_fsm_state12;
            break;
        case 2048 : 
            ap_NS_fsm = ap_ST_fsm_state13;
            break;
        case 4096 : 
            ap_NS_fsm = ap_ST_fsm_state14;
            break;
        case 8192 : 
            ap_NS_fsm = ap_ST_fsm_state15;
            break;
        case 16384 : 
            ap_NS_fsm = ap_ST_fsm_state16;
            break;
        case 32768 : 
            ap_NS_fsm = ap_ST_fsm_state17;
            break;
        case 65536 : 
            ap_NS_fsm = ap_ST_fsm_state18;
            break;
        case 131072 : 
            ap_NS_fsm = ap_ST_fsm_state19;
            break;
        case 262144 : 
            ap_NS_fsm = ap_ST_fsm_state20;
            break;
        case 524288 : 
            ap_NS_fsm = ap_ST_fsm_state21;
            break;
        case 1048576 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state21.read()) && esl_seteq<1,1,1>(out_V_data_V_1_ack_in.read(), ap_const_logic_1))) {
                ap_NS_fsm = ap_ST_fsm_state22;
            } else {
                ap_NS_fsm = ap_ST_fsm_state21;
            }
            break;
        case 2097152 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state22.read()) && !(esl_seteq<1,2,2>(out_V_data_V_1_state.read(), ap_const_lv2_1) || esl_seteq<1,2,2>(ap_const_lv2_1, out_V_dest_V_1_state.read()) || esl_seteq<1,2,2>(ap_const_lv2_1, out_V_last_V_1_state.read()) || esl_seteq<1,2,2>(ap_const_lv2_1, out_V_id_V_1_state.read()) || esl_seteq<1,2,2>(ap_const_lv2_1, out_V_user_V_1_state.read()) || esl_seteq<1,2,2>(ap_const_lv2_1, out_V_keep_V_1_state.read()) || (esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
  esl_seteq<1,2,2>(out_V_data_V_1_state.read(), ap_const_lv2_3)) || (esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_3, out_V_dest_V_1_state.read())) || (esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_3, out_V_last_V_1_state.read())) || (esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_3, out_V_id_V_1_state.read())) || (esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_3, out_V_user_V_1_state.read())) || (esl_seteq<1,1,1>(ap_const_logic_0, out_r_TREADY.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_3, out_V_keep_V_1_state.read())) || esl_seteq<1,1,1>(ap_const_boolean_1, ap_block_state22_io.read())))) {
                ap_NS_fsm = ap_ST_fsm_state1;
            } else {
                ap_NS_fsm = ap_ST_fsm_state22;
            }
            break;
        case 4194304 : 
            ap_NS_fsm = ap_ST_fsm_state22;
            break;
        default : 
            ap_NS_fsm =  (sc_lv<23>) ("XXXXXXXXXXXXXXXXXXXXXXX");
            break;
    }
}

}

