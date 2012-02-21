#include <iostream>

#include "packets.h"
#include "unpack.h"
#include "player.h"

/* ethernet headers are always exactly 14 bytes */
#define SIZE_ETHERNET 14

void myCallback(u_char *param, const struct pcap_pkthdr *header, const u_char *packet) {
    const struct sniff_ethernet *ethernet; /* The ethernet header */
	const struct sniff_ip *ip; /* The IP header */
	const struct sniff_tcp *tcp; /* The TCP header */
    unsigned char *payload; /* Packet payload */
    int packet_id;
    Player* player;
    
    u_int size_ip;
	u_int size_tcp;
    
    ethernet = (struct sniff_ethernet*)(packet);
	ip = (struct sniff_ip*)(packet + SIZE_ETHERNET);
	size_ip = IP_HL(ip)*4;
	if (size_ip < 20) {
		printf("   * Invalid IP header length: %u bytes\n", size_ip);
		return;
	}
	tcp = (struct sniff_tcp*)(packet + SIZE_ETHERNET + size_ip);
	size_tcp = TH_OFF(tcp)*4;
	if (size_tcp < 20) {
		printf("   * Invalid TCP header length: %u bytes\n", size_tcp);
		return;
	}
	if (ntohs(tcp->th_dport) != 25565)
        return;
    
    player = reinterpret_cast<Player*>(param);
    
    payload = (unsigned char *)(packet + SIZE_ETHERNET + size_ip + size_tcp);
    
    packet_id = (int)payload[0];
    if ( packet_id == 11) {
        player->x = unpack_double(payload+1);
        player->y = unpack_double(payload+9);
        player->z = unpack_double(payload+25);
        std::cout << "Paquet intercepte -> " << player->x << ", " << player->y << ", " << player->z << std::endl;
    }
    
}

int main(int argc, char *argv[])
{
    pcap_t *handle;			/* Session handle */
    char *dev;			/* The device to sniff on */
    char errbuf[PCAP_ERRBUF_SIZE];	/* Error string */
    bpf_u_int32 mask;		/* Our netmask */
    bpf_u_int32 net;		/* Our IP */
    
    Player* player = new Player();
    
    /* Define the device */
    //dev = pcap_lookupdev(errbuf);
    dev = "en1";
    //dev = argv[1];
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return(2);
    }
    /* Find the properties for the device */
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }
    /* Open the session in promiscuous mode */
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return(2);
    }
    
    if( pcap_loop(handle, -1, myCallback, reinterpret_cast<u_char*>(player)) == -1) {
        fprintf(stderr, "Error while looping: %s\n", pcap_geterr(handle));
        return(2);
    }
    
    pcap_close(handle);
    return(0);
}
