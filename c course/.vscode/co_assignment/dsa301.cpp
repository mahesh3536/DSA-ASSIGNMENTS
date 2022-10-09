#include <iostream>
using namespace std;
class node
{

public:
    int data;
    node *next;
    node()
    {
        this->data = 0;
        this->next = NULL;
    }
    node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};
void inserttail(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    temp->next = NULL;
    tail = temp;
}
void inserthead(node *&head, int d)
{
    node *temp = new node(d);
    temp->next = head;
    // head->next=NULL;
    head = temp;
}
void insertAtposition(node *&head, node *&tail, int position, int d)
{
    if (position == 1)
    {
        inserthead(head, d);
        return;
    }

    node *temp = head;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        inserttail(tail, d);
        return;
    }

    node *insert = new node(d);
    // temp->next=insert;
    insert->next = temp->next;
    temp->next = insert;
}

void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
node *even(node *&head)
{
    node *temp = new node();
    int count = 1;
    node *curr = head;
    node *tail = temp;
    while (curr != NULL)
    {
        if (count % 2 == 0)
        {
            node *temp1 = new node(curr->data);
            tail->next = temp1;
            temp1->next = NULL;
            tail = temp1;
        }
        curr = curr->next;
        count++;
    }
    return temp->next;
}
node *odd(node *&head)
{
    node *temp = new node();
    int count = 1;
    node *curr = head;
    node *tail = temp;
    while (curr != NULL)
    {
        if (count % 2)
        {
            node *temp1 = new node(curr->data);
            tail->next = temp1;
            temp1->next = NULL;
            tail = temp1;
        }
        curr = curr->next;
        count++;
    }
    return temp->next;
}
int main()
{
    node *head = new node();
    node *tail = head;
    int n;
    cout << "Enter the size of linked list : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        inserttail(tail, data);
    }

    node *e = even(head->next);
    node *o = odd(head->next);
    print(e);
    print(o);
}