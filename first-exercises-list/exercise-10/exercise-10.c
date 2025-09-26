//
// Created by Kenyo Faria on 24/09/25.
//

#include <stdio.h>

void print_values() {
    int value = 10;
    printf("The value is: %d \n", value);
    int* ptr = &value;
    int* ptr2 = &value;
    printf("The value pointed by the pointer is: %d \n", *ptr);
    value = 11;
    printf("The value is: %d \n", value);
    printf("The value pointed by the pointer should be updated: %d \n", *ptr);
    printf("ptr2: %d \n", *ptr2);
}