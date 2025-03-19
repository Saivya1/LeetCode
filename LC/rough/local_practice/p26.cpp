#include <iostream>
#include <BinaryTree.h>

using namespace std;

class Solution
{
public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (!root)
        {
            return false;
        }
        if (helper(root, subRoot))
        {
            return true;
        }

        bool l = isSubtree(root->left, subRoot);
        bool r = isSubtree(root->right, subRoot);

        return l || r;
    }

private:
    bool helper(TreeNode *p, TreeNode *q)
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

        bool l = helper(p->left, q->left);
        bool r = helper(p->right, q->right);

        return l && r;
    }
};