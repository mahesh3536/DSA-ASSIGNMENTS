#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};
void insertAtTail(Node *&head, Node *&tail, int d)
{
    if (head == NULL && tail == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
void display(Node *&head)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}
Node *mergeTwoLists(Node *list1, Node *list2)
{
    Node *temp1 = list1;
    Node *temp2 = list2;
    Node *temp3 = NULL;
    Node *tail = temp3;
    while (temp1 != NULL || temp2 != NULL)
    {
        if (temp1 == NULL && temp2 != NULL)
        {
            int d = temp2->data;

            insertAtTail(temp3, tail, d);

            temp2 = temp2->next;
        }
        else if (temp1 != NULL && temp2 == NULL)
        {
            int d = temp1->data;
            insertAtTail(temp3, tail, d);
            temp1 = temp1->next;
        }
        else if (temp1->data < temp2->data)
        {
            int d = temp1->data;
            insertAtTail(temp3, tail, d);
            temp1 = temp1->next;
        }
        else
        {
            int d = temp2->data;
            insertAtTail(temp3, tail, d);
            temp2 = temp2->next;
        }
    }
    return temp3;
}

Node *findmid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next;
        fast = fast->next;
    }
    return slow;
}
Node *sortList(Node *head)
{
    if (head == NULL)
        return head;
    if (head->next == NULL)
        return head;
    Node *mid = findmid(head);
    Node *right = mid->next;
    right->prev = NULL;
    mid->next = NULL;
    Node *left = sortList(head);
    Node *r1 = sortList(right);
    return mergeTwoLists(left, r1);
}
int main()
{
    Node *head1 = NULL;
    Node *tail1 = head1;
    cout << "Entering data in list1..." << endl;
    int val;
    do
    {
        cout << "Enter 1 for inserting data in list..." << endl;
        cout << "Enter number other than 1 to exit " << endl;
        cin >> val;
        if (val != 1)
            break;
        int data;
        cout << "Enter data : ";
        cin >> data;
        insertAtTail(head1, tail1, data);
    } while (val == 1);
    display(head1);
    Node *sortedList = sortList(head1);
    display(sortedList);
}