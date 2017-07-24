#include <iostream>
using namespace std;


class HasPtrMem{
public:
    HasPtrMem():d(new int (0)){
        cout<<"Construct: "<<++n_cstr<<endl;
    }
    //HasPtrMem(const HasPtrMem&h):d(h.d){}
    HasPtrMem(const HasPtrMem&h):d(new int(*h.d)){
        cout<<"Copy construct: "<<++n_cptr<<endl;
    }
    HasPtrMem(HasPtrMem&&h):d(h.d){
        h.d=nullptr;
        cout<<"Rvalue copy: "<<++n_cptr<<endl;
    }
    ~HasPtrMem(){
        cout<<"Destruct: "<<++n_dstr<<endl;
        delete d;
    }
    int* d;
    static int n_cstr;
    static int n_dstr;
    static int n_cptr;
    static int n_mvtr;
};
HasPtrMem GetTemp(){
    // HasPtrMem h;
    // cout<<"Resource from "<<__func__<<": "<<hex<<h.d<<endl;
    return HasPtrMem();
}
int HasPtrMem::n_cstr=0;
int HasPtrMem::n_dstr=0;
int HasPtrMem::n_cptr=0;
int HasPtrMem::n_mvtr=0;

int main(){
//     HasPtrMem a;
//     HasPtrMem b(a);
//     cout<<a.d<<endl;
//     cout<<b.d<<endl;
    HasPtrMem b=GetTemp();
    // cout<<"Resource from "<<__func__<<": "<<hex<<b.d<<endl;
    return 0;
}
//?? 这个编译器优化的我脑子都不好用了