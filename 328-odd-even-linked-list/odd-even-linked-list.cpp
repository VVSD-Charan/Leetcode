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
    ListNode* oddEvenList(ListNode* head) 
    {
        if(head == NULL || head -> next == NULL)return head;

        ListNode* new_head = new ListNode(head->val);
        ListNode* tail = new_head;
        ListNode* temp = head->next->next;

        while(temp)
        {
            tail -> next = new ListNode(temp->val);
            tail = tail->next;

            if(temp->next)temp = temp->next->next;
            else temp = NULL;
        }    

        temp = head->next;

        while(temp)
        {
            tail->next = new ListNode(temp->val);
            tail = tail->next;

            if(temp->next)temp=temp->next->next;
            else temp = NULL;
        }

        return new_head;
    }
};