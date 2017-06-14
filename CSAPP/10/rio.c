#include "../mycsapp.h"

void rio_readinitb(rio_t *rp,int fd){
    rp->rio_fd=fd;
    rp->rio_cnt=0;
    rp->rio_bufptr=rp->rio_buf;
}

ssize_t rio_readn(int fd,void *usrbuf,size_t n){
    size_t nleft=n;
    ssize_t nread;
    char *bufp=usrbuf;

    while(nleft>0){
        if((nread=read(fd,bufp,nleft))<0){
            if(errno==EINTR)
                nread=0;
            else
                return -1;
        }
        else if(nread==0)
            break;
        nleft-=nread;
        bufp+=nread;
    }
    return (n-nleft);
}
ssize_t rio_writen(int fd,void *usrbuf,size_t n){
    size_t nleft=n;
    ssize_t nwritten;
    char *bufp=usrbuf;

    while(nleft>0){
        if((nwritten=write(fd,bufp,nleft))<=0){
            if(errno==EINTR)
                nwritten=0;
            else
                return -1;
        }
        nleft-=nwritten;
        bufp+=nwritten;
    }
    return n;
}

static ssize_t rio_read(rio_t *rp,char *usrbuf,size_t n){
    int cnt;

    while(rp->rio_cnt<=0){//refill if buf is empty
        rp->rio_cnt = read(rp->rio_fd,rp->rio_buf,sizeof(rp->rio_buf));
        if(rp->rio_cnt<0){
            if(errno!=EINTR)//interrupted by sig handler return
                return -1;
        }
        else if (rp->rio_cnt==0)
            return 0;
        else rp->rio_bufptr=rp->rio_buf;
    }
    //copy min(n,rp->rio_cnt) nytes from internal buf to user buf
    cnt=n;
    if(rp->rio_cnt<n)
        cnt=rp->rio_cnt;//why not use min()?
    memcpy(usrbuf,rp->rio_bufptr,cnt);
    rp->rio_bufptr+=cnt;
    rp->rio_cnt-=cnt;
    return cnt;
}
ssize_t rio_readlineb(rio_t *rp,void *usrbuf,size_t maxlen){
    int n,rc;
    char c,*bufp=usrbuf;

    for(n=1;n<maxlen;n++){
        if((rc=rio_read(rp,&c,1))==1){
            *bufp++=c;
            if(c=='\n'){
                n++;
                break;
            }
        }else if(rc==0){
            if(n==1)return 0;//no data read
            else break;//read some data
        }else return -1;//error
    }
    *bufp=0;
    return n-1;
}
ssize_t rio_readnb(rio_t *rp,void *usrbuf,size_t n){
    size_t nleft=n;
    ssize_t nread;
    char *bufp=usrbuf;

    while(nleft>0){
        if((nread=rio_read(rp,bufp,nleft))<0)
            return -1;
        else if(nread==0)
            break;
        nleft-=nread;
        bufp+=nread;
    }
    return (n-nleft);
}
// int main(int argc,char **argv){
//     int n;
//     rio_t rio;
//     char buf[MAXLINE];
//     char *infile=NULL;
//     if(argc==2){
//         infile=argv[1];
//     }
//     rio_readinitb(&rio,STDIN_FILENO);
//     if(infile!=NULL){
//         int fd=open(infile,O_RDONLY,0);
//         dup2(fd,STDIN_FILENO);
//     }//homework 10.10
//     while((n=rio_readlineb(&rio,buf,MAXLINE))!=0)
//         rio_writen(STDOUT_FILENO,buf,n);
//     /* 10.7 homework
//     while((n=rio_readn(0,buf,RIO_BUFSIZE))!=0){
//         rio_writen(1,buf,n);
//     }
//     */
//     return 0;
// }