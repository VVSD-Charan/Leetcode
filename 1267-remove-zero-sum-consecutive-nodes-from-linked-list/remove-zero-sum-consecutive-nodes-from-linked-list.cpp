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
    ListNode* removeZeroSumSublists(ListNode* head) 
    {
        ListNode* new_head = NULL;
        ListNode* tail = NULL;

        for(ListNode* i = head ; i != NULL ; i = i->next)
        {
            int total_sum = 0;
            bool can_select = true;

            for(ListNode* j = i ; (j != NULL && can_select) ; j = j->next)
            {
                total_sum += (j->val);

                if(total_sum == 0){
                    can_select = false;
                    i = j;
                }
            }

            if(can_select)
            {
                if(new_head != NULL)
                {
                    tail->next = new ListNode(i->val);
                    tail = tail->next;
                }
                else
                {
                    new_head = new ListNode(i->val);
                    tail = new_head;
                }
            }
        }

        return new_head;    
    }
};