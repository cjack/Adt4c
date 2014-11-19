// test way to support algebraic data types in C 

#include<stdlib.h> // malloc
#include<stdio.h>

#define IMPOSIBLE -2
// check out enum types in more detail for tags (especially
// if we have separate macros for switch cases)?

//define the enum type for cord tag
typedef enum{NIL = 0, LEAF = 1, BRANCH = 2} cord_tag;


typedef struct cord_s *cord;
typedef struct nil_s {} nil_t;
typedef struct leaf_s {int datum;} leaf_t;
typedef struct branch_s {cord left; cord right;} branch_t;
// will optimise following for malloc etc
union cord_u {nil_t nil_d; leaf_t leaf_d; branch_t branch_d;};
//Add enum tag for cord
struct cord_s {
	cord_tag cord_t;
	int cord_k;
	union cord_u cord_n;
};

// XXX check return value; could have option to specify what
// malloc+free function to call - may want specialised malloc for
// ADTs.  Makes determining how many tag bits we can use a bit more
// tricky (with stdlib malloc we can probably use 3)
#define safe_malloc(s) malloc(s)

// can we make #define/inline version of following easily using ","?
// (maybe marginal due to malloc call, though we might
// optimise this away for zero arity constructors)


cord
malloc_nil() {
	cord c = (cord) safe_malloc(sizeof(struct cord_s));
	c->cord_t = NIL;
	c->cord_k = 0;
	return c;
}

cord
malloc_leaf(int datum_v) {
	cord c = (cord) safe_malloc(sizeof(struct cord_s));
	c->cord_t = LEAF;
	c->cord_k = 1;
	c->cord_n.leaf_d.datum = datum_v;
	return c;
}

cord
malloc_branch(cord left_v, cord right_v) {
	cord c = (cord) safe_malloc(sizeof(struct cord_s));
	c->cord_t = BRANCH;
	c->cord_k = 2;
	c->cord_n.branch_d.left = left_v;
	c->cord_n.branch_d.right = right_v;
	return c;
}

// want this for optimised case where we may not call free for
// zero arity constructors
void
free_cord(cord cord_v) {
	free(cord_v);
}

#define if_nil(cord_v, s1, s2) \
	 if (cord_v->cord_k == 0) { \
		s1} else s2

#define if_leaf(cord_v, datum_v, s1, s2) \
	 if (cord_v->cord_k == 1) { \
		int datum_v = cord_v->cord_n.leaf_d.datum; \
		s1} else s2

#define if_branch(cord_v, left_v, right_v, s1, s2) \
	 if (cord_v->cord_k == 2) { \
		cord left_v = cord_v->cord_n.branch_d.left; \
		cord right_v = cord_v->cord_n.branch_d.right; \
		s1} else s2

//------------------------------------------------------------------------------
#define isNIL() \
case NIL: \

#define isLEAF(_cord_, val) \
case LEAF : \
val = _cord_->cord_n.leaf_d.datum;

#define isBRANCH(_cord_, val, left, right) \
case BRANCH : \
left = _cord_->cord_n.branch_d.left; \
right = _cord_->cord_n.branch_d.right;


//Use the macro with the tag for pattern matching
int cord_sum2(cord c){
	int s = 0;
	cord left, right;
	switch(c->cord_t){
//	switch(get_tag(c)){
		isNIL()
			return 0;
		isLEAF(c,s)
			return s;
		isBRANCH(c,s, left, right)
			return (s + cord_sum2(left) + cord_sum2(right));
		printf("Impossible!\n");
		return IMPOSIBLE;
	}


}
//------------------------------------------------------------------------------



// returns sum of data in cord
// Uses iteration to avoid some recursion
int
cord_sum(cord c) {
	int s = 0;
	while (1) {
		if_nil(c,
			return s;,
		if_leaf(c, d,
			return d+s;,
		if_branch(c, l, r,
			s += cord_sum(l);
			c = r;,
		//else
		printf("Impossible!\n");
		return s;
		)))
	}
}

//get the tag from a cord
//cord_tag get_tag(cord *c){
//	return c->cord_t;
//}

int main(){
	int i = 10;
// 	printf("Sizes: %d %d %d\n", (int)sizeof(void*), (int)sizeof(int),(int)sizeof(long));
	cord c = malloc_branch(
			// malloc_nil(),
			malloc_branch(
				malloc_leaf(42),
				malloc_leaf(1)),
			malloc_branch(
				malloc_leaf(i),
				malloc_nil()));
	printf("Sum is %d\n", cord_sum2(c));
	return 0;

}
