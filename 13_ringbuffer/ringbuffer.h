
enum e_queue_status{
	E_QUEUE_STATUS_EMPTY,
	E_QUEUE_STATUS_AVAILABLE,
	E_QUEUE_STATUS_FULL
};
#define QUEUE_SIZE (10)

#define QUEUE_NG (0)
#define QUEUE_OK (1)

typedef struct {
	int head;
	int tail;
    int freeSize;
	int flag;
	char data[QUEUE_SIZE];
}queue_t;

void printQueue(queue_t* pQueue);
int initQueue(queue_t* pQueue);
int enQueue(queue_t* pQueue, char *pcBuf, int iBufSize);
int deQueue(queue_t* pQueue, char *pcBuf, int iBufSize);