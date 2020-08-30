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

void printLevelATNewLine(BinaryTreeNode<int> *root) {
        queue<BinaryTreeNode<int>*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            BinaryTreeNode<int> *first = q.front();
            q.pop();
            if(first == NULL) {
                if(q.empty()) {
                    break;
                }
                cout << endl;
                q.push(NULL);
                continue;
            }
            cout << first -> data << " ";
            if(first -> left != NULL) {
                q.push(first -> left);
            }
            if(first -> right != NULL) {
                q.push(first -> right);
            }
        }
}


BinaryTreeNode<int>* getTreeFromPostorderAndInorderHelper(int *postorder,
						int* inorder, int inS, int inE, int postS, 
						int postE) {

	if (inS > inE)
	{
		return NULL;
	}

	int rootData = postorder[postE];
	int rootIndex = -1;

	for (int i = 0; i <= inE; i++)
	{
		if (inorder[i]==rootData)
		{
			rootIndex = i;
			break;
		}
	}

	int LinS = inS;
	int LinE = rootIndex - 1;
	int LpoS = postS;
	int LpoE = LinE - LinS + LpoS;
	int RinS = rootIndex + 1;
	int RinE = inE;
	int RpoS = LpoE + 1;
	int RpoE = RinE - RinS + RpoS;

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	root->left = getTreeFromPostorderAndInorderHelper(postorder, inorder, LinS, LinE, LpoS, LpoE);
	root->right = getTreeFromPostorderAndInorderHelper(postorder, inorder, RinS, RinE, RpoS, RpoE);

	return root; 
}


BinaryTreeNode<int>* getTreeFromPostorderAndInorder(int *postorder, int postLength, 
					int *inorder, int inLength)

{
	return getTreeFromPostorderAndInorderHelper(postorder, inorder, 0, inLength-1, 0, postLength-1);
}


int main() {
    int size;
    cin >> size;
    int *pre = new int[size];
    int *in = new int[size];
    for(int i=0;i<size;i++)
        cin>>pre[i];
    for(int i=0;i<size;i++)
        cin>>in[i];
    BinaryTreeNode<int>* root = buildTree(pre, size, in, size);
    printLevelATNewLine(root);
}