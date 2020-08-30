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

node *swap_nodes(node *head, int i, int j)
{
    if (head==NULL)
    {
        return head;
    }

    if (i==j)
    {
        return head;
    }
    node *p1= NULL;
    node *c1= head;
    node *p2= NULL;
    node *c2= head;    
    
    for (int k = 1; k < i && c1 !=NULL; k++)
    {
      p1 = c1;
      c1 = c1->next;   
    }

    for (int k = 1; k <= j && c2 !=NULL; k++)
    {
      p2 = c2;
      c2 = c2->next;   
    }

    if (c1==NULL || c2==NULL)
    {
        return head;
    }
    if (p1!=NULL)
    {
        p1->next = c2;
    }
    else
    {
        head = c2;
    }

    if (p2!=NULL)
    {
        p2->next = c1;
    }
    else
    {
        head = c1;
    }    

    node *temp = c2->next;
    c2->next = c1->next;
    c1->next  = temp;

    return head;
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