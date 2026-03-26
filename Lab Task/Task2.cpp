#include <iostream>
using namespace std;

void bubbleSort(int a[],int size){
    int i,j,temp;
    for(i=size-1;i>=0;i--){
        for(j=1;j<i+1;j++){
            if(a[j-1]>a[j]){
                temp = a[j-1];
                a[j-1]= a[j];
                a[j] = temp;
            }
        }
    }
}

int binarySearch(int a[],int size,int n){
    int first = 0;
    int last = size-1;
    while(first<=last){
        int mid = first + (last-first)/2;
        if(n == a[mid]){
            return mid;
        }
        else if(n> a[mid]){
            first = mid +1;
        }
        else{
            last = mid-1;
        }
    }
    return -1;
}


int main(){

    int N,Q;
    cin>>N>>Q;
    int A[N];
    int X[Q];
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    for(int i=0;i<Q;i++){
        cin>>X[i];
    }

    bubbleSort(A,N);

    for(int i=0;i<Q;i++){
        int index ;
        index = binarySearch(A,N,X[i]);
        if(index == -1){
            cout<<"not found"<<endl;
        }
        else{
            cout<<"found"<<endl;
        }
    }


}