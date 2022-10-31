#include <iostream>
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
        for (int i = 0; i < d; i++)
        {
            arr[i] = 0;
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
            arr[f] = 0;
            f = -1;
            r = -1;
            return x;
        }
        else
        {
            int x = arr[f];
            arr[f] = 0;
            f = (f + 1) % size;
            return x;
        }
    }
    void print()
    {  if(f==-1 && r==-1 ) cout << "queue is empty" << endl;
       else {
        for (int i = f; i <size; i++)
        {
            if (arr[i] == 0)
                cout << "_"
                     << " ";
            else
                cout << arr[i] << " ";
        }
        for (int i = 0;i<f;i++){
            if (arr[i] == 0)
                cout << "_"
                     << " ";
            else
                cout << arr[i] << " ";
        }
    
   
        cout << endl;
       }
    }
    
};
int main()
{
    int size;
    cout << "Enter size of queue : ";
    cin >> size;
    Queue *q = new Queue(size);
    int val;
    do
    {
        cout << "1.Enter 1 for enqueue : " << endl;
        cout << "2.Enter 2 for dequeue : " << endl;
        cout << "3.Enter 3 for printing printer data ..." << endl;
        cout << "4.Enter 4 for exit..." << endl;
        cout << "Enter val : ";
        cin >> val;
        switch (val)
        {
        case 1:
        {
            int data;
            cout << "Enter file number for enqueue : ";
            cin >> data;
            q->enQueue(data);
        }
        break;
        case 2:
        {
            cout << "deQueue element is : " << q->deQueue()<<endl;
        }
        break;
        case 3:
        {
            cout << "Printing the queue..." << endl;
            q->print();
        }
        }
    } while (val != 4);
}