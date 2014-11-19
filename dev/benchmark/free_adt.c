#include <stdio.h>
#include <stdlib.h>
#include "adt_t.h"
#include <time.h>

//Indicate how many times to repeat
int times = 10000;
double sum = 0;
//------------------------------------------------------------------------------
/*
Macros for checking the time used
*/
FILE *fp;
double t1, t2;
#define TIME_CHECK_START()	{t1 = (double)clock() / CLOCKS_PER_SEC;}
#define TIME_CHECK_END()	\
{t2 = (double)clock() / CLOCKS_PER_SEC;\
sum += t2;\
printf("Time used = %lf\n", t2 - t1);}
#define TOTAL_TIME_USED() \
{double ans = (double)clock() / CLOCKS_PER_SEC; \
printf("Total Time used = %lf\n", ans); \
printf("Average Time used = %lf\n", sum / times);\
fp= fopen("result_free", "a+");\
fprintf(fp, "ADT = %lf\n", sum / times); \
fclose(fp);}
#define CHECK(str) \
{char s[] = str; printf("Check the time used of %s\n",s);}
#define BLANK_LINE() {printf("\n\n");}

//------------------------------------------------------------------------------

int _ADT_list_length(int_list input){
	int_list p = input;
	int len = 0;
	while(1){
		if_next_list(p, val, next)
			len++;
			p = next;
		else()
			return len;
		end_if()

	}
}


void add_adt_list(int_list *input, int count){
	if(count == 0) return;
	*input = next_list(1, *input);
	add_adt_list(input, count - 1);
}

void add_adt_list2(int_list *input, int count){
	while(count--){
		*input = next_list(1, *input);
	}
}

void free_adt_list(int_list *input){
	int_list temp;
	while(1){
		if_next_list(*input, val, next)
			temp = *input;
			*input = next;
			free(temp);
		else()
			return;
		end_if()
	}
}

void run(){
	int_list adt_p = nil();
	adt_p = next_list(1, adt_p);

	//add list nodes
	int count = 1000000;
	int_list *q = &adt_p;


	CHECK("List Construction && Free")
	printf("Repeat %d times\n", times);

	while(times--){
		TIME_CHECK_START()
		adt_p = nil();
		adt_p = next_list(0, adt_p);
		add_adt_list2(q, count);
		free_adt_list(q);
		TIME_CHECK_END()
	}
	TOTAL_TIME_USED()
}

int main(){
	run();
	return EXIT_SUCCESS;
}






