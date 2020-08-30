#include <iostream>
#include <vector>
#include <queue>
#include "TreeNode.h"
using namespace std;

TreeNode<int>* takeInputLevelWise()
{	
	// Data for root node
	int rootData;
	cin >> rootData;

	// Create root node
	TreeNode<int>* root = new TreeNode<int>(rootData);

	// queue for lining up nodes
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);

	while(!pendingNodes.empty())
	{
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();

		for (int i = 0; i < front->children.size(); ++i)
		{	
			int childData;
			cin >> childData;
			TreeNode<int>* child = new TreeNode<int>(childData);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}

	return root;
}

bool containsX(TreeNode<int>* root, int x) {

	if (root==NULL)
	{
		return false;
	}

	if (root->data == x)
	{
		return true;
	}

	bool smallAns = containsX(root->children[i]);
	
	if (smallAns) {
		return true;
	}


	for (int i = 0; i < root->children.size(); i++)
	{
		bool smallAns = containsX(root->children[i],x);
		if (smallAns)
		{
			break;
		}
	}
}

int main() {
    int x;
    cin >> x;
    TreeNode<int>* root = takeInputLevelWise();
    if(containsX(root, x)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}