#include "include/tree_node/list_node.h"
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
这道题时间空间消耗都快击败100%的哥们了
思路就是归并，因为合并K个升序链表和合并升序数组没有本质的区别
所以，就是先分治，最后合并链表就好了
1、实现合并两个升序链表的算法
    1.1 这里用递归实现，参数除了两个链表之外，还需要一个cur指针。
    1.2 结束递归的时候就return ; 干净利落的结束
2、实现分治算法。
    2.2 这里和数组没什么区别，主要就是主动使用了一个栈来完成暂存指针的工作
*/
class Solution {
public:
    stack<ListNode*> s;
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
        if (left->val <= right->val)
        {
            cur->next = left;
            // left = left->next;
            merge(left->next, right, cur->next);
        } 
        else
        {
            cur->next = right;
            // right = right->next;
            merge(left, right->next, cur->next);
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
    void helper(vector<ListNode*>& lists, int left, int right)
    {
        if (left+1 == right)
        {
            s.push(lists[right]);
            s.push(lists[left]);
            auto l = s.top();
            s.pop();
            auto r = s.top();
            s.pop();
            s.push(mergeTwoLists(l, r));
            return ;
        }
        if (left == right) 
        {
            s.push(lists[left]);
            return ;
        }
        int mid = (left+right)/2;
        helper(lists, left, mid);
        helper(lists, mid+1, right);
        auto l = s.top();
        s.pop();
        auto r = s.top();
        s.pop();
        s.push(mergeTwoLists(l, r));
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        if (size == 0) return nullptr;
        helper(lists, 0, size-1);
        return s.top();
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
    // auto x = s.mergeTwoLists(&node1, &node4);
    auto x = s.mergeKLists(v1);
    while (x)
    {
        cout << x->val << ' ';
        x = x->next;
    }
    cout << '\n';
    return 0;
}