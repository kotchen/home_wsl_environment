#include <iostream>
#include <vector>
#include <stack>
#include "include/tree_node/Node.h"
#include <algorithm>
class Solution {
public:
    std::vector<int> postorder(Node* root) {
        if (!root) return std::vector<int>();
        std::stack<Node*> s;
        std::vector<int> v;
        s.push(root);
        while (!s.empty())
        {
            auto temp = s.top();
            v.emplace_back(temp->val);
            s.pop();
            for (auto i : temp->children)
                s.push(i);
        }
        reverse(v.begin(), v.end());
        return v;
    }
};

class Solution {
public:
    std::vector<int> v;
    void _postorder(Node* root)
    {
        if (!root) return ;
        for (auto i : root->children)
        {
            _postorder(i);
        }
        v.emplace_back(root->val);
    }
    std::vector<int> postorder(Node* root) {
        _postorder(root);
        return v;
    }
};
int main(int argc, char const *argv[])
{
    Node node(1);
    return 0;
}
