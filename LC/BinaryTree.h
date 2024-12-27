#ifndef BinaryTree
#define BinaryTree

#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Tree
{
public:
    TreeNode *create()
    {
        int x;
        cout << "Enter the value (-1 for no new node) : " << endl;
        cin >> x;
        TreeNode *newnode = new TreeNode(x);

        if (x == -1)
        {
            return 0;
        }

        cout << "Enter the left child of " << x << endl;
        newnode->left = create();

        cout << "Enter the right child of " << x << endl;
        newnode->right = create();

        return newnode;
    }

    void preorder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
    void postorder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->val << " ";
    }
    void inorder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
};

#endif