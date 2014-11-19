#include <stdint.h>
#define end_switch() }}}}
#define default() break;}} default: {{
#define else() } else {
#define end_if() }}
/***************************/
typedef struct _ADT_Long{} *Long;
void free_Long(Long v);
#define switch_Long(v) \
{Long _Long_tchk, _ADT_v=(v); \
switch(((intptr_t)(_ADT_v)&7)) {{{

Long Long_(long v0);
struct _ADT_Long_Long_ {
    long f0;};
#define if_Long_(v, v0) \
{Long _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==0) {\
long v0=((struct _ADT_Long_Long_*)((intptr_t)_ADT_v-0))->f0; 
#define else_if_Long_(v0) \
} else if (((intptr_t)(_ADT_v)&7)==0) {\
long v0=((struct _ADT_Long_Long_*)((intptr_t)_ADT_v-0))->f0; 
#define if_Long__ptr(v, v0) \
{Long _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==0) {\
long *v0=&((struct _ADT_Long_Long_*)((intptr_t)_ADT_v-0))->f0; 
#define case_Long_(v0) \
break;}} case 0: {{Long _SW_tchk=_Long_tchk;}{char _Long_tchk; \
long v0=((struct _ADT_Long_Long_*)((intptr_t)_ADT_v-0))->f0; 
#define case_Long__ptr(v0) \
break;}} case 0: {{Long _SW_tchk=_Long_tchk;}{char _Long_tchk; \
long *v0=&((struct _ADT_Long_Long_*)((intptr_t)_ADT_v-0))->f0; 

/***************************/
typedef struct _ADT_V1{} *V1;
void free_V1(V1 v);
#define switch_V1(v) \
{V1 _V1_tchk, _ADT_v=(v); \
switch(((intptr_t)(_ADT_v)&7)) {{{

/***************************/

typedef struct _ADT_List{} *List; /* List is the pointer of _ADT_List */

void free_List(List v);

#define switch_List(v) \
{List _List_tchk, _ADT_v=(v); \
switch(((intptr_t)(_ADT_v)&7)) {{{

List Nil();
struct _ADT_List_Nil {};
#define if_Nil(v) \
{List _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==0) {
#define else_if_Nil() \
} else if (((intptr_t)(_ADT_v)&7)==0) {
#define if_Nil_ptr(v) \
{List _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==0) {
#define case_Nil() \
break;}} case 0: {{List _SW_tchk=_List_tchk;}{char _List_tchk; 
#define case_Nil_ptr() \
break;}} case 0: {{List _SW_tchk=_List_tchk;}{char _List_tchk; 

List Cons(struct _ADT_V1* v0, struct _ADT_List* v1);
struct _ADT_List_Cons {
    struct _ADT_V1* f0;
    struct _ADT_List* f1;};
#define if_Cons(v, v0, v1) \
{List _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==1) {\
struct _ADT_V1* v0=((struct _ADT_List_Cons*)((intptr_t)_ADT_v-1))->f0; \
struct _ADT_List* v1=((struct _ADT_List_Cons*)((intptr_t)_ADT_v-1))->f1; 
#define else_if_Cons(v0, v1) \
} else if (((intptr_t)(_ADT_v)&7)==1) {\
struct _ADT_V1* v0=((struct _ADT_List_Cons*)((intptr_t)_ADT_v-1))->f0; \
struct _ADT_List* v1=((struct _ADT_List_Cons*)((intptr_t)_ADT_v-1))->f1; 

#define if_Cons_ptr(v, v0, v1) \
{List _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==1) {\
struct _ADT_V1* *v0=&((struct _ADT_List_Cons*)((intptr_t)_ADT_v-1))->f0; \
struct _ADT_List* *v1=&((struct _ADT_List_Cons*)((intptr_t)_ADT_v-1))->f1; 

#define case_Cons(v0, v1) \
break;}} case 1: {{List _SW_tchk=_List_tchk;}{char _List_tchk; \
struct _ADT_V1* v0=((struct _ADT_List_Cons*)((intptr_t)_ADT_v-1))->f0; \
struct _ADT_List* v1=((struct _ADT_List_Cons*)((intptr_t)_ADT_v-1))->f1; 

#define case_Cons_ptr(v0, v1) \
break;}} case 1: {{List _SW_tchk=_List_tchk;}{char _List_tchk; \
struct _ADT_V1* *v0=&((struct _ADT_List_Cons*)((intptr_t)_ADT_v-1))->f0; \
struct _ADT_List* *v1=&((struct _ADT_List_Cons*)((intptr_t)_ADT_v-1))->f1; 

/***************************/
typedef struct _ADT_List_Long{} *List_Long;
void free_List_Long(List_Long v);
#define switch_List_Long(v) \
{List_Long _List_Long_tchk, _ADT_v=(v); \
switch(((intptr_t)(_ADT_v)&7)) {{{

List_Long Nil_Long();
struct _ADT_List_Long_Nil_Long {};
#define if_Nil_Long(v) \
{List_Long _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==0) {
#define else_if_Nil_Long() \
} else if (((intptr_t)(_ADT_v)&7)==0) {
#define if_Nil_Long_ptr(v) \
{List_Long _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==0) {
#define case_Nil_Long() \
break;}} case 0: {{List_Long _SW_tchk=_List_Long_tchk;}{char _List_Long_tchk; 
#define case_Nil_Long_ptr() \
break;}} case 0: {{List_Long _SW_tchk=_List_Long_tchk;}{char _List_Long_tchk; 

List_Long Cons_Long(struct _ADT_Long* v0, struct _ADT_List_Long* v1);
struct _ADT_List_Long_Cons_Long {
    struct _ADT_Long* f0;
    struct _ADT_List_Long* f1;};
#define if_Cons_Long(v, v0, v1) \
{List_Long _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==1) {\
struct _ADT_Long* v0=((struct _ADT_List_Long_Cons_Long*)((intptr_t)_ADT_v-1))->f0; \
struct _ADT_List_Long* v1=((struct _ADT_List_Long_Cons_Long*)((intptr_t)_ADT_v-1))->f1; 
#define else_if_Cons_Long(v0, v1) \
} else if (((intptr_t)(_ADT_v)&7)==1) {\
struct _ADT_Long* v0=((struct _ADT_List_Long_Cons_Long*)((intptr_t)_ADT_v-1))->f0; \
struct _ADT_List_Long* v1=((struct _ADT_List_Long_Cons_Long*)((intptr_t)_ADT_v-1))->f1; 
#define if_Cons_Long_ptr(v, v0, v1) \
{List_Long _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==1) {\
struct _ADT_Long* *v0=&((struct _ADT_List_Long_Cons_Long*)((intptr_t)_ADT_v-1))->f0; \
struct _ADT_List_Long* *v1=&((struct _ADT_List_Long_Cons_Long*)((intptr_t)_ADT_v-1))->f1; 
#define case_Cons_Long(v0, v1) \
break;}} case 1: {{List_Long _SW_tchk=_List_Long_tchk;}{char _List_Long_tchk; \
struct _ADT_Long* v0=((struct _ADT_List_Long_Cons_Long*)((intptr_t)_ADT_v-1))->f0; \
struct _ADT_List_Long* v1=((struct _ADT_List_Long_Cons_Long*)((intptr_t)_ADT_v-1))->f1; 
#define case_Cons_Long_ptr(v0, v1) \
break;}} case 1: {{List_Long _SW_tchk=_List_Long_tchk;}{char _List_Long_tchk; \
struct _ADT_Long* *v0=&((struct _ADT_List_Long_Cons_Long*)((intptr_t)_ADT_v-1))->f0; \
struct _ADT_List_Long* *v1=&((struct _ADT_List_Long_Cons_Long*)((intptr_t)_ADT_v-1))->f1; 

/***************************/
typedef struct _ADT_ListList{} *ListList; // just define the type

//typedef struct abc{
//	int a;
//	int b;
//	int c;
//} *abc;
typedef struct _ADT_List1{} *List1;

void free_ListList(ListList v);//?
#define switch_ListList(v) \
{ListList _ListList_tchk, _ADT_v=(v); \
switch(((intptr_t)(_ADT_v)&7)) {{{

ListList Nil_ListList();
struct _ADT_ListList_Nil_ListList {};
#define if_Nil_ListList(v) \
{ListList _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==0) {
#define else_if_Nil_ListList() \
} else if (((intptr_t)(_ADT_v)&7)==0) {
#define if_Nil_ListList_ptr(v) \
{ListList _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==0) {
#define case_Nil_ListList() \
break;}} case 0: {{ListList _SW_tchk=_ListList_tchk;}{char _ListList_tchk; 
#define case_Nil_ListList_ptr() \
break;}} case 0: {{ListList _SW_tchk=_ListList_tchk;}{char _ListList_tchk; 

ListList Cons_ListList(struct _ADT_List_Long* v0, struct _ADT_ListList* v1);
struct _ADT_ListList_Cons_ListList {
    struct _ADT_List_Long* f0;
    struct _ADT_ListList* f1;};
#define if_Cons_ListList(v, v0, v1) \
{ListList _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==1) {\
struct _ADT_List_Long* v0=((struct _ADT_ListList_Cons_ListList*)((intptr_t)_ADT_v-1))->f0; \
struct _ADT_ListList* v1=((struct _ADT_ListList_Cons_ListList*)((intptr_t)_ADT_v-1))->f1; 
#define else_if_Cons_ListList(v0, v1) \
} else if (((intptr_t)(_ADT_v)&7)==1) {\
struct _ADT_List_Long* v0=((struct _ADT_ListList_Cons_ListList*)((intptr_t)_ADT_v-1))->f0; \
struct _ADT_ListList* v1=((struct _ADT_ListList_Cons_ListList*)((intptr_t)_ADT_v-1))->f1; 
#define if_Cons_ListList_ptr(v, v0, v1) \
{ListList _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==1) {\
struct _ADT_List_Long* *v0=&((struct _ADT_ListList_Cons_ListList*)((intptr_t)_ADT_v-1))->f0; \
struct _ADT_ListList* *v1=&((struct _ADT_ListList_Cons_ListList*)((intptr_t)_ADT_v-1))->f1; 
#define case_Cons_ListList(v0, v1) \
break;}} case 1: {{ListList _SW_tchk=_ListList_tchk;}{char _ListList_tchk; \
struct _ADT_List_Long* v0=((struct _ADT_ListList_Cons_ListList*)((intptr_t)_ADT_v-1))->f0; \
struct _ADT_ListList* v1=((struct _ADT_ListList_Cons_ListList*)((intptr_t)_ADT_v-1))->f1; 
#define case_Cons_ListList_ptr(v0, v1) \
break;}} case 1: {{ListList _SW_tchk=_ListList_tchk;}{char _ListList_tchk; \
struct _ADT_List_Long* *v0=&((struct _ADT_ListList_Cons_ListList*)((intptr_t)_ADT_v-1))->f0; \
struct _ADT_ListList* *v1=&((struct _ADT_ListList_Cons_ListList*)((intptr_t)_ADT_v-1))->f1; 

/***************************/
typedef struct _ADT_List_4char{} *List_4char;
void free_List_4char(List_4char v);
#define switch_List_4char(v) \
{List_4char _List_4char_tchk, _ADT_v=(v); \
switch(((intptr_t)(_ADT_v)&7)) {{{

List_4char Nil_4char();
struct _ADT_List_4char_Nil_4char {};
#define if_Nil_4char(v) \
{List_4char _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==0) {
#define else_if_Nil_4char() \
} else if (((intptr_t)(_ADT_v)&7)==0) {
#define if_Nil_4char_ptr(v) \
{List_4char _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==0) {
#define case_Nil_4char() \
break;}} case 0: {{List_4char _SW_tchk=_List_4char_tchk;}{char _List_4char_tchk; 
#define case_Nil_4char_ptr() \
break;}} case 0: {{List_4char _SW_tchk=_List_4char_tchk;}{char _List_4char_tchk; 

List_4char Cons_4char(char v0, char v1, char v2, char v3, struct _ADT_List_4char* v4);
struct _ADT_List_4char_Cons_4char {
    char f0;
    char f1;
    char f2;
    char f3;
    struct _ADT_List_4char* f4;};
#define if_Cons_4char(v, v0, v1, v2, v3, v4) \
{List_4char _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==1) {\
char v0=((struct _ADT_List_4char_Cons_4char*)((intptr_t)_ADT_v-1))->f0; \
char v1=((struct _ADT_List_4char_Cons_4char*)((intptr_t)_ADT_v-1))->f1; \
char v2=((struct _ADT_List_4char_Cons_4char*)((intptr_t)_ADT_v-1))->f2; \
char v3=((struct _ADT_List_4char_Cons_4char*)((intptr_t)_ADT_v-1))->f3; \
struct _ADT_List_4char* v4=((struct _ADT_List_4char_Cons_4char*)((intptr_t)_ADT_v-1))->f4; 
#define else_if_Cons_4char(v0, v1, v2, v3, v4) \
} else if (((intptr_t)(_ADT_v)&7)==1) {\
char v0=((struct _ADT_List_4char_Cons_4char*)((intptr_t)_ADT_v-1))->f0; \
char v1=((struct _ADT_List_4char_Cons_4char*)((intptr_t)_ADT_v-1))->f1; \
char v2=((struct _ADT_List_4char_Cons_4char*)((intptr_t)_ADT_v-1))->f2; \
char v3=((struct _ADT_List_4char_Cons_4char*)((intptr_t)_ADT_v-1))->f3; \
struct _ADT_List_4char* v4=((struct _ADT_List_4char_Cons_4char*)((intptr_t)_ADT_v-1))->f4; 
#define if_Cons_4char_ptr(v, v0, v1, v2, v3, v4) \
{List_4char _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==1) {\
char *v0=&((struct _ADT_List_4char_Cons_4char*)((intptr_t)_ADT_v-1))->f0; \
char *v1=&((struct _ADT_List_4char_Cons_4char*)((intptr_t)_ADT_v-1))->f1; \
char *v2=&((struct _ADT_List_4char_Cons_4char*)((intptr_t)_ADT_v-1))->f2; \
char *v3=&((struct _ADT_List_4char_Cons_4char*)((intptr_t)_ADT_v-1))->f3; \
struct _ADT_List_4char* *v4=&((struct _ADT_List_4char_Cons_4char*)((intptr_t)_ADT_v-1))->f4; 
#define case_Cons_4char(v0, v1, v2, v3, v4) \
break;}} case 1: {{List_4char _SW_tchk=_List_4char_tchk;}{char _List_4char_tchk; \
char v0=((struct _ADT_List_4char_Cons_4char*)((intptr_t)_ADT_v-1))->f0; \
char v1=((struct _ADT_List_4char_Cons_4char*)((intptr_t)_ADT_v-1))->f1; \
char v2=((struct _ADT_List_4char_Cons_4char*)((intptr_t)_ADT_v-1))->f2; \
char v3=((struct _ADT_List_4char_Cons_4char*)((intptr_t)_ADT_v-1))->f3; \
struct _ADT_List_4char* v4=((struct _ADT_List_4char_Cons_4char*)((intptr_t)_ADT_v-1))->f4; 
#define case_Cons_4char_ptr(v0, v1, v2, v3, v4) \
break;}} case 1: {{List_4char _SW_tchk=_List_4char_tchk;}{char _List_4char_tchk; \
char *v0=&((struct _ADT_List_4char_Cons_4char*)((intptr_t)_ADT_v-1))->f0; \
char *v1=&((struct _ADT_List_4char_Cons_4char*)((intptr_t)_ADT_v-1))->f1; \
char *v2=&((struct _ADT_List_4char_Cons_4char*)((intptr_t)_ADT_v-1))->f2; \
char *v3=&((struct _ADT_List_4char_Cons_4char*)((intptr_t)_ADT_v-1))->f3; \
struct _ADT_List_4char* *v4=&((struct _ADT_List_4char_Cons_4char*)((intptr_t)_ADT_v-1))->f4; 

/***************************/
typedef struct _ADT_Cord_int{} *Cord_int;
void free_Cord_int(Cord_int v);
#define switch_Cord_int(v) \
{Cord_int _Cord_int_tchk, _ADT_v=(v); \
switch(((intptr_t)(_ADT_v)&7)) {{{

Cord_int Empty();
struct _ADT_Cord_int_Empty {};
#define if_Empty(v) \
{Cord_int _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==0) {
#define else_if_Empty() \
} else if (((intptr_t)(_ADT_v)&7)==0) {
#define if_Empty_ptr(v) \
{Cord_int _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==0) {
#define case_Empty() \
break;}} case 0: {{Cord_int _SW_tchk=_Cord_int_tchk;}{char _Cord_int_tchk; 
#define case_Empty_ptr() \
break;}} case 0: {{Cord_int _SW_tchk=_Cord_int_tchk;}{char _Cord_int_tchk; 

Cord_int Leaf(int v0);
struct _ADT_Cord_int_Leaf {
    int f0;
};
#define if_Leaf(v, v0) \
{Cord_int _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==1) {\
int v0=((struct _ADT_Cord_int_Leaf*)((intptr_t)_ADT_v-1))->f0; 
#define else_if_Leaf(v0) \
} else if (((intptr_t)(_ADT_v)&7)==1) {\
int v0=((struct _ADT_Cord_int_Leaf*)((intptr_t)_ADT_v-1))->f0; 
#define if_Leaf_ptr(v, v0) \
{Cord_int _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==1) {\
int *v0=&((struct _ADT_Cord_int_Leaf*)((intptr_t)_ADT_v-1))->f0; 
#define case_Leaf(v0) \
break;}} case 1: {{Cord_int _SW_tchk=_Cord_int_tchk;}{char _Cord_int_tchk; \
int v0=((struct _ADT_Cord_int_Leaf*)((intptr_t)_ADT_v-1))->f0; 
#define case_Leaf_ptr(v0) \
break;}} case 1: {{Cord_int _SW_tchk=_Cord_int_tchk;}{char _Cord_int_tchk; \
int *v0=&((struct _ADT_Cord_int_Leaf*)((intptr_t)_ADT_v-1))->f0; 

Cord_int Branch(struct _ADT_Cord_int* v0, struct _ADT_Cord_int* v1);
struct _ADT_Cord_int_Branch {
    struct _ADT_Cord_int* f0;
    struct _ADT_Cord_int* f1;};
#define if_Branch(v, v0, v1) \
{Cord_int _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==2) {\
struct _ADT_Cord_int* v0=((struct _ADT_Cord_int_Branch*)((intptr_t)_ADT_v-2))->f0; \
struct _ADT_Cord_int* v1=((struct _ADT_Cord_int_Branch*)((intptr_t)_ADT_v-2))->f1; 
#define else_if_Branch(v0, v1) \
} else if (((intptr_t)(_ADT_v)&7)==2) {\
struct _ADT_Cord_int* v0=((struct _ADT_Cord_int_Branch*)((intptr_t)_ADT_v-2))->f0; \
struct _ADT_Cord_int* v1=((struct _ADT_Cord_int_Branch*)((intptr_t)_ADT_v-2))->f1; 
#define if_Branch_ptr(v, v0, v1) \
{Cord_int _ADT_v=(v);if (((intptr_t)(_ADT_v)&7)==2) {\
struct _ADT_Cord_int* *v0=&((struct _ADT_Cord_int_Branch*)((intptr_t)_ADT_v-2))->f0; \
struct _ADT_Cord_int* *v1=&((struct _ADT_Cord_int_Branch*)((intptr_t)_ADT_v-2))->f1; 
#define case_Branch(v0, v1) \
break;}} case 2: {{Cord_int _SW_tchk=_Cord_int_tchk;}{char _Cord_int_tchk; \
struct _ADT_Cord_int* v0=((struct _ADT_Cord_int_Branch*)((intptr_t)_ADT_v-2))->f0; \
struct _ADT_Cord_int* v1=((struct _ADT_Cord_int_Branch*)((intptr_t)_ADT_v-2))->f1; 
#define case_Branch_ptr(v0, v1) \
break;}} case 2: {{Cord_int _SW_tchk=_Cord_int_tchk;}{char _Cord_int_tchk; \
struct _ADT_Cord_int* *v0=&((struct _ADT_Cord_int_Branch*)((intptr_t)_ADT_v-2))->f0; \
struct _ADT_Cord_int* *v1=&((struct _ADT_Cord_int_Branch*)((intptr_t)_ADT_v-2))->f1; 


#define while_Cons(v, v0, v1, t) \
{List _ADT_v; \
struct _ADT_V1* v0; \
struct _ADT_List* v1; \
while ((_ADT_v=(v),((intptr_t)(_ADT_v)&7)==1) && \
(v0=((struct _ADT_List_Cons*)((intptr_t)_ADT_v-1))->f0, \
v1=((struct _ADT_List_Cons*)((intptr_t)_ADT_v-1))->f1, \
t)) {\


//construct the new type of cons
#define new_Cons(consp, headp, tailp) \
{\
struct _ADT_consp* cp;\
struct _ADT_headp* hp;\
struct _ADT_tailp* tp;\
cp = &consp,hp = &headp, tp = &tailp\
}\
//---------------------For List-------------------------------------------------
//define an ADT list
struct ADTList{
	void *_ADT_Value;
	struct _ADT_List *next;
};
typedef struct ADTList ADTList;

void* ADTHead(ADTList *adtlist){
	return adtlist->_ADT_Value;
}

ADTList* ADTTail(ADTList *adtlist){
	return adtlist->next;
}
#define New_List1(type, value, next) \
struct ADTList1{\
	(type)* V1 = value;\
	ADTList1* tail = &next;}\

#define New_List(type, value, next) \
assign_list(value,next);\

ADTList* assign_list(void* value, ADTList* next)
{
	ADTList *list1;\
	list1->_ADT_Value  = value;
	list1->next = next;
	return list1;
}

//------------------------------------------------------------------------------


//define cons for cons and nil
typedef enum {Consx,Nilx} Cons_tag;
typedef struct _ADT_cons{
	Cons_tag c_tag;

};
#define Nil struct _ADT_nil;
struct _ADT_Cons_int {
    struct _ADT_Cons_int* f0;
    struct _ADT_Cons_int* f1;};
