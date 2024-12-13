#include <iostream>
void example1() {
    int number = 10;
    int *p = &number;
    printf("memory content referred by p: %d\n", *p);
    printf("memory address of number: %p\n", &number);
    printf("memory address pointed by p: %p\n", p);
    printf("memory address of p: %p\n", &p);
}

void changeArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = array[i] + 1;
    }
}
void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}
void example2() {
    int array[5] = {3, 6, 7, 1, 9};
    int size = sizeof(array) / sizeof(int);
    changeArray(array, size);
    printf("array after change: ");
    printArray(array, size);
}

void example3() {
    char *p = "Bit";
    printf("memory content referred by p: %s\n", p);
    printf("memory address to where p is pointing to: %p\n", p);
    printf("memory address of p: %p\n", &p);
    printf("\n-----------------------------------------------------\n\n");
    char **p2 = &p;
    printf("memory content referred by p2: %s\n", *p2);
    printf("memory address to where p2 is pointing to: %p\n", p2);
    printf("memory address of p: %p\n", &p2);
}

void example4() {
    char* p = "hello world";
    char** pp = &p;
    printf("memory content referred by p: %s\n", p);
    printf("memory content referred by p: %s\n", *pp);
}

void allocateMemory(char** string) {
    *string = (char*) malloc(sizeof(char) * 4); //using heap
    if (*string == NULL) {
        return;
    }
    strcpy(*string, "Bit");
}
void example5() {
    char *p = nullptr;
    allocateMemory(&p);
    printf("memory address on heap: %p\n", p);
    printf("content on heap (first position): %c\n", *p);
    printf("content on heap: %s\n", p);
    printf("guilherme: %p\n", &*p);
}

int* populateArray(int size) {
    int* array = (int*) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        array[i] = rand();
    }
    return array;
}

void example6() {
    int size = 5;
    int* result = populateArray(size);
    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }
    free(result);
}

void example7() {
    char* p = "Bit";
    printf("%p\t%c\n", p, *p);
    printf("%p\t%c\n", ++p, *p);
    printf("%p\t%c\n", ++p, *p);
}

void example8() {
    char b = 'B';
    char i = 'i';
    char t = 't';
    char* p = &i;
    p--;
    printf("%p\t%c\n", &b, b);
    printf("%p\t%c\n", &i, i);
    printf("%p\t%c\n", &t, t);
    printf("%p\t%c\n", p, *p);
}

int main()
{
    printf("\n\n------------------- example 1 -------------------\n\n");
    example1();
    printf("\n\n------------------- example 2 -------------------\n\n");
    example2();
    printf("\n\n------------------- example 3 -------------------\n\n");
    example3();
    printf("\n\n------------------- example 4 -------------------\n\n");
    example4();
    printf("\n\n------------------- example 5 -------------------\n\n");
    example5();
    printf("\n\n------------------- example 6 -------------------\n\n");
    example6();
    printf("\n\n------------------- example 7 -------------------\n\n");
    example7();
    printf("\n\n------------------- example 8 -------------------\n\n");
    example8();
    return 0;
}
