//
// Created by Kenyo Faria on 24/09/25.
//

#include <stdbool.h>
#include <stdio.h>
#include "exercise-9.h"
#include "../utils/inputReader.h"

int get_num_days() {
    int year = input_int_reader("Enter with the year: ");
    if (year < 0) {
        printf("Invalid year");
        return 0;
    }
    int month = input_int_reader("Enter with the month: ");
    bool isLeap = false;
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        isLeap = true;
    }
    int days;
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            days = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
        case 2:
            if (isLeap) {
                days = 29;
            } else {
                days = 28;
            }
            break;
        default:
            printf("Invalid month");
            return 0;
    }
    return days;
}
