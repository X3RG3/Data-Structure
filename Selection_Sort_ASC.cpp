#include <iostream>
using namespace std;

void selectionSort(int A[],int n){
    int i,index,j,temp;
    for (i = 0; i < n-1; i++) {
        index = i;
        for (j = i+1; j < n; j++) {
            if (A[j] < A[index])
                index = j;
        }
        temp = A[i];
        A[i] = A[index];
        A[index] = temp;
    }
}

int main(){
    int arr[] ={34,12,67,19,30,50,-34};
    int size = sizeof(arr)/sizeof(arr[0]);

    selectionSort(arr,size);
    cout<<"Sorted Array : ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}
