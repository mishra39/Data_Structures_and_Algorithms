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
TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    TreeNode<int>* max1=NULL;
    TreeNode<int>* max2;
    
    for(int i=0;i<root->children.size();i++)
    {
        max2=maxDataNode(root->children[i]);
        if(max1==NULL)
            max1=max2;
        else
        if(max1->data<max2->data)
         {
        max1=max2;
         }    
    }
    if(max1==NULL)
    {
        return root;
    }
    else
        if(max1->data<root->data)
   return root;
    else
        return max1;
}