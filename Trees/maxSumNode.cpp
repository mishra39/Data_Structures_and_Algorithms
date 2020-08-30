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


TreeNode<int>* maxSumNode(TreeNode<int> *root){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
	TreeNode<int>* ans = root;
	int sum = ans->data;

	for (int i = 0; i < root0>children.size(); i++)
	{
		sum += ans->children[i]->data;
	}

	for (int i = 0; i < root->children.size(); i++)
	{
		TreeNode<int>* x  =  maxSumNode(root->children[i]);
	}

	int sumx = x->data;

	for (int i = 0; i < x->children.size(); i++)
	{
		sumx += x->children[i]->data;
	}

	if (sumx > sum)
	{
		ans = x;
	}

	return ans; 
}
