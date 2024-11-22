#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <stdbool.h>


int exercise1_receive_values(int** array) {
    int size;
    printf("enter with the size of the array:");
    scanf("%d", &size);
    *array = (int*) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        (*array)[i] = rand();
    }
    return size;
}

void exercise1() {
    int* array;
    int size = exercise1_receive_values(&array);
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    free(array);
}

int exercise2_copyChars(char* source, char* target, int size) {
    target = (char*)malloc(size * sizeof(char));
    if (target == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 0;
    }
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (source[i] != ' ') {
            target[j] = source[i];
            j++;
        } else {
            break;
        }
    }
    free(target);
    return j;
}

void exercise2() {
    char* source = "data structure";
    char* target;
    int size = strlen(source);
    printf("Total of copied chars: %d", exercise2_copyChars(source, target, size));
}

void exercise3() {
    int a, b, c, d;
    float e, f, g, h;
    char v[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    int x;
    int* ptr = &a;
    while(true) {
        printf("\n\n-------------------------------------------------\n\n");
        ptr--;
        printf("a: %p\t%d\n", &a, a);
        printf("b: %p\t%d\n", &b, b);
        printf("c: %p\t%d\n", &c, c);
        printf("d: %p\t%d\n", &d, d);
        printf("e: %p\t%f\n", &e, e);
        printf("f: %p\t%f\n", &f, f);
        printf("g: %p\t%f\n", &g, g);
        printf("h: %p\t%f\n", &h, h);
        printf("v: %p\t%p\n", &v, v);
        printf("x: %p\t%d\n", &x, x);
        printf("pointer: %p\t%d\n", ptr, *ptr);
        bool match = false;
        if (ptr == &b || ptr == &c || ptr == &d) {
            match = true;
        }
        if (match) {
            printf("True: Pointer matches another variable's address.\n");
            break;
        } else {
            printf("False: Pointer does not match any other variable's address.\n");
        }
    }
}


int* exercise4_inputValues() {
    int tmp;
    int* values = (int*)malloc(3 * sizeof(int));
    printf("enter with the first value:");
    scanf("%d",&values[0]);
    printf("enter with the second value:");
    scanf("%d",&values[1]);
    printf("enter with the third value:");
    scanf("%d",&values[2]);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3 - i - 1; j++) {
            if (values[j] > values[j+1]) {
                tmp = values[j];
                values[j] = values[j+1];
                values[j+1] = tmp;
            }
        }
    }
    return values;
}

void exercise4() {
    int* result = exercise4_inputValues();
    printf("result: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", result[i]);
    }
}

void exercise5_operation(int* array, int size, int* max, int* min, float* avg) {
    int sum = 0;
    *max = *min = array[0];
    for (int i = 0; i < size; i++) {
        if(*max < array[i]) {
            *max = array[i];
        }
        if(*min > array[i]) {
            *min = array[i];
        }
        sum = sum + array[i];
    }
    *avg = (float)sum / size;
}

void exercise5() {
    int array[5] = {5,6,9,3,2};
    int max = 0;
    int min = 0;
    float avg = 0;
    exercise5_operation(array, 5, &max, &min, &avg);
    printf("max: %d, min: %d, avg: %f\n", max, min, avg);
}

/**
 * This function aims to convert a given number to a standard order. For example:
 * when num = 213 the return is 123;
 * when num = 849 the return is 489;
 * @param num integer that has been coming from an array
 * @return the inverse order for every num provided as input
 */
int exercise7_sortDigits(int num) {
    int digits[4] = {0}; // Assuming max 4 digits
    int count = 0;
    int sortedNum = 0;

    //transforming a number into digits[]
    while (num > 0) {
        digits[count++] = num % 10; //rest from num/10
        num /= 10; //num = num/10
    }

    //Since the num (parameter) has been put into digits, we are applying the bubble sort on it
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (digits[i] > digits[j]) {
                int temp = digits[i];
                digits[i] = digits[j];
                digits[j] = temp;
            }
        }
    }

    int multiplier = 1;
    for (int i = count - 1; i >= 0; i--) {
        sortedNum += digits[i] * multiplier;
        multiplier *= 10;
    }

    return sortedNum;
}

void exercise7_groupPermutations(int arr[], int size) {
    bool *visited = (bool *)malloc(size * sizeof(bool));
    if (visited == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return;
    }
    //we are defining all the positions as not visited.
    //It is necessary because we have nested for on next statement.
    //So, this flag ensure that we don't consider already visited numbers
    for (int i = 0; i < size; i++) {
        visited[i] = false;
    }

    int group = 1;
    for (int i = 0; i < size; i++) {
        if (!visited[i]) {
            int sortedNum = exercise7_sortDigits(arr[i]);
            printf("Group %d: %d ", group, arr[i]);
            visited[i] = true;
            group++;

            for (int j = i + 1; j < size; j++) {
                if (!visited[j] && exercise7_sortDigits(arr[j]) == sortedNum) {
                    printf("%d ", arr[j]);
                    visited[j] = true;
                }
            }
            printf("\n");
        }
    }
    //deallocating the memory allocated to mark the elements already visited
    free(visited);
}
void exercise7() {
    int size = 10;
    int* input = (int*)malloc(size * sizeof(int));
    int i = 0;
    while (i<size) {
        printf("\nEnter with a valid number:");
        if (scanf("%d", &input[i]) != 1) {
            printf("Invalid input, exiting.\n");
            break;
        }

        if (input[i] < -9999 || input[i] > 9999) {
            printf("Error: Number exceeds 4 digits. Please try again.\n");
        } else {
            printf("Valid number\n");
            i++;
        }
    }
    exercise7_groupPermutations(input, size);
}

void performBubleSort() {
    int array[8] = {7, 4, 5, 3, 1, 8, 2, 6};
    for (int i = 0; i < 8 - 1; i++) {
        for (int j = i + 1; j < 8; j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        printf("%d ", array[i]);
    }
}

int main()
{
    exercise1();
    //exercise2();
    //exercise3();
    //exercise4();
    //exercise5();
    //exercise7();
    // performBubleSort();
    return 0;
}
