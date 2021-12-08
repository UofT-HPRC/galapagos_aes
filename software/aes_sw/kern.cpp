#define INTERFACE_100G
#include "kern.hpp"

void init_kern (
  short id,
  galapagos_interface * in,
  galapagos_interface  * out)
{
#pragma HLS INTERFACE axis register both port=out
#pragma HLS INTERFACE axis register both port=in
     
     // ***** the receiver rsa's packet should be sent first
     // initialize the receiver RSA
     ap_uint<32> key_exchange_dest1 = 0x1;
     out->packet_write((char *)&key_exchange_dest1, 1, 2, 0);
     printf("the second packet sent.\n");
     
     // initialize the sender RSA
     ap_uint<32> key_exchange_dest = 2;
     printf("the first packet is going to be send.\n");
     out->packet_write((char *)&key_exchange_dest, 1, 1, 0);
     printf("the first packet sent.\n");
     
     // send the plain text to the aes encryption core
     // IN plainText ("0111111111abcdeffedcfff876443210", 16);
     IN plainText ("0123456789abcdeffedcba9876543210", 16);
     out->packet_write((char *)&plainText, 1, 3, 0);
     
     size_t size;
     short dest, src;
     // IN golden_plain ("0123456789abcdeffedcba9876543210", 16);
     while (true)
     {
         T * read_data = (T *)in->packet_read(&size, &dest, &src);
         //std::cout<<std::endl<< "ACTUAL PACKET " << std::hex << (read_data[0]) << std::dec << std::endl;
         if (src == 1 || src == 2)  {
             IN ack_pack = (ap_uint<128>)read_data[0];
             std::cout<<std::endl<< "ACK packet from rsa 1/2 core : " << std::hex << (ack_pack) << std::dec << std::endl;
         }
         if (src == 4) {
             
             
             IN ret_text = (ap_uint<128>)read_data[0];
             IN ret_text_final = 0;
             
             std::cout<<std::endl<< "plain text  " << std::hex << plainText << std::dec << std::endl;
             std::cout<<std::endl<< "deciphered text " << std::hex << ret_text << std::dec << std::endl;
             
             /*for (int i = 0; i < 16; i++)
              {
              ret_text_final |= ret_text & 0xff;
              ret_text >>= 8;
              if (i == 15)
              continue;
              ret_text_final <<= 8;
              }
              
              std::cout<<std::endl;
              std::cout<< " retreived text from the DEC in the CPU: " << std::hex << (ret_text_final) << std::dec << std::endl;
              
              if (ret_text_final == golden_plain) {
              printf("\n IT WORKED CORRECT :-)) \n");
              }
              else {
              printf("\n WRONG Ooops !!! \n");
              }*/
         }
     }
 }


