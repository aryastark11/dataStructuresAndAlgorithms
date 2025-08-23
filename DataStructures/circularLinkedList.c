// CIRCULAR LINKED LIST
// Circular LinkedList - data and node* storing the value at node X and address of node (X+1)
/* This code has circular LinkedList which has a cycle.

The time complexity of is as follows:
Insert - 
Delete -
Print - Traverse
*/


#include <stdio.h>
#include <stdlib.h>

void insertAtFirst(struct Node** head, int value);
void insertAtEnd(struct Node** head, int value);
void deleteFromFirst(struct Node** head);
void deleteFromEnd(struct Node** head);
void print(struct Node* head);


// Structure to denote a node in SINGLY LINKEDLIST.
struct Node {
    int data;
    struct Node* next;    // pointer to a structure node. Hence its of type Node as well. 
};

// Function to print the full LinkedList.
void print(struct Node* head){
    struct Node* tempNode = head;
    printf("Printing the whole LINKED_LIST\n");
    while(tempNode != NULL){
        printf(" %d ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("\n");
}

struct Node* createNode(int value){
    // create a new struct Node.
    // assign data = value passed and address of next Node = NULL.
    // return this NewNode.
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
};

void insertAtFirst(struct Node** head, int value){
    // Insert at the beginning of the linkedList.
    struct Node* newNode;
    newNode = createNode(value);
    newNode->next = *head;  // pointer of newNode points to current HEAD
    *head = newNode; // HEAD = new Node ( first node is the new node created)
    return;
};

void insertAtEnd(struct Node** head, int value){
    // Insert at the beginning of the linkedList.
    struct Node* newNode;
    newNode = createNode(value);
    // if LinkedList is NULL, head is the new Node created.
    if (*head == NULL){
        *head = newNode;
        return;
    }
   // if LinkedList is not NULL, traverse to the end of the existing LinkedList, and add the node.
    struct Node* tempNode = *head;
    while(tempNode->next != NULL){
        tempNode = tempNode->next;
    } // points to the end of Last node.
    tempNode->next = newNode; // create the LINK.
    return;
};

void insertAtPosition(struct Node** head, int value, int position){
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
        insertAtFirst(head, value);
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

void deleteFromFirst(struct Node** head){
    // Delete at the beginning of the linkedList.
    struct Node* tempNode;
    tempNode = (*head)->next;
    // delete HEAD
    free(*head);
    // assign HEAD equal to second node.
    *head = tempNode;
}

void deleteFromEnd(struct Node** head){
    // Delete at the end of the linkedList.
    if(head == NULL){
        printf("LinkedList is empty, so cannot be deleted\n");
        return;
    }
    if((*head)->next == NULL){
        printf("There is only one node in the LinkedList: %d\n", (*head)->data);
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* tempNode = *head;
    while(tempNode->next->next != NULL){
        tempNode = tempNode->next;
    } // tempNode points to last but one (last second) node.
    // make the next pointer of last but one node to NULL.
    free(tempNode->next);
    tempNode->next = NULL;
}

void deleteAtPosition(){

}


int main() {
    struct Node* head = NULL;

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
    
    // Positioning index starts from 0 to len(LinkedList) - 1
    printf("Linked list after inserting the node:150 at position 2 \n");
    insertAtPosition(&head, 15, 2);
    print(head);
    printf("Linked list after inserting the node:150 at position -1 \n");
    insertAtPosition(&head, 15, -1);
    print(head);
    printf("Linked list after inserting the node:150 at position 0 \n");
    insertAtPosition(&head, 15, 0);
    print(head);
    printf("Linked list after inserting the node:150 at position 9 \n");
    insertAtPosition(&head, 15, 9);
    print(head);

    printf("Linked list after deleting the first node: \n");
    deleteFromFirst(&head);
    print(head);
    printf("Linked list after deleting the last node: \n");
    deleteFromEnd(&head);
    print(head);

    // Positioning index starts from 0 to len(LinkedList) - 1
    printf("Linked list after deleting the node at position 1: \n");
    deleteAtPosition(&head, 1);
    print(head);

    return 0;
}
