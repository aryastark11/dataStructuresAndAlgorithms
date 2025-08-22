// LINKED LIST WITH TAIL
// Singly LinkedList - data and node* storing the value at node X and address of node (X+1)
/* This code has Singly LinkedList with tail.

LINKED LIST WITHOUT TAIL:
Singly LinkedList with only head pointer - each node contains data and pointer to next node.
Insert at beginning: O(1) - update head pointer
Insert at end: O(n) - traverse to find last node
Delete from beginning: O(1) - update head pointer
Delete from end: O(n) - traverse to find second-to-last node
Search: O(n) - linear traversal required
Space: O(1) extra space (only head pointer needed)

The time complexity of is as follows:
Insert - 
Delete -
Print - Traverse
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
