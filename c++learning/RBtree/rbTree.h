#include <iostream>
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
    RbNode()=default;
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
    }
    ~RbTree(){
        delete(Nil);
    }
    void RbDelete(RbNode<T>* z);
    void LeftRotate(RbNode<T>* t);
    void RightRotate(RbNode<T>* t);
    void RbInsert(RbNode<T>* z);
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
};
