//
// Created by Kenyo Faria on 24/09/25.
//

#ifndef STUDENT_H
#define STUDENT_H

typedef struct {
    char *name;
    float grade1, grade2;
    char *status;
} Student;

Student* createStudent(char *name, float grade1, float grade2);

#endif //STUDENT_H
