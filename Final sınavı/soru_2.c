/*
this program converts lower case letters to upper ones, such as:

string -> STRING
Int -> INT
*/

#include <stdio.h>
#include <stdlib.h>


void F(char *S) {
    if(*S == '\0')
      return;

    if(*S >= 'a' && *S <= 'z')
      *S -= 32;

    F(S + 1);
}

int main(void)
{
    char S[50] = "Hi there!";
    puts(S);
    F(S);
    puts(S);
    return 0;
}
