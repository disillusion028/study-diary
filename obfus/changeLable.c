#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

void makeCodeWritable(char* first){
    char * firstpage=first-((long)first%getpagesize());
    //char * lastpage=last-((int)last%getpagesize());

    //int pages=(lastpage-firstpage)/getpagesize()+1;
    if(mprotect(firstpage,1*getpagesize(),PROT_READ|PROT_EXEC|PROT_WRITE)==-1)
        perror("mprotect");
}
// char * allocExecuablePages(int pages){
//     t=(char*)valloc(getpagesize()*pages);
//     if(mprotect(t.))
// }
int player_main(){
    long x=*(long*)(&&Lable1);
    long x2=*(long*)(&&Lable2);
    printf("%lx\n",x);
   // long s1=x1;
    int y=0x12;
    // long x2=*(long*)(&&Lable2);
    // printf("%x\n",x2);
    //long s2=x2;
    //*(long*)(&&Lable1)=x2;
    *(long*)(&&Lable1)=0;
    *(long*)(&&Lable1)=x;

Lable1:
    y=0x34;
    printf("%d\n",y);
    fflush(stdout);
    //return 0;
Lable2:
    y=0x12;
    printf("%d\n",y);
    fflush(stdout);
    return 0;
}

int main(){
    void *m=main;
   // makeCodeWritable(m);
    player_main();
    return 0;
}
