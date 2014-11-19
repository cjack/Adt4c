#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define CLEAN_FILE(filename) fclose(fopen(filename, "w+"));


int main(){

	const int repeat = 100;

	int i;
	for (i = 0; i < repeat; ++i){
		system("free_adt");
		system("free_c");
	}
	FILE *fp;
	char filename[] = "result_free";
	if((fp = fopen(filename, "r")) == NULL){
		fprintf(stderr, "Cannot open file %s\n", filename);
		exit(-1);
	}
	const int str_len = 50;
	const char C[] = "C";
	const char ADT[] = "ADT";
	char str[str_len], equal;
	double num, total = 0, counter = 0;
	double a_sum = 0, c_sum = 0;
	while(fscanf(fp, "%s %c %lf", &str, &equal, &num) != EOF){
		if(strcmp(str, C) == 0){
			c_sum += num;
		}else if(strcmp(str, ADT) == 0){
			a_sum += num;
		}
		total = total + num;
		counter++;
	}
	counter = counter / 2;
	a_sum = a_sum / counter;
	c_sum = c_sum / counter;
	printf("\nThe total repeat times of program execution: %d\n", repeat);
	printf("The average time use in c version is %lf\n", c_sum);
	printf("The average time use in ADT version is %lf\n", a_sum);

	fclose(fp);
	// CLEAN_FILE(filename)
	return EXIT_SUCCESS;
}
