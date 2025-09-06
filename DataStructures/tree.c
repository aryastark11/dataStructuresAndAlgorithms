/*
===============================================================================
                              BINARY TREE
===============================================================================

A tree is a hierarchical data structure consisting of nodes connected by edges.
A binary tree is a tree where each node has at most two children: left and right.

TREE TERMINOLOGY:
- Root: The topmost node (no parent)
- Parent: Node that has children
- Child: Node connected below another node
- Leaf: Node with no children
- Height: Maximum depth from root to any leaf
- Depth: Distance from root to a specific node
- Subtree: Tree formed by any node and its descendants

STRUCTURE:
        Root
       /    \
    Left    Right
   /   \   /     \
  ...  ... ...   ...

TYPES OF BINARY TREES:
- Full Binary Tree: Every node has 0 or 2 children
- Complete Binary Tree: All levels filled except possibly the last
- Perfect Binary Tree: All internal nodes have 2 children, all leaves at same level
- Binary Search Tree (BST): Left child < parent < right child

TRAVERSAL METHODS:
- Inorder (Left, Root, Right): For BST, gives sorted order
- Preorder (Root, Left, Right): Used for copying/serialization
- Postorder (Left, Right, Root): Used for deletion/cleanup
- Level Order (Breadth-First): Level by level traversal

TIME COMPLEXITY (Average/Worst for BST):
- Search: O(log n) / O(n)
- Insertion: O(log n) / O(n)
- Deletion: O(log n) / O(n)
- Traversal: O(n)

SPACE COMPLEXITY:
- Storage: O(n)
- Recursion stack: O(h) where h is height

ADVANTAGES:
- Hierarchical data representation
- Efficient searching in BST
- Dynamic size
- Natural recursive structure

DISADVANTAGES:
- Can become unbalanced (degrade to linked list)
- No constant time operations
- Extra memory for pointers

COMMON OPERATIONS:
- Insert: Add new node maintaining tree properties
- Delete: Remove node while preserving structure
- Search: Find specific value in tree
- Traversals: Visit all nodes in specific order
- Height calculation: Find maximum depth
- Level order printing: Display tree level by level

APPLICATIONS:
- File systems (directory structure)
- Expression parsing (syntax trees)
- Database indexing (B-trees)
- Huffman coding (compression)
- Decision trees (AI/ML)

MEMORY MANAGEMENT:
- malloc(): Allocate memory for new nodes
- free(): Deallocate memory when deleting nodes

======================================================================
*/


#include <stdio.h>
#include <stdlib.h>


struct Node {
  // a node in a tree is denoted using struct.
  int data;
  struct Node* left;
  struct Node* right;
};


// function prototypes.
void printInOrder(struct Node* root);
void printPostOrder(struct Node* root);
void printPreOrder(struct Node* root);
void printLevelOrder(struct Node* root, int treeHeight);
struct Node* createNode(int value);
int calculateHeightOfTree(struct Node *root);
int calculateDiameterOfTree(struct Node *root);
// void deleteAtPosition(struct Node** head, int position);


// to display the tree in InOrder
void printInOrder(struct Node *root)
{
  // IN-ORDER traversal of tree.
  // using RECURSION
  if(root == NULL)
  {
    printf("Empty tree\n");
    return;
  }
  if (root->left)
      printInOrder(root->left);
  printf("%d->", root->data);
  if (root->right)
      printInOrder(root->right);
}


void printPreOrder(struct Node *root)
{
  // PRE-ORDER traversal of tree.
  // using RECURSION
  if(root == NULL)
  {
    printf("Empty tree\n");
    return;
  }
  printf("%d->", root->data);
  if (root->left)
      printPreOrder(root->left);
  if (root->right)
      printPreOrder(root->right);
}


void printPostOrder(struct Node *root)
{
  // POST-ORDER traversal of tree.
  // using RECURSION
  if(root == NULL)
  {
    printf("Empty tree\n");
    return;
  }
  if (root->left)
      printPostOrder(root->left);
  if (root->right)
      printPostOrder(root->right);
  printf("%d->", root->data);
}

