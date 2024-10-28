#include <stdio.h>

struct student {
    char* registerNumer;
    char* name;
};

int main(){

    student studentA;
    studentA.registerNumer = "20240190";
    studentA.name = "John";

    student studentB = {"20240191", "Ryan"};

    printf("Data from student A: %s \t %s\n", studentA.registerNumer, studentA.name);
    printf("Data from student B: %s \t %s\n", studentB.registerNumer, studentB.name);

    printf("\n\n Now we are making a copy of a struct \n");

    struct student copyFromStydentA = studentA;

    printf("Data from the backup of the student A: %s \t %s\n", copyFromStydentA.registerNumer, copyFromStydentA.name);

}
