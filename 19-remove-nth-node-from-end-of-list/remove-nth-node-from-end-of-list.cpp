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

    int lengthList(ListNode* head)
    {
        if(head == NULL)return 0;

        int counter = 0;
        ListNode* tail = head;

        while(tail)
        {
            counter++;
            tail = tail -> next;
        }

        return counter;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        int len = lengthList(head);

        if(len == n)return head -> next;

        ListNode* tail = head;
        int diff = len - n - 1;

        while(diff--)
        {
            tail = tail -> next;
        }    

        tail -> next = tail -> next -> next;
        return head;
    }
};