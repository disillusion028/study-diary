#include <stdio.h>
#include <arpa/inet.h>
#include <stdlib.h>
#define MAXBUF 20
int main(int argc,char ** argv){
    if(argc!=2)exit(-1);
    struct in_addr inaddr;
    uint32_t addr;
    char buf[MAXBUF];

    sscanf(argv[1],"%x",&addr);
    inaddr.s_addr=htonl(addr);

    if(!inet_ntop(AF_INET,&inaddr,buf,MAXBUF)){
        perror("inet_ntop");
        exit(-1);
    }
    printf("%s\n",buf);
    exit(0);
}