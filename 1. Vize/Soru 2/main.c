#include <stdio.h>

int commonElement(char* A, char* B) {
    int i, j;
    for (int i = 0; B[i]; ++i)
        for (j = 0; A[j]; ++j)
            if (B[i] == A[j]) return j;
    return -1;
}

int main(void) {
    char a[20] = "mathematics";
    char b[10] = "yildiz";
    int res = commonElement(a, b);
    printf("Result is %d\n", res);
}
