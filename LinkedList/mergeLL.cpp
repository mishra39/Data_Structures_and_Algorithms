#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node * next;
    Node(int data){
        this->data=data;
        this->next=NULL;
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

Node* mergeTwoLLs(Node *head1, Node *head2)
{
    Node *finalHead = NULL;
    Node *finalTail = NULL;

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

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main() {
    Node *head1 = takeinput();
    Node *head2 = takeinput();
    Node *head3 = mergeTwoLLs(head1, head2);
    print(head3);
    return 0;
}
