#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
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

void secondLargestUtil(TreeNode<int>* root, TreeNode<int>** first, 
                       TreeNode<int>** second) {
	if (root == NULL) 
        return; 
  
    // If first is NULL, make root equal to first 
    if (!(*first)) 
        *first = root; 
  
    // if root is greater than first then second 
    // will become first and update first equal 
    // to root 
    else if (root->data > (*first)->data) { 
        *second = *first; 
        *first = root; 
    } 
  
    // If root is less than first but greater than 
    // second 
    else if (!(*second) || root->data > (*second)->data) 
        *second = root; 
  
    // number of children of root 
    int numChildren = root->children.size(); 
  
    // recursively calling for every child 
    for (int i = 0; i < numChildren; i++) 
        secondLargestUtil(root->children[i], first, second);
} 
  
TreeNode<int>* secondLargest(TreeNode<int>* root) 
{ 
    // second will store the second highest value 
    TreeNode<int>* second = NULL; 
  
    // first will store the largest value in the tree 
    TreeNode<int>* first = NULL; 
  
    // calling the helper function 
    secondLargestUtil(root, &first, &second); 
  
    if (second == NULL) 
        return NULL; 
  
    // This handles the case when every element in tree are same. 
    if (first->data == second->data) 
        return NULL; 
  
    // return the second largest element 
    return second; 
} 

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = secondLargest(root);
    if(ans == NULL) {
        cout << INT_MIN << endl;
    }
    else {
        cout << ans -> data << endl;
    }
}