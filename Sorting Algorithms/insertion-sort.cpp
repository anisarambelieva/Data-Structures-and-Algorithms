#include <iostream>
using namespace std;

void insertionSort(int* arr, int len)
{
	int toFindItsPlace;
	int current;

	for (int i = 1; i < len; i++)
	{
		//pick an element that will be inserted - key element
		toFindItsPlace = arr[i];

		//get the index of the previous one
		current = i - 1;

		//while we haven't reached the start of the array
		//and our key element is less than the current
		while (current >= 0 && arr[current] > toFindItsPlace)
		{
			//start moving the current element so as to make room for the key
			arr[current + 1] = arr[current];
			current--;
		}
		//move the key to its place
		arr[current + 1] = toFindItsPlace;
	}
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
	insertionSort(arr, count);
	for (int i = 0; i < count; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}
