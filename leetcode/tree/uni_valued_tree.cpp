#include "include/tree_node/binary_tree_node.h"
#include <stack>

class Solution {
public:

    bool isUnivalTree(TreeNode* root) {
        std::stack<TreeNode*> s;
        s.push(root);
        int value = root->val;
        int res = true;
        while (!s.empty())
        {
            auto temp = s.top();
            if (temp->val != value) 
            {
                res = false;
                break;
            }
            s.pop();
            if (temp->right) s.push(temp->right);
            if (temp->left) s.push(temp->left);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
