// System Programming
// Question 2
// Dosya adı: question2.c
// @gormelof

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

	int t_flag = 0, c_flag = 0;
	int ch, i;

	while((ch = getopt(argc, argv, "t:c:")) != -1) {
		switch(ch) {
			case 't':
			printf("t option selected\n");
			t_flag = 1;
			break;
			case 'c':
			printf("c option selected\n");
			c_flag = 1;
			break;
		}
	}

	int sum = 0, multiply = 1;
	
	if(argc == 1) {
		printf("Invalid. Correct usage example: \"./program -c 1 2 3 4\" \n");
	} else if(t_flag == 1 && c_flag == 0) {
		for(i = 2; i < argc; i++) {
			sum += atoi(argv[i]);
		}
		printf("Sum = %d\n", sum);
	} else if(t_flag == 0 && c_flag == 1) {
		for(i = 2; i < argc; i++) {
			multiply *= atoi(argv[i]);
		}
		printf("Multiply = %d\n", multiply);
	} else {
		printf("Invalid!\n");
	}

	return 0;
}