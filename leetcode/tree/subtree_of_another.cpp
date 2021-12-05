#include "include/tree_node/binary_tree_node.h"
#include <stack>
class Solution {
public:

    bool is_same(TreeNode* left, TreeNode* right)
    {
        if (!left && !right) return true;
        if (!left || !right) return false;
        if (left->val == right->val)
        {
            return is_same(left->left, right->left) &&
                   is_same(left->right, right->right);
        }
        else return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        std::stack<TreeNode*> s;
        s.push(root);
        bool res = false;
        while (!s.empty())
        {
            auto temp = s.top();
            res = is_same(temp, subRoot);
            if (res) break;
            s.pop();
            if (temp->left) s.push(temp->left);
            if (temp->right) s.push(temp->right);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);

    TreeNode subnode1(1);
    TreeNode subnode2(2);
    TreeNode subnode3(4);

    node3.left = &node4;
    node3.right = &node5;
    node4.left = &node1;
    node4.right = &node2;

    subnode3.left = &subnode1;
    subnode3.right = &subnode2;

    Solution s;
    s.isSubtree(&node3, &subnode3);


    return 0;
}
