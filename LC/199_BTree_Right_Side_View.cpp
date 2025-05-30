/*Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.



Example 1:

Input: root = [1,2,3,null,5,null,4]

Output: [1,3,4]

Explanation:

Example 2:

Input: root = [1,2,3,4,null,null,null,5]

Output: [1,3,4,5]

Explanation:

Example 3:

Input: root = [1,null,3]

Output: [1,3]

Example 4:

Input: root = []

Output: []
*/

#include <iostream>
#include <vector>
#include "BinaryTree.h"
#include <queue>

using namespace std;

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;

        if (!root)
            return ans;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int l = q.size();

            for (int i = 0; i < l; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                // Only add the first node of the current level (rightmost due to order)
                if (i == 0)
                    ans.push_back(node->val);

                // Push right child first so it's processed before left
                if (node->right)
                    q.push(node->right);
                if (node->left)
                    q.push(node->left);
            }
        }

        return ans;
    }
};
