#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, char ** argv){
    if(argc!=2)exit(-1);
    struct stat Stat;
    char *type,*readok;

    fstat(atoi(argv[1]),&Stat);
    if(S_ISREG(Stat.st_mode))
        type="regular";
    else if(S_ISDIR(Stat.st_mode)){
        type="directory";
    }
    else type="other";
    if((Stat.st_mode & S_IRUSR))
        readok="yes";
    else
        readok="no";
    printf("type: %s, read: %s\n",type,readok);
    exit(0);   
}
//home work 10.8