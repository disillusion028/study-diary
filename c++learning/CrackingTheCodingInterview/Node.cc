//Write a method that takes a pointer to a Node structure as a parameter and returns a complete copy of the passed in data structure,
//The Node data structure contains two pointers to other Nodes

#include <iostream>
class Node{    
public:
    Node(int v):val(v){}
    int val;
    Node *left;
    Node *right;
};
class Solution{
    Node* CopyNode(Node *root){
        if(root==NULL)return NULL;
        Node *p=new Node(root->val);
        p->left=CopyNode(root->left);
        p->right=CopyNode(root->right);
        return p;
    }
};