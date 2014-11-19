#include <stdint.h>
typedef char *c_string;
#define end_switch() }}}}
#define default() break;}} default: {{
#define else() } else {
#define end_if() }}
#define LOW_BIT_USED 7
/***************************/
typedef struct _ADT_string_t{} *string_t;
#define string_t_T_NUM_CONST (0) 
#define string_t_T_NUM_NONCONST (1) 
#define string_t_constructorNum(v) \
(( string_t_T_NUM_NONCONST>0 && v > string_t_T_NUM_CONST-1 ?  \
 ( string_t_T_NUM_NONCONST==1 ?  string_t_T_NUM_CONST   : \
(( string_t_T_NUM_NONCONST > (LOW_BIT_USED + 1))  && ((v&LOW_BIT_USED) == (LOW_BIT_USED))  )  ?   \
 (*(int*)((uintptr_t)_ADT_v-LOW_BIT_USED)) + string_t_T_NUM_CONST  : \
((v&(LOW_BIT_USED)) + string_t_T_NUM_CONST)) : v ) )

void free_string_t(string_t v);
#define switch_string_t(v) \
{string_t _string_t_tchk, _ADT_v=(v); \
int t = string_t_constructorNum((uintptr_t)(_ADT_v)); \
switch(t) {{{

string_t string(c_string v0);
struct _ADT_string_t_string {
    c_string f0;};
#define if_string(v, v0) \
{string_t _ADT_v=(v);if (1) {\
c_string v0=((struct _ADT_string_t_string*)((uintptr_t)_ADT_v-0))->f0; 
#define else_if_string(v0) \
} else if (1) {\
c_string v0=((struct _ADT_string_t_string*)((uintptr_t)_ADT_v-0))->f0; 
#define if_string_ptr(v, v0) \
{string_t _ADT_v=(v);if (1) {\
c_string *v0=&((struct _ADT_string_t_string*)((uintptr_t)_ADT_v-0))->f0; 
#define case_string(v0) \
break;}} case 0: {{string_t _SW_tchk=_string_t_tchk;}{char _string_t_tchk; \
c_string v0=((struct _ADT_string_t_string*)((uintptr_t)_ADT_v-0))->f0; 
#define case_string_ptr(v0) \
break;}} case 0: {{string_t _SW_tchk=_string_t_tchk;}{char _string_t_tchk; \
c_string *v0=&((struct _ADT_string_t_string*)((uintptr_t)_ADT_v-0))->f0; 

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

void free_int_list(int_list v);
#define switch_int_list(v) \
{int_list _int_list_tchk, _ADT_v=(v); \
int t = int_list_constructorNum((uintptr_t)(_ADT_v)); \
switch(t) {{{

int_list nil();
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

int_list next_list(int v0, struct _ADT_int_list* v1);
struct _ADT_int_list_next_list {
    int f0;
    struct _ADT_int_list* f1;};
#define if_next_list(v, v0, v1) \
{int_list _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 1) {\
int v0=((struct _ADT_int_list_next_list*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_int_list* v1=((struct _ADT_int_list_next_list*)((uintptr_t)_ADT_v-0))->f1; 
#define else_if_next_list(v0, v1) \
} else if ((uintptr_t)(_ADT_v) >= 1) {\
int v0=((struct _ADT_int_list_next_list*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_int_list* v1=((struct _ADT_int_list_next_list*)((uintptr_t)_ADT_v-0))->f1; 
#define if_next_list_ptr(v, v0, v1) \
{int_list _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 1) {\
int *v0=&((struct _ADT_int_list_next_list*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_int_list* *v1=&((struct _ADT_int_list_next_list*)((uintptr_t)_ADT_v-0))->f1; 
#define case_next_list(v0, v1) \
break;}} case 1: {{int_list _SW_tchk=_int_list_tchk;}{char _int_list_tchk; \
int v0=((struct _ADT_int_list_next_list*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_int_list* v1=((struct _ADT_int_list_next_list*)((uintptr_t)_ADT_v-0))->f1; 
#define case_next_list_ptr(v0, v1) \
break;}} case 1: {{int_list _SW_tchk=_int_list_tchk;}{char _int_list_tchk; \
int *v0=&((struct _ADT_int_list_next_list*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_int_list* *v1=&((struct _ADT_int_list_next_list*)((uintptr_t)_ADT_v-0))->f1; 
