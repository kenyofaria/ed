#include <cstdlib>
#include <stdio.h>

void pointerExample1() {
    printf("\n\n --------------------- pointer example 1 ----------------------\n");
    int* ptr;
    int number = 10;
    printf("number value is: %d\n", number);
    printf("number memory address is: %p\n", &number);
    ptr = &number;
    printf("look at the pointer value: %d\n", *ptr);
    *ptr = 20;
    printf("now the number value is: %d\n", number);
    printf("now the number memory address is: %p\n", &number);
}

void arrayExample1() {
    printf("\n\n --------------------- array example 1 ----------------------\n");
    int a[10] = {10,5,6,1,4,7,15,20,11,9};
    int size = sizeof(a)/sizeof(int);
    printf("The array of [%d] elements are:\n", size);
    for (int i = 0; i < size; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }
}

void arrayExample2() {
    printf("\n\n --------------------- array example 2 ----------------------\n");
    char vetor[] = "data structure";
    char *stringPtr = vetor;
    while (*stringPtr != '\0'){
        printf("%c\n", *stringPtr);
        stringPtr++;
    }
}

void printIntArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

void arrayExample3() {
    printf("\n\n --------------------- array example 3 ----------------------\n");
    int array[5] = {1,2,3,4,5};
    int size = sizeof(array)/sizeof(int);
    printf("Original array:\n");
    printIntArray(array, size);
    int* arrayPtr = array;
    *arrayPtr = 10;
    printf("First position updated:\n");
    printIntArray(array, size);
    *(arrayPtr+3)=11;
    printf("Other position updated:\n");
    printIntArray(array, size);
}

void pointerToArrayExample1() {
    printf("\n\n\n pointer to array example 1:\n");
    int numbers[5] = {1,3,5,7,9};
    int size = sizeof(numbers)/sizeof(int);
    for (int i = 0; i < size; i++) {
        printf("index: %d -> value: %d -> address %p\n", i, numbers[i], numbers + i);
    }
}

void pointerToArrayExample2() {
    printf("\n\n\n pointer to array example 2:\n");
    int numbers[5] = {1,3,5,7,9};
    int size = sizeof(numbers)/sizeof(int);
    for (int i = 0; i < size; i++) {
        printf("index: %d -> value: %d -> address %p\n", i, *(numbers + i), numbers + i);
    }
}

void addValueToArrayExample1(int* array, int size, int value) {
    for (int i = 0; i < size; i++) {
        array[i] = value;
    }
}

void addValueToArrayExample2(int** array, int size, int value) {
    *array = (int*) malloc(sizeof(int)); //using heap
    printf("address from array: %p \n", array); //pointer address in stack
    printf("address from where array points: %p", *array); //pointer target in heap
    for (int i = 0; i < size; i++) {
        (*array) [i] = value;
    }
}

void addArrayItemUsingPointerExample2() {
    printf("\n\n\n----------------- add array element by using pointer - example 2:\n");
    int values[] = {}; //asking for a heap space
    int *array = values; //allocating more space in the heap, to store pointer address
    int size = (sizeof(values)/sizeof(int))+1; //also, size is in the heap
    addValueToArrayExample2(&array, size, 10);
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    size = (sizeof(values)/sizeof(int))+1;
    addValueToArrayExample2(&array, size, 15);

    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}

void addArrayItemUsingPointerExample1() {
    printf("\n\n\n----------------- add array element by using pointer - example 1:\n");
    int values[] = {}; //asking for a stack space
    int *array = values; //allocating more space in the stack, to store pointer address
    int size = (sizeof(values)/sizeof(int))+1; //also, size is in the stack
    addValueToArrayExample1(array, size, 10);
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    size = (sizeof(values)/sizeof(int))+1;
    addValueToArrayExample1(array, size, 15);

    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    size = (sizeof(values)/sizeof(int))+1;
    addValueToArrayExample1(array, size, 17);

    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}

int main() {
    pointerExample1();
    arrayExample1();
    arrayExample2();
    arrayExample3();

    pointerToArrayExample1();
    pointerToArrayExample2();

    addArrayItemUsingPointerExample1();
    addArrayItemUsingPointerExample2();

    // int n = 9;
    // printf("bit wise \n%d", n << 1);
    return 0;
}
