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
int main(){
    stack<int> *s1=new stack<int>();
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s1->isEmpty()){
            s1->push(s[i]);
        }
        else if((s[i]==')' && s1->peek()=='(') || (s[i]=='}' && s1->peek()=='{') || (s[i]==']' && s1->peek()=='[')){
            s1->pop();
        }
        else{
            s1->push(s[i]);
        }
    }
    
    if(s1->isEmpty()) cout<<"Balanced"<<endl;
    else cout<<"Unbalanced"<<endl;
}