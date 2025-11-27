//
// Created by revanth on 24.11.25.
//
#include <stdio.h>

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to perform Insertion Sort on an array
void insertionSort(int arr[], int n) {
    int i, key, j;

    // Start from the second element (i=1) and go to the end
    for (i = 1; i < n; i++) {
        // 'key' is the element to be inserted into the sorted sublist
        key = arr[i];
        printf("Key: %d\n",key);
        // 'j' is the last index of the sorted sublist
        j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            printArray(arr, n);
        }

        // Insert the key into its correct position
        arr[j + 1] = key;
        printf("After key reinserted:\n");
        printArray(arr, n);
    }
}


// Driver code to test the function
int main() {
    int arr[] = {11, 12, 13, 5, 6,15};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array before sorting:\n");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Array after sorting (Ascending):\n");
    printArray(arr, n);

    return 0;
}