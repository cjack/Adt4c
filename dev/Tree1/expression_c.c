#include <stdio.h>
#include <stdlib.h>
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


#define expr struct expr_struct
typedef enum {
EXPR_NUM, EXPR_VAR, EXPR_BINOP, EXPR_UNOP
} ExprKind;
typedef struct expr_struct *Expr;

struct Binop{
	Expr e1;
	Expr e2;
};

struct Unop{
	Expr e;
};
union expr_val{
	int value; /* if EXPR_NUM */
	char *name; /* if EXPR_VAR */
	struct Binop binop; /* if EXPR_BINOP */
	struct Unop unop; /* if EXPR_UNOP */
};

struct expr_struct
{
	ExprKind kind;
	union expr_val subexpr;
};



Expr double_expr(Expr a){
	struct Binop binop = {a, a};
	Expr b = malloc(sizeof(expr));
	b -> kind = EXPR_BINOP;
	b -> subexpr.binop = binop; 
	// expr b = {EXPR_BINOP, binop};
	return b;
}

Expr build_expr(Expr a, int times){
	// expr b = *a;
	while(times--){
		a = double_expr(a);
		// b = *a;
	}
	return a;
}

long long val_sum(Expr a){
	if(a -> kind == 0){
		// printf("check here\n");
		return a -> subexpr.value;
		
	}

	if(a -> kind == 2){
		return val_sum(a -> subexpr.binop.e1) + val_sum(a -> subexpr.binop.e2); 
	}
	return 0;
}
int main(){
	int times = 10, i = 0;
	long long x;
	while(i++ < times){
		Expr a = malloc(sizeof(expr));
		a -> kind = EXPR_NUM;
		a -> subexpr.value = 1;
		Expr t = malloc(sizeof(expr));
		t -> kind = EXPR_BINOP;
		t -> subexpr.binop.e1 = a;
		t -> subexpr.binop.e2 = a;

		TIME_CHECK_START()
		int num_nodes = 29;
		t = build_expr(t, num_nodes);
		x = val_sum(t);
		TIME_CHECK_END()
	}
printf("The total time used is %lf\n", total);
printf("The average time used is %lf\n", (total / times));
printf("The total value is %lld\n", x);




	// printf("The total value is %lld\n", x);



	return EXIT_SUCCESS;
}
