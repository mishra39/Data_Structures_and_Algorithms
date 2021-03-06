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
        node *newnode = new node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}

void print(node *head) {
    node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

node *kReverse(node *head, int k)
{
    if (head==NULL)
    {
        return head;
    }

    node *curr = head;
    node *prev = NULL;
    node *next = NULL;
    int count = 0;
    
    while(curr!=NULL && count<k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next!=NULL)
    {
        head->next = kReverse(next,k);
    }
    return prev;
}

int main()
{
    int i,j;
    node* head =takeinput();
    cin>>i;
    cin>>j;
    head=swap_nodes(head,i,j);
    print(head);
    return 0;
}