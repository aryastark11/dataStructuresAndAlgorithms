// array - continuous allocation of memory of only one data type.
/*

===============================================================================
                 2D ARRAY (TWO-DIMENSIONAL ARRAY) IN C++
===============================================================================

A 2D ARRAY is a collection of elements organized in rows and columns, similar to a matrix.
This doc describes the typical implementation and operations for static and dynamic 2D arrays in C++.

STATIC 2D ARRAY:
- Fixed-size array declared at compile-time.
- Arrangement: arr[rows][cols]; contiguous (row-major) memory allocation.
- Access: O(1) random access via arr[i][j].
- Initialization: arr[2][3] = {{1,2,3},{4,5,6}}; initializes row by row.
- Pros: Simple, efficient access, low overhead.
- Cons: Size must be known at compile time; not resizable.

DYNAMIC 2D ARRAY:
- Size can be decided at runtime using pointers and dynamic memory allocation.
- Representation:
    int **array = new int*[rows];
    for (int i=0; i<rows; i++) array[i] = new int[cols];
- Access: array[i][j] gives element at row i, col j (same O(1) access).
- Initialization: manual via loops.
- Deallocation: 
    for (int i=0; i<rows; i++) delete[] array[i];
    delete[] array;
- Pros: Flexible size, resizable at runtime.
- Cons: Slightly slower allocation/deallocation, manual memory management required.

COMMON 2D ARRAY OPERATIONS:
Access: O(1)
Search (unsorted): O(n*m) - Linear traversal over all n x m elements.
Update value: O(1) at known position arr[i][j] or array[i][j]
Iterate all: Nested loops; e.g. for (int i=0; i<rows; ++i) for (int j=0; j<cols; ++j)
Space: O(n*m), where n = number of rows, m = number of columns.

MEMORY CONSIDERATIONS:
- Static arrays use stack (limited space).
- Dynamic arrays use heap (more space, but manual deallocation).
- Row-major order: all elements of first row stored sequentially, then second row, etc.

STANDARD CODE EXAMPLES:
// Static 2D Array
int arr[3][4];  // 3 rows x 4 cols, stack allocated

// Dynamic 2D Array
int **array = new int*[rows];
for (int i=0; i<rows; i++) array[i] = new int[cols];

// Freeing Dynamic 2D Array
for (int i=0; i<rows; i++) delete[] array[i];
delete[] array;

USE CASES:
Commonly used to represent grids, matrices, tables, images, and games.

===============================================================================
    SUMMARY: 2D ARRAY (STATIC/DYNAMIC) = TABLE OF ELEMENTS ACCESSED BY [i][j]
    - O(1) access, O(n*m) search/iteration, row-major memory, stack or heap
    - malloc/new = allocate memory, free/delete = deallocate memory
===============================================================================
*/


#include <iostream>
using namespace std;

int main(){
    // initializing array.
    int rowsB = 0;
    int colsB = 0;

    
    int arrayA[2][4] = {{1,2,3,4},{6,7,8,9}};

    // print arrayA
    cout<<"print array A "<<endl;
    for(int i = 0; i<2; i++){
        for(int j = 0; j<4; j++){
            cout<<arrayA[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    // take input for arrayB
    cout<<"Enter the number of rows in B";
    cin>>rowsB;
    cout<<"Enter the number of cols in B";
    cin>>colsB;

    int arrayB[rowsB][colsB];
    for(int i = 0; i<rowsB; i++){
        for(int j = 0; j<colsB; j++){
            cin>>arrayB[i][j];
        }
    }
    // print arrayB
    cout<<"print array B "<<endl;
    for(int i = 0; i<rowsB; i++){
        for(int j = 0; j<colsB; j++){
            cout<<arrayB[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
