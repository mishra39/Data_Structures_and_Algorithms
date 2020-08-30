#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}


void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}


Node *removeDuplicates(Node *head)
{	
	
	Node *temp1 = head;
	Node *temp2;

	if (temp1 == NULL)
	{
		return head;
	}
	
    while(temp1->next != NULL)
    {
    	if (temp1->data == temp1->next->data)
    	{
    		temp2 = temp1->next->next;
    		Node *b = temp1->next;
    		delete b;
    		temp1->next = temp2;
    	}

    	else
    	{
    		temp1 = temp1 -> next;
    	}
    	
    }
    return head;

}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		head = removeDuplicates(head);
		print(head);
	}
	return 0;
}