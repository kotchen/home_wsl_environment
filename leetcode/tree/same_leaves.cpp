#include "include/tree_node/binary_tree_node.h"
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> res1;
    vector<int> res2;
    void dfs(TreeNode* root, vector<int>& res)
    {
        if (!root->left && !root->right) res.push_back(root->val);
        if (root->left) dfs(root->left, res);
        if (root->right) dfs(root->right, res);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs(root1, res1);
        dfs(root2, res2);
        if (res1.size() != res2.size()) return false;
        for (int i = 0; i < res1.size(); i++)
            if (res1[i]!=res2[i]) return false;
        return true;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
