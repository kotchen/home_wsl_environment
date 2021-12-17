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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        res = new ListNode(0);
        helper(l1, l2, res, 0);
        return res->next;
    }
};
int main(int argc, char const *argv[])
{
    
    return 0;
}
