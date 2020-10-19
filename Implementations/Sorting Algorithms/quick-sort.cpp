#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}
    // 8 3 6 5 1 9 2 
int partition(int* array, int start, int end) {
    // 2 3 6 5 1 9 8 
    int pivot = array[(start + end) / 2]; // 5
    int left = start; // 1
    int right = end; // 5

    while (left <= right) { // 1 < 5
        while (array[left] < pivot) { // 3 < 5
            left++; // 2
        }
        while (array[right] > pivot) { // 9 > 5
            right--; // 4
        }

        swap(array[left], array[right]); // 2 3 1 5 6 9 8
        left++; // 3
        right--; // 3
    }

    return left; //return the mid element -> pivot
}

void _quickSort(int* arr, int start, int end)
{
    if (start < end)
    {
        int pivot = partition(arr, start, end);
        _quickSort(arr, start, pivot - 1);
        _quickSort(arr, pivot, end);
    }
}

void quickSort(int* arr, int len)
{
    _quickSort(arr, 0, len - 1);
}

int main()
{
    int arr[] = { 3, 2, 4, 1, 5 };

    int* startArr = &arr[0];

    quickSort(arr, 5);

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }
}
