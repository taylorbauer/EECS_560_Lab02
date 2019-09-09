#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "LinkedList.h"

class HashTable {
public:
    HashTable(int valueCount);
    ~HashTable();
    void print();
    bool insert(string value);
    int find(string key);
    bool remove(string value);
private:
    int hashFunction(string value);
    bool isPrime(int num);
    int m_bucket_size;
    LinkedList* m_arr;
};

#endif