
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX (10)

int main()
{
    char cChar = 'a';
    char *pcString = "abcd";

    printf("%c\n", cChar);
    printf("%s\n", &pcString[0]);


    return 0;
}

