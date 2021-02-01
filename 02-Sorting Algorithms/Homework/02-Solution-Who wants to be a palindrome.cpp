#include <iostream>
#include <string> 
using namespace std;

// 100/100 points

bool countingSortWithPalindromeCheck(char* arr, int len)
{
    bool seenTwoOddCount = false;

    //create and fill counting array
    int range = 127;
    int* countingArr = new int[range];

    for (int i = 0; i < range; i++)
    {
        countingArr[i] = 0;
    }

    for (int i = 0; i < len; i++)
    {
        int asciiValue = arr[i];
        countingArr[asciiValue]++;
    }

    //check the count of each letter in the counting arr
    int countOddLetters = 0;
    for (int i = 0; i < range; i++)
    {
        int value = countingArr[i];

        while (value == 0)
        {
            i++;
            if (i == range)
            {
                break;
            }
            value = countingArr[i];
        }

        if (value % 2 != 0)
        {
            countOddLetters++;
        }
    }

    if (countOddLetters > 1)
    {
        seenTwoOddCount = true;
    }
    return seenTwoOddCount;
}

int main()
{
    //read input

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;

        int len = input.length();
        char* arr = new char[len];

        //fill char arr
        for (int i = 0; i < len; i++)
        {
            arr[i] = input[i];
        }

        //sort char arr
        //check if it could be a palindome

        //if check is true => the word cannot be a palindrome
        bool check = countingSortWithPalindromeCheck(arr, len);

        if (check)
        {
            cout << "FALSE" << endl;
        }
        else
        {
            cout << "TRUE" << endl;
        }
    }
    return 0;
}
