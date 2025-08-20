#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0; int n = nums.size();
        int r = 0; int jumps = 0;
        while(r < n-1){
            int farthest = 0;
            for(int ind = l; ind <= r; ind++) farthest = max(farthest, nums[ind] + ind);
            l = r + 1; r = farthest;
            jumps = jumps + 1;
        }
        return jumps;
    }
};

int main()
{
    vector<int> arr = {2,3,1,1,4};
    Solution sh;
    cout<<sh.jump(arr);
 return 0;
}