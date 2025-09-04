#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>> &arr)
{
    vector<int> temp = arr[0];
    int count = 0;
    sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
        return a[1] < b[1];
    });
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i][0] < temp[1])
        {
            count++;
        }
        else
        {
            temp = arr[i];
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> arr = {{1, 2}, {2, 4}, {4, 6}, {1, 2}};
    cout << eraseOverlapIntervals(arr);
    return 0;
}