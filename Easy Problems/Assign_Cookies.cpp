#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int l = 0; int r = 0;
        sort(g.begin(), g.end()); 
        sort(s.begin(), s.end());
        while(l < g.size() && r < s.size()){ 
            if(g[l] <= s[r]) 
                l++;
            r++;
        }
        return l;
    }
};

int main(){
    Solution sh;
    vector<int> g = {1,2,3};
    vector<int> s = {1,2};

    cout<<sh.findContentChildren(g,s);
}