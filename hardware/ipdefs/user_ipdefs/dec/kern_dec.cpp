#define INTERFACE_100G

// the above define (INTERFACE_100G) is essential
// otherwise, you will get errors compiling the software project
// it defines that the galapagos packet should be 512 bits

#include "kern_dec.hpp"
#include "cstddef"

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

void kern_dec(short id,
              galapagos_interface * in,
              galapagos_interface * out) {
#pragma HLS_DATAFLOW
#pragma HLS INTERFACE ap_ctrl_none port=return
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
    
    static IN cipherT, keyT;
    
    static int flag = 0;
    size_t size;
    short dest, src;
    if (flag < 2)
    {
        if (!in->empty()){
            
            galapagos_packet data;
            data = in->read();
            src = data.id;
            
            if (src == 3) {
                // packet received from enc kernel (id = 3)
                cipherT = (ap_uint<128>)data.data;
                
                flag=flag+1;
            }
            if (src == 2) {
                // packet received from rsa kernel (id = 2)
                keyT = (ap_uint<128>)data.data;
                
                flag=flag+1;
            }
        }
    }
    else if (flag == 2){
        
        //
        // key schedule round
        //IO_DATA_TYPE keyT = key.read();
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
        //    cipher_block[i - 1] = cipherT  & 0xff;
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
        
        //
        // write back the results
        IO_DATA_TYPE plainT = 0;
    lp14:for (i = 0; i < AES_BLOCK_SIZE - 1; ++i) {
#pragma HLS unroll
        plainT |= plain[i];
        plainT <<= 8;
    }
        plainT |= plain[15];
        
        // send the deciphered text to the init kernel (id = 0)
        galapagos_packet data;
        data.dest = 0;
        data.id = 4;
        data.keep = KEEP_ALL;
        data.last = 1;
        data.user = 1; // this is used for size of the packet; don't forget to set it to one
        data.data = plainT;
        out->write(data);
        
        flag = 24;
    } else if (flag > 3){
        return;
    }
}
