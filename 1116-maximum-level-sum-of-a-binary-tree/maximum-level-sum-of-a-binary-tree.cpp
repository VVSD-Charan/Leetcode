/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) 
    {
        int max_level = 0;
        int curr_level = 1;
        int max_sum = INT_MIN;

        queue<TreeNode*>q;  q.push(root);

        while(q.size())
        {
            int nodes = q.size();
            int curr_sum = 0;

            while(nodes--)
            {
                TreeNode* node = q.front(); q.pop();
                curr_sum += node->val;

                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }

            if(curr_sum > max_sum)
            {
                max_sum = curr_sum;
                max_level = curr_level;
            }

            curr_level++;
        }

        return max_level;
    }
};