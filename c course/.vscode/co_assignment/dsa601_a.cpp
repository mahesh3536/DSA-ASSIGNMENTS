#include<iostream>
using namespace std;
void insertionsort(int arr[], int n,int* comparisons,int* swaps)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {   (*comparisons)++;
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = temp;
    }
}
void bubbleSort(int arr[],int n,int comparisons,int swaps){
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            comparisons++;
            if(arr[j]<arr[i]){
                swap(arr[j],arr[i]);
                swaps++;
            }
        }
    }
}
void selectionSort(int arr[],int n,int comparisons,int swaps){
    for(int i = 0;i<n;i++){
        int minIndex = i;
        for(int j=i+1;j<n;j++){
            comparisons++;
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        if(minIndex!=i){
            swap(arr[minIndex],arr[i]);
            swaps++;
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
    insertionsort(Arr,n,&comparisons,&swaps);
    cout << "Sorted Array is ..." << endl;
    for(int i = 0;i<n;i++){
        cout << Arr[i]<<" ";
    }
    cout << endl;
    cout << "The Number of Comparisons in InsertionSort is : " << comparisons << endl;
    cout << "The Number of swaps in InsertionSort is : " << swaps << endl;
}