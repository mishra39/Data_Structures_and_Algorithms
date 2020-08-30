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

Node *appendLastNToFirst(Node *head, int n)

{
	if (head!=NULL && n)
	{
	int len = length(head);
	int i = 1;
	Node *cur = head;
	int count = len-n;

	while(i<count)
	{
		cur = cur->next;
		i++;
	}

	Node *head2 = cur->next ;
	cur->next = NULL;
	Node *temp = head2;
	while(temp!=NULL)
	{
		if(temp->next==NULL)
		{
			temp->next = head;
			return head2;
		}
		else
		{
			temp = temp->next;
		}
	}

	return head2;
}

else
{
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
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}