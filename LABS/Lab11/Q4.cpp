#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
    vector<int> table;
    vector<bool> occupied;
    vector<bool> deleted;
    int size;

    int primaryHash(int id) {
        return id % size;
    }

    int secondaryHash(int id) {
        return 7 - (id % 7);
    }

public:
    HashTable(int tableSize) : size(tableSize) {
        table.resize(size, -1);
        occupied.resize(size, false);
        deleted.resize(size, false);
    }

    void insert(int id) {
        int index = primaryHash(id);
        int step = secondaryHash(id);
        int startIndex = index;

        while (occupied[index] && !deleted[index]) {
            index = (index + step) % size;
            if (index == startIndex) {
                cout << "Hash table is full. Cannot insert " << id << endl;
                return;
            }
        }

        table[index] = id;
        occupied[index] = true;
        deleted[index] = false;
    }

    void search(int id) {
        int index = primaryHash(id);
        int step = secondaryHash(id);
        int startIndex = index;

        while (occupied[index]) {
            if (table[index] == id && !deleted[index]) {
                cout << "Account number " << id << " found at index " << index << endl;
                return;
            }
            index = (index + step) % size;
            if (index == startIndex) break;
        }

        cout << "Account number " << id << " not found." << endl;
    }

    void remove(int id) {
        int index = primaryHash(id);
        int step = secondaryHash(id);
        int startIndex = index;

        while (occupied[index]) {
            if (table[index] == id && !deleted[index]) {
                cout << "Removing account number " << id << " from index " << index << endl;
                deleted[index] = true;
                return;
            }
            index = (index + step) % size;
            if (index == startIndex) break;
        }

        cout << "Account number " << id << " not found for removal." << endl;
    }

    void display() {
        cout << "Hash Table:" << endl;
        for (int i = 0; i < size; ++i) {
            if (occupied[i] && !deleted[i]) {
                cout << "Index " << i << ": " << table[i] << endl;
            } else if (deleted[i]) {
                cout << "Index " << i << ": [Deleted]" << endl;
            } else {
                cout << "Index " << i << ": [Empty]" << endl;
            }
        }
    }
};

int main() {
    HashTable bank(11);

    bank.insert(101);
    bank.insert(111);
    bank.insert(121);
    bank.insert(131);
    bank.insert(141);
    bank.insert(151);

    cout << "After inserting account numbers 101 to 151:" << endl;
    bank.display();

    cout << "\nSearching for account numbers:" << endl;
    bank.search(111);
    bank.search(141);
    bank.search(161);

    cout << "\nRemoving account numbers 111 and 131:" << endl;
    bank.remove(111);
    bank.remove(131);
    bank.display();

    cout << "\nInserting account numbers 161 and 171:" << endl;
    bank.insert(161);
    bank.insert(171);
    bank.display();

    return 0;
}
