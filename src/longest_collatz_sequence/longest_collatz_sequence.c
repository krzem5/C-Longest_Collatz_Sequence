#ifdef _MSC_VER
#include <intrin.h>
#endif
#include <longest_collatz_sequence.h>
#include <stdint.h>



#ifdef _MSC_VER
#pragma intrinsic(_BitScanForward64)
static uint32_t inline COUNT_TRAILING_ZEROS(uint64_t x){
	uint32_t out;
	_BitScanForward64(&out,x);
	return out;
}
#else
#define COUNT_TRAILING_ZEROS(x) __builtin_ctzll((x))
#endif



static uint16_t _table[1<<TABLE_SIZE_SHIFT];



static uint16_t _calculate_collatz_sequence_length(uint64_t x){
	uint16_t out=COUNT_TRAILING_ZEROS(x);
	x>>=out;
	uint16_t bias=out;
	uint64_t y=x>>1;
	while (x!=1){
		uint64_t z=x>>1;
		if (!(z>>TABLE_SIZE_SHIFT)&&_table[z]){
			out+=_table[z];
			break;
		}
		x+=(x<<1)+1;
		uint16_t w=COUNT_TRAILING_ZEROS(x);
		x>>=w;
		out+=w+1;
	}
	if (!(y>>TABLE_SIZE_SHIFT)){
		_table[y]=out-bias;
	}
	return out;
}



uint16_t longest_collatz_sequence(uint64_t from,uint64_t to,uint64_t* longest_start_ptr){
	if (from<2){
		from=2;
	}
	if (to<=from){
		to=from+1;
	}
	uint16_t longest_length=0;
	uint64_t longest_start=0;
	while (from<to){
		uint16_t length=_calculate_collatz_sequence_length(from);
		if (length>longest_length){
			longest_length=length;
			longest_start=from;
		}
		from++;
	}
	if (longest_start_ptr){
		*longest_start_ptr=longest_start;
	}
	return longest_length;
}
