//
// Created by Kenyo Faria on 25/09/25.
//

#include <string.h>

int compare(const char *a, const char *b) {
    int temp = strcmp(a, b);
    if (temp == 0) return 0;
    if (temp < 0) return -1;
    return 1;
}
