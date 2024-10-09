

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int iCnt = 0;

    printf("------- if ------\n");
    for(iCnt=0 ; iCnt<5 ; iCnt++){
        if (1 == iCnt) {
            printf("One\n");
        } else if(2 == iCnt) {
            printf("Two\n");
        } else {
            printf("Other\n");
        }
    }

    printf("------- swhitch ------\n");
    for(iCnt=0 ; iCnt<5 ; iCnt++){
        switch (iCnt) {
        case 1:
            printf("One\n");
            break;
        case 2:
            printf("Two\n");
            break;
        default:
            printf("Other\n");
            break;
        }
    }


    return 0;
}

