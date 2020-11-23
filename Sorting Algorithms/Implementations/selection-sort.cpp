#include <iostream>
using namespace std;

// helper to swap two elements
void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void selectionSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		//let the first be the minimum element
		int indexOfMin = i;

		//we start from the next element
		for (j = i + 1; j < n; j++)
		{
			//if we find a smaller element, update the minIndex
			if (arr[j] < arr[indexOfMin])
			{
				indexOfMin = j;
			}
		}

		//if we have updated the minIndex, swap the values
		if (indexOfMin != i)
		{
			swap(arr[i], arr[indexOfMin]);
		}
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
	selectionSort(arr, count);
	for (int i = 0; i < count; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}
