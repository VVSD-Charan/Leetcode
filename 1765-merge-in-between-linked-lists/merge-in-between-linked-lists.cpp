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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) 
    {
        a = a - 1;

        ListNode* tail1 = list1;
        while(a > 0)
        {
            tail1 = tail1->next;
            a = a - 1;
            b = b - 1;
        }

        ListNode* head2 = tail1;
        while(b >= 0)
        {
            head2 = head2->next;
            b = b - 1;
        }

        tail1->next = list2;
        while(tail1->next)
        {
            tail1 = tail1->next;
        }
        tail1->next = head2;

        return list1;
    }
};