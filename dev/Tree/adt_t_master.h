#include <stdint.h>
typedef char *c_string;
#define end_switch() }}}}
#define default() break;}} default: {{
#define else() } else {
#define end_if() }}
/***************************/
typedef struct _ADT_string_t{} *string_t;
void free_string_t(string_t v);
#define switch_string_t(v) \
{string_t _string_t_tchk, _ADT_v=(v); \
switch(((intptr_t)(_ADT_v)&7)) {{{

string_t string(c_string v0);
struct _ADT_string_t_string {
    c_string f0;};
#define if_string(v, v0) \
{string_t _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==0) {\
c_string v0=((struct _ADT_string_t_string*)((intptr_t)_ADT_v-0))->f0; 
#define else_if_string(v0) \
} else if (((intptr_t)(_ADT_v)&7)==0) {\
c_string v0=((struct _ADT_string_t_string*)((intptr_t)_ADT_v-0))->f0; 
#define if_string_ptr(v, v0) \
{string_t _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==0) {\
c_string *v0=&((struct _ADT_string_t_string*)((intptr_t)_ADT_v-0))->f0; 
#define case_string(v0) \
break;}} case 0: {{string_t _SW_tchk=_string_t_tchk;}{char _string_t_tchk; \
c_string v0=((struct _ADT_string_t_string*)((intptr_t)_ADT_v-0))->f0; 
#define case_string_ptr(v0) \
break;}} case 0: {{string_t _SW_tchk=_string_t_tchk;}{char _string_t_tchk; \
c_string *v0=&((struct _ADT_string_t_string*)((intptr_t)_ADT_v-0))->f0; 

/***************************/
typedef struct _ADT_stringlist_t{} *stringlist_t;
void free_stringlist_t(stringlist_t v);
#define switch_stringlist_t(v) \
{stringlist_t _stringlist_t_tchk, _ADT_v=(v); \
switch(((intptr_t)(_ADT_v)&7)) {{{

stringlist_t nil();
struct _ADT_stringlist_t_nil {};
#define if_nil(v) \
{stringlist_t _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==0) {
#define else_if_nil() \
} else if (((intptr_t)(_ADT_v)&7)==0) {
#define if_nil_ptr(v) \
{stringlist_t _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==0) {
#define case_nil() \
break;}} case 0: {{stringlist_t _SW_tchk=_stringlist_t_tchk;}{char _stringlist_t_tchk; 
#define case_nil_ptr() \
break;}} case 0: {{stringlist_t _SW_tchk=_stringlist_t_tchk;}{char _stringlist_t_tchk; 

stringlist_t nextlist(struct _ADT_string_t* v0, struct _ADT_stringlist_t* v1);
struct _ADT_stringlist_t_nextlist {
    struct _ADT_string_t* f0;
    struct _ADT_stringlist_t* f1;};
#define if_nextlist(v, v0, v1) \
{stringlist_t _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==1) {\
struct _ADT_string_t* v0=((struct _ADT_stringlist_t_nextlist*)((intptr_t)_ADT_v-1))->f0; \
struct _ADT_stringlist_t* v1=((struct _ADT_stringlist_t_nextlist*)((intptr_t)_ADT_v-1))->f1; 
#define else_if_nextlist(v0, v1) \
} else if (((intptr_t)(_ADT_v)&7)==1) {\
struct _ADT_string_t* v0=((struct _ADT_stringlist_t_nextlist*)((intptr_t)_ADT_v-1))->f0; \
struct _ADT_stringlist_t* v1=((struct _ADT_stringlist_t_nextlist*)((intptr_t)_ADT_v-1))->f1; 
#define if_nextlist_ptr(v, v0, v1) \
{stringlist_t _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==1) {\
struct _ADT_string_t* *v0=&((struct _ADT_stringlist_t_nextlist*)((intptr_t)_ADT_v-1))->f0; \
struct _ADT_stringlist_t* *v1=&((struct _ADT_stringlist_t_nextlist*)((intptr_t)_ADT_v-1))->f1; 
#define case_nextlist(v0, v1) \
break;}} case 1: {{stringlist_t _SW_tchk=_stringlist_t_tchk;}{char _stringlist_t_tchk; \
struct _ADT_string_t* v0=((struct _ADT_stringlist_t_nextlist*)((intptr_t)_ADT_v-1))->f0; \
struct _ADT_stringlist_t* v1=((struct _ADT_stringlist_t_nextlist*)((intptr_t)_ADT_v-1))->f1; 
#define case_nextlist_ptr(v0, v1) \
break;}} case 1: {{stringlist_t _SW_tchk=_stringlist_t_tchk;}{char _stringlist_t_tchk; \
struct _ADT_string_t* *v0=&((struct _ADT_stringlist_t_nextlist*)((intptr_t)_ADT_v-1))->f0; \
struct _ADT_stringlist_t* *v1=&((struct _ADT_stringlist_t_nextlist*)((intptr_t)_ADT_v-1))->f1; 

/***************************/
typedef struct _ADT_arg_t{} *arg_t;
void free_arg_t(arg_t v);
#define switch_arg_t(v) \
{arg_t _arg_t_tchk, _ADT_v=(v); \
switch(((intptr_t)(_ADT_v)&7)) {{{

arg_t arg(struct _ADT_string_t* v0);
struct _ADT_arg_t_arg {
    struct _ADT_string_t* f0;};
#define if_arg(v, v0) \
{arg_t _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==0) {\
struct _ADT_string_t* v0=((struct _ADT_arg_t_arg*)((intptr_t)_ADT_v-0))->f0; 
#define else_if_arg(v0) \
} else if (((intptr_t)(_ADT_v)&7)==0) {\
struct _ADT_string_t* v0=((struct _ADT_arg_t_arg*)((intptr_t)_ADT_v-0))->f0; 
#define if_arg_ptr(v, v0) \
{arg_t _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==0) {\
struct _ADT_string_t* *v0=&((struct _ADT_arg_t_arg*)((intptr_t)_ADT_v-0))->f0; 
#define case_arg(v0) \
break;}} case 0: {{arg_t _SW_tchk=_arg_t_tchk;}{char _arg_t_tchk; \
struct _ADT_string_t* v0=((struct _ADT_arg_t_arg*)((intptr_t)_ADT_v-0))->f0; 
#define case_arg_ptr(v0) \
break;}} case 0: {{arg_t _SW_tchk=_arg_t_tchk;}{char _arg_t_tchk; \
struct _ADT_string_t* *v0=&((struct _ADT_arg_t_arg*)((intptr_t)_ADT_v-0))->f0; 

/***************************/
typedef struct _ADT_arglist_t{} *arglist_t;
void free_arglist_t(arglist_t v);
#define switch_arglist_t(v) \
{arglist_t _arglist_t_tchk, _ADT_v=(v); \
switch(((intptr_t)(_ADT_v)&7)) {{{

arglist_t noarg();
struct _ADT_arglist_t_noarg {};
#define if_noarg(v) \
{arglist_t _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==0) {
#define else_if_noarg() \
} else if (((intptr_t)(_ADT_v)&7)==0) {
#define if_noarg_ptr(v) \
{arglist_t _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==0) {
#define case_noarg() \
break;}} case 0: {{arglist_t _SW_tchk=_arglist_t_tchk;}{char _arglist_t_tchk; 
#define case_noarg_ptr() \
break;}} case 0: {{arglist_t _SW_tchk=_arglist_t_tchk;}{char _arglist_t_tchk; 

arglist_t nextarg(struct _ADT_arg_t* v0, struct _ADT_arglist_t* v1);
struct _ADT_arglist_t_nextarg {
    struct _ADT_arg_t* f0;
    struct _ADT_arglist_t* f1;};
#define if_nextarg(v, v0, v1) \
{arglist_t _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==1) {\
struct _ADT_arg_t* v0=((struct _ADT_arglist_t_nextarg*)((intptr_t)_ADT_v-1))->f0; \
struct _ADT_arglist_t* v1=((struct _ADT_arglist_t_nextarg*)((intptr_t)_ADT_v-1))->f1; 
#define else_if_nextarg(v0, v1) \
} else if (((intptr_t)(_ADT_v)&7)==1) {\
struct _ADT_arg_t* v0=((struct _ADT_arglist_t_nextarg*)((intptr_t)_ADT_v-1))->f0; \
struct _ADT_arglist_t* v1=((struct _ADT_arglist_t_nextarg*)((intptr_t)_ADT_v-1))->f1; 
#define if_nextarg_ptr(v, v0, v1) \
{arglist_t _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==1) {\
struct _ADT_arg_t* *v0=&((struct _ADT_arglist_t_nextarg*)((intptr_t)_ADT_v-1))->f0; \
struct _ADT_arglist_t* *v1=&((struct _ADT_arglist_t_nextarg*)((intptr_t)_ADT_v-1))->f1; 
#define case_nextarg(v0, v1) \
break;}} case 1: {{arglist_t _SW_tchk=_arglist_t_tchk;}{char _arglist_t_tchk; \
struct _ADT_arg_t* v0=((struct _ADT_arglist_t_nextarg*)((intptr_t)_ADT_v-1))->f0; \
struct _ADT_arglist_t* v1=((struct _ADT_arglist_t_nextarg*)((intptr_t)_ADT_v-1))->f1; 
#define case_nextarg_ptr(v0, v1) \
break;}} case 1: {{arglist_t _SW_tchk=_arglist_t_tchk;}{char _arglist_t_tchk; \
struct _ADT_arg_t* *v0=&((struct _ADT_arglist_t_nextarg*)((intptr_t)_ADT_v-1))->f0; \
struct _ADT_arglist_t* *v1=&((struct _ADT_arglist_t_nextarg*)((intptr_t)_ADT_v-1))->f1; 

/***************************/
typedef struct _ADT_ctr_t{} *ctr_t;
void free_ctr_t(ctr_t v);
#define switch_ctr_t(v) \
{ctr_t _ctr_t_tchk, _ADT_v=(v); \
switch(((intptr_t)(_ADT_v)&7)) {{{

ctr_t ctr(struct _ADT_string_t* v0, struct _ADT_arglist_t* v1);
struct _ADT_ctr_t_ctr {
    struct _ADT_string_t* f0;
    struct _ADT_arglist_t* f1;};
#define if_ctr(v, v0, v1) \
{ctr_t _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==0) {\
struct _ADT_string_t* v0=((struct _ADT_ctr_t_ctr*)((intptr_t)_ADT_v-0))->f0; \
struct _ADT_arglist_t* v1=((struct _ADT_ctr_t_ctr*)((intptr_t)_ADT_v-0))->f1; 
#define else_if_ctr(v0, v1) \
} else if (((intptr_t)(_ADT_v)&7)==0) {\
struct _ADT_string_t* v0=((struct _ADT_ctr_t_ctr*)((intptr_t)_ADT_v-0))->f0; \
struct _ADT_arglist_t* v1=((struct _ADT_ctr_t_ctr*)((intptr_t)_ADT_v-0))->f1; 
#define if_ctr_ptr(v, v0, v1) \
{ctr_t _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==0) {\
struct _ADT_string_t* *v0=&((struct _ADT_ctr_t_ctr*)((intptr_t)_ADT_v-0))->f0; \
struct _ADT_arglist_t* *v1=&((struct _ADT_ctr_t_ctr*)((intptr_t)_ADT_v-0))->f1; 
#define case_ctr(v0, v1) \
break;}} case 0: {{ctr_t _SW_tchk=_ctr_t_tchk;}{char _ctr_t_tchk; \
struct _ADT_string_t* v0=((struct _ADT_ctr_t_ctr*)((intptr_t)_ADT_v-0))->f0; \
struct _ADT_arglist_t* v1=((struct _ADT_ctr_t_ctr*)((intptr_t)_ADT_v-0))->f1; 
#define case_ctr_ptr(v0, v1) \
break;}} case 0: {{ctr_t _SW_tchk=_ctr_t_tchk;}{char _ctr_t_tchk; \
struct _ADT_string_t* *v0=&((struct _ADT_ctr_t_ctr*)((intptr_t)_ADT_v-0))->f0; \
struct _ADT_arglist_t* *v1=&((struct _ADT_ctr_t_ctr*)((intptr_t)_ADT_v-0))->f1; 

/***************************/
typedef struct _ADT_ctrlist_t{} *ctrlist_t;
void free_ctrlist_t(ctrlist_t v);
#define switch_ctrlist_t(v) \
{ctrlist_t _ctrlist_t_tchk, _ADT_v=(v); \
switch(((intptr_t)(_ADT_v)&7)) {{{

ctrlist_t noctr();
struct _ADT_ctrlist_t_noctr {};
#define if_noctr(v) \
{ctrlist_t _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==0) {
#define else_if_noctr() \
} else if (((intptr_t)(_ADT_v)&7)==0) {
#define if_noctr_ptr(v) \
{ctrlist_t _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==0) {
#define case_noctr() \
break;}} case 0: {{ctrlist_t _SW_tchk=_ctrlist_t_tchk;}{char _ctrlist_t_tchk; 
#define case_noctr_ptr() \
break;}} case 0: {{ctrlist_t _SW_tchk=_ctrlist_t_tchk;}{char _ctrlist_t_tchk; 

ctrlist_t nextctr(struct _ADT_ctr_t* v0, struct _ADT_ctrlist_t* v1);
struct _ADT_ctrlist_t_nextctr {
    struct _ADT_ctr_t* f0;
    struct _ADT_ctrlist_t* f1;};
#define if_nextctr(v, v0, v1) \
{ctrlist_t _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==1) {\
struct _ADT_ctr_t* v0=((struct _ADT_ctrlist_t_nextctr*)((intptr_t)_ADT_v-1))->f0; \
struct _ADT_ctrlist_t* v1=((struct _ADT_ctrlist_t_nextctr*)((intptr_t)_ADT_v-1))->f1; 
#define else_if_nextctr(v0, v1) \
} else if (((intptr_t)(_ADT_v)&7)==1) {\
struct _ADT_ctr_t* v0=((struct _ADT_ctrlist_t_nextctr*)((intptr_t)_ADT_v-1))->f0; \
struct _ADT_ctrlist_t* v1=((struct _ADT_ctrlist_t_nextctr*)((intptr_t)_ADT_v-1))->f1; 
#define if_nextctr_ptr(v, v0, v1) \
{ctrlist_t _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==1) {\
struct _ADT_ctr_t* *v0=&((struct _ADT_ctrlist_t_nextctr*)((intptr_t)_ADT_v-1))->f0; \
struct _ADT_ctrlist_t* *v1=&((struct _ADT_ctrlist_t_nextctr*)((intptr_t)_ADT_v-1))->f1; 
#define case_nextctr(v0, v1) \
break;}} case 1: {{ctrlist_t _SW_tchk=_ctrlist_t_tchk;}{char _ctrlist_t_tchk; \
struct _ADT_ctr_t* v0=((struct _ADT_ctrlist_t_nextctr*)((intptr_t)_ADT_v-1))->f0; \
struct _ADT_ctrlist_t* v1=((struct _ADT_ctrlist_t_nextctr*)((intptr_t)_ADT_v-1))->f1; 
#define case_nextctr_ptr(v0, v1) \
break;}} case 1: {{ctrlist_t _SW_tchk=_ctrlist_t_tchk;}{char _ctrlist_t_tchk; \
struct _ADT_ctr_t* *v0=&((struct _ADT_ctrlist_t_nextctr*)((intptr_t)_ADT_v-1))->f0; \
struct _ADT_ctrlist_t* *v1=&((struct _ADT_ctrlist_t_nextctr*)((intptr_t)_ADT_v-1))->f1; 

/***************************/
typedef struct _ADT_decl_t{} *decl_t;
void free_decl_t(decl_t v);
#define switch_decl_t(v) \
{decl_t _decl_t_tchk, _ADT_v=(v); \
switch(((intptr_t)(_ADT_v)&7)) {{{

decl_t decl(struct _ADT_string_t* v0, struct _ADT_ctrlist_t* v1);
struct _ADT_decl_t_decl {
    struct _ADT_string_t* f0;
    struct _ADT_ctrlist_t* f1;};
#define if_decl(v, v0, v1) \
{decl_t _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==0) {\
struct _ADT_string_t* v0=((struct _ADT_decl_t_decl*)((intptr_t)_ADT_v-0))->f0; \
struct _ADT_ctrlist_t* v1=((struct _ADT_decl_t_decl*)((intptr_t)_ADT_v-0))->f1; 
#define else_if_decl(v0, v1) \
} else if (((intptr_t)(_ADT_v)&7)==0) {\
struct _ADT_string_t* v0=((struct _ADT_decl_t_decl*)((intptr_t)_ADT_v-0))->f0; \
struct _ADT_ctrlist_t* v1=((struct _ADT_decl_t_decl*)((intptr_t)_ADT_v-0))->f1; 
#define if_decl_ptr(v, v0, v1) \
{decl_t _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==0) {\
struct _ADT_string_t* *v0=&((struct _ADT_decl_t_decl*)((intptr_t)_ADT_v-0))->f0; \
struct _ADT_ctrlist_t* *v1=&((struct _ADT_decl_t_decl*)((intptr_t)_ADT_v-0))->f1; 
#define case_decl(v0, v1) \
break;}} case 0: {{decl_t _SW_tchk=_decl_t_tchk;}{char _decl_t_tchk; \
struct _ADT_string_t* v0=((struct _ADT_decl_t_decl*)((intptr_t)_ADT_v-0))->f0; \
struct _ADT_ctrlist_t* v1=((struct _ADT_decl_t_decl*)((intptr_t)_ADT_v-0))->f1; 
#define case_decl_ptr(v0, v1) \
break;}} case 0: {{decl_t _SW_tchk=_decl_t_tchk;}{char _decl_t_tchk; \
struct _ADT_string_t* *v0=&((struct _ADT_decl_t_decl*)((intptr_t)_ADT_v-0))->f0; \
struct _ADT_ctrlist_t* *v1=&((struct _ADT_decl_t_decl*)((intptr_t)_ADT_v-0))->f1; 

/***************************/
typedef struct _ADT_decllist_t{} *decllist_t;
void free_decllist_t(decllist_t v);
#define switch_decllist_t(v) \
{decllist_t _decllist_t_tchk, _ADT_v=(v); \
switch(((intptr_t)(_ADT_v)&7)) {{{

decllist_t nodecl();
struct _ADT_decllist_t_nodecl {};
#define if_nodecl(v) \
{decllist_t _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==0) {
#define else_if_nodecl() \
} else if (((intptr_t)(_ADT_v)&7)==0) {
#define if_nodecl_ptr(v) \
{decllist_t _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==0) {
#define case_nodecl() \
break;}} case 0: {{decllist_t _SW_tchk=_decllist_t_tchk;}{char _decllist_t_tchk; 
#define case_nodecl_ptr() \
break;}} case 0: {{decllist_t _SW_tchk=_decllist_t_tchk;}{char _decllist_t_tchk; 

decllist_t nextdecl(struct _ADT_decl_t* v0, struct _ADT_decllist_t* v1);
struct _ADT_decllist_t_nextdecl {
    struct _ADT_decl_t* f0;
    struct _ADT_decllist_t* f1;};
#define if_nextdecl(v, v0, v1) \
{decllist_t _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==1) {\
struct _ADT_decl_t* v0=((struct _ADT_decllist_t_nextdecl*)((intptr_t)_ADT_v-1))->f0; \
struct _ADT_decllist_t* v1=((struct _ADT_decllist_t_nextdecl*)((intptr_t)_ADT_v-1))->f1; 
#define else_if_nextdecl(v0, v1) \
} else if (((intptr_t)(_ADT_v)&7)==1) {\
struct _ADT_decl_t* v0=((struct _ADT_decllist_t_nextdecl*)((intptr_t)_ADT_v-1))->f0; \
struct _ADT_decllist_t* v1=((struct _ADT_decllist_t_nextdecl*)((intptr_t)_ADT_v-1))->f1; 
#define if_nextdecl_ptr(v, v0, v1) \
{decllist_t _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==1) {\
struct _ADT_decl_t* *v0=&((struct _ADT_decllist_t_nextdecl*)((intptr_t)_ADT_v-1))->f0; \
struct _ADT_decllist_t* *v1=&((struct _ADT_decllist_t_nextdecl*)((intptr_t)_ADT_v-1))->f1; 
#define case_nextdecl(v0, v1) \
break;}} case 1: {{decllist_t _SW_tchk=_decllist_t_tchk;}{char _decllist_t_tchk; \
struct _ADT_decl_t* v0=((struct _ADT_decllist_t_nextdecl*)((intptr_t)_ADT_v-1))->f0; \
struct _ADT_decllist_t* v1=((struct _ADT_decllist_t_nextdecl*)((intptr_t)_ADT_v-1))->f1; 
#define case_nextdecl_ptr(v0, v1) \
break;}} case 1: {{decllist_t _SW_tchk=_decllist_t_tchk;}{char _decllist_t_tchk; \
struct _ADT_decl_t* *v0=&((struct _ADT_decllist_t_nextdecl*)((intptr_t)_ADT_v-1))->f0; \
struct _ADT_decllist_t* *v1=&((struct _ADT_decllist_t_nextdecl*)((intptr_t)_ADT_v-1))->f1; 
