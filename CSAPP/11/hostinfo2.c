#include "../mycsapp.h"

int main(int argc, char ** argv){
    //just like nslookup
    struct addrinfo *p,*listp,hints;
    char buf[MAXLINE];
    int rc,flags;
    if(argc != 2){
        fprintf(stderr,"usage: %s <domain name>\n",argv[0]);
        exit(0);
    }

    memset(&hints,0,sizeof(struct addrinfo));
    hints.ai_family=AF_INET;
    hints.ai_socktype=SOCK_STREAM;//将列表限制为对每个地址最多一个addrinfo结构，该结构的套接字地址可以作为链接的一个端点。

    if((rc=getaddrinfo(argv[1],NULL,&hints,&listp))!=0){
        fprintf(stderr,"getaddrinfo error: %s\n",gai_strerror(rc));
        exit(1);
    }

    //walk the list and display each IP address
    flags=NI_NUMERICHOST;
    void *saddr=NULL;
    struct sockaddr_in *sain=NULL;
    struct in_addr *inaddr=NULL;
    uint32_t *ut=NULL;
    char buf2[20];
    for(p=listp;p;p=p->ai_next){
        memset(buf2,0,20);
        saddr=p->ai_addr;
        sain=saddr;
        inaddr=&sain->sin_addr;
        //uint32_t aaa=htonl(inaddr->s_addr);
        ut=&inaddr->s_addr;
        inet_ntop(AF_INET,ut,buf2,20);
        printf("%s\n",buf2);
    }
    freeaddrinfo(listp);
    exit(0);
}