#include <stdio.h>

int main() {
    int* ptr;
    int number = 10;
    ptr = &number;
    *ptr = 20;
    printf("number is: %d\n", number);

    printf("\n\n\n");

    //(k)01101011 (e)01100101 (n)01101110 (y)01111001 (o)01101111
    //01101011  01100101  01101110 stringPtr 01111001 01101111
    char string[] = "kenyo";
    char *stringPtr = string;
    while (*stringPtr != '\0'){
        printf("%c\n", *stringPtr);
        stringPtr++;
    }

    int n = 9;
    printf("bit wise \n%d", n << 1);
}
