#include <iostream>
using namespace std;

class Hashtable {
public:
    int* table;
    int capacity;
    int emptyslot;
    int deletedslot;
    int size;

    // Hash function to calculate index
    int hashfunction(int key) {
        return key % capacity;
    }

    // Constructor to initialize the hashtable
    Hashtable(int size) {
        capacity = size;
        table = new int[capacity];
        emptyslot = -1;  // Empty slots marked with -1
        deletedslot = -2;  // Deleted slots marked with -2
        this->size = 0;

        for (int i = 0; i < capacity; i++) {
            table[i] = emptyslot;
        }
    }

    // Destructor to deallocate memory
    ~Hashtable() {
        delete[] table;
    }

    // Insert a key into the hashtable
    void insertkey(int key) {
        if (size == capacity) {
            cout << "Hash table is full" << endl;
            return;
        }

        int index = hashfunction(key);
        while (table[index] != emptyslot && table[index] != deletedslot && table[index] != key) {
            index = (index + 1) % capacity;
        }

        if (table[index] == key) {
            cout << "Key " << key << " already exists" << endl;
            return;
        }

        table[index] = key;  // Correct assignment
        size++;
    }

    // Remove a key from the hashtable
    void remove(int key) {
        int index = hashfunction(key);
        int startindex = index;

        while (table[index] != emptyslot) {
            if (table[index] == key) {
                table[index] = deletedslot;  // Correct assignment
                size--;
                return;
            }
            index = (index + 1) % capacity;
            if (index == startindex) {
                break;
            }
        }
        cout << "Key " << key << " not found" << endl;
    }

    // Search for a key in the hashtable
    bool search(int key) {
        int index = hashfunction(key);
        int startindex = index;

        while (table[index] != emptyslot) {
            if (table[index] == key) {
                return true;
            }
            index = (index + 1) % capacity;
            if (index == startindex) {
                break;
            }
        }
        return false;
    }

    // Display the contents of the hashtable
    void display() {
        for (int i = 0; i < capacity; i++) {
            if (table[i] == emptyslot) {
                cout << "Index " << i << " is Empty" << endl;
            } else if (table[i] == deletedslot) {
                cout << "Index " << i << " is Deleted" << endl;
            } else {
                cout << "Index " << i << ": " << table[i] << endl;
            }
        }
    }
};

int main() {
    Hashtable ht(10);

    ht.insertkey(12);
    ht.insertkey(22);
    ht.insertkey(32);

    cout << "Initial Hashtable:" << endl;
    ht.display();

    cout << "\nSearching for 22: " << (ht.search(22) ? "Found" : "Not Found") << endl;
    cout << "Searching for 33: " << (ht.search(33) ? "Found" : "Not Found") << endl;

    cout << "\nRemoving 22" << endl;
    ht.remove(22);

    cout << "\nHashtable after removing 22:" << endl;
    ht.display();

    cout << "\nTrying to insert 42:" << endl;
    ht.insertkey(42);

    cout << "\nFinal Hashtable:" << endl;
    ht.display();

    return 0;
}
