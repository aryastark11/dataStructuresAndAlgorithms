// array - continuous allocation of memory of only one data type.
/* This code contains array Data Structure (2D)

// multi-dimensional arrays -> Row-major, column-major, etc.
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