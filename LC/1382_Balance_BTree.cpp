/*Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.



Example 1:

Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.

Example 2:

Input: root = [2,1,3]
Output: [2,1,3]
*/

#include <iostream>
#include <BinaryTree.h>
#include <vector>

using namespace std;

class Solution
{
public:
    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> inorderVals;
        inorder(root, inorderVals); // Step 1: Store inorder traversal

        return sortedArrayToBST(inorderVals, 0, inorderVals.size() - 1); // Step 2: Rebuild BST
    }

private:
    void inorder(TreeNode *root, vector<int> &vals)
    {
        if (!root)
            return;
        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }

    TreeNode *sortedArrayToBST(vector<int> &vals, int left, int right)
    {
        if (left > right)
            return nullptr;

        int mid = (left + right) / 2;
        TreeNode *root = new TreeNode(vals[mid]);

        root->left = sortedArrayToBST(vals, left, mid - 1);
        root->right = sortedArrayToBST(vals, mid + 1, right);

        return root;
    }
};
