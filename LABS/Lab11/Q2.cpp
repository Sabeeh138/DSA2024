#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
    vector<int> table;
    vector<bool> occupied;
    int size;

    int hashFunction(int id) {
        return id % size;
    }

public:
    HashTable(int tableSize) : size(tableSize) {
        table.resize(size, -1);
        occupied.resize(size, false);
    }

    void insert(int id) {
        int index = hashFunction(id);
        int startIndex = index;
        while (occupied[index]) {
            index = (index + 1) % size;
            if (index == startIndex) {
                cout << "Hash table is full. Cannot insert " << id << endl;
                return;
            }
        }
        table[index] = id;
        occupied[index] = true;
    }

    void search(int id) {
        int index = hashFunction(id);
        int startIndex = index;
        while (occupied[index]) {
            if (table[index] == id) {
                cout << "Member ID " << id << " found at index " << index << endl;
                return;
            }
            index = (index + 1) % size;
            if (index == startIndex) break;
        }
        cout << "Member ID " << id << " not found." << endl;
    }

    void remove(int id) {
        int index = hashFunction(id);
        int startIndex = index;
        while (occupied[index]) {
            if (table[index] == id) {
                cout << "Removing Member ID " << id << " from index " << index << endl;
                table[index] = -1;
                occupied[index] = false;
                return;
            }
            index = (index + 1) % size;
            if (index == startIndex) break;
        }
        cout << "Member ID " << id << " not found for removal." << endl;
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
    HashTable club(7);

    for (int id = 10; id <= 60; id += 10) {
        club.insert(id);
    }
    cout << "After inserting member IDs 10 to 60:" << endl;
    club.display();

    cout << "\nSearching for member IDs:" << endl;
    club.search(30);
    club.search(50);
    club.search(70);

    cout << "\nRemoving member IDs 20 and 40:" << endl;
    club.remove(20);
    club.remove(40);
    club.display();

    cout << "\nInserting member IDs 70 and 80:" << endl;
    club.insert(70);
    club.insert(80);
    club.display();

    return 0;
}
