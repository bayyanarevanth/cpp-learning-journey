//
// Created by revanth on 24.11.25.
//
#include <stdio.h>
#include <stdlib.h>

// 1. Define the Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Global head pointer (or pass it by reference/double pointer in a real system)
Node* head = NULL;

// Helper function to print the list
void printList(Node* node) {
    if (node == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// --- Implementations ---

// A. Insert Front
void insertFront(int new_data) {
    // 1. Allocate new node
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    // 2. Put in the data
    new_node->data = new_data;

    // 3. Make next of new node as head
    new_node->next = head;

    // 4. Move the head to point to the new node
    head = new_node;
    printf("Inserted %d at front.\n", new_data);
}

// B. Insert End
void insertEnd(int new_data) {
    // 1. Allocate new node & put in the data
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    new_node->data = new_data;
    new_node->next = NULL; // New node is always the last node

    // 2. If the list is empty, make the new node the head
    if (head == NULL) {
        head = new_node;
        printf("Inserted %d at end (list was empty).\n", new_data);
        return;
    }

    // 3. Else, traverse to the last node
    Node* last = head;
    while (last->next != NULL) {
        last = last->next;
    }

    // 4. Change the next of the last node
    last->next = new_node;
    printf("Inserted %d at end.\n", new_data);
}

// C. Search
Node* search(int key) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            printf("Found %d in the list.\n", key);
            return current;
        }
        current = current->next;
    }
    printf("%d not found in the list.\n", key);
    return NULL;
}

// D. Delete by Key (first occurrence)
void deleteNode(int key) {
    Node *temp = head, *prev = NULL;

    // Case 1: Key is at the head
    if (temp != NULL && temp->data == key) {
        head = temp->next; // Change head
        free(temp);        // Free old head
        printf("Deleted %d from head.\n", key);
        return;
    }

    // Case 2: Key is elsewhere (or not present)
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in the list
    if (temp == NULL) {
        printf("Key %d not found for deletion.\n", key);
        return;
    }

    // Unlink the node from the list
    prev->next = temp->next;
    free(temp); // Free memory
    printf("Deleted %d.\n", key);
}


// Reverse the list iteratively
void reverseList() {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        // 1. Store next node
        next = current->next;

        // 2. Reverse current node's pointer
        current->next = prev;

        // 3. Move pointers one step ahead
        prev = current;
        current = next;
    }
    // Update the head to the new front (which is 'prev')
    head = prev;
    printf("List reversed iteratively.\n");
}

// Detect a cycle using slow/fast pointers
int detectCycle() {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;        // Moves 1 step
        fast = fast->next->next;  // Moves 2 steps

        // If slow and fast meet, a cycle is present
        if (slow == fast) {
            printf("Cycle detected!\n");
            return 1; // True
        }
    }

    printf("No cycle detected.\n");
    return 0; // False
}


int main() {
    // Initialization: List is empty, head = NULL

    // 1. Test Insertions and Search
    printf("\n--- Test Insertions ---\n");
    insertFront(10); // 10 -> NULL
    insertEnd(30);   // 10 -> 30 -> NULL
    insertFront(5);  // 5 -> 10 -> 30 -> NULL
    insertEnd(40);   // 5 -> 10 -> 30 -> 40 -> NULL
    printf("Current List: ");
    printList(head);

    // 2. Test Search and Delete
    printf("\n--- Test Search and Delete ---\n");
    search(10);
    deleteNode(5);   // Delete head: 10 -> 30 -> 40 -> NULL
    deleteNode(30);  // Delete middle: 10 -> 40 -> NULL
    deleteNode(100); // Not found
    printf("List after Deletion: ");
    printList(head);

    // 3. Test Reverse
    printf("\n--- Test Reverse ---\n");
    insertFront(50); // 50 -> 10 -> 40 -> NULL
    insertFront(60); // 60 -> 50 -> 10 -> 40 -> NULL
    printf("List before reverse: ");
    printList(head);
    reverseList();
    printf("List after reverse: ");
    printList(head); // 40 -> 10 -> 50 -> 60 -> NULL

    // 4. Test Cycle Detection (No cycle)
    printf("\n--- Test Cycle Detection ---\n");
    detectCycle();

    // 5. Create a cycle for testing
    // Point the last node (60) back to the second node (10)
    Node* temp = head; // head is 40
    temp = temp->next; // temp is 10 (the node we point back to)
    Node* last = temp->next->next; // last is 60

    // Creating the cycle: 60's next points to 10
    last->next = temp;
    printf("Cycle created: 60 -> 10\n");

    // 6. Test Cycle Detection (Cycle present)
    detectCycle();

    // Note: Due to the cycle, freeing memory cleanly would require breaking the cycle first.
    // For this demonstration, we'll skip memory cleanup.

    return 0;
}