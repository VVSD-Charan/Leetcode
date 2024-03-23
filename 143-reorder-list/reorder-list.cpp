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
    void reorderList(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)return;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second_head = slow->next;
        ListNode* prev = NULL;
        ListNode* nxt = second_head->next;

        slow->next = NULL;

        while(nxt)
        {
            second_head->next = prev;
            prev = second_head;
            second_head = nxt;

            nxt = nxt->next;
        }
        second_head->next = prev;

        ListNode* ptr = head;

        while(second_head)
        {
            nxt = second_head->next;
            second_head->next = NULL;

            ListNode* temp = ptr->next;
            ptr->next = second_head;
            ptr->next->next = temp;

            ptr = ptr->next->next;
            second_head = nxt;
        }
    }
};