#include<iostream>
using namespace std;
template<class T>
class stack{
    public:
    T* arr;
    int top;
    int size;
    stack(int s){
        this->size=s;
        arr=new int[s];
        top=-1;
    }
    void push(T data){
        if(size-top>1){
            top++;
            arr[top]=data;
        }
        else{
            cout<<"stack is full"<<endl;
        }
    }
    bool isEmpty(){
        if(top==-1) return true;
        else return false;
    }
    bool isFull(){
        if(top==size-1) return true;
        else return false;
    }
    void pop(){
        if(top==-1){
            cout<<"stack is empty"<<endl;
        }
        else{
            top--;
        }
    }
    int peek(){
        if(top==-1){
            cout<<"stack is empty"<<endl;
            return -1;
        }
        else{
           return arr[top];
        }
    }
};
int main()
{
    stack<int> *s = new stack<int>(1);
    int val;
    do
    {

        cout << "1.Enter 1 for push" << endl;
        cout << "2.Enter 2 for pop" << endl;
        cout << "3.Enter 3 for checking that stack is empty or not " << endl;
        cout<<"4.Enter 4 for checking that stack is full or not " << endl;
        cout << "5.Enter 5 for getting the data of peek element" << endl;
        cout << "6.Enter 6 for exit" << endl;
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
                bool t = s->isFull();
                if(t) {
                    cout << "stack is full" <<endl;
                }
                else cout << "stack is not full"<<endl;
            }
            break;
        case 5:
            {
            int p = s->peek();
            if (p == -1)
                cout << "stack is empty" << endl;
            else
                cout << "The top element is : " << p << endl;
            }
            break;
        
        }
    } while (val != 6);
}