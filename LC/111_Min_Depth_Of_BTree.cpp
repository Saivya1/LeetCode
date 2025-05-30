/* Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.



Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 2
Example 2:

Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5 */

#include <iostream>
#include <algorithm>
#include "BinaryTree.h"

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
    int minDepth(TreeNode *a)
    {
        if (!a)
            return 0;

        int MinDepth = INT_MAX;
        Traverse(a, 0, MinDepth);
        return MinDepth;
    }

private:
    void Traverse(TreeNode *a, int count, int &MinDepth)
    {
        if (!a)
            return;

        count++;
        if (!a->left && !a->right)
            MinDepth = min(MinDepth, count);

        Traverse(a->left, count, MinDepth);
        Traverse(a->right, count, MinDepth);
    }
};