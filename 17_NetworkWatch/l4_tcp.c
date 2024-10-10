#include "l4_tcp.h"

void printTcp(struct tcphdr *ptr){
	printf(" TCP PORT: %u    \t\t=> %u \n",ntohs(ptr->source),ntohs(ptr->dest));
}

int analyserTcp(const unsigned char *frame){
    struct tcphdr *tcp;
    tcp = (struct tcphdr *)frame;
    printTcp(tcp);
}