void kern_enc(short id,
              galapagos_interface * in,
              galapagos_interface * out)
{
// #pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis register both port=out
#pragma HLS INTERFACE axis register both port=in
    
    const static DATA_TYPE RC[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36};
    
    const static DATA_TYPE SBOX[256] = {
        0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
        0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
        0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
        0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
        0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
        0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
        0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
        0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
        0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
        0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
        0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
        0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
        0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
        0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
        0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
        0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16};
    
    //
    // temporary variables used within the module
    DATA_TYPE i, j, m, n, temp, tmp_;
    DATA_TYPE temp_column[AES_COL_SIZE], temp_column_a[AES_COL_SIZE], temp_column_b[AES_COL_SIZE];
    DATA_TYPE temp_state[AES_BLOCK_SIZE];
    DATA_TYPE cipher[AES_BLOCK_SIZE];
    DATA_TYPE last4bytes[AES_COL_SIZE]; // used in the key schedule stage
    DATA_TYPE lastround[AES_BLOCK_SIZE]; // used in the key schedule stage
    
    while (true)
    {
        //
        // store the plain text onto on-chip memories
        DATA_TYPE plain_block[AES_BLOCK_SIZE]; // plain text; size = 16
        //
        // key schedule stage, generating the round keys
        static DATA_TYPE keys[AES_ROUND_KEY_SIZE]; // round keys; size = 176
        
        
#pragma HLS array_partition variable=keys complete
        
        IN keyT, plainT;
        
        int flag = 0;
        size_t size;
        short dest, src;
        while (flag < 2)
        {
            T * read_data = (T *)in->packet_read(&size, &dest, &src);
            
            if (src == 0) {
                plainT = (ap_uint<128>)read_data[0];
                flag++;
            }
            if (src == 1) {
                keyT = (ap_uint<128>)read_data[0];
                flag++;
            }
        }
        
    Lp2:for (i = AES_BLOCK_SIZE; i > 0 ; --i) {
#pragma HLS unroll
        keys[i - 1] = keyT & 0xff;
        keyT >>= 8;
    }
        
    Lp3:for (i = 0; i < AES_ROUNDS; ++i) {
#pragma HLS unroll
        
        temp = (i*16);
        tmp_ = (i+1)*16;
        
        last4bytes[0] = keys[temp + 12];
        last4bytes[1] = keys[temp + 13];
        last4bytes[2] = keys[temp + 14];
        last4bytes[3] = keys[temp + 15];
        
        // k0-k3 for next round
        temp_column[3] = SBOX[last4bytes[0]];
        temp_column[0] = SBOX[last4bytes[1]];
        temp_column[1] = SBOX[last4bytes[2]];
        temp_column[2] = SBOX[last4bytes[3]];
        temp_column[0] ^= RC[i];
        
    Lp4:for (j = 0; j < AES_BLOCK_SIZE; ++j) {
#pragma HLS unroll
        lastround[j] = keys[temp + j];
    }
        
        keys[tmp_] = temp_column[0] ^ lastround[0];
        keys[tmp_ + 1] = temp_column[1] ^ lastround[1];
        keys[tmp_ + 2] = temp_column[2] ^ lastround[2];
        keys[tmp_ + 3] = temp_column[3] ^ lastround[3];
        // k4-k7 for next round
        keys[tmp_ + 4] = keys[tmp_] ^ lastround[4];
        keys[tmp_ + 5] = keys[tmp_ + 1] ^ lastround[5];
        keys[tmp_ + 6] = keys[tmp_ + 2] ^ lastround[6];
        keys[tmp_ + 7] = keys[tmp_ + 3] ^ lastround[7];
        // k8-k11 for next round
        keys[tmp_ + 8] = keys[tmp_ + 4] ^ lastround[8];
        keys[tmp_ + 9] = keys[tmp_ + 5] ^ lastround[9];
        keys[tmp_ + 10] = keys[tmp_ + 6] ^ lastround[10];
        keys[tmp_ + 11] = keys[tmp_ + 7] ^ lastround[11];
        // k12-k15 for next round
        keys[tmp_ + 12] = keys[tmp_ + 8] ^ lastround[12];
        keys[tmp_ + 13] = keys[tmp_ + 9] ^ lastround[13];
        keys[tmp_ + 14] = keys[tmp_ + 10] ^ lastround[14];
        keys[tmp_ + 15] = keys[tmp_ + 11] ^ lastround[15];
    }
        
    Lp1:for (i = AES_BLOCK_SIZE; i > 0 ; --i) {
#pragma HLS unroll
        plain_block[i - 1] = plainT & 0xff;
        plainT >>= 8;
    }
        
        //
        // first add round key stage
    Lp5:for (i = 0; i < AES_BLOCK_SIZE; ++i ) {
#pragma HLS unroll
        cipher[i] = plain_block[i] ^ keys[i];
    }
        
        //
        // 9 rounds of AES encryption algorithm
    Lp6:for (j = 1; j < AES_ROUNDS ; ++j) {
#pragma HLS pipeline
        
        //
        // subtitute bytes stage
    Lp7:for (i = 0; i < AES_BLOCK_SIZE; ++i) {
        temp_state[i] = SBOX[cipher[i]];
    }
        
        //
        // shift rows stage
        // row1
        temp        = temp_state[1];
        temp_state[1]  = temp_state[5];
        temp_state[5]  = temp_state[9];
        temp_state[9]  = temp_state[13];
        temp_state[13] = temp;
        // row2
        temp        = temp_state[2];
        temp_state[2]  = temp_state[10];
        temp_state[10] = temp;
        temp        = temp_state[6];
        temp_state[6]  = temp_state[14];
        temp_state[14] = temp;
        // row3
        temp        = temp_state[15];
        temp_state[15] = temp_state[11];
        temp_state[11] = temp_state[7];
        temp_state[7]  = temp_state[3];
        temp_state[3]  = temp;
        
        //
        // mix columns stage
    Lp8:for (m = 0; m < AES_BLOCK_SIZE; m += 4) {
        temp_column[0] = temp_state[m];
        temp_column[1] = temp_state[m + 1];
        temp_column[2] = temp_state[m + 2];
        temp_column[3] = temp_state[m + 3];
        
    Lp9:for (n = 0; n < AES_COL_SIZE; ++n) {
        temp_column_a[n] = temp_column[n];
        if (temp_column[n] & 0x80) {
            temp_column_b[n] = (temp_column[n] << 1) ^ 0x1b;
        } else {
            temp_column_b[n] = (temp_column[n] << 1);
        }
    }
        
        temp_column[0] = temp_column_b[0] ^ temp_column_a[3] ^ temp_column_a[2] ^ temp_column_b[1] ^ temp_column_a[1]; /* 2 * a0 + a3 + a2 + 3 * a1 */
        temp_column[1] = temp_column_b[1] ^ temp_column_a[0] ^ temp_column_a[3] ^ temp_column_b[2] ^ temp_column_a[2]; /* 2 * a1 + a0 + a3 + 3 * a2 */
        temp_column[2] = temp_column_b[2] ^ temp_column_a[1] ^ temp_column_a[0] ^ temp_column_b[3] ^ temp_column_a[3]; /* 2 * a2 + a1 + a0 + 3 * a3 */
        temp_column[3] = temp_column_b[3] ^ temp_column_a[2] ^ temp_column_a[1] ^ temp_column_b[0] ^ temp_column_a[0]; /* 2 * a3 + a2 + a1 + 3 * a0 */
        
        cipher[m] = temp_column[0];
        cipher[m + 1] = temp_column[1];
        cipher[m + 2] = temp_column[2];
        cipher[m + 3] = temp_column[3];
    }
        
        //
        // add round key stage
    Lp10:for (i = 0; i < AES_BLOCK_SIZE; ++i) {
        cipher[i] ^= keys[(j * AES_BLOCK_SIZE) + i];
    }
    }
        
        //
        // last round of AES encryption algorithm
        
        // subtitute bytes stage
    Lp11:for (i = 0; i < AES_BLOCK_SIZE; ++i) {
#pragma HLS unroll
        cipher[i] = SBOX[cipher[i]];
    }
        
        // shift rows stage
        // row1
        temp = cipher[1];
        cipher[1]  = cipher[5];
        cipher[5]  = cipher[9];
        cipher[9]  = cipher[13];
        cipher[13] = temp;
        // row2
        temp        = cipher[2];
        cipher[2]  = cipher[10];
        cipher[10] = temp;
        temp        = cipher[6];
        cipher[6]  = cipher[14];
        cipher[14] = temp;
        // row3
        temp        = cipher[15];
        cipher[15] = cipher[11];
        cipher[11] = cipher[7];
        cipher[7]  = cipher[3];
        cipher[3]  = temp;
        
        // add round key stage
    Lp12:for (i = 0; i < AES_BLOCK_SIZE; ++i) {
#pragma HLS unroll
        cipher[i] ^= keys[160 + i]; // the last key; size = 16 bytes
    }
        
        out->packet_write((char *)cipher, 1, 4, 3);
        
        printf ("\nEND OF ECRYPTION !!!!!!!!!!!!\n");
        
        if (flag >= 2)
            return;
    }
}

