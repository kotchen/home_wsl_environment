#include "include/tree_node/list_node.h"
#include <iostream>
using namespace std;
class Solution {
public:
    void merge(ListNode* left, ListNode* right, ListNode* cur)
    {
        if (!left) 
        {
            cur->next = right;
            return ;
        }
        if (!right)
        {
            cur->next = left;
            return ;
        }
        if (left->val<=right->val)
        {
            cur->next = left;
            merge(left->next, right, cur->next);
        }
        else
        {
            cur->next = right;
            merge(left, right->next, cur->next);
        }
    }
    ListNode* find(ListNode* begin, ListNode* end)
    {
        auto pslow = begin;
        auto pfast = begin;
        while (true)
        {
            if (pfast==end || pfast->next==end || !pfast || !pfast->next)
                return pslow;
            pslow = pslow->next;
            pfast = pfast->next->next;
        }
    }
    ListNode* helper(ListNode* begin, ListNode*end)
    {
        // if (!begin || !end) return nullptr;
        if (begin->next == end)
        {
            if (begin->val>end->val)
            {
                end->next = begin;
                begin->next = nullptr;
                return end;
            }
            else
            {
                end->next = nullptr;
                return begin;
            }

        }
        if (begin == end)
        {
            begin->next = nullptr;
            return begin;
        }
        auto mid = find(begin, end);
        auto right = helper(mid->next, end);
        auto left = helper(begin, mid);
        if (left->val<=right->val)
        {
            auto cur = left;
            auto res = cur;
            merge(left->next, right, cur);
            return res;
        }
        else
        {
            auto cur = right;
            auto res = cur;
            merge(left, right->next, cur);
            return res;
        }
    }
    ListNode* sortList(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return head;
        auto end = head;
        while (end->next)
            end = end->next;
        return helper(head, end); 
    }
};


int main(int argc, char const *argv[])
{
    ListNode node1(4);
    ListNode node2(2);
    ListNode node3(1);
    ListNode node4(3);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;

    Solution s;
    auto res = s.sortList(&node1);
    while (res)
    {
        cout << res->val  << ' ';
        res = res->next;
    }
    cout << '\n';
    return 0;
}
