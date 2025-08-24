    #include<iostream>
    #include<bits/stdc++.h>
    using namespace std;

    struct ITEM {
        int profit;
        int deadline;
        int id;
    };

    int JobScheduling(vector<vector<int>> &jobs)
    {
        vector<ITEM> arr; int maxDead = 0;
        for (int i = 0; i < jobs.size(); i++)
        {
            ITEM temp;
            temp.id = jobs[i][0];
            temp.profit = jobs[i][2];
            temp.deadline = jobs[i][1];
            arr.push_back(temp);
            maxDead = max(maxDead, temp.deadline);
        }
        
        sort(arr.begin(), arr.end(), [](ITEM &a, ITEM &b){
            return a.profit > b.profit;
        });

        int maxProfit = 0;
        map<int,int> mp;
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = arr[i].deadline;j > 0;j--)
            {
                if(mp.find(j) == mp.end()){
                    mp[j] = arr[i].id;
                    maxProfit += arr[i].profit;
                    break;
                }
            }
        }
        cout << "Jobs scheduled: ";
        for (auto &it : mp) {
            cout << "JobID " << it.second << " at time " << it.first << " | ";
        }
        cout << endl;
        return maxProfit;       
    }

    int main()
    {
        vector<vector<int>> jobs = {
            {1, 4, 20},
            {2, 1, 10},
            {3, 1, 40},
            {4, 1, 30}
        };
        cout<<JobScheduling(jobs);
    return 0;
    }
