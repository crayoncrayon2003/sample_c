#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

struct bitfeeld{
    unsigned a: 1;
    unsigned b: 2;
    unsigned c: 1;
    unsigned d: 4;
};

int main(){
    unsigned char ucInitialValue = 0x6E;
    struct bitfeeld ucVar;

    memcpy(&ucVar, &ucInitialValue, sizeof(ucInitialValue));
    printf("%x \n", ucVar.a);
    printf("%x \n", ucVar.b);
    printf("%x \n", ucVar.c);
    printf("%x \n", ucVar.d);
    printf("\n");
    /* 0x6b         :  0 1 1 0 1 1 1 0 */
    /* Big-endian   :  a b b c d d d d */
    /* Little-endian:  d d d d c b b a */

    return 0;
}