//
// Created by Kenyo Faria on 25/09/25.
//

#include <stdio.h>
#include "../utils/array_util.h"

void invert(int* nums, int numsSize) {
    if (numsSize == 0) {
        return;
    }
    print_array(nums, numsSize);
    int j = numsSize - 1; //to the end
    int i = 0; //to the begin
    while (i <= j) {
        int a = *(nums + i);
        int b = *(nums + j);
        *(nums + i) = b;
        *(nums + j) = a;
        i++;
        j--;
    }
    print_array(nums, numsSize);
}
