// System Programming
// Question 1
// Dosya adı: question1.c
// @gormelof

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main fuction has two parameters:
 * argc: parameter count
 * argv: it is na array, it keeps the parameters we use while running the program on the console.
*/

int main(int argc, char *argv[]) {

	char hex[50];

	int N = atoi(argv[1]);

	int i;

	unsigned long arr[N];
	unsigned char new_arr[N];

	srand(time(NULL));

	for(i = 0; i < N; i++) {
		arr[i] = rand();

		printf("Normal value          -> arr[%d]  = %lu\n", i, arr[i]);
		sprintf(hex, "%lx", arr[i]);
		printf("Hexadecimal value     -> arr[%d]  = 0x%s\n", i, hex);
		printf("Address               -> &arr[%d] = %p\n", i, &arr[i]);
	}

	printf("\n--------------------------------------------------\n\n");

	for(i = 0; i < N; i++) {
		new_arr[i] = (unsigned char) arr[i]; // type casting

		printf("Normal value             -> new_arr[%d]  = %u\n", i, new_arr[i]);
		sprintf(hex, "%x", new_arr[i]);
		printf("Hexadecimal value        -> new_arr[%d]  = 0x%s\n", i, hex);
		printf("Address                  -> &new_arr[%d] = %p\n", i, &new_arr[i]);
	}

	return 0;
}