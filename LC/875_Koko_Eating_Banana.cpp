/* Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile.

If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.



Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution
{
public:
    // int minEatingSpeed(vector<int> &piles, int h)
    // {

    //     int total_hour_cost = 0;
    //     for (double i = 1; i < *max_element(piles.begin(), piles.end()); i++)
    //     {
    //         for (int j = 0; j < piles.size(); j++)
    //         {
    //             total_hour_cost += ceil((piles[j] / i));
    //         }
    //         if (total_hour_cost <= h)
    //         {
    //             return i;
    //         }
    //         else
    //         {
    //             total_hour_cost = 0;
    //         }
    //     }
    //     return *max_element(piles.begin(), piles.end());
    // }
    //                         Better Solution

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int total_hour_cost = 0;

            for (int pile : piles)
            {
                total_hour_cost += ceil(static_cast<double>(pile) / mid);
            }

            if (total_hour_cost <= h)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        return left;
    }
};

int main()
{
    vector<int> piles{3, 6, 7, 11};
    int h = 8;

    Solution s;

    cout << s.minEatingSpeed(piles, h);
}
