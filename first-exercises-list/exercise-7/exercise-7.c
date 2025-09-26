//
// Created by Kenyo Faria on 24/09/25.
//

#include <stdlib.h>
#include <string.h>

#include "../utils/inputReader.h"
#include "exercise-7.h"
#include "student.h"

Student* classifyStudent() {
    char *name = input_string_reader("Enter with the student name: ");
    float grade1 = input_float_reader("Enter with the grade 1: ");
    float grade2 = input_float_reader("Enter with the grade 2: ");
    Student* student = createStudent(name, grade1, grade2);
    float average = (student->grade1 + student->grade2) / 2;
    if (average >= 7) {
        strcpy(student->status, "APPROVED");
    } else {
        strcpy(student->status, "REPROVED");
    }
    return student;
}