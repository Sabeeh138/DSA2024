#include <iostream>
#include <string>
#include <vector>
using namespace std;


struct Student {
    string name;
    int score;
    Student* next;
    Student(string n, int s) : name(n), score(s), next(nullptr) {}
};


void append(Student*& head, string name, int score) {
    Student* newStudent = new Student(name, score);
    if (!head) {
        head = newStudent;
    } else {
        Student* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
}


void countingSort(Student*& head) {
    const int RANGE = 101; // Scores between 0 and 100
    vector<Student*> buckets(RANGE, nullptr);
    vector<Student*> tail(RANGE, nullptr);

    Student* current = head;

    while (current) {
        int score = current->score;
        if (!buckets[score]) {
            buckets[score] = current;
        } else {
            tail[score]->next = current;
        }
        tail[score] = current;
        current = current->next;
    }

    head = nullptr;
    Student* sortedTail = nullptr;

    for (int i = 0; i < RANGE; i++) {
        if (buckets[i]) {
            if (!head) {
                head = buckets[i];
                sortedTail = tail[i];
            } else {
                sortedTail->next = buckets[i];
                sortedTail = tail[i];
            }
        }
    }

    if (sortedTail) {
        sortedTail->next = nullptr;
    }
}

void displayList(Student* head) {
    Student* temp = head;
    while (temp) {
        cout << temp->name << " - " << temp->score << endl;
        temp = temp->next;
    }
}

int main() {
    Student* head = nullptr;
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    for (int i = 0; i < numStudents; i++) {
        string name;
        int score;
        cout << "Enter name of student " << i + 1 << ": ";
        cin >> name;
        cout << "Enter score of student " << i + 1 << " (0-100): ";
        cin >> score;
        append(head, name, score);
    }

    countingSort(head);

    cout << "\nSorted list of students by score:\n";
    displayList(head);

    return 0;
}
