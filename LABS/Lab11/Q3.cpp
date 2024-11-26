#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
    vector<int> table;
    vector<bool> occupied;
    int size;
    int elementCount;
    double loadFactorThreshold;

    int hashFunction(int id) {
        return id % size;
    }

    void rehash() {
        int oldSize = size;
        size *= 2;
        vector<int> oldTable = table;
        vector<bool> oldOccupied = occupied;

        table.assign(size, -1);
        occupied.assign(size, false);
        elementCount = 0;

        for (int i = 0; i < oldSize; ++i) {
            if (oldOccupied[i]) {
                insert(oldTable[i]);
            }
        }
    }

public:
    HashTable(int initialSize, double threshold) : size(initialSize), elementCount(0), loadFactorThreshold(threshold) {
        table.resize(size, -1);
        occupied.resize(size, false);
    }

    void insert(int id) {
        if (double(elementCount) / size >= loadFactorThreshold) {
            rehash();
        }

        int index = hashFunction(id);
        while (occupied[index]) {
            index = (index + 1) % size;
        }

        table[index] = id;
        occupied[index] = true;
        elementCount++;
    }

    void search(int id) {
        int index = hashFunction(id);
        int startIndex = index;

        while (occupied[index]) {
            if (table[index] == id) {
                cout << "Student ID " << id << " found at index " << index << endl;
                return;
            }
            index = (index + 1) % size;
            if (index == startIndex) break;
        }

        cout << "Student ID " << id << " not found." << endl;
    }

    void display() {
        cout << "Hash Table:" << endl;
        for (int i = 0; i < size; ++i) {
            if (occupied[i]) {
                cout << "Index " << i << ": " << table[i] << endl;
            } else {
                cout << "Index " << i << ": [Empty]" << endl;
            }
        }
    }
};

int main() {
    HashTable portal(7, 0.75);

    portal.insert(12);
    portal.insert(22);
    portal.insert(32);
    portal.insert(42);
    portal.insert(52);
    portal.insert(62);

    cout << "After inserting student IDs 12 to 62:" << endl;
    portal.display();

    cout << "\nSearching for student IDs:" << endl;
    portal.search(22);
    portal.search(42);
    portal.search(72);

    cout << "\nInserting student IDs 72 and 82 to exceed the load factor threshold:" << endl;
    portal.insert(72);
    portal.insert(82);
    portal.display();

    return 0;
}
