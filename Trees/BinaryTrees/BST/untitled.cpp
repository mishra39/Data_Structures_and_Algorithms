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

#include<vector>

vector<int>* getRootToNodePath(BinaryTreeNode<int>* root, int data)
{
    if (root==NULL)
    {
        return NULL;
    }

    if (root->data ==  data)
    {
        vector<int>* output = new vector<int>();
        output->push_back(root->data);
        return output;
    }

    std::vector<int> leftOutput = getRootToNodePath(root->left, data);

    if (leftOutput != NULL)
    {
        leftOutput->push_back(root->data);
        return leftOutput;
    }

    std::vector<int> rightOutput = getRootToNodePath(root->right, data);
    if (rightOutput!=NULL)
    {
        rightOutput.push_back(root->data);
        return rightOutput;
    }

    else
    {
        return NULL;
    }
}


void insertDuplicateNode(BinaryTreeNode<int> *root) {
    
    BinaryTreeNode<int>* oldLeft;

    if (root == NULL)
    {
        return;
    }

    insertDuplicateNode(root->left);
    insertDuplicateNode(root->right);

    oldLeft = root->left;
    root->left = new BinaryTreeNode<int>(root->data);
    (root->left)->left  = oldLeft;
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise();
    std::vector<int> v = getRootToNodePath(root, 8);    
}