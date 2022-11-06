#include<iostream>
using namespace std;
void bubbleSort(int arr[],int n,int* comparisons,int* swaps){
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            (*comparisons)++;
            if(arr[j]<arr[i]){
                swap(arr[j],arr[i]);
                (*swaps)++;
            }
        }
    }
}
int main(){
   int comparisons = 0;
    int swaps = 0;
    int n;
    cout << "Enter size of the array : ";
    cin >> n;
    int Arr[n];
    cout << "Taking Input of Array ..." << endl;
    for(int i = 0;i<n;i++){
        cin >> Arr[i];
    }
    bubbleSort(Arr,n,&comparisons,&swaps);
    cout << "Sorted Array is ..." << endl;
    for(int i = 0;i<n;i++){
        cout << Arr[i]<<" ";
    }
    cout << endl;
    cout << "The Number of Comparisons in bubbleSort is : " << comparisons << endl;
    cout << "The Number of swaps in bubbleSort is : " << swaps << endl;
}