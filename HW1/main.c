
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    double x;
    double y;
    double z;
} Vector;

void print_vector(const Vector v);
Vector sum(const Vector v1, const Vector v2);
Vector diff(const Vector v1, const Vector v2);
double dot_product(const Vector v1, const Vector v2);
Vector cross_product(const Vector v1, const Vector v2);
double norm(const Vector v);
int is_unitvector(const Vector v);
Vector unit(const Vector v);
Vector multiplyby_scalar(const Vector v1, const double c);
double angle(const Vector v1, const Vector v2);
double distance(const Vector v1, const Vector v2);
int are_linearly_independent(const Vector v1, const Vector v2, const Vector v3);
int are_orthogonal(const Vector v1, const Vector v2, const Vector v3);
int are_orthonormal(const Vector v1, const Vector v2, const Vector v3);
Vector projection(const Vector v1, const Vector v2);
Vector orthogonal_projection(const Vector v1, const Vector v2);
int convert_2_orthogonal_basis(Vector *v1, Vector *v2, Vector *v3);
char *vector2str(const Vector v);  //+

void print_vector(const Vector v) {
    printf("(%.2f, %.2f, %.2f)\n", v.x, v.y, v.z);
}

Vector sum(const Vector v1, const Vector v2) {
    Vector result = {(v1.x + v2.x), (v1.y + v2.y), (v1.z + v2.z)};
    return result;
}

Vector diff(const Vector v1, const Vector v2) {
    Vector result = {(v1.x - v2.x), (v1.y - v2.y), (v1.z - v2.z)};
    return result;
}

Vector multiplyby_scalar(const Vector v1, const double c) {
    Vector result = {(v1.x * c), (v1.y * c), (v1.z * c)};
    return result;
}

double dot_product(const Vector v1, const Vector v2) {
    double result = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
    return result;
}

double norm(const Vector v) {
    double result = sqrt(dot_product(v, v));
    return result;
}

int is_unitvector(const Vector v) { return (norm(v) == 1.); }

Vector unit(const Vector v) {
    double norm_of_v = norm(v);
    // assumed nonzero norm
    Vector result = multiplyby_scalar(v, 1. / norm_of_v);
    return result;
}

double distance(const Vector v1, const Vector v2) {
    double result = norm(diff(v1, v2));
    return result;
}

double angle(const Vector v1, const Vector v2) {
    double dotPro = dot_product(v1, v2);
    double normPro = norm(v1) * norm(v2);
    double result = acos(dotPro / normPro);
    return result;
}

Vector cross_product(const Vector v1, const Vector v2) {
    Vector result;
    result.x = v1.y * v2.z - v1.z * v2.y;
    result.y = v1.z * v2.x - v1.x * v2.z;
    result.z = v1.x * v2.y - v1.y * v2.x;
    return result;
}

int are_orthogonal(const Vector v1, const Vector v2, const Vector v3) {
    double d1 = dot_product(v1, v2);
    double d2 = dot_product(v1, v3);
    double d3 = dot_product(v2, v3);
    if (d1 == 0 && d2 == 0 && d3 == 0) return 1;
    return 0;
}

int are_orthonormal(const Vector v1, const Vector v2, const Vector v3) {
    if (are_orthogonal(v1, v2, v3) && is_unitvector(v1) && is_unitvector(v2) &&
        is_unitvector(v3))
        return 1;
    return 0;
}

Vector projection(const Vector v1, const Vector v2) {
    Vector result;
    Vector numerator = multiplyby_scalar(v2, dot_product(v1, v2));
    double denominator = norm(v2) * norm(v2);
    result.x = numerator.x / denominator;
    result.y = numerator.y / denominator;
    result.z = numerator.z / denominator;
    return result;
}

Vector orthogonal_projection(const Vector v1, const Vector v2) {
    Vector result = diff(v1, projection(v1, v2));
    return result;
}

char *vector2str(const Vector v) {
    char *buffer = (char *)malloc(sizeof(char) * 15);
    sprintf(buffer, "(%.2f, %.2f, %.2f)", v.x, v.y, v.z);
    return buffer;
}

int are_linearly_independent(const Vector v1, const Vector v2,
                             const Vector v3) {
    double result = v1.x * (v2.y * v3.z - v2.z * v3.y) -
                    v2.x * (v1.y * v3.z - v1.z * v3.y) +
                    v3.x * (v1.y * v2.z - v1.z * v2.y);
    return result ? 1 : 0;
}

int convert_2_orthogonal_basis(Vector *v1, Vector *v2, Vector *v3) {
    if (!are_linearly_independent(*v1, *v2, *v3)) return 0;

    *v2 = diff(*v2, projection(*v2, *v1));

    *v3 = diff(diff(*v3, projection(*v3, *v1)), projection(*v3, *v2));

    return 1;
}

int main() {
    Vector v1 = {1, 2, 2}, v2 = {-1, 0, 2}, v3 = {0, 0, 1};
    double k = 2;
    printf("k is %2.f\n", k);

    printf("v1 = ");
    print_vector(v1);
    printf("v2 = ");
    print_vector(v2);
    printf("v3 = ");
    print_vector(v3);

    printf("v1 + v2 = ");
    print_vector(sum(v1, v2));

    printf("v1 - v2 = ");
    print_vector(diff(v1, v2));

    printf("k * v1  = ");
    print_vector(multiplyby_scalar(v1, k));

    printf("v1 . v2 = %.2lf\n", dot_product(v1, v2));

    printf("v1 x v2 = ");
    print_vector(cross_product(v1, v2));

    printf("| v1 |  = %.2lf\n", norm(v1));

    if (is_unitvector(v1))
        printf("v1 is a unit vector.\n");
    else
        printf("v1 is not unit vector.\n");

    printf("unit( v1 ) = ");
    print_vector(unit(v1));

    printf("angle(v1, v2) = %.2lf\n", angle(v1, v2));

    printf("distance(v1, v2) = %.2lf\n", distance(v1, v2));

    if (are_linearly_independent(v1, v2, v3))
        printf("Vectors are linearly independent.\n");

    else
        printf("Vectors are not linearly independent.\n");

    if (are_orthogonal(v1, v2, v3))
        printf("Vectors are orthogonal.\n");
    else
        printf("Vectors are not orthogonal.\n");

    if (are_orthonormal(v1, v2, v3))
        printf("Vectors are orthonormal.\n");
    else
        printf("Vectors are not orthonormal.\n");

    printf("Projection of v1 onto v2 is = ");
    print_vector(projection(v1, v2));

    printf("Orthogonal projection of v1 onto v2 is = ");
    print_vector(orthogonal_projection(v1, v2));

    if (convert_2_orthogonal_basis(&v1, &v2, &v3)) {
        printf("Orthogonalization of vectors:\n");
        printf("v1 = ");
        print_vector(v1);
        printf("v2 = ");
        print_vector(v2);
        printf("v3 = ");
        print_vector(v3);
    }

    puts(vector2str(v1));

    return 0;
}
