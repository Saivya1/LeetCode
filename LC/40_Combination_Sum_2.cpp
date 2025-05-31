/*Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.



Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output:
[
[1,2,2],
[5]
]
*/

#include <iostream>
#include <vector>

using namespace std;

/*Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.



Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output:
[
[1,2,2],
[5]
]
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.



Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output:
[
[1,2,2],
[5]
]
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> curr;
    vector<vector<int>> res;

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return res;
    }

private:
    void dfs(vector<int> &candidates, int target, int idx)
    {
        if (target == 0)
        {
            res.push_back(curr);
            return;
        }
        if (idx == candidates.size() || target < 0)
        {
            return;
        }

        curr.push_back(candidates[idx]);
        dfs(candidates, target - candidates[idx], idx + 1);

        curr.pop_back();

        // Skip duplicates in the "skip" branch
        int nextIdx = idx + 1;
        while (nextIdx < candidates.size() && candidates[nextIdx] == candidates[idx])
        {
            nextIdx++;
        }
        dfs(candidates, target, nextIdx);
    }
};
