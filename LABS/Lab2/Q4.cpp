#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int NUM_DEPARTMENTS = 4;
const int SE_COURSES = 3;
const int AI_COURSES = 4;
const int CS_COURSES = 2;
const int DS_COURSES = 1;

void displayGPAs(const vector<vector<double>>& gpaMatrix) {
    const vector<string> departments = {"Software Engineering", "Artificial Intelligence", "Computer Science", "Data Science"};
    
    for (int i = 0; i < NUM_DEPARTMENTS; ++i) {
        cout << departments[i] << " GPA:\n";
        for (int j = 0; j < gpaMatrix[i].size(); ++j) {
            cout << "  Course " << (j + 1) << ": " << fixed << setprecision(2) << gpaMatrix[i][j] << endl;
        }
        cout << endl;
    }
}

int main() {
    vector<vector<double>> gpaMatrix = {
        {3.5, 4.0, 3.8},
        {3.7, 3.9, 4.0, 3.6},
        {3.2, 3.9},
        {3.8}
    };

    displayGPAs(gpaMatrix);

    return 0;
}
