//
// Created by Kenyo Faria on 24/09/25.
//
#include "exercise-6.h"
#include "../utils/inputReader.h"


float do_sum() {
    float a = input_float_reader("Enter with the first number: ");
    float b = input_float_reader("Enter with the second number: ");
    return a + b;
}
float do_sub() {
    float a = input_float_reader("Enter with the first number: ");
    float b = input_float_reader("Enter with the second number: ");
    return a - b;
}
float do_mul() {
    float a = input_float_reader("Enter with the first number: ");
    float b = input_float_reader("Enter with the second number: ");
    return a * b;
}
float do_div() {
    float a = input_float_reader("Enter with the numerator: ");
    float b = input_float_reader("Enter with the denominator: ");
    return a / b;
}

float do_operation(char operator) {
    switch (operator) {
        case '+':
            return do_sum();
        case '-':
            return do_sub();
        case '*':
            return do_mul();
        case '/':
            return do_div();
        default:
            return 0;
    }
}