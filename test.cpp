#include <iostream>
using namespace std;

// Function to partition the array and return the index of the pivot element
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            cout<<arr[i]<<" "<<arr[j]<<endl;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    // for(int i = 0; i<high+1; i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    return i + 1;
}

// Function to perform quick select
int quickSelect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pivotIndex = partition(arr, low, high);

        // If the pivot is the k-th smallest element, return it
        if (pivotIndex == k - 1)
            return arr[pivotIndex];

        // If the k-th smallest element is in the left subarray
        if (pivotIndex > k - 1)
            // cout<<k-1<<endl;
            return quickSelect(arr, low, pivotIndex - 1, k);

        // If the k-th smallest element is in the right subarray
        return quickSelect(arr, pivotIndex + 1, high, k);
    }

    // If the array is empty or k is out of bounds
    return -1; // You can choose a different indicator for an out-of-bounds case
}

int main() {
    int arr[] = {1,5,10,4,8,2,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3; // Find the 4th smallest element

    int result = quickSelect(arr, 0, n - 1, k);

    // if (result != -1)
    //     std::cout << "The " << k << "-th smallest element is: " << result << std::endl;
    // else
    //     std::cout << "Invalid value of k." << std::endl;

    return 0;
}
