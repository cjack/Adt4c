#include <stdio.h>
#include "adt_t.h"

int main(){

	Test test[15];
	test[0] = const_1();
	test[1] = const_2();
	test[2] = const_3();
	test[3] = const_4();
	test[4] = non_const_1(3, 'b', 4, 5.1);
	test[5] = non_const_2(3, 'b', 4);
	test[6] = non_const_3(3, 'b');
	test[7] = non_const_4(3);
	test[8] = non_const_5(3, 'b', 4, 5.1);
	test[9] = non_const_6(3);
	test[10] = non_const_7(3);
	test[11] = non_const_8(3);
	test[12] = non_const_9(3);

	int i = 1;

	for(i = 0; i < 13; i++){
		switch_Test(test[i])
			case_const_1() printf("This is const_1\n");
			case_const_2() printf("This is const_2\n");
			case_const_3() printf("This is const_3\n");
			case_const_4() printf("This is const_4\n");
			case_non_const_1(a, b, c, d) printf("This is non_const_1\n");
			case_non_const_2(a, b, c) printf("This is non_const_2\n");
			case_non_const_3(a, b) printf("This is non_const_3\n");
			case_non_const_4(a) printf("This is non_const_4\n");
			case_non_const_5(a, b, c, d) printf("This is non_const_5\n");
			case_non_const_6(a) printf("This is non_const_6\n");
			case_non_const_7(a) printf("This is non_const_7\n");
			case_non_const_8(a) printf("This is non_const_8\n");
			case_non_const_9(a) printf("This is non_const_9\n");
			default() printf("This is default\n");
		end_switch()
	}

	for(i = 0; i < 13; i++){
		free_Test(test[i]);
		switch_Test(test[i])
			case_const_1() printf("This is const_1\n");
			case_const_2() printf("This is const_2\n");
			case_const_3() printf("This is const_3\n");
			case_const_4() printf("This is const_4\n");
			case_non_const_1(a, b, c, d) printf("This is non_const_1\n");
			case_non_const_2(a, b, c) printf("This is non_const_2\n");
			case_non_const_3(a, b) printf("This is non_const_3\n");
			case_non_const_4(a) printf("This is non_const_4, value is %d\n",a);
			case_non_const_5(a, b, c, d) printf("This is non_const_5 is %d, %c, %ld, %lf\n", a, b, c, d);
			case_non_const_6(a) printf("This is non_const_6\n");
			case_non_const_7(a) printf("This is non_const_7\n");
			case_non_const_8(a) printf("This is non_const_8\n");
			case_non_const_9(a) printf("This is non_const_9\n");
			default() printf("This is default\n");
		end_switch()
	}

	return 0;
}
