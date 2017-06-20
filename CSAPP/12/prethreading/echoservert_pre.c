#include "../csapp.h"
#include "sbuf.h"

#define NTHREADS 4
#define SBUFSIZE 16

void echo_cnt(int connfd);
void *thread(void *vargp);

sbuf_t sbuf;

int main(int argc,char**argv){
    int i,listenfd,connfd;
    socklen_t clientlen;
    struct sockaddr_storage clientaddr;
    pthread_t tid;

    if(argc!=2){
        fprintf(stderr,"Usage: %s <port>\n",argv[1]);
        exit(0);
    }
    listenfd=Open_listenfd(argv[1]);

    sbuf_init(&sbuf,SBUFSIZE);
    for(i=0;i<NTHREADS;i++){
        Pthread_create(&tid,NULL,thread,NULL);
    }
    while(1){
        clientlen=sizeof(struct sockaddr_storage);
        connfd=Accept(listenfd,(SA*)&clientaddr,&clientlen);
        sbuf_insert(&sbuf,connfd);
    }
}

void *thread(void* vargp){
    Pthread_detach(pthread_self());
    while(1){
        int connfd=sbuf_remove(&sbuf);
        echo_cnt(connfd);
        Close(connfd);
    }
}