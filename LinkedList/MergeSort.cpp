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
};

node *takeinput()
{
    int data;
    cin >> data;
    node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        node *newNode = new node(data);
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

node* mergeTwoLLs(node *head1, node *head2)
{
    node *finalHead = NULL;
    node *finalTail = NULL;

    if (head1==NULL)
    {
        return head2;

    }

    if (head2==NULL)
    {
        return head1;

    }

    if (head1->data <= head2-> data)
    {
        finalTail = head1;
        finalTail->next = mergeTwoLLs(head1->next, head2);
    }
    else
    {
        finalTail = head2;
        finalTail->next = mergeTwoLLs(head1, head2->next);
    }

    return finalTail;
}

void print(node *head) {
    node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}


node* mergeSort(node *head) {

    if (head->next==NULL)
    {
        return head;
    }
    //Break the LL in half
    node *midNode = midpoint_linkedlist(head);
    node *temp = head;
    node *head2 = NULL;
    

    while(1)
    {
        if (temp==midNode)
        {
            head2 = midNode->next;
            midNode->next = NULL;
            break;
        }

        temp = temp -> next;
    }

    
    // Call recursion on halves
    node *L1 = mergeSort(head);
    node *L2 = mergeSort(head2);

    //merge two linked lists
    temp = mergeTwoLLs(head,head2);
    return temp;
}

int main()
{
    node* head=takeinput();
    head= mergeSort(head);
    print(head);
    return 0;
}