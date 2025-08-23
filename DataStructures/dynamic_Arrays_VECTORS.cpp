//// DYNAMIC ARRAYS (VECTORS)
// C++ vectors are dynamic arrays that are part of the Standard Template Library (STL). 
// They offer a flexible and efficient way to store collections of elements of the same data type.
//REFERENCE : https://cplusplus.com/reference/vector/vector/

/* This program uses VECTORS to explain Dynamic arrays in cpp

CREATE -
INSERT - 
DELETE -
TRAVERSE - 

*/

#include <iostream>
#include <vector>
using namespace std;

// no need to define MAX size before hand.
std::vector<int> v; // declares vector of integers.
std::vector<char> vChar; // one string. vector of chars

std::vector<string> vString[4]; // collection of 4 strings.
// vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};


int main() {
    vector<int> v = {1, 2, 3};

    // ways to insert elements into vector.
    v.push_back(4);
    v.insert(v.begin(), 0);
    v.insert(v.begin()+1, 10);

    // ways to access elements of vector.
    cout<<v[0]<<endl;
    for(int i=0; i< v.size(); i++){
        cout<<v[i]<<" "; // using []
    }
    cout<<endl;
    for(int i=0; i< v.size(); i++){
        cout<<v.at(i)<< " "; // using .at()
    }
    cout<<endl;

    // traversing through vector using iterator.
    std::vector<int>::iterator it;
    for(it = v.begin(); it != v.end(); ++it){
        cout<< *it << " ";
    }
    cout<<endl;

    // remove element from vector.
    // remove v[i]
    // try i =0; i =2; i = v.size()-1
    int i = v.size() - 1;
    if(i<0 || i>v.size()-1){
        return 0;
    }
    else{
        for(int j=i; j<v.size()-1; j++){
            v[j] = v[j+1];
        }
    }
    v.pop_back();  // remove the last element since it is occupied.
    cout<<"Printing the vector after removing element at %d position\n";    
    for(it = v.begin(); it != v.end(); ++it){
        cout<< *it << " ";
    }
    cout<<endl;

    return 0;
}
