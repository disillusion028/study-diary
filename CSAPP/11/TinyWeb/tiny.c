//A simple, iterative HTTP/1.0 Web server that uses the GET method to serve static and dynamic content
#include "../../mycsapp.h"
void doit(int fd);
void read_requesthdrs(rio_t *rp);
int parse_uri(char *uri,char *filename,char* cgiargs);
void serve_static(int fd,char *filename,int filesize);
void get_filetype(char* filename,char *filetype);
void serve_dynamic(int fd,char *filename,char* cgiargs);
void clienterror(int fd,char * cause,char* errnum,char *shortmsg,char* longmsg);

int main(int argc,char **argv){
    int listenfd,connfd;
    char hostname[MAXLINE],port[MAXLINE];
    socklen_t clientlen;
    struct sockaddr_storage clientaddr;
    
    if(argc!=2){
        fprintf(stderr,"usage: %s <port>\n",argv[0]);
        exit(1);
    }
    listenfd=open_listenfd(argv[1]);
    while(1){
        clientlen=sizeof(clientaddr);
        connfd=accept(listenfd,(SA*)&clientaddr,&clientlen);
        getnameinfo((SA*)&clientaddr,clientlen,hostname,MAXLINE,port,MAXLINE,0);
        printf("Accepted connection from (%s %s)\n",hostname,port);
        doit(connfd);
        close(connfd);
    }
}
//将URI解析为一个文件名和一个可能为空的CGI参数字符串。并且设置一个标志，表明请求的是静态内容还是动态内容，
//如果文件在磁盘上不存在，我们立即发送一个错误信息给客户端并返回。

void doit(int fd){
    int is_static;
    struct stat sbuf;
    char buf[MAXLINE],method[MAXLINE],uri[MAXLINE],version[MAXLINE];
    char filename[MAXLINE],cgiargs[MAXLINE];
    rio_t rio;

    //read request line and headers
    rio_readinitb(&rio,fd);
    rio_readlineb(&rio,buf,MAXLINE);
    printf("request headers:\n");
    printf("%s",buf);
    sscanf(buf,"%s %s %s",method,uri,version);
    if(strcasecmp(method,"GET")){
        clienterror(fd,method,"501","Not implemented","Tiny does not implement this method");
        return;
    }
    read()
}