
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX (10)

int main()
{
    int iCnt   = 0;
    int *piCnt = &iCnt;

    printf("tihis is value   of iCnt %d\n",  iCnt);
    printf("tihis is address of iCnt %p\n", &iCnt);

    printf("tihis is value   of iCnt %d\n", *piCnt);
    printf("tihis is address of iCnt %p\n",  piCnt);

    return 0;
}

