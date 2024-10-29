#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSafe(int x, int y, vector<vector<int>> &mat, int n, vector<vector<bool>> &visited) {
    return (x >= 0 && x < n && y >= 0 && y < n && mat[x][y] == 1 && !visited[x][y]);
}

void findPaths(vector<vector<int>> &mat, int n, int x, int y, string path, vector<string> &paths, vector<vector<bool>> &visited) {
    if (x == n - 1 && y == n - 1) {
        paths.push_back(path);
        return;
    }

    // Mark the current cell as visited
    visited[x][y] = true;

    // Move Down
    if (isSafe(x + 1, y, mat, n, visited)) {
        findPaths(mat, n, x + 1, y, path + 'D', paths, visited);
    }

    // Move Left
    if (isSafe(x, y - 1, mat, n, visited)) {
        findPaths(mat, n, x, y - 1, path + 'L', paths, visited);
    }

    // Move Right
    if (isSafe(x, y + 1, mat, n, visited)) {
        findPaths(mat, n, x, y + 1, path + 'R', paths, visited);
    }

    // Move Up
    if (isSafe(x - 1, y, mat, n, visited)) {
        findPaths(mat, n, x - 1, y, path + 'U', paths, visited);
    }

    
    visited[x][y] = false;
}

vector<string> findAllPaths(vector<vector<int>> &mat, int n) {
    vector<string> paths;
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    if (mat[0][0] == 1) { // Start the search if the starting cell is open
        findPaths(mat, n, 0, 0, "", paths, visited);
    }

    return paths;
}

int main() {
    int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));

    cout << "Enter the matrix (0 for blocked, 1 for open cells):" << endl;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> mat[i][j];

    vector<string> paths = findAllPaths(mat, n);
    if (paths.empty()) {
        cout << "No paths found." << endl;
    } else {
        cout << "Paths from source to destination:" << endl;
        for (const string &path : paths) {
            cout << path << endl;
        }
    }

    return 0;
}
