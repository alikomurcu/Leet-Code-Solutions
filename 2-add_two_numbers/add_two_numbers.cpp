/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int num, cr = 0;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* newNode = new ListNode();
        ListNode* head = newNode;
        ListNode* curr = head;
        while(l1 && l2)
        {
            num = l1->val + l2->val + cr;
            if(num>=10) cr = 1;
            else cr = 0;
            num = num%10;
            ListNode* result = new ListNode(num); 
            curr->next = result;
            curr = curr->next; l1 = l1->next; l2 = l2->next;
        }
        if(l1)
        {
            while(l1)
            {
                num = l1->val + cr;
                if(num>=10) cr = 1;
                else cr = 0;
                num = num%10;
                ListNode* result = new ListNode(num); 
                curr->next = result;
                curr = curr->next;
                l1 = l1->next;
            }
        }
        if (l2)
        {
            while(l2)
            {
                    num = l2->val + cr;
                    if(num>=10) cr = 1;
                    else cr = 0;
                    num = num%10;
                    ListNode* result = new ListNode(num); 
                    curr->next = result;
                    curr = curr->next;
                    l2 = l2->next;
            }
        }
        if(!l1 && !l2)
        {
            if(cr == 1)
            {
                ListNode* result = new ListNode(cr); 
                curr->next = result;
            }
        }
        return head->next;
    }
};