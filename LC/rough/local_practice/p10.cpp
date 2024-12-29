#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 1)
        {
            return 0;
        }
        int min = 9999;
        int curr_profit;
        int max_profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < min)
            {
                min = prices[i];
            }
            curr_profit = prices[i] - min;
            max_profit = max(curr_profit, max_profit);
        }

        return max_profit;
    }
};