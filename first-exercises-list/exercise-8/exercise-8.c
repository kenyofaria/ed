//
// Created by Kenyo Faria on 24/09/25.
//
#include "../utils/inputReader.h"

float calculate_tax() {
    int allowed = input_int_reader("Enter with the max velocity allowed: ");
    int current = input_int_reader("Enter with the current velocity: ");
    int diff = current - allowed;
    if (diff < 0) {
        return 0;
    }
    return diff * 5;
}
