// array - continuous allocation of memory of only one data type.

/*
===============================================================================
                     ONE-DIMENSIONAL (1D) ARRAY IN C++
===============================================================================

A 1D ARRAY is a linear collection of elements, each of the same data type, stored in contiguous memory. Each element is accessed by a unique index starting at 0.

STATIC 1D ARRAY:
- Declared with a fixed size at compile-time.
- Syntax: data_type array_name[size];
  Example: int arr[5];
- Memory: Contiguous allocation in stack memory.
- Initialization: int arr[5] = {10, 20, 30, 40, 50};
- Access: O(1) random access by index (arr[i]).
- Pros: Fast access, simple syntax, minimal overhead.
- Cons: Size is fixed, cannot be resized after declaration.

DYNAMIC 1D ARRAY:
- Allocated on the heap using pointers for flexible size at runtime.
- Syntax:
    int* array = new int[size];
    // Initialize, use, and later deallocate with:
    delete[] array;
- Pros: Size decided at runtime, more flexible.
- Cons: Manual memory management required, potential memory leaks if not freed.

COMMON 1D ARRAY OPERATIONS:
Access: O(1)
Update: O(1) at arr[i]
Search: O(n) (linear search required for unsorted arrays)
Iteration: for (int i=0; i<size; ++i) arr[i]
Space: O(n) where n = number of elements

MEMORY CONSIDERATIONS:
- Static arrays use stack (limited by system), fast allocation.
- Dynamic arrays use heap (large sizes possible), but require delete[] to prevent leaks.

STANDARD CODE EXAMPLES:
// Static 1D Array
int arr[5];

// Dynamic 1D Array
int* arr = new int[size];
//... use arr[i] as needed
delete[] arr;  // Free memory

USE CASES:
Sequences, lists of values, buffer storage, and indexing collections.

===============================================================================
SUMMARY: 1D ARRAY = LINEAR LIST OF ELEMENTS (STATIC/HEAP)
- O(1) direct access, O(n) search, contiguous memory, stack or heap
- malloc/new = allocate memory, free/delete = deallocate memory
===============================================================================

#include <iostream>
using namespace std;

int readElementFromarray(int arrayA[], int pos){
    int n = sizeof(arrayA)/sizeof(arrayA[0]);
    if(pos >= n or pos <0){
        cout<<"Invalid input"<<endl;
        return -1;
    }
    return arrayA[pos];
}

int* insertElementIntoarray(int arrayA[], int pos, int val){
    int n = sizeof(arrayA)/sizeof(arrayA[0]);
    int temp[n+1] = {}; // initializing array.
    for(int i = 0; i<pos; i++){
        if(i == pos){
            temp[i] = val;
        }
        else{
            temp[i] = arrayA[i];
        }
    }
    return temp;
}

int* UpdateElementinarray(int arrayA[], int pos, int val){
    int n = sizeof(arrayA)/sizeof(arrayA[0]);
    if(pos >= n or pos <0){
        cout<<"Invalid input"<<endl;
        return;
    }
    arrayA[pos] = val;
    return arrayA;
}

void removeElementFromarray(int arrayA[], int pos, int val){
    int n = sizeof(arrayA)/sizeof(arrayA[0]);
    if(pos >= n or pos <0){
        cout<<"Invalid input"<<endl;
        return;
    }
    for(int i = n; i>pos; i--){
        arrayA[i] = arrayA[i-1];
    }
}

/* Sorting array
Linear Sort
Bubble Sort
Merge Sort
Quick Sort
Insertion Sort
Selection Sort
*/

void sortarray(int arrayA[]){
    // Sort in ascending order.
    int n = sizeof(arrayA)/sizeof(arrayA[0]);
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(arrayA[i]>arrayA[j]){
                int temp = arrayA[i];
                arrayA[i] = arrayA[j];
                arrayA[j] = temp;
            }
        }
    }
}


/* Sorting array
Linear Search
Binary Search
*/

int searcharray(int arrayA[], int n, int k){
    // Linear Search
    for(int i = n; i>=0; i--){
        if(arrayA[i]==k){
            return i;
        }
    }
    return -1;
}

int* mergearray(int* a, int* b, int index){

    int n = sizeof(a)/sizeof(a[0]);
    int m = sizeof(b)/sizeof(b[0]);
    cout<<n<<" "<<m<<endl;
    if(index>n or index<0){
        cout<<"Invalid input";
        return a;
    }

    int mergedarray[n+m];
    for(int i = 0; i<index; i++){
        mergedarray[i] = a[i];
    }
    for(int i=0; i<m; i++){
        mergedarray[index+i] = b[i];
    }
    for(int i=index; i<n; i++){
        mergedarray[m+index+i] = a[i];
    }

    cout<<"Printing merged array"<<endl;
    for(int i = 0; i<n+m; i++){
        cout<<mergedarray[i]<<" ";
    }
    return mergedarray;
}

int main(){
    // initializing array.
    int arrayA[] = {1,2,3,4,5,6,7,8,9,10};
    int arrayB[] = {};

    // print arrayA
    cout<<"print A "<<endl;
    for(int i = 0; i<20; i++){
        cout<<arrayA[i]<<" ";
    }
    cout<<endl;

    // take input for arrayB
    for(int i = 0; i<5; i++){
        cin>>arrayB[i];
    }
    cout<<endl;
    // print arrayB
    cout<<"print B "<<endl;
    for(int i = 0; i<5; i++){
        cout<<arrayB[i]<<" ";
    }
    cout<<endl;
 
    //readElementFromarray
    
    cout<<"Calling Mergearray"<<endl;
    mergearray(arrayA, arrayB, 4);
    // cout<<mergearray(arrayA,10,arrayB,5,4)<<endl;
    // 1 2 3 4 10 20 30 40 50 5 6 7 8 9 10

    return 0;
}
