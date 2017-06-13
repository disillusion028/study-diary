#include "unix_error.h"
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv){
    if(argc!=2)unix_error("argc==2");
    DIR *streamp;
    struct dirent *dep;
    streamp=opendir(argv[1]);

    errno=0;
    while((dep=readdir(streamp))!=NULL){
        printf("Found file : %s\n",dep->d_name);
    }
    if(errno!=0){
        unix_error("readdir error");
    }
    closedir(streamp);
    exit(0);
} 