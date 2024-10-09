
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int iCnt = 0;

    printf("-------forループ ascending order------\n");
    for(iCnt=0 ; iCnt<10 ; iCnt++){
        printf("%d\n", iCnt);
    }

    printf("-------forループ descending order------\n");
    for(iCnt=10 ; iCnt>=0 ; iCnt--){
        printf("%d\n", iCnt);
    }

    printf("-------whileループ ------\n");
    iCnt = 0;
    while ( iCnt<10 )
    {
        printf("%d\n", iCnt);
        iCnt++;
    }

    printf("-------do whileループ ------\n");
    iCnt = 0;
    do{
        printf("%d\n", iCnt);
        iCnt++;
    }while (iCnt<10);

    return 0;
}
