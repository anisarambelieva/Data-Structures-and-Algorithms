#include <iostream>
using namespace std;

int binarySearch(int* array, int length, int target) 
{
    int left = 0;
    int right = length - 1;

    while (left <= right) 
    {
        int mid = (left + right) / 2;

        if (array[mid] == target) 
        {
            return mid;
        }
        if (array[mid] > target) 
        {
            right = mid - 1;
        }
        if (array[mid] < target) 
        {
            left = mid + 1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int* arrStart = &arr[0];

    cout << "index of 5: " << binarySearch(arr, 10, 5) << "\n";
    cout << "index of 0: " << binarySearch(arr, 10, 0) << "\n";
    cout << "index of -3: " << binarySearch(arr, 10, -3) << "\n";
}