ap_uint<8> mul_bytes(ap_uint<8> a, ap_uint<8> b) {
    ap_uint<8> p = 0;
    ap_uint<8> high_bit_mask = 0x80;
    ap_uint<8> high_bit = 0;
    ap_uint<8> modulo = 0x1B;
    
lpmool:for (int i = 0; i < 8; i++) {
#pragma HLS unroll
    if (b & 1) {
        p ^= a;
    }
    
    high_bit = a & high_bit_mask;
    a <<= 1;
    if (high_bit) {
        a ^= modulo;
    }
    b >>= 1;
}
    
    return p;
}

void kern_dec(
              short id,
              galapagos_interface * in,
              galapagos_interface * out)
{
    
// #pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis register both port=out
#pragma HLS INTERFACE axis register both port=in
    
    const static ap_uint<8> RC[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36};
    
    const static ap_uint<8> SBOX[256] = {
        0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
        0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
        0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
        0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
        0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
        0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
        0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
        0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
        0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
        0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
        0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
        0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
        0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
        0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
        0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
        0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16};
    
    const static ap_uint<8> INV_SBOX[256] = {
        0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,
        0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,
        0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,
        0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,
        0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,
        0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,
        0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,
        0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,
        0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,
        0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,
        0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,
        0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,
        0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,
        0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,
        0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,
        0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d};
    
    //
    // temp vars
    DATA_TYPE i, j, temp, tmp_;
    DATA_TYPE temp_column[AES_COL_SIZE], temp_column_a[AES_COL_SIZE], temp_column_b[AES_COL_SIZE];
    DATA_TYPE temp_state[16];
    DATA_TYPE plain[AES_BLOCK_SIZE];
    DATA_TYPE last4bytes[AES_COL_SIZE]; // used in the key schedule stage
    DATA_TYPE lastround[AES_BLOCK_SIZE]; // used in the key schedule stage
    
    DATA_TYPE cipher_block[AES_BLOCK_SIZE];
    DATA_TYPE keys[AES_ROUND_KEY_SIZE];
    static DATA_TYPE inv_keys[AES_ROUND_KEY_SIZE];
#pragma HLS array_partition variable=keys complete
#pragma HLS array_partition variable=inv_keys complete
    
    while (true) {
        
        IN cipherT, keyT;
        
        int flag = 0;
        size_t size;
        short dest, src;
        while (flag < 2)
        {
            T * read_data = (T *)in->packet_read(&size, &dest, &src);
            
            if (src == 3) {
                cipherT = (ap_uint<128>)read_data[0];
                flag++;
            }
            if (src == 2) {
                keyT = (ap_uint<128>)read_data[0];
                flag++;
            }
        }
        
    lp2:for (i = AES_BLOCK_SIZE; i > 0 ; --i) {
#pragma HLS unroll
        keys[i - 1] = keyT  & 0xff;
        keyT >>= 8;
    }
        
    lp3:for (i = 0; i < AES_ROUNDS; ++i) {
#pragma HLS unroll
        
        temp = (i*16);
        tmp_ = (i+1)*16;
        
        last4bytes[0] = keys[temp + 12];
        last4bytes[1] = keys[temp + 13];
        last4bytes[2] = keys[temp + 14];
        last4bytes[3] = keys[temp + 15];
        
        // k0-k3 for next round
        temp_column[3] = SBOX[last4bytes[0]];
        temp_column[0] = SBOX[last4bytes[1]];
        temp_column[1] = SBOX[last4bytes[2]];
        temp_column[2] = SBOX[last4bytes[3]];
        temp_column[0] ^= RC[i];
        
    lp4:for (j = 0; j < AES_BLOCK_SIZE; ++j) {
#pragma HLS unroll
        lastround[j] = keys[temp + j];
    }
        
        keys[tmp_] = temp_column[0] ^ lastround[0];
        keys[tmp_ + 1] = temp_column[1] ^ lastround[1];
        keys[tmp_ + 2] = temp_column[2] ^ lastround[2];
        keys[tmp_ + 3] = temp_column[3] ^ lastround[3];
        // k4-k7 for next round
        keys[tmp_ + 4] = keys[tmp_] ^ lastround[4];
        keys[tmp_ + 5] = keys[tmp_ + 1] ^ lastround[5];
        keys[tmp_ + 6] = keys[tmp_ + 2] ^ lastround[6];
        keys[tmp_ + 7] = keys[tmp_ + 3] ^ lastround[7];
        // k8-k11 for next round
        keys[tmp_ + 8] = keys[tmp_ + 4] ^ lastround[8];
        keys[tmp_ + 9] = keys[tmp_ + 5] ^ lastround[9];
        keys[tmp_ + 10] = keys[tmp_ + 6] ^ lastround[10];
        keys[tmp_ + 11] = keys[tmp_ + 7] ^ lastround[11];
        // k12-k15 for next round
        keys[tmp_ + 12] = keys[tmp_ + 8] ^ lastround[12];
        keys[tmp_ + 13] = keys[tmp_ + 9] ^ lastround[13];
        keys[tmp_ + 14] = keys[tmp_ + 10] ^ lastround[14];
        keys[tmp_ + 15] = keys[tmp_ + 11] ^ lastround[15];
    }
        int m, n;
    lp5:for (m = 0, n = AES_ROUND_KEY_SIZE - 1; n >= 0; m+=16, n-=16) {
#pragma HLS unroll
        inv_keys[m] = keys[n-15];
        inv_keys[m+1] = keys[n-14];
        inv_keys[m+2] = keys[n-13];
        inv_keys[m+3] = keys[n-12];
        inv_keys[m+4] = keys[n-11];
        inv_keys[m+5] = keys[n-10];
        inv_keys[m+6] = keys[n-9];
        inv_keys[m+7] = keys[n-8];
        inv_keys[m+8] = keys[n-7];
        inv_keys[m+9] = keys[n-6];
        inv_keys[m+10] = keys[n-5];
        inv_keys[m+11] = keys[n-4];
        inv_keys[m+12] = keys[n-3];
        inv_keys[m+13] = keys[n-2];
        inv_keys[m+14] = keys[n-1];
        inv_keys[m+15] = keys[n];
    }
        
    lp1:for (i = 0; i < AES_BLOCK_SIZE; ++i) {
#pragma HLS unroll
        cipher_block[i] = cipherT  & 0xff;
        cipherT >>= 8;
    }
        
        //
        // first AddRoundKey
    lp7:for ( i = 0; i < AES_BLOCK_SIZE; ++i ) {
#pragma HLS unroll
        plain[i] = cipher_block[i] ^ inv_keys[i];
    }
        
        //
        // 9 rounds AES_ROUNDS
    lp8:for (j = 1; j < AES_ROUNDS; ++j) {
#pragma HLS unroll
        
        //
        // shift rows
        // row1
        temp = plain[13];
        plain[13] = plain[9];
        plain[9] = plain[5];
        plain[5] = plain[1];
        plain[1] = temp;
        // row2
        temp        = plain[14];
        plain[14]  = plain[6];
        plain[6] = temp;
        temp        = plain[10];
        plain[10]  = plain[2];
        plain[2] = temp;
        // row3
        temp        = plain[3];
        plain[3] = plain[7];
        plain[7] = plain[11];
        plain[11]  = plain[15];
        plain[15]  = temp;
        
        //
        // subtitute bytes stage
    lp9:for (i = 0; i < AES_BLOCK_SIZE; ++i) {
#pragma HLS unroll
        temp_state[i] = INV_SBOX[plain[i]];
    }
        
        //
        // AddRoundKey
    lp10:for ( i = 0; i < AES_BLOCK_SIZE; ++i ) {
#pragma HLS unroll
        temp_state[i] ^= inv_keys[(j * AES_BLOCK_SIZE) + i];
    }
        
        //
        // mix column
    lp11:for (int i = 0; i < AES_BLOCK_SIZE; i += 4) {
#pragma HLS unroll
        temp_column_a[0] = temp_state[i];
        temp_column_a[1] = temp_state[i + 1];
        temp_column_a[2] = temp_state[i + 2];
        temp_column_a[3] = temp_state[i + 3];
        
        temp_column_b[0] = mul_bytes(0x0e, temp_column_a[0]) ^
        mul_bytes(0x0b, temp_column_a[1]) ^
        mul_bytes(0x0d, temp_column_a[2]) ^
        mul_bytes(0x09, temp_column_a[3]);
        
        temp_column_b[1] = mul_bytes(0x09, temp_column_a[0]) ^
        mul_bytes(0x0e, temp_column_a[1]) ^
        mul_bytes(0x0b, temp_column_a[2]) ^
        mul_bytes(0x0d, temp_column_a[3]);
        
        temp_column_b[2] = mul_bytes(0x0d, temp_column_a[0]) ^
        mul_bytes(0x09, temp_column_a[1]) ^
        mul_bytes(0x0e, temp_column_a[2]) ^
        mul_bytes(0x0b, temp_column_a[3]);
        
        temp_column_b[3] = mul_bytes(0x0b, temp_column_a[0]) ^
        mul_bytes(0x0d, temp_column_a[1]) ^
        mul_bytes(0x09, temp_column_a[2]) ^
        mul_bytes(0x0e, temp_column_a[3]);
        
        plain[i] = temp_column_b[0];
        plain[i + 1] = temp_column_b[1];
        plain[i + 2] = temp_column_b[2];
        plain[i + 3] = temp_column_b[3];
    }
    }
        
        // last round
        //
        // shift rows
        // row1
        temp = plain[13];
        plain[13] = plain[9];
        plain[9] = plain[5];
        plain[5] = plain[1];
        plain[1] = temp;
        // row2
        temp        = plain[14];
        plain[14]  = plain[6];
        plain[6] = temp;
        temp        = plain[10];
        plain[10]  = plain[2];
        plain[2] = temp;
        // row3
        temp        = plain[3];
        plain[3] = plain[7];
        plain[7] = plain[11];
        plain[11]  = plain[15];
        plain[15]  = temp;
        
        //
        // subtitute bytes stage
    lp12:for (i = 0; i < AES_BLOCK_SIZE; ++i) {
#pragma HLS unroll
        plain[i] = INV_SBOX[plain[i]];
    }
        //
        // AddRoundKey
    lp13:for ( i = 0; i < AES_BLOCK_SIZE; ++i ) {
#pragma HLS unroll
        plain[i] ^= inv_keys[160 + i];
    }
        
        out->packet_write((char *)plain, 1, 0, 4);
        
        printf("\nEND OF DECRYPTION !!!!!!\n");
        
        if (flag >= 2)
            return;
    }
}


