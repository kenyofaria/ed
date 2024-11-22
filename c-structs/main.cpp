#include <stdio.h>

struct Student {
    char* registerNumber;
    char* name;
};

typedef struct {
    char* registerNumber;
    char* name;
} Professor;

void studentExample() {
    printf("\n--------------------Student Example--------------------\n");
    Student studentA;
    studentA.registerNumber = "20240190";
    studentA.name = "John";

    Student studentB = {"20240191", "Ryan"};

    printf("Data of student A: %s \t %s\n", studentA.registerNumber, studentA.name);
    printf("Data of student B: %s \t %s\n", studentB.registerNumber, studentB.name);

    printf("\n\n Now we are making a copy of a struct \n");

    struct Student copyFromStydentA = studentA;

    printf("Data from the backup of the student A: %s \t %s\n", copyFromStydentA.registerNumber, copyFromStydentA.name);
}

void professorExample() {
    printf("\n--------------------Professor Example--------------------\n");
    Professor professorA = {"45625232", "Kenyo"};
    printf("Data of professor A: %s \t %s\n", professorA.registerNumber, professorA.name);
}

int main() {
    studentExample();
    professorExample();
}
