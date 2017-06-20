//  多线程并行处理求和；
//  方法2：将每个线程所计算的部分和放入一个线程私有数组元素中

#include "../csapp.h"
#define MAXTHREADS 16384


void *sum_array(void *vargp);
long psum[MAXTHREADS];

long nelems_per_thread;//number of elements to sum
sem_t mutex;//mutex to protect global sum

struct timespec start_time,finish_time;
double elapsed;

int main(int argc,char**argv){
    long i,gsum=0,nelems,log_nelems,nthreads,myid[MAXTHREADS];
    pthread_t tid[MAXTHREADS];

    if(argc!=3){
        printf("Usage: %s <nthreads> <log_nelems>\n",argv[0]);
        exit(0);
    }
    nthreads=atoi(argv[1]);
    log_nelems=atoi(argv[2]);
    nelems=1L<<log_nelems;
    nelems_per_thread=nelems/nthreads;
    Sem_init(&mutex,0,1);
    clock_gettime(CLOCK_MONOTONIC,&start_time);
    for(i=0;i<nthreads;i++){
        myid[i]=i;
        psum[i]=0;
        Pthread_create(&tid[i],NULL,sum_array,&myid[i]);
    }
    for(i=0;i<nthreads;i++){
        Pthread_join(tid[i],NULL);
        gsum+=psum[i];
    }

    if(gsum!=(nelems*(nelems-1))/2)
        printf("Error: result=%ld\n",gsum);
    clock_gettime(CLOCK_MONOTONIC,&finish_time);
    elapsed=(finish_time.tv_sec-start_time.tv_sec);
    elapsed+=(finish_time.tv_nsec-start_time.tv_nsec)/1000000000.0;
    printf("%lf seconds\n",elapsed);
    exit(0);
}

void *sum_array(void *vargp){
    long myid=*((long*)vargp);
    long start=myid*nelems_per_thread;
    long end=start+nelems_per_thread;
    long i;
    for(i=start;i<end;i++){
        psum[myid]+=i;
    }
    return NULL;
}