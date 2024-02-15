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
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode* less_head = NULL;
        ListNode* less_tail = NULL;

        ListNode* great_head = NULL;
        ListNode* great_tail = NULL;

        ListNode* temp = head;

        while(temp)
        {
            if(temp->val < x)
            {
                if(less_head == NULL)
                {
                    less_head = new ListNode(temp->val);
                    less_tail = less_head;
                }
                else
                {
                    less_tail->next = new ListNode(temp->val);
                    less_tail = less_tail->next;
                }
            }
            else
            {
                if(great_head == NULL)
                {
                    great_head = new ListNode(temp->val);
                    great_tail = great_head;
                }
                else
                {
                    great_tail->next = new ListNode(temp->val);
                    great_tail = great_tail->next;
                }
            }
            temp = temp->next;
        }

        if(less_head == NULL)return great_head;
        less_tail->next = great_head;

        return less_head;
    }
};