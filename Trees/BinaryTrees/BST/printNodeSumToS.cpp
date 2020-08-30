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

#include <algorithm>
#include <bits/stdc++.h>

void BST_toArray(BinaryTreeNode<int>* root, int* arr, int idx)
{

    if (root == NULL)
    {
        return;
    }

    BST_toArray(root->left, arr, idx);
    arr[idx++] = root->data;
    BST_toArray(root->right, arr, idx);

}

void printNodesSumToS(BinaryTreeNode<int> *root, int s)
{
    int* arr = new int[10000];
    int* idx = 0;
    BST_toArray(root, arr,idx);

    for (int i = 0; i < idx; i++)
    {
        cout << arr[i] << endl;
    }
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int s;
    cin >> s;
    printNodesSumToS(root, s);
    delete root;
}