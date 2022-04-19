#include <stdio.h>

// (a)
int sumDigits(int number) {
    if (!number) return 0;
    return (number % 10) + sumDigits(number / 10);
}

// (b)
int oddEvenDifference(int number) {
    if (!number) return 0;
    int temp = number % 10;
    return ((temp % 2 == 1) ? temp : -1 * temp) + oddEvenDifference(number / 10);
}

int main(void) {
    int number = 45632;
    int sum = sumDigits(number);
    int dif = oddEvenDifference(number);
    printf("sum and dif: %d %d\n", sum ,dif);
}
