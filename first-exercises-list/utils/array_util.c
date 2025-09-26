//
// Created by Kenyo Faria on 25/09/25.
//


#include <stdio.h>
#include <stdbool.h>

void print_array(int *array, int size) {
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}

bool contains(int *array, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return true;
        }
    }
    return false;
}
