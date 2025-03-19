#include <iostream>
#include <vector>
#include <BinaryTree.h>

using namespace std;

class Solution
{
public:
    int res = 0;
    int diameterOfBinaryTree(TreeNode *root)
    {
        dfs(root);
        return res;
    }

private:
    int dfs(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        int x = 0;
        int y = 0;

        x = dfs(root->left);
        y = dfs(root->right);

        res = max(res, x + y);

        return max(x, y) + 1;
    }
};