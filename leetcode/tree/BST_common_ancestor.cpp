#include "include/tree_node/binary_tree_node.h"
#include <vector>
using namespace std;
/*
公共祖先，逻辑上很好理解，如果要找的两个节点在当前节点的两边，那么公共祖先就是当前节点了。
如果两个节点在当前节点的左边，那么就递归调用，让根节点变成左子节点
同理，就可以写出右子节点的代码

如果不是都在左边或者都在右边，那么就可能是有一个节点是root，那么公共祖先就是root,返回即可
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val>p->val&&root->val>q->val)
            return lowestCommonAncestor(root->left, p ,q);
        else if (root->val<p->val&&root->val<q->val)
            return lowestCommonAncestor(root->right, p ,q);
        else 
            return root;
    } 
};

int main(int argc, char const *argv[])
{
    TreeNode node0(0);
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);
    TreeNode node6(6);
    TreeNode node7(7);
    TreeNode node8(8);
    node3.left = &node5;
    node3.right = &node1;
    node5.left = &node6;
    node5.right = &node2;
    node2.left = &node7;
    node2.right = &node4;
    node1.left = &node0;
    node1.right = &node8;
    Solution s;
    s.lowestCommonAncestor(&node3, &node5, &node1);
    return 0;
}