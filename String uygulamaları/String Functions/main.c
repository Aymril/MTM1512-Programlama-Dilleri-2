#include <stdio.h>

int my_strlenIter(const char* str) {
    int count = 0;
    while (*str) ++count;
    return count;
}

int my_strlenRec(const char* str) {
    if (!*str) return 0;
    return 1 + my_strlenRec(str + 1);
}

char* my_strcatIter(char* dest, const char* source) {
    char* p = dest;
    while (*dest) ++dest;
    while (*dest++ = *source++)
        ;
    return p;
}

void my_strcatRec(char* dest, const char* source) {
    if (*dest)
        my_strcatRec(++dest, source);
    else if (*dest = *source)
        my_strcatRec(++dest, ++source);
}

int my_strcmpRec(const char* str1, const char* str2) {
    if (*str1 != *str2) return *str1 - *str2;

    return (!*str1) ? 0 : my_strcmpRec(++str1, ++str2);
}

int my_strcmpIter(const char* str1, const char* str2) {
    while (*str1 && *str1 == *str2) {
        ++str1, ++str2;
    }
    return (*str1 > *str2) - (*str1 < *str2);
}

char* my_strcpyIter(char* dest, const char* source) {
    char* p = dest;
    while (*dest++ = *source++)
        ;
    return p;
}

void my_strcpyRec(char* dest, const char* source) {
    if (*dest = *source) my_strcpyRec(++dest, ++source);
    return;
}

char* my_strNcpyIter(char* dest, const char* source, size_t N) {
    if(dest == NULL)
        return dest;
    char* p = dest;
    for (size_t i = N; i > 0 && (*dest++ = *source++); --i)
        ;
    *dest = 0;
    return p;
}

void my_strNcpyRec(char* dest, const char* source, size_t N) {
    if (N <= 0) {
        *dest = 0;
        return;
    }
    if (*dest = *source) return my_strNcpyRec(++dest, ++source, --N);
}

int main(void) {
    //    int arr[2][2] = { {1,1}, {2,3} };
    char str[100] = "asgafhssss";
    char source[] = "5";
    my_strNcpyRec(str, source, -5);
    printf("%s\n", str);
    return 0;
}
