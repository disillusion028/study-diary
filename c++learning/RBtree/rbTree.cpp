#include "rbTree.h"
#include <vector>
#include <random>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <queue>
template<typename T>
void RbTree<T>::LeftRotate(RbNode<T>* x){
    RbNode<T> *y=x->right;
    x->right=y->left;
    if(y->left!=Nil){
        y->left->pre=x;
    }
    y->pre=x->pre;
    if(x->pre==Nil)
        this->root=y;
    else if(x==x->pre->left){
        x->pre->left=y;
    }
    else x->pre->right=y;
    y->left=x;
    x->pre=y;
}
template<typename T>
void RbTree<T>::RightRotate(RbNode<T>* y){
    RbNode<T> *x=y->left;
    y->left=x->right;
    if(x->right!=Nil){
        x->right->pre=y;
    }
    x->pre=y->pre;
    if(y->pre==Nil){
        root=x;
    }
    else if(y==y->pre->left){
        y->pre->left=x;
    }
    else y->pre->right=x;
    x->right=y;
    y->pre=x;
}
template<typename T>
void RbTree<T>::RbInsertFixup(RbNode<T> *z){
    RbNode<T> *y;
    while(z->pre->color==RED){
        if(z->pre==z->pre->pre->left){
            y=z->pre->pre->right;
            if(y->color==RED){
                z->pre->color=BLACK;
                y->color=BLACK;
                z->pre->pre->color=RED;
                z=z->pre->pre;
            }
            else if(z==z->pre->right){
                z=z->pre;
                LeftRotate(z);
            }
            else{
                z->pre->color=BLACK;
                z->pre->pre->color=RED;
                RightRotate(z->pre->pre);
            }
        }
        else{
            y=z->pre->pre->left;
            if(y->color==RED){
                z->pre->color=BLACK;
                y->color=BLACK;
                z->pre->pre->color=RED;
                z=z->pre->pre;
            }
            else if(z==z->pre->left){
                z=z->pre;
                RightRotate(z);
            }
            else{
                z->pre->color=BLACK;
                z->pre->pre->color=RED;
                LeftRotate(z->pre->pre);
            }
        }
    }
    root->color=BLACK;
}
template<typename T>
void RbTree<T>::RbInsert(const T& zz){
    RbNode<T> *z=new RbNode<T>(zz);
    RbNode<T> *y=Nil;
    RbNode<T> *x=root;
    while(x!=Nil){//find where this Node should be put 
        y=x;
        if(z->val<x->val){
            x=x->left;
        }else{
            x=x->right;
        }
    }
    z->pre=y;
    if(y==Nil)
        root=z;
    else if(z->val<y->val){
        y->left=z;
    }
    else{
        y->right=z;
    }
    z->left=Nil;
    z->right=Nil;
    z->color=RED;
    RbInsertFixup(z);//fix up red-black balance
    cnt++;
}
template<typename T>
int RbTree<T>::getCount(){
    return cnt;
}
template<typename T>
void RbTree<T>::RbTransplant(RbNode<T> *u,RbNode<T> *v){
    if(u->pre==Nil){
        root=v;
    }
    else if(u==u->pre->left){
        u->pre->left=v;
    }
    else u->pre->right=v;
    v->pre=u->pre;
}
/*
TREE-DELETE(T,z){
    if z.left==NIL
        TRANSPLANT(T,z,z.right)
    elseif z.right==NIL
        TRANSPLANT(T,z,z.left)
    else
        y=TREE-MINIMUM(z.right)
        if(y.p!=z)
            TRANSPLANT(T,y,y.right)
            y.right=z.right
            y,right.p=y
        TRANSPLANT(T,z,y)
        y.left=z.left
        y.left.p=y
}
*/
template<typename T>
void RbTree<T>::RbDelete(RbNode<T> *z){
    RbNode<T> *y=z;
    RbNode<T> *x;
    bool yOriColor=y->color;
    if(z->left==Nil){
        x=z->right;
        RbTransplant(z,z->right);
    }
    else if(z->right==Nil){
        x=z->left;
        RbTransplant(z,z->left);
    }
    else{
        y=TreeMinimum(z->right);
        yOriColor=y->color;
        x=y->right;
        if(y->pre==z) x->pre=y;
        else {
            RbTransplant(y,y->right);
            y->right=z->right;
            y->right->pre=y;
        }
        RbTransplant(z,y);
        y->left=z->left;
        y->left->pre=y;
        y->color=z->color;
    }
    if(yOriColor==BLACK)
        RbDeleteFixup(x);
    cnt--;
    delete z;
    z=nullptr;
}
template<typename T>
void RbTree<T>::RbDeleteFixup(RbNode<T> *x){
    RbNode<T>* w;
    while(x!=root&&x->color==BLACK){
        if(x==x->pre->left)//x是它父节点的左儿子
        {
            w=x->pre->right;
            if(w->color==RED){
                w->color=BLACK;
                x->pre->color=RED;
                LeftRotate(x->pre);
                w=x->pre->right;
            }
            if(w->left->color==BLACK&&w->right->color==BLACK){
                w->color=RED;
                x=x->pre;
            }
            else if(w->right->color==BLACK){
                w->left->color=BLACK;
                w->color=RED;
                RightRotate(w);
                w=x->pre->right;
            }
            else{
                w->color=x->pre->color;
                x->pre->color=BLACK;
                w->right->color=BLACK;
                LeftRotate(x->pre);
                x=root;
            }
        }
        else{
            w=x->pre->left;
            if(w->color==RED){
                w->color=BLACK;
                x->pre->color=RED;
                RightRotate(x->pre);
                w=x->pre->left;
            }
            if(w->right->color==BLACK&&w->left->color==BLACK){
                w->color=RED;
                x=x->pre;
            }
            else if(w->left->color==BLACK){
                w->right->color=BLACK;
                w->color=RED;
                LeftRotate(w);
                w=x->pre->left;
            }
            else{
                w->color=x->pre->color;
                x->pre->color=BLACK;
                w->left->color=BLACK;
                RightRotate(x->pre);
                x=root;
            }
        }
    }
    x->color=BLACK;
}
template<typename T>
std::pair<bool, RbNode<T>*> RbTree<T>::RbFind(const T &t){
    RbNode<T>* ret=root;
    while(ret!=Nil&&ret->val!=t){
        if(ret->val>t){
            ret=ret->left;
        }
        else if(ret->val<t){
            ret=ret->right;
        }
    }
    if(ret==Nil){
        return {false,ret};
    }
    else return {true,ret};
}
template<typename T>
void RbTree<T>::RbClear()
{
    std::queue<RbNode<T>*> myqueue;
    if(this->root!=this->Nil&&this->root!=nullptr)
        myqueue.push(this->root);
    while(!myqueue.empty()){
        RbNode<T>* temp=myqueue.front();
        myqueue.pop();
        if(temp->left!=Nil){
            myqueue.push(temp->left);
        }
        if(temp->right!=Nil){
            myqueue.push(temp->right);
        }

        delete temp;
        temp=nullptr;
        this->cnt--;
    }
    root=nullptr;
}
template<typename TT>
ostream& operator<<(ostream& os,RbTree<TT> *T){
    // level travel
    std::vector<RbNode<TT>*> myvec;
    myvec.push_back(T->root);
    int level=1;
    while(!myvec.empty()){
        std::vector<RbNode<TT>*> vectemp;
        os<<"level "<<level<<" : ";
        for(int i=0;i<myvec.size();i++){
            if(myvec[i]!=T->Nil){
                os<<"(val):"<<myvec[i]->val<<"  "<<"(color):"<<myvec[i]->color<<"  ";
                if(myvec[i]->left!=T->Nil){
                    if(myvec[i]->color==RED&&myvec[i]->left->color==RED)std::cerr<<"error with rbtree"<<std::endl;
                    vectemp.push_back(myvec[i]->left);
                }
                if(myvec[i]->right!=T->Nil){
                    if(myvec[i]->color==RED&&myvec[i]->right->color==RED)std::cerr<<"error with rbtree"<<std::endl;                    
                    vectemp.push_back(myvec[i]->right);
                }
            }
        }
        os<<std::endl;
        level++;        
        myvec.swap(vectemp);
    }
    return os;
}

