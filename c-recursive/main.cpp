#include <iostream>

int* functionB(int * arr, int size) {
    printf("\n\n starting function B\n\n");
    int* even = (int*) malloc(size * sizeof(int));
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            even[j++] = arr[i];
        }
    }
    printf("\n\n ending function B\n\n");
    return even;
}

void functionA(int * arr, int size) {
    printf("\n\n starting function A\n\n");
    int* result = functionB(arr, size);
    for (int i = 0; i < size; i++) {
        printf("   %d\n", result[i]);
    }
    free(result);
    printf("\n\n ending function A\n\n");
}

void experiment2() {
    printf("\n\nstarting experiment2\n\n");
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    size_t size = sizeof(array) / sizeof(array[0]);
    functionA(array, size);
    printf("\n\nending experiment2\n\n");
}

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
    printf("address from experiment1: %p\n", &array);
    function1(array);
}

void experiment3() {
    char *hello = (char*) malloc(5*sizeof(char));
    char *world = (char*) malloc(6*sizeof(char));
    char *data = (char*) malloc(4*sizeof(char));
    char *structure = (char*) malloc(9*sizeof(char));
    strcpy(hello, "Hello");
    strcpy(world, "World");
    strcpy(data, "Data");
    strcpy(structure, "Structure");
    printf("experiment 2, hello pointer on stack: %p\n", &hello);
    printf("experiment 2 world pointer on stack: %p\n", &world);
    printf("experiment 2 data pointer on stack: %p\n", &data);
    printf("experiment 2 structure pointer on stack: %p\n", &structure);

    printf("experiment 2, hello address on heap: %p\n", hello);
    printf("experiment 2, world address on heap: %p\n", world);
    printf("experiment 2, data address on heap: %p\n",  data);
    printf("experiment 2, structure address on heap: %p\n", structure);

    printf("\n%s ",hello);
    printf("%s ",data);
    printf("%s\n",structure);

    free(hello);
    free(world);
    free(data);
    free(structure);
}

void stack_overflow_recursion(char p[]) {
    printf("address from recursion: %p\n", &p);
    stack_overflow_recursion(p);
}

int main() {
    // experiment1();
    experiment2();
    // experiment3();
    //char array[] = "Hello World!";
    //stack_overflow_recursion(array);
    return 0;
}
