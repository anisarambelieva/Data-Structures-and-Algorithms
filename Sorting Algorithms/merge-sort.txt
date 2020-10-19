#include <iostream>
using namespace std;

void merge(int* arr, int left, int mid, int right)
{
    int size1 = mid - left + 1;
    int size2 = right - mid;

    int* arr1 = new int[size1];
    int* arr2 = new int[size2];

    //fill the temp arrays
    for (int i = 0; i < size1; i++)
    {
        arr1[i] = arr[left + i];
    }
    for (int i = 0; i < size2; i++)
    {
        arr2[i] = arr[mid + i + 1];
    }

    //merge arrays back
    //idexes to track each array

    int i = 0; //first
    int j = 0; //second
    int k = left; //merged

    while (i < size1 && j < size2)
    {
        if (arr1[i] <= arr2[j])
        {
            arr[k] = arr1[i];
            i++; //move to the next element
        } 
        else
        {
            arr[k] = arr2[j];
            j++;
        }
        k++; //in both cases we have added to the merged array so we go to the next element

    }
    while (i < size1)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while (j < size2)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void mergeSort(int* arr, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    int arr[] = { 2, 3, 1, 5, 2, 7 };

    mergeSort(arr, 0, 5);

    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }

    //cout << "Hello World!\n";
}
