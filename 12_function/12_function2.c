#include <stdio.h>
#include <stdlib.h>

/* 関数プロトタイプ */
int add(int iVarX, int iVarY);
int sub(int iVarX, int iVarY);
int mul(int iVarX, int iVarY);
int dvi(int iVarX, int iVarY);

/* 関数テーブル */
typedef struct {
    char *name;
    int  (*func)(int iVarX, int iVarY);
}stCmd;

stCmd stCmdList[] = {
    {"add", add},
    {"sub", sub},
    {"mul", sub},
    {"dvi", dvi},
};

/* 関数 */
int add(int iVarX, int iVarY){
    return iVarX + iVarY;
}
int sub(int iVarX, int iVarY){
    return iVarX - iVarY;
}
int mul(int iVarX, int iVarY){
    return iVarX * iVarY;
}
int dvi(int iVarX, int iVarY){
    int iVarZ = 0;
    if(0!=iVarY){
        iVarZ = iVarX / iVarY;
    }
    return iVarZ;
}

int (*p_func)(int, int);
int main(){
    int iVarX = 10;
    int iVarY = 5;
    int iVarZ = 0;
    int iCnt  = 0;

    for(iCnt=0 ; iCnt<sizeof(stCmdList)/sizeof(stCmd); iCnt++){
        iVarZ = stCmdList[iCnt].func(iVarX,iVarY);
        printf("%s = %d\n", &stCmdList[iCnt].name[0], iVarZ);
    }

    return 0;
}