#include "include/tree_node/binary_tree_node.h"
#include <cmath>
#include <iostream>
class Solution {
public:
    int depth(TreeNode* root)
    {
        if (!root) return 0;
        return std::max(depth(root->left), depth(root->right))+1;
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (std::abs(depth(root->left)-depth(root->right))<=1)
        return isBalanced(root->left)&&isBalanced(root->right);
        else return false; 
    }
};

int main(int argc, char const *argv[])
{
    TreeNode node; 
    return 0;
}
