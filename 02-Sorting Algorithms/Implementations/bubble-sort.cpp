#include <iostream>
using namespace std;

// helper to swap two elements
void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void bubbleSort(int * arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

int main()
{
	int count;
	cin >> count;

	int* arr = new int[count];

	//fill array
	for (int i = 0; i < count; i++)
	{
		cin >> arr[i];
	}

	bubbleSort(arr, count);

	//print to check if sorted
	for (int i = 0; i < count; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}
