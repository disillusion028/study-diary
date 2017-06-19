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
        //printf("before accept\n");
        connfd=Accept(listenfd,(SA*)&clientaddr,&clientlen);
        //printf("connfd:  %d\n",connfd);
        getnameinfo((SA*)&clientaddr,clientlen,hostname,MAXLINE,port,MAXLINE,0);
        printf("Accepted connection from (%s %s)\n",hostname,port);
        doit(connfd);
        //fflush(stdout);
        close(connfd);
        //shutdown(connfd,SHUT_RDWR);
    }
}

//将URI解析为一个文件名和一个可能为空的CGI参数字符串。并且设置一个标志，表明请求的是静态内容还是动态内容，
//如果文件在磁盘上不存在，我们立即发送一个错误信息404给客户端并返回。
//判断文件需求的权限，权限不满足则返回错误码403  
void doit(int fd){
    int is_static;
    struct stat sbuf;
    char buf[MAXLINE],method[MAXLINE],uri[MAXLINE],version[MAXLINE];
    char filename[MAXLINE],cgiargs[MAXLINE];
    rio_t rio;

    //read request line and headers
    rio_readinitb(&rio,fd);
    rio_readlineb(&rio,buf,MAXLINE);
    //printf("request headers:\n");
    printf("%s",buf);
    sscanf(buf,"%s %s %s",method,uri,version);
    if(strcasecmp(method,"GET")){
        clienterror(fd,method,"501","Not implemented","Tiny does not implement this method");
        return;
    }
    read_requesthdrs(&rio);

    //parse URI from GET request
    is_static=parse_uri(uri,filename,cgiargs);
    if(stat(filename,&sbuf)<0){
        clienterror(fd,filename,"404","Not Found","Tiny couldn't find this file");
        return;
    }

    if(is_static){
        if(!(S_ISREG(sbuf.st_mode))||!(S_IRUSR&sbuf.st_mode)){
            clienterror(fd,filename,"403","Forbidden","Tiny couldn't read the file");
            return;
        }
        //printf("before serve_static");
        serve_static(fd,filename,sbuf.st_size);
    }
    else{
        if(!(S_ISREG(sbuf.st_mode))||!(S_IXUSR&sbuf.st_mode)){
            clienterror(fd,filename,"403","Forbidden","Tiny couldn't run the CGI program");
            return;
        }
        serve_dynamic(fd,filename,cgiargs);
    }
}
//发送一个HTTP响应到客户端，在响应行中包含相应的状态码和状态消息，响应主体包含一个HTML文件，向浏览器的用户解释这个错误
void clienterror(int fd,char *cause,char *errnum,char *shortmsg,char *longmsg){
    char buf[MAXLINE],body[MAXLINE];

    sprintf(body,"<html><title>Tiny Error</title>");
    sprintf(body,"%s<body bgcolor=""ffffff"">\r\n",body);// this may not run right because of glabc version
    sprintf(body,"%s%s: %s\r\n",body,errnum,shortmsg);
    sprintf(body,"%s<p>%s: %s\r\n",body,longmsg,cause);
    sprintf(body,"%s<hr><em>The Tiny Web server</em>\r\n",body);

    sprintf(buf,"HTTP/1.0 %s %s\r\n",errnum,shortmsg);
    rio_writen(fd,buf,strlen(buf));
    sprintf(buf,"Content-type: text/html\r\n");
    rio_writen(fd,buf,strlen(buf));
    sprintf(buf,"Content-length: %d\r\n\r\n",(int)strlen(body));//指明主体中内容的大小和类型
    rio_writen(fd,buf,strlen(buf));
    rio_writen(fd,body,strlen(body));
}

// 读取并忽略请求报头
void read_requesthdrs(rio_t *rp){
    char buf[MAXLINE];

    rio_readlineb(rp,buf,MAXLINE);
    while(strcmp(buf,"\r\n")){
        rio_readlineb(rp,buf,MAXLINE);
        printf("%s",buf);
    }
    return;
}
//静态内容主目录设置为它的当前目录，可执行文件的主目录设置为 ./cgi-bin
//包含cgi-bin的URI当作对动态内容的请求
int parse_uri(char *uri,char *filename,char *cgiargs){
    char *ptr;

    if(!strstr(uri,"cgi-bin")){
        strcpy(cgiargs,"");
        strcpy(filename,".");
        strcat(filename,uri);
        if(uri[strlen(uri)-1]=='/')
            strcat(filename,"home.html");
        return 1;
    }
    else{
        ptr=index(uri,'?');//same as strchr
        if(ptr){
            strcpy(cgiargs,ptr+1);
            *ptr='\0';
        }
        else{
            strcpy(cgiargs,"");
        }
        strcpy(filename,".");
        strcat(filename,uri);
        return 0;
    }
}
void serve_static(int fd,char *filename,int filesize){
    int srcfd;
    char *srcp,filetype[MAXLINE],buf[MAXBUF];

    //send response headers to client
    get_filetype(filename,filetype);
    //printf("?????????????is there any thing wrong??");
    sprintf(buf,"HTTP/1.0 200 OK\r\nServer: Tiny Web Server\r\nConnection: close\r\nContent-length: %d\r\nContent-type: %s\r\n\r\n",filesize,filetype);
    // sprintf(buf,"%sServer: Tiny Web Server\r\n",buf);
    // sprintf(buf,"%sConnection: close\r\n",buf);
    // sprintf(buf,"%sContent-length: %d\r\n",buf,filesize);
    // sprintf(buf,"%sContent-type: %s\r\n\r\n",buf,filetype);
    //printf("buflen: %d\n",(int)strlen(buf));
    rio_writen(fd,buf,strlen(buf));
    printf("Response headers:\n");
    
    printf("%s",buf);

    //fflush(stdout);
    //printf("after print buf\n");
    //send response body to client
    srcfd=open(filename,O_RDONLY,0);
    srcp=mmap(0,filesize,PROT_READ,MAP_PRIVATE,srcfd,0);
    //调用mmap将文件srcfd的前filesize个字节映射到一个从地址srcp开始的私有只读虚拟内存区域
    close(srcfd);
    rio_writen(fd,srcp,filesize);
    munmap(srcp,filesize);
}

//get_filetype-Derive file type from filename
void get_filetype(char *filename,char *filetype){
    if(strstr(filename,".html"))
        strcpy(filetype,"text/html");
    else if(strstr(filename,".gif"))
        strcpy(filetype,"image/gif");
    else if(strstr(filename,".png"))
        strcpy(filetype,"image/png");
    else if(strstr(filename,".jpg"))
        strcpy(filetype,"image/jpeg");
    else
        strcpy(filetype,"text/plain");
}

void serve_dynamic(int fd,char *filename,char *cgiargs){
    char buf[MAXLINE],*emptylist[]={NULL};

    //return first part of HTTP response
    sprintf(buf,"HTTP/1.0 200 OK\r\n");
    rio_writen(fd,buf,strlen(buf));
    sprintf(buf,"Server: Tiny Web Server\r\n");
    rio_writen(fd,buf,strlen(buf));

    if(fork()==0){
        setenv("QUERY_STRING",cgiargs,1);
        dup2(fd,STDOUT_FILENO);
        execve(filename,emptylist,environ);       
    }
    wait(NULL);
}
int Accept(int s, struct sockaddr *addr, socklen_t *addrlen) 
{
    int rc;

    if ((rc = accept(s, addr, addrlen)) < 0)
	unix_error("Accept error");
    return rc;
}