#include <stack>
#include "include/tree_node/binary_tree_node.h"

class Solution {
public:

    void preoreder(TreeNode* p, TreeNode* q)
    {
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p && !q) return false;
        if (!p && q) return false;
        if (!p && !q) return true;
        std::stack<TreeNode*> p_s;
        std::stack<TreeNode*> q_s;
        p_s.push(p);
        q_s.push(q);
        bool res = true;
        while (!p_s.empty() && !q_s.empty())
        {
            auto temp_p = p_s.top();
            auto temp_q = q_s.top();
            if (temp_p->val != temp_q->val)
            {
                res = false;
                break;
            }
            p_s.pop();
            q_s.pop();
            if (temp_p->right && temp_q->right)
            {
                p_s.push(temp_p->right);
                q_s.push(temp_q->right);
            } 
            else if (!temp_p->right && !temp_q->right)
            {
            }
            else
            {
                res = false;
                break;
            }
            if (temp_p->left && temp_q->left)
            {
                p_s.push(temp_p->left);
                q_s.push(temp_q->left);
            }
            else if (!temp_p->left && !temp_q->left)
            {

            }
            else
            {
                res = false;
                break;
            }     
        }
        if (p_s.size() || q_s.size()) res = false;
        return res;
    }
};
// class Solution {
// public:

//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         if (p && !q) return false;
//         if (!p && q) return false;
//         if (!p && !q) return true;
//         if (p->val!=q->val) return false;
//         return isSameTree(p->left, q->left) && 
//                isSameTree(p->right, q->right);
//     } 
// };
int main(int argc, char const *argv[])
{
    /* code */
    TreeNode node;
    
    return 0;
}
