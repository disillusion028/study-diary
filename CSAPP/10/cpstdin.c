#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// int main(){
//     int fd1,fd2;
//     fd1=open("foo.txt",O_RDONLY,0);
//     close(fd1);
//     fd2=open("baz.txt",O_RDONLY,0);
//     printf("fd2=%d\n",fd2);
//     exit(0);
// }
int main(void){
    char c;

    while(read(STDIN_FILENO,&c,1)!=0)
        write(STDOUT_FILENO,&c,1);
    exit(0);
}