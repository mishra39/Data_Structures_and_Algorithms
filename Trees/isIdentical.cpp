#include <iostream>
#include <vector>
#include "TreeNode.h"
#include <queue>

using namespace std;

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    
    queue<TreeNode<int>*> pendingNodes;
    
    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

void print(TreeNode<int>* root)
{
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(!pendingNodes.empty())
	{
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << front->data << ": ";
		for (int i = 0; i < front->children.size(); i++)
		{
			cout << front->children[i]->data <<",";
			pendingNodes.push(front->children[i]);
		}

		cout << endl;
	}
}
bool isIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {

 if (root1==NULL || root2==NULL)
    {
        return false;
    }
    
    if (root1->children.size() != root2->children.size())
    {
        return false;
    }
	if (root1->data == root2->data)
	{
		for (int i = 0; i < root2->children.size(); ++i)
		{
			bool smallAns = isIdentical(root1->children[i], root2->children[i]);
		}
	}

	else
	{
		return false;
	}

	return true;
}
