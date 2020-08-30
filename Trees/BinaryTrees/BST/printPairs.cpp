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

#include <vector>
#include <algorithm>

int AddToArray(BinaryTreeNode<int>* node, int* arr, int i)
{
     if(node == NULL)
          return i;


     arr[i] = node->data;
     i++;
     if(node->left != NULL)
          i = AddToArray(node->left, arr, i);
     if(node->right != NULL)
          i = AddToArray(node->right, arr, i);

     return i;
}


void nodesSumToS(BinaryTreeNode<int> *root, int sum) {
    
    if (root == NULL)
    {
        return;
    }

    int *arr = new int[10000];
    int idx = 0;

    idx = AddToArray(root, arr, idx);
    sort(arr, arr+idx);
    
    int i = 0;
    int j = idx-1;

    while(i < j)
    {
        if (arr[i] + arr[j] > sum)
        {
            j--;
        }

        else if (arr[i] + arr[j] < sum)
        {
            i++;
        }

        else
        {
            cout << arr[i] << " " << arr[j] << endl;
            i++;
            j--; 
        }
    }

}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int sum;
    cin >> sum;
    nodesSumToS(root, sum);
    delete root;
}