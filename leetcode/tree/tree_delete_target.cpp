#include "include/tree_node/binary_tree_node.h"
class Solution {
public:

    TreeNode* trim(TreeNode* root, int target)
    {
        if (!root) return nullptr;
        root->left = trim(root->left, target);
        root->right = trim(root->right, target);
        if (root->val == target && !root->left && !root->right) 
            return nullptr;
        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return trim(root, target);
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
