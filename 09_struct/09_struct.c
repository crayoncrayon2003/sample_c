#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned long  ulVarV;  // 4 byte  4-byte boundary
    unsigned long  ulVarW;  // 4 byte  4-byte boundary
    unsigned short usVarX;  // 2 byte
    unsigned short usVarY;  // 2 byte  4-byte boundary
    unsigned short usVarZ;  // 2 byte
    unsigned short dummy;   // 2 byte  4-byte boundary, tis is Alignment
} point;

int main()
{
    point stPoint = {1, 2, 3, 4, 5, 0};
    printf("%ld\n", stPoint.ulVarV);
    printf("%ld\n", stPoint.ulVarV);
    printf("%d\n", stPoint.usVarX);
    printf("%d\n", stPoint.usVarY);

    printf("%ld\n", sizeof(stPoint));

    return 0;
}

