#include "include/tree_node/binary_tree_node.h"
#include <stack>
#include <vector>
#include <iostream>
class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return std::vector<int>();
        std::stack<TreeNode*> s;
        std::vector<int> v;
        auto temp = root;
        while (temp)
        {
            s.push(temp);
            temp = temp->left;
        }
        while (!s.empty())
        {
            if (s.top()->right)
            {
                auto temp = s.top()->right;
                v.push_back(s.top()->val);
                s.pop();
                while (temp)
                {
                    s.push(temp);
                    temp = temp->left;
                }
            }
            else
            {
                v.push_back(s.top()->val);
                s.pop();
            }
        }
        return v;  
    }
};
int main(int argc, char const *argv[])
{
    TreeNode* root;
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);

    root = &node1;
    node1.left = nullptr;
    node1.right = &node2;
    node2.left = &node3;
    
    Solution s;

    auto v = s.inorderTraversal(root);
    for (auto i : v)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
    return 0;
}

// class Solution {
// public:
//     std::vector<int> inorderTraversal(TreeNode* root) {
//         if (!root) return std::vector<int>();
//         std::stack<TreeNode*> s;
//         std::vector<int> v;
//         s.push(root);
//         while (!s.empty())
//         {
//             auto temp = s.top();
//             s.pop();
//             v.push_back(temp->val);
//             if (temp->right) s.push(temp->right);
//             if (temp->left) s.push(temp->left); 
//         }
//         return v;
//     }
// };


