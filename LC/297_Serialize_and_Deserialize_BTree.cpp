/*Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.



Example 1:

Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]

Example 2:

Input: root = []
Output: []
*/

#include <iostream>
#include <vector>
#include <sstream>
#include "BinaryTree.h"

using namespace std;

class Codec
{
public:
    string serialize(TreeNode *root)
    {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    TreeNode *deserialize(string data)
    {
        istringstream in(data);
        return deserialize(in);
    }

private:
    void serialize(TreeNode *root, ostringstream &out)
    {
        if (root)
        {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        }
        else
        {
            out << "# ";
        }
    }

    TreeNode *deserialize(istringstream &in)
    {
        string val;
        in >> val;
        if (val == "#")
            return nullptr;
        TreeNode *root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};
