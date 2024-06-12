/* Merge sort*/
#include <iostream>
using namespace std;

void Merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    // Create temporary arrays
    int left[n1], right[n2];

    // Copy data to temporary arrays left[] and right[]
    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[low:high]
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left[], if there are any
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right[], if there are any
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int low, int high) {
    if (low < high) {
        // Find the middle point
        int mid = (low + high) / 2;

        // Recursively sort the first and second halves
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);

        // Merge the sorted halves
        Merge(arr, low, mid, high);
    }
}

int main() {
    // Example usage
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }

    MergeSort(arr, 0, arr_size - 1);

    cout << "\nSorted array: ";
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

