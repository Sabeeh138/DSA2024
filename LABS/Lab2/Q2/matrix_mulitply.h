#include <iostream>
#ifndef matrix_multiply_h 
#define matrix_multiply_h

using namespace std;

namespace calculations
{

   
    bool can_be_multiplied(int r1, int r2, int c1, int c2)
    {
        if (c1 = r2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // function to multiply the 2 matrices
    int **matrix_multiply(int **a, int **b, int r1, int c1, int r2, int c2)
    {
        // dma for the rows
        int **result = new int *[r1];
        // dma for the columns
        for (int i = 0; i < c2; i++)
        {
            result[i] = new int[c2];
        }

        
        for (int i = 0; i < r1; i++)
        {
         
            for (int j = 0; j < c2; j++)
            {
                result[i][j] = 0; 
                for (int k = 0; k < c1; k++)
                {
                    result[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return result;
    }

    // function to print the answer matrix
    void print(int **result, int row, int column)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }
}

#endif
