#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int ShortestJobFirst(vector<int> arr){
    int ti = 0;
    int wt = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        wt = ti + wt;
        ti = ti + arr[i];
    }
    int ans = wt/arr.size();
    return ans;
}   

int main()
{
    vector<int> arr = {1,2,3,4,7};
    cout<<ShortestJobFirst(arr);
 return 0;
}