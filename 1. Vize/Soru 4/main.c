#include <stdio.h>

int* max_address(int* A, int n) {
    int *result = A, max = A[0];
    int i;
    for (i = 1; i < n; ++i) {
        if (A[i] > max) {
            max = A[i];
            result = &A[i];
        }
    }
    return result;
}

void printArray(int* A, int n) {
    int i;
    for (i = 0; i < n; ++i) {
        printf("%3d", A[i]);
    }
    printf("\n");
}

int main(void) {
    int A[5] = {1, 1, 2, 3, 5};
    int B[6] = {8, 13, 21, 34, 55, 89};
    int temp, *p, *q;

    p = max_address(A, 5);
    q = max_address(B, 3);

    temp = *p;
    *p = *q;
    *q = temp;

    printArray(A, 5);
    printArray(B, 6);
}
