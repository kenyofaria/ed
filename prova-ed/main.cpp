

#include <cstdio>
#include <cstdlib>


int main() {
    int a = 10;
    int b = 20;
    int c = 30;
    int* pointer = &a;
    printf("%d\t%d\t%d\n", *pointer--, *pointer, *++pointer);
}

// int main() {
//     char* p = "data structure";
//     printf("%c\n", *++++p);
// }
//
// long int calc(long int k, long int n) {
//     if (n == 0) {
//         return 1;
//     }
//     return k * calc(k, n - 1);
// }
//
// int main() {
//     printf("\n the value is: %d", calc(2, 3));
// }

// int process(int number, int value) {
//     if (number == 0) {
//         return value;
//     }
//     return process(number/10, value*10 + number%10);
// }
// int main() {
//     printf("\n the output is: %d", process(691, 0));
// }
//
// int main() {
//     int *var1 = (int*) malloc(sizeof(int));
//     int *var2 = (int*) malloc(sizeof(int));
//
//     printf("%p\n", var1);
//     printf("%p\n", &var1);
//     printf("%p\n", var2);
//     printf("%p\n", &var2);
//
//     return 0;
// }

// void functionArray(int* array, int size) {
//     for (int i = 0; i < size - 1; i++) {
//         for (int j = 0; j < size - i - 1; j++) {
//             if (array[j] > array[j + 1]) {
//                 int temp = array[j];
//                 array[j] = array[j + 1];
//                 array[j + 1] = temp;
//             }
//         }
//     }
// }
//
// int main() {
//     int array[5] = {8, 4, 7, 1, 9};
//     int size = sizeof(array) / sizeof(array[0]);
//     functionArray(array, size);
//     for (int i = 0; i < size; i++) {
//         printf("%d ", array[i]);
//     }
// }

// void performCalc(int* number) {
//     if (*number%2 == 0) {
//         *number = *number/2;
//     }
// }
//
// int main() {
//     int number = 7;
//     performCalc(&number);
//     printf("%p\n", &number);
// }
