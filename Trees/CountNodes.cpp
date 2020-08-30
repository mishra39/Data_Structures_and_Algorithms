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

int nodesGreaterThanX(TreeNode<int> *root, int x) {

	int num = 0;
	cout << root->data << endl;
	if (root->data > x)
	{	
		cout << root->data << endl;
		return 1;
	}

	for (int i = 0; i < root->children.size(); i++)
	{
		num += nodesGreaterThanX(root->children[i],x); 
	}

	return num;
}

int main() {
    int x;
    cin >> x;
    TreeNode<int>* root = takeInputLevelWise();
    cout << nodesGreaterThanX(root, x) << endl;
}