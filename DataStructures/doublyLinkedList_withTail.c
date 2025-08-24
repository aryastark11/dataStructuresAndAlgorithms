/*
===============================================================================
                    DOUBLY LINKED LIST WITH TAIL POINTER
===============================================================================

A doubly linked list is a linear data structure where each node contains:
- Data: The actual value stored in the node
- Next pointer: Reference to the next node in the sequence
- Previous pointer: Reference to the previous node in the sequence

This implementation maintains a tail pointer, meaning we track both
the head and tail (end) of the list. To access the last node, use the TAIL node.

STRUCTURE:
[NULL] <- [prev|data|next] <-> [prev|data|next] <-> ... <-> [prev|data|NULL]
   ^                                                              ^
  HEAD                                                           TAIL

TIME COMPLEXITY:
- Insert at beginning: O(1)
- Insert at end: O(1) - use tail node
- Insert at position: O(n) - must traverse to position
- Delete from beginning: O(1)
- Delete from end: O(n) -  still need to find second-to-last node
- Delete at position: O(n) - must traverse to position
- Search: O(n)
- Print forward/backward: O(n)

SPACE COMPLEXITY: O(n) where n is the number of nodes

KEY FUNCTIONS IMPLEMENTED:
- createNode(): Creates a new node with given value
- insertAtFirst(): Adds node at the beginning
- insertAtEnd(): Adds node at the end 
                 (tail gets updated automatically)
- insertAtPosition(): Adds node at specified position
- deleteFromFirst(): Removes first node
- deleteFromEnd(): Removes last node
- deleteAtPosition(): Removes node at specified position
- print(): Displays list in both forward and backward directions

===============================================================================

malloc - allocate memory (create node)
free - delete memory that is allocated (delete node)
*/


#include <stdio.h>
#include <stdlib.h>

// Structure to denote a node in Doubly LinkedList.
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to print the full LinkedList.
void print(struct Node* head, struct Node* tail){
    struct Node* tempNode = head;
    printf("Present HEAD: %d \t TAIL: %d\t", head->data, tail->data);
    printf("Printing the whole LINKED_LIST\n");
    while(tempNode != NULL){
        printf(" %d ->", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("\n");
}

// function to create a new node.
struct Node* createNode(int value){
    // create and return a new struct Node.
    // assign data = value passed and address of next Node = NULL.
    // return this NewNode.
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
};


void insertAtFirst(struct Node** head, struct Node** tail, int value){
    // Insert at the beginning of the linkedList.
    struct Node* newNode;
    newNode = createNode(value);
    newNode->next = *head;  // pointer of newNode points to current HEAD
    // prev remains as NULL
    *head = newNode; // HEAD = new Node ( first node is the new node created)
    *tail = newNode;
    // prev will still be NULL (since its the first node)
    return;
};


void insertAtEnd(struct Node** head, struct Node** tail, int value){
    // if LinkedList is NULL, head is the new Node created.
    if (head == NULL && tail == NULL){
        insertAtFirst(head, tail, value);
        return;
    }
    struct Node* newNode;
    newNode = createNode(value);
    // if LinkedList is not NULL, add the node, update tail.
    // HEAD remains same.
    // tempNode points to last but one (last second) node.    
    (*tail)->next = newNode;  // tail->next should direct to new Node created just now.
    newNode->prev = *tail;  // newNodes prev points to old TAIL.
    *tail = newNode; // update the tail.
    // head remains same
    return;
};


void insertAtPosition(struct Node** head, struct Node** tail, int value, int position){
    // calculate the length of the linkedList.
    int len = 0;
    struct Node* tempNode = *head;
    while(tempNode != *tail){
        len = len + 1;
        tempNode = tempNode->next;
    }
    len += 1;

    // if position is greater than the length of the linkedList, return.
    if(position > len || position < 0){
        printf("Position is invalid, so cannot be inserted\n");
        return;
    }

    if(position == 0){
        insertAtFirst(head, tail, value);
        return;
    }
    if(position == len){
        insertAtEnd(head, tail, value);
        return;
    }
    tempNode = *head;
    while(position > 1){
        tempNode = tempNode->next;
        position = position - 1;
    }
    struct Node* newNode = createNode(value);
    newNode->next = tempNode->next;
    newNode->prev = tempNode;
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
        printf("Position selected is invalid, element cannot be deleted\n");
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
    nodeToBeDeleted->next->prev = nodeToBeDeleted->prev;
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
    
    printf("Linked list after inserting the node:100 at position 4 \n");
    insertAtPosition(&head, &tail, 100, 4);
    printf("Linked list after inserting the node:100 at position 3 \n");
    insertAtPosition(&head, &tail, 100, 3);
    print(head, tail);

    printf("Linked list after deleting the node at position -1: \n");
    deleteAtPosition(&head, &tail, -1);
    printf("Linked list after deleting the node at position 4: \n");
    deleteAtPosition(&head, &tail, 4);
    printf("Linked list after deleting the node at position 2: \n");
    deleteAtPosition(&head, &tail, 2);
    print(head, tail);
    return 0;
}