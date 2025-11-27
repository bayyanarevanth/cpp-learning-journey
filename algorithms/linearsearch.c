//
// Created by revanth on 24.11.25.
//
#include <stdio.h>
#include <stdbool.h>

// Define the maximum capacity for the array
#define MAX_CAPACITY 10

// --- Utility Function ---

void printArray(const char *title, const int arr[], int n) {
    /** Utility function to print the current state of the array. */
    printf("%s [Size: %d, Capacity: %d]: ", title, n, MAX_CAPACITY);
    if (n == 0) {
        printf("Empty");
    } else {
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

// --- 1. Array Operations ---

int insertAtIndex(int arr[], int *n, int index, int value) {
    /**
     * Inserts a value at a specific index by shifting elements to the right.
     * n (current size) is passed by pointer to allow modification.
     * Returns 1 on success, 0 on failure.
     */
    printf("\nAttempting to insert %d at index %d...\n", value, index);

    // Check for capacity overflow
    if (*n >= MAX_CAPACITY) {
        printf("Failure: Array is full (size %d). Cannot insert.\n", *n);
        return 0;
    }

    // Check for invalid index (index can be up to *n for appending)
    if (index < 0 || index > *n) {
        printf("Failure: Invalid index %d. Index must be between 0 and %d.\n", index, *n);
        return 0;
    }

    // Shift elements to the right, starting from the last element down to the insertion index
    for (int i = *n; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the new value and update the size
    arr[index] = value;
    (*n)++;
    printf("Success: Element inserted.\n");
    return 1;
}

int deleteAtIndex(int arr[], int *n, int index) {
    /**
     * Deletes the element at a specific index by shifting elements to the left.
     * n (current size) is passed by pointer to allow modification.
     * Returns the deleted value on success, -1 on failure.
     */
    printf("\nAttempting to delete at index %d...\n", index);

    // Check for empty array
    if (*n <= 0) {
        printf("Failure: Array is empty. Cannot delete.\n");
        return -1;
    }

    // Check for invalid index
    if (index < 0 || index >= *n) {
        printf("Failure: Invalid index %d. Index must be between 0 and %d.\n", index, *n - 1);
        return -1;
    }

    int deleted_value = arr[index];

    // Shift elements to the left, starting from the deletion index up to the end
    for (int i = index; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Decrement the size
    (*n)--;
    printf("Success: Deleted value %d.\n", deleted_value);
    return deleted_value;
}

// --- 2. Search Algorithm ---

int linearSearch(const int arr[], int n, int target) {
    /**
     * Implements the linear search algorithm.
     * Searches through the array sequentially.
     * Returns the index of the first occurrence of the target, or -1 if not found.
     */
    printf("\n--- Linear Search for %d ---\n", target);
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            printf("Found %d at index %d.\n", target, i);
            return i; // Target found
        }
    }
    printf("%d not found in the array.\n", target);
    return -1; // Target not found
}


// --- Example Usage ---

int main() {

    printf("====================================================\n");
    printf("              ARRAY OPERATIONS DEMONSTRATION\n");
    printf("====================================================\n");

    // Use a fixed-size array and a variable to track the logical size
    int my_array[MAX_CAPACITY] = {10, 20, 30, 40, 50};
    int current_size = 5;

    printArray("Initial Array", my_array, current_size);

    // 1. Insertion Tests

    // Test 1: Insert in the middle (99 at index 2)
    insertAtIndex(my_array, &current_size, 2, 99);
    printArray("Array after Insert (Mid)", my_array, current_size);

    // Test 2: Insert at the beginning (5 at index 0)
    insertAtIndex(my_array, &current_size, 0, 5);
    printArray("Array after Insert (Start)", my_array, current_size);

    // Test 3: Insert at the end (100 at index 7)
    insertAtIndex(my_array, &current_size, current_size, 100);
    printArray("Array after Insert (End)", my_array, current_size);

    // Test 4: Invalid insertion (out of bounds)
    insertAtIndex(my_array, &current_size, 10, 500);

    // 2. Deletion Tests

    // Test 5: Delete in the middle (at index 3, value 99)
    deleteAtIndex(my_array, &current_size, 3);
    printArray("Array after Delete (Mid)", my_array, current_size);

    // Test 6: Delete at the beginning (at index 0, value 5)
    deleteAtIndex(my_array, &current_size, 0);
    printArray("Array after Delete (Start)", my_array, current_size);

    // Test 7: Invalid deletion (out of bounds)
    deleteAtIndex(my_array, &current_size, 10);

    // 3. Linear Search Tests

    printArray("Current Array for Search", my_array, current_size);

    // Test 8: Successful search
    linearSearch(my_array, current_size, 40);

    // Test 9: Unsuccessful search
    linearSearch(my_array, current_size, 999);

    // Test 10: Search for a value known to be deleted
    linearSearch(my_array, current_size, 99);


    return 0;
}