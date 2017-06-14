#include "../mycsapp.h"

//建立与服务器的连接，该服务器运行在主机hostname上，并在端口号port上监听连接请求
//它返回一个打开的套接字描述符，该描述符准备好了，可以用Unix I/O 函数做输入和输出
int open_clientfd(char *hostname,char *port){
    int clientfd;
    struct addrinfo hints,*listp,*p;//netdb.h

    //get a list of potential server address
    memset(&hints,0,sizeof(struct addrinfo));
    hints.ai_socktype=SOCK_STREAM;
    hints.ai_flags=AI_NUMERICSERV;
    hints.ai_flags|=AI_ADDRCONFIG;
    getaddrinfo(hostname,port,&hints,&listp);

    //walk the list for one that we can successfully connect to
    for(p=listp;p;p=p->ai_next){
        //create a socket descriptor
        if((clientfd=socket(p->ai_family,p->ai_socktype,p->ai_protocol))<0)continue;

        if(connect(clientfd,p->ai_addr,p->ai_addrlen)!=-1)break;//succeed

        close(clientfd);
    }
    freeaddrinfo(listp);
    if(!p)return -1;
    else return clientfd;
}

//打开和返回一个监听描述符，这个描述符准备好在端口port上接受连接请求
int open_listenfd(char *port){
    struct addrinfo hints,*listp,*p;
    int listenfd,optval=1;

    //get a list of potential server addresses
    memset(&hints,0,sizeof(struct addrinfo));
    hints.ai_socktype=SOCK_STREAM;
    hints.ai_flags=AI_PASSIVE|AI_ADDRCONFIG;
    hints.ai_flags|=AI_NUMERICSERV;
    getaddrinfo(NULL,port,&hints,&listp);//host参数设置为NULL，
    //每个套接字地址结构中的地址字段会被设置为通配符地址，
    //告诉内核这个服务器会接收发送到本主机所有IP地址的请求。

    //walk the list for one that we can bind to
    for(p=listp;p;p=p->ai_next){
        if((listenfd=socket(p->ai_family,p->ai_socktype,p->ai_protocol))<0)continue;

        setsockopt(listenfd,SOL_SOCKET,SO_REUSEADDR,(const void*)&optval,sizeof(int));

        if(bind(listenfd,p->ai_addr,p->ai_addrlen)==0)break;//succeed
        close(listenfd);
    }    
    freeaddrinfo(listp);
    if(!p)return -1;

    if(listen(listenfd,LISTENQ)<0){
        close(listenfd);
        return -1;
    }
    return listenfd;
}