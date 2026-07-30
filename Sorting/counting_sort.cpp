/*this was written on 30 july 2026 
it's code for counting sort which is aplicable for input values on a range
but i have set a variable for that so i think it would work for any >0 values
happy coding ......:3...*/

#include <bits/stdc++.h>
using namespace std;

void counting_sort(int a[],int n){
    int k = a[0];

    for(int i=0;i<n;i++){ // finding the max value
        k = max(k,a[i]);
    }
    
    int count[k+1] = {0};

    for(int i=0;i<n;i++){ // counting frequancy
        count[a[i]]++;
    }

    for(int i=1;i<=k+1;i++){ // sum for getting position
        count[i]+=count[i-1];
    }

    int output[n];

    for(int i=n-1;i>=0;i--){ // assigning values to output array 
        output[--count[a[i]]] = a[i];
    }

    for(int i=0;i<n;i++){ // assigning to main array
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