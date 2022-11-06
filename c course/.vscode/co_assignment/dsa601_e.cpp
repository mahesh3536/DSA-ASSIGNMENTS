#include<iostream>
using namespace std;
bool binarysearch(int arr[], int size, int key,int* comparisons)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {   
        (*comparisons)++;
        if (arr[mid] == key)
        {
            return true;
        }
        if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }
    return false;
}
void bubbleSort(int arr[],int n){
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(arr[j]<arr[i]){
                swap(arr[j],arr[i]);
            }
        }
    }
}
int main(){
    int comparisons = 0;
    int n;
    cout << "Enter size of Array : " ;
    cin >> n;
    int Arr[n];
    cout << "Taking Input ..."<<endl;
    for(int i =0;i<n;i++){
        cin>>Arr[i];
    }
    cout << "Sorting array for binary search..." << endl;
    bubbleSort(Arr,n);
    cout << "Searching Element..." << endl;
    cout << "Enter key : " ;
    int key ;
    cin>>key;
    if(binarysearch(Arr,n,key,&comparisons)) cout << "Key found" << endl;
    else cout << "Key not found" << endl;
    cout << "The number of comparisons : " << comparisons ;
}