#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include <errno.h>

#define MAX_HEAP 1024*1024
extern int mm_init(void);
extern void* mm_malloc(size_t size);
extern void mm_free(void* ptr);

static char *mem_heap;
static char *mem_brk;
static char * mem_max_addr;

void mem_init(void){
    mem_heap=(char*)malloc(MAX_HEAP);
    mem_brk=(char*)mem_heap;
    mem_max_addr=(char*)(mem_heap+MAX_HEAP);
}

void* mem_sbrk(int incr){
    char* old_brk=mem_brk;
    if((incr<0)||((mem_brk+incr)>mem_max_addr)){
        errno=ENOMEM;
        fprintf(stderr,"error:mem_sbrk failed. Ran out of memory...");
    }
}