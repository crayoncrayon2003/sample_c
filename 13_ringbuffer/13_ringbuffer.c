#include <stdio.h>
#include <string.h>
#include "ringbuffer.h"

void printData(char *pcBuf, int iBufSize){
	int iIdx;
	for(iIdx = 0; iIdx < iBufSize; iIdx++){
		printf("%d ", pcBuf[iIdx]);
	}
	printf("\n");
    return;
}

int main(int argc, char const *argv[])
{
    char acWriteData1[] = { 1,  2,  3};
    char acWriteData2[] = { 4,  5,  6};
    char acWriteData3[] = { 7,  8,  9};
    char acWriteData4[] = {10, 11, 12};

    char acReadData[]   = { 0, 0, 0, 0};
    int  ret=1;

    queue_t stQueue;

    /* init */
    ret = initQueue(&stQueue);
    printf("ret = %d : ",ret);
    printQueue(&stQueue);

    /* enQueue */
    ret = enQueue(&stQueue , &acWriteData1[0], sizeof(acWriteData1));
    printf("ret = %d : ",ret);
    printQueue(&stQueue);

    ret = enQueue(&stQueue , &acWriteData2[0], sizeof(acWriteData2));
    printf("ret = %d : ",ret);
    printQueue(&stQueue);

    ret = enQueue(&stQueue , &acWriteData3[0], sizeof(acWriteData3));
    printf("ret = %d : ",ret);
    printQueue(&stQueue);

    ret = enQueue(&stQueue , &acWriteData4[0], sizeof(acWriteData4));
    printf("ret = %d : ",ret);
    printQueue(&stQueue);

    /* deQueue */
    memset(&acReadData[0], 0x00, sizeof(acReadData));
    ret = deQueue(&stQueue , &acReadData[0], sizeof(acReadData));
    printf("ret = %d : ",ret);
    printQueue(&stQueue);
    printData(acReadData, sizeof(acReadData));

    memset(&acReadData[0], 0x00, sizeof(acReadData));
    ret = deQueue(&stQueue , &acReadData[0], sizeof(acReadData));
    printf("ret = %d : ",ret);
    printQueue(&stQueue);
    printData(acReadData, sizeof(acReadData));

    memset(&acReadData[0], 0x00, sizeof(acReadData));
    ret = deQueue(&stQueue , &acReadData[0], sizeof(acReadData));
    printf("ret = %d : ",ret);
    printQueue(&stQueue);
    printData(acReadData, sizeof(acReadData));

    /* enQueue */
    ret = enQueue(&stQueue , &acWriteData1[0], sizeof(acWriteData1));
    printf("ret = %d : ",ret);
    printQueue(&stQueue);

    ret = enQueue(&stQueue , &acWriteData2[0], sizeof(acWriteData2));
    printf("ret = %d : ",ret);
    printQueue(&stQueue);

    /* deQueue */
    memset(&acReadData[0], 0x00, sizeof(acReadData));
    ret = deQueue(&stQueue , &acReadData[0], sizeof(acReadData));
    printf("ret = %d : ",ret);
    printQueue(&stQueue);
    printData(acReadData, sizeof(acReadData));

    return 0;
}
