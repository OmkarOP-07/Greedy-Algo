#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int candy(vector<int> &arr)
{
    vector<int> left(arr.size());
    int ans = 0; int curr = 1;
    left[0] = 1; int right = 1;

    for (int i = 1; i < arr.size(); i++)
    {
        if(arr[i] > arr[i - 1]){
            left[i] = left[i-1] + 1;
        } else {
            left[i] = 1;
        }
    }
    for (int i = 0; i < left.size(); i++){
        cout<<left[i]<<" ";
    }
    ans += max(1, left[arr.size()-1]);

    for (int i = arr.size()-2; i >= 0; i--)
    {
        if(arr[i] > arr[i + 1]){
            curr = right + 1;
            
        } else {
            curr = 1;
        }
        right = curr;
        ans += max(left[i], curr);
    }

    return ans;

}

int main()
{
    vector<int> arr = {1,3,2,2,1};
    cout<<candy(arr);
    return 0;
}