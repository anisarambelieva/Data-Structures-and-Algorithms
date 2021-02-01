#include <iostream>
using namespace std;

//THIS SOLUTION GETS 60/100p

void insertionSort(int * arr, int len)
{
    int toFindItsPlace;
    int current;

    for (int i = 1; i < len; i++)
    {
        toFindItsPlace = arr[len-1];
        current = len - 2;

        while (current >= 0 && arr[current] > toFindItsPlace)
        {
            arr[current + 1] = arr[current];
            current--;
        }
        arr[current + 1] = toFindItsPlace;
    }
}

double findMedian(int* arr, int len)
{
    //array will be sorted

    double result;

    if (len % 2 == 0)
    {
        int index1 = len / 2 - 1;
        int index2 = len / 2;
        result = (arr[index1] * 1.0 + arr[index2]) / 2;
    }
    else
    {
        int index = len / 2;
        result = arr[index];
    }

    return result;
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        int number;
        cin >> number;
        arr[i] = number;

        insertionSort(arr, i + 1);
        double res = findMedian(arr, i + 1);
        cout << res << endl;
    }
}
