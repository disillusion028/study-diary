//16.14 编写Screen类模板，用非类型参数定义Screen的高和宽
#include <string>
#include <iostream>
struct xyc{
    int x=0;
    int y=0;
    char c=' ';
};
std::istream &operator>>(std::istream &is,xyc &c){
    is>>c.x;
    is>>c.y;
    is>>c.c;
    return is;
}
template<unsigned N,unsigned M>
class Screen{
    unsigned cursor=0;
    unsigned width=N,height=M;
    std::string contents;
public:
    Screen()=default;
    Screen(char c):contents(N*M,c){}
    char get()const {return contents[cursor];}
    Screen set(xyc c){
        cursor=--c.x*width + --c.y;
        contents[cursor]=c.c;
        return *this;
    }
    template<unsigned NN,unsigned MM>
    friend std::ostream &operator<<(std::ostream &os,const Screen<NN,MM> &s);
    template<unsigned NN,unsigned MM>
    friend std::istream &operator>>(std::istream &is,Screen <NN,MM> &s);
};
template <unsigned NN,unsigned MM>
std::ostream &operator<<(std::ostream &os,const Screen<NN,MM>&s){
    for(unsigned i=0;i<s.width;++i){
        for(unsigned j=0;j<s.height;++j){
            putchar(s.contents[i*s.width+j]);
        }
        putchar('\n');
    }
    return os;
}
template<unsigned NN,unsigned MM>
std::istream &operator>>(std::istream &is,Screen<NN,MM> &s){
    xyc c;
    is>>c;
    s.set(c);
    return is;
}

int main(){
    using namespace std;
    Screen<6,6> scr('-');
    cout<<scr;
    cin>>scr;
    cout<<scr;
    return 0;
}
