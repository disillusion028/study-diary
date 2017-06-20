#include "../csapp.h"
#define N 4

void *thread(void *vargp);

int main(){
    pthread_t tid[N];
    int i;
    int *ptr;
    for(i=0;i<N;i++){
        ptr=Malloc(sizeof(int));
        *ptr=i;
        Pthread_create(&tid[i],NULL,thread,ptr);
    }
    for(i=0;i<N;i++){
        Pthread_join(tid[i],NULL);
    }
    exit(0);
}



void *thread(void *vargp){
    int myid=*((int*)vargp);
    Free((int*)vargp);
    printf("Hello from thread %d\n",myid);
    return NULL;
}