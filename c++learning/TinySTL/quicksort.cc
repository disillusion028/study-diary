#include <iostream>
#include <vector>
using namespace std;
int Lomuto_partition(vector<int>& a,int lo,int hi){
    int x=a[hi];
    int res=lo-1;
    for(int i=lo;i<hi;i++){
        if(a[i]<=x){
            res++;            
            swap(a[res],a[i]);
        }
    }
    swap(a[res+1],a[hi]);
    return res+1;
}
int Hoare_partition(vector<int> &a,int lo,int hi){
    int x=a[lo];
    int i=lo-1,j=hi+1;
    while(true){
        do{
            i+=1;
        }while(a[i]<x);
        do{
            j-=1;
        }while(a[j]>x);
        if(i>=j)return j;
        swap(a[i],a[j]);
    }
}
void Hoare_quicksort(vector<int> &a,int lo,int hi){
    if(lo<hi){
        int k=Hoare_partition(a,lo,hi);
        Hoare_quicksort(a,lo,k);
        Hoare_quicksort(a,k+1,hi);
    }
}
void Lomuto_quicksort(vector<int> &a,int lo,int hi){
    if(lo<hi){
        int k=Lomuto_partition(a,lo,hi);
        Lomuto_quicksort(a,lo,k-1);
        Lomuto_quicksort(a,k+1,hi);
    }
}
ostream& operator<<(ostream &os,vector<int>& a){
    for(auto i: a){
        os<<i<<" ";
    }
    os<<endl;
    return os;
}
int main(){
    vector<int> m={4,7,8,4,2,0,1,8,2};
    vector<int> n={1,2,3,4,5,6,7,8};
    vector<int> p={8,7,6,5,4,3,2,1};
    vector<int> q={0,0,0,0,0};
    vector<int> r={3};
    Lomuto_quicksort(m,0,m.size()-1);
    //cout<<partition(m,0,m.size()-1)<<endl;
   //cout<<m;

    Lomuto_quicksort(n,0,n.size()-1);
    Lomuto_quicksort(p,0,p.size()-1);
    Lomuto_quicksort(q,0,q.size()-1);
    Lomuto_quicksort(r,0,r.size()-1);
    cout<<m<<n<<p<<q<<r;
    return 0;
}