int main(){
    {
        RbTree<int> *T=new RbTree<int>();
        std::vector<int> va;
        va.reserve(10);
        for(int i=0;i<10;i++){
            va.push_back(i);
        }
        std::random_shuffle(va.begin(),va.end());//,std::mt19937{std::random_device{}()}
        
        std::clock_t a_start=std::clock();
        for(int i=0;i<va.size();i++){
            T->RbInsert(va[i]);
        }
        std::clock_t a_end=std::clock();
        std::cout<<(a_end-a_start)*1000/CLOCKS_PER_SEC<<"ms"<<std::endl;
        std::ofstream ofs("/home/caoqi/GITs/study diary/c++learning/RBtree/res2.txt");
        if(!ofs.is_open()){std::cout<<"error"<<std::endl;}
        
        ofs<<T;
        std::clock_t b_start=std::clock();
        std::pair<bool,RbNode<int>*> pairret=T->RbFind(3333);
        std::clock_t b_end=std::clock();
        std::cout<<(b_end-b_start)<<"us"<<std::endl;
        std::cout<<pairret.second->color<<"  "<<pairret.second->val<<std::endl;
        ofs.close();
        delete T;
        T=nullptr;
    }
    {
        MySet<int> ms;
        std::vector<int> vb;
        for(int i=0;i<10;i++){
            ms.insert(i);
        }
        ms.erase(6);
        ms.print();
    }
    return 0;
}