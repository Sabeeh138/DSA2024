#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dfs(vector<vector<char>>& field, vector<vector<bool>>& visited, int x, int y, int n, int m) {
    if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y] || field[x][y] == 'W') {
        return 0;
    }
    visited[x][y] = true;
    int size = 1;
    size += dfs(field, visited, x + 1, y, n, m);
    size += dfs(field, visited, x - 1, y, n, m);
    size += dfs(field, visited, x, y + 1, n, m);
    size += dfs(field, visited, x, y - 1, n, m);
    return size;
}

int largestForest(vector<vector<char>>& field) {
    int n = field.size();
    int m = field[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int maxForestSize = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (field[i][j] == 'T' && !visited[i][j]) {
                int forestSize = dfs(field, visited, i, j, n, m);
                maxForestSize = max(maxForestSize, forestSize);
            }
        }
    }
    return maxForestSize;
}

int main() {
    int n, m;
    cout << "Enter the number of rows and columns in the field: ";
    cin >> n >> m;
    vector<vector<char>> field(n, vector<char>(m));
    cout << "Enter the field (W for water, T for tree):" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> field[i][j];
        }
    }
    int largestForestSize = largestForest(field);
    cout << "The size of the largest forest is: " << largestForestSize << endl;
    return 0;
}
