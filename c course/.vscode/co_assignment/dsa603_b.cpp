#include<iostream>
using namespace std;
int partition(int arr[],int s,int e){
   int pivot = arr[e];
   int i = s-1;
   for(int j = s;j<e;j++){
     if(arr[j]<=pivot){
        i++;
        swap(arr[i],arr[j]);
     }
   }
   swap(arr[i+1],arr[e]);
   return (i+1);
}
void quickSort(int arr[],int s,int e){
    int stack[e-s+1];
    int top = -1;
    stack[++top] = s;
    stack[++top] = e ;
    while(top>=0){
        e = stack[top--];
        s = stack[top--];
        int p = partition(arr,s,e);
        if(p-1 > s){
            stack[++top] = s;
            stack[++top] = p-1;
        }
        if(p+1 < e){
            stack[++top] = p+1;
            stack[++top] = e;
        }
    }
}
int main(){
    int n;
    cout << "Enter size of Array : " ;
    cin >> n;
    int Arr[n];
    cout << "Taking input..."<< endl;
    for(int i = 0;i<n;i++){
        cin >> Arr[i];
    }
    cout << "Sorted array is..." << endl;
    quickSort(Arr,0,n-1);
    for(int i = 0;i<n;i++){
        cout << Arr[i] << " ";
    }
}