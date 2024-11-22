#include <stdio.h>

unsigned int factorial(unsigned int N) {
    int fact = 1, i;
    for (i = 1; i <= N; i++) {
        fact *= i;
    }
    return fact;
}

unsigned int recursiveFactorial(unsigned int n) {
    if (n == 1) {
        return 1;
    }
    return n * recursiveFactorial(n - 1);
}

int main() {
    int N = 10;
    unsigned int fact = factorial(N);
    unsigned int recursive_fact = recursiveFactorial(N);
    printf("Factorial of %d is %d", N, fact);
    printf("\nFactorial of %d is %d", N, recursive_fact);
    return 0;
}
