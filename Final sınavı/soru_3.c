#include <stdio.h>
#include <stdlib.h>

const double pi = 3.1415;

typedef struct {
    double h;
    double r;
} Cylinder;

double Volume(Cylinder c) { return pi * c.r * c.r * c.h; }

Cylinder maxSurfaceArea(Cylinder c1, Cylinder c2) {
    double result1 = 2 * pi * c1.r * (c1.r + c1.h);
    double result2 = 2 * pi * c2.r * (c2.r + c2.h);
    if (result1 >= result2) return c1;
    return c2;
}

int main(void) {
    //
    return 0;
}
