#include <iostream>
#include <BinaryTree.h>

using namespace std;

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