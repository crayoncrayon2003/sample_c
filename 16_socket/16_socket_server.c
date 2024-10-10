#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFF_MAX (100)

int main(int argc, char** argv)
{
    /* variable declaration */
    int rxFD;
    int txFD;
    struct servent *serv;
    struct sockaddr_in serverAddr;
    struct sockaddr_in cliantAddr;
    socklen_t len = sizeof(struct sockaddr_in);
    char rxBuf[BUFF_MAX];

    /* variable initialize */
    /* recive buffer */
    memset(rxBuf, 0x00, sizeof(rxBuf));
    /* create socket */
    if (( rxFD = socket(AF_INET, SOCK_STREAM, 0 )) < 0 ) {
        fprintf( stdout, "socket error : fd = %d\n", rxFD );
        return -1;
    }

    /* set ip/port */
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(50003);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    /* bind */
    if ( bind( rxFD, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0 ) {
        fprintf( stdout, "bind error\n" );
        return -1;
    }

    /* listen state, connection 1 */
    if ( listen( rxFD, 1 ) < 0 ) {
        fprintf( stdout, "listen error\n" );
        return -1;
    }

    while ( 1 ) {
        /* accept */
        if (( txFD = accept(rxFD, (struct sockaddr *)&cliantAddr, &len )) < 0 ) {
            fprintf( stdout, "accept error : fd2 = %d\n", txFD );
            return -1;
        }

        /* recv */
        if ( recv( txFD, rxBuf, sizeof(rxBuf), 0 ) < 0 ) {
            fprintf( stdout, "recv");
            return -1;
        }

        /* output */
        fprintf( stdout, "%s\n", rxBuf );
        memset(rxBuf, 0x00, sizeof(rxBuf));

        close(txFD);
    }

    close(rxFD);

    return 0;
}