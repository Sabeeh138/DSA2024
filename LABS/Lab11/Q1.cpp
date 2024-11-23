#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

struct Book {
    int bookID;
    string title;

    Book(int id, string t) : bookID(id), title(t) {}
};

class LibraryCatalog {
private:
    vector<list<Book>> table;
    int tableSize;

    int hashFunction(int bookID) {
        int authorID = bookID / 10;
        return authorID % tableSize;
    }

public:
    LibraryCatalog(int size) : tableSize(size) {
        table.resize(size);
    }

    void insertBook(int bookID, string title) {
        int index = hashFunction(bookID);
        table[index].emplace_back(bookID, title);
        cout << "Inserted book: " << bookID << " (" << title << ") at index " << index << endl;
    }

    void deleteBook(int bookID) {
        int index = hashFunction(bookID);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->bookID == bookID) {
                cout << "Deleted book: " << bookID << " (" << it->title << ") from index " << index << endl;
                table[index].erase(it);
                return;
            }
        }
        cout << "Book " << bookID << " not found in the table." << endl;
    }

    void searchBook(int bookID) {
        int index = hashFunction(bookID);
        for (const auto& book : table[index]) {
            if (book.bookID == bookID) {
                cout << "Found book: " << book.bookID << " (" << book.title << ") at index " << index << endl;
                return;
            }
        }
        cout << "Book " << bookID << " not found in the table." << endl;
    }

    void displayTable() {
        cout << "Hash Table Contents:" << endl;
        for (int i = 0; i < tableSize; ++i) {
            cout << "Index " << i << ": ";
            for (const auto& book : table[i]) {
                cout << "[" << book.bookID << " - " << book.title << "] ";
            }
            cout << endl;
        }
    }
};

int main() {
    LibraryCatalog catalog(10);

    catalog.insertBook(101, "Author A - Book 1");
    catalog.insertBook(102, "Author A - Book 2");
    catalog.insertBook(103, "Author A - Book 3");
    catalog.insertBook(201, "Author B - Book 1");
    catalog.insertBook(202, "Author B - Book 2");
    catalog.insertBook(301, "Author C - Book 1");
    catalog.insertBook(302, "Author C - Book 2");
    catalog.insertBook(303, "Author C - Book 3");
    catalog.insertBook(304, "Author C - Book 4");

    cout << "\nAfter Insertion:" << endl;
    catalog.displayTable();

    cout << "\nSearch Operations:" << endl;
    catalog.searchBook(101);
    catalog.searchBook(202);
    catalog.searchBook(999);

    cout << "\nDelete Operations:" << endl;
    catalog.deleteBook(101);
    catalog.deleteBook(202);

    cout << "\nAfter Deletion:" << endl;
    catalog.displayTable();

    return 0;
}
