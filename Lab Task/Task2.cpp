#include <iostream>
using namespace std;
void selectionSort(int A[],int n){
    int i,j,k,temp;
    for(i = 0;i<n-1;i++){
        k = i;
        for(j = i+1;j<n;j++){
            if(A[j]<A[k]){
                k = j;
            }
        }
        temp = A[i];
        A[i] = A[k];
        A[k] = temp;
    }
}
int main(){
    int arr[]= {22,66,33,88,11,44,55,99};
    int size = sizeof(arr)/sizeof(arr[0]);

    selectionSort(arr,size);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}