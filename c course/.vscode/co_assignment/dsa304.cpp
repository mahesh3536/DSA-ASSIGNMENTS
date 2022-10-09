#include <iostream>
using namespace std;
int mod = (int)1e9 + 7;
class Node
{
public:
    int power;
    int coefficient;
    Node *next;
    Node(int p, int c)
    {
        this->power = p;
        this->coefficient = c;
        this->next = NULL;
    }
    Node()
    {
        this->power = 0;
        this->coefficient = 0;
        this->next = NULL;
    }
};
int pow1(int a, int b)
{
    if (b == 0)
        return 1;
    int result = pow1(a, b / 2);
    if (b % 2 == 1)
        return ((result * result) % mod * a) % mod;
    else
        return (result * result) % mod;
}
void insertAtTail(Node *&tail, int power, int coefficient)
{
    Node *temp = new Node(power, coefficient);
    tail->next = temp;
    temp->next = NULL;
    tail = temp;
}
int result(Node *head, int x)
{
    Node *curr = head;
    int sum = 0;
    while (curr != NULL)
    {
        sum = sum + (curr->coefficient) * pow1(x, curr->power);
        curr = curr->next;
    }
    return sum;
}
int main()
{
    Node *head = new Node();
    Node *tail = head;
    cout << "Entering data in list1..." << endl;
    int val;
    do
    {
        cout << "Enter 1 for inserting data in list..." << endl;
        cout << "Enter number other than 1 to exit " << endl;
        cin >> val;
        if (val != 1)
            break;
        int power;
        cout << "Enter power : ";
        cin >> power;
        int coefficient;
        cout << "Enter coefficient : ";
        cin >> coefficient;
        insertAtTail(tail, power, coefficient);
    } while (val == 1);
    int x;
    cout << "Enter value of variable x : ";
    cin >> x;
    cout << result(head->next, x);
}