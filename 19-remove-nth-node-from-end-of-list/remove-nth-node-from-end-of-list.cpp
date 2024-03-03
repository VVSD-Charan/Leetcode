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

    int getLength(ListNode* node)
    {
        int nodes = 0;
        ListNode* temp = node;

        while(temp)
        {
            nodes = nodes + 1;
            temp = temp->next;
        }

        return nodes;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        int lengthOfList = getLength(head);
        if(n == lengthOfList)return head->next;

        lengthOfList = lengthOfList - n - 1;
        ListNode* temp = head;

        while(lengthOfList > 0)
        {
            temp = temp->next;
            lengthOfList = lengthOfList - 1;
        }    

        temp->next = temp->next->next;
        return head;
    }
};