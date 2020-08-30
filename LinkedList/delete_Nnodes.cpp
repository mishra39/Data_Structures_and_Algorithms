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

node* skipMdeleteN(node  *head, int M, int N) {
    
    if (head==NULL)
    {
        return head;
    }


    node *temp1 = head;
    node *temp2 = NULL;
    int count1 = 1;
    int count2 = 1;

    while (temp1!=NULL)
    {

        for (count1 = 1; count1 < M && temp1!=NULL; count1++)
        {
            temp1 = temp1 -> next; // keep M nodes
        }

        if (temp1==NULL)
        {
            return head;
        }

        temp2 = temp1->next;

        for (count2 = 1; count2 <= N && temp2!=NULL; count2++)
        {
            node *a = temp2;
            temp2 = temp2->next;
            delete a;
        }
        temp1->next = temp2;
        temp1 = temp2;
    }

    return head;
}

int main()
{
    node* head=takeinput();
    int m,n;
    cin>>m >> n;
    head= skipMdeleteN(head,m,n);
    print(head);
    return 0;
}