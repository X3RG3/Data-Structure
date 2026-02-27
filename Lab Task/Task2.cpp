#include <iostream>
using namespace std;
 
int binarySearch(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;
 
    while (low <= high) {
        int mid = low + (high - low) / 2;
 
        if (arr[mid] == key)
            return mid;          // element found
 
        else if (arr[mid] < key)
            low = mid + 1;       // search right half
 
        else
            high = mid - 1;      // search left half
    }
 
    return -1;  // element not found
}
 
int main() {
    int arr[] = {10, 20, 25, 30, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30;
 
    int result = binarySearch(arr, n, key);
 
    if (result != -1)
        cout << "Element found at index: " << result<<endl;
    else
        cout << "Element not found";
 
    return 0;
}