#include "matrix_multiply.h" //including the header file we made
#include <iostream>

using namespace std;

int main()
{
    int row1 = 2;
    int col1 = 3;
    int row2 = 3;
    int col2 = 2;

    // DMA for matrix1
    int **matrix1 = new int *[row1];
    for (int i = 0; i < row1; i++)
    {
        matrix1[i] = new int[col1];
    }

    // DMA for matrix2
    int **matrix2 = new int *[row2];
    for (int i = 0; i < row2; i++)
    {
        matrix2[i] = new int[col2];
    }

    // Populating the first matrix
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            matrix1[i][j] = i + 1;
        }
    }

    // Populating the second matrix
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            matrix2[i][j] = 2;
        }
    }

    if (calculations::can_be_multiplied(row1, row2, col1, col2))
    {
        int **answer = calculations::matrix_multiply(matrix1, matrix2, row1, col1, row2, col2);
        calculations::print(answer, row1, col2);

        // Deallocate memory for the result matrix
        for (int i = 0; i < row1; i++)
        {
            delete[] answer[i];
        }
        delete[] answer;
    }
    else
    {
        cout << "Matrices cannot be multiplied";
    }

    //deallocating memory for the entered matrices
    for (int i = 0; i < row1; i++)
    {
        delete[] matrix1[i];
    }
    delete[] matrix1;

    for (int i = 0; i < row2; i++)
    {
        delete[] matrix2[i];
    }
    delete[] matrix2;

    return 0;
}
