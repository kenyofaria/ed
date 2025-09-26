//
// Created by Kenyo Faria on 25/09/25.
//

#include "../utils/array_util.h"
#include <stdlib.h>



void remove_duplicates(int *s, int size) {
    print_array(s, size);
    int *p = s;
    int *result = malloc(size * sizeof(int));
    int position = 0; //index for the result array
    int new_size = 0; //used to determine how far the result array should be printed
    for (int i = 0; i < size; i++) {
        if (*p != *p + 1) { //avoiding execute the following statements when is not needed
            int value = *(p + i);
            if (!contains(result, size, value)) {
                result[position++] = value;
                new_size++;
            }
        }
        *p = *p + 1;
    }
    print_array(result, new_size);
}
