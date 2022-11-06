#include<iostream>
using namespace std;
void selectionSort(int arr[],int n,int* comparisons,int* swaps){
    for(int i = 0;i<n;i++){
        int minIndex = i;
        for(int j=i+1;j<n;j++){
            (*comparisons)++;
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        if(minIndex!=i){
            swap(arr[minIndex],arr[i]);
            (*swaps)++;
        }
    }
}
int main(){
    int comparisons = 0;
    int swaps = 0;
    int n;
    cout << "Enter size of the Array : ";
    cin >> n;
    int Arr[n];
    cout << "Taking Input of Array ..." << endl;
    for(int i = 0;i<n;i++){
        cin >> Arr[i];
    }
    selectionSort(Arr,n,&comparisons,&swaps);
    cout << "Sorted Array is ..." << endl;
    for(int i = 0;i<n;i++){
        cout << Arr[i]<<" ";
    }
    cout << endl;
    cout << "The Number of Comparisons in selectionSort is : " << comparisons << endl;
    cout << "The Number of swaps in selectionSort is : " << swaps << endl;
}