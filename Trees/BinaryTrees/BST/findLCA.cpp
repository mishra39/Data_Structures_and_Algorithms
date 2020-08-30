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

    if (rootData==NULL)
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
        if (leftNodeData != NULL)
        {
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftNodeData);
            front->left = child;
            pendingNodes.push(child);
        }

        cout << "Enter right child of" << front->data << endl;
        int rightNodeData;
        cin >> rightNodeData;
        if (rightNodeData != NULL)
        {
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightNodeData);
            front->right = child;
            pendingNodes.push(child);
        }
     }

     return root;
}

#include <vector>
#include <algorithm>

int lcaBinaryTree(BinaryTreeNode <int>* root , int val1, int val2){
  
  if (root == NULL)
  {
    return -1;
  }

  if (val1 == root->data || val2 == root->data)
  {
    return root->data;
  }

  int a = lcaBinaryTree(root->left,  val1, val2);
  int b = lcaBinaryTree(root->right, val1, val2);

  if (a!=-1 && b == -1)
  {
    return a;
  }

  else if(b!=-1 && a == -1)
  {
    return b;
  }

  else if(a!=-1 && b!= -1)
  {
    return root->data;
  }

  else if (a== -1 && b == -1)
  {
    return -1;
  }
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    int sum;
    cin >> sum;
    nodesSumToS(root, sum);
    delete root;
}