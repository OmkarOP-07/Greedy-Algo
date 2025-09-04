#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals;

        // Step 1: Sort intervals by start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        // Step 2: Traverse and merge
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= ans.back()[1]) {
                // Merge both start and end
                ans.back()[0] = min(ans.back()[0], intervals[i][0]);
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example test case 1
    vector<vector<int>> intervals1 = {{1,4},{0,0}};
    vector<vector<int>> result1 = sol.merge(intervals1);

    cout << "Output 1: ";
    for (auto &interval : result1) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    // Example test case 2
    vector<vector<int>> intervals2 = {{1,4},{0,2},{3,5}};
    vector<vector<int>> result2 = sol.merge(intervals2);

    cout << "Output 2: ";
    for (auto &interval : result2) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    // Example test case 3
    vector<vector<int>> intervals3 = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> result3 = sol.merge(intervals3);

    cout << "Output 3: ";
    for (auto &interval : result3) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}