//
// Created by Kenyo Faria on 25/09/25.
//

#include <string.h>

int count_words(char *s) {
    if (strlen(s) == 0) return 0;
    int count = 1;
    char *p = s;
    while (*p != '\0') {
        if (*p == ' ') {
            if (*(p+1) != ' ') {
                count++;
            }
        }
        *p++;
    }
    return count;
}
