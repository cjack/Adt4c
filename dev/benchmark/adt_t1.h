#include <stdint.h>
#include <stdlib.h>
typedef char *c_string;
#define end_switch() }}}}
#define default() break;}} default: {{
#define else() } else {
#define end_if() }}
#define LOW_BIT_USED 7
/***************************/
typedef struct _ADT_double_non_constant{} *double_non_constant;
#define double_non_constant_T_NUM_CONST (0) 
#define double_non_constant_T_NUM_NONCONST (2) 
#define double_non_constant_constructorNum(v) \
(( double_non_constant_T_NUM_NONCONST>0 && v > double_non_constant_T_NUM_CONST-1 ?  \
 ( double_non_constant_T_NUM_NONCONST==1 ?  double_non_constant_T_NUM_CONST   : \
(( double_non_constant_T_NUM_NONCONST > (LOW_BIT_USED + 1))  && ((v&LOW_BIT_USED) == (LOW_BIT_USED))  )  ?   \
 (*(int*)((uintptr_t)_ADT_v-LOW_BIT_USED)) + double_non_constant_T_NUM_CONST  : \
((v&(LOW_BIT_USED)) + double_non_constant_T_NUM_CONST)) : v ) )

;
#define switch_double_non_constant(v) \
{double_non_constant _double_non_constant_tchk, _ADT_v=(v); \
int t = double_non_constant_constructorNum((uintptr_t)(_ADT_v)); \
switch(t) {{{


/******************************************************************************/
static __inline void free_double_non_constant(double_non_constant v){
	free((void*)((uintptr_t)v&~LOW_BIT_USED));
}


struct _ADT_double_non_constant_non_1 {
    int f0;};
#define if_non_1(v, v0) \
{double_non_constant _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 0 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==0) {\
int v0=((struct _ADT_double_non_constant_non_1*)((uintptr_t)_ADT_v-0))->f0; 
#define else_if_non_1(v0) \
} else if ((uintptr_t)(_ADT_v) >= 0 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==0)  {\
int v0=((struct _ADT_double_non_constant_non_1*)((uintptr_t)_ADT_v-0))->f0; 
#define if_non_1_ptr(v, v0) \
{double_non_constant _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 0 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==0)  {\
int *v0=&((struct _ADT_double_non_constant_non_1*)((uintptr_t)_ADT_v-0))->f0; 
#define case_non_1(v0) \
break;}} case 0: {{double_non_constant _SW_tchk=_double_non_constant_tchk;}{char _double_non_constant_tchk; \
int v0=((struct _ADT_double_non_constant_non_1*)((uintptr_t)_ADT_v-0))->f0; 
#define case_non_1_ptr(v0) \
break;}} case 0: {{double_non_constant _SW_tchk=_double_non_constant_tchk;}{char _double_non_constant_tchk; \
int *v0=&((struct _ADT_double_non_constant_non_1*)((uintptr_t)_ADT_v-0))->f0; 

static __inline double_non_constant non_1(int v0){
	struct _ADT_double_non_constant_non_1 *v=(struct _ADT_double_non_constant_non_1*)malloc(sizeof(struct _ADT_double_non_constant_non_1));
	v->f0=v0; 
	return (double_non_constant)(0+(uintptr_t)v);
}

struct _ADT_double_non_constant_non_2 {
    int f0;};
#define if_non_2(v, v0) \
{double_non_constant _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 1 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==0) {\
int v0=((struct _ADT_double_non_constant_non_2*)((uintptr_t)_ADT_v-1))->f0; 
#define else_if_non_2(v0) \
} else if ((uintptr_t)(_ADT_v) >= 1 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==0)  {\
int v0=((struct _ADT_double_non_constant_non_2*)((uintptr_t)_ADT_v-1))->f0; 
#define if_non_2_ptr(v, v0) \
{double_non_constant _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 1 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==0)  {\
int *v0=&((struct _ADT_double_non_constant_non_2*)((uintptr_t)_ADT_v-1))->f0; 
#define case_non_2(v0) \
break;}} case 1: {{double_non_constant _SW_tchk=_double_non_constant_tchk;}{char _double_non_constant_tchk; \
int v0=((struct _ADT_double_non_constant_non_2*)((uintptr_t)_ADT_v-1))->f0; 
#define case_non_2_ptr(v0) \
break;}} case 1: {{double_non_constant _SW_tchk=_double_non_constant_tchk;}{char _double_non_constant_tchk; \
int *v0=&((struct _ADT_double_non_constant_non_2*)((uintptr_t)_ADT_v-1))->f0; 

static __inline double_non_constant non_2(int v0){
	struct _ADT_double_non_constant_non_2 *v=(struct _ADT_double_non_constant_non_2*)malloc(sizeof(struct _ADT_double_non_constant_non_2));
	v->f0=v0; 
	return (double_non_constant)(1+(uintptr_t)v);
}

/***************************/
typedef struct _ADT_Tree{} *Tree;
#define Tree_T_NUM_CONST (1) 
#define Tree_T_NUM_NONCONST (2) 
#define Tree_constructorNum(v) \
(( Tree_T_NUM_NONCONST>0 && v > Tree_T_NUM_CONST-1 ?  \
 ( Tree_T_NUM_NONCONST==1 ?  Tree_T_NUM_CONST   : \
(( Tree_T_NUM_NONCONST > (LOW_BIT_USED + 1))  && ((v&LOW_BIT_USED) == (LOW_BIT_USED))  )  ?   \
 (*(int*)((uintptr_t)_ADT_v-LOW_BIT_USED)) + Tree_T_NUM_CONST  : \
((v&(LOW_BIT_USED)) + Tree_T_NUM_CONST)) : v ) )

;
#define switch_Tree(v) \
{Tree _Tree_tchk, _ADT_v=(v); \
int t = Tree_constructorNum((uintptr_t)(_ADT_v)); \
switch(t) {{{


/******************************************************************************/
static __inline void free_Tree(Tree v){
	if ((uintptr_t)(v) >= 1){
		free((void*)((uintptr_t)v&~LOW_BIT_USED));
	}
}


struct _ADT_Tree_Empty {};
#define if_Empty(v) \
{Tree _ADT_v=(v);if (((uintptr_t)(_ADT_v))==0) {
#define else_if_Empty() \
} else if (((uintptr_t)(_ADT_v))==0) {
#define if_Empty_ptr(v) \
{Tree _ADT_v=(v);if (((uintptr_t)(_ADT_v))==0) {
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
{Tree _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 0 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==1) {\
int v0=((struct _ADT_Tree_Leaf*)((uintptr_t)_ADT_v-0))->f0; 
#define else_if_Leaf(v0) \
} else if ((uintptr_t)(_ADT_v) >= 0 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==1)  {\
int v0=((struct _ADT_Tree_Leaf*)((uintptr_t)_ADT_v-0))->f0; 
#define if_Leaf_ptr(v, v0) \
{Tree _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 0 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==1)  {\
int *v0=&((struct _ADT_Tree_Leaf*)((uintptr_t)_ADT_v-0))->f0; 
#define case_Leaf(v0) \
break;}} case 1: {{Tree _SW_tchk=_Tree_tchk;}{char _Tree_tchk; \
int v0=((struct _ADT_Tree_Leaf*)((uintptr_t)_ADT_v-0))->f0; 
#define case_Leaf_ptr(v0) \
break;}} case 1: {{Tree _SW_tchk=_Tree_tchk;}{char _Tree_tchk; \
int *v0=&((struct _ADT_Tree_Leaf*)((uintptr_t)_ADT_v-0))->f0; 

static __inline Tree Leaf(int v0){
	struct _ADT_Tree_Leaf *v=(struct _ADT_Tree_Leaf*)malloc(sizeof(struct _ADT_Tree_Leaf));
	v->f0=v0; 
	return (Tree)(0+(uintptr_t)v);
}

struct _ADT_Tree_Node {
    struct _ADT_Tree* f0;
    struct _ADT_Tree* f1;};
#define if_Node(v, v0, v1) \
{Tree _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 1 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==1) {\
struct _ADT_Tree* v0=((struct _ADT_Tree_Node*)((uintptr_t)_ADT_v-1))->f0; \
struct _ADT_Tree* v1=((struct _ADT_Tree_Node*)((uintptr_t)_ADT_v-1))->f1; 
#define else_if_Node(v0, v1) \
} else if ((uintptr_t)(_ADT_v) >= 1 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==1)  {\
struct _ADT_Tree* v0=((struct _ADT_Tree_Node*)((uintptr_t)_ADT_v-1))->f0; \
struct _ADT_Tree* v1=((struct _ADT_Tree_Node*)((uintptr_t)_ADT_v-1))->f1; 
#define if_Node_ptr(v, v0, v1) \
{Tree _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 1 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==1)  {\
struct _ADT_Tree* *v0=&((struct _ADT_Tree_Node*)((uintptr_t)_ADT_v-1))->f0; \
struct _ADT_Tree* *v1=&((struct _ADT_Tree_Node*)((uintptr_t)_ADT_v-1))->f1; 
#define case_Node(v0, v1) \
break;}} case 2: {{Tree _SW_tchk=_Tree_tchk;}{char _Tree_tchk; \
struct _ADT_Tree* v0=((struct _ADT_Tree_Node*)((uintptr_t)_ADT_v-1))->f0; \
struct _ADT_Tree* v1=((struct _ADT_Tree_Node*)((uintptr_t)_ADT_v-1))->f1; 
#define case_Node_ptr(v0, v1) \
break;}} case 2: {{Tree _SW_tchk=_Tree_tchk;}{char _Tree_tchk; \
struct _ADT_Tree* *v0=&((struct _ADT_Tree_Node*)((uintptr_t)_ADT_v-1))->f0; \
struct _ADT_Tree* *v1=&((struct _ADT_Tree_Node*)((uintptr_t)_ADT_v-1))->f1; 

static __inline Tree Node(struct _ADT_Tree* v0, struct _ADT_Tree* v1){
	struct _ADT_Tree_Node *v=(struct _ADT_Tree_Node*)malloc(sizeof(struct _ADT_Tree_Node));
	v->f0=v0; 
	v->f1=v1; 
	return (Tree)(1+(uintptr_t)v);
}

/***************************/
typedef struct _ADT_one_non_const{} *one_non_const;
#define one_non_const_T_NUM_CONST (0) 
#define one_non_const_T_NUM_NONCONST (1) 
#define one_non_const_constructorNum(v) \
(( one_non_const_T_NUM_NONCONST>0 && v > one_non_const_T_NUM_CONST-1 ?  \
 ( one_non_const_T_NUM_NONCONST==1 ?  one_non_const_T_NUM_CONST   : \
(( one_non_const_T_NUM_NONCONST > (LOW_BIT_USED + 1))  && ((v&LOW_BIT_USED) == (LOW_BIT_USED))  )  ?   \
 (*(int*)((uintptr_t)_ADT_v-LOW_BIT_USED)) + one_non_const_T_NUM_CONST  : \
((v&(LOW_BIT_USED)) + one_non_const_T_NUM_CONST)) : v ) )

;
#define switch_one_non_const(v) \
{one_non_const _one_non_const_tchk, _ADT_v=(v); \
int t = one_non_const_constructorNum((uintptr_t)(_ADT_v)); \
switch(t) {{{


/******************************************************************************/
static __inline void free_one_non_const(one_non_const v){
	free((void*)((uintptr_t)v));
}


struct _ADT_one_non_const_non_const {
    int f0;};
#define if_non_const(v, v0) \
{one_non_const _ADT_v=(v);if (1) {\
int v0=((struct _ADT_one_non_const_non_const*)((uintptr_t)_ADT_v-0))->f0; 
#define else_if_non_const(v0) \
} else if (1) {\
int v0=((struct _ADT_one_non_const_non_const*)((uintptr_t)_ADT_v-0))->f0; 
#define if_non_const_ptr(v, v0) \
{one_non_const _ADT_v=(v);if (1) {\
int *v0=&((struct _ADT_one_non_const_non_const*)((uintptr_t)_ADT_v-0))->f0; 
#define case_non_const(v0) \
break;}} case 0: {{one_non_const _SW_tchk=_one_non_const_tchk;}{char _one_non_const_tchk; \
int v0=((struct _ADT_one_non_const_non_const*)((uintptr_t)_ADT_v-0))->f0; 
#define case_non_const_ptr(v0) \
break;}} case 0: {{one_non_const _SW_tchk=_one_non_const_tchk;}{char _one_non_const_tchk; \
int *v0=&((struct _ADT_one_non_const_non_const*)((uintptr_t)_ADT_v-0))->f0; 

static __inline one_non_const non_const(int v0){
	struct _ADT_one_non_const_non_const *v=(struct _ADT_one_non_const_non_const*)malloc(sizeof(struct _ADT_one_non_const_non_const));
	v->f0=v0; 
	return (one_non_const)(0+(uintptr_t)v);
}

/***************************/
typedef struct _ADT_Test2{} *Test2;
#define Test2_T_NUM_CONST (1) 
#define Test2_T_NUM_NONCONST (0) 
#define Test2_constructorNum(v) \
(( Test2_T_NUM_NONCONST>0 && v > Test2_T_NUM_CONST-1 ?  \
 ( Test2_T_NUM_NONCONST==1 ?  Test2_T_NUM_CONST   : \
(( Test2_T_NUM_NONCONST > (LOW_BIT_USED + 1))  && ((v&LOW_BIT_USED) == (LOW_BIT_USED))  )  ?   \
 (*(int*)((uintptr_t)_ADT_v-LOW_BIT_USED)) + Test2_T_NUM_CONST  : \
((v&(LOW_BIT_USED)) + Test2_T_NUM_CONST)) : v ) )


#define switch_Test2(v) \
{Test2 _Test2_tchk, _ADT_v=(v); \
int t = Test2_constructorNum((uintptr_t)(_ADT_v)); \
switch(t) {{{


/******************************************************************************/
static __inline void free_Test2(Test2 v){
}


struct _ADT_Test2_con {};
#define if_con(v) \
{Test2 _ADT_v=(v);if (1) {
#define else_if_con() \
} else if (1) {
#define if_con_ptr(v) \
{Test2 _ADT_v=(v);if (1) {
#define case_con() \
break;}} case 0: {{Test2 _SW_tchk=_Test2_tchk;}{char _Test2_tchk; 
#define case_con_ptr() \
break;}} case 0: {{Test2 _SW_tchk=_Test2_tchk;}{char _Test2_tchk; 

static __inline Test2 con(){
	struct _ADT_Test2_con *v=(struct _ADT_Test2_con*)0;
	return (Test2)((uintptr_t)v);
}

/***************************/
typedef struct _ADT_Test{} *Test;
#define Test_T_NUM_CONST (4) 
#define Test_T_NUM_NONCONST (9) 
#define Test_constructorNum(v) \
(( Test_T_NUM_NONCONST>0 && v > Test_T_NUM_CONST-1 ?  \
 ( Test_T_NUM_NONCONST==1 ?  Test_T_NUM_CONST   : \
(( Test_T_NUM_NONCONST > (LOW_BIT_USED + 1))  && ((v&LOW_BIT_USED) == (LOW_BIT_USED))  )  ?   \
 (*(int*)((uintptr_t)_ADT_v-LOW_BIT_USED)) + Test_T_NUM_CONST  : \
((v&(LOW_BIT_USED)) + Test_T_NUM_CONST)) : v ) )

;
#define switch_Test(v) \
{Test _Test_tchk, _ADT_v=(v); \
int t = Test_constructorNum((uintptr_t)(_ADT_v)); \
switch(t) {{{


/******************************************************************************/
static __inline void free_Test(Test v){
	if ((uintptr_t)(v) >= 4){
		free((void*)((uintptr_t)v&~LOW_BIT_USED));
	}
}


struct _ADT_Test_const_1 {};
#define if_const_1(v) \
{Test _ADT_v=(v);if (((uintptr_t)(_ADT_v))==0) {
#define else_if_const_1() \
} else if (((uintptr_t)(_ADT_v))==0) {
#define if_const_1_ptr(v) \
{Test _ADT_v=(v);if (((uintptr_t)(_ADT_v))==0) {
#define case_const_1() \
break;}} case 0: {{Test _SW_tchk=_Test_tchk;}{char _Test_tchk; 
#define case_const_1_ptr() \
break;}} case 0: {{Test _SW_tchk=_Test_tchk;}{char _Test_tchk; 

static __inline Test const_1(){
	struct _ADT_Test_const_1 *v=(struct _ADT_Test_const_1*)0;
	return (Test)((uintptr_t)v);
}

struct _ADT_Test_const_2 {};
#define if_const_2(v) \
{Test _ADT_v=(v);if (((uintptr_t)(_ADT_v))==1) {
#define else_if_const_2() \
} else if (((uintptr_t)(_ADT_v))==1) {
#define if_const_2_ptr(v) \
{Test _ADT_v=(v);if (((uintptr_t)(_ADT_v))==1) {
#define case_const_2() \
break;}} case 1: {{Test _SW_tchk=_Test_tchk;}{char _Test_tchk; 
#define case_const_2_ptr() \
break;}} case 1: {{Test _SW_tchk=_Test_tchk;}{char _Test_tchk; 

static __inline Test const_2(){
	struct _ADT_Test_const_2 *v=(struct _ADT_Test_const_2*)1;
	return (Test)((uintptr_t)v);
}

struct _ADT_Test_const_3 {};
#define if_const_3(v) \
{Test _ADT_v=(v);if (((uintptr_t)(_ADT_v))==2) {
#define else_if_const_3() \
} else if (((uintptr_t)(_ADT_v))==2) {
#define if_const_3_ptr(v) \
{Test _ADT_v=(v);if (((uintptr_t)(_ADT_v))==2) {
#define case_const_3() \
break;}} case 2: {{Test _SW_tchk=_Test_tchk;}{char _Test_tchk; 
#define case_const_3_ptr() \
break;}} case 2: {{Test _SW_tchk=_Test_tchk;}{char _Test_tchk; 

static __inline Test const_3(){
	struct _ADT_Test_const_3 *v=(struct _ADT_Test_const_3*)2;
	return (Test)((uintptr_t)v);
}

struct _ADT_Test_const_4 {};
#define if_const_4(v) \
{Test _ADT_v=(v);if (((uintptr_t)(_ADT_v))==3) {
#define else_if_const_4() \
} else if (((uintptr_t)(_ADT_v))==3) {
#define if_const_4_ptr(v) \
{Test _ADT_v=(v);if (((uintptr_t)(_ADT_v))==3) {
#define case_const_4() \
break;}} case 3: {{Test _SW_tchk=_Test_tchk;}{char _Test_tchk; 
#define case_const_4_ptr() \
break;}} case 3: {{Test _SW_tchk=_Test_tchk;}{char _Test_tchk; 

static __inline Test const_4(){
	struct _ADT_Test_const_4 *v=(struct _ADT_Test_const_4*)3;
	return (Test)((uintptr_t)v);
}

struct _ADT_Test_non_const_1 {
    int f0;
    char f1;
    long f2;
    double f3;};
#define if_non_const_1(v, v0, v1, v2, v3) \
{Test _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 0 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4) {\
int v0=((struct _ADT_Test_non_const_1*)((uintptr_t)_ADT_v-0))->f0; \
char v1=((struct _ADT_Test_non_const_1*)((uintptr_t)_ADT_v-0))->f1; \
long v2=((struct _ADT_Test_non_const_1*)((uintptr_t)_ADT_v-0))->f2; \
double v3=((struct _ADT_Test_non_const_1*)((uintptr_t)_ADT_v-0))->f3; 
#define else_if_non_const_1(v0, v1, v2, v3) \
} else if ((uintptr_t)(_ADT_v) >= 0 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4)  {\
int v0=((struct _ADT_Test_non_const_1*)((uintptr_t)_ADT_v-0))->f0; \
char v1=((struct _ADT_Test_non_const_1*)((uintptr_t)_ADT_v-0))->f1; \
long v2=((struct _ADT_Test_non_const_1*)((uintptr_t)_ADT_v-0))->f2; \
double v3=((struct _ADT_Test_non_const_1*)((uintptr_t)_ADT_v-0))->f3; 
#define if_non_const_1_ptr(v, v0, v1, v2, v3) \
{Test _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 0 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4)  {\
int *v0=&((struct _ADT_Test_non_const_1*)((uintptr_t)_ADT_v-0))->f0; \
char *v1=&((struct _ADT_Test_non_const_1*)((uintptr_t)_ADT_v-0))->f1; \
long *v2=&((struct _ADT_Test_non_const_1*)((uintptr_t)_ADT_v-0))->f2; \
double *v3=&((struct _ADT_Test_non_const_1*)((uintptr_t)_ADT_v-0))->f3; 
#define case_non_const_1(v0, v1, v2, v3) \
break;}} case 4: {{Test _SW_tchk=_Test_tchk;}{char _Test_tchk; \
int v0=((struct _ADT_Test_non_const_1*)((uintptr_t)_ADT_v-0))->f0; \
char v1=((struct _ADT_Test_non_const_1*)((uintptr_t)_ADT_v-0))->f1; \
long v2=((struct _ADT_Test_non_const_1*)((uintptr_t)_ADT_v-0))->f2; \
double v3=((struct _ADT_Test_non_const_1*)((uintptr_t)_ADT_v-0))->f3; 
#define case_non_const_1_ptr(v0, v1, v2, v3) \
break;}} case 4: {{Test _SW_tchk=_Test_tchk;}{char _Test_tchk; \
int *v0=&((struct _ADT_Test_non_const_1*)((uintptr_t)_ADT_v-0))->f0; \
char *v1=&((struct _ADT_Test_non_const_1*)((uintptr_t)_ADT_v-0))->f1; \
long *v2=&((struct _ADT_Test_non_const_1*)((uintptr_t)_ADT_v-0))->f2; \
double *v3=&((struct _ADT_Test_non_const_1*)((uintptr_t)_ADT_v-0))->f3; 

static __inline Test non_const_1(int v0, char v1, long v2, double v3){
	struct _ADT_Test_non_const_1 *v=(struct _ADT_Test_non_const_1*)malloc(sizeof(struct _ADT_Test_non_const_1));
	v->f0=v0; 
	v->f1=v1; 
	v->f2=v2; 
	v->f3=v3; 
	return (Test)(0+(uintptr_t)v);
}

struct _ADT_Test_non_const_2 {
    int f0;
    char f1;
    long f2;};
#define if_non_const_2(v, v0, v1, v2) \
{Test _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 1 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4) {\
int v0=((struct _ADT_Test_non_const_2*)((uintptr_t)_ADT_v-1))->f0; \
char v1=((struct _ADT_Test_non_const_2*)((uintptr_t)_ADT_v-1))->f1; \
long v2=((struct _ADT_Test_non_const_2*)((uintptr_t)_ADT_v-1))->f2; 
#define else_if_non_const_2(v0, v1, v2) \
} else if ((uintptr_t)(_ADT_v) >= 1 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4)  {\
int v0=((struct _ADT_Test_non_const_2*)((uintptr_t)_ADT_v-1))->f0; \
char v1=((struct _ADT_Test_non_const_2*)((uintptr_t)_ADT_v-1))->f1; \
long v2=((struct _ADT_Test_non_const_2*)((uintptr_t)_ADT_v-1))->f2; 
#define if_non_const_2_ptr(v, v0, v1, v2) \
{Test _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 1 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4)  {\
int *v0=&((struct _ADT_Test_non_const_2*)((uintptr_t)_ADT_v-1))->f0; \
char *v1=&((struct _ADT_Test_non_const_2*)((uintptr_t)_ADT_v-1))->f1; \
long *v2=&((struct _ADT_Test_non_const_2*)((uintptr_t)_ADT_v-1))->f2; 
#define case_non_const_2(v0, v1, v2) \
break;}} case 5: {{Test _SW_tchk=_Test_tchk;}{char _Test_tchk; \
int v0=((struct _ADT_Test_non_const_2*)((uintptr_t)_ADT_v-1))->f0; \
char v1=((struct _ADT_Test_non_const_2*)((uintptr_t)_ADT_v-1))->f1; \
long v2=((struct _ADT_Test_non_const_2*)((uintptr_t)_ADT_v-1))->f2; 
#define case_non_const_2_ptr(v0, v1, v2) \
break;}} case 5: {{Test _SW_tchk=_Test_tchk;}{char _Test_tchk; \
int *v0=&((struct _ADT_Test_non_const_2*)((uintptr_t)_ADT_v-1))->f0; \
char *v1=&((struct _ADT_Test_non_const_2*)((uintptr_t)_ADT_v-1))->f1; \
long *v2=&((struct _ADT_Test_non_const_2*)((uintptr_t)_ADT_v-1))->f2; 

static __inline Test non_const_2(int v0, char v1, long v2){
	struct _ADT_Test_non_const_2 *v=(struct _ADT_Test_non_const_2*)malloc(sizeof(struct _ADT_Test_non_const_2));
	v->f0=v0; 
	v->f1=v1; 
	v->f2=v2; 
	return (Test)(1+(uintptr_t)v);
}

struct _ADT_Test_non_const_3 {
    int f0;
    char f1;};
#define if_non_const_3(v, v0, v1) \
{Test _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 2 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4) {\
int v0=((struct _ADT_Test_non_const_3*)((uintptr_t)_ADT_v-2))->f0; \
char v1=((struct _ADT_Test_non_const_3*)((uintptr_t)_ADT_v-2))->f1; 
#define else_if_non_const_3(v0, v1) \
} else if ((uintptr_t)(_ADT_v) >= 2 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4)  {\
int v0=((struct _ADT_Test_non_const_3*)((uintptr_t)_ADT_v-2))->f0; \
char v1=((struct _ADT_Test_non_const_3*)((uintptr_t)_ADT_v-2))->f1; 
#define if_non_const_3_ptr(v, v0, v1) \
{Test _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 2 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4)  {\
int *v0=&((struct _ADT_Test_non_const_3*)((uintptr_t)_ADT_v-2))->f0; \
char *v1=&((struct _ADT_Test_non_const_3*)((uintptr_t)_ADT_v-2))->f1; 
#define case_non_const_3(v0, v1) \
break;}} case 6: {{Test _SW_tchk=_Test_tchk;}{char _Test_tchk; \
int v0=((struct _ADT_Test_non_const_3*)((uintptr_t)_ADT_v-2))->f0; \
char v1=((struct _ADT_Test_non_const_3*)((uintptr_t)_ADT_v-2))->f1; 
#define case_non_const_3_ptr(v0, v1) \
break;}} case 6: {{Test _SW_tchk=_Test_tchk;}{char _Test_tchk; \
int *v0=&((struct _ADT_Test_non_const_3*)((uintptr_t)_ADT_v-2))->f0; \
char *v1=&((struct _ADT_Test_non_const_3*)((uintptr_t)_ADT_v-2))->f1; 

static __inline Test non_const_3(int v0, char v1){
	struct _ADT_Test_non_const_3 *v=(struct _ADT_Test_non_const_3*)malloc(sizeof(struct _ADT_Test_non_const_3));
	v->f0=v0; 
	v->f1=v1; 
	return (Test)(2+(uintptr_t)v);
}

struct _ADT_Test_non_const_4 {
    int f0;};
#define if_non_const_4(v, v0) \
{Test _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 3 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4) {\
int v0=((struct _ADT_Test_non_const_4*)((uintptr_t)_ADT_v-3))->f0; 
#define else_if_non_const_4(v0) \
} else if ((uintptr_t)(_ADT_v) >= 3 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4)  {\
int v0=((struct _ADT_Test_non_const_4*)((uintptr_t)_ADT_v-3))->f0; 
#define if_non_const_4_ptr(v, v0) \
{Test _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 3 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4)  {\
int *v0=&((struct _ADT_Test_non_const_4*)((uintptr_t)_ADT_v-3))->f0; 
#define case_non_const_4(v0) \
break;}} case 7: {{Test _SW_tchk=_Test_tchk;}{char _Test_tchk; \
int v0=((struct _ADT_Test_non_const_4*)((uintptr_t)_ADT_v-3))->f0; 
#define case_non_const_4_ptr(v0) \
break;}} case 7: {{Test _SW_tchk=_Test_tchk;}{char _Test_tchk; \
int *v0=&((struct _ADT_Test_non_const_4*)((uintptr_t)_ADT_v-3))->f0; 

static __inline Test non_const_4(int v0){
	struct _ADT_Test_non_const_4 *v=(struct _ADT_Test_non_const_4*)malloc(sizeof(struct _ADT_Test_non_const_4));
	v->f0=v0; 
	return (Test)(3+(uintptr_t)v);
}

struct _ADT_Test_non_const_5 {
    int f0;
    char f1;
    long f2;
    double f3;};
#define if_non_const_5(v, v0, v1, v2, v3) \
{Test _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 4 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4) {\
int v0=((struct _ADT_Test_non_const_5*)((uintptr_t)_ADT_v-4))->f0; \
char v1=((struct _ADT_Test_non_const_5*)((uintptr_t)_ADT_v-4))->f1; \
long v2=((struct _ADT_Test_non_const_5*)((uintptr_t)_ADT_v-4))->f2; \
double v3=((struct _ADT_Test_non_const_5*)((uintptr_t)_ADT_v-4))->f3; 
#define else_if_non_const_5(v0, v1, v2, v3) \
} else if ((uintptr_t)(_ADT_v) >= 4 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4)  {\
int v0=((struct _ADT_Test_non_const_5*)((uintptr_t)_ADT_v-4))->f0; \
char v1=((struct _ADT_Test_non_const_5*)((uintptr_t)_ADT_v-4))->f1; \
long v2=((struct _ADT_Test_non_const_5*)((uintptr_t)_ADT_v-4))->f2; \
double v3=((struct _ADT_Test_non_const_5*)((uintptr_t)_ADT_v-4))->f3; 
#define if_non_const_5_ptr(v, v0, v1, v2, v3) \
{Test _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 4 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4)  {\
int *v0=&((struct _ADT_Test_non_const_5*)((uintptr_t)_ADT_v-4))->f0; \
char *v1=&((struct _ADT_Test_non_const_5*)((uintptr_t)_ADT_v-4))->f1; \
long *v2=&((struct _ADT_Test_non_const_5*)((uintptr_t)_ADT_v-4))->f2; \
double *v3=&((struct _ADT_Test_non_const_5*)((uintptr_t)_ADT_v-4))->f3; 
#define case_non_const_5(v0, v1, v2, v3) \
break;}} case 8: {{Test _SW_tchk=_Test_tchk;}{char _Test_tchk; \
int v0=((struct _ADT_Test_non_const_5*)((uintptr_t)_ADT_v-4))->f0; \
char v1=((struct _ADT_Test_non_const_5*)((uintptr_t)_ADT_v-4))->f1; \
long v2=((struct _ADT_Test_non_const_5*)((uintptr_t)_ADT_v-4))->f2; \
double v3=((struct _ADT_Test_non_const_5*)((uintptr_t)_ADT_v-4))->f3; 
#define case_non_const_5_ptr(v0, v1, v2, v3) \
break;}} case 8: {{Test _SW_tchk=_Test_tchk;}{char _Test_tchk; \
int *v0=&((struct _ADT_Test_non_const_5*)((uintptr_t)_ADT_v-4))->f0; \
char *v1=&((struct _ADT_Test_non_const_5*)((uintptr_t)_ADT_v-4))->f1; \
long *v2=&((struct _ADT_Test_non_const_5*)((uintptr_t)_ADT_v-4))->f2; \
double *v3=&((struct _ADT_Test_non_const_5*)((uintptr_t)_ADT_v-4))->f3; 

static __inline Test non_const_5(int v0, char v1, long v2, double v3){
	struct _ADT_Test_non_const_5 *v=(struct _ADT_Test_non_const_5*)malloc(sizeof(struct _ADT_Test_non_const_5));
	v->f0=v0; 
	v->f1=v1; 
	v->f2=v2; 
	v->f3=v3; 
	return (Test)(4+(uintptr_t)v);
}

struct _ADT_Test_non_const_6 {
    int f0;};
#define if_non_const_6(v, v0) \
{Test _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 5 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4) {\
int v0=((struct _ADT_Test_non_const_6*)((uintptr_t)_ADT_v-5))->f0; 
#define else_if_non_const_6(v0) \
} else if ((uintptr_t)(_ADT_v) >= 5 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4)  {\
int v0=((struct _ADT_Test_non_const_6*)((uintptr_t)_ADT_v-5))->f0; 
#define if_non_const_6_ptr(v, v0) \
{Test _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 5 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4)  {\
int *v0=&((struct _ADT_Test_non_const_6*)((uintptr_t)_ADT_v-5))->f0; 
#define case_non_const_6(v0) \
break;}} case 9: {{Test _SW_tchk=_Test_tchk;}{char _Test_tchk; \
int v0=((struct _ADT_Test_non_const_6*)((uintptr_t)_ADT_v-5))->f0; 
#define case_non_const_6_ptr(v0) \
break;}} case 9: {{Test _SW_tchk=_Test_tchk;}{char _Test_tchk; \
int *v0=&((struct _ADT_Test_non_const_6*)((uintptr_t)_ADT_v-5))->f0; 

static __inline Test non_const_6(int v0){
	struct _ADT_Test_non_const_6 *v=(struct _ADT_Test_non_const_6*)malloc(sizeof(struct _ADT_Test_non_const_6));
	v->f0=v0; 
	return (Test)(5+(uintptr_t)v);
}

struct _ADT_Test_non_const_7 {
    int f0;};
#define if_non_const_7(v, v0) \
{Test _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 6 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4) {\
int v0=((struct _ADT_Test_non_const_7*)((uintptr_t)_ADT_v-6))->f0; 
#define else_if_non_const_7(v0) \
} else if ((uintptr_t)(_ADT_v) >= 6 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4)  {\
int v0=((struct _ADT_Test_non_const_7*)((uintptr_t)_ADT_v-6))->f0; 
#define if_non_const_7_ptr(v, v0) \
{Test _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 6 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4)  {\
int *v0=&((struct _ADT_Test_non_const_7*)((uintptr_t)_ADT_v-6))->f0; 
#define case_non_const_7(v0) \
break;}} case 10: {{Test _SW_tchk=_Test_tchk;}{char _Test_tchk; \
int v0=((struct _ADT_Test_non_const_7*)((uintptr_t)_ADT_v-6))->f0; 
#define case_non_const_7_ptr(v0) \
break;}} case 10: {{Test _SW_tchk=_Test_tchk;}{char _Test_tchk; \
int *v0=&((struct _ADT_Test_non_const_7*)((uintptr_t)_ADT_v-6))->f0; 

static __inline Test non_const_7(int v0){
	struct _ADT_Test_non_const_7 *v=(struct _ADT_Test_non_const_7*)malloc(sizeof(struct _ADT_Test_non_const_7));
	v->f0=v0; 
	return (Test)(6+(uintptr_t)v);
}

struct _ADT_Test_non_const_8 {
	int ftag;
    int f0;};
#define if_non_const_8(v, v0) \
{Test _ADT_v=(v);\
if ((uintptr_t)(_ADT_v) >= 4 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==LOW_BIT_USED && (((struct _ADT_Test_non_const_8*)((uintptr_t)_ADT_v-LOW_BIT_USED))->ftag == 7)){\
int v0=((struct _ADT_Test_non_const_8*)((uintptr_t)_ADT_v-LOW_BIT_USED))->f0; 
#define else_if_non_const_8(v0) \
} else if ((uintptr_t)(_ADT_v) >= 4 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==LOW_BIT_USED && (((struct _ADT_Test_non_const_8*)((uintptr_t)_ADT_v-LOW_BIT_USED))->ftag == 7)) {\
int v0=((struct _ADT_Test_non_const_8*)((uintptr_t)_ADT_v-LOW_BIT_USED))->f0; 
#define if_non_const_8_ptr(v, v0) \
{Test _ADT_v=(v);{\
if ((uintptr_t)(_ADT_v) >= 4 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==LOW_BIT_USED && (((struct _ADT_Test_non_const_8*)((uintptr_t)_ADT_v-LOW_BIT_USED))->ftag == 7)) {\
int *v0=&((struct _ADT_Test_non_const_8*)((uintptr_t)_ADT_v-LOW_BIT_USED))->f0; 
#define case_non_const_8(v0) \
break;}} case 11: {{Test _SW_tchk=_Test_tchk;}{char _Test_tchk; \
int v0=((struct _ADT_Test_non_const_8*)((uintptr_t)_ADT_v-LOW_BIT_USED))->f0; 
#define case_non_const_8_ptr(v0) \
break;}} case 11: {{Test _SW_tchk=_Test_tchk;}{char _Test_tchk; \
int *v0=&((struct _ADT_Test_non_const_8*)((uintptr_t)_ADT_v-LOW_BIT_USED))->f0; 

static __inline Test non_const_8(int v0){
	struct _ADT_Test_non_const_8 *v=(struct _ADT_Test_non_const_8*)malloc(sizeof(struct _ADT_Test_non_const_8));
	v->ftag = 7; 
	v->f0=v0; 
	return (Test)(LOW_BIT_USED+(uintptr_t)v);
}

struct _ADT_Test_non_const_9 {
	int ftag;
    int f0;};
#define if_non_const_9(v, v0) \
{Test _ADT_v=(v);\
if ((uintptr_t)(_ADT_v) >= 4 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==LOW_BIT_USED && (((struct _ADT_Test_non_const_9*)((uintptr_t)_ADT_v-LOW_BIT_USED))->ftag == 8)){\
int v0=((struct _ADT_Test_non_const_9*)((uintptr_t)_ADT_v-LOW_BIT_USED))->f0; 
#define else_if_non_const_9(v0) \
} else if ((uintptr_t)(_ADT_v) >= 4 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==LOW_BIT_USED && (((struct _ADT_Test_non_const_9*)((uintptr_t)_ADT_v-LOW_BIT_USED))->ftag == 8)) {\
int v0=((struct _ADT_Test_non_const_9*)((uintptr_t)_ADT_v-LOW_BIT_USED))->f0; 
#define if_non_const_9_ptr(v, v0) \
{Test _ADT_v=(v);{\
if ((uintptr_t)(_ADT_v) >= 4 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==LOW_BIT_USED && (((struct _ADT_Test_non_const_9*)((uintptr_t)_ADT_v-LOW_BIT_USED))->ftag == 8)) {\
int *v0=&((struct _ADT_Test_non_const_9*)((uintptr_t)_ADT_v-LOW_BIT_USED))->f0; 
#define case_non_const_9(v0) \
break;}} case 12: {{Test _SW_tchk=_Test_tchk;}{char _Test_tchk; \
int v0=((struct _ADT_Test_non_const_9*)((uintptr_t)_ADT_v-LOW_BIT_USED))->f0; 
#define case_non_const_9_ptr(v0) \
break;}} case 12: {{Test _SW_tchk=_Test_tchk;}{char _Test_tchk; \
int *v0=&((struct _ADT_Test_non_const_9*)((uintptr_t)_ADT_v-LOW_BIT_USED))->f0; 

static __inline Test non_const_9(int v0){
	struct _ADT_Test_non_const_9 *v=(struct _ADT_Test_non_const_9*)malloc(sizeof(struct _ADT_Test_non_const_9));
	v->ftag = 8; 
	v->f0=v0; 
	return (Test)(LOW_BIT_USED+(uintptr_t)v);
}

/***************************/
typedef struct _ADT_int_list{} *int_list;
#define int_list_T_NUM_CONST (1) 
#define int_list_T_NUM_NONCONST (1) 
#define int_list_constructorNum(v) \
(( int_list_T_NUM_NONCONST>0 && v > int_list_T_NUM_CONST-1 ?  \
 ( int_list_T_NUM_NONCONST==1 ?  int_list_T_NUM_CONST   : \
(( int_list_T_NUM_NONCONST > (LOW_BIT_USED + 1))  && ((v&LOW_BIT_USED) == (LOW_BIT_USED))  )  ?   \
 (*(int*)((uintptr_t)_ADT_v-LOW_BIT_USED)) + int_list_T_NUM_CONST  : \
((v&(LOW_BIT_USED)) + int_list_T_NUM_CONST)) : v ) )

;
#define switch_int_list(v) \
{int_list _int_list_tchk, _ADT_v=(v); \
int t = int_list_constructorNum((uintptr_t)(_ADT_v)); \
switch(t) {{{


/******************************************************************************/
static __inline void free_int_list(int_list v){
	if ((uintptr_t)(v) >= 1){
		free((void*)((uintptr_t)v));
	}
}


struct _ADT_int_list_nil {};
#define if_nil(v) \
{int_list _ADT_v=(v);if (((uintptr_t)(_ADT_v))==0) {
#define else_if_nil() \
} else if (((uintptr_t)(_ADT_v))==0) {
#define if_nil_ptr(v) \
{int_list _ADT_v=(v);if (((uintptr_t)(_ADT_v))==0) {
#define case_nil() \
break;}} case 0: {{int_list _SW_tchk=_int_list_tchk;}{char _int_list_tchk; 
#define case_nil_ptr() \
break;}} case 0: {{int_list _SW_tchk=_int_list_tchk;}{char _int_list_tchk; 

static __inline int_list nil(){
	struct _ADT_int_list_nil *v=(struct _ADT_int_list_nil*)0;
	return (int_list)((uintptr_t)v);
}

struct _ADT_int_list_next_list {
    double f0;
    struct _ADT_int_list* f1;};
#define if_next_list(v, v0, v1) \
{int_list _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 1) {\
double v0=((struct _ADT_int_list_next_list*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_int_list* v1=((struct _ADT_int_list_next_list*)((uintptr_t)_ADT_v-0))->f1; 
#define else_if_next_list(v0, v1) \
} else if ((uintptr_t)(_ADT_v) >= 1) {\
double v0=((struct _ADT_int_list_next_list*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_int_list* v1=((struct _ADT_int_list_next_list*)((uintptr_t)_ADT_v-0))->f1; 
#define if_next_list_ptr(v, v0, v1) \
{int_list _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 1) {\
double *v0=&((struct _ADT_int_list_next_list*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_int_list* *v1=&((struct _ADT_int_list_next_list*)((uintptr_t)_ADT_v-0))->f1; 
#define case_next_list(v0, v1) \
break;}} case 1: {{int_list _SW_tchk=_int_list_tchk;}{char _int_list_tchk; \
double v0=((struct _ADT_int_list_next_list*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_int_list* v1=((struct _ADT_int_list_next_list*)((uintptr_t)_ADT_v-0))->f1; 
#define case_next_list_ptr(v0, v1) \
break;}} case 1: {{int_list _SW_tchk=_int_list_tchk;}{char _int_list_tchk; \
double *v0=&((struct _ADT_int_list_next_list*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_int_list* *v1=&((struct _ADT_int_list_next_list*)((uintptr_t)_ADT_v-0))->f1; 

static __inline int_list next_list(double v0, struct _ADT_int_list* v1){
	struct _ADT_int_list_next_list *v=(struct _ADT_int_list_next_list*)malloc(sizeof(struct _ADT_int_list_next_list));
	v->f0=v0; 
	v->f1=v1; 
	return (int_list)(0+(uintptr_t)v);
}
