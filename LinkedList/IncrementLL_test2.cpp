#include <iostream>
#include <stack>
using namespace std;


class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};


int addWithCarry(Node *head)
{
	if (head==NULL)
	{
		return 1;
	}

	int res = head->data + addWithCarry(head->next);

	head->data = (res) % 10;
	return (res)/data;
}

Node* NextLargeNumber(Node *head) {
    if (head==NULL)
        {
        	return head;
        }


    int carry = addWithCarry(head);

    if (carry)
    {
    	Node *newNode = new Node;
    	newNode->data = carry;
    	newNode->next = head;
    	return newNode;
    }

    return head;
}

