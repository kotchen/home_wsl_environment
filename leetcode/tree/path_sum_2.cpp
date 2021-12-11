#include "include/tree_node/binary_tree_node.h"
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    void helper(TreeNode* root, int targetSum, vector<int>& v)
    {
        if (!root) return ;
        if (!root->left && !root->right)
        {
            if (root->val == targetSum)
            {
                v.push_back(root->val);
                res.push_back(v);
                v.pop_back();
            }
            return ;
        }
        v.push_back(root->val);
        helper(root->left, targetSum-root->val, v);
        helper(root->right, targetSum-root->val, v);
        v.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> v;
        helper(root, targetSum, v);
        return res;
    }
};
 

int main(int argc, char const *argv[])
{
    
    return 0;
}
