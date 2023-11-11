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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        if(l1 == NULL)return l2;
        if(l2 == NULL)return l1;

        //Head and tail of new linked list
        ListNode* new_head = NULL;
        ListNode* tail = NULL;

        // Temporary pointers to make sure we donot lose lists
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;

        int carry = 0;

        while(ptr1 && ptr2)
        {
            int sum = ptr1->val + ptr2->val + carry;
            carry = (sum / 10);
            sum = (sum % 10);

            if(new_head == NULL)
            {
                new_head = new ListNode(sum);
                tail = new_head;
            }
            else
            {
                tail -> next = new ListNode(sum);
                tail = tail -> next;
            }

            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        while(ptr1)
        {
            int sum = ptr1->val + carry;
            carry = (sum / 10);
            sum = (sum % 10);

            tail -> next = new ListNode(sum);
            tail = tail->next;
            ptr1 = ptr1->next;
        }

        while(ptr2)
        {
            int sum = ptr2->val + carry;
            carry = (sum / 10);
            sum = (sum % 10);

            tail -> next = new ListNode(sum);
            tail = tail -> next;
            ptr2 = ptr2 -> next;
        }

        if(carry > 0)
        {
            tail->next = new ListNode(carry);
        }

        return new_head;
    }
};

// TC : O(n) and SC : O(1)