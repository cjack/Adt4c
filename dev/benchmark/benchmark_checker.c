#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//------------------------------------------------------------------------------
/*
Macros for checking the time used
*/
FILE *fp;
double t1, t2;
#define TIME_CHECK_START()	{t1 = (double)clock() / CLOCKS_PER_SEC;}
#define TIME_CHECK_END()	\
{t2 = (double)clock() / CLOCKS_PER_SEC;\
printf("Time used = %lf\n", t2 - t1);}
#define TOTAL_TIME_USED() \
{double ans = (double)clock() / CLOCKS_PER_SEC; \
printf("Total Time used = %lf\n", ans); \
fp= fopen("result", "a+");\
fprintf(fp, "C = %lf\n", ans);\
fclose(fp);}
#define CHECK(str) \
{char s[] = str; printf("Check the time used of %s\n",s);}
#define BLANK_LINE() {printf("\n\n");}


//------------------------------------------------------------------------------


struct list
{
	int value;
	struct list *next;
};

// count the length of list in oriental c code
int _c_list_length(struct list *input){
	int len = 0;
	while(1){
		if(input == NULL) break;
		len++;
		input = input -> next;
	}
	return len;
}

//add the list by count
void add_c_list(struct list *input, int count){
	if(count == 0) return;
	struct list *temp = (struct list *)malloc(sizeof(struct list));
	temp -> value = 1;
	temp -> next = NULL;
	input -> next = temp;
	add_c_list(temp, count - 1);
}

void add_c_list2(struct list *input, int count){
	struct list *p = input;
	while(count--){
		struct list *temp = (struct list *)malloc(sizeof(struct list));
		temp -> value = 1;
		temp -> next = NULL;
		p -> next = temp;
		p = p -> next;
	}
}

void free_c_list(struct list *input){
	struct list *temp;

	while(1){
		if(input != NULL){
			temp = input;
			input = input -> next;
			free(temp);
		}else{
			return;
		}
	}

}

void run(){
	struct list *p = (struct list *)malloc(sizeof(struct list));
	p -> value = 1;
	p -> next = NULL;

	printf("Start Checking of C List\n");
	BLANK_LINE()
	//add list nodes
	int count = 999999;
	//Indicate how many times to repeat
	int times = 10000;

	CHECK("List Construction")
	TIME_CHECK_START()
	add_c_list2(p, count);
	TIME_CHECK_END()

	CHECK("list length")
	TIME_CHECK_START()
	int c_len;
	printf("Repeat %d times\n", times);
	while(times--)
		c_len = _c_list_length(p);
	printf("The length in c list is %d\n", c_len);
	TIME_CHECK_END()

	CHECK("Free function")
	TIME_CHECK_START()
	free_c_list(p);
	TIME_CHECK_END()

	TOTAL_TIME_USED()
	BLANK_LINE()
}

void run2(){
	//skip all print out
	struct list *p = (struct list *)malloc(sizeof(struct list));
	p -> value = 1;
	p -> next = NULL;

	//add list nodes
	int count = 999999;
	//Indicate how many times to repeat
	int times = 10000;

	add_c_list2(p, count);

	int c_len;
	while(times--)
		c_len = _c_list_length(p);

	free_c_list(p);
}
int main(){
	run2();
	return EXIT_SUCCESS;
}
