#include "../csapp.h"
#define MAXTHREADS 16384
void *thread(void *vargp);

int main(int argc,char **argv){
    pthread_t tid[MAXTHREADS];
    int i;
    
    if(argc!=2){
        fprintf(stderr,"Usage: %s <countofthread>\n",argv[0]);
        exit(0);
    }
    int N=atoi(argv[1]);
    if(N>16386||N<0){
        fprintf(stderr,"Usage: pthread count should be 0-16386\n");
        exit(0);        
    }    
    for(i=0;i<N;i++){
        Pthread_create(&tid[i],NULL,thread,NULL);
    }
    for(i=0;i<N;i++){
        Pthread_join(tid[i],NULL);        
    }
    exit(0);
}

void *thread(void *vargp){
    printf("Hello,world\n");
    return NULL;
}