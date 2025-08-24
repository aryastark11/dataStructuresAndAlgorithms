/*
===============================================================================
                    DOUBLY LINKED LIST WITHOUT TAIL POINTER
===============================================================================

A doubly linked list is a linear data structure where each node contains:
- Data: The actual value stored in the node
- Next pointer: Reference to the next node in the sequence
- Previous pointer: Reference to the previous node in the sequence

This implementation does NOT maintain a tail pointer, meaning we only track
the head of the list. To access the last node, we must traverse from head.

STRUCTURE:
[NULL] <- [prev|data|next] <-> [prev|data|next] <-> ... <-> [prev|data|NULL]
   ^                                                              ^
  HEAD                                                        LAST NODE

ADVANTAGES:
- Bidirectional traversal (forward and backward)
- Efficient insertion/deletion at known positions
- No need to traverse from beginning for backward operations

DISADVANTAGES:
- Extra memory overhead for previous pointers
- More complex pointer manipulation
- Without tail pointer, operations at end require O(n) traversal

TIME COMPLEXITY:
- Insert at beginning: O(1)
- Insert at end: O(n) - must traverse to find last node
- Insert at position: O(n) - must traverse to position
- Delete from beginning: O(1)
- Delete from end: O(n) - must traverse to find last node
- Delete at position: O(n) - must traverse to position
- Search: O(n)
- Print forward/backward: O(n)

SPACE COMPLEXITY: O(n) where n is the number of nodes

KEY FUNCTIONS IMPLEMENTED:
- createNode(): Creates a new node with given value
- insertAtFirst(): Adds node at the beginning
- insertAtEnd(): Adds node at the end
- insertAtPosition(): Adds node at specified position
- deleteFromFirst(): Removes first node
- deleteFromEnd(): Removes last node
- deleteAtPosition(): Removes node at specified position
- print(): Displays list in both forward and backward directions

===============================================================================
*/
/*
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
void print(struct Node* head){
    struct Node* tempNode = head;
    printf("HEAD = %d \n", head->data);
    printf("Printing the whole LINKED_LIST\n");
    while(tempNode != NULL){
        printf(" %d ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("\n");

    printf("Printing the full LINKED_LIST in reverse order\n");
    tempNode = head;
    while(tempNode->next != NULL){
        tempNode = tempNode->next;
    }
    // tempNode now points to the last node in the LL.   
    while(tempNode != NULL){
        printf(" %d <-", tempNode->data);
        tempNode = tempNode->prev;        
    }
    printf("\n");
}

struct Node* createNode(int value){
    // create and return a new struct Node.
    // assign data = value passed and address of next Node = NULL.
    // return this NewNode.
    // malloc - allocate memory (create node)
    // free - delete memory that is allocated.
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
    if(*head == NULL){ // handle case for first time insertion
        *head = newNode;
        return;
    }
    newNode->next = *head;   // pointer of newNode points to current HEAD
    (*head)->prev = newNode;
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
    // HEAD remains same.
    struct Node* tempNode = *head;
    while(tempNode->next != NULL){
        tempNode = tempNode->next;
    }
    tempNode->next = newNode;
    newNode->prev = tempNode;
    return;
};

void insertAtPosition(struct Node** head, int value, int position)
{
    struct Node* tempNode = *head;
    int len = 0;
    while(tempNode != NULL){
        len += 1;
        tempNode = tempNode->next;
    }
    if(position < 1 || position > len+1){
        printf("Invalid position, cannot INSERT\n");
        return;
    }
    if(position == 0){
        insertAtFirst(head, value);
        return;
    }
    if(position == len){
        insertAtEnd(head, value);
        return;
    }
    tempNode = *head;
    while(position > 1){
        tempNode = tempNode->next;
        position -= 1;
    }
    struct Node* newNode = createNode(value);
    newNode->prev = tempNode; // node[position]->prev = node[position-1]
    newNode->next = tempNode->next; // node[position+1]
    tempNode->next = newNode;

    tempNode = tempNode->next->next;
    tempNode->prev = newNode;
    return;
}


void deleteFromFirst(struct Node** head){
    // Delete at the beginning of the linkedList.
    struct Node* tempNode;
    tempNode = (*head)->next;
    tempNode->prev = NULL;
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
        *head = NULL; // assigns data, prev and next all to NULL.
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
    while(tempNode != NULL){ // has non-null data and next pointer value.
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
    nodeToBeDeleted->next->prev = tempNode;
    tempNode->next = nodeToBeDeleted->next; // next->next;
    free(nodeToBeDeleted);  // delete or remove the node.
}

// start of program.
int main() {
    struct Node* head = NULL;

    insertAtFirst(&head, 10);
    printf("Linked list after inserting the node:10 at the beginning \n");
    print(head);
 
    printf("Linked list after inserting the node:20 at the beginning \n");
    insertAtFirst(&head, 20);
    print(head);
    
    printf("Linked list after inserting the node:5 at the end \n");
    insertAtEnd(&head, 5);
    print(head);
    
    printf("Linked list after inserting the node:30 at the end \n");
    insertAtEnd(&head, 30);
    print(head);
    
    printf("Linked list after inserting the node:15 at position 1/ 2 / 3 / 4 \n");
    insertAtPosition(&head, 15, 1);
    print(head);
    
    printf("Linked list after deleting the first node: \n");
    deleteFromFirst(&head);
    print(head);
    
    printf("Linked list after deleting the last node: \n");
    deleteFromEnd(&head);
    print(head);
    
    printf("Linked list after deleting the node at position 0/ 1 / 2 : \n");
    deleteAtPosition(&head, 1);
    print(head);

    return 0;
}