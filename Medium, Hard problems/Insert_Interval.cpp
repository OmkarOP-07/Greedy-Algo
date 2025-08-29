#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& newInt) {
    int i = 0;
    int n = arr.size();
    vector<vector<int>> ans;
    while (i < n && arr[i][1] < newInt[0])
    {
        ans.push_back(arr[i]); 
        i++;
    }
    
    while (i < n && arr[i][0] <= newInt[1]) 
    {
        newInt[0] = min(newInt[0], arr[i][0]);
        newInt[1] = max(newInt[1], arr[i][1]);
        i++;
    }
    ans.push_back(newInt);
    while (i < n)   
    {
        ans.push_back(arr[i]);
        i++;
    }
    return ans;
    
}

int main()
{
    vector<vector<int>> arr = {{1,2} ,{3,5},{6,7}, {8,10},{12,16}};
    vector<int> newInt = {4,8};
    vector<vector<int>> ans = insert(arr, newInt);
    for (size_t i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}