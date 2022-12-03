#include <longest_collatz_sequence.h>
#include <stdint.h>
#include <stdio.h>



#define BOUND_LOWER 0ull
#define BOUND_UPPER 100000000ull
	
	

int main(int argc,const char** argv){
	uint64_t value=0;
	uint16_t length=longest_collatz_sequence(BOUND_LOWER,BOUND_UPPER,&value);
	printf("Longest collatz sequence between %llu and %llu: %u (start=%lu)\n",BOUND_LOWER,BOUND_UPPER,length,value);
	return 0;
}
