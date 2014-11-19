#include <stdio.h>
#include <stdlib.h>
#include "adt_t.h"

/*
data tree{
     leaf();
     node(int, tree, tree);
}
*/

int count_node(tree root){
	if_node(root, val, left, right)
		return 1 + count_node(left) + count_node(right);
	else()
		return 0;
	end_if()
}

int main(){

	return EXIT_SUCCESS;
}
