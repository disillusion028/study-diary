#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
// 使用 mmap 将一个任意大小的磁盘文件复制到 stdout
void printfile(const char*filename){
    int fd=open(filename,O_RDONLY);
    if(fd==-1)perror("error open file\n");
    struct stat sb;
    if(fstat(fd,&sb)==-1)perror("fstat failed\n");
    char * addr=mmap(NULL,sb.st_size,PROT_READ,MAP_PRIVATE,fd,0);
    if(addr==MAP_FAILED)perror("mmap failed\n");
    if(write(STDOUT_FILENO,addr,sb.st_size)!=sb.st_size)perror("write failed\n");
}
int main(int argc,char**argv){
    if(argc!=2)perror("should input filename\n");
    const char *filename = argv[1];
    printfile(filename);
    //printf("what??");
    return 0;    
}
