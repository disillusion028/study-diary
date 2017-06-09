#include <iostream>
#include <vector>
#include <initializer_list>

using std::vector;
using std::ostream;

class Myheap;
ostream& operator<<(ostream& os,const Myheap &s);
void HeapSort(vector<int>&);
class Myheap{
public:
    friend std::ostream& operator<<(ostream& os,const Myheap &s);    
    friend void HeapSort(vector<int>&);
    Myheap(const std::vector<int> &s){
        this->heapvec=vector<int>();
        this->heapvec.push_back(0);
        this->heapvec.insert(this->heapvec.end(),s.begin(),s.end());
        heapLength=this->heapvec.size()-1;
        this->heapSize=this->heapLength;
    }
    std::vector<int> operator()(void){
        return this->heapvec;
    }
    int parent(int x){
        return x>>1;
    }
    int left(int x){
        return x<<1;
    }
    int right(int x){
        return (x<<1)+1;
    }
    void MaxHeapify(int x);
    void BuildMaxHeap()     //O(n)
    {
        this->heapSize=this->heapLength;
        for(int i=this->heapLength/2;i>=1;i--){
            MaxHeapify(i);
        }
    }
private:
    vector<int> heapvec;
    int heapSize;
    int heapLength;
};

ostream& operator<<(ostream& os, const Myheap &s){
    // for(auto i:s()){
    //     os<<i<<"  ";
    // }
    for(auto i=s.heapvec.begin()+1;i!=s.heapvec.end();i++){
        os<<*i<<"  ";
    }
    return os;
}

void Myheap::MaxHeapify(int x){
    int l=left(x);
    int r=right(x);
    int largest=0;
    if(l<=heapSize&&this->heapvec[l]>this->heapvec[x])
        largest=l;
    else largest=x;
    if(r<=heapSize&&this->heapvec[r]>this->heapvec[largest])
        largest=r;
    if(largest!=x){
        std::swap(this->heapvec[x],this->heapvec[largest]);
        MaxHeapify(largest);
    }
}
void HeapSort(vector<int>& v){
    Myheap Hs(v);
    Hs.BuildMaxHeap();
    for(int i=Hs.heapLength;i>=2;i--){
        std::swap(Hs.heapvec[1],Hs.heapvec[i]);
        Hs.heapSize=Hs.heapSize-1;
        Hs.MaxHeapify(1);
    }
    std::cout<<Hs<<std::endl;
}