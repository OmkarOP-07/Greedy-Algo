#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int> &arr)
{
    int maxInd = 0;
    if(arr.size() ==1) return true;
    for (int i = 0 ;i < arr.size(); i++)
    {
        maxInd = max(maxInd,arr[i]+i);
        if(maxInd >= arr.size()) return true;
        if(maxInd == arr[i] + i) return false;
    }
    return false;
}

int main()
{
    
    return 0;
}