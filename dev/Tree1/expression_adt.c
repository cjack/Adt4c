#include <stdio.h>
#include <stdlib.h>
#include "adt_t.h"
#include <time.h>


//------------------------------------------------------------------------------
/*
Macros for checking the time used
*/
double t1, t2, temp;
double total = 0;
#define TIME_CHECK_START()	{t1 = (double)clock() / CLOCKS_PER_SEC;}
#define TIME_CHECK_END()	\
{t2 = (double)clock() / CLOCKS_PER_SEC;\
temp = t2 - t1; total += temp; \
printf("Time used = %lf\n", temp);}
#define TOTAL_TIME_USED() \
{printf("Total Time used = %lf\n", (double)clock() / CLOCKS_PER_SEC);}
#define CHECK(str) \
{char s[] = str; printf("Check the time used of %s\n",s);}
#define BLANK_LINE() {printf("\n\n");}

//------------------------------------------------------------------------------

// data Expr{
// 	Val(int);
// 	Name(char*);
// 	Binop(Expr, Expr);
// 	Unop(Expr);
// }

long long val_sum(Expr a){
	if_Val(a, val)
		// printf("check here%d\n", val);
		return val;
	end_if()

	if_Binop(a, e1, e2)
		return val_sum(e1) + val_sum(e2);
	end_if()
	return 0;
}

Expr double_expr(Expr a){
	return Binop(a, a); 
}

Expr build_expr(Expr a, int times){
	while(times--)
		a = double_expr(a);
	return a;
}
// void free_expr(Expr a){
// 	if_Val(a, val)
// 		// printf("check here%d\n", val);
// 		free(a);
// 	end_if()

// 	if_Binop(a, e1, e2)
// 		free_expr(e1);
// 		free_expr(e2);
// 	end_if()
// }
int main(){
	
	// printf("The total value is %d\n", val_sum(t));
	int times = 10, i = 0;
	long long x;
	while(i++ < times){
		Expr t = Binop(Val(1), Val(1));
		int num_nodes = 29;
		TIME_CHECK_START()
		t = build_expr(t, num_nodes);
		x = val_sum(t);
	
		// printf("The total value is %lld\n", x);	

		TIME_CHECK_END()

}
printf("The total time used is %lf\n", total);
printf("The average time used is %lf\n", (total / times));
printf("The total value is %lld\n", x);

	data tree{
		Empty();
		
	}
	// free_expr(t);
	return EXIT_SUCCESS;
}
