#include "include/tree_node/binary_tree_node.h"

// 舒服了，第一次流畅的写出递归算法
class Solution {
public:

    bool helper(TreeNode* left, TreeNode* right)
    {
        if (!left && !right) return true;
        if (!left || !right) return false;
        if(left->val == right->val)  
        {
            return helper(left->left, right->right) &&
                   helper(left->right, right->left);
        }
        else return false;
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;

        return helper(root->left, root->right);
    }
};

int main(int argc, char const *argv[])
{
    /* code */

    TreeNode node;
    return 0;
}
