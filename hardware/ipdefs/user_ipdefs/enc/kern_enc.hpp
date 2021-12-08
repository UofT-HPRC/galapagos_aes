#include "ap_int.h"
#include "hls_stream.h"
#include "ap_utils.h"
#include "packet_size.h"
#include "galapagos_packet.h"

#define SENDER_ID 1

#define AES_BLOCK_SIZE 16
#define AES_COL_SIZE 4
#define AES_ROUNDS 10
#define AES_ROUND_KEY_SIZE 176
#define DATA_SIZE 8

typedef ap_uint<8> DATA_TYPE;
typedef ap_uint<128> IO_DATA_TYPE;
typedef ap_uint<128> IN;

typedef ap_uint<PACKET_DATA_LENGTH> T;

typedef ap_uint<512> big_mult_t;

typedef struct data_t{
	ap_uint<32> dest;
	ap_uint<128> value;
	bool last;
	bool keep;
} data;

void kern_enc(
    short id, 
    galapagos_interface * in, 
    galapagos_interface * out
);

