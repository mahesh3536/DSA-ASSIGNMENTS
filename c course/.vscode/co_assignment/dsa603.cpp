#include<iostream>
using namespace std;
int partition(int arr[],int s,int e){
   int pivot = arr[s];
   int cnt = 0;
   for(int i = s;i<=e;i++){
     if(arr[i]<pivot) cnt++;
   }
   int pivotIndex = s + cnt;
   swap(arr[s],arr[pivotIndex]);
   int i = s;
   int j = e;
   while(i<pivotIndex && j>pivotIndex){
       while(arr[i]<pivot){
        i++;
       }
       while(arr[j]>pivot){
        j--;
       }
       if(i<pivotIndex && j>pivotIndex){
         swap(arr[i],arr[j]);
         i++;
         j--;
       }
   }
   return pivotIndex;
}
void quickSort(int arr[],int s,int e){
   if(s>=e) return ;
   int p = partition(arr,s,e);
   quickSort(arr,s,p-1);
   quickSort(arr,p+1,e);
}
int main(){
   int n;
   cout << "Enter size of Array : " ;
   cin >> n;
   int Arr[n];
   cout << "Taking input..." << endl;
   for(int i = 0;i<n;i++){
    cin >> Arr[i] ;
   }
   quickSort(Arr,0,n-1);
   cout << "The sorted Array is..." << endl;
   for(int i = 0;i<n;i++){
    cout << Arr[i] << " ";
   }
   cout << endl;
}