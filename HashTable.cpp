#include "HashTable.h"
#include <iostream>     // for testing

using namespace std;


HashTable::HashTable(int valueCount) {
    int bucketCounter = valueCount + 1;
    while (! isPrime(bucketCounter)) {
        bucketCounter ++;
    }
    m_bucket_size = bucketCounter;

    cout << "\nWe have " << valueCount << " values and are placing them in " << m_bucket_size << " buckets.\n\n";

    m_arr = new LinkedList[m_bucket_size];
}



HashTable::~HashTable() {

}

bool HashTable::isPrime(int num) {
    for (int i = 2; i < (num / 2); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void HashTable::print() {
    for (int i = 0; i < m_bucket_size; i++) {
        cout << i << ": ";
        m_arr[i].print();
    }
}

bool HashTable::insert(string value) {
    int index = hashFunction(value);
    if (m_arr[index].insert(value)) {
        return true;
    }
    else {
        return false;
    }
}

int HashTable::hashFunction(string value) {
    int index = 0;
    for (int i = 0; i < value.length(); i++) {
        index += int(value[i]);
    }
    return index % m_bucket_size;
}

int HashTable::find(string key) {
    int index = hashFunction(key);
    if (m_arr[index].find(key)) {
        return index;
    }
    else {
        return -1;      //returns -1 if not found
    }
}

bool HashTable::remove(string value) {
    int index = find(value);
    if (index == -1) {
        return false;
    }
    else {
        m_arr[index].remove(value);
        return true;
    }
}