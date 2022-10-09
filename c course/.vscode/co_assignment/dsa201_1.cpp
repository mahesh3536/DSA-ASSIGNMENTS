#include <iostream>
using namespace std;
template<class T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T d)
    {
        this->data = d;
        this->next = NULL;
    }
};
template<class T>
class stack
{
public:
    Node<T> *top;
    stack()
    {
        top = NULL;
    }
    bool isEmpty()
    {
        if (top == NULL)
        {
            return true;
        }
        else
            return false;
    }
    void push(T data)
    {
        Node<T> *temp = new Node<T>(data);
        temp->next = top;
        top = temp;
    }
    void pop()
    {
        if (top == NULL)
        {
            cout << "stack is empty" << endl;
        }
        else
        {
            top = top->next;
        }
    }
    int peek()
    {
        if (top == NULL)
        {
            return -1;
        }
        else
            return top->data;
    }
};
int main()
{
    stack<int> *s = new stack<int>();
    int val;
    do
    {

        cout << "1.Enter 1 for push" << endl;
        cout << "2.Enter 2 for pop" << endl;
        cout << "3.Enter 3 for checking that stack is empty or not " << endl;
        cout << "4.Enter 4 for getting the data of peek element" << endl;
        cout << "5.Enter 5 for exit" << endl;
        cin >> val;
        switch (val)
        {
        case 1:
            {
            int d;
            cout << "Enter data for push:";
            cin >> d;
            s->push(d);
            }
            break;
        case 2:
            {
            cout << "Poping.." << endl;
            s->pop();
            }
            break;
        case 3:
            {
            bool t1 = s->isEmpty();
            if (t1)
            {
                cout << "stack is empty" << endl;
            }
            else
                cout << "stack is not empty" << endl;
            }
            break;
        case 4:
            {
            int p = s->peek();
            if (p == -1)
                cout << "stack is empty" << endl;
            else
                cout << "The top element is : " << p << endl;
            }
            break;
        }
    } while (val != 5);
}