#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};

class Solution {
  public:
   
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<Item> items;
        for (int i = 0; i < val.size(); i++)
        {
            Item temp ;
            temp.value = val[i];
            temp.weight = wt[i];
            items.push_back(temp);
        }
        sort(items.begin(), items.end(), [](Item val1,Item val2){                    // Lambda Function
        return (double)val1.value / val1.weight > (double)val2.value / val2.weight;  // descending order
        });
        double total = 0.0;
        for (int i = 0; i < val.size(); i++)
        {
            if(items[i].weight <= capacity){
                total += items[i].value;
                capacity = capacity - items[i].weight;
            } else {
                total += (double) items[i].value/items[i].weight * capacity;
                break;
            }
        }
        return total;
    }
};


int main()
{
    vector<int> value = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    Solution sh;
    cout<<sh.fractionalKnapsack(value, weight, 30);
 return 0;
}