#include "include/tree_node/list_node.h"
class Solution {
public:
    ListNode* res;
    void helper(ListNode* l1, ListNode* l2, ListNode* cur, int car)
    {
        if (!l1 && !l2)
        {
            if (car) 
            {
                ListNode* temp = new ListNode(1);
                cur->next = temp;
            }
            return ;
        }
        if (l1 && !l2)
        {
            int value = (l1->val+car)%10;
            car = (l1->val+car)/10;
            ListNode* temp = new ListNode(value);
            cur->next = temp;
            cur = cur->next;
            helper(l1->next, l2, cur, car);
        }
        if (!l1 && l2)
        {
            int value = (l2->val+car)%10;
            car = (l2->val+car)/10;
            ListNode* temp = new ListNode(value);
            cur->next = temp;
            cur = cur->next;
            helper(l1, l2->next, cur, car);
        }
        if (l1 && l2)
        {
            int value = (l1->val+l2->val+car)%10;
            car = (l1->val+l2->val+car)/10;
            ListNode* temp = new ListNode(value);
            cur->next = temp;
            cur = cur->next;
            helper(l1->next, l2->next, cur, car);
        }
    }
    
    ListNode* reverse(ListNode* left, ListNode* right)
    {
        if (!left || !right) return left;
        ListNode* new_right = right->next;
        right->next = left;
        return reverse(right, new_right);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* new_l1 = reverse(l1, l1->next);
        l1->next = nullptr;
        ListNode* new_l2 = reverse(l2, l2->next);
        l2->next = nullptr;
        res = new ListNode(0);
        helper(new_l1, new_l2, res, 0);
        auto head = res->next;
        res = reverse(head, head->next);
        head->next = nullptr;
        return res;
    }
};
int main(int argc, char const *argv[])
{
    
    return 0;
}