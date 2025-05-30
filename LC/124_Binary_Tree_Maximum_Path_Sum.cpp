/*A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.



Example 1:

Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

Example 2:

Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include "BinaryTree.h"

using namespace std;

class Solution
{
public:
    int maxsum = INT_MIN;

    int maxPathSum(TreeNode *root)
    {
        dfs(root);
        return maxsum;
    }

private:
    int dfs(TreeNode *node)
    {
        if (!node)
            return 0;

        // Recurse left and right, ignore negative paths
        int left = max(0, dfs(node->left));
        int right = max(0, dfs(node->right));

        // Case 1: path that passes through this node as peak
        int localMax = left + right + node->val;
        maxsum = max(maxsum, localMax);

        // Case 2: path to be extended to parent (only one side allowed)
        return max(left, right) + node->val;
    }
};
