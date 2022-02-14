/*
 * Compiled with clang 13.0.1
 * flags: -Wall -Wextra --std=c99
 */

#include <stdio.h>
#include <stdarg.h>

int rob_house(int values, ...) {
        // va = variable arguments
        // declase va_list
        va_list list;
        // init a va list
        va_start(list, values);

        // declare array with size [values]
        int arr[values];

        if ((values <= 1 || values >= 100)) {
                printf("%s: unhandled values, ret 0\n", __func__);
                return 0;
        }

        for (int i = 0; i < values; ++i) {
                // insert va args from va_list to array[i]
                arr[i] = va_arg(list, int);
                if (arr[i] <= 0 || arr[i] >= 400) {
                        printf("%s: unhandled values, ret 0\n", __func__);
                        return 0;
                }
        }

        /* 
         * va_end should be called just before a return, but as it won't 
         * be used anymore in this function, close va_list here
         */
        va_end(list);

        int ret = 0;
        for (int i = 0; i < values; i += 2)
                ret += arr[i];
        return ret;
}

int main() {
        int rob = rob_house(5, 2, 7, 9, 5000, 1);

        if (rob != 0)
                printf("%d\n", rob);
        return 0;
}