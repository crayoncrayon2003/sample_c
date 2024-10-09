#include <stdio.h>
#include <stdlib.h>

/* 関数プロトタイプ */
static int add(int iVarX, int iVarY);
static int sub(int iVarX, int iVarY);
int mul(int iVarX, int iVarY);
int dvi(int iVarX, int iVarY);

static int add(int iVarX, int iVarY){
    return iVarX + iVarY;
}
static int sub(int iVarX, int iVarY){
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

int main(){
    int iVarX = 10;
    int iVarY = 5;
    int iVarZ = 0;

    iVarZ = add(iVarX, iVarY);
    printf("add = %d\n", iVarZ);

    iVarZ = sub(iVarX, iVarY);
    printf("sub = %d\n", iVarZ);

    iVarZ = mul(iVarX, iVarY);
    printf("mul = %d\n", iVarZ);

    iVarZ = dvi(iVarX, iVarY);
    printf("mul = %d\n", iVarZ);

    return 0;
}