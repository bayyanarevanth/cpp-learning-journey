//
// Created by revanth on 24.11.25.
//#include <stdio.h>
#include <stdbool.h>

// Function to swap two elements
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to perform Bubble Sort on an array
void bubbleSort(int arr[], int n) {
    int i, j;
    // optimization: flag to check if any swap happened in a pass
    bool swapped;

    // Outer loop controls the number of passes
    // The largest i elements are already in place at the end
    for (i = 0; i < n - 1; i++) {
        swapped = false;

        // Inner loop compares adjacent elements and swaps them
        // n-i-1 because the last i elements are already sorted
        for (j = 0; j < n - i - 1; j++) {
            // Compare current element with the next
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        // Optimization: If no two elements were swapped
        // by inner loop, then the array is sorted
        if (swapped == false)
            break;
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver code to test the function
int main() {
    int arr[] = {20, 34, 25, 98, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array before sorting:\n");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Array after sorting (Ascending):\n");
    printArray(arr, n);

    return 0;
}