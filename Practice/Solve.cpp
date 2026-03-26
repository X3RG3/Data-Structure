#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int max,maxi,  min,mini;

    max == a[0];
    min == a[0];

    for(int i=0;i<n;i++){
        if(a[i]>max){
            maxi = i;
        }
    }

    for(int i=0;i<n;i++){
        if(a[i]<min){
            mini = i;
        }
    }

    int sec = maxi+mini -1;
    cout<<sec<<endl;

}