#include <vector>
#include <deque>
#include "include/tree_node/Node.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return std::vector<std::vector<int>>();
        int counter = 1;
        std::deque<Node*> q;
        std::vector<std::vector<int>> res;
        q.push_back(root);
        while (!q.empty())
        {
            int new_counter = 0;
            std::vector<int> v;
            for (int count = 0; count < counter; count++)
            {
                auto i = q.front();
                
                for (auto x : i->children)
                {
                    if (!x) continue;
                    q.push_back(x);
                    new_counter++;
                }
                v.push_back(i->val);
                q.pop_front();
            }
            counter = new_counter;
            res.push_back(v);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    Node node1(1);
    Node node2(2);
    Node node3(3);
    Node node4(4);
    Node node5(5);
    Node node6(6);
    node1.children.push_back(&node3);
    node1.children.push_back(&node2);
    node1.children.push_back(&node4);

    node3.children.push_back(&node5);
    node3.children.push_back(&node6);

    auto res = s.levelOrder(&node1);
    return 0;
}

