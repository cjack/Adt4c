#include <stdint.h>
#include <stdlib.h>
typedef char *c_string;
#define end_switch() }}}}
#define default() break;}} default: {{
#define else() } else {
#define end_if() }}
#define LOW_BIT_USED 7
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
typedef struct _ADT_Test4{} *Test4;
#define Test4_T_NUM_CONST (4) 
#define Test4_T_NUM_NONCONST (8) 
#define Test4_constructorNum(v) \
(( Test4_T_NUM_NONCONST>0 && v > Test4_T_NUM_CONST-1 ?  \
 ( Test4_T_NUM_NONCONST==1 ?  Test4_T_NUM_CONST   : \
(( Test4_T_NUM_NONCONST > (LOW_BIT_USED + 1))  && ((v&LOW_BIT_USED) == (LOW_BIT_USED))  )  ?   \
 (*(int*)((uintptr_t)_ADT_v-LOW_BIT_USED)) + Test4_T_NUM_CONST  : \
((v&(LOW_BIT_USED)) + Test4_T_NUM_CONST)) : v ) )

;
#define switch_Test4(v) \
{Test4 _Test4_tchk, _ADT_v=(v); \
int t = Test4_constructorNum((uintptr_t)(_ADT_v)); \
switch(t) {{{


/******************************************************************************/
static __inline void free_Test4(Test4 v){
	if ((uintptr_t)(v) >= 4){
		free((void*)((uintptr_t)v&~LOW_BIT_USED));
	}
}


struct _ADT_Test4_con1 {};
#define if_con1(v) \
{Test4 _ADT_v=(v);if (((uintptr_t)(_ADT_v))==0) {
#define else_if_con1() \
} else if (((uintptr_t)(_ADT_v))==0) {
#define if_con1_ptr(v) \
{Test4 _ADT_v=(v);if (((uintptr_t)(_ADT_v))==0) {
#define case_con1() \
break;}} case 0: {{Test4 _SW_tchk=_Test4_tchk;}{char _Test4_tchk; 
#define case_con1_ptr() \
break;}} case 0: {{Test4 _SW_tchk=_Test4_tchk;}{char _Test4_tchk; 

static __inline Test4 con1(){
	struct _ADT_Test4_con1 *v=(struct _ADT_Test4_con1*)0;
	return (Test4)((uintptr_t)v);
}

struct _ADT_Test4_con2 {};
#define if_con2(v) \
{Test4 _ADT_v=(v);if (((uintptr_t)(_ADT_v))==1) {
#define else_if_con2() \
} else if (((uintptr_t)(_ADT_v))==1) {
#define if_con2_ptr(v) \
{Test4 _ADT_v=(v);if (((uintptr_t)(_ADT_v))==1) {
#define case_con2() \
break;}} case 1: {{Test4 _SW_tchk=_Test4_tchk;}{char _Test4_tchk; 
#define case_con2_ptr() \
break;}} case 1: {{Test4 _SW_tchk=_Test4_tchk;}{char _Test4_tchk; 

static __inline Test4 con2(){
	struct _ADT_Test4_con2 *v=(struct _ADT_Test4_con2*)1;
	return (Test4)((uintptr_t)v);
}

struct _ADT_Test4_con3 {};
#define if_con3(v) \
{Test4 _ADT_v=(v);if (((uintptr_t)(_ADT_v))==2) {
#define else_if_con3() \
} else if (((uintptr_t)(_ADT_v))==2) {
#define if_con3_ptr(v) \
{Test4 _ADT_v=(v);if (((uintptr_t)(_ADT_v))==2) {
#define case_con3() \
break;}} case 2: {{Test4 _SW_tchk=_Test4_tchk;}{char _Test4_tchk; 
#define case_con3_ptr() \
break;}} case 2: {{Test4 _SW_tchk=_Test4_tchk;}{char _Test4_tchk; 

static __inline Test4 con3(){
	struct _ADT_Test4_con3 *v=(struct _ADT_Test4_con3*)2;
	return (Test4)((uintptr_t)v);
}

struct _ADT_Test4_con4 {};
#define if_con4(v) \
{Test4 _ADT_v=(v);if (((uintptr_t)(_ADT_v))==3) {
#define else_if_con4() \
} else if (((uintptr_t)(_ADT_v))==3) {
#define if_con4_ptr(v) \
{Test4 _ADT_v=(v);if (((uintptr_t)(_ADT_v))==3) {
#define case_con4() \
break;}} case 3: {{Test4 _SW_tchk=_Test4_tchk;}{char _Test4_tchk; 
#define case_con4_ptr() \
break;}} case 3: {{Test4 _SW_tchk=_Test4_tchk;}{char _Test4_tchk; 

static __inline Test4 con4(){
	struct _ADT_Test4_con4 *v=(struct _ADT_Test4_con4*)3;
	return (Test4)((uintptr_t)v);
}

struct _ADT_Test4_non_1 {
    int f0;};
#define if_non_1(v, v0) \
{Test4 _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 0 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4) {\
int v0=((struct _ADT_Test4_non_1*)((uintptr_t)_ADT_v-0))->f0; 
#define else_if_non_1(v0) \
} else if ((uintptr_t)(_ADT_v) >= 0 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4)  {\
int v0=((struct _ADT_Test4_non_1*)((uintptr_t)_ADT_v-0))->f0; 
#define if_non_1_ptr(v, v0) \
{Test4 _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 0 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4)  {\
int *v0=&((struct _ADT_Test4_non_1*)((uintptr_t)_ADT_v-0))->f0; 
#define case_non_1(v0) \
break;}} case 4: {{Test4 _SW_tchk=_Test4_tchk;}{char _Test4_tchk; \
int v0=((struct _ADT_Test4_non_1*)((uintptr_t)_ADT_v-0))->f0; 
#define case_non_1_ptr(v0) \
break;}} case 4: {{Test4 _SW_tchk=_Test4_tchk;}{char _Test4_tchk; \
int *v0=&((struct _ADT_Test4_non_1*)((uintptr_t)_ADT_v-0))->f0; 

static __inline Test4 non_1(int v0){
	struct _ADT_Test4_non_1 *v=(struct _ADT_Test4_non_1*)malloc(sizeof(struct _ADT_Test4_non_1));
	v->f0=v0; 
	return (Test4)(0+(uintptr_t)v);
}

struct _ADT_Test4_non_2 {
    int f0;};
#define if_non_2(v, v0) \
{Test4 _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 1 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4) {\
int v0=((struct _ADT_Test4_non_2*)((uintptr_t)_ADT_v-1))->f0; 
#define else_if_non_2(v0) \
} else if ((uintptr_t)(_ADT_v) >= 1 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4)  {\
int v0=((struct _ADT_Test4_non_2*)((uintptr_t)_ADT_v-1))->f0; 
#define if_non_2_ptr(v, v0) \
{Test4 _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 1 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4)  {\
int *v0=&((struct _ADT_Test4_non_2*)((uintptr_t)_ADT_v-1))->f0; 
#define case_non_2(v0) \
break;}} case 5: {{Test4 _SW_tchk=_Test4_tchk;}{char _Test4_tchk; \
int v0=((struct _ADT_Test4_non_2*)((uintptr_t)_ADT_v-1))->f0; 
#define case_non_2_ptr(v0) \
break;}} case 5: {{Test4 _SW_tchk=_Test4_tchk;}{char _Test4_tchk; \
int *v0=&((struct _ADT_Test4_non_2*)((uintptr_t)_ADT_v-1))->f0; 

static __inline Test4 non_2(int v0){
	struct _ADT_Test4_non_2 *v=(struct _ADT_Test4_non_2*)malloc(sizeof(struct _ADT_Test4_non_2));
	v->f0=v0; 
	return (Test4)(1+(uintptr_t)v);
}

struct _ADT_Test4_non_3 {
    int f0;};
#define if_non_3(v, v0) \
{Test4 _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 2 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4) {\
int v0=((struct _ADT_Test4_non_3*)((uintptr_t)_ADT_v-2))->f0; 
#define else_if_non_3(v0) \
} else if ((uintptr_t)(_ADT_v) >= 2 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4)  {\
int v0=((struct _ADT_Test4_non_3*)((uintptr_t)_ADT_v-2))->f0; 
#define if_non_3_ptr(v, v0) \
{Test4 _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 2 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4)  {\
int *v0=&((struct _ADT_Test4_non_3*)((uintptr_t)_ADT_v-2))->f0; 
#define case_non_3(v0) \
break;}} case 6: {{Test4 _SW_tchk=_Test4_tchk;}{char _Test4_tchk; \
int v0=((struct _ADT_Test4_non_3*)((uintptr_t)_ADT_v-2))->f0; 
#define case_non_3_ptr(v0) \
break;}} case 6: {{Test4 _SW_tchk=_Test4_tchk;}{char _Test4_tchk; \
int *v0=&((struct _ADT_Test4_non_3*)((uintptr_t)_ADT_v-2))->f0; 

static __inline Test4 non_3(int v0){
	struct _ADT_Test4_non_3 *v=(struct _ADT_Test4_non_3*)malloc(sizeof(struct _ADT_Test4_non_3));
	v->f0=v0; 
	return (Test4)(2+(uintptr_t)v);
}

struct _ADT_Test4_non_4 {
    int f0;};
#define if_non_4(v, v0) \
{Test4 _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 3 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4) {\
int v0=((struct _ADT_Test4_non_4*)((uintptr_t)_ADT_v-3))->f0; 
#define else_if_non_4(v0) \
} else if ((uintptr_t)(_ADT_v) >= 3 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4)  {\
int v0=((struct _ADT_Test4_non_4*)((uintptr_t)_ADT_v-3))->f0; 
#define if_non_4_ptr(v, v0) \
{Test4 _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 3 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4)  {\
int *v0=&((struct _ADT_Test4_non_4*)((uintptr_t)_ADT_v-3))->f0; 
#define case_non_4(v0) \
break;}} case 7: {{Test4 _SW_tchk=_Test4_tchk;}{char _Test4_tchk; \
int v0=((struct _ADT_Test4_non_4*)((uintptr_t)_ADT_v-3))->f0; 
#define case_non_4_ptr(v0) \
break;}} case 7: {{Test4 _SW_tchk=_Test4_tchk;}{char _Test4_tchk; \
int *v0=&((struct _ADT_Test4_non_4*)((uintptr_t)_ADT_v-3))->f0; 

static __inline Test4 non_4(int v0){
	struct _ADT_Test4_non_4 *v=(struct _ADT_Test4_non_4*)malloc(sizeof(struct _ADT_Test4_non_4));
	v->f0=v0; 
	return (Test4)(3+(uintptr_t)v);
}

struct _ADT_Test4_non_5 {
    int f0;};
#define if_non_5(v, v0) \
{Test4 _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 4 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4) {\
int v0=((struct _ADT_Test4_non_5*)((uintptr_t)_ADT_v-4))->f0; 
#define else_if_non_5(v0) \
} else if ((uintptr_t)(_ADT_v) >= 4 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4)  {\
int v0=((struct _ADT_Test4_non_5*)((uintptr_t)_ADT_v-4))->f0; 
#define if_non_5_ptr(v, v0) \
{Test4 _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 4 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4)  {\
int *v0=&((struct _ADT_Test4_non_5*)((uintptr_t)_ADT_v-4))->f0; 
#define case_non_5(v0) \
break;}} case 8: {{Test4 _SW_tchk=_Test4_tchk;}{char _Test4_tchk; \
int v0=((struct _ADT_Test4_non_5*)((uintptr_t)_ADT_v-4))->f0; 
#define case_non_5_ptr(v0) \
break;}} case 8: {{Test4 _SW_tchk=_Test4_tchk;}{char _Test4_tchk; \
int *v0=&((struct _ADT_Test4_non_5*)((uintptr_t)_ADT_v-4))->f0; 

static __inline Test4 non_5(int v0){
	struct _ADT_Test4_non_5 *v=(struct _ADT_Test4_non_5*)malloc(sizeof(struct _ADT_Test4_non_5));
	v->f0=v0; 
	return (Test4)(4+(uintptr_t)v);
}

struct _ADT_Test4_non_6 {
    int f0;};
#define if_non_6(v, v0) \
{Test4 _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 5 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4) {\
int v0=((struct _ADT_Test4_non_6*)((uintptr_t)_ADT_v-5))->f0; 
#define else_if_non_6(v0) \
} else if ((uintptr_t)(_ADT_v) >= 5 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4)  {\
int v0=((struct _ADT_Test4_non_6*)((uintptr_t)_ADT_v-5))->f0; 
#define if_non_6_ptr(v, v0) \
{Test4 _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 5 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4)  {\
int *v0=&((struct _ADT_Test4_non_6*)((uintptr_t)_ADT_v-5))->f0; 
#define case_non_6(v0) \
break;}} case 9: {{Test4 _SW_tchk=_Test4_tchk;}{char _Test4_tchk; \
int v0=((struct _ADT_Test4_non_6*)((uintptr_t)_ADT_v-5))->f0; 
#define case_non_6_ptr(v0) \
break;}} case 9: {{Test4 _SW_tchk=_Test4_tchk;}{char _Test4_tchk; \
int *v0=&((struct _ADT_Test4_non_6*)((uintptr_t)_ADT_v-5))->f0; 

static __inline Test4 non_6(int v0){
	struct _ADT_Test4_non_6 *v=(struct _ADT_Test4_non_6*)malloc(sizeof(struct _ADT_Test4_non_6));
	v->f0=v0; 
	return (Test4)(5+(uintptr_t)v);
}

struct _ADT_Test4_non_7 {
    int f0;};
#define if_non_7(v, v0) \
{Test4 _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 6 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4) {\
int v0=((struct _ADT_Test4_non_7*)((uintptr_t)_ADT_v-6))->f0; 
#define else_if_non_7(v0) \
} else if ((uintptr_t)(_ADT_v) >= 6 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4)  {\
int v0=((struct _ADT_Test4_non_7*)((uintptr_t)_ADT_v-6))->f0; 
#define if_non_7_ptr(v, v0) \
{Test4 _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 6 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4)  {\
int *v0=&((struct _ADT_Test4_non_7*)((uintptr_t)_ADT_v-6))->f0; 
#define case_non_7(v0) \
break;}} case 10: {{Test4 _SW_tchk=_Test4_tchk;}{char _Test4_tchk; \
int v0=((struct _ADT_Test4_non_7*)((uintptr_t)_ADT_v-6))->f0; 
#define case_non_7_ptr(v0) \
break;}} case 10: {{Test4 _SW_tchk=_Test4_tchk;}{char _Test4_tchk; \
int *v0=&((struct _ADT_Test4_non_7*)((uintptr_t)_ADT_v-6))->f0; 

static __inline Test4 non_7(int v0){
	struct _ADT_Test4_non_7 *v=(struct _ADT_Test4_non_7*)malloc(sizeof(struct _ADT_Test4_non_7));
	v->f0=v0; 
	return (Test4)(6+(uintptr_t)v);
}

struct _ADT_Test4_non_8 {
    int f0;};
#define if_non_8(v, v0) \
{Test4 _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 7 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4) {\
int v0=((struct _ADT_Test4_non_8*)((uintptr_t)_ADT_v-LOW_BIT_USED))->f0; 
#define else_if_non_8(v0) \
} else if ((uintptr_t)(_ADT_v) >= 7 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4)  {\
int v0=((struct _ADT_Test4_non_8*)((uintptr_t)_ADT_v-LOW_BIT_USED))->f0; 
#define if_non_8_ptr(v, v0) \
{Test4 _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 7 && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==4)  {\
int *v0=&((struct _ADT_Test4_non_8*)((uintptr_t)_ADT_v-LOW_BIT_USED))->f0; 
#define case_non_8(v0) \
break;}} case 11: {{Test4 _SW_tchk=_Test4_tchk;}{char _Test4_tchk; \
int v0=((struct _ADT_Test4_non_8*)((uintptr_t)_ADT_v-LOW_BIT_USED))->f0; 
#define case_non_8_ptr(v0) \
break;}} case 11: {{Test4 _SW_tchk=_Test4_tchk;}{char _Test4_tchk; \
int *v0=&((struct _ADT_Test4_non_8*)((uintptr_t)_ADT_v-LOW_BIT_USED))->f0; 

static __inline Test4 non_8(int v0){
	struct _ADT_Test4_non_8 *v=(struct _ADT_Test4_non_8*)malloc(sizeof(struct _ADT_Test4_non_8));
	v->f0=v0; 
	return (Test4)(7+(uintptr_t)v);
}

/***************************/
typedef struct _ADT_Test3{} *Test3;
#define Test3_T_NUM_CONST (1) 
#define Test3_T_NUM_NONCONST (1) 
#define Test3_constructorNum(v) \
(( Test3_T_NUM_NONCONST>0 && v > Test3_T_NUM_CONST-1 ?  \
 ( Test3_T_NUM_NONCONST==1 ?  Test3_T_NUM_CONST   : \
(( Test3_T_NUM_NONCONST > (LOW_BIT_USED + 1))  && ((v&LOW_BIT_USED) == (LOW_BIT_USED))  )  ?   \
 (*(int*)((uintptr_t)_ADT_v-LOW_BIT_USED)) + Test3_T_NUM_CONST  : \
((v&(LOW_BIT_USED)) + Test3_T_NUM_CONST)) : v ) )

;
#define switch_Test3(v) \
{Test3 _Test3_tchk, _ADT_v=(v); \
int t = Test3_constructorNum((uintptr_t)(_ADT_v)); \
switch(t) {{{


/******************************************************************************/
static __inline void free_Test3(Test3 v){
	if ((uintptr_t)(v) >= 1){
		free((void*)((uintptr_t)v));
	}
}


struct _ADT_Test3_nil {};
#define if_nil(v) \
{Test3 _ADT_v=(v);if (((uintptr_t)(_ADT_v))==0) {
#define else_if_nil() \
} else if (((uintptr_t)(_ADT_v))==0) {
#define if_nil_ptr(v) \
{Test3 _ADT_v=(v);if (((uintptr_t)(_ADT_v))==0) {
#define case_nil() \
break;}} case 0: {{Test3 _SW_tchk=_Test3_tchk;}{char _Test3_tchk; 
#define case_nil_ptr() \
break;}} case 0: {{Test3 _SW_tchk=_Test3_tchk;}{char _Test3_tchk; 

static __inline Test3 nil(){
	struct _ADT_Test3_nil *v=(struct _ADT_Test3_nil*)0;
	return (Test3)((uintptr_t)v);
}

struct _ADT_Test3_non_con {
    int f0;};
#define if_non_con(v, v0) \
{Test3 _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 1) {\
int v0=((struct _ADT_Test3_non_con*)((uintptr_t)_ADT_v-0))->f0; 
#define else_if_non_con(v0) \
} else if ((uintptr_t)(_ADT_v) >= 1) {\
int v0=((struct _ADT_Test3_non_con*)((uintptr_t)_ADT_v-0))->f0; 
#define if_non_con_ptr(v, v0) \
{Test3 _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 1) {\
int *v0=&((struct _ADT_Test3_non_con*)((uintptr_t)_ADT_v-0))->f0; 
#define case_non_con(v0) \
break;}} case 1: {{Test3 _SW_tchk=_Test3_tchk;}{char _Test3_tchk; \
int v0=((struct _ADT_Test3_non_con*)((uintptr_t)_ADT_v-0))->f0; 
#define case_non_con_ptr(v0) \
break;}} case 1: {{Test3 _SW_tchk=_Test3_tchk;}{char _Test3_tchk; \
int *v0=&((struct _ADT_Test3_non_con*)((uintptr_t)_ADT_v-0))->f0; 

static __inline Test3 non_con(int v0){
	struct _ADT_Test3_non_con *v=(struct _ADT_Test3_non_con*)malloc(sizeof(struct _ADT_Test3_non_con));
	v->f0=v0; 
	return (Test3)(0+(uintptr_t)v);
}

/***************************/
typedef struct _ADT_Test2{} *Test2;
#define Test2_T_NUM_CONST (0) 
#define Test2_T_NUM_NONCONST (1) 
#define Test2_constructorNum(v) \
(( Test2_T_NUM_NONCONST>0 && v > Test2_T_NUM_CONST-1 ?  \
 ( Test2_T_NUM_NONCONST==1 ?  Test2_T_NUM_CONST   : \
(( Test2_T_NUM_NONCONST > (LOW_BIT_USED + 1))  && ((v&LOW_BIT_USED) == (LOW_BIT_USED))  )  ?   \
 (*(int*)((uintptr_t)_ADT_v-LOW_BIT_USED)) + Test2_T_NUM_CONST  : \
((v&(LOW_BIT_USED)) + Test2_T_NUM_CONST)) : v ) )

;
#define switch_Test2(v) \
{Test2 _Test2_tchk, _ADT_v=(v); \
int t = Test2_constructorNum((uintptr_t)(_ADT_v)); \
switch(t) {{{


/******************************************************************************/
static __inline void free_Test2(Test2 v){
	free((void*)((uintptr_t)v));
}


struct _ADT_Test2_non_con_1 {
    int f0;};
#define if_non_con_1(v, v0) \
{Test2 _ADT_v=(v);if (1) {\
int v0=((struct _ADT_Test2_non_con_1*)((uintptr_t)_ADT_v-0))->f0; 
#define else_if_non_con_1(v0) \
} else if (1) {\
int v0=((struct _ADT_Test2_non_con_1*)((uintptr_t)_ADT_v-0))->f0; 
#define if_non_con_1_ptr(v, v0) \
{Test2 _ADT_v=(v);if (1) {\
int *v0=&((struct _ADT_Test2_non_con_1*)((uintptr_t)_ADT_v-0))->f0; 
#define case_non_con_1(v0) \
break;}} case 0: {{Test2 _SW_tchk=_Test2_tchk;}{char _Test2_tchk; \
int v0=((struct _ADT_Test2_non_con_1*)((uintptr_t)_ADT_v-0))->f0; 
#define case_non_con_1_ptr(v0) \
break;}} case 0: {{Test2 _SW_tchk=_Test2_tchk;}{char _Test2_tchk; \
int *v0=&((struct _ADT_Test2_non_con_1*)((uintptr_t)_ADT_v-0))->f0; 

static __inline Test2 non_con_1(int v0){
	struct _ADT_Test2_non_con_1 *v=(struct _ADT_Test2_non_con_1*)malloc(sizeof(struct _ADT_Test2_non_con_1));
	v->f0=v0; 
	return (Test2)(0+(uintptr_t)v);
}

/***************************/
typedef struct _ADT_Test1{} *Test1;
#define Test1_T_NUM_CONST (12) 
#define Test1_T_NUM_NONCONST (0) 
#define Test1_constructorNum(v) \
(( Test1_T_NUM_NONCONST>0 && v > Test1_T_NUM_CONST-1 ?  \
 ( Test1_T_NUM_NONCONST==1 ?  Test1_T_NUM_CONST   : \
(( Test1_T_NUM_NONCONST > (LOW_BIT_USED + 1))  && ((v&LOW_BIT_USED) == (LOW_BIT_USED))  )  ?   \
 (*(int*)((uintptr_t)_ADT_v-LOW_BIT_USED)) + Test1_T_NUM_CONST  : \
((v&(LOW_BIT_USED)) + Test1_T_NUM_CONST)) : v ) )


#define switch_Test1(v) \
{Test1 _Test1_tchk, _ADT_v=(v); \
int t = Test1_constructorNum((uintptr_t)(_ADT_v)); \
switch(t) {{{


/******************************************************************************/
static __inline void free_Test1(Test1 v){
}


struct _ADT_Test1_con_1 {};
#define if_con_1(v) \
{Test1 _ADT_v=(v);if (((uintptr_t)(_ADT_v))==0) {
#define else_if_con_1() \
} else if (((uintptr_t)(_ADT_v))==0) {
#define if_con_1_ptr(v) \
{Test1 _ADT_v=(v);if (((uintptr_t)(_ADT_v))==0) {
#define case_con_1() \
break;}} case 0: {{Test1 _SW_tchk=_Test1_tchk;}{char _Test1_tchk; 
#define case_con_1_ptr() \
break;}} case 0: {{Test1 _SW_tchk=_Test1_tchk;}{char _Test1_tchk; 

static __inline Test1 con_1(){
	struct _ADT_Test1_con_1 *v=(struct _ADT_Test1_con_1*)0;
	return (Test1)((uintptr_t)v);
}

struct _ADT_Test1_con_2 {};
#define if_con_2(v) \
{Test1 _ADT_v=(v);if (((uintptr_t)(_ADT_v))==1) {
#define else_if_con_2() \
} else if (((uintptr_t)(_ADT_v))==1) {
#define if_con_2_ptr(v) \
{Test1 _ADT_v=(v);if (((uintptr_t)(_ADT_v))==1) {
#define case_con_2() \
break;}} case 1: {{Test1 _SW_tchk=_Test1_tchk;}{char _Test1_tchk; 
#define case_con_2_ptr() \
break;}} case 1: {{Test1 _SW_tchk=_Test1_tchk;}{char _Test1_tchk; 

static __inline Test1 con_2(){
	struct _ADT_Test1_con_2 *v=(struct _ADT_Test1_con_2*)1;
	return (Test1)((uintptr_t)v);
}

struct _ADT_Test1_con_3 {};
#define if_con_3(v) \
{Test1 _ADT_v=(v);if (((uintptr_t)(_ADT_v))==2) {
#define else_if_con_3() \
} else if (((uintptr_t)(_ADT_v))==2) {
#define if_con_3_ptr(v) \
{Test1 _ADT_v=(v);if (((uintptr_t)(_ADT_v))==2) {
#define case_con_3() \
break;}} case 2: {{Test1 _SW_tchk=_Test1_tchk;}{char _Test1_tchk; 
#define case_con_3_ptr() \
break;}} case 2: {{Test1 _SW_tchk=_Test1_tchk;}{char _Test1_tchk; 

static __inline Test1 con_3(){
	struct _ADT_Test1_con_3 *v=(struct _ADT_Test1_con_3*)2;
	return (Test1)((uintptr_t)v);
}

struct _ADT_Test1_con_4 {};
#define if_con_4(v) \
{Test1 _ADT_v=(v);if (((uintptr_t)(_ADT_v))==3) {
#define else_if_con_4() \
} else if (((uintptr_t)(_ADT_v))==3) {
#define if_con_4_ptr(v) \
{Test1 _ADT_v=(v);if (((uintptr_t)(_ADT_v))==3) {
#define case_con_4() \
break;}} case 3: {{Test1 _SW_tchk=_Test1_tchk;}{char _Test1_tchk; 
#define case_con_4_ptr() \
break;}} case 3: {{Test1 _SW_tchk=_Test1_tchk;}{char _Test1_tchk; 

static __inline Test1 con_4(){
	struct _ADT_Test1_con_4 *v=(struct _ADT_Test1_con_4*)3;
	return (Test1)((uintptr_t)v);
}

struct _ADT_Test1_con_5 {};
#define if_con_5(v) \
{Test1 _ADT_v=(v);if (((uintptr_t)(_ADT_v))==4) {
#define else_if_con_5() \
} else if (((uintptr_t)(_ADT_v))==4) {
#define if_con_5_ptr(v) \
{Test1 _ADT_v=(v);if (((uintptr_t)(_ADT_v))==4) {
#define case_con_5() \
break;}} case 4: {{Test1 _SW_tchk=_Test1_tchk;}{char _Test1_tchk; 
#define case_con_5_ptr() \
break;}} case 4: {{Test1 _SW_tchk=_Test1_tchk;}{char _Test1_tchk; 

static __inline Test1 con_5(){
	struct _ADT_Test1_con_5 *v=(struct _ADT_Test1_con_5*)4;
	return (Test1)((uintptr_t)v);
}

struct _ADT_Test1_con_6 {};
#define if_con_6(v) \
{Test1 _ADT_v=(v);if (((uintptr_t)(_ADT_v))==5) {
#define else_if_con_6() \
} else if (((uintptr_t)(_ADT_v))==5) {
#define if_con_6_ptr(v) \
{Test1 _ADT_v=(v);if (((uintptr_t)(_ADT_v))==5) {
#define case_con_6() \
break;}} case 5: {{Test1 _SW_tchk=_Test1_tchk;}{char _Test1_tchk; 
#define case_con_6_ptr() \
break;}} case 5: {{Test1 _SW_tchk=_Test1_tchk;}{char _Test1_tchk; 

static __inline Test1 con_6(){
	struct _ADT_Test1_con_6 *v=(struct _ADT_Test1_con_6*)5;
	return (Test1)((uintptr_t)v);
}

struct _ADT_Test1_con_7 {};
#define if_con_7(v) \
{Test1 _ADT_v=(v);if (((uintptr_t)(_ADT_v))==6) {
#define else_if_con_7() \
} else if (((uintptr_t)(_ADT_v))==6) {
#define if_con_7_ptr(v) \
{Test1 _ADT_v=(v);if (((uintptr_t)(_ADT_v))==6) {
#define case_con_7() \
break;}} case 6: {{Test1 _SW_tchk=_Test1_tchk;}{char _Test1_tchk; 
#define case_con_7_ptr() \
break;}} case 6: {{Test1 _SW_tchk=_Test1_tchk;}{char _Test1_tchk; 

static __inline Test1 con_7(){
	struct _ADT_Test1_con_7 *v=(struct _ADT_Test1_con_7*)6;
	return (Test1)((uintptr_t)v);
}

struct _ADT_Test1_con_8 {};
#define if_con_8(v) \
{Test1 _ADT_v=(v);if (((uintptr_t)(_ADT_v))==7) {
#define else_if_con_8() \
} else if (((uintptr_t)(_ADT_v))==7) {
#define if_con_8_ptr(v) \
{Test1 _ADT_v=(v);if (((uintptr_t)(_ADT_v))==7) {
#define case_con_8() \
break;}} case 7: {{Test1 _SW_tchk=_Test1_tchk;}{char _Test1_tchk; 
#define case_con_8_ptr() \
break;}} case 7: {{Test1 _SW_tchk=_Test1_tchk;}{char _Test1_tchk; 

static __inline Test1 con_8(){
	struct _ADT_Test1_con_8 *v=(struct _ADT_Test1_con_8*)7;
	return (Test1)((uintptr_t)v);
}

struct _ADT_Test1_con_9 {};
#define if_con_9(v) \
{Test1 _ADT_v=(v);if (((uintptr_t)(_ADT_v))==8) {
#define else_if_con_9() \
} else if (((uintptr_t)(_ADT_v))==8) {
#define if_con_9_ptr(v) \
{Test1 _ADT_v=(v);if (((uintptr_t)(_ADT_v))==8) {
#define case_con_9() \
break;}} case 8: {{Test1 _SW_tchk=_Test1_tchk;}{char _Test1_tchk; 
#define case_con_9_ptr() \
break;}} case 8: {{Test1 _SW_tchk=_Test1_tchk;}{char _Test1_tchk; 

static __inline Test1 con_9(){
	struct _ADT_Test1_con_9 *v=(struct _ADT_Test1_con_9*)8;
	return (Test1)((uintptr_t)v);
}

struct _ADT_Test1_con_10 {};
#define if_con_10(v) \
{Test1 _ADT_v=(v);if (((uintptr_t)(_ADT_v))==9) {
#define else_if_con_10() \
} else if (((uintptr_t)(_ADT_v))==9) {
#define if_con_10_ptr(v) \
{Test1 _ADT_v=(v);if (((uintptr_t)(_ADT_v))==9) {
#define case_con_10() \
break;}} case 9: {{Test1 _SW_tchk=_Test1_tchk;}{char _Test1_tchk; 
#define case_con_10_ptr() \
break;}} case 9: {{Test1 _SW_tchk=_Test1_tchk;}{char _Test1_tchk; 

static __inline Test1 con_10(){
	struct _ADT_Test1_con_10 *v=(struct _ADT_Test1_con_10*)9;
	return (Test1)((uintptr_t)v);
}

struct _ADT_Test1_con_11 {};
#define if_con_11(v) \
{Test1 _ADT_v=(v);if (((uintptr_t)(_ADT_v))==10) {
#define else_if_con_11() \
} else if (((uintptr_t)(_ADT_v))==10) {
#define if_con_11_ptr(v) \
{Test1 _ADT_v=(v);if (((uintptr_t)(_ADT_v))==10) {
#define case_con_11() \
break;}} case 10: {{Test1 _SW_tchk=_Test1_tchk;}{char _Test1_tchk; 
#define case_con_11_ptr() \
break;}} case 10: {{Test1 _SW_tchk=_Test1_tchk;}{char _Test1_tchk; 

static __inline Test1 con_11(){
	struct _ADT_Test1_con_11 *v=(struct _ADT_Test1_con_11*)10;
	return (Test1)((uintptr_t)v);
}

struct _ADT_Test1_con_12 {};
#define if_con_12(v) \
{Test1 _ADT_v=(v);if (((uintptr_t)(_ADT_v))==11) {
#define else_if_con_12() \
} else if (((uintptr_t)(_ADT_v))==11) {
#define if_con_12_ptr(v) \
{Test1 _ADT_v=(v);if (((uintptr_t)(_ADT_v))==11) {
#define case_con_12() \
break;}} case 11: {{Test1 _SW_tchk=_Test1_tchk;}{char _Test1_tchk; 
#define case_con_12_ptr() \
break;}} case 11: {{Test1 _SW_tchk=_Test1_tchk;}{char _Test1_tchk; 

static __inline Test1 con_12(){
	struct _ADT_Test1_con_12 *v=(struct _ADT_Test1_con_12*)11;
	return (Test1)((uintptr_t)v);
}
