#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root){
            return root;
        }
        swap(root->left,root->right);

        invertTree(root->left);
        invertTree(root->right);
    }
};