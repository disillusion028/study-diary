#include <iostream>
#include <utility>
using std::ostream;
#define RED false
#define BLACK true
template<typename T>
class RbNode;
template<typename T>
class RbTree;
template<typename T>
ostream& operator<<(ostream &,RbTree<T>*);//层序遍历输出节点
template<typename T>
class RbNode{
public:
    RbNode(){}
    RbNode(T _val):val(_val),color(RED),left(NULL),right(NULL),pre(NULL){}
    RbNode(bool _color,T _val,RbNode* _pre):color(_color),val(_val),left(NULL),right(NULL),pre(NULL){}
    bool color;// 0 means red ,1 means black
    T val;
    RbNode* left;
    RbNode* right;
    RbNode* pre;
};
template<typename T>
class RbTree{
public:
    template<typename TT>
    friend ostream& operator<<(ostream&,RbTree<TT>*);
    RbTree(){
        Nil=new RbNode<T>(BLACK,-1,NULL);
        root=Nil;
        cnt=0;
    }
    ~RbTree(){//TODO: 这样写很不安全啊，析构函数应该保证异常安全
        this->RbClear();
        delete Nil;
        Nil=nullptr;
    }
    std::pair<bool,RbNode<T>*> RbFind(const T &t);
    void RbDelete(RbNode<T>* z);
    void LeftRotate(RbNode<T>* t);
    void RightRotate(RbNode<T>* t);
    void RbInsert(const T& zz);
    int getCount();
    void RbClear();
private:
    //helper function
    void RbDeleteFixup(RbNode<T> *x);
    void RbInsertFixup(RbNode<T> *z);
    void RbTransplant(RbNode<T> *u,RbNode<T> *v);
    RbNode<T>* TreeMinimum(RbNode<T> *x){
        while(x->left!=Nil){
            x=x->left;
        }
        return x;
    }
    RbNode<T> *root;
    RbNode<T> *Nil;
    int cnt;
};

template<typename T>
class MySet{
public:
    MySet(){
        rb=new RbTree<T>();
    }
    ~MySet(){
        delete rb;
    }
    bool insert(const T& t){
        if(this->count(t))return false;
        rb->RbInsert(t);
        return true;
    }
    
    bool erase(T t){
        std::pair<bool,RbNode<T>*> prtemp=rb->RbFind(t);
        if(prtemp.first){
            rb->RbDelete(prtemp.second);
            return true;
        }
        else return false;
    }
    void clear(){
        rb->RbClear();
    }
    int count(const T &t){
        if(this->findhlp(t).first)return 1;
        else return 0;
    }
    void print(){
        std::cout<<rb;
    }
private:
    std::pair<bool,RbNode<T>*> findhlp(const T& t){
        return rb->RbFind(t);
    }
    RbTree<T> *rb;
};