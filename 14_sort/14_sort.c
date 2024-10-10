#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SIZE_ARRAY 5
#define SIZE_STR 100

int cmpnum(const void* left, const void* right){
    int iRet = 0;
    char *a  = *(char**)left;
    char *b  = *(char**)right;

    /* > : Ascending order */
    /* < : Descending order */
    if (strcmp(a, b) < 0){
        iRet = 1;
    }
    printf("a = %s  b = %s\n", a, b);

    return iRet;
}

void printArray(char **pp2dArray, int iSize){
    int iIdx;
    for (iIdx = 0; iIdx < iSize ; iIdx++) {
        printf("%d : %s\n" , iIdx ,pp2dArray[iIdx]);
    }
}

void main (){
    /* variable declaration */
    char **pp2dArray;

    /* variable initialize */
    pp2dArray = (char **)malloc( sizeof(char *) * SIZE_ARRAY );
    for (int i = 0; i < SIZE_ARRAY ; i++) {
        pp2dArray[i] = malloc( sizeof(char) * SIZE_STR );
        memset(pp2dArray[i] , 0x00 , sizeof(char) * SIZE_STR);
    }

    /* input sample data */
    strcpy(pp2dArray[0], "dir1/dir2/filename1");
    strcpy(pp2dArray[1], "dir1/dir2/filename2");
    strcpy(pp2dArray[2], "dir1/dir2/filename3");
    strcpy(pp2dArray[3], "dir1/dir2/filename4");
    strcpy(pp2dArray[4], "dir1/dir2/filename5");

    printf("pre processing\n");
    printArray(pp2dArray, SIZE_ARRAY);

    printf("    processing\n");
    qsort(pp2dArray, SIZE_ARRAY, sizeof(char*), cmpnum);

    printf("post processing\n");
    printArray(pp2dArray, SIZE_ARRAY);

    /* variable finalize */
    for (int i = 0; i < SIZE_ARRAY ; i++) {
        free( pp2dArray[i] );
    }
    free( pp2dArray );
}