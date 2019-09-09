#include "HashTable.h"
#include <iostream>     // for testing

using namespace std;


HashTable::HashTable(int valueCount) {
    m_value_count = 0;
    int bucketCounter = valueCount + 1;
    while (! isPrime(bucketCounter)) {
        bucketCounter ++;
    }
    m_bucket_size = bucketCounter;
    // cout << "\nWe have " << valueCount << " values and are placing them in " << m_bucket_size << " buckets.\n\n";

    m_arr = new LinkedList[m_bucket_size];
}



HashTable::~HashTable() {

}

bool HashTable::isPrime(int num) {
    for (int i = 2; i < num; i++) {
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
        m_value_count ++;
        // cout << "Now i have this many values: " << m_value_count << " is it prime? " << isPrime(m_value_count) << endl;
        if (m_value_count > m_bucket_size) {
            // cout << "IM REHAHSING BECAUSE I THINK " << m_value_count << " IS GREATER THAN " << m_bucket_size << endl << endl;
            rehash();
        }
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

// special hash function that accepts a different bucket size
int HashTable::hashFunction(string value, int newBucketSize) {  
    int index = 0;
    for (int i = 0; i < value.length(); i++) {
        index += int(value[i]);
    }
    return index % newBucketSize;
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
        m_value_count --;
        m_arr[index].remove(value);
        return true;
    }
}

void HashTable::rehash() {
    int newSize = (m_bucket_size * 2) + 1;
    while (!isPrime(newSize)) {
        newSize ++;
    }
    LinkedList* newArr = new LinkedList[newSize];
    string tempValue = "";
    for (int i = 0; i < m_bucket_size; i++) {
        while (!m_arr[i].isEmpty()) {
            tempValue = m_arr[i].getFirst()->getValue();
            newArr[hashFunction(tempValue, newSize)].insert(tempValue);
            m_arr[i].remove(tempValue);
        }
    }
    delete[] m_arr;
    m_bucket_size = newSize;
    m_arr = newArr;

    cout << "Hash table is rehashed!\n\n";
}