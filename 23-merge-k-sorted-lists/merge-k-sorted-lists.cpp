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

    bool operator()(ListNode* a,ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<ListNode*,vector<ListNode*>,cmp>pq;
        
        for(auto it : lists)
        {
            if(it != NULL)
            {
                pq.push(it);
            }
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(pq.size() > 0)
        {
            ListNode* node = pq.top();  pq.pop();

            if(head == NULL)
            {
                head = new ListNode(node->val);
                tail = head;
            }
            else
            {
                tail -> next = new ListNode(node->val);
                tail = tail -> next;
            }

            node = node -> next;

            if(node)pq.push(node);
        }

        return head;
    }
};