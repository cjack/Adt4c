// test way to support algebraic data types in C 

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "cordlist.h"  // generated from types etc

////////////////////////////////////////////////////////////////////////////////
// There is some stuff which should be generated automatically eventually but
// is not yet (currently no proper support for polymorphism)

// generated for List_Long instance of length etc
// We would need to declare these as generic/polymorphic functions
// and say what instances we need.
# define length_Long(v) length2((List) \
	(_ADT_List_Long_tchk=(v),_ADT_List_Long_tchk))


# define tail_Long(v) ((List_Long)tail((List) \
	((_ADT_List_Long_tchk=(v),_ADT_List_Long_tchk))))


# define append_Long(v,v1) (append((List*) \
	((_ADT_List_Long_ptr_tchk=(v),_ADT_List_Long_ptr_tchk)), \
	(List)((_ADT_List_Long_tchk=(v1),_ADT_List_Long_tchk)) ))


# define append1_Long(v,v1) (append1((List*) \
	((_ADT_List_Long_ptr_tchk=(v),_ADT_List_Long_ptr_tchk)), \
	(List)((_ADT_List_Long_tchk=(v1),_ADT_List_Long_tchk)) ))

// generated if we use this type check technique
// (with extern version in .h file)
// XXX Hmm, append example shows we need ptrs to _ADT types, and
// potentially ptrs to ptrs etc - how many do we generate?
// Also, strictly, we need more than one _ADT..._tchk var of each type
// for functions with more than one argument (arg evaluation could
// potentially be interleaved in C, which would break with this method)
// Can have default max number of args and ptrs to ptrs which can be overridden
// by command line option (or do two passes and compute maxima)
List _ADT_List_tchk;
List_Long _ADT_List_Long_tchk,
	*_ADT_List_Long_ptr_tchk;

// Note: using a void function would make it easier to get a type
// check included with {...}:
// # define length_Long(resptr, v) \
// {{{List_Long tchk=(v);}; length(resptr, (List)(v))}
// We can get type checks into expressions with
// ((expected_type) v == v ? v : v)
// The problem with this is that if there are function calls in v
// C can't optimise them away because they might cause side effects
// ...:-( Should be ok for variables.  For now we use
// (var_of_expected_type=v, var_of_expected_type)
// It would be nice to avoid writing to a global var, though its
// probably not that significant an overhead for a function call.
// 
// NOTE: Also, since this is a compile time check, it would be possible
// to have a build script which checks it compiles ok with the checks
// included then have another version of the code without the checks
// which is actually used to build the final executable.  The same
// applies to various other checks we add: even though they are cheap it
// might be best to avoid them if we can.  Could have options on
// preprocessor or always(?) spit out two versions (maybe with #ifdef)
// for build script to handle.  Eg, in Makefile:
// foo.o: foo.c adt1.h
// 	$(CC) $(CFLAGS) -DADT_CHECK -o foo.c
// 	$(CC) $(CFLAGS) -DADT_NO_CHECK -o foo.c
// This is quite distinct from runtime checks where we only want to
// remove them when the program is free of runtime errors (which is
// rather hard to determine).  Our approach catches more errors at
// compile time compared to "adt" and is very lean wrt what needs to be
// done at runtime (need some malloc checks which we could possibly make
// optional but they should be cheap enough to do all the time anyway).
// We could also add some extra stuff like avoiding zero being the
// representation of anything and malloc zeroing args of data
// constructors which are ADTs to catch uninitialised data.

////////////////////////////////////////////////////////////////////////////////

// returns sum of ints in a Cord_int
// Uses iteration to avoid some recursion
// (optimised for larger right branch, like list case)
// if-the-else version (not quite as nice as switch)
int
sum_cord(Cord_int c) {
	int s = 0;
	while (1) {
// printf("s %d \n", s);
		if_Empty(c)
			return s;
		else_if_Leaf(d) // note c is not an argument
			return d+s;
		else_if_Branch(l, r)
			s += sum_cord(l);
			c = r;
// 		else()
// 			printf("Doh! %lx\n", (long) c);
// 			return s;
		end_if()
	}
}

// returns sum of ints in a Cord_int
// Uses iteration to avoid some recursion
int
sum_cord1(Cord_int c) {
	int s = 0;
	while (1) {
		switch_Cord_int(c)
		case_Empty()
			return s;
		case_Leaf(d)
			return d+s;
		case_Branch(l, r)
			s += sum_cord1(l);
			c = r;
		default() // "impossible"
			printf("Doh! %lx\n", (long) c);
			return s;
		end_switch()
	}
}

// returns sum of ints in a Cord_int
// Simple double recursion version without sanity check
// Extra semicolons added to make syntax look like std C
// so IDEs are not confused by these macros
// (this is also why we add () to end_switch etc)
int
sum_cord2(Cord_int c) {
	switch_Cord_int(c);
	case_Empty();
		return 0;
	case_Leaf(d);
		return d;
	case_Branch(l, r);
		return sum_cord2(l) + sum_cord2(r);
	end_switch();
}

// polymorphic length function
// void
// length(int *res, List l) {
int
length(List l) {
	int len = 0;
	while (1) {
		if_Cons(l, _h, t)
			l = t;
			len++;
		else()
// 			*res = len; return;
			return len;
		end_if()
	}
}

