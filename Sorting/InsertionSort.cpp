#include <iostream>
using namespace std;
void insertionSort(int arr[],int n){
    int i,j,v;
    for(i=1;i<n;i++){
        v = arr[i];
        for(j=i-1;j>=0;j--){
            if(arr[j]>v){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
            
        }
        arr[j+1] = v;

    }
}
void insertionSortV2(int arr[], int n){
    int i, j, v;
    for(i = 1; i < n; i++){   // start from 1 (another small fix)
        v = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > v){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = v;  // place v AFTER shifting
    }
}
int main(){

    int A[]= {33,66,22,99,77,11,91};
    int size = sizeof(A)/ sizeof(A[0]);

    insertionSort(A,size);

    for(int i=0;i<size;i++){
        cout<<A[i]<<" ";
    }

}