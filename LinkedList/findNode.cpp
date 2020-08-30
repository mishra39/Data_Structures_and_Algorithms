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

int length(Node *head)
{	
	if (head==NULL)
	{
		return 0;
	}
	
	int smallAns = length(head->next);
	return smallAns + 1;
}

Node *
int findNode(Node *head, int n)
{
    if (head==NULL)
    {
    	return -1;
    }

    if (head->data == n)
    {
    	return 0;
    }

    int smallAns = findNode(head->next, n);
    if (smallAns>=0)
    {
    	return smallAns+1;
    }

    else
    {
    	return smallAns;
    }
}



int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int val;
		cin >> val;
		cout << findNode(head, val) << endl;
	}
}S