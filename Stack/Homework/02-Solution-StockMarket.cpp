#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int findMinDays(vector<int> allDays, int profit)
{
    int size = allDays.size();
    int result = size + 1;

    deque<int> helper;

    for (int i = 0; i < size; i++)
    {
        if (i > 0)
        {
            allDays[i] += allDays[i - 1];
        }

        if (allDays[i] >= profit)
        {
            result = min(result, i + 1);
        }

        while (helper.size() > 0 && allDays[i] - allDays[helper.front()] >= profit)
        {
            result = min(result, i - helper.front());
            helper.pop_front();
        }

        while (helper.size() > 0 && allDays[i] <= allDays[helper.back()])
        {
            helper.pop_back();
        }
        helper.push_back(i);
    }

    return result <= size ? result : -1;
}

int main()
{
    int countDays, minProfit;
    cin >> countDays >> minProfit;

    vector<int> allDays;

    for (int i = 0; i < countDays; i++)
    {
        int currDayProfit;
        cin >> currDayProfit;

        allDays.push_back(currDayProfit);
    }

    int res = findMinDays(allDays, minProfit);
    cout << res << endl;
    return 0;
}