void key_core_one (
  short id,
  galapagos_interface * in,
  galapagos_interface  * out
  )
{
// #pragma HLS_DATAFLOW
#pragma HLS INTERFACE axis register both port=out
#pragma HLS INTERFACE axis register both port=in
     
     //Message handling logistics
     static bool trans_done = 0;
     static ap_uint<16> time_step = 0;
     static ap_uint<32> key_exchange_partner_dest = 0;
     const bool is_sender = (id == SENDER_ID);
     
     //Key exchange variables
     static ap_uint<128> secret = 0;
     static ap_uint<128> public_key = 0;
     static ap_uint<128> shared_secret = 0;
     
     static ap_uint<128> modulus = 0; //large prime number
     static ap_uint<128> base = 0; //smaller number
     
     size_t size;
     short dest, src;
     
     while (true) {
         
         if(trans_done)
             return;
         
         //Load in the destination (i.e. who we are generating a key with)
         if( (time_step == 0) ){
             //Retrieve data and add to the sum
             // key_exchange_partner_dest = in.read().value(31,0);
             
             printf("\n timestep 0 \n");
             
             char flag = 0;
             while (flag == 0)
             {
                 T * read_data = (T *)in->packet_read(&size, &dest, &src);
                 
                 if (src == 0) {
                     // key_exchange_partner_dest = read_data[0] & 0xffffffff;
                     key_exchange_partner_dest = (ap_uint<32>)read_data[0];
                     
                     secret = 12 + id;
                     time_step++;
                     
                     flag = 1;
                 }
             }
             
         }
         
         //Sender/receiver logic needs to be split for the first few steps
         if(time_step <= 2){
             if(is_sender){
                 //Modulus  generation
                 if(time_step == 1){
                     
                     printf("\n timestep 1 from rsa 1 \n");
                     
                     //Generate modulus and send it
                     modulus = 524287;
                     const data out_data = {key_exchange_partner_dest, modulus, 1, 0};
                     
                     // it should send to the other RSA kernel
                     out->packet_write((char *)&out_data, 1, 2 /*rec RSA id*/, 1 /*send RSA id*/);
                     
                     time_step++;
                 }
                 
                 else if(time_step == 2){
                     // if(time_step == 2){
                     
                     printf("\n timestep 2 from rsa 1 \n");
                     
                     //Generate base and send it
                     base = 23;
                     const data out_data = {key_exchange_partner_dest, base, 1, 0};
                     
                     // it should send to the other RSA kernel
                     out->packet_write((char *)&out_data, 1, 2 /*rec RSA id*/, 1 /*send RSA id*/);
                     
                     time_step++;
                 }
             }
             
             else{
                 
                 size_t size;
                 short dest, src;
                 
                 char flag = 0;
                 while (flag == 0)
                 {
                     T * read_data = (T *)in->packet_read(&size, &dest, &src);
                     
                     if (src == 1) { /* if it's from the sender kernel */
                         
                         //Load modulus
                         if(time_step == 1){
                             
                             printf("\n timestep 1 from rsa 2 \n");
                             
                             modulus = (ap_uint<128>)(read_data[0] >> 32);
                             
                             time_step++;
                             
                             flag = 1;
                         }
                         
                         //Load base
                         else if(time_step == 2){
                             
                             printf("\n timestep 2 from rsa 2 \n");
                             
                             base = (ap_uint<128>)(read_data[0] >> 32);
                             
                             time_step++;
                             
                             flag = 1;
                         }
                         
                     }
                 }
             }
         }
         
         //Latter time steps - send/receive phase is done
         else{
             //Public key generation
             if(time_step == 3){
                 
                 printf("\n timestep 3 from rsa %d\n", id);
                 
                 //public_key = pow(base, secret) % self.modulus
#ifdef ENABLE_DEBUG_PRINT
                 std::cout << "CORE generating pub key with:\n\tbase: " << base << "\n\tsecret: " << secret << "\n\tmod: " << modulus << std::endl;
#endif
                 
                 big_mult_t big_mult = base;
                 
             pub_key_loop:
                 for(ap_uint<128> i = 1; i < secret; i++){
#pragma HLS loop_tripcount min=1 max=256 avg=128
#pragma HLS pipeline
#pragma HLS unroll factor = 1
                     big_mult *= base;
                 }
                 big_mult = (big_mult % modulus);
                 public_key = big_mult;
                 
#ifdef ENABLE_DEBUG_PRINT
                 std::cout << "CORE generated pub key: " << public_key << std::endl;
#endif
                 const data out_data = {key_exchange_partner_dest, public_key, 1, 0};
                 
                 if (id == 1) {
                     out->packet_write((char *)&out_data, 1, 2, 1);
                 }
                 else if (id == 2) {
                     out->packet_write((char *)&out_data, 1, 1, 2);
                 }
                 
                 time_step++;
             }
             
             //Shared secret generation
             else if(time_step == 4){
                 
                 printf("\n timestep 4 from rsa %d\n", id);
                 
                 ap_uint<128> other_public_key;
                 size_t size;
                 short dest, src;
                 
                 char flag = 0;
                 while (flag == 0)
                 {
                     T * read_data = (T *)in->packet_read(&size, &dest, &src);
                     
                     if (src == 1 && dest == 2) {
                         // other_public_key = (read_data[0] >> 32).value(127,0);
                         other_public_key = (ap_uint<128>)(read_data[0] >> 64);
                         
                         flag = 1;
                     }
                     if (src == 2 && dest == 1) {
                         // other_public_key = (read_data[0] >> 32).value(127,0);
                         other_public_key = (ap_uint<128>)(read_data[0] >> 64);
                         
                         flag = 1;
                     }
                 }
                 
                 //shared_secret = pow(other_public_key, secret) % modulus
#ifdef ENABLE_DEBUG_PRINT
                 std::cout << "CORE generating shared secret with:\n\tother pub: " << other_public_key << "\n\tsecret: " << secret << "\n\tmod: " << modulus << std::endl;
#endif
                 big_mult_t big_mult = other_public_key;
                 
             share_secret_loop:
                 for(ap_uint<128> i = 1; i < secret; i++){
#pragma HLS loop_tripcount min=1 max=256 avg=128
#pragma HLS pipeline
#pragma HLS unroll factor = 1
                     big_mult *= other_public_key;
                 }
                 big_mult = big_mult % modulus;
                 shared_secret = big_mult;
                 
#ifdef ENABLE_DEBUG_PRINT
                 std::cout << "CORE generated shared secret: " << shared_secret << std::endl;
#endif
                 
                 time_step++;
                 trans_done = true;
                 
                 // it should send to the corresponding AES kernel
                 if (id == 1) {
                     out->packet_write((char *)&shared_secret, 1, 3 /*rec ENC id*/, 1 /*send RSA id*/);
                     printf("\n shared secret key from rsa 1: %x \n", (unsigned int)shared_secret);
                 }
                 
                 else if (id == 2) {
                     out->packet_write((char *)&shared_secret, 1, 4 /*rec DEC id*/, 2 /*send RSA id*/);
                     printf("\n shared secret key from rsa 2: %x \n", (unsigned int)shared_secret);
                 }
                 
             }
         }
     }
 }



