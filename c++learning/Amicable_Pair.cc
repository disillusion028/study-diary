#include <iostream>
#include <vector>
using namespace std;
vector<int> A(5000010,1);
int main(){
    int j;
    for(int i=2;i+i<=5000000;i++){
        j=i+i;
        while(j<=5000000){
            A[j]+=i;
            j+=i;
        }
    }
    int count=0;
    for(int i=0;i<=5000000;i++){
        if(A[i]>i&&A[i]<=5000000&&A[A[i]]==i){
            cout<<i<<" "<<A[i]<<endl;
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}