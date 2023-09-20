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
    vector<int> largestValues(TreeNode* root) 
    {
        if(root == NULL)return {};

        vector<int>maxNodes;
        queue<TreeNode*>q;    q.push(root);

        while(q.size())
        {
            int nodes = q.size();
            long long maxi = LLONG_MIN;

            while(nodes--)
            {
                TreeNode* node = q.front(); q.pop();
                maxi = max(maxi , (long long)node->val);

                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }

            maxNodes.push_back((int)maxi);
        }

        return maxNodes;    
    }
};