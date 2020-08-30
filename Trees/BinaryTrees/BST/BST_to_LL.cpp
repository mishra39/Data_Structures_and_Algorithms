#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
using namespace std;

 template <typename T>
 class Node{
    public:
    T data;
    Node<T> *next;
    
    Node(T data){
        this -> data = data;
        this -> next = NULL;
    }
 };

BinaryTreeNode<int>* takeInput()
{
    int rootData;
    cout << "Enter Root Data" << endl;
    cin  >> rootData;

    if (rootData==-1)
     {
        return NULL;
     }

     BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
     queue<BinaryTreeNode<int>*> pendingNodes;
     pendingNodes.push(root);

     while(!pendingNodes.empty())
     {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter left child of" << front->data << endl;
        int leftNodeData;
        cin >> leftNodeData;
        if (leftNodeData != -1)
        {
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftNodeData);
            front->left = child;
            pendingNodes.push(child);
        }

        cout << "Enter right child of" << front->data << endl;
        int rightNodeData;
        cin >> rightNodeData;
        if (rightNodeData != -1)
        {
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightNodeData);
            front->right = child;
            pendingNodes.push(child);
        }
     }

     return root;
}

#include<bits/stdc++.h>
Node<int>* constructBST(BinaryTreeNode<int>* root) {
     if(root==NULL){
        return NULL;
     }
    Node<int>* a= new Node<int>(root->data);
    Node<int>*le= constructBST(root->left);
    if(le==NULL){
        le=a;
    }
    else{
        Node<int>*temp = le;
        while(temp -> next != NULL){
        temp = temp -> next;
    }
        
    temp -> next = a;
    }
    
    Node<int>*re= constructBST(root->right);
    
    if(re==NULL){
        a -> next = NULL;
    }
    else{
    a -> next = re;
    }   
    return le;
    }

void preOrder(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        return;
    }
    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}

int main() {
    int size;
    cin>>size;
    int *input=new int[1+size];
    
    for(int i=0;i<size;i++)
        cin>>input[i];
    
    BinaryTreeNode<int>* root = constructTree(input, size);
    preOrder(root);
    
}