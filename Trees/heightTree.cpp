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

int height(TreeNode<int>* root)
{	
	int ans = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        int smallAns = height(root->children[i]);
        ans = (smallAns > ans) ? smallAns : ans;
    }
    
    ans +=1;
    
    return ans;
}