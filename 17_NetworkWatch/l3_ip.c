#include "l3_ip.h"
#include "l4_tcp.h"
#include "l4_udp.h"

char *ip_ntoa(u_int32_t ip){
	unsigned char *d = (unsigned char *)&ip;
	static char str[15];
	sprintf(str,"%d.%d.%d.%d",d[0],d[1],d[2],d[3]);
	return str;
}

void printIp(struct iphdr *ip){
    printf("     IP  : %s \t=> %s\n",ip_ntoa(ip->saddr), ip_ntoa(ip->daddr));
}

int analyserIp(const unsigned char *frame){
    struct iphdr *ip;
    unsigned char *upper_protocol;
    ip = (struct iphdr *)frame;
    printIp(ip);

    upper_protocol = ((unsigned char *)frame + sizeof(struct iphdr));
    switch(ip->protocol){
        case IP_ICMP:
            printf("\nIP protocol ICMP analyse stop\n");
            break;
        case IP_TCP:
            analyserTcp(upper_protocol);
            break;
        case IP_UDP:
            analyserUdp(upper_protocol);
            break;
        default:
            printf("\nIP protocol unknown analyse stop\n");
    }
}