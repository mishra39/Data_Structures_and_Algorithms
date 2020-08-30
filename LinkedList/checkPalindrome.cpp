#include <iostream>
#include <vector>
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

// Iterative function to reverse nodes of linked list
void reverse(Node* &head)
{
	Node* result = nullptr;
	Node* current = head;

	// Iterate through the list and move/insert each node to the
	// front of the result list (like a push of the node)
	while (current != nullptr)
	{
		// tricky: note the next node
		Node* next = current->next;

		// move the current node onto the result
		current->next = result;
		result = current;

		// process next node
		current = next;
	}

	// fix head pointer
	head = result;
}

// Recursive function to check if two linked lists are equal or not
bool compare(Node* a, Node* b)
{
	// see if both list is empty
	if (a == nullptr && b == nullptr)
		return true;

	return a && b && (a->data == b->data) && compare(a->next, b->next);
}

// Function to split the linked list into two equal parts and return
// pointer to the second half
Node* findMiddle(Node* head, bool &odd)
{
	Node* prev = nullptr;
	Node *slow = head, *fast = head;

	// find middle pointer
	while (fast && fast->next)
	{
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}

	// for odd nodes, fast still points to last node
	if (fast)
		odd = true;

	// make next of prev node null
	prev->next = nullptr;

	// return mid node
	return slow;
}

// Function to check if linked list is palindrome or not
bool isPalindrome(Node* head)
{
	// base case
	if (head == nullptr || head->next == nullptr)
		return true;

	// flag to indicate if number of nodes in the linked list is
	// odd or not. It will be passed by reference to findMiddle()
	bool odd = false;

	// find second half of linked list
	Node* mid = findMiddle(head, odd);

	// if number of nodes is odd, advance mid
	if (odd)
		mid = mid->next;

	// reverse the second half
	reverse(mid);

	// compare first and second half
	return compare(head, mid);
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

// Function to split the linked list into two equal parts and return
// pointer to the second half
Node *findMidAndReverse(Node *head, bool odd)
{
	Node *prev = NULL;
	Node *curr  = head, *next = head;

	// find middle pointer
	while(next!=NULL && next->next!=NULL)
	{
		prev = curr;
		curr = curr -> next;
		next = next->next->next;
	}

	// for odd nodes, next still points to last node
	if (next)
	{
		odd = true;
	}

	// make next of prev node null
	prev->next = NULL;

	// return mid node
	return curr;
}
/*bool isPalindrome(Node *head)
{
	if (head==NULL)
	{
		return true;
	}

	bool odd = false;

	Node *mid = findMidAndReverse(head, odd);

	int len = length(head); // length of linked list
	int mid = len/2; // mid-point of linked list
	Node *head2 = head; // node for second-half of linked list

	while(mid)
	{
		head2 = head2 -> next;
		mid--;
	}

	 // end first half with a null
	//Reversing the second half
	Node *prev = NULL;
	Node *curr = head;
	Node *next = NULL;

	while(curr!=NULL)
	{
		next = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = next;
	}

	head2 = prev;

	while(head!=NULL && head2!=NULL)
	{
		if (head->data != head2->data)
		{
			return false;
		}
	}
	return true;	
}*/

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		cout << isPalindrome(head);
	}
	return 0;
}