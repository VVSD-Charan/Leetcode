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
    vector<int> rightSideView(TreeNode* root) 
    {
        if(root == NULL)return {};

        queue<TreeNode*>q;  q.push(root);
        vector<int>right;

        while(q.size())
        {
            int nodes = q.size();   
            int last_node = -1;

            while(nodes--)
            {
                TreeNode* node = q.front(); q.pop();
                last_node = node->val;

                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }

            right.push_back(last_node);
        }    

        return right;
    }
};