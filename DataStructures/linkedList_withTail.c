/*
===============================================================================
                    SINGLE LINKED LIST WITH TAIL POINTER
===============================================================================

A singly linked list is a linear data structure where each node contains:
- Data: The actual value stored in the node
- Next pointer: Reference to the next node in the sequence

This implementation maintains BOTH head and tail pointers for optimized operations.
The tail pointer always points to the last node in the list.

STRUCTURE:
[data|next] -> [data|next] -> [data|next] -> [data|NULL]
      ^                                         ^
     HEAD                                     TAIL

ADVANTAGES OF TAIL POINTER:
- O(1) insertion at the end (vs O(n) without tail)
- O(1) access to last element
- Efficient for queue implementations (FIFO)
- Better performance for append-heavy operations

DISADVANTAGES:
- Extra memory for tail pointer storage
- Additional pointer maintenance complexity
- Tail pointer must be updated during deletions

TIME COMPLEXITY:
- Insert at beginning: O(1)
- Insert at end: O(1) - major advantage with tail pointer
- Insert at position: O(n) - must traverse to position
- Delete from beginning: O(1)
- Delete from end: O(n) - still need to find second-to-last node
- Delete at position: O(n) - must traverse to position
- Search: O(n)
- Print: O(n)

SPACE COMPLEXITY: O(n) where n is the number of nodes

KEY FUNCTIONS IMPLEMENTED:
- createNode(): Creates a new node with given value
- insertAtFirst(): Adds node at beginning (updates head)
- insertAtEnd(): Adds node at end (updates tail) - O(1) operation!
- insertAtPosition(): Adds node at specified position
- deleteFromFirst(): Removes first node (updates head)
- deleteFromEnd(): Removes last node (updates tail)
- deleteAtPosition(): Removes node at specified position
- print(): Displays entire list and current head/tail values

USE CASES:
- Queue implementation (enqueue at tail, dequeue from head)
- Append-heavy applications (logs, streaming data)
- When frequent access to last element is needed

===============================================================================
*/


#include <stdio.h>
#include <stdlib.h>

// Structure to denote a node in Singly LinkedList.
struct Node {
    int data;
    struct Node* next;
};

// Function to print the full LinkedList.
void print(struct Node* head, struct Node* tail){
    struct Node* tempNode = head;
    printf("current HEAD = %d \t", head->data);
    printf("current TAIL = %d \n", tail->data);
    printf("Printing the whole LINKED_LIST\n");
    while(tempNode != NULL){
        printf(" %d ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("\n");
}

struct Node* createNode(int value){
    // create and return a new struct Node.
    // assign data = value passed and address of next Node = NULL.
    // return this NewNode.
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
};

void insertAtFirst(struct Node** head, struct Node** tail, int value){
    // Insert at the beginning of the linkedList.
    struct Node* newNode;
    newNode = createNode(value);
    newNode->next = *head;  // pointer of newNode points to current HEAD
    *head = newNode; // HEAD = new Node ( first node is the new node created)
    // tail remains same.
    return;
};

void insertAtEnd(struct Node** head, struct Node** tail, int value){
    // Insert at the beginning of the linkedList.
    struct Node* newNode = createNode(value);
    if (*head == NULL){
        *head = newNode;
        *tail = newNode;
        return;
    }
    (*tail)->next = newNode;  // tail->next should direct to new Node created just now.
    *tail = newNode; // update the tail.
    // head remains same
};

void insertAtPosition()
{
}

void deleteFromFirst(){
}

void deleteFromEnd(){
}

void deleteAtPosition(){
}


int main() {
    struct Node* head = NULL;
    struct Node* tail = NULL;

    insertAtFirst(&head, &tail, 10);
    tail = head; // Initialize tail after first insertion
    printf("Linked list after inserting the node:10 at the beginning \n");
    print(head, tail);
    
    printf("Linked list after inserting the node:20 at the end \n");
    insertAtEnd(&head, &tail, 20);
    print(head, tail);
    
    printf("Linked list after inserting the node:5 at the end \n");
    insertAtEnd(&head, &tail, 5);
    print(head, tail);
    
    printf("Linked list after inserting the node:30 at the end \n");
    insertAtEnd(&head, &tail, 30);
    print(head, tail);
    
/*     printf("Linked list after inserting the node:15 at position 2 \n");
    insertAtPosition(&head, 15, 2);
    print(head);
    
    printf("Linked list after deleting the first node: \n");
    deleteFromFirst(&head);
    print(head); 
    
    printf("Linked list after deleting the last node: \n");
    deleteFromEnd(&head);
    print(head); 
    
    printf("Linked list after deleting the node at position 1: \n");
    deleteAtPosition(&head, 1);
    print(head); */

    return 0;
}
