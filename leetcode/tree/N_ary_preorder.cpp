#include <iostream>
#include <vector>
#include <stack>
#include "include/tree_node/Node.h"
class Solution {
public:

    std::vector<int> v;
    void _preorder(Node* root)
    {
        if (!root) return ;
        v.emplace_back(root->val);
        for (auto i : root->children)
            _preorder(i);
    }

    std::vector<int> preorder(Node* root) {
        _preorder(root);
        return v;
    }
};
// class Solution {
// public:
//     std::vector<int> preorder(Node* root) {
//         if(!root) return std::vector<int>();
//         std::vector<int> v;
//         std::stack<Node*> s;
//         s.push(root);
//         while (!s.empty())
//         {
//             auto temp = s.top()->children;
//             v.emplace_back(s.top()->val);
//             s.pop();
//             for (auto i = temp.rbegin(); i!=temp.rend(); i++)
//             {
//                 if(!(*i)) continue;
//                 s.push(*i);
//             }
//         }
//         return v;
//     }
// };
int main(int argc, char const *argv[])
{
    Node node(1);
    return 0;
}
