/*The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

    For example, for arr = [2,3,4], the median is 3.
    For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.

Implement the MedianFinder class:

    MedianFinder() initializes the MedianFinder object.
    void addNum(int num) adds the integer num from the data stream to the data structure.
    double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.



Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class MedianFinder
{
public:
    priority_queue<int, vector<int>, greater<>> minheap;
    priority_queue<int> maxheap;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (maxheap.empty() or maxheap.top() > num)
        {
            maxheap.push(num);
        }
        else
        {
            minheap.push(num);
        }

        if (maxheap.size() > minheap.size() + 1)
        {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if (minheap.size() > maxheap.size() + 1)
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }

    double findMedian()
    {
        if (maxheap.size() == minheap.size())
        {
            if (maxheap.empty())
            {
                return 0;
            }
            else
            {
                double avg = (maxheap.top() + minheap.top()) / 2.0;
                return avg;
            }
        }
        else
        {
            return maxheap.size() > minheap.size() ? maxheap.top() : minheap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */