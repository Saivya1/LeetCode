/*Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.



Example 1:

Input: root = [3,1,4,null,2], k = 1
Output: 1

Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
*/

#include <iostream>
#include <vector>
#include <queue>
#include "BinaryTree.h"

using namespace std;

// class Solution
// {
// public:
//     priority_queue<int> maxheap;
//     int kthSmallest(TreeNode *root, int k)
//     {
//         dfs(root, k);
//         return maxheap.top();
//     }

// private:
//     void dfs(TreeNode *root, int k)
//     {
//         if (!root)
//         {
//             return;
//         }
//         maxheap.push(root->val);
//         if (maxheap.size() > k)
//         {
//             maxheap.pop();
//         }
//         dfs(root->left, k);
//         dfs(root->right, k);
//     }
// };

class Solution
{
public:
    vector<int> arr;
    int kthSmallest(TreeNode *root, int k)
    {
        inorder(root);
        return arr[k - 1];
    }

private:
    void inorder(TreeNode *root)
    {
        if (!root)

        {
            return;
        }
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }
};
