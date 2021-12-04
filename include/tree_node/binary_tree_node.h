#ifndef __TreeNode__
#define __TreeNode__
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0), left(nullptr), right(nullptr){}
    TreeNode(int value): val(value), left(nullptr), right(nullptr){}
    TreeNode(int value, TreeNode* _left, TreeNode* _right):val(value),left(_left), right(_right){}
};
#endif