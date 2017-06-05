#include <cstring>
#include <iostream>
using namespace std;
int main(){
    char item[]="AAAAAAAAAA";
    char* p = (char*)&item;
    for (int i=0; i<sizeof(item)/2; i++)
    {
        char temp = p[i];
        p[i] = p[sizeof(item)-1-i];
        p[sizeof(item)-1-i] = temp;
    }
    for(int i=0;i<sizeof(item)-1;i++){
        std::cout<<p[i]<<"  ";
    }
    return 0;
}