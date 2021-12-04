#include "include/binary_tree/tree_node.h"
#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
public:
    std::vector<int> v;
    void postorder(TreeNode* root)
    {
        if (!root) return ;
        postorder(root->left);
        postorder(root->right);
        v.push_back(root->val); 
    }
    std::vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return v;
    }
};

// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         if (!root) return std::vector<int>();
//         std::stack<TreeNode*> s;
//         std::vector<int> v;
//         s.push(root);
//         while (!s.empty())
//         {
//             v.push_back(s.top()->val);
//             auto temp = s.top();
//             s.pop();
//             if (temp->left) s.push(temp->left);
//             if (temp->right) s.push(temp->right);
//         }
//         reverse(v.begin(), v.end());
//         return v;

//     }
// };
int main(int argc, char const *argv[])
{
    
    return 0;
}
