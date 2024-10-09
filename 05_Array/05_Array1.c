
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX (10)

int main()
{
    int iCnt;
    int aiArrayX[ARRAY_MAX];

    for(iCnt=0 ; iCnt<ARRAY_MAX ; iCnt++){
        printf("%d\n", aiArrayX[iCnt]);
    }

    return 0;
}

