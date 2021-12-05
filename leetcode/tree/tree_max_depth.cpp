#include "include/tree_node/binary_tree_node.h"
#include <iostream>
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return std::max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