int
length1(List l) {
	int len = 0;
	while (1) {
		switch_List(l)
		case_Cons(_h, t)
			l = t;
			len++;
		case_Nil()
			return len;
// Errors:
// 			t = t;    // t not in scope here
// 		case_Branch(l, r) // type error
		end_switch()
	}
}

// Possible while_CON, end_while macros (maybe implement?)
// Slightly different positioning of _ADT_v=(v) so its done each
// iteration (could have similar for if_CON and switch_T for consistency)
// Works ok:
// #define while_Cons(v, v0, v1) \
// {List _ADT_v;while ((_ADT_v=(v),((intptr_t)(_ADT_v)&7)==1)) {\
// struct _ADT_V1* v0=((struct _ADT_List_Cons*)((intptr_t)_ADT_v-1))->f0; \
// struct _ADT_List* v1=((struct _ADT_List_Cons*)((intptr_t)_ADT_v-1))->f1;
// #define end_while }}

// More flexible version which allows extra conjunct in while condition,
// including use of head and tail.  Could do the same for if.  Probably
// not much point for if, possibly more useful with while but marginal?

#define while_Cons(v, v0, v1, t) \
{List _ADT_v; \
struct _ADT_V1* v0; \
struct _ADT_List* v1; \
while ((_ADT_v=(v),((intptr_t)(_ADT_v)&7)==1) && \
(v0=((struct _ADT_List_Cons*)((intptr_t)_ADT_v-1))->f0, \
v1=((struct _ADT_List_Cons*)((intptr_t)_ADT_v-1))->f1, \
t)) {\


#define while_Cons1(v, v0, v1, t) \
{List _ADT_v = v; \
struct _ADT_V1* v0;\
struct _ADT_List* v1;\
v0= (((struct _ADT_List_Cons*)((intptr_t)_ADT_v-1))->f0); \
v1= (((struct _ADT_List_Cons*)((intptr_t)_ADT_v-1))->f1); \
if ((((intptr_t)(_ADT_v)&7)==1) && t){ \

#define end_while1(v, v0, v1, t) while_Cons1(v, v0, v1, t)}}}}\

#define end_while() }}

#define True 1
length3(List l) {
	int len = 0;
	while_Cons1(l, _h, t, True)
		l = t;
		len++;
	end_while1(l, _h, t, True)
	return len;
}

length2(List l) {
	int len = 0;
	while_Cons(l, _h, t, True)
		l = t;
		len++;
	end_while()
	return len;
}

// polymorphic tail function
List
tail(List l) {
	if_Cons(l, _h, t)
		return l;
	end_if()
	fprintf(stderr, "tail of Empty List\n");
	exit(1);
}

// polymorphic destructive append: takes pointer to List
// and changes Nil ("next" pointer at end) to another List r.
// if_then_else version - handy for using break
void
append(List *lp, List r) {
	while (1) {
		if_Cons_ptr(*lp, _hp, tp)
			lp = tp;
		else()
			break;
		end_if()
	}
	*lp = r;
}

// polymorphic destructive append
// returns from inside loop since break wouldn't work
void
append1(List *lp, List r) {
	while (1) {
		switch_List(*lp)
		case_Cons_ptr(_hp, tp)
			lp = tp;
		case_Nil()
			// note: break here exits from switch only
			*lp = r;
			return;
		end_switch()
	}
}

main(){
	int i = 10;
	List_Long llong;
	ListList ll;
	Cord_int c;
	Cord_int c2, c3, c4, c5, c6, c7;
	c2 = Leaf(42);
	c3 = Leaf(1);
	c4 = Leaf(i);
	c5 = Empty();
	c6 = Branch(c2, c3);
	c7 = Branch(c4, c5);
	c = Branch(c6, c7);
//	printf(" %lx\n", (long unsigned) c2);
//	printf(" %lx\n", (long unsigned) c3);
//	printf(" %lx\n", (long unsigned) c4);
//	printf(" %lx\n", (long unsigned) c5);
//	printf(" %lx\n", (long unsigned) c6);
//	printf(" %lx\n", (long unsigned) c7);
//	printf(" %lx\n", (long unsigned) c);
// 	c = Branch(
// 		Branch(
// 			Leaf(42),
// 			Leaf(1)),
// 		Branch(
// 			Leaf(i),
// 			Empty()));
	printf("Sum is %d\n", sum_cord(c));
	printf("Sum is %d\n", sum_cord1(c));
	printf("Sum is %d\n", sum_cord2(c));
	llong = tail_Long(
			Cons_Long(Long_(123L),
			Cons_Long(Long_(234L),
			Nil_Long())));
	printf("Length is %d\n", length_Long(llong));
	append_Long(&llong, Cons_Long(Long_(56L), Nil_Long()));
	append1_Long(&llong, Cons_Long(Long_(78L), Nil_Long()));
//	append1_Long(&llong, Cons_Long(Long_(78L), Nil_Long()));
	printf("Length is %d\n", length_Long(llong));
// 	llong = tail_Long(Nil_ListList()); // type error (arg)
// 	ll = tail_Long(Nil_Long()); // type error (LHS)


	//---------------test------------------------
	ADTList *list1;
	ADTList *list2;
	list1 = New_List((int), 100, NULL);
}

