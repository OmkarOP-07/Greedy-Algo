#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
	int MinimumCoins(vector<int>& coins, int amount) {
        int n = coins.size()-1;
        int minCoins = 0;
        while (n >= 0 && amount != 0)  
        {
            while (coins[n] <= amount)
            {
                amount -= coins[n];
                minCoins++;
            }
            n--;
        }
        return amount?-1:minCoins;
    }
};

int main()
{
    vector<int> coins = {2,5};
    int amount = 3;
    Solution sh;
    cout<<sh.MinimumCoins(coins, amount);
 return 0;
}