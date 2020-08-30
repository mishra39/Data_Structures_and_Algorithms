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

void printLevelWise(BinaryTreeNode<int>* root)
{
	if (root==NULL)
	{
		return;
	}

	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);

	while(!pendingNodes.empty())
	{
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		
        cout << front->data << ":";
		if (front->left)
		{
			cout << "L:" << front->left->data << ",";
			pendingNodes.push(front->left);
		}

		else
		{
			cout << "L:" << "-1" << ",";
		}

		if (front->right)
		{
			cout << "R:" << front->right->data << endl;
			pendingNodes.push(front->right);
		}

		else
		{
			cout << "R:" << "-1" << endl;
		}
	}
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    printLevelWise(root);
}