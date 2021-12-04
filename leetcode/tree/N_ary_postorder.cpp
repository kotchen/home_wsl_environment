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
int main(int argc, char const *argv[])
{
    Node node(1);
    return 0;
}
