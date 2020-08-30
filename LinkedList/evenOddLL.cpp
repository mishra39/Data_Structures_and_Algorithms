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

node* arrange_LinkedList(node* head)
{   

    // special case(s)
    if (head==NULL || head->next==NULL)
    {
        return head;
    }


    // nodes for new linked lists
    node *oddH = NULL; node *oddT = NULL; node *evenH = NULL; node *evenT = NULL;
    int ind = 0;

    while(head!=NULL)
    {
        if (head->data %2 ==0)
        {
            if (evenH==NULL)
            {
                ind=2;
                evenH = head;
                evenT = head;
            }

            else
            {
                evenT->next = head;
                evenT = head;
            }
        }

        else
        {
            if (oddH==NULL)
            {   
                ind = 1;
                oddH = head;
                oddT = head;
            }

            else
            {
                oddT->next = head;
                oddT = head;
            }
        }
        head = head ->next;
    }

    if (oddT!=NULL)
    {
        oddT->next = NULL;
        oddT->next = evenH;
    }

    if (evenT!=NULL)
    {
        evenT->next = NULL;
    }


    return oddH;

}

int main()
{
    node*head=takeinput();
    head=arrange_LinkedList(head);
    print(head);
    return 0;
}