
#include "l2_ether.h"
#include "l3_ip.h"

char *mac_ntoa(unsigned char *d){
    static char str[18];
    sprintf(str,"%02x:%02x:%02x:%02x:%02x:%02x",d[0],d[1],d[2],d[3],d[4],d[5]);
    return str;
}

void printEther(struct ether_header *eth){
    printf("     MAC : %17s \t=> %17s \n",mac_ntoa(eth->ether_dhost), mac_ntoa(eth->ether_shost));
}

int analyserEther(const unsigned char *frame){
    struct ether_header *eth;
    unsigned char *next_protocol;
    eth = (struct ether_header *)frame;
    printEther(eth);

    next_protocol = ((unsigned char *)frame + sizeof(struct ether_header));
    switch(ntohs(eth->ether_type)){
        case ETH_P_IP:
            analyserIp(next_protocol);
            break;
        case ETH_P_IPV6:
            printf("\nEther Type IPv6 analyse stop \n");
            break;
        case ETH_P_ARP:
            printf("\nEther Type ARP analyse stop \n");
            break;
        default:
            printf("\nEther Type unknown analyse stop\n");
    }

}