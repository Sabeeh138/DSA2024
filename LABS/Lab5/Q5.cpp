#include <iostream>
#include <vector>

using namespace std;

void printBoard(const vector<vector<int>>& board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1)
                cout << "Q ";  // Queen is placed here
            else
                cout << ". ";  // Empty spot
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(const vector<vector<int>>& board, int row, int col, int N) {
    // Check this column (upwards) for another queen
    for (int i = 0; i < row; i++)
        if (board[i][col] == 1)
            return false;

    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    // Check upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j] == 1)
            return false;

    return true;
}

bool solveNQueens(vector<vector<int>>& board, int row, int N) {
    // Base case: If all queens are placed
    if (row == N)
        return true;

   
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            // Place the queen
            board[row][col] = 1;

            // Recur to place the rest of the queens
            if (solveNQueens(board, row + 1, N))
                return true;

            // Backtrack: Remove the queen and try next column
            board[row][col] = 0;
        }
    }

    return false;
}

bool solveNQueens(int N) {
    
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (!solveNQueens(board, 0, N)) {
        cout << "Solution does not exist" << endl;
        return false;
    }

    
    printBoard(board, N);
    return true;
}

int main() {
    int N;
    cout << "Enter the value of N for N-Queens problem: ";
    cin >> N;

    solveNQueens(N);

    return 0;
}
