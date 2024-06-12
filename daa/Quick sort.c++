/*QUICK SORT*/
#include <iostream>
using namespace std;

// Partition function to find the position of the pivot element
int Partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (true) {
        while (i <= j && arr[i] <= pivot) {
            i++;
        }
        while (j >= i && arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            // Swap arr[i] and arr[j]
            swap(arr[i], arr[j]);
        } else {
            // Swap arr[low] and arr[j]
            swap(arr[low], arr[j]);
            return j; // Return the position of the pivot element
        }
    }
}

// QuickSort function
void QuickSort(int arr[], int low, int high) {
    if (low < high) {
        // Find the partitioning position
        int partitionIndex = Partition(arr, low, high);

        // Recursively sort the subarrays
        QuickSort(arr, low, partitionIndex - 1);
        QuickSort(arr, partitionIndex + 1, high);
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

    QuickSort(arr, 0, arr_size - 1);

    cout << "\nSorted array: ";
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
