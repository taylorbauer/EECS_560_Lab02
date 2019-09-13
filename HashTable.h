#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "LinkedList.h"

//  This class is the point of the lab.  A hash table is a data structure that
//  runs the value it is storing through a hash function, which returns a
//  numbered "bucket" for the value to be stored in.
//  When the table becomes crowded, that is, we have more values than buckets,
//  it "rehashes" and builds a new table with more buckets, storing the old
//  values to the new table.
class HashTable {
public:
    //  Basic constructor, needs a valueCount to calculate how many buckets it should need
    HashTable(int valueCount);

    //  Basic destructor
    ~HashTable();

    //  Prints out the contents of the hash table in the format specified by the professor
    void print();

    //  Runs the value through the hash function and inserts it in the proper bucket
    //  Returns false if it cannot be inserted, i.e. if it is a duplicate value
    bool insert(string value);

    //  Returns -1 if the key is not found, returns the index of the bucket in which the key resides otherwise
    int find(string key);

    //  Returns true if the value is found and removed
    //  Returns false otherwise, i.e. the value is not in the hash table
    bool remove(string value);
private:

    //  (Sum of the ASCII values of each character in the value string) % (number of buckets)
    int hashFunction(string value);

    //  An alternate hash function, used in rehashing.  It is exactly the same except it accepts a new bucket size as a parameter
    //  This is useful because during rehash, we are working with two different buckets of different sizes
    int hashFunction(string value, int newBucketSize);

    //  To be called when the hash table is getting "full", i.e. when we have more values than buckets
    //  It builds a new array of linked lists, recalulates indeces for values, stores all old values to the new list
    //      and deletes the old array
    void rehash();

    //  A (inefficient) function to check if a number is prime, used when calculating number of buckets
    bool isPrime(int num);

    //  These variables only use snake case because the example given by the professor uses snake case
    int m_bucket_size;  //  How many buckets are in the hash table?
    int m_value_count;  //  How many values have been stored in the hash table?

    LinkedList* m_arr;  //  A pointer to the array of linkedlists used by the hash table, effectively the table itself

    //  A member method written to avoid use of STL library function calls
    //  It does the same thing as string's .length(), it iterates through the string,
    //  looking for the null terminal character, and returns the size of the string
    int findLength(string value);
};

#endif