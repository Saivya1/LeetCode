#include <iostream>
#include <vector>
#include <BinaryTree.h>

using namespace std;

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        int x = 0;
        int y = 0;

        x += maxDepth(root->left);
        y += maxDepth(root->right);

        return max(x, y) + 1;
    }
};