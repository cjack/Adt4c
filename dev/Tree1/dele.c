typedef enum {
	EMPTY = 0, LEAF = 1, NODE = 2
} TreeKind;
typedef struct Tree *tree;

struct tree_struct
{
	TreeKind kind;
	union tree_data{
		int val;
		tree left;
		tree right;
	}

};
