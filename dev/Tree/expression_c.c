typedef enum {
EMPTY, LEAF, NODE
} TreeKind;
typedef struct Tree *tree;

struct tree_struct
{
TreeKind kind;
union tree_data{
	int val;
	tree left;
	tree right;
	}
};

#include <stdio.h>
#include <stdlib.h>

typedef enum {
EXPR_NUM, EXPR_VAR, EXPR_BINOP, EXPR_UNOP
} ExprKind;
typedef struct expr_struct *Expr;

struct expr_struct
{
ExprKind kind;
int value; /* if EXPR_NUM */
char *name; /* if EXPR_VAR */
Binop binop; /* if EXPR_BINOP */
Unop unop; /* if EXPR_UNOP */
Expr subexpr1; /* if EXPR_BINOP or EXPR_UNOP */
Expr subexpr2; /* if EXPR_BINOP */
};


int main(){

	return EXIT_SUCCESS;
}


