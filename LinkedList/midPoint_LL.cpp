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

    while(fast->next != NULL && fast!=NULL)
    {
    	slow = slow -> next;
    	fast = fast -> next -> next;
    }

    return slow;
}

int main(){
    node*head=takeinput();
    node* mid=midpoint_linkedlist(head);
    cout<<mid->data;
    return 0;
}