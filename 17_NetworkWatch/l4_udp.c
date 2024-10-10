#include "l4_udp.h"

void printUdp(struct udphdr *ptr){
	printf(" UDP PORT: %u    \t\t=> %u \n",ntohs(ptr->source), ntohs(ptr->dest));
}

int analyserUdp(const unsigned char *frame){
    struct udphdr *udp;
    udp = (struct udphdr *)frame;
    printUdp(udp);
}