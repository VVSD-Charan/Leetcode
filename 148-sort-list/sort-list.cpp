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

    ListNode* findMiddle(ListNode* head)
    {
        if(head == NULL || head -> next == NULL)return head;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast -> next)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        return slow;
    }

    ListNode* mergeLists(ListNode* head1,ListNode* head2)
    {
        if(head1 == NULL)return head2;
        if(head2 == NULL)return head1;

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(head1 && head2)
        {
            if(head1->val > head2->val)
            {
                if(head == NULL){
                    head = new ListNode(head2->val);
                    tail = head;
                }else{
                    tail->next = new ListNode(head2->val);
                    tail = tail -> next;
                }
                head2 = head2 -> next;
            }
            else
            {
                if(head == NULL){
                    head = new ListNode(head1 -> val);
                    tail = head;
                }else{
                    tail -> next = new ListNode(head1->val);
                    tail=tail->next;
                }

                head1 = head1->next;
            }
        }

        if(head1){
            tail->next = head1;
        }

        if(head2){
            tail->next = head2;
        }

        return head;
    }

    ListNode* mergeSort(ListNode* head)
    {
        if(head == NULL || head -> next == NULL)return head;

        ListNode* mid = findMiddle(head);

        ListNode* head2 = mid -> next;

        mid -> next = NULL;

        head = mergeSort(head);
        head2 = mergeSort(head2);

        return mergeLists(head,head2);
    }

public:
    ListNode* sortList(ListNode* head) 
    {
       if(head == NULL || head -> next == NULL)return head;

       head = mergeSort(head);

       return head;   
    }
};