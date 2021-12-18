#include "include/tree_node/list_node.h"
/*
对链表实现插入排序，这个其实和数字的排序也没什么区别
一开始实现起来感觉有点难度，但是确实，又有方便之处。
因为可能有头节点的改变，所以可以单独的先判断一个是否是插入头节点

对于递归返回值的理解：
现在一般根据基本逻辑，是可以写出递归的
然后返回值就根据递归结束的条件来判断吧
比如这里，我们可以选择到了递归终点之后，return ;
但是最终我们需要一个指向头结点的指针，但是递归其实是一个栈，在回到第一层调用的时候
head其实还是原来的head, 所以我们将返回值设置为最新的头节点，这样就可以了。
*/
class Solution {
public:
    ListNode* helper(ListNode* head, ListNode* cur, ListNode* pre)
    {
        if (!cur) 
            return head;
        if (cur->val<pre->val)
        {
            // search from head
            if (head->val>cur->val)
            {
                pre->next = cur->next;
                cur->next = head;
                head = cur;
                return helper(head, pre->next, pre);
            }
            auto temp = head;
            while (temp!=pre)
            {
                if (temp->next->val<cur->val)
                    temp = temp->next;
                else
                {
                    pre->next = cur->next;
                    cur->next = temp->next;
                    temp->next = cur;
                    break;
                }
            }
            return helper(head, pre->next, pre);
        }
        else
        {
            return helper(head, cur->next, cur);
        }
    }
    ListNode* insertionSortList(ListNode* head) {
        if (!head) 
            return nullptr;
        if (!head->next) 
            return head;
        return helper(head, head->next, head);
    }
};