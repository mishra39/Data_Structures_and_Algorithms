#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
#include <algorithm>    // std::max

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

#include <algorithm>
#include <bits/stdc++.h>

int depth(BinaryTreeNode<int>* root)
{
    if (root == NULL)
    {
        return 0;
    }

    return 1 + max( depth(root->left), depth(root->right));
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {

    if (root == NULL)
    {
        return;
    }

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);

    while(!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        if (front != NULL)
        {
            cout << front->data;

            if (front->left !=NULL)
            {
                pendingNodes.push(front->left);
            }

            if (front->right !=NULL)
            {
                pendingNodes.push(front->right);
            }
        }

        else
        {
            if (pendingNodes.empty())
            {
                break;
            }

            else
            {
                cout << endl;
                pendingNodes.push(NULL);
            }
        }
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