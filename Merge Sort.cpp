#include <bits/stdc++.h>
#define ll long long int
#define pi acos(-1)
using namespace std;

void MergeSort(int arr[], int lo, int hi)
{
    if(lo==hi) return;
    int mid = (lo+hi)/2;

    MergeSort(arr, lo, mid);
    MergeSort(arr, mid+1, hi);

    int currentLeft = lo, currentRight = mid+1, index = lo;
    int tmp[10000];

    while(currentLeft <= mid && currentRight <= hi){

        if(arr[currentLeft] < arr[currentRight]){
            tmp[index] = arr[currentLeft];
            index++, currentLeft++;
        }
        else{
            tmp[index] = arr[currentRight];
            index++, currentRight++;
        }
    }
    while(currentLeft <= mid){
        tmp[index] = arr[currentLeft];
        index++, currentLeft++;
    }
    while(currentRight <= hi){
        tmp[index] = arr[currentRight];
        index++, currentRight++;
    }
    for(int i=lo; i<=hi; i++){
        arr[i] = tmp[i];
    }
}

int main()
{

    int n;
    scanf("%d", &n);
    int arr[n+4];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);

    MergeSort(arr, 0, n-1);

    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}











