#include <iostream>
#include <BinaryTree.h>

using namespace std;

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {

        if (!p && !q)
        {
            return true;
        }
        if (!p || !q)
        {
            return false;
        }
        if (p->val != q->val)
        {
            return false;
        }

        bool x = isSameTree(p->left, q->left);
        bool y = isSameTree(p->right, q->right);

        return x && y;
    }
};