#include <iostream>


int sum(int number) {
    if (number == 1)
        return number;
    return number + sum(number - 1);
}

void exercise1() {
   printf("\n the sum is: %d", sum(5));
}

int fibo(int number) {
    if (number <= 1) {
        return number;
    }
    return fibo(number - 1) + fibo(number - 2);
}

void exercise2() {
    printf("\n the fiboo is: %d", fibo(6));
}

int sumDigits(int number) {
    if (number == 0) {
        return 0;
    }
    return (number % 10) + sumDigits(number / 10);
}

void exercise3() {
    printf("\n digits sum: %d", sumDigits(1234));
}

int invertNumber(int number, int invert) {
    if (number == 0) {
        return invert;
    }
    return invertNumber(number / 10, invert * 10 + number % 10);
}
void exercise4() {
    printf("\n the inverted number is: %d", invertNumber(123, 0));
}

long int pow2(long int k, long int n) {
    if (n == 0) {
        return 1;
    }
    return k * pow2(k, n - 1);
}

void exercise5() {
    printf("\n the pow is: %d", pow2(2, 23));
}

int main()
{
    exercise1();
    exercise2();
    exercise3();
    exercise4();
    exercise5();
    return 0;
}
