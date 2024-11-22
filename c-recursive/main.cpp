#include <iostream>

// int* functionB(int * arr, int size) {
//     printf("\n\n starting function B\n\n");
//     int* even = (int*) malloc(size * sizeof(int));
//     int j = 0;
//     for (int i = 0; i < size; i++) {
//         if (arr[i] % 2 == 0) {
//             even[j++] = arr[i];
//         }
//     }
//     printf("\n\n ending function B\n\n");
//     return even;
// }
//
// void functionA(int * arr, int size) {
//     printf("\n\n starting function A\n\n");
//     int* result = functionB(arr, size);
//     for (int i = 0; i < size; i++) {
//         printf("   %d\n", result[i]);
//     }
//     printf("\n\n ending function A\n\n");
// }
//
// void experiment2() {
//     printf("\n\n starting program\n\n");
//     int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     size_t size = sizeof(array) / sizeof(array[0]);
//     functionA(array, size);
//     printf("\n\n ending program\n\n");
// }

void function2(char q[]) {
    printf("address from function2: %p\n", &q);
    printf("%s\n", q);
}

void function1(char p[]) {
    printf("address from function1: %p\n", &p);
    function2(p);
}

void experiment1() {
    char array[] = "Hello World!";
    printf("address from main: %p\n", &array);
    function1(array);
}

void experiment2() {
    char *hello = (char*) malloc(5*sizeof(char));
    char *world = (char*) malloc(6*sizeof(char));
    char *data = (char*) malloc(4*sizeof(char));
    char *structure = (char*) malloc(9*sizeof(char));
    strcpy(hello, "Hello");
    strcpy(world, "World");
    strcpy(data, "Data");
    strcpy(structure, "Structure");
    printf("experiment 2 hello on stack: %p\n", &hello);
    printf("experiment 2 world on stack: %p\n", &world);
    printf("experiment 2 data on stack: %p\n", &data);
    printf("experiment 2 structure on stack: %p\n", &structure);

    printf("experiment 2 hello on heap: %p\n", (void*) hello);
    printf("experiment 2 world on heap: %p\n", (void*) world);
    printf("experiment 2 data on heap: %p\n",  (void*) data);
    printf("experiment 2 structure on heap: %p\n", (void*) structure);
}

void recursion(char p[]) {
    printf("address from recursion: %p\n", &p);
    recursion(p);
}

int main() {
    //experiment1();
    //experiment2();
    char array[] = "Hello World!";
    recursion(array);
    return 0;
}
