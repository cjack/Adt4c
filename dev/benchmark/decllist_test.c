#include"decllist_test.h"
#include <stdlib.h>

/******************************************************************************/
void free_string_t(string_t v){
	free((void*)((uintptr_t)v));
}

string_t string(c_string v0){
	struct _ADT_string_t_string *v=(struct _ADT_string_t_string*)malloc(sizeof(struct _ADT_string_t_string));
	v->f0=v0; 
	return (string_t)(0+(uintptr_t)v);
}


/******************************************************************************/
void free_int_list(int_list v){
	free((void*)((uintptr_t)v));
}

int_list nil(){
	struct _ADT_int_list_nil *v=(struct _ADT_int_list_nil*)0;
	return (int_list)((uintptr_t)v);
}

int_list next_list(int v0, struct _ADT_int_list* v1){
	struct _ADT_int_list_next_list *v=(struct _ADT_int_list_next_list*)malloc(sizeof(struct _ADT_int_list_next_list));
	v->f0=v0; 
	v->f1=v1; 
	return (int_list)(0+(uintptr_t)v);
}
