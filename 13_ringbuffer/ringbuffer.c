#include <stdio.h>
#include <string.h>
#include "ringbuffer.h"

void printQueue(queue_t* pstQueue){
	int iIdx;
	for(iIdx = 0; iIdx < QUEUE_SIZE ; iIdx++){
		printf("%d ", pstQueue->data[iIdx]);
	}
    printf(" : flag     = %d ", pstQueue->flag);
    printf(" : head     = %d ", pstQueue->head);
    printf(" : tail     = %d ", pstQueue->tail);
    printf(" : freeSize = %d ", pstQueue->freeSize);
	printf("\n");

    return;
}

int initQueue(queue_t* pstQueue){
    pstQueue->flag = E_QUEUE_STATUS_EMPTY;
    pstQueue->head = 0;
    pstQueue->tail = 0;
    pstQueue->freeSize = QUEUE_SIZE;
    memset(&pstQueue->data[0], 0x00, QUEUE_SIZE);

    return QUEUE_OK;
}

int enQueue(queue_t *pstQueue , char *pcBuf, int iBufSize){
    int iIdx;
    int iInterimEndSize;
    char *pcInterimTopBuf;
    int   iInterimTopSize;

	/* check arguments */
	if(pstQueue->flag == E_QUEUE_STATUS_FULL){
		return QUEUE_NG;
	}

    if( iBufSize > pstQueue->freeSize){
        return QUEUE_NG;
    }

	/* enQueue */
    iIdx = pstQueue->tail + iBufSize;
    if ( iIdx < QUEUE_SIZE ) {
        memcpy(&pstQueue->data[pstQueue->tail], &pcBuf[0], iBufSize);
        pstQueue->tail     += iBufSize;
        pstQueue->freeSize -= iBufSize;
    }else{
        iInterimEndSize = iIdx - QUEUE_SIZE-1;
        memcpy(&pstQueue->data[pstQueue->tail], &pcBuf[0], iInterimEndSize);
        pcInterimTopBuf = ( pcBuf    + iInterimEndSize );
        iInterimTopSize = ( iBufSize - iInterimEndSize );
        memcpy(&pstQueue->data[0], &pcInterimTopBuf[0], iInterimTopSize);
        pstQueue->tail      = iInterimTopSize;
        pstQueue->freeSize -= iBufSize;
    }

	/* chage queue status */
	if(pstQueue->tail == pstQueue->head){
		pstQueue->flag = E_QUEUE_STATUS_FULL;
	}else{
		pstQueue->flag = E_QUEUE_STATUS_AVAILABLE;
	}

    return QUEUE_OK;
}

int deQueue(queue_t* pstQueue, char *pcBuf, int iBufSize){
    int iIdx;
    int iInterimEndSize;
    char *pcInterimTopBuf;
    int   iInterimTopSize;

	/* check arguments */
	if(pstQueue->flag == E_QUEUE_STATUS_EMPTY){
		return QUEUE_NG;
	}

    if( iBufSize > (QUEUE_SIZE - pstQueue->freeSize)) {
        return QUEUE_NG;
    }

	/* deQueue */
    iIdx = pstQueue->head + iBufSize;
    if ( iIdx < QUEUE_SIZE) {
        memcpy(&pcBuf[0], &pstQueue->data[pstQueue->head], iBufSize);
        memset(&pstQueue->data[pstQueue->head], 0x00, iBufSize);
        pstQueue->head     += iBufSize;
        pstQueue->freeSize += iBufSize;
    }else{
        iInterimEndSize = iIdx - QUEUE_SIZE;
        memcpy(&pcBuf[0], &pstQueue->data[pstQueue->head], iInterimEndSize);
        memset(&pstQueue->data[pstQueue->head], 0x00, iInterimEndSize);
        pcInterimTopBuf = (pcBuf    + iInterimEndSize );
        iInterimTopSize = (iBufSize - iInterimEndSize );
        memcpy(&pcBuf[iInterimEndSize], &pstQueue->data[0], iInterimTopSize);
        memset(&pstQueue->data[0]  ,      0x00, iInterimTopSize);
        pstQueue->head      = iInterimTopSize;
        pstQueue->freeSize += iBufSize;
    }

	/* chage queue status */
	if(pstQueue->tail == pstQueue->head){
		pstQueue->flag = E_QUEUE_STATUS_EMPTY;
	}else{
		pstQueue->flag = E_QUEUE_STATUS_AVAILABLE;
	}

    return QUEUE_OK;
}
