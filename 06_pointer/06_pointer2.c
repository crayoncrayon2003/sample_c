
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_MAX (10)

int main()
{
    /* variable declaration */
    int iCnt;
    int aiArrayX[ARRAY_MAX];
    int *piCnt;


    /* variable initialize */
    iCnt=0;
    for(iCnt=0 ; iCnt<ARRAY_MAX ; iCnt++){
        aiArrayX[iCnt] = iCnt;
    }

    /* processing */
    printf(" print value of Array");
    for(iCnt=0 ; iCnt<ARRAY_MAX ; iCnt++){
        printf("%d\n", aiArrayX[iCnt]);
    }

    printf(" print value of pointer ");
    for(piCnt=&aiArrayX[0] ; piCnt<(&aiArrayX[0]+ARRAY_MAX) ; piCnt++){
        printf("%d\n", *piCnt);
    }

    printf(" &aiArrayX[0] is pointer,  therefore\n");
    for(iCnt=0 ; iCnt<ARRAY_MAX ; iCnt++){
        printf("%d == %d == %d\n", aiArrayX[iCnt], *(&aiArrayX[0]+iCnt), iCnt[aiArrayX]);
    }

    return 0;
}

