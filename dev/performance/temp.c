#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adt_t.h"
#include <time.h>

//------------------------------------------------------------------------------
/*
Macros for checking the time used
*/
FILE *fp;
double TIME1, Time2;
#define TIME_CHECK_START()	{TIME1 = (double)clock() / CLOCKS_PER_SEC;}
#define TIME_CHECK_END()	\
{Time2 = (double)clock() / CLOCKS_PER_SEC;\
printf("Time used = %lf\n", Time2 - TIME1);}
#define TOTAL_TIME_USED() \
{double ans = (double)clock() / CLOCKS_PER_SEC; \
printf("Total Time used = %lf\n", ans); \
fp= fopen("./result", "a+");\
fprintf(fp, "ADT = %lf\n", ans); \
fclose(fp);}
#define CHECK(str) \
{char s[] = str; printf("Check the time used of %s\n",s);}
#define BLANK_LINE() {printf("\n\n");}

//------------------------------------------------------------------------------
// char *remove_file_suffix(char* mystr) {
//     char *retstr;
//     if (mystr == NULL)
//          return NULL;
//     if ((retstr = (char *)malloc(strlen(mystr) + 1)) == NULL)
//         return NULL;
//     strcpy (retstr, mystr);
//     char *lastdot = strrchr (retstr, '.');
//     if (lastdot != NULL)
//         *lastdot = '\0';
//     return retstr;
// }

// void check_suffix(char *target, char *suffix){
// 	int t_len = strlen(target);
// 	int s_len = strlen(suffix);
// 	int i = 0;
// 	while(s_len > 0){
// 		printf("%c and %c\n", target[t_len - s_len], suffix[i]);
// 		if(target[t_len - s_len] != suffix[i]){
// 			fprintf(stderr, "\nERROR: %s should end with \"%s\"\n\n", target, suffix);
// 			exit(-1);
// 		}
// 		i++;
// 		s_len = s_len - 1;
// 	}
// }

typedef enum{
	EMPTY = 0, LEAF = 1, NODE = 2
} TreeKind;

struct Empty{
	TreeKind kind;
};

struct Leaf
{
	TreeKind kind;
	int value;
};
typedef union tree *utree;
struct Node{
	TreeKind kind;
	utree left;
	utree right;
};

union tree{
	struct Empty empty;
	struct Leaf leaf;
	struct Node node;
};

union tree insert_tree_c(union tree t, int times){
	union tree *p = &t;
	while(times--){
		union tree *t1 = (union tree *)malloc(sizeof(union tree));
		union tree *t2 = (union tree *)malloc(sizeof(union tree));
		*t1 = *p;
		*t2 = *p;
		p -> node.left = t1;
		p -> node.right = t2;
	}
	return *p;
}

Tree insert_tree_adt(Tree t, int times){
	Tree *p = &t;
	while(times--){
		Tree *t1 = (Tree *)malloc(sizeof(Tree));
		Tree *t2 = (Tree *)malloc(sizeof(Tree));
		*t1 = t;
		*t2 = t;
		*p = Node(*t1, *t2);
	}
	return *p;
}
long long total_nodes_c(union tree t){
	TreeKind tag = t.node.kind;
	if(tag == LEAF) return 1;
	else{
		return 1 + total_nodes_c(*t.node.left) + total_nodes_c(*t.node.right);
	}
}
long long total_nodes_adt(Tree t){
	if_Node(t, l, r)
		return 1 + total_nodes_adt(l) + total_nodes_adt(r);
	else()
		return 1;
	end_if()
}

long long count_size_c(union tree t){
	TreeKind tag = t.node.kind;
	if(tag == LEAF) return sizeof(t);
	else{
		return sizeof(t) + count_size_c(*t.node.left) + count_size_c(*t.node.right);
	}
}
long long count_size_adt(Tree t){
	if_Node(t, l, r)
		return sizeof(t) + count_size_adt(l) + count_size_adt(r);
	else()
		return sizeof(t);
	end_if()

}
int add_tree_c(union tree t){
	TreeKind tag = t.node.kind;
	if(tag == LEAF) return t.leaf.value;
	else if(tag == NODE) return add_tree_c(*t.node.left) + add_tree_c(*t.node.right);
	else return 0;
}
int main(){
	const int times = 25;
	union tree t;
	struct Leaf l, r;
	l.kind = LEAF;
	l.value = 1;
	r = l;
	t.node.kind = NODE;
	t.node.left = &l;
	t.node.right = &r;
	t = insert_tree_c(t, times);
	// insert_c(&t);
	int num = add_tree_c(t);
	printf("The result is %d\n", add_tree_c(t));



	Tree l1 = Leaf(1);
	Tree r1 = Leaf(1);
	Tree adt_t = Node(l1, r1);
	adt_t = insert_tree_adt(adt_t, times);
	TIME_CHECK_START()
	printf("The total space occupied by union tree is %lld\n", count_size_c(t));
	printf("The total nodes in union tree are %lld\n", total_nodes_c(t));
	TIME_CHECK_END()
	TIME_CHECK_START()
	printf("The total space occupied by ADT tree is %lld\n", count_size_adt(adt_t));
	printf("The total nodes in ADT tree are %lld\n", total_nodes_adt(adt_t));
	TIME_CHECK_END()
	return 0;
}


	// char s[] = "test.adt";
	// char suffix[] = ".adt";
	// check_suffix(s, suffix);
	// printf("suffix checksum is successful\n");
	// FILE *fp = fopen("./result", "w+");
	// fprintf(fp, "test input\n");


	// int total_num = 100000000;
	// int leaf_num = total_num / 2;
	// int node_num = total_num - leaf_num;
	// int space_c = 12;
	// int space_node = 8;
	// int space_leaf = 4;
	// printf("The total space occupied by union tree is %d\n", total_num * space_c);
	// printf("The total space occupied by ADT tree is %d\n", space_leaf * leaf_num + space_node * node_num);

	// union tree t;
	// Tree adt = Empty();
	// Test test = non_const_9(10);
	// printf("Memory size occupied by union tree : %d\n", sizeof(t));
	// Tree a = Leaf(1);
	// Tree b = Leaf (2);
	// adt = Node(a, b);
	// struct _ADT_Tree_Node adt_node;
	// struct _ADT_Tree_Leaf adt_left;
	// struct _ADT_Tree_Empty adt_empty;
	// printf("Memory size occupied by adt_node: %d\n", sizeof(adt_node));
	// printf("Memory size occupied by adt_leaf: %d\n", sizeof(adt_left));
	// printf("Memory size occupied by adt_empty: %d\n", sizeof(adt_empty));
