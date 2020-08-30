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



int height(BinaryTreeNode<int> *root) {
    if (root == NULL)
    {
        return 0;
    }

    int finalAns = 0;
    if (root->left)
    {

        int ans1 = height(root->left);
        finalAns = (finalAns>ans1) ? finalAns : ans1;
    }
    
    if (root->right)
    {
        int ans2 = height(root->right);
        finalAns = (finalAns > ans2) ? finalAns : ans2;
    }

    return 1+finalAns;
}


bool isBST(BinaryTreeNode<int>* node, int min, int max)
{
    // base case
    if (node == nullptr)
        return true;

    // if node's value fall outside valid range
    if (node->data < min || node->data > max)
        return false;

    // recursively check left and right subtrees with updated range
    return isBST(node->left, min, node->data) &&
           isBST(node->right, node->data, max);
}


int largestBSTSubtree(BinaryTreeNode<int> *root) {

    if(isBST(root, INT_MIN, INT_MAX))
    {
        return height(root);
    }

    return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));

}


int main() {
    BinaryTreeNode<int>* root = takeInput();
}