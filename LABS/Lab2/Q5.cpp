#include<iostream>
#include<string> //for using strng data typ

using namespace std;

int main() {
    int rows;

    cout<<"Enter the number of rows in the area:"<<endl;
    cin>>rows;

    // DMA for the row that will hold the row capacity
    int* row_capacity = new int[rows];

    // DMA for the seating plan
    string** seating = new string*[rows];

    for (int i = 0; i < rows; i++)
    {   
        cout<<"Enter the number of seats in row "<<i + 1<<": ";
        cin>>row_capacity[i];

        // Allocate memory for the seats in this row
        seating[i] = new string[row_capacity[i]];

        for (int j = 0; j < row_capacity[i]; j++)
        {
            cout<<"Enter the name of attendee for seat# "<<j + 1<<" in row# "<<i + 1<<": ";
            cin>>seating[i][j];
        }
    }

    // Seating plan
    cout<<"---- Seating Plan ----"<<endl;
    for (int i = 0; i < rows; i++)
    {   
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < row_capacity[i]; j++)
        {
            cout<<seating[i][j]<<" ";
        }
        cout<<endl;
    }

    // Memory deallocation
    for (int i = 0; i < rows; i++) {
        delete[] seating[i];
    }
    delete[] seating;
    delete[] row_capacity;

    return 0;
}
