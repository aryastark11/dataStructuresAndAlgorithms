/*
===========================================================================================================

                              ASSOCIATIVE ARRAY - HASH TABLE
===========================================================================================================


Hashmap vs Hashtable in context of Datastructure -
https://stackoverflow.com/questions/32274953/difference-between-hashmap-and-hashtable-purely-in-data-structures

A HashMap (Hash Table) is a data structure that implements an associative array
abstract data type, mapping keys to values using a hash function.

HashMaps improve lookup (or search) efficiency compared to arrays and linked lists by allowing
O(1) average-time complexity for search operations. This is achieved through the use
of a hash function that maps keys to specific indices within the array.

KEY CONCEPTS:
- Hash Function: Converts keys into array indices
- Buckets: Array slots where key-value pairs are stored
- Collision: When multiple keys hash to the same index
- Load Factor: Ratio of stored elements to total buckets

COLLISION RESOLUTION METHODS:
1. Chaining: Store multiple elements in linked lists at each bucket
    In the chaining approach, the hash table is an array of linked lists i.e., each index has its own linked list. All key-value pairs mapping to the same index will be stored in the linked list of that index
2. Open Addressing: Find next available slot (linear/quadratic probing) [linear probing - search in a straight line]
3. Double Hashing: Use second hash function for probing

STRUCTURE (with chaining):
Bucket[0] -> [key1,val1] -> [key2,val2] -> NULL
Bucket[1] -> [key3,val3] -> NULL
Bucket[2] -> NULL
...

TIME COMPLEXITY (Average/Worst):
- Search: O(1) / O(n)
- Insert: O(1) / O(n)
- Delete: O(1) / O(n)

SPACE COMPLEXITY: O(n)

COMMON OPERATIONS:
- Insert or update key-value pair
- Retrieve value for given key
- Delete key-value pair
- Check if key exists
- Expand table when load factor exceeds threshold

HASH FUNCTION PROPERTIES:
- Deterministic: Same key always produces same hash
- Uniform Distribution: Keys spread evenly across buckets
- Fast Computation: Efficient to calculate

MEMORY MANAGEMENT:
- malloc(): Allocate memory for table and nodes
- free(): Deallocate memory when removing elements

===============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_NAME 256 // number of characters in the string is 256 max (256 bytes)
#define TABLE_SIZE 10 // max number of entries in the hash table is 10.


typedef struct person {
    char name[MAX_NAME];
    int age;
    // add other info of a person if needed.
} person;


// Declare a pointer of type struct person to the hashtable.
person *hash_table[TABLE_SIZE];


// empty table.
// Initialize the hash table to NULL.
void init_hash_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
}


unsigned int hashFunction(char *name){
    // different input names must match to different locations in the hash table.
    //
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++){
        hash_value += name[i]; // add each character value to the hash_value.
        hash_value = (hash_value * name[i]) % TABLE_SIZE; // multiply each char value and modulus with hash_table size.
    }
    return hash_value;
}


bool hash_table_insert(person *p){
    if (p == NULL) return false;
    int index = hashFunction(p->name);
    //printf("%s => %d\n", p->name, index);
    if(hash_table[index] != NULL){
        return false;
        // bucket location is filled.
        // hence cannot insert new element.s
    }
    hash_table[index] = p;
    return true;
}


void print_hash_table(){
    printf("Start of HashTable\n");
    for (int i = 0; i < TABLE_SIZE; i++){
        if (hash_table[i] == NULL){
            printf("\t%i\t---\n", i);
        }else{
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }
    }
    printf("End of HashTable\n");
}

int main(){
    /*
    printf("Jacob => %u\n", hashFunction("Jacob"));
    printf("Kavya => %u\n", hashFunction("Kavya"));
    printf("Kanti => %u\n", hashFunction("Kanti"));
    printf("Eric => %u\n", hashFunction("Eric"));
    printf("PhD => %u\n", hashFunction("PhD"));
    // hashFunction returns an integer value.
    Jacob => 2
    Kavya => 8
    Kanti => 5
    Eric => 6
    PhD => 2 
    PhD and Jacob have a collision */

    init_hash_table();
    print_hash_table();
    person jacob = {.name = "Jacob", .age = 25};
    person kavya = {.name = "Kavya", .age = 27};
    hash_table_insert(&jacob);
    hash_table_insert(&kavya); 
    print_hash_table();
    return 0;
}