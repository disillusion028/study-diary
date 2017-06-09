# heap study
* MAX_HEAPIFY 过程：其时间复杂度为O(lg n)
* BUILD_MAX_HEAP 过程： 线性时间复杂度，功能是从无序的输入数据数组中构造一个最大堆。
* HEAPSORT过程：时间复杂度为O(nlgn)，对一个数组进行原址排序
* MAX_HEAP_INSERT/HEAP_EXTRACT_MAX/HEAP_INCREASE_KEY/HEAP_MAXIMUM过程：时间复杂度O(lgn)，功能是利用堆实现一个优先队列。

 ```
 MAX_HEAPIFY(A,i)
 l=LEFT(i)
 r=RIGHT(i)
 if l<=A.heap_size and A[l]>A[i]
    largest=l
else lagest=r
if r<=A.heap_size and A[r]>A[largest]
    lagest=r
if largest!=i
    exchange A[i] with A[largest]
    MAX_HEAPIFY(A,largest)
 ```