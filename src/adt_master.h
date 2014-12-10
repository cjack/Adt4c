#include <stdint.h>
#include <stdlib.h>
typedef char *c_string;
#define end_switch() }}}}
#define default() break;}} default: {{
#define else() } else {
#define end_if() }}
#ifndef ADT_MALLOC
#define ADT_MALLOC(s) malloc(s)
#endif
#ifndef ADT_FREE
#define ADT_FREE(s) free(s)
#endif
#ifndef LOW_BIT_USED
#define LOW_BIT_USED 7
#endif
/***************************/
typedef struct _ADT_string_t{} *string_t;
#define string_t_T_NUM_CONST (0) 
#define string_t_T_NUM_NONCONST (1) 
#define string_t_constructorNum(v) \
(( string_t_T_NUM_NONCONST>0 && v >= string_t_T_NUM_CONST ?  \
 ( string_t_T_NUM_NONCONST==1 ?  string_t_T_NUM_CONST   : \
(( string_t_T_NUM_NONCONST > (LOW_BIT_USED + 1))  && ((v&LOW_BIT_USED) == (LOW_BIT_USED))  )  ?   \
 (*(int*)((uintptr_t)_ADT_v-LOW_BIT_USED)) + string_t_T_NUM_CONST  : \
((v&(LOW_BIT_USED)) + string_t_T_NUM_CONST)) : v ) )

