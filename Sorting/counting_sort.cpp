/*this was written on 30 july 2026 
it's code for counting sort which is aplicable for input values on a range
but i have set a variable for that so i think it would work for any >0 values
happy coding ......:3...*/

#include <bits/stdc++.h>
using namespace std;

void counting_sort(int a[],int n){
    int k = a[0];

    for(int i=0;i<n;i++){
        k = max(k,a[i]);
    }
    
    int count[k+1] = {0};

    for(int i=0;i<n;i++){
        count[a[i]]++;
    }

    for(int i=1;i<=k+1;i++){
        count[i]+=count[i-1];
    }

    int output[n];

    for(int i=n-1;i>=0;i--){
        output[--count[a[i]]] = a[i];
    }

    for(int i=0;i<n;i++){
        a[i] = output[i];
    }
}

int main() {
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    counting_sort(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i] <<" ";
    }
    return 0;
}