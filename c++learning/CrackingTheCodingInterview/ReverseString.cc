// implement a function void reverse(char* str)in C or C++ which reverses a null-terminated string
#include <iostream>
#include <string>
using namespace std;
class Reverse{
public:    
    Reverse(char * str){
        mystr=string(str);
        s=str;
    }
    string doRevstr(){
        return string(this->mystr.rbegin(),this->mystr.rend());
    }
    void doRev(){
        char *s=this->s;
        char *end = s;
        char tmp;
        int sz=0;
        for(;s[sz]!='\0';sz++);
        int half=sz/2;
        for(int i=0;i<half;i++){
            swap(s[i],s[sz-1-i]);
        }
    }
private:
    string mystr;
    char *s;
};
void doRev(char *s){
        char *end = s;
        char tmp;
        if(s){
            while(*end){
                ++end;
            }
            --end;
        }
        while(s<end){
            tmp=*s;
            *s++=*end;
            *end--=tmp;
        }
    }
int main(){
    char* str=new char[100];
    const char *x="210y548y afdsfa09u&GIUG12))_*Q(&#)*(";//字符串常量存放位置--不能直接对字符串常量进行修改
    for(int i=0;x[i]!='\0';i++){
        str[i]=x[i];
    }
    cout<<str<<endl;
    Reverse r(str);
    r.doRev();
    cout<<r.doRevstr()<<endl;
    cout<<str<<endl;
    delete[] str;
    return 0;
}