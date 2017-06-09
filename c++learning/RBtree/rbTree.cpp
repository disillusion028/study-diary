#include "rbTree.h"
#include <vector>
#include <random>
#include <algorithm>
#include <fstream>
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
void RbTree<T>::RbInsert(RbNode<T> *z){
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
                    vectemp.push_back(myvec[i]->left);
                }
                if(myvec[i]->right!=T->Nil){
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
    RbTree<int> *T=new RbTree<int>();
    std::vector<int> va;
    va.reserve(100000);
    for(int i=0;i<100000;i++){
        va.push_back(i);
    }
    std::shuffle(va.begin(),va.end(),std::mt19937{std::random_device{}()});
    RbNode<int> *A[va.size()];
    for(int i=0;i<va.size();i++){
        A[i]=new RbNode<int>(va[i]);
        T->RbInsert(A[i]);
    }
    std::ofstream ofs("/home/caoqi/GITs/study diary/c++learning/RBtree/res.txt");
    if(!ofs.is_open()){std::cout<<"error"<<std::endl;}
    // for(int i=0;i<va.size();i++){
    //     T->RbDelete(A[i]);
    //     std::cout<<T;
    //     std::cout<<std::endl;
    // }
    ofs<<T;
    delete T;
    for(int i=0;i<va.size();i++){
        delete A[i];
    }
    return 0;
}