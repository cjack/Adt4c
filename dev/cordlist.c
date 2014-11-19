#include "cordlist.h"
#include <stdlib.h>
/***************************/
void free_Long(Long v){free((void*)((intptr_t)v&~7));};

Long Long_(long v0){
struct _ADT_Long_Long_ *v=(struct _ADT_Long_Long_*)malloc(sizeof(struct _ADT_Long_Long_));
v->f0=v0; return (Long)(0+(intptr_t)v);
}

/***************************/
void free_V1(V1 v){free((void*)((intptr_t)v&~7));};

/***************************/
void free_List(List v){free((void*)((intptr_t)v&~7));};

List Nil(){
struct _ADT_List_Nil *v=(struct _ADT_List_Nil*)malloc(sizeof(struct _ADT_List_Nil));
return (List)(0+(intptr_t)v);
}

List Cons(struct _ADT_V1* v0, struct _ADT_List* v1){
struct _ADT_List_Cons *v=(struct _ADT_List_Cons*)malloc(sizeof(struct _ADT_List_Cons));
v->f0=v0; v->f1=v1; return (List)(1+(intptr_t)v);
}

/***************************/
void free_List_Long(List_Long v){free((void*)((intptr_t)v&~7));};

List_Long Nil_Long(){
struct _ADT_List_Long_Nil_Long *v=(struct _ADT_List_Long_Nil_Long*)malloc(sizeof(struct _ADT_List_Long_Nil_Long));
return (List_Long)(0+(intptr_t)v);
}

List_Long Cons_Long(struct _ADT_Long* v0, struct _ADT_List_Long* v1){
struct _ADT_List_Long_Cons_Long *v=(struct _ADT_List_Long_Cons_Long*)malloc(sizeof(struct _ADT_List_Long_Cons_Long));
v->f0=v0; v->f1=v1; return (List_Long)(1+(intptr_t)v);
}

/***************************/
void free_ListList(ListList v){free((void*)((intptr_t)v&~7));};

ListList Nil_ListList(){
struct _ADT_ListList_Nil_ListList *v=(struct _ADT_ListList_Nil_ListList*)malloc(sizeof(struct _ADT_ListList_Nil_ListList));
return (ListList)(0+(intptr_t)v);
}

ListList Cons_ListList(struct _ADT_List_Long* v0, struct _ADT_ListList* v1){
struct _ADT_ListList_Cons_ListList *v=(struct _ADT_ListList_Cons_ListList*)malloc(sizeof(struct _ADT_ListList_Cons_ListList));
v->f0=v0; v->f1=v1; return (ListList)(1+(intptr_t)v);
}

/***************************/
void free_List_4char(List_4char v){free((void*)((intptr_t)v&~7));};

List_4char Nil_4char(){
struct _ADT_List_4char_Nil_4char *v=(struct _ADT_List_4char_Nil_4char*)malloc(sizeof(struct _ADT_List_4char_Nil_4char));
return (List_4char)(0+(intptr_t)v);
}

List_4char Cons_4char(char v0, char v1, char v2, char v3, struct _ADT_List_4char* v4){
struct _ADT_List_4char_Cons_4char *v=(struct _ADT_List_4char_Cons_4char*)malloc(sizeof(struct _ADT_List_4char_Cons_4char));
v->f0=v0; v->f1=v1; v->f2=v2; v->f3=v3; v->f4=v4; return (List_4char)(1+(intptr_t)v);
}

/***************************/
void free_Cord_int(Cord_int v){free((void*)((intptr_t)v&~7));};

Cord_int Empty(){
struct _ADT_Cord_int_Empty *v=(struct _ADT_Cord_int_Empty*)malloc(sizeof(struct _ADT_Cord_int_Empty));
return (Cord_int)(0+(intptr_t)v);
}

Cord_int Leaf(int v0){
struct _ADT_Cord_int_Leaf *v=(struct _ADT_Cord_int_Leaf*)malloc(sizeof(struct _ADT_Cord_int_Leaf));
v->f0=v0; return (Cord_int)(1+(intptr_t)v);
}

Cord_int Branch(struct _ADT_Cord_int* v0, struct _ADT_Cord_int* v1){
struct _ADT_Cord_int_Branch *v=(struct _ADT_Cord_int_Branch*)malloc(sizeof(struct _ADT_Cord_int_Branch));
v->f0=v0; v->f1=v1; return (Cord_int)(2+(intptr_t)v);
}

