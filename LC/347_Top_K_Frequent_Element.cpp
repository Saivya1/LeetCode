/* Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.



Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
  */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freqMap;

        // Count frequency of each element
        for (int num : nums)
        {
            freqMap[num]++;
        }

        // Min-heap to keep top k elements
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        for (auto ele : freqMap)
        {
            minHeap.push({ele.second, ele.first});
            if (minHeap.size() > k)
            {
                minHeap.pop();
            }
        }

        vector<int> result;
        while (!minHeap.empty())
        {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};

int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    Solution s;
    vector<int> result = s.topKFrequent(nums, k);

    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
