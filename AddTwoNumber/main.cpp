#include <iostream>
#include <vector>


struct ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

};

void add_node(ListNode *l, int n)
{
    ListNode *tmp = new ListNode(n);
    while(l->next != nullptr)
    {
        l = l->next;
    }
    l->next = tmp;
}

class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        if(!l1 && !l2) return nullptr; // if l1 and l2 pointer point to invalid address

        int c = (l1? l1->val:0) + (l2? l2->val:0); //add first element of two list if valid address

        ListNode *newHead = new ListNode(c%10);
        ListNode *next = l1? l1->next:nullptr; 
        c /= 10;
        if(next)
        {
            next->val += c;
        }
        else if(c) //if two value added > 10 and at last position next is null add one more pos in linked list
        {
            next = new ListNode(c);
        }

        //this will create a newhead linked list newHead(val(c%10),&newHead(val(c%10),&newHead(val(c%10),null)))
        newHead->next = addTwoNumbers(next,l2? l2->next:nullptr);
        return newHead;
    }
};


int main ()
{
    Solution myresult;

    ListNode L1 {9};
    add_node(&L1,9);
    add_node(&L1,9);
    add_node(&L1,9);

    ListNode L2 {9};
    add_node(&L2,9);
    add_node(&L2,9);
    add_node(&L2,9);
    add_node(&L2,9);
    add_node(&L2,9);
    add_node(&L2,9);
    

    ListNode *r_ptr;
    r_ptr = myresult.addTwoNumbers(&L1, &L2);

    while (r_ptr->next != nullptr)
    {
        std::cout << r_ptr->val;
        r_ptr = r_ptr->next;
    }
    std::cout << r_ptr->val <<std::endl;

    return 0;
}