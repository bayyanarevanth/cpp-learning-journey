//
// Created by revanth on 24.11.25.
//
#include <stdio.h>

// --- Binary Search Implementation ---

int binarySearch(const int arr[], int n, int target) {
    /**
     * Implements the iterative binary search algorithm.
     * Searches a SORTED array efficiently by repeatedly halving the search space.
     * * Parameters:
     * arr[]: The array to search (must be sorted).
     * n: The logical size of the array.
     * target: The value to search for.
     * * Returns:
     * The index of the target element, or -1 if the target is not found.
     */
    int low = 0;
    int high = n - 1;

    printf("\n--- Starting Binary Search for %d ---\n", target);

    // Continue the loop as long as the search space is valid
    while (low <= high) {
        // Calculate the middle index. Using (high - low) / 2 prevents overflow
        // compared to (low + high) / 2 for very large arrays.
        int mid = low + (high - low) / 2;

        printf("Current search range: [%d] to [%d]. Checking index %d (value %d).\n",
               low, high, mid, arr[mid]);

        // Case 1: Target found in the middle
        if (arr[mid] == target) {
            printf("Result: Found %d at index %d.\n", target, mid);
            return mid;
        }

        // Case 2: Target is in the right half
        // If the middle element is less than the target, we discard the left half
        else if (arr[mid] < target) {
            low = mid + 1;
        }

        // Case 3: Target is in the left half
        // If the middle element is greater than the target, we discard the right half
        else {
            high = mid - 1;
        }
    }

    // If the loop finishes, the target was not found
    printf("Result: %d not found in the array.\n", target);
    return -1;
}


// --- Utility Function ---

void printArray(const int arr[], int n) {
    /** Utility function to print the array elements. */
    printf("Array: [");
    for (int i = 0; i < n; i++) {
        printf("%d%s", arr[i], (i == n - 1) ? "" : ", ");
    }
    printf("]\n");
}


// --- Example Usage ---

int main() {

    printf("====================================================\n");
    printf("          BINARY SEARCH ALGORITHM DEMONSTRATION\n");
    printf("====================================================\n");

    // Binary Search REQUIRES the array to be sorted
    int sorted_array[] = {10, 25, 30, 42, 55, 68, 70, 81, 95};
    int n = sizeof(sorted_array) / sizeof(sorted_array[0]);

    printArray(sorted_array, n);

    // Test Case 1: Target found in the middle (42)
    binarySearch(sorted_array, n, 42);

    // Test Case 2: Target found near the start (10)
    binarySearch(sorted_array, n, 10);

    // Test Case 3: Target found near the end (95)
    binarySearch(sorted_array, n, 95);

    // Test Case 4: Target not found (60)
    binarySearch(sorted_array, n, 60);

    // Test Case 5: Target outside range (1)
    binarySearch(sorted_array, n, 1);

    // Test Case 6: Target outside range (100)
    binarySearch(sorted_array, n, 100);

    return 0;
}