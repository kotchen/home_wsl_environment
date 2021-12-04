#include <iostream>
#include <vector>
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

int main(int argc, char const *argv[])
{
    Node node(1);
    return 0;
}
