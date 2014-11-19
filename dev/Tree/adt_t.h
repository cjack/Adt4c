#include <stdint.h>
#include <stdlib.h>
typedef char *c_string;
#define end_switch() }}}}
#define default() break;}} default: {{
#define else() } else {
#define end_if() }}
#define LOW_BIT_USED 7
/***************************/
typedef struct _ADT_details{} *details;
#define details_T_NUM_CONST (0) 
#define details_T_NUM_NONCONST (1) 
#define details_constructorNum(v) \
(( details_T_NUM_NONCONST>0 && v > details_T_NUM_CONST-1 ?  \
 ( details_T_NUM_NONCONST==1 ?  details_T_NUM_CONST   : \
(( details_T_NUM_NONCONST > (LOW_BIT_USED + 1))  && ((v&LOW_BIT_USED) == (LOW_BIT_USED))  )  ?   \
 (*(int*)((uintptr_t)_ADT_v-LOW_BIT_USED)) + details_T_NUM_CONST  : \
((v&(LOW_BIT_USED)) + details_T_NUM_CONST)) : v ) )

static __inline void free_details(details v);
#define switch_details(v) \
{details _details_tchk, _ADT_v=(v); \
int t = details_constructorNum((uintptr_t)(_ADT_v)); \
switch(t) {{{


/******************************************************************************/
static __inline void free_details(details v){
	free((void*)((uintptr_t)v));
}


struct _ADT_details_record {
    char* f0;
    int f1;
    char* f2;
    float f3;};
#define if_record(v, v0, v1, v2, v3) \
{details _ADT_v=(v);if (1) {\
char* v0=((struct _ADT_details_record*)((uintptr_t)_ADT_v-0))->f0; \
int v1=((struct _ADT_details_record*)((uintptr_t)_ADT_v-0))->f1; \
char* v2=((struct _ADT_details_record*)((uintptr_t)_ADT_v-0))->f2; \
float v3=((struct _ADT_details_record*)((uintptr_t)_ADT_v-0))->f3; 
#define else_if_record(v0, v1, v2, v3) \
} else if (1) {\
char* v0=((struct _ADT_details_record*)((uintptr_t)_ADT_v-0))->f0; \
int v1=((struct _ADT_details_record*)((uintptr_t)_ADT_v-0))->f1; \
char* v2=((struct _ADT_details_record*)((uintptr_t)_ADT_v-0))->f2; \
float v3=((struct _ADT_details_record*)((uintptr_t)_ADT_v-0))->f3; 
#define if_record_ptr(v, v0, v1, v2, v3) \
{details _ADT_v=(v);if (1) {\
char* *v0=&((struct _ADT_details_record*)((uintptr_t)_ADT_v-0))->f0; \
int *v1=&((struct _ADT_details_record*)((uintptr_t)_ADT_v-0))->f1; \
char* *v2=&((struct _ADT_details_record*)((uintptr_t)_ADT_v-0))->f2; \
float *v3=&((struct _ADT_details_record*)((uintptr_t)_ADT_v-0))->f3; 
#define case_record(v0, v1, v2, v3) \
break;}} case 0: {{details _SW_tchk=_details_tchk;}{char _details_tchk; \
char* v0=((struct _ADT_details_record*)((uintptr_t)_ADT_v-0))->f0; \
int v1=((struct _ADT_details_record*)((uintptr_t)_ADT_v-0))->f1; \
char* v2=((struct _ADT_details_record*)((uintptr_t)_ADT_v-0))->f2; \
float v3=((struct _ADT_details_record*)((uintptr_t)_ADT_v-0))->f3; 
#define case_record_ptr(v0, v1, v2, v3) \
break;}} case 0: {{details _SW_tchk=_details_tchk;}{char _details_tchk; \
char* *v0=&((struct _ADT_details_record*)((uintptr_t)_ADT_v-0))->f0; \
int *v1=&((struct _ADT_details_record*)((uintptr_t)_ADT_v-0))->f1; \
char* *v2=&((struct _ADT_details_record*)((uintptr_t)_ADT_v-0))->f2; \
float *v3=&((struct _ADT_details_record*)((uintptr_t)_ADT_v-0))->f3; 

static __inline details record(char* v0, int v1, char* v2, float v3){
	struct _ADT_details_record *v=(struct _ADT_details_record*)malloc(sizeof(struct _ADT_details_record));
	v->f0=v0; 
	v->f1=v1; 
	v->f2=v2; 
	v->f3=v3; 
	return (details)(0+(uintptr_t)v);
}

/***************************/
typedef struct _ADT_tree{} *tree;
#define tree_T_NUM_CONST (1) 
#define tree_T_NUM_NONCONST (1) 
#define tree_constructorNum(v) \
(( tree_T_NUM_NONCONST>0 && v > tree_T_NUM_CONST-1 ?  \
 ( tree_T_NUM_NONCONST==1 ?  tree_T_NUM_CONST   : \
(( tree_T_NUM_NONCONST > (LOW_BIT_USED + 1))  && ((v&LOW_BIT_USED) == (LOW_BIT_USED))  )  ?   \
 (*(int*)((uintptr_t)_ADT_v-LOW_BIT_USED)) + tree_T_NUM_CONST  : \
((v&(LOW_BIT_USED)) + tree_T_NUM_CONST)) : v ) )

static __inline void free_tree(tree v);
#define switch_tree(v) \
{tree _tree_tchk, _ADT_v=(v); \
int t = tree_constructorNum((uintptr_t)(_ADT_v)); \
switch(t) {{{


/******************************************************************************/
static __inline void free_tree(tree v){
	if ((uintptr_t)(v) >= 1){
		free((void*)((uintptr_t)v));
	}
}


struct _ADT_tree_leaf {};
#define if_leaf(v) \
{tree _ADT_v=(v);if (((uintptr_t)(_ADT_v))==0) {
#define else_if_leaf() \
} else if (((uintptr_t)(_ADT_v))==0) {
#define if_leaf_ptr(v) \
{tree _ADT_v=(v);if (((uintptr_t)(_ADT_v))==0) {
#define case_leaf() \
break;}} case 0: {{tree _SW_tchk=_tree_tchk;}{char _tree_tchk; 
#define case_leaf_ptr() \
break;}} case 0: {{tree _SW_tchk=_tree_tchk;}{char _tree_tchk; 

static __inline tree leaf(){
	struct _ADT_tree_leaf *v=(struct _ADT_tree_leaf*)0;
	return (tree)((uintptr_t)v);
}

struct _ADT_tree_node {
    int f0;
    struct _ADT_tree* f1;
    struct _ADT_tree* f2;};
#define if_node(v, v0, v1, v2) \
{tree _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 1) {\
int v0=((struct _ADT_tree_node*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_tree* v1=((struct _ADT_tree_node*)((uintptr_t)_ADT_v-0))->f1; \
struct _ADT_tree* v2=((struct _ADT_tree_node*)((uintptr_t)_ADT_v-0))->f2; 
#define else_if_node(v0, v1, v2) \
} else if ((uintptr_t)(_ADT_v) >= 1) {\
int v0=((struct _ADT_tree_node*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_tree* v1=((struct _ADT_tree_node*)((uintptr_t)_ADT_v-0))->f1; \
struct _ADT_tree* v2=((struct _ADT_tree_node*)((uintptr_t)_ADT_v-0))->f2; 
#define if_node_ptr(v, v0, v1, v2) \
{tree _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 1) {\
int *v0=&((struct _ADT_tree_node*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_tree* *v1=&((struct _ADT_tree_node*)((uintptr_t)_ADT_v-0))->f1; \
struct _ADT_tree* *v2=&((struct _ADT_tree_node*)((uintptr_t)_ADT_v-0))->f2; 
#define case_node(v0, v1, v2) \
break;}} case 1: {{tree _SW_tchk=_tree_tchk;}{char _tree_tchk; \
int v0=((struct _ADT_tree_node*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_tree* v1=((struct _ADT_tree_node*)((uintptr_t)_ADT_v-0))->f1; \
struct _ADT_tree* v2=((struct _ADT_tree_node*)((uintptr_t)_ADT_v-0))->f2; 
#define case_node_ptr(v0, v1, v2) \
break;}} case 1: {{tree _SW_tchk=_tree_tchk;}{char _tree_tchk; \
int *v0=&((struct _ADT_tree_node*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_tree* *v1=&((struct _ADT_tree_node*)((uintptr_t)_ADT_v-0))->f1; \
struct _ADT_tree* *v2=&((struct _ADT_tree_node*)((uintptr_t)_ADT_v-0))->f2; 

static __inline tree node(int v0, struct _ADT_tree* v1, struct _ADT_tree* v2){
	struct _ADT_tree_node *v=(struct _ADT_tree_node*)malloc(sizeof(struct _ADT_tree_node));
	v->f0=v0; 
	v->f1=v1; 
	v->f2=v2; 
	return (tree)(0+(uintptr_t)v);
}
