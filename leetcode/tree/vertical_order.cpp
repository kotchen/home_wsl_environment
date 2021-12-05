#include "include/tree_node/binary_tree_node.h"
#include <vector>
#include <set>
#include <map>
class Solution {
public:
    std::map<int, std::multiset<int>> m;
    void level_order(TreeNode* root, int x, int y)
    {
        if (!root) return ;
        m[x].insert(y*1000 + root->val);
        if (root->left) level_order(root->left, x-1, y+1);
        if (root->right) level_order(root->right, x+1, y+1);
    }
    std::vector<std::vector<int>> verticalTraversal(TreeNode* root) {
        if (!root) return std::vector<std::vector<int>> ();
        level_order(root, 0, 0);
        std::vector<std::vector<int>> res;
        for (auto i : m)
        {
            std::vector<int> v;
            for (auto ii : i.second)
                v.emplace_back(ii%1000);
            res.emplace_back(v);
        }
        return res;
    }    
};

int main(int argc, char const *argv[])
{
    /* code */
    TreeNode node;
    return 0;
}
