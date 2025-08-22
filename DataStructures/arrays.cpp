// array - continuous allocation of memory of only one data type.

/* This code contains array Data Structure (1D)
The time complexity of array is as follows:
Create - 
Read - 
Insert - 
Update - 
Delete -
Sort - 
Merge -
*/

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