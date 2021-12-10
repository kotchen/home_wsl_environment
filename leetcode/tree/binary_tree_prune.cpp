#include "include/tree_node/binary_tree_node.h"
/*
搞清楚这个prune的意思，就是子树中含有1就要保留，而不是删除0

*/
class Solution {
public:
    TreeNode* prune(TreeNode* root)
    {
        if (!root) return nullptr;

        root->left = prune(root->left);
        root->right = prune(root->right);

        if (root->left || root->right || root->val) return root;
        else return nullptr;

    }
    TreeNode* pruneTree(TreeNode* root) {
        return prune(root);
    }
};

int main(int argc, char const *argv[])
{
    TreeNode node1(0);
    TreeNode node2(0);
    TreeNode node3(0);
    TreeNode node4(0);

    node1.right = &node2;
    node2.left = &node3;
    node2.right = &node4;

    Solution s;
    auto root = s.pruneTree(&node1);


    return 0;
}
