#include <stdio.h>
#include <stdlib.h>
#include "adt_t.h"

/*
data details{
     record(char*, int, char*, float);
}
*/

int main(){

	details r = record("Noar", 50, "Melbourne", 1500);
	if_record(r, name, age, address, salary)
		address = name;
		printf("The address is %s\n", address);
	end_if()
	return EXIT_SUCCESS;
}
