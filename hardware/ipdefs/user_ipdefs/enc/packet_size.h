#ifndef PACKET_SIZE_H
#define PACKET_SIZE_H


//#ifndef CPU
//#define INTERFACE_100G
//#endif

#ifdef INTERFACE_100G
# define PACKET_DATA_LENGTH 512 
# define PACKET_KEEP_LENGTH 64
# define PACKET_LAST
# define PACKET_USER_LENGTH 16
# define PACKET_DEST_LENGTH 8
#else
# define PACKET_DATA_LENGTH 64
# define PACKET_KEEP_LENGTH 8
# define PACKET_LAST
# define PACKET_USER_LENGTH 16
# define PACKET_DEST_LENGTH 8
#endif
#endif
