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

            1       2
             \     /
              \   /
                0
               
        Array        
        0          LinkedList
        1 => 0 => 2 => NULL
        2 => 0 => NULL

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
#include<stdlib.h>

struct adjListNode{
    int dest;
    struct adjListNode* next;
};


struct Graph{
    int V;
    struct adjListNode** array;
};


// Function to create a new adjacency list node
struct adjListNode* newAdjListNode(int dest) {
    struct adjListNode* newNode = malloc(sizeof(struct adjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}


// Function to create a graph of V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = calloc(V, sizeof(struct AdjListNode*));
    return graph;
}


// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct adjListNode* node = newAdjListNode(dest);
    node->next = graph->array[src];
    graph->array[src] = node;

    // Since the graph is undirected, add an edge from dest to src
    node = newAdjListNode(src);
    node->next = graph->array[dest];
    graph->array[dest] = node;
}  


// Function to print the complete graph.
void displayGraph(struct Graph* graph){
    for (int i = 0; i < graph->V; i++) {
    printf("%d:", i);
    for (struct adjListNode* cur = graph->array[i]; cur; cur = cur->next) {
        printf(" %d", cur->dest);
    }
    printf("\n");
    }
}

int main(){
    int V = 5;
    struct Graph* graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printf("Adjacency list representation:\n");
    displayGraph(graph);

    return 0;
}