#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
  int value;
  struct node *left;
  struct node *right;
}tree;

int count_node(tree *root){
	if(root != NULL){
		return 1 + count_node(left) + count_node(right);
	}else{
		retrun 0;
	}
}
int main(){


	return EXIT_SUCCESS;
}
