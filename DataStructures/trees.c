/*
===============================================================================
                              BINARY TREES
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

===============================================================================
*/