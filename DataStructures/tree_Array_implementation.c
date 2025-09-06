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

TIME COMPLEXITY (Average/Worst for BST):
- Search: O(log n) / O(n)
- Insertion: O(log n) / O(n)
- Deletion: O(log n) / O(n)
- Traversal: O(n)

SPACE COMPLEXITY:
- Storage: O(n)
- Recursion stack: O(h) where h is height

COMMON OPERATIONS:
- Insert: Add new node maintaining tree properties
- Delete: Remove node while preserving structure
- Search: Find specific value in tree
- Traversals: Visit all nodes in specific order
- Height calculation: Find maximum depth
- Level order printing: Display tree level by level

MEMORY MANAGEMENT:
- malloc(): Allocate memory for new nodes
- free(): Deallocate memory when deleting nodes

======================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// array representing binary tree.
char binary_tree_array[14] = {'R', 'A', 'B', 'C', 'D', 'E', 'F', 0, 0, 0, 0, 0, 0, 'G'};

// STRUCTURE of the tree now:
//            R
//         /     \
//        A       B
//       / \     / \
//      C   D   E   F 
//                 /
//                G


// function prototypes.
void printInOrder(int index);
void printPostOrder(int index);
void printPreOrder(int index);
void printLevelOrder(int index, int treeHeight);
//int calculateHeightOfTree(struct Node *root);
//void calculateDiameterOfTree(struct Node *root);
int left_child_index(int index);
int right_child_index(int index);
int get_data(int index, int length);


int left_child_index(int index)
{
  return 2*index+1;
}


int right_child_index(int index)
{
  return 2*index+2;
}


int get_data(int index, int length){
  if (index > length || index <0 || binary_tree_array[index] == 0){
    return -1;
  }
  return binary_tree_array[index];
}


int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}


// to display the tree in InOrder
void printInOrder(int index)
{
  // IN-ORDER traversal of tree.
  // using RECURSION

}


void printPreOrder(int index)
{
  // PRE-ORDER traversal of tree.
  // using RECURSION
}


void printPostOrder(int index)
{
  // POST-ORDER traversal of tree.
  // using RECURSION
}


int floorLog(int n){
  double result;
  result = log2(n);
  int floor_log2_n = (int) floor(result);
  return floor_log2_n;
}


int calculateHeightOfTree(int index){
  // Calculate the height of the tree.
  // using RECURSION
  if(index<0 || index > sizeof(binary_tree_array)/sizeof(binary_tree_array[0])) {
    return -1;
  }
  return floorLog(index);
}


int main() {
  // display the complete tree through Traversal
  // Depth-First traversal
  int binaryTreeArrayLength = sizeof(binary_tree_array)/sizeof(binary_tree_array[0]);

  printf("%d\n", left_child_index(6));
  printf("%d\n", right_child_index(2));
  printf("%d\n", get_data(7, binaryTreeArrayLength));
  printf("%d\n", get_data(8, binaryTreeArrayLength));
  printf("%d\n", calculateHeightOfTree(0));
  // printf("\n \t DEPTH-FIRST TRAVERSAL METHODS\n");
  // printf("\nInOrder Traversal\n");
  // printInOrder(0);
  // printf("\nPreOrder Traversal\n");
  // printPreOrder(0);
  // printf("\nPostOrder Traversal\n");
  // printPostOrder(0);

  // printf("\n Height of the TREE - \t");
  // int treeHeight = calculateHeightOfTree(0);
  // printf("%d\n", treeHeight);
  // // currentLevel();

  // // Breadth-First traversal
  // printf("\n \t BREADTH-FIRST TRAVERSAL METHODS\n");
  // printf("\n Level Order Traversal\n");
  // printLevelOrder(0, treeHeight);

  return 0;
}