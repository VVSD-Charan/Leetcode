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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>critical;
        int position = 1;
        int prev = head->val;
        int curr,nxt;

        ListNode* ptr = head->next;
        while(ptr && ptr->next)
        {
            curr = ptr->val;
            nxt = ptr->next->val;

            if(curr > prev && curr > nxt)critical.push_back(position);
            if(curr < prev && curr < nxt)critical.push_back(position);

            prev = ptr->val;
            position = position + 1;
            ptr = ptr->next;
        }

        int max_dist = -1;
        int min_dist = -1;

        if(critical.size() <= 1)return {max_dist,min_dist};

        max_dist = critical.back() - critical[0];
        min_dist = 1e9;

        for(int i = 1 ; i < critical.size() ; i++){
            min_dist = min(min_dist,critical[i]-critical[i-1]);
        }

        return {min_dist,max_dist};
    }
};