void key_core_two (
  short id,
  galapagos_interface * in,
  galapagos_interface  * out
  )
{
// #pragma HLS_DATAFLOW
#pragma HLS INTERFACE axis register both port=out
#pragma HLS INTERFACE axis register both port=in
     
     //Message handling logistics
     static bool trans_done = 0;
     static ap_uint<16> time_step = 0;
     static ap_uint<32> key_exchange_partner_dest = 0;
     const bool is_sender = (id == SENDER_ID);
     
     //Key exchange variables
     static ap_uint<128> secret = 0;
     static ap_uint<128> public_key = 0;
     static ap_uint<128> shared_secret = 0;
     
     static ap_uint<128> modulus = 0; //large prime number
     static ap_uint<128> base = 0; //smaller number
     
     size_t size;
     short dest, src;
     while (true) {
         if(trans_done)
             return;
         
         //Load in the destination (i.e. who we are generating a key with)
         if( (time_step == 0) ){
             //Retrieve data and add to the sum
             
             printf("\n timestep 0 \n");
             
             char flag = 0;
             while (flag == 0)
             {
                 T * read_data = (T *)in->packet_read(&size, &dest, &src);
                 
                 if (src == 0) {
                     key_exchange_partner_dest = (ap_uint<32>)read_data[0];
                     
                     secret = 12 + id;
                     time_step++;
                     
                     flag = 1;
                 }
             }
             
         }
         
         //Sender/receiver logic needs to be split for the first few steps
         else if(time_step <= 2){
             if(is_sender){
                 //Modulus  generation
                 if(time_step == 1){
                     
                     printf("\n timestep 1 from rsa 1 \n");
                     
                     //Generate modulus and send it
                     modulus = 524287;
                     const data out_data = {key_exchange_partner_dest, modulus, 1, 0};
                     
                     // it should send to the other RSA kernel
                     out->packet_write((char *)&out_data, 1, 2 /*rec RSA id*/, 1 /*send RSA id*/);
                     
                     time_step++;
                 }
                 
                 else if(time_step == 2){
                     
                     printf("\n timestep 2 from rsa 1 \n");
                     
                     //Generate base and send it
                     base = 23;
                     const data out_data = {key_exchange_partner_dest, base, 1, 0};
                     
                     // it should send to the other RSA kernel
                     out->packet_write((char *)&out_data, 1, 2 /*rec RSA id*/, 1 /*send RSA id*/);
                     
                     time_step++;
                 }
             }
             
             else{
                 
                 size_t size;
                 short dest, src;
                 
                 char flag = 0;
                 while (flag == 0)
                 {
                     T * read_data = (T *)in->packet_read(&size, &dest, &src);
                     
                     if (src == 1) { /* if it's from the sender kernel */
                         
                         //Load modulus
                         if(time_step == 1){
                             
                             printf("\n timestep 1 from rsa 2 \n");
                             
                             modulus = (ap_uint<128>)(read_data[0] >> 64);
                             
                             time_step++;
                         }
                         
                         //Load base
                         else if(time_step == 2){
                             
                             printf("\n timestep 2 from rsa 2 \n");
                             
                             base = (ap_uint<128>)(read_data[0] >> 64);
                             
                             time_step++;
                             
                             flag = 1;
                         }
                         
                     }
                 }
             }
         }
         
         //Latter time steps - send/receive phase is done
         else{
             //Public key generation
             if(time_step == 3){
                 
                 printf("\n timestep 3 from rsa %d\n", id);
                 
                 //public_key = pow(base, secret) % self.modulus
#ifdef ENABLE_DEBUG_PRINT
                 std::cout << "CORE generating pub key with:\n\tbase: " << base << "\n\tsecret: " << secret << "\n\tmod: " << modulus << std::endl;
#endif
                 
                 big_mult_t big_mult = base;
                 
             pub_key_loop:
                 for(ap_uint<128> i = 1; i < secret; i++){
#pragma HLS loop_tripcount min=1 max=256 avg=128
#pragma HLS pipeline
#pragma HLS unroll factor = 1
                     big_mult *= base;
                 }
                 big_mult = (big_mult % modulus);
                 public_key = big_mult;
                 
#ifdef ENABLE_DEBUG_PRINT
                 std::cout << "CORE generated pub key: " << public_key << std::endl;
#endif
                 const data out_data = {key_exchange_partner_dest, public_key, 1, 0};
                 
                 if (id == 1) {
                     out->packet_write((char *)&out_data, 1, 2 /*rec RSA id*/, 1 /*send RSA id*/);
                 }
                 else if (id == 2) {
                     out->packet_write((char *)&out_data, 1, 1 /*rec RSA id*/, 2 /*send RSA id*/);
                 }
                 
                 time_step++;
             }
             
             //Shared secret generation
             else if(time_step == 4){
                 
                 printf("\n timestep 4 from rsa %d\n", id);
                 
                 ap_uint<128> other_public_key;
                 size_t size;
                 short dest, src;
                 
                 char flag = 0;
                 while (flag == 0)
                 {
                     T * read_data = (T *)in->packet_read(&size, &dest, &src);
                     
                     if (src == 1 && dest == 2) {
                         // other_public_key = (read_data[0] >> 32).value(127,0);
                         other_public_key = (ap_uint<128>)(read_data[0] >> 64);
                         
                         flag = 1;
                     }
                     if (src == 2 && dest == 1) {
                         // other_public_key = (read_data[0] >> 32).value(127,0);
                         other_public_key = (ap_uint<128>)(read_data[0] >> 64);
                         
                         flag = 1;
                     }
                 }
                 
                 //shared_secret = pow(other_public_key, secret) % modulus
#ifdef ENABLE_DEBUG_PRINT
                 std::cout << "CORE generating shared secret with:\n\tother pub: " << other_public_key << "\n\tsecret: " << secret << "\n\tmod: " << modulus << std::endl;
#endif
                 big_mult_t big_mult = other_public_key;
                 
             share_secret_loop:
                 for(ap_uint<128> i = 1; i < secret; i++){
#pragma HLS loop_tripcount min=1 max=256 avg=128
#pragma HLS pipeline
#pragma HLS unroll factor = 1
                     big_mult *= other_public_key;
                 }
                 big_mult = big_mult % modulus;
                 shared_secret = big_mult;
                 
#ifdef ENABLE_DEBUG_PRINT
                 std::cout << "CORE generated shared secret: " << shared_secret << std::endl;
#endif
                 
                 time_step++;
                 trans_done = true;
                 
                 // it should send to the corresponding AES kernel
                 if (id == 1) {
                     out->packet_write((char *)&shared_secret, 1, 3 /*rec ENC id*/, 1 /*send RSA id*/);
                     printf("\n shared secret key from rsa 1: %x \n", (unsigned int)shared_secret);
                 }
                 
                 else if (id == 2) {
                     out->packet_write((char *)&shared_secret, 1, 4 /*rec DEC id*/, 2 /*send RSA id*/);
                     printf("\n shared secret key from rsa 2: %x \n", (unsigned int)shared_secret);
                 }
                 
             }
         }
     }
 }
