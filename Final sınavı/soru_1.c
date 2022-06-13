/*
print output of this program.

output of the program:


4 7
5 5
4 7
6 5
5 7
5
*/

#include <stdio.h>
#include <stdlib.h>

void F(int *a, int b) {
    (*a)--, b += 2;
    if (*a + b < 12) {
        printf("\n%d %d", *a, b);
        return;
    }

    (*a)--, b--;
    printf("\n%d %d", *a, b);
    F(&b, *a);
    (*a)++, b++;
    printf("\n%d %d", *a, b);
    return;
}

int main(void) {
    int b = 6;
    F(&b, b);
    printf("\n%d", b);
    return 0;
}
