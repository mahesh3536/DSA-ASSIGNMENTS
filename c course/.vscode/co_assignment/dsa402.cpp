#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};
class queue
{
public:
    Node *front;
    Node *rear;
    queue()
    {
        this->front = NULL;
        this->rear = NULL;
    }
    bool empty()
    {
        if (front == rear && front == NULL)
        {
            return true;
        }
        else
            return false;
    }
    void push(int d)
    {
        Node *temp = new Node(d);
        if (front == rear && front == NULL)
        {
            front = temp;
            rear = temp;
        }
        else
        {
            rear->next = temp;
            temp->next = NULL;
            rear = temp;
        }
    }
    int peek()
    {
        if (front == rear && front == NULL)
        {
            return -1;
        }
        else
            return front->data;
    }
    void pop()
    {
        if (front == rear && front == NULL)
        {
            cout << "queue is empty" << endl;
        }
        else
        {
            front = front->next;
        }
    }
    int back()
    {
        if (front == rear && front == NULL)
        {
            return -1;
        }
        else
            return rear->data;
    }
    void print()
    {
        Node* temp = front;
        while(temp!=NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
class stack{
     public:
     queue* q;
     int  pop(){
        if(q->front == NULL && q->rear==NULL) {
            cout << "stack is empty" << endl;
            return -1;
        }
        else {
            int p = q->front->data;
            q->pop();
            return p;
        }
     }
     bool isEmpty(){
        if(q->front==NULL && q->rear==NULL){
            return true;
        }
        else return false;
     }
     int top(){
        if(q->front == NULL && q->rear==NULL){
            cout << "stack is empty" << endl;
            return -1;
        }
        else return q->front->data;
     };
     void push(int d){
        if(q->front==NULL && q->rear==NULL){
            q->push(d);
        }
        else {
            Node* temp = new Node(d);
            temp->next = q->front;
            q->front = temp;
        }
     }
     void print(){
        if(q->front==NULL && q->rear==NULL) {
            cout << "stack is empty" << endl;
            return;
        }
        else {
            q->print();
        }
     }

};
int main(){
    queue* q1 = new queue();
    q1->print();
    stack* s ;
    s->q=q1;
    int val ;
    do{
        cout << "1.Enter 1 for push " << endl;
        cout << "2.Enter 2 for pop " << endl;
        cout << "3.Enter 3 for printing queue" << endl;  
        cout << "4.Enter 4 for top element" << endl;
        cout << "5.Enter 5 for stack empty or not" << endl;
        cout << "6.Enter 6 for exit"<<endl;
        cout << "Enter val : " ;
        cin >> val;
        switch(val){
            case 1:
            {   
                int data;
                cout << "Enter data : ";
                cin>>data;
                s->push(data);
            }
            break;
            case 2:
            {
                if(s->isEmpty()) cout << "stack is Empty" << endl;
                else {
                    cout << "Poped element is : " << s->pop() << endl;
                }
            }
            break;
            case 3:
            {
                if(s->isEmpty()) cout << "stack is empty" << endl;
                else {
                    cout << "Printint the queue..."<< endl;
                   s->print();
                }
            }
            break;
            case 4:
            {
                if(s->isEmpty()) cout << "stack is empty" << endl;
                else {
                    cout << "The top element is : " << s->top() << endl;
                }
            }
            break;
            case 5:
            {
                if(s->isEmpty()) cout << "stack is empty" << endl;
                else cout << "stack is not empty " << endl;
            }
        }
    }while(val!=6);
    
}