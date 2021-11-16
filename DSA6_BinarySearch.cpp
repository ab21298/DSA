#include <iostream>
using namespace std;
int BinarySearch(int arr[], int left, int right, int x)
{
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else
        {
            if (arr[mid] < x)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }
    return -1;
}
int main()
{
    int arr[5] = {6, 9, 12, 15, 19};
    int left, right, data, i, size;
    size = sizeof(arr) / sizeof(arr[0]);
    left = 0;
    right = size - 1;
    cout << "Enter the data you want to search : ";
    cin >> data;
    i = BinarySearch(arr, left, right, data);
    if (i == -1)
    {
        cout << "Data not found" << endl;
    }
    else
    {
        cout << "Element is found at position: " << i + 1 << endl;
    }
    return 0;
}