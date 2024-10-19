#include <iostream>
#include <string>

using namespace std;

struct Runner {
    string name;
    int finishTime;
};

void merge(Runner runners[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Runner* leftArray = new Runner[n1];
    Runner* rightArray = new Runner[n2];

    for (int i = 0; i < n1; i++)
        leftArray[i] = runners[left + i];
    for (int i = 0; i < n2; i++)
        rightArray[i] = runners[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i].finishTime <= rightArray[j].finishTime) {
            runners[k] = leftArray[i];
            i++;
        } else {
            runners[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        runners[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        runners[k] = rightArray[j];
        j++;
        k++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(Runner runners[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(runners, left, mid);
        mergeSort(runners, mid + 1, right);
        merge(runners, left, mid, right);
    }
}

int main() {
    const int totalRunners = 10;
    Runner runners[totalRunners];

    cout << "Enter the name and finish time (in seconds) for each runner:\n";
    for (int i = 0; i < totalRunners; i++) {
        cout << "Runner " << i + 1 << " name: ";
        cin >> runners[i].name;
        cout << "Runner " << i + 1 << " finish time (seconds): ";
        cin >> runners[i].finishTime;
    }

    mergeSort(runners, 0, totalRunners - 1);

    cout << "\nTop 5 fastest runners:\n";
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << runners[i].name << " - " << runners[i].finishTime << " seconds\n";
    }

    return 0;
}
