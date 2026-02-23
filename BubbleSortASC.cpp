#include <iostream>
using namespace std;
    void bubbleSort(int num[],int size){
        int i,j,temp;
        for(i=size-1;i>=0;i--){
            for(j=1;j<=i;j++){
                if(num[j-1]>num[j]){
                    temp = num[j-1];
                    num[j-1] = num[j];
                    num[j] = temp;
                }
            }
        }
    }

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }



    bubbleSort(arr,n);

    cout<<"Sorted Array : "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    
}