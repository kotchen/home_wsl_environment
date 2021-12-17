#include "include/tree_node/list_node.h"
class Solution {
public:
    void helper(ListNode* left, ListNode* right, ListNode* pre)
    {
        if (!right) 
        {
            pre->next = left;
            return ;
        }
        auto temp = right->next;
        right->next = left;
        left->next = temp;
        if (pre) pre->next = right;
        pre = left;
        if (pre->next) helper(pre->next, pre->next->next, pre);
        else pre->next = nullptr;
    }

    ListNode* swapPairs(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return head;
        auto res = head->next;
        helper(head, head->next, nullptr);
        return res;
    }
};
int main(int argc, char const *argv[])
{
    
    return 0;
}
