// Input : Start = [1, 3, 0, 5, 8, 5] , End = [2, 4, 6, 7, 9, 9]
// Output : 4
// Explanation : The meetings that can be accommodated in
// meeting room are (1,2) , (3,4) , (5,7) , (8,9).

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct Item
    {
        int start;
        int end;
        int posi;
    };
    int maxMeetings(vector<int> &start, vector<int> &end)
    {
        int count = 0;
        int freetime = 0;
        vector<Item> items;
        vector<int> posi;
        for (int i = 0; i < start.size(); i++)
        {
            Item temp;
            temp.start = start[i];
            temp.end = end[i];
            temp.posi = i;
            items.push_back(temp);
        }

        sort(items.begin(), items.end(), [](Item &a, Item &b)
             { return a.end < b.end; });

        for (int i = 0; i < start.size(); i++)
        {
            if (items[i].start > freetime)
            {
                count++;
                freetime = items[i].end;
                posi.push_back(items[i].posi);
            }
        }
        for (int i = 0; i < posi.size(); i++)
        {
            cout << posi[i] << " ";
        }
        cout << endl;
        return count;
    }
};

int main()
{
    Solution sh;
    vector<int> start = {10, 12, 20};
    vector<int> end ={ 20, 25, 30};
    cout<<sh.maxMeetings(start, end);
    return 0;
}