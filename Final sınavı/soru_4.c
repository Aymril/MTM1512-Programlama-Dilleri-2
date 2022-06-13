/*
Caesar cipher implemented on data placed in file. Substition coefficient is 1
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE* f = fopen("sample.txt", "r");
    FILE* result = fopen("encryped.txt", "w");

    if (!f || !result) {
        printf("error happened while opening files");
        exit(1);
    }

    char ch;
    while ((ch = fgetc(f)) != EOF) {
        if (ch == 'Z')
            ch = 'A';
        else if (ch == 'z')
            ch = 'a';

        else if ((ch >= 'a' && ch < 'z') || (ch >= 'A' && ch < 'Z'))
            ch += 1;

        fputc(ch, result);
    }

    fclose(f);
    fclose(result);
    return 0;
}
