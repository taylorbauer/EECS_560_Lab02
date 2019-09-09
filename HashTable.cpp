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

void HashTable::insert(string value) {
    int index = hashFunction(value);
    m_arr[index].insert(value);
}

int HashTable::hashFunction(string value) {
    int index = 0;
    for (int i = 0; i < value.length(); i++) {
        index += int(value[i]);
    }
    return index % m_bucket_size;
}