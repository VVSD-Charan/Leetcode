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
    
    ListNode* reverseList(ListNode* node)
    {
        if(node == NULL || node->next == NULL)return node;

        ListNode* prev = NULL;
        ListNode* curr = node;
        ListNode* nxt = node->next;

        while(nxt)
        {
            curr->next = prev;
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
        }

        curr->next = prev;
        return curr;
    }

    ListNode* removeNodes(ListNode* head) 
    {
        head = reverseList(head);

        int curr_max = head->val;
        ListNode* ptr = head;

        while(ptr && ptr->next)
        {
            if(ptr->next->val < curr_max)
            {
                ptr->next = ptr->next->next;
            }
            else
            {
                curr_max = max(curr_max,ptr->next->val);
                ptr = ptr->next;
            }
        }    

        return reverseList(head);
    }
};