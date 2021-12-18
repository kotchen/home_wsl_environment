#include "include/tree_node/list_node.h"
#include <iostream>
#include <vector>
#include <stack>
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
            left = left->next;
            merge(left, right, cur->next);
        }
        else
        {
            cur->next = right;
            right = right->next;
            merge(left, right, cur->next);
        }
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       if (!list1) return list2;
       if (!list2) return list1;
       if (list1->val<=list2->val)
       {
           auto cur = list1;
           auto res = cur;
           merge(list1->next, list2, cur);
           return res;
       }
       else
       {
           auto cur = list2;
           auto res = cur;
           merge(list1, list2->next, cur);
           return res;
       }
        
    }
};
int main(int argc, char const *argv[])
{
    ListNode node1(1); 
    ListNode node2(4); 
    ListNode node3(5); 

    ListNode node4(1); 
    ListNode node5(3); 
    ListNode node6(4); 

    ListNode node7(2); 
    ListNode node8(6); 

    node1.next = &node2;
    node2.next = &node3;

    node4.next = &node5;
    node5.next = &node6;
    
    node7.next = &node8;

    vector<ListNode*> v1;
    // v1.emplace_back(&node1, &node4, &node7);
    v1.push_back(&node1);
    v1.push_back(&node4);
    v1.push_back(&node7);
    Solution s;
    // auto x = s.mergeKLists(v1);
    ListNode* x = new ListNode(-1);
    s.merge(&node1, &node4, x);
    x = x->next;
    while (x)
    {
        cout << x->val << ' ';
        x = x->next;
    }
    cout << '\n';
    return 0;
}