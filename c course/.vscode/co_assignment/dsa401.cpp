#include<iostream>
using namespace std;
class Queue
{
public:
    int *arr;
    int f;
    int r;
    int size;
    Queue(int d)
    {
        this->size = d;
        arr = new int[d];
        for(int i = 0;i<d;i++){
            arr[i]=0;
        }
        this->f = -1;
        this->r = -1;
    }
    bool isEmpty()
    {
        if (f == -1 && r == -1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if ((r + 1) % size == f)
            return true;
        else
            return false;
    }
    int front()
    {
        if (f == -1 && r == -1)
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        else
        {
            return arr[f];
        }
    }
    int rear()
    {
        if (f == -1 && r == -1)
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        else
            return arr[r];
    }
    void enQueue(int val)
    {
        if ((r + 1) % size == f)
        {
            cout << "Queue is Full" << endl;
            return;
        }
        else if (f == -1 && r == -1)
        {
            f++;
            r++;
            arr[r] = val;
        }
        else
        {
            r = (r + 1) % size;
            arr[r] = val;
        }
    }
    int deQueue()
    {
        if (f == -1 && r == -1)
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        else if (f == r)
        {
            int x = arr[f];
            arr[f]=0;
            f = -1;
            r = -1;
            return x;
        }
        else
        {   
            int x = arr[f];
            arr[f]=0;
            f = (f + 1) % size;
            return x;
        }
    }
    void print(){
        for(int i = 0;i<size;i++){
            if(arr[i]==0) cout << "_" << " ";
            else cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main(){
    Queue* q=new Queue(5);
    q->enQueue(5);
    q->deQueue();
    q->enQueue(6);
    q->enQueue(7);
    q->enQueue(8);
    q->print();
}