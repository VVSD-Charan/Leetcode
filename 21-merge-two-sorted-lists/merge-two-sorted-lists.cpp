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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if(list1 == NULL)return list2;
        if(list2 == NULL)return list1;

        ListNode* new_head = NULL;
        ListNode* tail = NULL;
        ListNode* l1 = list1;
        ListNode* l2 = list2;

        while(l1 && l2)
        {
            if(l1->val > l2->val)
            {
                if(new_head == NULL)
                {
                    new_head = new ListNode(l2->val);
                    tail = new_head;
                }
                else
                {
                    tail -> next = new ListNode(l2->val);
                    tail = tail -> next;
                }
                l2 = l2 -> next;
            }
            else
            {
                if(new_head == NULL)
                {
                    new_head = new ListNode(l1 -> val);
                    tail = new_head;
                }
                else
                {
                    tail -> next = new ListNode(l1 -> val);
                    tail = tail -> next;
                }
                l1 = l1 -> next;
            }
        }

        if(l1)tail->next=l1;
        if(l2)tail->next=l2;

        return new_head;
    }
};