#include <iostream>
#include <vector>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        std::vector<ListNode*> vec;
        while (head!=nullptr)
        {
            vec.push_back(head);
            head = head->next;
        }

        if (vec.size()==0) return nullptr;

        int x = k % vec.size();

        return reverse(vec, x);

    }

    ListNode* reverse(std::vector<ListNode*>& vec, int x)
    {
        if (x == 0) return vec[0];
        else
        {
            ListNode* new_head = vec[vec.size()-x];
            ListNode* new_end  = vec[vec.size()-x-1];
            new_end->next = nullptr;
            (*vec.rbegin())->next = vec[0];
            return new_head;
        }
    }
};

int main()
{
    ListNode node1(1);
    ListNode node2(2);
    // ListNode node3(3);
    // ListNode node4(4);
    // ListNode node5(5);

    node1.next = &node2;
    // node2.next = &node3;
    // node3.next = &node4;
    // node4.next = &node5;

    // Solution s;
    // auto l = s.reverseKGroup(&node1,2);
    // while(l!=nullptr) 
    // {
    //     std::cout << l->val << ' ';
    //     l = l->next;
    // }


}