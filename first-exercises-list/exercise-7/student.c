//
// Created by Kenyo Faria on 24/09/25.
//
#include <stdlib.h>
#include <string.h>
#include "student.h"

Student* createStudent(char *name, float grade1, float grade2) {
    Student *student = malloc(sizeof(Student)); //using heap space
    student->name = malloc(strlen(name) + 1);
    student->status = malloc(10 * sizeof(char));
    strcpy(student->name, name);
    student->grade1 = grade1;
    student->grade2 = grade2;
    return student;
}
