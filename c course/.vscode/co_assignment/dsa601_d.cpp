#include<iostream>
using namespace std;
bool linearSearch(int Arr[],int n,int key,int* comparisons){
   for(int i = 0;i<n;i++){
    (*comparisons)++;
    if(Arr[i]==key){
        return true;
    }
   }
   return false;
}
int main(){
    int comparisons = 0;
    int key;
    int n;
    cout << "Enter size of the array : ";
    cin >> n;
    int Arr[n];
    cout << "Taking Input of Array ..." << endl;
    for(int i = 0;i<n;i++){
        cin >> Arr[i];
    }
    cout << "Enter key to search : ";
    cin>>key;
    if(linearSearch(Arr,n,key,&comparisons)) cout << "Key " << key << " Found" << endl;
    else cout << "Key not Found" << endl;
    cout << "The Number of Comparisons : " << comparisons; 
}