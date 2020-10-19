#include <iostream>
using namespace std;

void countingSort(int* array, int length) {
    //find the range of the counting array
    int maxNumber = 0;
    for (int i = 0; i < length; i++) {
        if (array[i] > maxNumber) {
            maxNumber = array[i];
        }
    }

    //create the counting array and fill it with 0s that will later be updated if needed
    int* countingArray = new int[maxNumber + 1];
    for (int i = 0; i < maxNumber + 1; i++) {
        countingArray[i] = 0;
    }

    //update the 0s in the counting array if we have that number in the original array
    for (int i = 0; i < length; i++) {
        countingArray[array[i]]++;
    }

    //move the sorted elements back in the original array
    int sortedIndex = 0;
    for (int i = 0; i < length; i++) {
        //while we still have at least 1 of that number
        while (countingArray[sortedIndex] == 0) {
            sortedIndex++;
        }

        array[i] = sortedIndex;
        countingArray[sortedIndex]--;
    }
    //we do not need the counting array anymore
    delete[] countingArray;
}

int main()
{
    int count;
    cin >> count;

    int* arr = new int[count];

    for (int i = 0; i < count; i++)
    {
        cin >> arr[i];
    }
    countingSort(arr, count);
    for (int i = 0; i < count; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
