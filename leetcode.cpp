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
    ListNode* reverseKGroup(ListNode* head, int k) {
        std::vector<ListNode*> vec;
        while (head!=nullptr)
        {
            vec.push_back(head);
            head = head -> next;
        }
        if (k==1) return vec[0];
        for (int i = 0; i+k<=vec.size(); i=i+k)
            reverse(vec, i, i+k-1, k);
        return vec[k-1];
    }

    void reverse(const std::vector<ListNode*>& vec, int x, int y, int k)
    {
        if(x==0)
        {
            for (int i=x+1;i<=y-1;i++)
                vec[i]->next = vec[i-1];
            if (vec[y]->next!=nullptr) vec[x]->next = vec[y]->next;
            else vec[x]->next = nullptr;
            vec[y]->next = vec[y-1];
        }
        else 
        {
            vec[x-k]->next = vec[y];
            for (int i=x+1;i<=y-1;i++)
                vec[i]->next = vec[i-1];
            if (vec[y]->next!=nullptr) vec[x]->next = vec[y]->next;
            else vec[x]->next = nullptr;
            vec[y]->next = vec[y-1];
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

    Solution s;
    auto l = s.reverseKGroup(&node1,2);
    while(l!=nullptr) 
    {
        std::cout << l->val << ' ';
        l = l->next;
    }


}