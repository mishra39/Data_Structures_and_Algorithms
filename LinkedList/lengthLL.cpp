#include <iostream>
#include <vector>
using namespace std;

class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
}

node* midpoint_linkedlist(node *head)
{
    node *slow = head;
    node *fast = head->next;

}