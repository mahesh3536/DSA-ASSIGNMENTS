#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};
void inserttail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    temp->next = NULL;
    tail = temp;
}
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node *mergeTwoLists(Node *list1, Node *list2)
{
    Node *temp1 = list1;
    Node *temp2 = list2;
    Node *temp3 = new Node(0);
    Node *tail = temp3;
    while (temp1 != NULL || temp2 != NULL)
    {
        if (temp1 == NULL && temp2 != NULL)
        {
            int d = temp2->data;
            Node *temp = new Node(d);

            tail->next = temp;
            temp->next = NULL;
            tail = temp;

            temp2 = temp2->next;
        }
        else if (temp1 != NULL && temp2 == NULL)
        {
            int d = temp1->data;
            Node *temp = new Node(d);

            tail->next = temp;
            temp->next = NULL;
            tail = temp;
            temp1 = temp1->next;
        }
        else if (temp1->data < temp2->data)
        {
            int d = temp1->data;
            Node *temp = new Node(d);

            tail->next = temp;
            temp->next = NULL;
            tail = temp;
            temp1 = temp1->next;
        }
        else
        {
            int d = temp2->data;
            Node *temp = new Node(d);

            tail->next = temp;
            temp->next = NULL;
            tail = temp;

            temp2 = temp2->next;
        }
    }
    return temp3->next;
}
int main()
{
    Node *head1 = new Node();
    Node *tail1 = head1;
    Node *head2 = new Node();
    Node *tail2 = head2;
    int size1;
    int size2;
    cout << "Enter size of list1 : ";
    cin >> size1;
    for (int i = 0; i < size1; i++)
    {
        int data;
        cin >> data;
        inserttail(tail1, data);
    }
    cout << "Enter size of list2 : ";
    cin >> size2;
    for (int i = 0; i < size2; i++)
    {
        int data;
        cin >> data;
        inserttail(tail2, data);
    }
    Node *merge = mergeTwoLists(head1->next, head2->next);
    print(merge);
}