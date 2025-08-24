/* CIRCULAR LINKED LIST

A circular linked list is a variation of linked list where the last node points back to the first node,
forming a circle. Unlike regular linked lists that end with NULL, circular lists have no definitive end.

Key Characteristics
No NULL pointers: Last node connects to first node
Continuous traversal: Can loop infinitely through nodes
Single entry point: Typically maintain pointer to last node (easier insertion)
Memory efficient: No wasted NULL pointer space

Types
Singly Circular: Each node points to next, last→first
Doubly Circular: Bidirectional pointers, forms complete circle

The time complexity of is as follows:
Insert - 
Delete -
Print - Traverse
*/


#include <stdio.h>
#include <stdlib.h>

void checkIfCircular(struct Node** head);
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


// scan through the full LinkedList, check if &head == temp->next
// if yes, then there is a cycle (circular), else there is no circle.
void checkIfCircular(struct Node** head){
    struct Node* tempNode = *head;
    while(tempNode->next != NULL){
        tempNode = tempNode->next;
    }
    if(tempNode->next == *head){
        printf("The linked list is circular\n");
    }
    else{
        printf("The linked list is NOT circular\n");
    }
    return;
}

// Function to print the full LinkedList.
void print(struct Node* head){
    struct Node* tempNode = head;
    printf("Printing the whole LINKED_LIST\n");
    while(tempNode->next != head){
        printf(" %d -> ", tempNode->data);
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

void deleteAtPosition(struct Node** head, int position){
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

    if(position==0){ // delete the HEAD
        deleteFromFirst(head);
        return;
    }
    if(position == len-1){ // delete the last node
        deleteFromEnd(head);
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

    printf("This is CIRCULAR LINKEDLIST \n");
    insertAtFirst(&head, 10);
    printf("Linked list after inserting the node:10 at the beginning \n");
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
    // Positioning index starts from 0 to len(LinkedList) - 1
    printf("Linked list after deleting the node at position : \n");
    deleteAtPosition(&head, -1);
    // deleteAtPosition(&head, 3);
    // deleteAtPosition(&head, 0);
    // deleteAtPosition(&head, 2);
    deleteAtPosition(&head, 1);
    print(head);

    return 0;
}
