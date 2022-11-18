#include <iostream>
using namespace std;
void heapify(int Arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && Arr[largest] < Arr[left])
    {
        largest = left;
    }
    if (right < n && Arr[largest] < Arr[right])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(Arr[largest], Arr[i]);
        heapify(Arr, n, largest);
    }
}
void heapSort(int Arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(Arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(Arr[0], Arr[i]);
        heapify(Arr, i, 0);
    }
}
int main()
{
    int n;
    cout << "Enter size of Array : ";
    cin >> n;
    int Arr[n];
    cout << "Taking input..." << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> Arr[i];
    }
    heapSort(Arr, n);
    cout << "Printing the sorted Array..." << endl;
    for (int i = 0; i < n; i++)
    {
        cout << Arr[i] << " ";
    }
}