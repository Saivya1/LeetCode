#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        int maxl = maxDepth(root->left);
        int maxr = maxDepth(root->right);

        return 1+max(maxl,maxr);


    }
};