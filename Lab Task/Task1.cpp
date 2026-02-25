#include <iostream>
using namespace std;
int main(){
    int arr[8];
    for(int i=0;i<8;i++){
        cin>>arr[i];
    }   
    for(int i=0;i<8;i++){
        if(i%2 ==0){
            cout<<arr[i]<<" ";
        }
    }
}