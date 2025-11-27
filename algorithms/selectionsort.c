//
// Created by revanth on 24.11.25.
//
#include <stdio.h>

// Function to swap two elements
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to perform Selection Sort on an array
void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // Outer loop moves boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {
        // Assume the current element is the minimum
        min_idx = i;

        // Inner loop finds the minimum element in the remaining unsorted array
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element of the unsorted subarray
        if (min_idx != i) {
            swap(&arr[i], &arr[min_idx]);
        }
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver code to test the function
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array before sorting:\n");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Array after sorting (Ascending):\n");
    printArray(arr, n);

    return 0;
}