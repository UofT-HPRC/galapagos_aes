#define INTERFACE_100G

// the above define (INTERFACE_100G) is essential
// otherwise, you will get errors compiling the software project
// it defines that the galapagos packet should be 512 bits

#include "kern_enc.hpp"
#include "cstddef"

void kern_enc(short id,
              galapagos_interface * in,
              galapagos_interface * out)
{
#pragma HLS_DATAFLOW
#pragma HLS INTERFACE ap_ctrl_none port=return
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
    
    //
    // store the plain text onto on-chip memories
    DATA_TYPE plain_block[AES_BLOCK_SIZE]; // plain text; size = 16
    //
    // key schedule stage, generating the round keys
    static DATA_TYPE keys[AES_ROUND_KEY_SIZE]; // round keys; size = 176
    
    
#pragma HLS array_partition variable=keys complete
    
    
    static IN keyT, plainT;
    
    static int flag = 0;
    size_t size;
    short dest, src;
    if (flag < 2)
    {
        if (!in->empty()) {
            
            galapagos_packet data;
            data = in->read();
            src = data.id;
            
            if (src == 0) {
                // packet received from init kernel (id = 0)
                plainT = (ap_uint<128>)data.data;
                
                flag = flag + 1;
            }
            if (src == 1) {
                // packet received from rsa kernel (id = 1)
                keyT = (ap_uint<128>)data.data;
                
                flag = flag + 1;
            }
        }
    }
    else if (flag == 2){
        
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
        
        //
        // write back the cipher result
        IO_DATA_TYPE cipherT = 0;
    Lp13:for (i = AES_BLOCK_SIZE - 1; i > 0; --i) {
#pragma HLS unroll
        cipherT |= cipher[i];
        cipherT <<= 8;
    }
        cipherT |= cipher[0];
        
        // send the ciphered text to the dec kernel (id = 4)
        galapagos_packet data;
        data.dest = 4;
        data.id = 3;
        data.keep = KEEP_ALL;
        data.last = 1;
        data.user = 1; // this is used for size of the packet; don't forget to set it to one
        data.data = cipherT;
        out->write(data);
        
        flag = 24;
    }
    else if (flag > 3) {
        return;
    }
}
