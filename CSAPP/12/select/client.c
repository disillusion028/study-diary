#include "../csapp.h"


int main(int argc, char **argv){
    int clientfd;
    char *host,*port,buf[MAXLINE];
    rio_t rio;

    if(argc!=3){
        fprintf(stderr,"useage: %s <host> <port>\n",argv[0]);
        exit(0);
    }
    host = argv[1];
    port = argv[2];

    if(-1==(clientfd=open_clientfd(host,port))){
        fprintf(stderr,"can't connect to %s : %s<host> :<port>\n",argv[1],argv[2]);
        exit(0);
    }
    rio_readinitb(&rio,clientfd);
    FILE *ftest=Fopen("testvalues.txt","r");
    while(fgets(buf,MAXLINE,ftest)!=NULL){
        //strcat(buf,"\n");
        rio_writen(clientfd,buf,strlen(buf));
        //rio_readlineb(&rio,buf,MAXLINE);
        //fputs(buf,stdout);
    }
    close(clientfd);
    exit(0);
}