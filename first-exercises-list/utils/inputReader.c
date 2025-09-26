//
// Created by Kenyo Faria on 24/09/25.
//
#include "inputReader.h"

#include <stdio.h>
#include <stdlib.h>

int input_int_reader(char *label) {
    int input;
    printf(label);
    scanf("%d", &input);
    return input;
}

float input_float_reader(char *label) {
    float input;
    printf(label);
    scanf("%f", &input);
    return input;
}

char input_char_reader(char *label) {
    char input;
    printf(label);
    scanf("%c", &input);
    return input;
}

char* input_string_reader(char *label) {
    printf("%s", label);

    char *input = malloc(256 * sizeof(char));
    if (input == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    // Read entire line including spaces
    if (scanf("%255[^\n]", input) != 1) {
        printf("Input reading failed!\n");
        free(input);
        return NULL;
    }

    return input;
}