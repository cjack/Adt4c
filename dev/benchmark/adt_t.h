#include <stdint.h>
#include <stdlib.h>
typedef char *c_string;
#define end_switch() }}}}
#define default() break;}} default: {{
#define else() } else {
#define end_if() }}
#define LOW_BIT_USED 7
/***************************/
typedef struct _ADT_Tree{} *Tree;
#define Tree_T_NUM_CONST (1)
#define Tree_T_NUM_NONCONST (2)
#define Tree_constructorNum(v) \
(( Tree_T_NUM_NONCONST>0 && v >= Tree_T_NUM_CONST ?  \
 ( Tree_T_NUM_NONCONST==1 ?  Tree_T_NUM_CONST   : \
(( Tree_T_NUM_NONCONST > (LOW_BIT_USED + 1))  && ((v&LOW_BIT_USED) == (LOW_BIT_USED))  )  ?   \
 (*(int*)((uintptr_t)v-LOW_BIT_USED)) + Tree_T_NUM_CONST  : \
((v&(LOW_BIT_USED)) + Tree_T_NUM_CONST)) : v ) )

;
#define switch_Tree(v) \
{Tree _Tree_t; \
int t = Tree_constructorNum((uintptr_t)(v)); \
switch(t) {{{


/******************************************************************************/
static __inline void free_Tree(Tree v){
	if ((uintptr_t)(v) >= 1){
		free((void*)((uintptr_t)v&~LOW_BIT_USED));
	}
}


struct _ADT_Tree_Empty {};
#define if_Empty(v) \
{if (((uintptr_t)(v))==0) {
#define else_if_Empty() \
} else if (((uintptr_t)(v))==0) {
#define if_Empty_ptr(v) \
{if (((uintptr_t)(v))==0) {
#define case_Empty() \
break;}} case 0: {{Tree _SW_tchk=_Tree_tchk;}{char _Tree_tchk;
#define case_Empty_ptr() \
break;}} case 0: {{Tree _SW_tchk=_Tree_tchk;}{char _Tree_tchk;

static __inline Tree Empty(){
	struct _ADT_Tree_Empty *v=(struct _ADT_Tree_Empty*)0;
	return (Tree)((uintptr_t)v);
}

struct _ADT_Tree_Leaf {
    int f0;};
#define if_Leaf(v, v0) \
{if (((uintptr_t)(v)&LOW_BIT_USED)==0) {\
int v0=((struct _ADT_Tree_Leaf*)((uintptr_t)v-0))->f0;
#define else_if_Leaf(v0) \
} else if ((uintptr_t)(v) >= 1 && ((uintptr_t)(v)&LOW_BIT_USED)==0)  {\
int v0=((struct _ADT_Tree_Leaf*)((uintptr_t)v-0))->f0;
#define if_Leaf_ptr(v, v0) \
{if ((uintptr_t)(v) >= 1 && ((uintptr_t)(v)&LOW_BIT_USED)==0)  {\
int *v0=&((struct _ADT_Tree_Leaf*)((uintptr_t)v-0))->f0;
#define case_Leaf(v0) \
break;}} case 1: {{Tree _SW_tchk=_Tree_tchk;}{char _Tree_tchk; \
int v0=((struct _ADT_Tree_Leaf*)((uintptr_t)v-0))->f0;
#define case_Leaf_ptr(v0) \
break;}} case 1: {{Tree _SW_tchk=_Tree_tchk;}{char _Tree_tchk; \
int *v0=&((struct _ADT_Tree_Leaf*)((uintptr_t)v-0))->f0;

static __inline Tree Leaf(int v0){
	struct _ADT_Tree_Leaf *v=(struct _ADT_Tree_Leaf*)malloc(sizeof(struct _ADT_Tree_Leaf));
	v->f0=v0;
	return (Tree)(0+(uintptr_t)v);
}

struct _ADT_Tree_Node {
    struct _ADT_Tree* f0;
    struct _ADT_Tree* f1;};
#define if_Node(v, v0, v1) \
{if ( ((uintptr_t)(v)&LOW_BIT_USED)==1) {\
struct _ADT_Tree* v0=((struct _ADT_Tree_Node*)((uintptr_t)v-1))->f0; \
struct _ADT_Tree* v1=((struct _ADT_Tree_Node*)((uintptr_t)v-1))->f1;
#define else_if_Node(v0, v1) \
} else if ((uintptr_t)(v) >= 1 && ((uintptr_t)(v)&LOW_BIT_USED)==1)  {\
struct _ADT_Tree* v0=((struct _ADT_Tree_Node*)((uintptr_t)v-1))->f0; \
struct _ADT_Tree* v1=((struct _ADT_Tree_Node*)((uintptr_t)v-1))->f1;
#define if_Node_ptr(v, v0, v1) \
{if ((uintptr_t)(v) >= 1 && ((uintptr_t)(v)&LOW_BIT_USED)==1)  {\
struct _ADT_Tree* *v0=&((struct _ADT_Tree_Node*)((uintptr_t)v-1))->f0; \
struct _ADT_Tree* *v1=&((struct _ADT_Tree_Node*)((uintptr_t)v-1))->f1;
#define case_Node(v0, v1) \
break;}} case 2: {{Tree _SW_tchk=_Tree_tchk;}{char _Tree_tchk; \
struct _ADT_Tree* v0=((struct _ADT_Tree_Node*)((uintptr_t)v-1))->f0; \
struct _ADT_Tree* v1=((struct _ADT_Tree_Node*)((uintptr_t)v-1))->f1;
#define case_Node_ptr(v0, v1) \
break;}} case 2: {{Tree _SW_tchk=_Tree_tchk;}{char _Tree_tchk; \
struct _ADT_Tree* *v0=&((struct _ADT_Tree_Node*)((uintptr_t)v-1))->f0; \
struct _ADT_Tree* *v1=&((struct _ADT_Tree_Node*)((uintptr_t)v-1))->f1;

static __inline Tree Node(struct _ADT_Tree* v0, struct _ADT_Tree* v1){
	struct _ADT_Tree_Node *v=(struct _ADT_Tree_Node*)malloc(sizeof(struct _ADT_Tree_Node));
	v->f0=v0;
	v->f1=v1;
	return (Tree)(1+(uintptr_t)v);
}
