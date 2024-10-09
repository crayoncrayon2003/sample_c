#include <stdio.h>
#include <stdlib.h>

typedef union {
    struct {
        unsigned long  ulVarX;  // 4 byte
    } one;
    struct {
        unsigned short usVarY;  // 2 byte
        unsigned short usVarZ;  // 2 byte
    } two;
} point;

int main()
{
    point stPoint = {0x12345678};
    printf("%lx\n", stPoint.one.ulVarX);
    printf("%x \n", stPoint.two.usVarY);
    printf("%x \n", stPoint.two.usVarZ);
    /* アドレス     : 0x00  0x01  0x02  0x03 */
    /* Big-endian   : 0x12  0x34  0x56  0x78 */
    /* Little-endian: 0x78  0x56  0x34  0x12 */

    return 0;
}

