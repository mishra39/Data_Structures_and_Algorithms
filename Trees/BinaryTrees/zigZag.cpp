#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
#include <vector>
#include <stack>
using namespace std;

template <typename T>
class node
{
public:
    T data;
    node<T>* next;

    node(T data)
    {
        this->data = data; 
        this->next = NULL;
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

void print(node<int> *head)
{
    node<int> *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void zigZagOrder(BinaryTreeNode<int> *root) 
{
    if (root == NULL)
    {
        return;
    }

    stack<BinaryTreeNode<int>*> s1;
    s1.push(root);

    while(!s1.empty())
    {
        BinaryTreeNode<int>* top = s1.top();
        s1.pop();
        cout << top->data;

        if (top->left != NULL)
        {
            s2.push(top->left);
        }

        if (top->right != NULL)
        {
            s2.push(top->right);
        }

        cout << endl;

        while(!s2.empty())
        {
            BinaryTreeNode<int>* top2 = s2.top();
            s2.pop();

            cout << top2->data;

            if (top2->right != NULL)
            {
                s1.push(top2->right);
            }

            if (top2->left != NULL)
            {
                s1.push(top2->left);
            }
        }

        cout << endl;      
    }
}


int main() {
    BinaryTreeNode<int>* root = takeInput();
    vector<node<int>*> ans = createLLForEachLevel(root);
    for(int i = 0; i < ans.size(); i++) {
        print(ans[i]);
    }
}