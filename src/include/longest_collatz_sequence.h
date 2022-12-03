#ifndef _LONGEST_COLLATZ_SEQUENCE_H_
#define _LONGEST_COLLATZ_SEQUENCE_H_ 1
#include <stdint.h>
	
	
	
#define TABLE_SIZE_SHIFT 29



uint16_t longest_collatz_sequence(uint64_t from,uint64_t to,uint64_t* longest_start_ptr);



#endif
