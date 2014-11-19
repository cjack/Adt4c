#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const int repeat = 10;

#define CLEAN_FILE(filename) fclose(fopen(filename, "w"));
double t1, t2, tm;
#define TIME_CHECK_START() {t1 = (double)clock() / CLOCKS_PER_SEC;}
#define TIME_CHECK_END() \
{t2 = (double)clock() / CLOCKS_PER_SEC;\
tm = t2 - t1;\
printf("The total time used is %lfs\n", tm); \
printf("The average time used is %lfs\n", tm / repeat);}
#define CHECK(str) \
{char s[] = str; printf("Check the time used of %s\n",s);}
#define BLANK_LINE() {printf("\n\n");}

int main(){

	int times = 100;
	while(times--){
		system("temp");
	}

	// int i;
	// CHECK("C version");
	// TIME_CHECK_START()
	// for (i = 0; i < repeat; ++i){
	// 	system("c_version");
	// }
	// TIME_CHECK_END()

	// BLANK_LINE()
	// CHECK("ADT version");
	// TIME_CHECK_START()
	// for (i = 0; i < repeat; ++i){
	// 	system("adt_version");
	// }
	// TIME_CHECK_END()


	// FILE *fp;
	// char filename[] = "result";
	// if((fp = fopen(filename, "r")) == NULL){
	// 	fprintf(stderr, "Cannot open file %s\n", filename);
	// 	exit(-1);
	// }


	// const int str_len = 50;
	// const char C[] = "C";
	// const char ADT[] = "ADT";
	// char str[str_len], equal;
	// double num, total = 0, counter = 0;
	// double a_sum = 0, c_sum = 0;
	// while(fscanf(fp, "%s %c %lf", &str, &equal, &num) != EOF){
	// 	if(strcmp(str, C) == 0){
	// 		c_sum += num;
	// 	}else if(strcmp(str, ADT) == 0){
	// 		a_sum += num;
	// 	}
	// 	total = total + num;
	// 	counter++;
	// }
	// counter = counter / 2;
	// a_sum = a_sum / counter;
	// c_sum = c_sum / counter;
	// printf("\nThe total repeat times of program execution: %d\n", repeat);
	// printf("The average time use in c version is %lf\n", c_sum);
	// printf("The average time use in ADT version is %lf\n", a_sum);

	// fclose(fp);
	// CLEAN_FILE(filename)
	return EXIT_SUCCESS;
}
