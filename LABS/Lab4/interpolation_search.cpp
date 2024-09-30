#include <iostream>

using namespace std;

// for sorting as interpolation search only works on sorted lists
void bubble_sort(int *arr, int length)
{
    bool swapped = false;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        // sort optimized so that if no swaps occur that means list is sorted so
        // unneccesary iterations are avoided
        if (!swapped)
        {
            break;
        }
    }
}

int interpolation_search(int *arr, int length, int search)
{
    int low = 0; // first element index
    int high = length;
    -1; // last element index

    while (low <= high && search >= arr[low] && search <= arr[high])
    {
        // checking if array has all same values
        if (low == high)
        {
            if (arr[low] == search)
            {
                return low;
            }
            return -1;
        }

        int pos = low + ((search - arr[low]) * (high - low) / (arr[high] - arr[low]));

        if (arr[pos] == search)
        {
            return pos;
        }

        if (arr[pos] < search)
        {
            low = pos + 1;
        }
        else
        {
            high = pos - 1;
        }
    }
    return -1;
}

int main()
{
    int length;
    cout << "Enter length of the array to be searched: ";
    cin >> length;
    int *arr1 = new int[length];

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < length; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr1[i];
    }
    bubble_sort(arr1, length); // as interpolation search only works on sorted elements

    int n;
    cout << "enter the element to search" << endl;
    cin >> n;
    if (interpolation_search(arr1, length, n) == -1)
    {
        cout << "value is not in the array" << endl;
    }
    else
    {
        cout << "value found: " << arr1[interpolation_search(arr1, length, n)] << "at index " << interpolation_search(arr1, length, n) << endl;
    }

    delete[] arr1;

    return 0;
}
