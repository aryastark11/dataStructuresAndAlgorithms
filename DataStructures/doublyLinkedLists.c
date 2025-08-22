//// DOUBLE LINKED LIST WITHOUT TAIL
// Doubly LinkedList - data and node* storing dthe value at node X and address of node (X+1)
/* This code has Doubly LinkedList without tail.

The time complexity of  is as follows:
Insert - 
Delete -
*/

#include <stdio.h>
#include <stdlib.h>

// Structure to denote a node in Singly LinkedList.
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to print the full LinkedList.
void print(struct Node* head){
    struct Node* tempNode = head;
    printf("%d \t", head->data);
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
    newNode->prev = NULL;
    return newNode;
};

void insertAtFirst(struct Node** head, int value){
    // Insert at the beginning of the linkedList.
    struct Node* newNode;
    newNode = createNode(value);
    newNode->next = *head;  // pointer of newNode points to current HEAD
    // prev remains as NULL
    *head = newNode; // HEAD = new Node ( first node is the new node created)
    return;
};

void insertAtEnd(struct Node** head, int value){
    // Insert at the beginning of the linkedList.
    struct Node* newNode;
    newNode = createNode(value);
    // if LinkedList is NULL, head is the new Node created.
    if (*head == NULL && tail == NULL){
        *head = newNode;
        return;
    }
    // if LinkedList is not NULL, traverse to the end of the existing LinkedList, and add the node.
    // HEAD remains same.

    return;
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

    insertAtFirst(&head, 10);
    printf("Linked list after inserting the node:10 at the beginning \n");
    print(head);
    
    printf("Linked list after inserting the node:20 at the end \n");
    insertAtEnd(&head, 20);
    print(head);
    
    printf("Linked list after inserting the node:5 at the end \n");
    insertAtEnd(&head, 5);
    print(head);
    
    printf("Linked list after inserting the node:30 at the end \n");
    insertAtEnd(&head, 30);
    print(head);
    
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