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
    ListNode* insertGreatestCommonDivisors(ListNode* head) 
    {
        ListNode* tail = head;

        while(tail -> next)
        {
            int val1 = tail->val;
            int val2 = tail->next->val;

            int mid_val = __gcd(val1,val2);
            ListNode* mid_node = new ListNode(mid_val);

            mid_node -> next = tail->next;
            tail->next = mid_node;

            tail = tail->next->next;
        }    

        return head;
    }
};