void currentLevel(struct Node *root, int level, int treeHeight){
  if(root == NULL)
  {
    printf("Empty tree\n");
    return;
  }
  if(level > 1+treeHeight){
    printf("Invalid Entry\n");
    return;
  }
  if(level == 1){
    printf("\t%d\t", root->data);
  }
  else if (level>1){
    if(root->left)
      currentLevel(root->left, level-1, treeHeight);
    if(root->right)
      currentLevel(root->right, level-1, treeHeight);
  }
}


void printLevelOrder(struct Node *root, int treeHeight)
{
  // LEVEL-ORDER traversal of tree.
  // using RECURSION
  for(int i=1; i<=treeHeight+1; i++){
    currentLevel(root, i, treeHeight);
    printf("\n");
  }
}


// Create a new node. Still not attached to the tree.
struct Node* createNode(int value)
{
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->left = NULL;
  newNode->right = NULL;
  return(newNode);
}


int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}


int leftHeight = 0, rightHeight = 0;
int calculateHeightOfTree(struct Node *root){
  // Calculate the height of the tree.
  // using RECURSION
  if(root == NULL)
  {
    return -1;
  }
  leftHeight = calculateHeightOfTree(root->left);
  rightHeight = calculateHeightOfTree(root->right);
  return 1 + max(leftHeight, rightHeight); // root is added as one height
}


// Complexity
// Time Complexity - O(n)
// Space complexity - O(h) {height of the tree}
int result = 0, left = 0, right = 0;
int calculateDiameterOfTree(struct Node *root){
  if(root == NULL)
  {
    return 0;
  }
  left = calculateDiameterOfTree(root->left);
  right = calculateDiameterOfTree(root->right);
  result = max(result, left + right);
  return 1 + max(left, right);
}


int main() {
  // Create ROOT node
  struct Node* root = createNode(100);
  // Create tree nodes.
  struct Node* n1 = createNode(10);
  struct Node* n2 = createNode(20);
  struct Node* n3 = createNode(30);
  struct Node* n4 = createNode(40);
  struct Node* n5 = createNode(50);
  struct Node* n6 = createNode(60);
  struct Node* n7 = createNode(70);
  // create link in the tree.
  // STRUCTURE of the tree now:
  //         root(100)
  //        /     \
  //      n1(10)  n2(20)
  //             /     \
  //          n3(30)   n4(40)
  //         /   \       /
  //     n5(50) n6(60) n7(70) 

  // root->left = n1;
  // root->right = n2;
  // n2->left = n3;
  // n2->right = n4;
  // n3->left = n5;
  // n3->right = n6;
  // n4->left = n7;

  root->right = n1;
  n1->left = n2;
  n1->right = n3;
  n2->left = n4;
  n2->right = n5;
  n3->left = n6;
  n3->right = n7;

  // STRUCTURE of the tree now:
  //         root(100)
  //             \
  //              n1
  //             /   \
  //           n2     n3
  //         /   \    /  \
  //       n4     n5 n6   n7

  // display the complete tree through Traversal

  // Depth-First traversal
  printf("\n \t DEPTH-FIRST TRAVERSAL METHODS\n");
  printf("\nInOrder Traversal\n");
  printInOrder(root);
  printf("\nPreOrder Traversal\n");
  printPreOrder(root);
  printf("\nPostOrder Traversal\n");
  printPostOrder(root);

  printf("\n Height of the TREE - \t");
  int treeHeight = calculateHeightOfTree(root);
  printf("%d\n", treeHeight);
  currentLevel(root, 4, treeHeight);

  // Breadth-First traversal
  printf("\n \t BREADTH-FIRST TRAVERSAL METHODS\n");
  printf("\n Level Order Traversal\n");
  printLevelOrder(root, treeHeight);

  //printf("%d\n", result);
  printf("%d\n", calculateDiameterOfTree(root));
  //printf("%d\n", result);
  return 0;
}