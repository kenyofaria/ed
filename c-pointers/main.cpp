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
    char string[] = "data structure";
    char *stringPtr = string;
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
    printf("Second position updated:\n");
    printIntArray(array, size);
}

int main() {
    //pointerExample1();
    //arrayExample1();
    //arrayExample2();
    //arrayExample3();
    // int n = 9;
    // printf("bit wise \n%d", n << 1);
}
