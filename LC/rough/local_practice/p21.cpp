#include <iostream>
#include <vector>
#include "BinaryTree.h"

using namespace std;

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return root;
        }
        TreeNode *temp;
        temp = root->left;
        root->left = root->right;
        root->right = temp;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};