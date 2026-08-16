#include <iostream>
#include <vector>
#include <queue>
#include <BinaryTree.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
        {
            return ans;
        }

        queue<TreeNode *> q;

        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> v;
            while (size--)
            {
                TreeNode *node = q.front();
                q.pop();
                v.push_back(node->val);
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
            ans.push_back(v);
        }

        return ans;
    }
};