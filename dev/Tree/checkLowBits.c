#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

// set up the upper bound value
#define INF 9999999999999;
#define MAX_BITS 60

// return a binary number based on the num of bits given
long long binary_num(int num_of_bits){
	long long result = pow(2.0, num_of_bits) - 1;
	return result;
}

// return the number of low bits which is always 0
int check_low_bit(void *p){
	int i = 1;
	int t = ((uintptr_t)p);
	int b;
	while(i <= MAX_BITS){
		i++;
		b = binary_num(i);
		if((t & b) != 0){
			return i - 1;
		}
	}

	return i - 1;
}

int main(){
	// set up the default
	// times for outer loop

	int times = 100;
	int i;
	const int MAX = 10001;
	int min_bits = MAX_BITS;
	long long min_value = INF;
	int temp;
	void *p[MAX];
	while(times--){
		int i = 1;
			//malloc from 1 to max
			for(i = 1; i < MAX; i++){
				printf("Processing ---- current malloc size is: %d\n", i);
				p[i] = (void *)malloc(i);
				//check the low-bits each time;
				temp = check_low_bit(p[i]);
				if(temp < min_bits){
					min_bits = temp;
				}
				//check the low-value here
				if(((uintptr_t)p[i]) < min_value){
					min_value = ((uintptr_t)p[i]);
				}
			}
			//free every second record
			for(i = 2; i < MAX; i+=2){
				free(p[i]);
			}
	}
	printf("The minimal available low bits is %d\n", min_bits);
	printf("The acceptable min_value is %lld\n", min_value);
	FILE *fp;
	fp = fopen("LOW_BITS.h", "w");
	fprintf(fp, "#define LOW_BIT_USED %lld\n", binary_num(min_bits));
	fprintf(fp, "#define MIN_ADDRESS %lld\n", min_value);
	return EXIT_SUCCESS;
}