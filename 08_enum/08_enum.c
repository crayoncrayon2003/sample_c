#include <stdio.h>
#include <stdlib.h>

enum
{
    E_COLOR_RED,
    E_COLOR_GREEN,
    E_COLOR_BLUE,
};
enum
{
    E_IDENTIFIER_101 = 101,
    E_IDENTIFIER_102,
    E_IDENTIFIER_103,
    E_IDENTIFIER_201 = 201,
    E_IDENTIFIER_202,
    E_IDENTIFIER_203,
};

int main()
{
    char cChar = 'a';
    char *pcString = "abcd";

    printf("COLORs\n");
    printf("%d\n", E_COLOR_RED);
    printf("%d\n", E_COLOR_GREEN);
    printf("%d\n", E_COLOR_BLUE);

    printf("IDENTIFIERs\n");
    printf("%d\n", E_IDENTIFIER_103);
    printf("%d\n", E_IDENTIFIER_203);

    return 0;
}

