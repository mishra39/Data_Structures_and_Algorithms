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


void nodesWithoutSibling(BinaryTreeNode<int> *root) {

	if (root == NULL)
	    {
	    	return;
	    }

	if (root-> left || root->right)
	{
		if (root->left && root->right == NULL) {cout << root->left->data << endl;}
		else if (root->right && root->left == NULL) {cout << root->right->data << endl;}
	}

	nodesWithoutSibling(root->left);
	nodesWithoutSibling(root->right);
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    vector<node<int>*> ans = createLLForEachLevel(root);
    for(int i = 0; i < ans.size(); i++) {
        print(ans[i]);
    }
}

