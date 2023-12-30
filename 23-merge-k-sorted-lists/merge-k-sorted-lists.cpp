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

class cmp
{
    public :

    bool operator()(ListNode* l1,ListNode* l2)
    {
        return (l1->val > l2->val);
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<ListNode*,vector<ListNode*>,cmp>pq;

        for(auto it : lists)
        {
            if(it == NULL)continue;
            pq.push(it);
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(pq.size() > 0)
        {
            ListNode* node = pq.top();  pq.pop();
            if(node->next)pq.push(node->next);

            node->next = NULL;

            if(head == NULL)
            {
                head = node;
                tail = head;
            }
            else
            {
                tail->next = node;
                tail = tail->next;
            }
        }

        return head;
    }
};