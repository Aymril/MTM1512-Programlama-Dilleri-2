#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Find_CharRec(const char* A, char ch) {
    if (!*A) return 0;
    return Find_CharRec(++A, ch) + (*A == ch) ? 1 : 0;
}

int Find_CharIter(const char* A, char ch) {
    int count = 0;
    while (*A) {
        if (*A == ch) ++count;
        ++A;
    }
    return count;
}

int strlenn(const char* A) {
    if (!*A) return 0;
    return 1 + strlenn(++A);
}

void toLowerCaseRec(char* str) {
    if (!*str) return;
    if (*str >= 'A' && *str <= 'Z') *str += 32;
    toLowerCaseRec(++str);
}

void toLowerCaseIter(char* str) {
    for (; *str; ++str)
        if (*str >= 'A' && *str <= 'Z') *str += 32;
}

void toUpperCaseRec(char* str) {
    if (!*str) return;
    if (*str >= 'a' && *str <= 'z') *str -= 32;
    toUpperCaseRec(++str);
}

void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void str_Reverse(char* str, int length) {
    for (int i = 0, j = length - 1; i <= j; ++i, --j) {
        swap(&str[i], &str[j]);
    }
}

// str_Reverse function is a special case of str_Reverse_firstN
// function, where we take first 'length' characters of str.

void str_Reverse_firstN(char* str, int N) {
    if (N >= strlenn(str)) N = strlenn(str);
    for (int i = 0, j = N - 1; i <= j; ++i, --j) {
        swap(&str[i], &str[j]);
    }
}

void myStrCpyIter(char* destination, const char* source) {
    while (*destination++ = *source++)
        ;
}

void myStrCpyRec(char* destination, const char* source) {
    *destination = *source;
    if (!*destination) return;
    myStrCpyRec(++destination, ++source);
}

char* firstOccurence(char* str, char ch) {
    int length = strlenn(str);
    for (int i = 0; i <= length; ++i) {
        if (str[i] == ch) return &str[i];
    }
    return NULL;
}

char* LastOccurence(char* str, char ch) {
    int length = strlenn(str);
    for (int i = length - 1; i >= 0; --i) {
        if (str[i] == ch) return &str[i];
    }
    return NULL;
}

char* FirstOccuredString(char* str, char* searched, int length) {
    for (int i = 0; str[i]; ++i) {
        if (str[i] == searched[0]) {
            if (strncmp(searched, &str[i], length) == 0) return &str[i];
        }
    }
    return NULL;
}

int main(void) {
    char temp[50] = "Imral Okyar";
    char s[50] = "Imral Ok";
    int length = strlenn(s);

    char* p = FirstOccuredString(temp, s, length);

    if (p) printf("%s\n", p);

    return 0;
}
