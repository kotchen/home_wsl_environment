#include "include/graph_node/node.h"
#include <map>
using namespace std;
/*
这里的思路不难，就是遍历所有节点，我这里的写法是dfs
这里还使用一个map来记录已经构造的节点，如果节点已经构造那么直接返回
否则就要先构造节点了。
*/
class Solution {
public:
    map<int, Node*> m;
    Node* helper(Node* node)
    {
        auto ite = m.find(node->val);
        if (ite!=m.end())
            return ite->second;
        auto node_new = new Node(node->val);
        m[node_new->val] = node_new;
        for (auto i : node->neighbors)
        {
            node_new->neighbors.push_back(helper(i));
        }
        return node_new;
    }
    Node* cloneGraph(Node* node) {
        if (!node)
            return node;
        return helper(node);        
    }
};
int main(int argc, char const *argv[])
{
    return 0;
}
