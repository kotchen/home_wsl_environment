#include "include/tree_node/binary_tree_node.h"
#include <vector>
using namespace std;
/*
对于二叉搜索树来说，我们可以很好的分辨，p,q是在root的左边还是右边，从而递归调用函数
现在对于一颗普通的二叉树，我们怎么找

之前可以用值搜索，那么现在只能使用指针相等来实现
而且也很好写，因为如果p, q在一边的话，先遇到谁，谁就是公共祖先

1、直接搜索，找到就立刻返回
2、如果左边和右边都找到了，那么root就是公共祖先
3、如果有一边没有，那么说明在一边，而且返回值就是存在的那个，因为上面以及说了先遇到的就是祖先

*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) 
            return root;
        auto left = lowestCommonAncestor(root->left, p, q); 
        auto right = lowestCommonAncestor(root->right, p, q);

        if (left && right) return root;
        else if (!left && right) return right;
        else if (left && !right) return left;
        else return nullptr;
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
