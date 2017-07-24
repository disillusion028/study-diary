#include <cstdlib>
class alloc{
private:
//以字节数为单位分配的空间配置器
    enum EAlign{ALIGN=8};//小型区块上调边界
    enum EMaxBytes{MAXBYTES=128};//小型区块的上限，超过的区块由malloc分配
    enum ENFreeLists{NFREELISTS=(EMaxBytes::MAXBYTES/EAlign::ALIGN)};//free-lists的个数
    enum ENObjs{NOBJS=20};//每次增加的字节数
private:
    //free-lists的节点构造
    union obj{
        union obj* next;
        char client[1];
    };
    static obj *free_list[ENFreeLists::NFREELISTS];
private:
    static char * start_free;//内存池起始位置
    static char * end_free;//内存池结束位置
    static size_t heap_size;
private:
    //将bytes上调至8的倍数
    static size_t ROUND_UP(size_t bytes){
        return ((bytes+EAlign::ALIGN-1)&~(EAlign::ALIGN-1));
    }
    //根据区块大小，决定使用第n号free-list，n从0开始计算
    static size_t FREELIST_INDEX(size_t bytes){
        return (((bytes)+EAlign::ALIGN-1)/EAlign::ALIGN-1);
    }
    static void *refill(size_t n);
    static char* chunk_alloc(size_t size, size_t&nobjs);
public:
    static void *allocate(size_t bytes);
    static void deallocate(void *ptr,size_t bytes);
    static void *reallocate(void *ptr,size_t old_sz,size_t new_sz);
};