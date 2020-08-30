#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
#include <vector>
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

vector<node<int>*> createLLForEachLevel(BinaryTreeNode<int>* root)
{
    vector<node<int>*> output;
    
    if (root == NULL)
    {
        return output;
    }       

    node<int>* head = NULL;
    node<int>* tail = NULL;
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);

    while(!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        if (front != NULL)
        {
            node<int>* newNode = new node<int>(front->data);

            if (head == NULL)
            {
                head = newNode;
                tail = newNode;
                pendingNodes.push(front->left);
                pendingNodes.push(front->right);
                // 2 4 5 7 8 10 11 -1 -1 -1 -1 -1 -1 -1 -1
            }

            else
            {
                tail->next = newNode;
                tail = tail->next;
                pendingNodes.push(front->left);
                pendingNodes.push(front->right);
            }
        }

        else
        {

            output.push_back(head);
            head = NULL;
            tail = NULL;

            if (!pendingNodes.empty())
            {
                pendingNodes.push(NULL);
            }
        }
    
    }

return output;
}


int main() {
    BinaryTreeNode<int>* root = takeInput();
    vector<node<int>*> ans = createLLForEachLevel(root);
    for(int i = 0; i < ans.size(); i++) {
        print(ans[i]);
    }
}