static __inline void free_string_t(string_t v);
#define switch_string_t(v) \
{string_t _string_t_tchk, _ADT_v=(v); \
int t = string_t_constructorNum((uintptr_t)(_ADT_v)); \
switch(t) {{{


/******************************************************************************/
static __inline void free_string_t(string_t v){
	if ((uintptr_t)(v) >= 0){
		ADT_FREE((void*)((uintptr_t)v));
	}
}

;
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

static __inline string_t string(c_string v0){
	struct _ADT_string_t_string *v=(struct _ADT_string_t_string*)ADT_MALLOC(sizeof(struct _ADT_string_t_string));
	v->f0=v0; 
	return (string_t)(0+(uintptr_t)v);
}

/***************************/
typedef struct _ADT_stringlist_t{} *stringlist_t;
#define stringlist_t_T_NUM_CONST (1) 
#define stringlist_t_T_NUM_NONCONST (1) 
#define stringlist_t_constructorNum(v) \
(( stringlist_t_T_NUM_NONCONST>0 && v >= stringlist_t_T_NUM_CONST ?  \
 ( stringlist_t_T_NUM_NONCONST==1 ?  stringlist_t_T_NUM_CONST   : \
(( stringlist_t_T_NUM_NONCONST > (LOW_BIT_USED + 1))  && ((v&LOW_BIT_USED) == (LOW_BIT_USED))  )  ?   \
 (*(int*)((uintptr_t)_ADT_v-LOW_BIT_USED)) + stringlist_t_T_NUM_CONST  : \
((v&(LOW_BIT_USED)) + stringlist_t_T_NUM_CONST)) : v ) )

static __inline void free_stringlist_t(stringlist_t v);
#define switch_stringlist_t(v) \
{stringlist_t _stringlist_t_tchk, _ADT_v=(v); \
int t = stringlist_t_constructorNum((uintptr_t)(_ADT_v)); \
switch(t) {{{


/******************************************************************************/
static __inline void free_stringlist_t(stringlist_t v){
	if ((uintptr_t)(v) >= 1){
		ADT_FREE((void*)((uintptr_t)v));
	}
}

;
struct _ADT_stringlist_t_nextlist {
    struct _ADT_string_t* f0;
    struct _ADT_stringlist_t* f1;};
#define if_nextlist(v, v0, v1) \
{stringlist_t _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 1) {\
struct _ADT_string_t* v0=((struct _ADT_stringlist_t_nextlist*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_stringlist_t* v1=((struct _ADT_stringlist_t_nextlist*)((uintptr_t)_ADT_v-0))->f1; 
#define else_if_nextlist(v0, v1) \
} else if ((uintptr_t)(_ADT_v) >= 1) {\
struct _ADT_string_t* v0=((struct _ADT_stringlist_t_nextlist*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_stringlist_t* v1=((struct _ADT_stringlist_t_nextlist*)((uintptr_t)_ADT_v-0))->f1; 
#define if_nextlist_ptr(v, v0, v1) \
{stringlist_t _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 1) {\
struct _ADT_string_t* *v0=&((struct _ADT_stringlist_t_nextlist*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_stringlist_t* *v1=&((struct _ADT_stringlist_t_nextlist*)((uintptr_t)_ADT_v-0))->f1; 
#define case_nextlist(v0, v1) \
break;}} case 1: {{stringlist_t _SW_tchk=_stringlist_t_tchk;}{char _stringlist_t_tchk; \
struct _ADT_string_t* v0=((struct _ADT_stringlist_t_nextlist*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_stringlist_t* v1=((struct _ADT_stringlist_t_nextlist*)((uintptr_t)_ADT_v-0))->f1; 
#define case_nextlist_ptr(v0, v1) \
break;}} case 1: {{stringlist_t _SW_tchk=_stringlist_t_tchk;}{char _stringlist_t_tchk; \
struct _ADT_string_t* *v0=&((struct _ADT_stringlist_t_nextlist*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_stringlist_t* *v1=&((struct _ADT_stringlist_t_nextlist*)((uintptr_t)_ADT_v-0))->f1; 

static __inline stringlist_t nextlist(struct _ADT_string_t* v0, struct _ADT_stringlist_t* v1){
	struct _ADT_stringlist_t_nextlist *v=(struct _ADT_stringlist_t_nextlist*)ADT_MALLOC(sizeof(struct _ADT_stringlist_t_nextlist));
	v->f0=v0; 
	v->f1=v1; 
	return (stringlist_t)(0+(uintptr_t)v);
}
;
struct _ADT_stringlist_t_nil {};
#define if_nil(v) \
{stringlist_t _ADT_v=(v);if (((uintptr_t)(_ADT_v))==0) {
#define else_if_nil() \
} else if (((uintptr_t)(_ADT_v))==0) {
#define if_nil_ptr(v) \
{stringlist_t _ADT_v=(v);if (((uintptr_t)(_ADT_v))==0) {
#define case_nil() \
break;}} case 0: {{stringlist_t _SW_tchk=_stringlist_t_tchk;}{char _stringlist_t_tchk; 
#define case_nil_ptr() \
break;}} case 0: {{stringlist_t _SW_tchk=_stringlist_t_tchk;}{char _stringlist_t_tchk; 

static __inline stringlist_t nil(){
	struct _ADT_stringlist_t_nil *v=(struct _ADT_stringlist_t_nil*)0;
	return (stringlist_t)((uintptr_t)v);
}

/***************************/
typedef struct _ADT_arg_t{} *arg_t;
#define arg_t_T_NUM_CONST (0) 
#define arg_t_T_NUM_NONCONST (1) 
#define arg_t_constructorNum(v) \
(( arg_t_T_NUM_NONCONST>0 && v >= arg_t_T_NUM_CONST ?  \
 ( arg_t_T_NUM_NONCONST==1 ?  arg_t_T_NUM_CONST   : \
(( arg_t_T_NUM_NONCONST > (LOW_BIT_USED + 1))  && ((v&LOW_BIT_USED) == (LOW_BIT_USED))  )  ?   \
 (*(int*)((uintptr_t)_ADT_v-LOW_BIT_USED)) + arg_t_T_NUM_CONST  : \
((v&(LOW_BIT_USED)) + arg_t_T_NUM_CONST)) : v ) )

static __inline void free_arg_t(arg_t v);
#define switch_arg_t(v) \
{arg_t _arg_t_tchk, _ADT_v=(v); \
int t = arg_t_constructorNum((uintptr_t)(_ADT_v)); \
switch(t) {{{


/******************************************************************************/
static __inline void free_arg_t(arg_t v){
	if ((uintptr_t)(v) >= 0){
		ADT_FREE((void*)((uintptr_t)v));
	}
}

;
struct _ADT_arg_t_arg {
    struct _ADT_string_t* f0;};
#define if_arg(v, v0) \
{arg_t _ADT_v=(v);if (1) {\
struct _ADT_string_t* v0=((struct _ADT_arg_t_arg*)((uintptr_t)_ADT_v-0))->f0; 
#define else_if_arg(v0) \
} else if (1) {\
struct _ADT_string_t* v0=((struct _ADT_arg_t_arg*)((uintptr_t)_ADT_v-0))->f0; 
#define if_arg_ptr(v, v0) \
{arg_t _ADT_v=(v);if (1) {\
struct _ADT_string_t* *v0=&((struct _ADT_arg_t_arg*)((uintptr_t)_ADT_v-0))->f0; 
#define case_arg(v0) \
break;}} case 0: {{arg_t _SW_tchk=_arg_t_tchk;}{char _arg_t_tchk; \
struct _ADT_string_t* v0=((struct _ADT_arg_t_arg*)((uintptr_t)_ADT_v-0))->f0; 
#define case_arg_ptr(v0) \
break;}} case 0: {{arg_t _SW_tchk=_arg_t_tchk;}{char _arg_t_tchk; \
struct _ADT_string_t* *v0=&((struct _ADT_arg_t_arg*)((uintptr_t)_ADT_v-0))->f0; 

static __inline arg_t arg(struct _ADT_string_t* v0){
	struct _ADT_arg_t_arg *v=(struct _ADT_arg_t_arg*)ADT_MALLOC(sizeof(struct _ADT_arg_t_arg));
	v->f0=v0; 
	return (arg_t)(0+(uintptr_t)v);
}

/***************************/
typedef struct _ADT_arglist_t{} *arglist_t;
#define arglist_t_T_NUM_CONST (1) 
#define arglist_t_T_NUM_NONCONST (1) 
#define arglist_t_constructorNum(v) \
(( arglist_t_T_NUM_NONCONST>0 && v >= arglist_t_T_NUM_CONST ?  \
 ( arglist_t_T_NUM_NONCONST==1 ?  arglist_t_T_NUM_CONST   : \
(( arglist_t_T_NUM_NONCONST > (LOW_BIT_USED + 1))  && ((v&LOW_BIT_USED) == (LOW_BIT_USED))  )  ?   \
 (*(int*)((uintptr_t)_ADT_v-LOW_BIT_USED)) + arglist_t_T_NUM_CONST  : \
((v&(LOW_BIT_USED)) + arglist_t_T_NUM_CONST)) : v ) )

static __inline void free_arglist_t(arglist_t v);
#define switch_arglist_t(v) \
{arglist_t _arglist_t_tchk, _ADT_v=(v); \
int t = arglist_t_constructorNum((uintptr_t)(_ADT_v)); \
switch(t) {{{


/******************************************************************************/
static __inline void free_arglist_t(arglist_t v){
	if ((uintptr_t)(v) >= 1){
		ADT_FREE((void*)((uintptr_t)v));
	}
}

;
struct _ADT_arglist_t_nextarg {
    struct _ADT_arg_t* f0;
    struct _ADT_arglist_t* f1;};
#define if_nextarg(v, v0, v1) \
{arglist_t _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 1) {\
struct _ADT_arg_t* v0=((struct _ADT_arglist_t_nextarg*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_arglist_t* v1=((struct _ADT_arglist_t_nextarg*)((uintptr_t)_ADT_v-0))->f1; 
#define else_if_nextarg(v0, v1) \
} else if ((uintptr_t)(_ADT_v) >= 1) {\
struct _ADT_arg_t* v0=((struct _ADT_arglist_t_nextarg*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_arglist_t* v1=((struct _ADT_arglist_t_nextarg*)((uintptr_t)_ADT_v-0))->f1; 
#define if_nextarg_ptr(v, v0, v1) \
{arglist_t _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 1) {\
struct _ADT_arg_t* *v0=&((struct _ADT_arglist_t_nextarg*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_arglist_t* *v1=&((struct _ADT_arglist_t_nextarg*)((uintptr_t)_ADT_v-0))->f1; 
#define case_nextarg(v0, v1) \
break;}} case 1: {{arglist_t _SW_tchk=_arglist_t_tchk;}{char _arglist_t_tchk; \
struct _ADT_arg_t* v0=((struct _ADT_arglist_t_nextarg*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_arglist_t* v1=((struct _ADT_arglist_t_nextarg*)((uintptr_t)_ADT_v-0))->f1; 
#define case_nextarg_ptr(v0, v1) \
break;}} case 1: {{arglist_t _SW_tchk=_arglist_t_tchk;}{char _arglist_t_tchk; \
struct _ADT_arg_t* *v0=&((struct _ADT_arglist_t_nextarg*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_arglist_t* *v1=&((struct _ADT_arglist_t_nextarg*)((uintptr_t)_ADT_v-0))->f1; 

static __inline arglist_t nextarg(struct _ADT_arg_t* v0, struct _ADT_arglist_t* v1){
	struct _ADT_arglist_t_nextarg *v=(struct _ADT_arglist_t_nextarg*)ADT_MALLOC(sizeof(struct _ADT_arglist_t_nextarg));
	v->f0=v0; 
	v->f1=v1; 
	return (arglist_t)(0+(uintptr_t)v);
}
;
struct _ADT_arglist_t_noarg {};
#define if_noarg(v) \
{arglist_t _ADT_v=(v);if (((uintptr_t)(_ADT_v))==0) {
#define else_if_noarg() \
} else if (((uintptr_t)(_ADT_v))==0) {
#define if_noarg_ptr(v) \
{arglist_t _ADT_v=(v);if (((uintptr_t)(_ADT_v))==0) {
#define case_noarg() \
break;}} case 0: {{arglist_t _SW_tchk=_arglist_t_tchk;}{char _arglist_t_tchk; 
#define case_noarg_ptr() \
break;}} case 0: {{arglist_t _SW_tchk=_arglist_t_tchk;}{char _arglist_t_tchk; 

static __inline arglist_t noarg(){
	struct _ADT_arglist_t_noarg *v=(struct _ADT_arglist_t_noarg*)0;
	return (arglist_t)((uintptr_t)v);
}

/***************************/
typedef struct _ADT_ctr_t{} *ctr_t;
#define ctr_t_T_NUM_CONST (0) 
#define ctr_t_T_NUM_NONCONST (1) 
#define ctr_t_constructorNum(v) \
(( ctr_t_T_NUM_NONCONST>0 && v >= ctr_t_T_NUM_CONST ?  \
 ( ctr_t_T_NUM_NONCONST==1 ?  ctr_t_T_NUM_CONST   : \
(( ctr_t_T_NUM_NONCONST > (LOW_BIT_USED + 1))  && ((v&LOW_BIT_USED) == (LOW_BIT_USED))  )  ?   \
 (*(int*)((uintptr_t)_ADT_v-LOW_BIT_USED)) + ctr_t_T_NUM_CONST  : \
((v&(LOW_BIT_USED)) + ctr_t_T_NUM_CONST)) : v ) )

static __inline void free_ctr_t(ctr_t v);
#define switch_ctr_t(v) \
{ctr_t _ctr_t_tchk, _ADT_v=(v); \
int t = ctr_t_constructorNum((uintptr_t)(_ADT_v)); \
switch(t) {{{


/******************************************************************************/
static __inline void free_ctr_t(ctr_t v){
	if ((uintptr_t)(v) >= 0){
		ADT_FREE((void*)((uintptr_t)v));
	}
}

;
struct _ADT_ctr_t_ctr {
    struct _ADT_string_t* f0;
    struct _ADT_arglist_t* f1;};
#define if_ctr(v, v0, v1) \
{ctr_t _ADT_v=(v);if (1) {\
struct _ADT_string_t* v0=((struct _ADT_ctr_t_ctr*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_arglist_t* v1=((struct _ADT_ctr_t_ctr*)((uintptr_t)_ADT_v-0))->f1; 
#define else_if_ctr(v0, v1) \
} else if (1) {\
struct _ADT_string_t* v0=((struct _ADT_ctr_t_ctr*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_arglist_t* v1=((struct _ADT_ctr_t_ctr*)((uintptr_t)_ADT_v-0))->f1; 
#define if_ctr_ptr(v, v0, v1) \
{ctr_t _ADT_v=(v);if (1) {\
struct _ADT_string_t* *v0=&((struct _ADT_ctr_t_ctr*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_arglist_t* *v1=&((struct _ADT_ctr_t_ctr*)((uintptr_t)_ADT_v-0))->f1; 
#define case_ctr(v0, v1) \
break;}} case 0: {{ctr_t _SW_tchk=_ctr_t_tchk;}{char _ctr_t_tchk; \
struct _ADT_string_t* v0=((struct _ADT_ctr_t_ctr*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_arglist_t* v1=((struct _ADT_ctr_t_ctr*)((uintptr_t)_ADT_v-0))->f1; 
#define case_ctr_ptr(v0, v1) \
break;}} case 0: {{ctr_t _SW_tchk=_ctr_t_tchk;}{char _ctr_t_tchk; \
struct _ADT_string_t* *v0=&((struct _ADT_ctr_t_ctr*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_arglist_t* *v1=&((struct _ADT_ctr_t_ctr*)((uintptr_t)_ADT_v-0))->f1; 

static __inline ctr_t ctr(struct _ADT_string_t* v0, struct _ADT_arglist_t* v1){
	struct _ADT_ctr_t_ctr *v=(struct _ADT_ctr_t_ctr*)ADT_MALLOC(sizeof(struct _ADT_ctr_t_ctr));
	v->f0=v0; 
	v->f1=v1; 
	return (ctr_t)(0+(uintptr_t)v);
}

/***************************/
typedef struct _ADT_ctrlist_t{} *ctrlist_t;
#define ctrlist_t_T_NUM_CONST (1) 
#define ctrlist_t_T_NUM_NONCONST (1) 
#define ctrlist_t_constructorNum(v) \
(( ctrlist_t_T_NUM_NONCONST>0 && v >= ctrlist_t_T_NUM_CONST ?  \
 ( ctrlist_t_T_NUM_NONCONST==1 ?  ctrlist_t_T_NUM_CONST   : \
(( ctrlist_t_T_NUM_NONCONST > (LOW_BIT_USED + 1))  && ((v&LOW_BIT_USED) == (LOW_BIT_USED))  )  ?   \
 (*(int*)((uintptr_t)_ADT_v-LOW_BIT_USED)) + ctrlist_t_T_NUM_CONST  : \
((v&(LOW_BIT_USED)) + ctrlist_t_T_NUM_CONST)) : v ) )

static __inline void free_ctrlist_t(ctrlist_t v);
#define switch_ctrlist_t(v) \
{ctrlist_t _ctrlist_t_tchk, _ADT_v=(v); \
int t = ctrlist_t_constructorNum((uintptr_t)(_ADT_v)); \
switch(t) {{{


/******************************************************************************/
static __inline void free_ctrlist_t(ctrlist_t v){
	if ((uintptr_t)(v) >= 1){
		ADT_FREE((void*)((uintptr_t)v));
	}
}

;
struct _ADT_ctrlist_t_nextctr {
    struct _ADT_ctr_t* f0;
    struct _ADT_ctrlist_t* f1;};
#define if_nextctr(v, v0, v1) \
{ctrlist_t _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 1) {\
struct _ADT_ctr_t* v0=((struct _ADT_ctrlist_t_nextctr*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_ctrlist_t* v1=((struct _ADT_ctrlist_t_nextctr*)((uintptr_t)_ADT_v-0))->f1; 
#define else_if_nextctr(v0, v1) \
} else if ((uintptr_t)(_ADT_v) >= 1) {\
struct _ADT_ctr_t* v0=((struct _ADT_ctrlist_t_nextctr*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_ctrlist_t* v1=((struct _ADT_ctrlist_t_nextctr*)((uintptr_t)_ADT_v-0))->f1; 
#define if_nextctr_ptr(v, v0, v1) \
{ctrlist_t _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 1) {\
struct _ADT_ctr_t* *v0=&((struct _ADT_ctrlist_t_nextctr*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_ctrlist_t* *v1=&((struct _ADT_ctrlist_t_nextctr*)((uintptr_t)_ADT_v-0))->f1; 
#define case_nextctr(v0, v1) \
break;}} case 1: {{ctrlist_t _SW_tchk=_ctrlist_t_tchk;}{char _ctrlist_t_tchk; \
struct _ADT_ctr_t* v0=((struct _ADT_ctrlist_t_nextctr*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_ctrlist_t* v1=((struct _ADT_ctrlist_t_nextctr*)((uintptr_t)_ADT_v-0))->f1; 
#define case_nextctr_ptr(v0, v1) \
break;}} case 1: {{ctrlist_t _SW_tchk=_ctrlist_t_tchk;}{char _ctrlist_t_tchk; \
struct _ADT_ctr_t* *v0=&((struct _ADT_ctrlist_t_nextctr*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_ctrlist_t* *v1=&((struct _ADT_ctrlist_t_nextctr*)((uintptr_t)_ADT_v-0))->f1; 

static __inline ctrlist_t nextctr(struct _ADT_ctr_t* v0, struct _ADT_ctrlist_t* v1){
	struct _ADT_ctrlist_t_nextctr *v=(struct _ADT_ctrlist_t_nextctr*)ADT_MALLOC(sizeof(struct _ADT_ctrlist_t_nextctr));
	v->f0=v0; 
	v->f1=v1; 
	return (ctrlist_t)(0+(uintptr_t)v);
}
;
struct _ADT_ctrlist_t_noctr {};
#define if_noctr(v) \
{ctrlist_t _ADT_v=(v);if (((uintptr_t)(_ADT_v))==0) {
#define else_if_noctr() \
} else if (((uintptr_t)(_ADT_v))==0) {
#define if_noctr_ptr(v) \
{ctrlist_t _ADT_v=(v);if (((uintptr_t)(_ADT_v))==0) {
#define case_noctr() \
break;}} case 0: {{ctrlist_t _SW_tchk=_ctrlist_t_tchk;}{char _ctrlist_t_tchk; 
#define case_noctr_ptr() \
break;}} case 0: {{ctrlist_t _SW_tchk=_ctrlist_t_tchk;}{char _ctrlist_t_tchk; 

static __inline ctrlist_t noctr(){
	struct _ADT_ctrlist_t_noctr *v=(struct _ADT_ctrlist_t_noctr*)0;
	return (ctrlist_t)((uintptr_t)v);
}

/***************************/
typedef struct _ADT_decl_t{} *decl_t;
#define decl_t_T_NUM_CONST (0) 
#define decl_t_T_NUM_NONCONST (1) 
#define decl_t_constructorNum(v) \
(( decl_t_T_NUM_NONCONST>0 && v >= decl_t_T_NUM_CONST ?  \
 ( decl_t_T_NUM_NONCONST==1 ?  decl_t_T_NUM_CONST   : \
(( decl_t_T_NUM_NONCONST > (LOW_BIT_USED + 1))  && ((v&LOW_BIT_USED) == (LOW_BIT_USED))  )  ?   \
 (*(int*)((uintptr_t)_ADT_v-LOW_BIT_USED)) + decl_t_T_NUM_CONST  : \
((v&(LOW_BIT_USED)) + decl_t_T_NUM_CONST)) : v ) )

static __inline void free_decl_t(decl_t v);
#define switch_decl_t(v) \
{decl_t _decl_t_tchk, _ADT_v=(v); \
int t = decl_t_constructorNum((uintptr_t)(_ADT_v)); \
switch(t) {{{


/******************************************************************************/
static __inline void free_decl_t(decl_t v){
	if ((uintptr_t)(v) >= 0){
		ADT_FREE((void*)((uintptr_t)v));
	}
}

;
struct _ADT_decl_t_decl {
    struct _ADT_string_t* f0;
    struct _ADT_ctrlist_t* f1;};
#define if_decl(v, v0, v1) \
{decl_t _ADT_v=(v);if (1) {\
struct _ADT_string_t* v0=((struct _ADT_decl_t_decl*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_ctrlist_t* v1=((struct _ADT_decl_t_decl*)((uintptr_t)_ADT_v-0))->f1; 
#define else_if_decl(v0, v1) \
} else if (1) {\
struct _ADT_string_t* v0=((struct _ADT_decl_t_decl*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_ctrlist_t* v1=((struct _ADT_decl_t_decl*)((uintptr_t)_ADT_v-0))->f1; 
#define if_decl_ptr(v, v0, v1) \
{decl_t _ADT_v=(v);if (1) {\
struct _ADT_string_t* *v0=&((struct _ADT_decl_t_decl*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_ctrlist_t* *v1=&((struct _ADT_decl_t_decl*)((uintptr_t)_ADT_v-0))->f1; 
#define case_decl(v0, v1) \
break;}} case 0: {{decl_t _SW_tchk=_decl_t_tchk;}{char _decl_t_tchk; \
struct _ADT_string_t* v0=((struct _ADT_decl_t_decl*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_ctrlist_t* v1=((struct _ADT_decl_t_decl*)((uintptr_t)_ADT_v-0))->f1; 
#define case_decl_ptr(v0, v1) \
break;}} case 0: {{decl_t _SW_tchk=_decl_t_tchk;}{char _decl_t_tchk; \
struct _ADT_string_t* *v0=&((struct _ADT_decl_t_decl*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_ctrlist_t* *v1=&((struct _ADT_decl_t_decl*)((uintptr_t)_ADT_v-0))->f1; 

static __inline decl_t decl(struct _ADT_string_t* v0, struct _ADT_ctrlist_t* v1){
	struct _ADT_decl_t_decl *v=(struct _ADT_decl_t_decl*)ADT_MALLOC(sizeof(struct _ADT_decl_t_decl));
	v->f0=v0; 
	v->f1=v1; 
	return (decl_t)(0+(uintptr_t)v);
}

/***************************/
typedef struct _ADT_decllist_t{} *decllist_t;
#define decllist_t_T_NUM_CONST (1) 
#define decllist_t_T_NUM_NONCONST (1) 
#define decllist_t_constructorNum(v) \
(( decllist_t_T_NUM_NONCONST>0 && v >= decllist_t_T_NUM_CONST ?  \
 ( decllist_t_T_NUM_NONCONST==1 ?  decllist_t_T_NUM_CONST   : \
(( decllist_t_T_NUM_NONCONST > (LOW_BIT_USED + 1))  && ((v&LOW_BIT_USED) == (LOW_BIT_USED))  )  ?   \
 (*(int*)((uintptr_t)_ADT_v-LOW_BIT_USED)) + decllist_t_T_NUM_CONST  : \
((v&(LOW_BIT_USED)) + decllist_t_T_NUM_CONST)) : v ) )

static __inline void free_decllist_t(decllist_t v);
#define switch_decllist_t(v) \
{decllist_t _decllist_t_tchk, _ADT_v=(v); \
int t = decllist_t_constructorNum((uintptr_t)(_ADT_v)); \
switch(t) {{{


/******************************************************************************/
static __inline void free_decllist_t(decllist_t v){
	if ((uintptr_t)(v) >= 1){
		ADT_FREE((void*)((uintptr_t)v));
	}
}

;
struct _ADT_decllist_t_nextdecl {
    struct _ADT_decl_t* f0;
    struct _ADT_decllist_t* f1;};
#define if_nextdecl(v, v0, v1) \
{decllist_t _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 1) {\
struct _ADT_decl_t* v0=((struct _ADT_decllist_t_nextdecl*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_decllist_t* v1=((struct _ADT_decllist_t_nextdecl*)((uintptr_t)_ADT_v-0))->f1; 
#define else_if_nextdecl(v0, v1) \
} else if ((uintptr_t)(_ADT_v) >= 1) {\
struct _ADT_decl_t* v0=((struct _ADT_decllist_t_nextdecl*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_decllist_t* v1=((struct _ADT_decllist_t_nextdecl*)((uintptr_t)_ADT_v-0))->f1; 
#define if_nextdecl_ptr(v, v0, v1) \
{decllist_t _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= 1) {\
struct _ADT_decl_t* *v0=&((struct _ADT_decllist_t_nextdecl*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_decllist_t* *v1=&((struct _ADT_decllist_t_nextdecl*)((uintptr_t)_ADT_v-0))->f1; 
#define case_nextdecl(v0, v1) \
break;}} case 1: {{decllist_t _SW_tchk=_decllist_t_tchk;}{char _decllist_t_tchk; \
struct _ADT_decl_t* v0=((struct _ADT_decllist_t_nextdecl*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_decllist_t* v1=((struct _ADT_decllist_t_nextdecl*)((uintptr_t)_ADT_v-0))->f1; 
#define case_nextdecl_ptr(v0, v1) \
break;}} case 1: {{decllist_t _SW_tchk=_decllist_t_tchk;}{char _decllist_t_tchk; \
struct _ADT_decl_t* *v0=&((struct _ADT_decllist_t_nextdecl*)((uintptr_t)_ADT_v-0))->f0; \
struct _ADT_decllist_t* *v1=&((struct _ADT_decllist_t_nextdecl*)((uintptr_t)_ADT_v-0))->f1; 

static __inline decllist_t nextdecl(struct _ADT_decl_t* v0, struct _ADT_decllist_t* v1){
	struct _ADT_decllist_t_nextdecl *v=(struct _ADT_decllist_t_nextdecl*)ADT_MALLOC(sizeof(struct _ADT_decllist_t_nextdecl));
	v->f0=v0; 
	v->f1=v1; 
	return (decllist_t)(0+(uintptr_t)v);
}
;
struct _ADT_decllist_t_nodecl {};
#define if_nodecl(v) \
{decllist_t _ADT_v=(v);if (((uintptr_t)(_ADT_v))==0) {
#define else_if_nodecl() \
} else if (((uintptr_t)(_ADT_v))==0) {
#define if_nodecl_ptr(v) \
{decllist_t _ADT_v=(v);if (((uintptr_t)(_ADT_v))==0) {
#define case_nodecl() \
break;}} case 0: {{decllist_t _SW_tchk=_decllist_t_tchk;}{char _decllist_t_tchk; 
#define case_nodecl_ptr() \
break;}} case 0: {{decllist_t _SW_tchk=_decllist_t_tchk;}{char _decllist_t_tchk; 

static __inline decllist_t nodecl(){
	struct _ADT_decllist_t_nodecl *v=(struct _ADT_decllist_t_nodecl*)0;
	return (decllist_t)((uintptr_t)v);
}
