#include <stdio.h>
#include <stdlib.h>


struct details
{
 char* name;
 int age;
 char* address;
 float salary;
};

int main(){
	struct details record = {"Noar", 50, "Melbourne", 1500};
	record.address = record.name;
	printf("The addree is %s\n", record.name);
	return EXIT_SUCCESS;
}
