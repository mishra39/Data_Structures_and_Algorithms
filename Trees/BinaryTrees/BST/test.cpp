
using namespace std;
/*
template <typename T>
T nodeValue(BinaryTreeNode<T> *node){
  return node->data.val;
}
vector<int>* maxDistinctPath(BinaryTreeNode<int> *node, vector<int>* visited){
  if (node == nullptr)
    return visited;
  else {
    vector<int>* left = maxDistinctPath<int>(node->left, visited);
    vector<int>* right = maxDistinctPath<int>(node->right, visited);
    if (find(left->begin(), left->end(), node->data) == left->end()) // if nodekey not present in left visited path
      left->push_back(node->data);
    if (find(right->begin(), right->end(), node->data) == right->end()) 
      right->push_back(node->data);
    return (left->size() > right->size() ? left : right);
  }
}

vector<int>* longestPath(BinaryTreeNode<int> *root){  // function call wrapper
  vector<int>* visited;
  return maxDistinctPath(node, visited);
}
*/

#include <iostream>
#include <vector>
using namespace std;
// Function to check if given node is a leaf node or not
bool isLeaf(BinaryTreeNode<int>* node)
{
    return (node->left == nullptr && node->right == nullptr);
}

// Recursive function to find paths from root node to every leaf node
void printRootToleafPaths(BinaryTreeNode<int>* node, vector<int> &path)
{
    // base case
    if (node == nullptr)
        return;

    // include current node to path vector
    path.push_back(node->data);

    // if leaf node is found, print the path
    if (isLeaf(node))
    {
        for (int data: path)
            cout << data << " ";
        cout << endl;
    }

    // recur for left and right subtree
    printRootToleafPaths(node->left, path);
    printRootToleafPaths(node->right, path);

    // remove current node after left and right subtree are done
    path.pop_back();
}

// Main function to print paths from root node to every leaf node
vector<int>* longestPath(BinaryTreeNode<int> *root){  // function call wrapper
{
    // vector to store root to leaf path
    vector<int>* path;

    printRootToleafPaths(root, path);
    return path;
}















/*
TreeNode<int>* removeLeafNodes(TreeNode<int>* root)
{ 
    // if root->children is a leaf node 
    // then delete it from children vector 
    for (int i = 0; 
         i < root->numChildren(); 
         i++) { 
  
        TreeNode* child = root->getChild(i); 
  
        // if it is  a leaf 
        if (child->numChildren() == 0) { 
  
            // shifting the vector to left 
            // after the point i 
            for (int j = i;  j < root->numChildren(); j++) 
            {
                removeChild(j);
                i--; 
        } 
    } 
    }
  
    // Remove all leaf node 
    // of children of root 
    for (int i = 0; i < root->numChildren(); i++)
    {
        removeNodes(root->getChild(i));
    }
    
    return root;
}*/