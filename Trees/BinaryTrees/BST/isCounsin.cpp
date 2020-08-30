#include <bits/stdc++.h> 
#include <queue>
using namespace std; 
  

// A utility function to create a new 
// Binary Tree BinaryTreeNode<int> 

  struct Node* newNode(int item) 
{ 
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
// Returns true if a and b are cousins, 
// otherwise false. 
bool isCousin(BinaryTreeNode<int>* root, BinaryTreeNode<int>* a, BinaryTreeNode<int>* b) 
{ 
    if (root == NULL) 
        return false; 
  
    // To store parent of node a. 
    BinaryTreeNode<int>* parA;
  
    // To store parent of node b. 
    BinaryTreeNode<int>* parB ; 
  
    // queue to perform level order 
    // traversal. Each element of 
    // queue is a pair of node and 
    // its parent. 
    queue<pair<BinaryTreeNode<int>*, BinaryTreeNode<int>*> > q; 
  
    // Dummy node to act like parent 
    // of root node. 
    BinaryTreeNode<int>* tmp = newBinaryTreeNode<int>(-1); 
  
    // To store front element of queue. 
    pair<BinaryTreeNode<int>*, BinaryTreeNode<int>*> ele; 
  
    // Push root to queue. 
    q.push(make_pair(root, tmp)); 
    int levSize; 
  
    while (!q.empty()) { 
  
        // find number of elements in 
        // current level. 
        levSize = q.size(); 
        while (levSize) { 
  
            ele = q.front(); 
            q.pop(); 
  
            // check if current node is node a 
            // or node b or not. 
            if (ele.first->data == a->data) { 
                parA = ele.second; 
            } 
  
            if (ele.first->data == b->data) { 
                parB = ele.second; 
            } 
  
            // push children of current node 
            // to queue. 
            if (ele.first->left) { 
                q.push(make_pair(ele.first->left, ele.first)); 
            } 
  
            if (ele.first->right) { 
                q.push(make_pair(ele.first->right, ele.first)); 
            } 
  
            levSize--; 
  
            // If both nodes are found in 
            // current level then no need 
            // to traverse current level further. 
            if (parA && parB) 
                break; 
        } 
  
        // Check if both nodes are siblings 
        // or not. 
        if (parA && parB) { 
            return parA != parB; 
        } 
  
        // If one node is found in current level 
        // and another is not found, then 
        // both nodes are not cousins. 
        if ((parA && !parB) || (parB && !parA)) { 
            return false; 
        } 
    } 
  
    return false; 
} 