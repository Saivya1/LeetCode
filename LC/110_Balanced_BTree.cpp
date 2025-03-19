/*Given a binary tree, determine if it is
height-balanced
.



Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:

Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Example 3:

Input: root = []
Output: true
*/

#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool balanced = true;
    bool isBalanced(TreeNode *root)
    {
        dfs(root);
        return balanced;
    }

private:
    int dfs(TreeNode *root)
    {
        if (!root)
        {
            return -1;
        }

        int x = dfs(root->left);
        int y = dfs(root->right);

        if (abs(x - y) > 1)
        {
            balanced = false;
            return -1;
        }

        return max(x, y) + 1;
    }
};
;
