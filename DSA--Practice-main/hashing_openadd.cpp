#include <iostream>
using namespace std;

class HashTable {
private:
    int* table;      // Array to store hash table entries
    int capacity;    // Capacity of the hash table

public:
    // Constructor to initialize hash table
    HashTable(int cap) {
        capacity = cap;
        table = new int[capacity];
        for (int i = 0; i < capacity; i++) {
            table[i] = -1; // -1 indicates empty slot
        }
    }

    // Destructor to clean up memory
    ~HashTable() {
        delete[] table;
    }

    // Hash function using modulus operator
    int hashFunction(int key) {
        return key % capacity;
    }

    // Insert key into the hash table
    void insert(int key) {
        int index = hashFunction(key);

        // Handle collisions using linear probing
        while (table[index] != -1) {
            index = (index + 1) % capacity;
        }
        table[index] = key;
    }

    // Search for a key in the hash table
    bool search(int key) {
        int index = hashFunction(key);

        // Traverse to search the key using linear probing
        for (int i = 0; i < capacity; i++) {
            int probeIndex = (index + i) % capacity;
            if (table[probeIndex] == key) {
                return true;
            }
            if (table[probeIndex] == -1) {
                return false;
            }
        }
        return false;
    }

    // Display the hash table
    void display() {
        for (int i = 0; i < capacity; i++) {
            if (table[i] == -1) {
                cout << i << ": " << "empty" << endl;
            } else {
                cout << i << ": " << table[i] << endl;
            }
        }
    }
};

int main() {
    HashTable ht(7); // Create a hash table with capacity 7

    // Insert keys
    ht.insert(10);
    ht.insert(20);
    ht.insert(5);
    ht.insert(15);
    ht.insert(7);

    // Display the hash table
    cout << "Hash Table:" << endl;
    ht.display();

    // Search for a key
    int key = 15;
    if (ht.search(key)) {
        cout << "Key " << key << " found in the hash table." << endl;
    } else {
        cout << "Key " << key << " not found in the hash table." << endl;
    }

    return 0;
}
