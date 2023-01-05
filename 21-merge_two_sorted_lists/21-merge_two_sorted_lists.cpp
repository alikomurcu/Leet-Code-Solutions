#include<vector>
#include<cmath>
#include<iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *cur1 = list1, *cur2 = list2;
        if(cur1 == nullptr) return cur2;
        if(cur2 == nullptr) return cur1;
        ListNode *ret = new ListNode();
        ListNode *cur = ret;
        while (cur1 != nullptr && cur2 != nullptr)
        {
            if (cur1->val > cur2->val)
            {
                cur->val = cur2->val;
                cur->next = new ListNode();
                cur = cur->next;
                cur2 = cur2->next;
            }
            else
            {
                cur->val = cur1->val;
                cur->next = new ListNode();
                cur = cur->next;
                cur1 = cur1->next;
            }
        }
        while(cur1 != nullptr)
        {
            cur->val = cur1->val;
            if(cur1->next != nullptr)
            {
                cur->next = new ListNode();
                cur = cur->next;
            }
            else
            {
                cur->next = nullptr;
            }
            cur1 = cur1->next;
        }
        while (cur2 != nullptr)
        {
            cur->val = cur2->val;
            if(cur2->next != nullptr)
            {
                cur->next = new ListNode();
                cur = cur->next;
            }
            else
            {
                cur->next = nullptr;
            }
            cur2 = cur2->next;
        }
        return ret;
    }
};
