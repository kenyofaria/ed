//
// Created by Kenyo Faria on 24/09/25.
//
#include "exercise-5.h"

float max(float *values, int size) {
    float max = values[0];
    for (int i = 1; i < size; i++) {
        if (values[i] > max) {
            max = values[i];
        }
    }
    return max;
}

float min(float *values, int size) {
    float min = values[0];
    for (int i = 1; i < size; i++) {
        if (values[i] < min) {
            min = values[i];
        }
    }
    return min;
}

float mid(float *values, int size) {
    float ma = max(values, size);
    float mi = min(values, size);

    for(int i = 0; i < size; i++) {
        if (values[i] != ma && values[i] != mi) {
            return values[i];
        }
    }
}
