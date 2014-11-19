#include"adt_t_master.h"
#include <stdlib.h>

/******************************************************************************/
void free_string_t(string_t v){
	free((void*)((intptr_t)v&~7));
}

string_t string(c_string v0){
struct _ADT_string_t_string *v=(struct _ADT_string_t_string*)malloc(sizeof(struct _ADT_string_t_string));
v->f0=v0; return (string_t)(0+(intptr_t)v);
}


/******************************************************************************/
void free_stringlist_t(stringlist_t v){
	free((void*)((intptr_t)v&~7));
}

stringlist_t nil(){
struct _ADT_stringlist_t_nil *v=(struct _ADT_stringlist_t_nil*)malloc(sizeof(struct _ADT_stringlist_t_nil));
return (stringlist_t)(0+(intptr_t)v);
}

stringlist_t nextlist(struct _ADT_string_t* v0, struct _ADT_stringlist_t* v1){
struct _ADT_stringlist_t_nextlist *v=(struct _ADT_stringlist_t_nextlist*)malloc(sizeof(struct _ADT_stringlist_t_nextlist));
v->f0=v0; v->f1=v1; return (stringlist_t)(1+(intptr_t)v);
}


/******************************************************************************/
void free_arg_t(arg_t v){
	free((void*)((intptr_t)v&~7));
}

arg_t arg(struct _ADT_string_t* v0){
struct _ADT_arg_t_arg *v=(struct _ADT_arg_t_arg*)malloc(sizeof(struct _ADT_arg_t_arg));
v->f0=v0; return (arg_t)(0+(intptr_t)v);
}


/******************************************************************************/
void free_arglist_t(arglist_t v){
	free((void*)((intptr_t)v&~7));
}

arglist_t noarg(){
	struct _ADT_arglist_t_noarg *v=
		(struct _ADT_arglist_t_noarg*)malloc(sizeof(struct _ADT_arglist_t_noarg));
	return (arglist_t)(0+(intptr_t)v);
}

arglist_t nextarg(struct _ADT_arg_t* v0, struct _ADT_arglist_t* v1){
struct _ADT_arglist_t_nextarg *v=(struct _ADT_arglist_t_nextarg*)malloc(sizeof(struct _ADT_arglist_t_nextarg));
v->f0=v0; v->f1=v1; return (arglist_t)(1+(intptr_t)v);
}


/******************************************************************************/
void free_ctr_t(ctr_t v){
	free((void*)((intptr_t)v&~7));
}

ctr_t ctr(struct _ADT_string_t* v0, struct _ADT_arglist_t* v1){
struct _ADT_ctr_t_ctr *v=(struct _ADT_ctr_t_ctr*)malloc(sizeof(struct _ADT_ctr_t_ctr));
v->f0=v0; v->f1=v1; return (ctr_t)(0+(intptr_t)v);
}


/******************************************************************************/
void free_ctrlist_t(ctrlist_t v){
	free((void*)((intptr_t)v&~7));
}

ctrlist_t noctr(){
struct _ADT_ctrlist_t_noctr *v=(struct _ADT_ctrlist_t_noctr*)malloc(sizeof(struct _ADT_ctrlist_t_noctr));
return (ctrlist_t)(0+(intptr_t)v);
}

ctrlist_t nextctr(struct _ADT_ctr_t* v0, struct _ADT_ctrlist_t* v1){
struct _ADT_ctrlist_t_nextctr *v=(struct _ADT_ctrlist_t_nextctr*)malloc(sizeof(struct _ADT_ctrlist_t_nextctr));
v->f0=v0; v->f1=v1; return (ctrlist_t)(1+(intptr_t)v);
}


/******************************************************************************/
void free_decl_t(decl_t v){
	free((void*)((intptr_t)v&~7));
}

decl_t decl(struct _ADT_string_t* v0, struct _ADT_ctrlist_t* v1){
struct _ADT_decl_t_decl *v=(struct _ADT_decl_t_decl*)malloc(sizeof(struct _ADT_decl_t_decl));
v->f0=v0; v->f1=v1; return (decl_t)(0+(intptr_t)v);
}


/******************************************************************************/
void free_decllist_t(decllist_t v){
	free((void*)((intptr_t)v&~7));
}

decllist_t nodecl(){
struct _ADT_decllist_t_nodecl *v=(struct _ADT_decllist_t_nodecl*)malloc(sizeof(struct _ADT_decllist_t_nodecl));
return (decllist_t)(0+(intptr_t)v);
}

decllist_t nextdecl(struct _ADT_decl_t* v0, struct _ADT_decllist_t* v1){
struct _ADT_decllist_t_nextdecl *v=(struct _ADT_decllist_t_nextdecl*)malloc(sizeof(struct _ADT_decllist_t_nextdecl));
v->f0=v0; v->f1=v1; return (decllist_t)(1+(intptr_t)v);
}
