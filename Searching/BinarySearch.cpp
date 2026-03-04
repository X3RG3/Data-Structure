#include <iostream>
using namespace std;

int binarySearch(int A[],int size,int target){
    int first = 0;
    int last = size-1;
    while(first<=last){
        int mid = (first+last)/2;
        if(A[mid]==target){
            return mid;
        }
        else if(A[mid]<target){
            first = mid+1;
        }
        else{
            last = mid-1;
        }
    }
}

int main(){
    int arr[] = {11,22,33,66,77,91,99};
    int size = sizeof(arr)/sizeof(arr[0]);

    int N;
    cin>>N ;
    int index = binarySearch(arr,size,N);
    cout<<index;
}