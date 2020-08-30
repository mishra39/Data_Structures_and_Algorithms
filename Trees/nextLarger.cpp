#include <iostream>
#include <vector>
#include "TreeNode.h"
#include <queue>
#include<bits/stdc++.h> 

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

TreeNode<int>* nextLargerElement(TreeNode<int> *root, int n) {

   TreeNode<int>* ans = NULL;
   TreeNode<int>* temp = NULL;

   if (root->data > n)
   {
   		ans = root;
   }

   for (int i = 0; i < root->children.size(); i++)
   {
   		temp = nextLargerElement(root->children[i],n);
   }


   if (ans == NULL)
   {
   	 	ans = temp;
   }

   else if (temp!=NULL && (temp->data < ans->data))
   {
   		ans = temp;
   }

   return ans;
}

int main() {
    int n;
    cin >> n;
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = nextLargerElement(root, n);
    if(ans != NULL) {
        cout << ans -> data << endl;
    }
    else {
        cout << INT_MIN << endl;
    }
}