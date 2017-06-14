#include <stdio.h>
#include <arpa/inet.h>
#include <stdlib.h>
int main(int argc,char** argv){
    if(argc!=2)exit(-1);
    struct in_addr inaddr;
    int ret=0;
    int x;
    if((x=inet_pton(AF_INET,argv[1],&ret))==1){
        int y=ntohl(ret);
        printf("%#x",y);
    }
    else{
        perror("inet_pton error");
    }
    
    exit(0);
}