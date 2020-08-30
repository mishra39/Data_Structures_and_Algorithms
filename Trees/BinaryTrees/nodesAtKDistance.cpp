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

void printAtDepthK(BinaryTreeNode<int>* root, int depth)
{
    if (root == NULL || depth <0)
    {
        return;
    }

    if (depth==0)
    {
        cout << root->data << endl;
        return;
    }

    // Recur for left and right subtrees
    printAtDepthK(root->left, depth-1);
    printAtDepthK(root->right, depth-1);
}

int IntnodesAtDistanceK(BinaryTreeNode<int>* root, int node, int k)
{
    if (root == NULL)
    {
        return -1;
    }

    // If target is same as root.  Use the downward function 
    // to print all nodes at distance k in subtree rooted with 
    // target or root
    if (root->data == node)
    {
        printAtDepthK(root, k);
        return 0;
    }

    // Recur for left subtree 
    int dl = IntnodesAtDistanceK(root->left, node, k);

    if (dl != -1)
     {
         if (dl +1 == k)
         {
             cout << root->data << endl;
         }

         else
         {
            printAtDepthK(root->right, k-dl-2);
         }

         return dl+1;
     }

    // Recur for right subtree 
    int dr = IntnodesAtDistanceK(root->right, node, k);

    if (dr != -1)
     {
         if (dr +1 == k)
         {
             cout << root->data << endl;
         }

         else
         {
            printAtDepthK(root->left, k-dr-2);
         }

         return dr+1;
     }

     return -1;
}

void nodesAtDistanceK(BinaryTreeNode<int>* root, int node, int k) {

    int ans = IntnodesAtDistanceK(root, node, k);
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int targetNode, k;
    cin >> targetNode >> k;
    nodesAtDistanceK(root, targetNode, k);
    delete root;
}