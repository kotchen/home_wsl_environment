#include <iostream>
using namespace std;
struct List_Node
{
    int val;
    List_Node* next;
    List_Node* prev;
    List_Node(int val) : val(val), next(nullptr), prev(nullptr) {}
};
class MyLinkedList {
private:
    List_Node* head;
    size_t size;
public:
    MyLinkedList() {
        head = new List_Node(-1);
        size = 0;
    }
    
    int get(int index) {
        if (index<0 || index>size-1) 
            return -1;
        auto temp = head->next;
        while (index--)
            temp = temp->next;
        if (!temp) 
            return -1;
        else
            return temp->val;
    }

    List_Node* get_addr(int index)
    {
        auto temp = head->next;
        while (index--)
            temp = temp->next;
        return temp;
    }
    
    void addAtHead(int val) {
        if (!head->next)
        {
            head->next = new List_Node(val);
            head->next->prev = head->next;
            size++;
            return ;
        }
        auto node = new List_Node(val);
        auto tail = head->next->prev;
        head->next->prev = node;
        node->next = head->next;
        node->prev = tail;
        head->next = node;
        size++;
    }
    
    void addAtTail(int val) {
        if (!head->next)
        {
            addAtHead(val);
            return ;
        }
        auto node = new List_Node(val);
        auto tail = head->next->prev;
        tail->next = node;
        node->prev = tail;
        head->next->prev = node;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index<=0)
        {
            addAtHead(val);
            return ;
        }
        if (index == size)
        {
            addAtTail(val);
            return ;
        }
        if (index > size)
            return ;
        auto cur = get_addr(index);
        auto temp = new List_Node(val);
        temp->next = cur;
        temp->prev = cur->prev;
        cur->prev->next = temp;
        cur->prev = temp;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index>0 && index<size-1)
        {
            auto temp = get_addr(index);
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            size--;
            return ;
        }
        if (index == 0)
        {
            if (size == 1)
            {
                auto temp = head->next;
                head->next = nullptr;
                delete temp;
                size = 0;
                return ;
            }            
            else
            {
                auto tail = head->next->prev;
                auto temp = head->next;
                head->next = temp->next;
                head->next->prev = tail;
                delete temp;
                size--;
                return ;
            }
        }
        if (index == size-1)
        {
            if (size == 1)
            {
                auto temp = head->next;
                head->next = nullptr;
                delete temp;
                size = 0;
                return ;
            }
            else
            {
                auto tail = head->next->prev;
                head->next->prev = tail->prev;
                head->next->prev->next = nullptr;
                size--;
                return ;
            }
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main(int argc, char const *argv[])
{
    MyLinkedList* list = new MyLinkedList();
    list->addAtTail(1);
    list->addAtTail(3);
    cout << list->get(1) << '\n';
    return 0;
}
