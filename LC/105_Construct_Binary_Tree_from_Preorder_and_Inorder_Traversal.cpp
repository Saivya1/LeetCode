/*Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.



Example 1:

Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
*/

#include <iostream>
#include <vector>
#include "BinaryTree.h"
#include <unordered_map>

using namespace std;

class Solution
{
    unordered_map<int, int> inorderMap;
    int preIndex = 0;

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {

        for (int i = 0; i < inorder.size(); ++i)
        {
            inorderMap[inorder[i]] = i;
        }

        return build(preorder, 0, inorder.size() - 1);
    }

private:
    TreeNode *build(vector<int> &preorder, int inStart, int inEnd)
    {
        if (inStart > inEnd)
            return NULL;

        int rootVal = preorder[preIndex++];
        TreeNode *root = new TreeNode(rootVal);

        int inIndex = inorderMap[rootVal];

        root->left = build(preorder, inStart, inIndex - 1);
        root->right = build(preorder, inIndex + 1, inEnd);

        return root;
    }
};
