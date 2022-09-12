#include<bits/stdc++.h>
class stack{
    public:
    int* arr;
    int top;
    int size;
    stack(int s){
        this->size=s;
        arr=new int[s];
        top=-1;
    }
    void push(int data){
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