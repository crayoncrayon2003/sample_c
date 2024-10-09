#include <stdio.h>
#include <stdlib.h>

int main()
{
    int iVarX = 1;
    float iVarY = 2.222222222222;
    const int iVarZ = iVarX + (int)iVarY;

    printf("x=%d y=%.2f z=%d\n",iVarX, iVarY, iVarZ);

    return 0;
}