// testing macros with code as arguments (++) for preprocessor to
// support algebraic data types in C 

#include<stdlib.h> // malloc
#include<stdio.h>

// check out enum types in more detail...?
// enum {cons, nil} l_et;
// enum l_et xxx; // complains don't know size of xxx

typedef struct l_s *tl;
typedef struct l_nil {} tl_nil;
typedef struct l_cons {int head; tl tail;} tl_cons;
typedef union l_u {tl_nil sn; tl_cons sc;} tl_u;
struct l_s {char ltag; tl_u un;};

// can we make #define/inline version easily using ","?
tl
malloc_nil() {
	tl c = (tl) malloc(sizeof(struct l_s)); // should check ret val
	c->ltag = 0;
	return c;
}

// can we make #define/inline version easily using ","?
tl
malloc_cons(int h, tl t) {
	tl c = (tl) malloc(sizeof(struct l_s)); // should check ret val
	c->ltag = 1;
	c->un.sc.head = h;
	c->un.sc.tail = t;
	return c;
}

#define if_cons(l, h, t, s1, s2) \
	 if (l->ltag == 1) { \
		int h = l->un.sc.head; \
		tl t = l->un.sc.tail; \
		s1} else s2

typedef struct str {int foo;} st;

int
f(int *i){
// 	{st *j = (st *) i;} // optimised away with -O1
// 	{st *j = i;} // type warning (can make it error?)
	return *i+1;
}

struct s1 {int tag; int f; int g;};
struct s2 {int tag; int *f; int g;};
struct s3 {int tag; char f; int *g;};
struct s4 {char tag; char f; int *g;};
struct s5 {char tag; int *f; char g;};

#define foo(S) if (1) {int i = 10; S}
main(){
	struct s1 v1;
	struct s2 v2;
	struct s3 v3;
	struct s4 v4;
	struct s5 v5;
	int i = 10;
	printf("%ld %ld %ld\n", (long)&(v1.tag)-(long)&v1, (long)&(v1.f)-(long)&v1, (long)&(v1.g)-(long)&v1);
	printf("%ld %ld %ld\n", (long)&(v2.tag)-(long)&v2, (long)&(v2.f)-(long)&v2, (long)&(v2.g)-(long)&v2);
	printf("%ld %ld %ld\n", (long)&(v3.tag)-(long)&v3, (long)&(v3.f)-(long)&v3, (long)&(v3.g)-(long)&v3);
	printf("%ld %ld %ld\n", (long)&(v4.tag)-(long)&v4, (long)&(v4.f)-(long)&v4, (long)&(v4.g)-(long)&v4);
	printf("%ld %ld %ld\n", (long)&(v5.tag)-(long)&v5, (long)&(v5.f)-(long)&v5, (long)&(v5.g)-(long)&v5);
// 	for (i=0; i < 17; i++)
// 		printf("Malloc returned %lx\n", (long) malloc(1));
// 	foo(printf("Works\n");printf("Works %d\n",i);)
//	printf("Works %d\n",f(&i));

//  	tl l = malloc_cons(42, malloc_cons(43, malloc_nil()));
//  	if_cons(l, h1, l1,
//  		if_cons(l1, h, t, printf("Works %d\n",h);,;),
//  		;)
}
