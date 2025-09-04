#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() <= 1)
            return intervals;
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());
        vector<int> temp = intervals[0];

        for (auto it : intervals)
        {
            if (it[0] <= temp[1])
            {
                temp[1] = max(it[1], temp[1]);
            }
            else
            {
                ans.push_back(temp);
                temp = it;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> intervals1 = {{1, 4}, {0, 0}};
    Solution sh;
    vector<vector<int>> ans = sh.merge(intervals1);
    for (auto it : ans)
    {
        cout << it[0] << " " << it[1] << endl;
    }
}