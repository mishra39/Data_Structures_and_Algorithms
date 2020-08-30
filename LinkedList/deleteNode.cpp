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

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

Node *deleteNode(Node *head, int pos)
{
	Node *temp = head;
	int count = 0;

	if (pos==0)
	{
		head = temp->next;
    	delete temp;
    	return head;
	}

	while(temp != NULL && count < pos-1)
	{
		temp = temp -> next;
		count++;
	}

	if(temp==NULL || temp->next==NULL) {
        return head;
	}

	if (temp!=NULL)
    {
    	Node *a = temp -> next;
    	Node *b = a -> next;
    	temp ->  next = b;
    	delete a;
    	return head;
    }
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		int pos;
		cin >> pos;
		head = deleteNode(head, pos);
		//cout << head->next << endl;

		print(head);
	}

	return 0;
}