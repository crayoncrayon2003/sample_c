
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_MAX (10)

int main()
{
    /* variable declaration */
    int iCnt;
    int aiArrayX[ARRAY_MAX];

    /* variable initialize */
    iCnt=0;
    memset(&aiArrayX[0], 0x00, sizeof(aiArrayX) );

    /* processing */
    for(iCnt=0 ; iCnt<ARRAY_MAX ; iCnt++){
        aiArrayX[iCnt] = iCnt;
    }

    for(iCnt=ARRAY_MAX-1 ; iCnt>=0 ; iCnt--){
        printf("%d\n", aiArrayX[iCnt]);
    }

    return 0;
}

