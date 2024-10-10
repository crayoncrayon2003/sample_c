#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFF_MAX (10)

int main(int argc, char** argv)
{
    /* variable declaration */
    int txFD;
    struct hostent *info;
    struct servent *serv;
    struct sockaddr_in cliantAddr;
    char *txBuf = NULL;
    ssize_t txBufLen;

    /* set ip/port */
    cliantAddr.sin_family = AF_INET;
    cliantAddr.sin_port = htons(50003);
    cliantAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    while ( 1 ){
        /* create socket */
        if((txFD = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            fprintf( stdout, "socket error\n" );
            return -1;
        }

        /* connect */
        connect(txFD, (struct sockaddr *)&cliantAddr, sizeof(struct sockaddr_in));

        /* translate message */
        if ((txBufLen = getline(&txBuf, &(size_t){BUFF_MAX}, stdin)) == EOF) {
            return 1;
        }
        if (txBuf[txBufLen-1] == '\n') {
           txBuf[--txBufLen] = '\0';
        }

        /* send */
        int cnt = send( txFD, txBuf, txBufLen, 0 );
        if ( cnt < 0 ) {
            fprintf( stdout, "send %d\n", cnt );
        }else{
            fprintf( stdout, "send %d\n", cnt );
        }

        close(txFD);
    }
    free(txBuf);

    return 0;
}