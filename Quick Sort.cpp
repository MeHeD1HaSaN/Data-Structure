#include<bits/stdc++.h>
using namespace std;

int Partition(int arr[], int lo, int hi, int n)
{
    int pivot = arr[lo];
    int i=lo, j=hi;

    while(i<j){
        while(arr[i]<=pivot) i++;
        while(arr[j]>pivot) j--;
        if(i < j){
            //cout<<"swap in loop: "<<ar[i]<<' '<<ar[j]<<endl;
            swap(arr[i],arr[j]);
        }
    }
    //cout<<"swap out of loop: "<<ar[lo]<<' '<<ar[j]<<endl;
    swap(arr[lo], arr[j]);

    return j;
}
void QuickSort(int arr[], int lo, int hi, int n)
{
    if(lo>=hi) return;

    int loc = Partition(arr, lo, hi, n);

    QuickSort(arr, lo, loc-1, n);
    QuickSort(arr, loc+1, hi, n);

}

int main()
{
    int n;
    cin>>n;
    int arr[n+5];
    for(int i=0; i<n; i++) cin>>arr[i];

    QuickSort(arr, 0, n-1, n);

    for(int i=0; i<n; i++) cout<<arr[i]<<' ';

    cout<<endl;
}

/*

5
3 1 4 2 5

*/
