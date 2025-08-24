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
        printf(" %d ->", tempNode->data);
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
    // tail node remains same.
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

void insertAtPosition(struct Node** head, struct Node** tail, int value, int position){
    // calculate the length of the linkedList.
    int len = 0;
    struct Node* tempNode = *head;
    while(tempNode != NULL){
        len = len + 1;
        tempNode = tempNode->next;
    }
    // if position is greater than the length of the linkedList, return.
    if(position > len || position < 0){
        printf("Position is invalid, so cannot be inserted\n");
        return;
    }

    if(position==0){
        insertAtFirst(head, tail, value);
        return;
    }
    if(position==len){
        insertAtEnd(head, tail, value);
        return;
    }
    tempNode = *head;
    while(position>1){
        tempNode = tempNode->next;
        position = position - 1;
    }
    struct Node* newNode = createNode(value);
    newNode->next = tempNode->next;
    tempNode->next = newNode;
}

void deleteFromFirst(struct Node** head, struct Node** tail){
    // Delete at the beginning of the linkedList.
    struct Node* tempNode;
    tempNode = (*head)->next;
    // delete HEAD
    free(*head);
    // assign HEAD equal to second node.
    *head = tempNode;
}

void deleteFromEnd(struct Node** head, struct Node** tail){
    // Delete at the end of the linkedList.
    if(head == NULL){
        printf("LinkedList is empty, so cannot be deleted\n");
        return;
    }
    if((*head)->next == NULL){
        printf("There is only one node in the LinkedList: %d\n", (*head)->data);
        printf("head and tail make it NULL");
        free(*head); free(*tail);
        *head = NULL; *tail = NULL;
        return;
    }
    struct Node* tempNode = *head;
    while(tempNode->next->next != NULL){
        tempNode = tempNode->next;
    } // tempNode points to last but one (last second) node.
    // make the next pointer of last but one node to NULL.
    *tail = tempNode;
    tempNode = tempNode->next;
    free(tempNode);
    (*tail)->next = NULL;
    return;
}

void deleteAtPosition(struct Node** head, struct Node** tail, int position){
    // calculate the length of the linkedList.
    int len = 0;
    struct Node* tempNode = *head;
    while(tempNode != NULL){
        len = len + 1;
        tempNode = tempNode->next;
    }
    // if position is greater than the length of the linkedList, return.
    if(position >= len || position < 0){
        printf("Position selected is invalid, so element cannot be deleted\n");
        return;
    }

    if(position == 0){ // delete the HEAD
        deleteFromFirst(head, tail);
        return;
    }
    if(position == len-1){ // delete the last node
        deleteFromEnd(head, tail);
        return;
    }

    tempNode = *head;
    int index = 0;
    while(index<position-1){
        tempNode = tempNode->next;
        index = index + 1;
    } // tempNode is the node that is before the node to be deleted (Previous node.)
    struct Node* nodeToBeDeleted = tempNode->next;
    tempNode->next = nodeToBeDeleted->next; // next->next;
    free(nodeToBeDeleted);  // delete or remove the node.
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
    
    printf("Linked list after inserting the node:15 at position 2 \n");
    insertAtPosition(&head, &tail, 15, 2);
    print(head, tail);
    
    printf("Linked list after deleting the first node: \n");
    deleteFromFirst(&head, &tail);
    print(head, tail);
    
    printf("Linked list after deleting the last node: \n");
    deleteFromEnd(&head, &tail);
    print(head, tail);
    
    printf("Linked list after deleting the node at position 1: \n");
    deleteAtPosition(&head, &tail, 1);
    print(head, tail);

    return 0;
}
