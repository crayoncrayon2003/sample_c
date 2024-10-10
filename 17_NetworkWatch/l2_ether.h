#ifndef ETHER_H
#define ETHER_H

#include <stdio.h>
#include <netinet/in.h>
#include <net/ethernet.h>

char *mac_ntoa(unsigned char *d);
void printEther(struct ether_header *eth);
extern int analyserEther(const unsigned char *frame);

#endif