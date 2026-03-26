#include <iostream>
using namespace std;

int bubbleSort(int A[],int N ){
    int i,j,temp,c;
    for(i=N-1;i>=0;i--){
        for(j=1;j<i+1;j++){
            if(A[j-1]>A[j]){
                temp = A[j-1];
                A[j-1]=A[j];
                A[j]=temp;
                c++;
            }
        }
    }
    return c;
}

int binarySearch(int A[],int N,int n){
    int first = 0;
    int last = N-1;


    while(first<=last){
        int mid = first +(last-first)/2;
        if(n == A[mid]){
            return mid;
        }
        else if(n > A[mid]){
            first = mid+1;
        }
        else{
            last = mid-1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {10,9,8,7,6};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<"Search : ";

    int find;
    cin>>find;



    int count = bubbleSort(arr,size);
    cout<<"Number of swaps : "<<count<<endl;

    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int index = binarySearch(arr,size,find);
    if(index == -1){
        cout<<"Not Found";
    }
    else{
        cout<<"Found on index : "<<index<<endl;
    }

}
