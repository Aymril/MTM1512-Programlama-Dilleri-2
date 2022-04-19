#include <stdio.h>

void F(int a, int* b) {
    a++, (*b)--;
    if(a == *b)
        return;
    
    printf("(1): %d %d\n", a, *b);
    F(a, b);
    printf("(2): %d %d\n", a, *b);
}

int main(void) {
    int a = 2, b = 8;
    F(a, &b);
    printf("x = %d y = %d\n", a, b);
}
