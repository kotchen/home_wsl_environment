#include "include/tree_node/list_node.h"
// map 的使用
// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         if (!head || !head->next) return nullptr;
//         unordered_set<ListNode*> m;
//         auto temp = head;
//         while (temp)
//         {
//             m.insert(temp);
//             auto ite = m.find(temp->next);
//             if (ite!=m.end()) return *ite;
//             temp = temp->next;
//         }
//         return nullptr;
//     }
// };
// 快慢指针
// 这个思想是真的巧妙，找链表中的第几个元素，就是正向遍历过去
// 但是如果是找倒数第n个元素，那么我们可能就是要先遍历，看看链表有多少个元素，然后再遍历一次
// 快慢指针 先用一个快的指针快速的跑到末端，我们只要设置好慢指针和快指针之间的间隔，就可以拿到倒数第N个数了。 
// 除此之外，快慢指针还可以判断是否有环。这就和跑步一样，如果链表有环，那么环就相当于一个跑道
// 快的指针和慢的指针必定会相遇。如果快的指针指向了nullptr说明没有环
// 快指针顾名思义，慢指针一次挑一下，快指针一次就跳多下
// 这里因为要返回环的起点，所以，不像第一题一样，起点随便设置，这里必须要同起点启动
// 先快慢指针找到环中一点，然后移动一个指针到head处，然后每次移动一格，最终相遇的位置就是入口
// 原理就是根据公式算出来的，快指针走的是慢指针的两倍 a = c + (n-1) * (b+c)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        if (!head || !head->next) return nullptr;
        auto pslow = head;
        auto pfast = head;
        while (true)
        {
            if (!pfast || !pfast->next) return nullptr;
            pslow = pslow->next;
            pfast = pfast->next->next;
            if (pfast == pslow) break;
        }
        pfast = head;
        while (pfast!=pslow)
        {
            pslow = pslow->next;
            pfast = pfast->next;
        }
        return pfast;
    }
};
int main(int argc, char const *argv[])
{
    
    return 0;
}