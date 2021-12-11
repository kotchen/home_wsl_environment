#include "include/tree_node/binary_tree_node.h"
#include <vector>
using namespace std;
// class Solution {
// public:
//     bool dfs(TreeNode* root, int targetSum, int sum)
//     {
//         if (!root) return false;
//         if (!root->left && !root->right)  
//         {
//             sum+=root->val;
//             return (targetSum==sum);
//         }
//         sum+=root->val;
//         return 
//         dfs(root->left, targetSum, sum) ||
//         dfs(root->right, targetSum, sum);

//     }
//     bool hasPathSum(TreeNode* root, int targetSum) {
//         if(!root) return false;
//         return dfs(root, targetSum, 0);
//     }
// };


// 速度快，感觉是减少了一些计算的操作
class Solution {
public:
    bool dfs(TreeNode* root, int targetSum)
    {
        if (!root) return false;
        if (!root->left && !root->right)  
        {
            return (targetSum==root->val);
        }
        return dfs(root->left, targetSum-root->val) ||
               dfs(root->right, targetSum-root->val);

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return dfs(root, targetSum);
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
