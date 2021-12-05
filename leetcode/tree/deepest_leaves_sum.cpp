#include "include/tree_node/binary_tree_node.h"
#include <map>
#include <vector>
class Solution {
public:
    std::map<int, std::vector<int>> m;
    void deep_order(TreeNode* root, int y)
    {
        if (!root) return ;
        if (root->left) deep_order(root->left, y+1);
        m[y].emplace_back(root->val);
        if (root->right) deep_order(root->right,y+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        if (!root) return 0;
        deep_order(root, 0);
        int res = 0;
        auto layer = m.rbegin();
        for (auto i : layer->second)
            res += i;

        return res;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    TreeNode node;
    node.val = 1;
    return 0;
}
