#include "include/graph_node/random_node.h"
#include <map>
using namespace std;
/*
这里的思路和复制无向图一样，就是用一个map来记录之前访问过的节点
使用unordered_map会快一些
*/
class Solution {
public:
    map<Node*, Node*> m;
    Node* helper(Node* node)
    {
        if (!node)
            return nullptr;
        auto ite = m.find(node);
        if (ite!=m.end())
            return ite->second;
        auto node_new = new Node(node->val);
        m[node] = node_new;
        node_new->next = helper(node->next);
        node_new->random = helper(node->random); 
        return node_new;
    }
    Node* copyRandomList(Node* head) {
        if (!head)
            return head;
        return helper(head);
    }
};
int main(int argc, char const *argv[])
{
    return 0;
}
