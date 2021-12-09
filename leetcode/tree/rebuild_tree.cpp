#include "include/tree_node/binary_tree_node.h"
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// class Solution {
// public:
//     int index = 0;
//     unordered_map<int, int> dic;
//     TreeNode* helper(vector<int>& preorder, 
//                      vector<int>& inorder, 
//                      int left, int right, int& index)
//     {
//         if (left == right) return  new TreeNode(preorder[index++]);
//         if (left>right) return nullptr;
//         // int i = left;
//         // for (; i<=right; i++)
//         // {
//         //     if (inorder[i] == preorder[index]) break;
//         // }
//         int i = dic[preorder[index]];
//         TreeNode* root = new TreeNode(preorder[index++]);
//         root->left = helper(preorder, inorder, left, i-1, index);
//         root->right = helper(preorder, inorder, i+1, right, index);
//         return root;
//     }
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         if (!preorder.size() || !inorder.size()) return nullptr;
//         TreeNode* root = nullptr;
//         for (int i = 0; i<inorder.size(); i++)
//             dic[inorder[i]] = i;
//         root = helper(preorder, inorder, 0, inorder.size()-1, index);
//         return root;
//     }
// };

class Solution {
public:
    int index = 0;
    unordered_map<int, int> u_m;
    TreeNode* helper(vector<int>& preorder, int left, int right)
    {
        if (left == right) return  new TreeNode(preorder[index++]);
        if (left>right) return nullptr;
        int i = u_m[preorder[index]];
        TreeNode* root = new TreeNode(preorder[index++]);
        root->left = helper(preorder, left, i-1);
        root->right = helper(preorder, i+1, right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (!preorder.size() || !inorder.size()) return nullptr;
        TreeNode* root = nullptr;
        for (int i = 0; i<inorder.size(); i++)
            u_m[inorder[i]] = i;
        root = helper(preorder, 0, inorder.size()-1);
        return root;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode node1(1);
    TreeNode node2(2);
    node1.left = nullptr;
    node1.right = &node2;
    Solution s;
    vector<int> preorder = {3,1,2,4};
    vector<int> inorder = {1,2,3,4};
    auto root = s.buildTree(preorder, inorder);

    return 0;
}
