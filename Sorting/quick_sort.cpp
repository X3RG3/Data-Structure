#include <bits/stdc++.h>
using namespace std;


int  partition(int arr[], int st,int end){
    int idx = st-1;
    int pivot = arr[end];

    for(int i = st ;i<end;i++){

        if(arr[i] <= pivot){
            idx++;
            swap(arr[i] , arr[idx]);
        }
    }

    idx++;
    swap(arr[end], arr[idx]);
    return idx;
}


void quick_sort(int arr[], int st, int end){
    if(st<end){
        int pividx = partition(arr,st,end);
        quick_sort(arr,st,pividx-1);

        quick_sort(arr,pividx+1,end);
    }
}



int main() {
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int st = 0;
    int end = n-1;
    quick_sort(arr,st,end);


    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}