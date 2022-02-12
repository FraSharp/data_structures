/*
 * Compiled with clang 13.0.1
 * flags: -Wall -Wextra --std=c99
 */

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

// take number of values, [.. values]	
int find_in_arr(int values, ...) {
	// va = variable arguments
	// declase va_list
	va_list list;
	// init a va list
	va_start(list, values);

	// declare array with size [values]
	int arr[values];

	for (int i = 0; i < values; ++i)
		// insert va args from va_list to array[i]
		arr[i] = va_arg(list, int);

	/* 
	 * va_end should be called just before a return, but as it won't 
	 * be used anymore in this function, close va_list here
	 */
	va_end(list);

	for (int i = 0; i < values; i++) {
		for (int j = i + 1; j < values; j++) {
			if (arr[i] * 2 == arr[j] || (arr[i] / 2 == arr[j] && arr[i] % 2 == 0)) {
				return 1;
			}
		}
	}

	return 0;
}

int main() {

	// number of values, [... values]
	find_in_arr(4, 3, 1, 7, 11) == 1 ? printf("true") : printf("false");

	/*
	 * test values
	 * 10,2,5,3
	 * 7,1,14,11
	 * 3,1,7,11
	 */

	return 0;
}