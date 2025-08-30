#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    int b[high - low + 1];
    while(i <= mid && j <= high) {
        if(arr[i] <= arr[j]) {
            b[k++] = arr[i++];
        } else {
            b[k++] = arr[j++];
        }
    }
    while(i <= mid) {
        b[k++] = arr[i++];
    }
    while(j <= high) {
        b[k++] = arr[j++];
    }
    for(i = low, k = 0; i <= high; i++, k++) {
        arr[i] = b[k];
    }
}

void mergesort(int arr[], int low, int high) {
    if(low < high) {
        int mid = low + (high - low)/2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int testCases[][10] = {
        {},
        {7},
        {1, 2, 3, 4, 5},
        {9, 7, 5, 3, 1},
        {2, 3, 2, 3, 1},
        {5, 5, 5, 5, 5},
        {-3, 0, 2, -1, 4},
        {1000, 99999, 54321, 12345, 999},
        {4, 9, 76, 54, 33, 9},
        {1, 2, 4, 3, 5}
    };
    int sizes[] = {0, 1, 5, 5, 5, 5, 5, 5, 6, 5};
    
    for (int i = 0; i < 10; i++) {
        cout << "Test case " << i + 1 << " input: ";
        printArray(testCases[i], sizes[i]);
        if(sizes[i] > 0) {
            mergesort(testCases[i], 0, sizes[i] - 1);
        }
        cout << "Sorted output: ";
        printArray(testCases[i], sizes[i]);
    }

    return 0;
}