//
// Created by Kenyo Faria on 26/09/25.
//

#include <stdbool.h>

bool is_triangle(int a, int b, int c) {
    return ((a + b > c) && (a + c > b) && (b + c > a));
}