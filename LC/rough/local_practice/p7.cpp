#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int mid;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            int total = 0;

            for (int pile : piles)
            {
                total += ceil(static_cast<double>(pile) / mid);
            }

            if (total <= h)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return l;
    }
};