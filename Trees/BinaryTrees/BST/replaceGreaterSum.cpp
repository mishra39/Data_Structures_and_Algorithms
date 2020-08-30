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

void replaceWithLargerNodesSumHelper(BinaryTreeNode<int> *root, int* sum) {

    // Base Case
    if (root == NULL)
    {
        return;
    }

    // Recurse the right subtree
    replaceWithLargerNodesSumHelper(root->right, sum);

    // Now *sum has sum of nodes of right subtree
    // add root data to the sum
    *sum = *sum + root->data;
    root->data  = *sum; // replace root data with the sum

    // Recurse the left tree
    replaceWithLargerNodesSumHelper(root->left, sum);
}

void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    
    int sum = 0;
    replaceWithLargerNodesSumHelper(root, &sum);
}


int main() {
    BinaryTreeNode<int>* root = takeInput();
}