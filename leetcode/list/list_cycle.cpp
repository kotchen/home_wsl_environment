#include "include/tree_node/list_node.h"
// class Solution {
// public:
//     bool find(ListNode* head, ListNode* end, ListNode* target)
//     {
//         while (head!=end)
//         {
//             if (target==head) return true;
//             head = head->next;
//         }
//         return false;
//     }
//     bool hasCycle(ListNode *head) {
//         if (!head || !head->next) return false;
//         auto temp = head;
//         while (temp)
//         {
//             if (temp == temp->next) return true;
//             auto res = find(head, temp, temp->next);
//             if (res) return true;
//             temp = temp->next;
//         }
//         return false;
//     }
// };  慢的一，搞笑算法


// map 的使用
// class Solution {
// public:
//     unordered_map<ListNode*, int> m;
//     bool hasCycle(ListNode *head) {
//         if (!head || !head->next) return false;
//        int count = 0;
//        while (head)
//        {
//            auto ite = m.find(head->next);
//            if (ite!=m.end()) return true;
//            m[head] = count++;
//            head = head->next;
//        } 
//        return false;
//     }
// };

// 快慢指针
// 这个思想是真的巧妙，找链表中的第几个元素，就是正向遍历过去
// 但是如果是找倒数第n个元素，那么我们可能就是要先遍历，看看链表有多少个元素，然后再遍历一次
// 快慢指针 先用一个快的指针快速的跑到末端，我们只要设置好慢指针和快指针之间的间隔，就可以拿到倒数第N个数了。 
// 除此之外，快慢指针还可以判断是否有环。这就和跑步一样，如果链表有环，那么环就相当于一个跑道
// 快的指针和慢的指针必定会相遇。如果快的指针指向了nullptr说明没有环
// 快指针顾名思义，慢指针一次挑一下，快指针一次就跳多下
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next)
         return false;
        
        ListNode* pslow=head;
        ListNode* pfast=head->next;

        while(pslow!=pfast)
        {
            if(!pfast || !pfast->next)
                return false;
            pslow=pslow->next;
            pfast=pfast->next->next;
        }
        return true;
    }
};
int main(int argc, char const *argv[])
{
    
    return 0;
}