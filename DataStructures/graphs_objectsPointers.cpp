/*
===============================================================================
                       GRAPHS (ABSTRACT DATA TYPE) IN C
===============================================================================

A GRAPH is a non-linear data structure consisting of nodes (vertices) and edges (connections between nodes).
Graphs can be directed or undirected, weighted or unweighted, sparse or dense.

COMMON REPRESENTATIONS:
1. Adjacency Matrix:
   - 2D array mat[V][V], V = number of vertices.
   - mat[i][j] = 1 if edge from i to j exists; (or weight of edge if weighted).
   - Space: O(V^2)
   - Pros: Quick edge existence/access (O(1)), good for dense graphs.
   - Cons: Large memory for sparse graphs.

2. Adjacency List:
   - Array of vertex pointers; each points to a linked list containing all adjacent vertices.
   - Often:
     ```
     struct Node { int dest; struct Node* next; };
     struct Graph { int V; struct Node** adjList; };
     ```
   - Space: O(V + E) (E = number of edges)
   - Pros: Efficient for sparse graphs, easy to enumerate neighbors.
   - Cons: Edge access is O(degree of vertex).

3. Edge List

4. Object and Pointer

COMMON GRAPH OPERATIONS:
    Add edge: O(1) (adjacency list), O(1) (adjacency matrix)
    Delete edge: O(1) (matrix), O(degree) (list, search required)
    Check edge: O(1) (matrix), O(degree) (list)
    Traversal: O(V+E) for BFS/DFS
    Insert vertex: O(V^2) (matrix, need new row/col), O(1) (list, add new pointer)
    Space: O(V^2) (matrix), O(V+E) (list)

MEMORY/MANAGEMENT:
- For adjacency matrix, 2D array allocated statically or dynamically.
- For adjacency list, use malloc/free for nodes and arrays.

===============================================================================
*/

// Graphs using Adjacency List.
#include<stdio.h>

#define MAX_VERTICES 4


void addEdge(int matrixB[MAX_VERTICES][MAX_VERTICES], int i, int j)
{

}

void displayGraph(int matrixB[MAX_VERTICES][MAX_VERTICES]){

}

int main(){
    int;

    addEdge(matrixA, 0, 1);
    addEdge(matrixA, 0, 2);
    addEdge(matrixA, 2, 1);
    addEdge(matrixA, 2, 3);

    displayGraph(matrixA);

    // If there is a sparse Graph with less nodes and less edges, most of the space used by Adjacency Matrix
    // goes as waste. Hence, need a better approach.
    return 0;
}