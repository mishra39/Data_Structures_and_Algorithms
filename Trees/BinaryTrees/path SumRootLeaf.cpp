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
#include <string>
#include <bits/stdc++.h>

void printPath(BinaryTreeNode<int>* root, int k,  string path)
{
    if (root == NULL)
    {
        return;
    }

    path.append(" ");
    path.append(to_string(root->data));
    printPath(root->left, k-(root->data), path);
    printPath(root->right, k-(root->data), path);
    // check if current node is leaf node
    if (root->left == NULL && root->right == NULL)
    {
        if (root->data == k)
        {
            cout << path << endl;
        }
    }

    else
    {
        path.clear();
    }

}

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    string path;
    printPath(root, k, path);
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int k;
    cin >> k;
    rootToLeafPathsSumToK(root, k);
    delete root;
}