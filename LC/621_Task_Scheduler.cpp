/*You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.

Return the minimum number of CPU intervals required to complete all tasks.



Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2

Output: 8

Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.

After completing task A, you must wait two intervals before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2 intervals have passed.

Example 2:

Input: tasks = ["A","C","A","B","D","B"], n = 1

Output: 6

Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.

With a cooling interval of 1, you can repeat a task after just one other task.

Example 3:

Input: tasks = ["A","A","A", "B","B","B"], n = 3

Output: 10

Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B.

There are only two types of tasks, A and B, which need to be separated by 3 intervals. This leads to idling twice between repetitions of these tasks.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        unordered_map<char, int> um;
        int count = 0;

        for (char c : tasks)
        {
            um[c]++;
            count = max(count, um[c]);
        }

        int ans = (count - 1) * (n + 1);
        for (auto e : um)
        {
            if (e.second == count)
            {
                ans++;
            }
        }

        return max(ans, int(tasks.size()));
    }
};

/*
    First count the number of occurrences of each element.
    Let the max frequency seen be M for element E
    We can schedule the first M-1 occurrences of E, each E will be followed by at least N CPU cycles in between successive schedules of E
    Total CPU cycles after scheduling M-1 occurrences of E = (M-1) * (N + 1) // 1 comes for the CPU cycle for E itself
    Now schedule the final round of tasks. We will need at least 1 CPU cycle of the last occurrence of E. If there are multiple tasks with frequency M, they will all need 1 more cycle.
    Run through the frequency dictionary and for every element which has frequency == M, add 1 cycle to result.
    If we have more number of tasks than the max slots we need as computed above we will return the length of the tasks array as we need at least those many CPU cycles.
*/