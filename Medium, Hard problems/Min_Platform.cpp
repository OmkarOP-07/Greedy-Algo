#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int Min_Platforms(vector<int> &arr, vector<int> &dept){
    sort(arr.begin(), arr.end());
    sort(dept.begin(), dept.end());
    int i = 0; int j= 0; int count = 0;
    int maxCount = INT_MIN;
    while (i < arr.size() && j < dept.size())
    {
        if(arr[i] < dept[j]){
            count++;
            maxCount = max(maxCount, count);
            i++;
        } else {
            count--;
            maxCount = max(maxCount, count);
            j++;
        }
    }
    return maxCount;
}

// Arrival = [0900, 0940, 0950, 1100, 1500, 1800] , Departure = [0910, 1200, 1120, 1130, 1900, 2000]
int main()
{
    vector<int> arr = { 900, 1100, 1235};
    vector<int> dept ={1000, 1200, 1240};
    cout<<Min_Platforms(arr, dept);
    return 0;
}