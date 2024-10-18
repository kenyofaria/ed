//
// Created by Kenyo Faria on 17/10/24.
// programiz.com/c-programming/online-compiler
/*
 * C data types:
 * => if a variable has 4 bytes = 32 bits
 * it might represent 2ˆ32 distinct values
 * from -2147483648 to 2147483647.
 *
 * int (4 bytes) | %d for printing
 * double (8 bytes) | %lf for printing
 * float (4 bytes) | %f for printing
 * char (1 byte) | %c for printing
 *
 */
#include <stdio.h>
#include <stdbool.h>

void printHelloWorld() {
    printf("Hello World\n");
}
void printInt() {
    int number = 101;
    printf("the int number is: %d\n", number);
}
void printFloat() {
    float number = 10.1;
    printf("the float number is: %f\n", number);
    printf("the float number (precision 2) is: %.2f\n", number);
}
void printDouble() {
    double number = 10.1;
    printf("the double number is: %lf\n", number);
    printf("the double number (precision 2) is: %.2lf\n", number);
    double exponential = 5.5e6;
    printf("the double (exponential) number is: %lf\n", exponential);
}
void printCharacter() {
    char minusChar = 'k';
    char capitalChar = 'K';
    printf("the character as a char is: %c\n", minusChar);
    printf("the character as a int is: %d\n", minusChar);
    printf("the character as a char is: %c\n", capitalChar);
    printf("the character as a int is: %d\n", capitalChar);
}
void printSizeOf() {
    int intNumber = 10;
    float floatNumber = 10.1;
    double doubleNumber = 10.1;
    char character = 'K';
    // %zu -> %z tells printf to expect an argument of type size_t
    // and the flag u indicates that the size_t value should be printed
    // as a unsigned decimal integer
    printf("size of int is: %zu\n", sizeof(intNumber));
    printf("size of float is: %zu\n", sizeof(floatNumber));
    printf("size of double is: %zu\n", sizeof(doubleNumber));
    printf("size of char is: %zu\n", sizeof(character));
}
void printSetOfChars() {
    char k = 'K';
    char e = 'e';
    char n = 'n';
    char y = 'y';
    char o = 'o';
    printf("%c %c %c %c %c\n", k, e, n, y, o);
    printf("%c%c%c%c%c\n", k, e, n, y, o);
}

void printChosenOption(int option) {
    printf("option chosen was: %d \n", option);
}

void prompt() {
    int command;
    while(true) {
        printf("\n-------- Enter command ------------ \n");
        scanf("%d", &command);
        switch(command) {
            case 0:
                printf("leaving the program");
                return;
            case 1:
                printChosenOption(command);
                break;
            case 2:
                printChosenOption(command);
                break;
            case 3:
                printChosenOption(command);
                break;
            default:
                printf("invalid option: %d \n", command);
                break;
        }
    }
}

int main() {
    printHelloWorld();
    printInt();
    printFloat();
    printDouble();
    printCharacter();
    printSizeOf();
    printSetOfChars();
    prompt();
    return 0;
}


