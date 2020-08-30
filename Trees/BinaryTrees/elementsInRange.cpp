#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
using namespace std;

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

void printLevelATNewLine(BinaryTreeNode<int> *root) {
        queue<BinaryTreeNode<int>*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            BinaryTreeNode<int> *first = q.front();
            q.pop();
            if(first == NULL) {
                if(q.empty()) {
                    break;
                }
                cout << endl;
                q.push(NULL);
                continue;
            }
            cout << first -> data << " ";
            if(first -> left != NULL) {
                q.push(first -> left);
            }
            if(first -> right != NULL) {
                q.push(first -> right);
            }
        }
}

void printCheck(BinaryTreeNode<int>* root, int k1, int k2)
{
    if (root->data >= k1 && root->data <= k2)
    {
        cout << root->data << " ";
    }
}

void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {

    if (root == NULL)
    {
        return;
    }

    if (root->data > k1)
    {
        elementsInRangeK1K2(root->left, k1, k2);
    }

    printCheck(root, k1, k2);

    if (root->data < k2)
    {
        elementsInRangeK1K2(root->right, k1, k2);
    }
}


int main() {
    int size;
    cin >> size;
    int *pre = new int[size];
    int *in = new int[size];
    for(int i=0;i<size;i++)
        cin>>pre[i];
    for(int i=0;i<size;i++)
        cin>>in[i];
    BinaryTreeNode<int>* root = buildTree(pre, size, in, size);
    printLevelATNewLine(root);
}