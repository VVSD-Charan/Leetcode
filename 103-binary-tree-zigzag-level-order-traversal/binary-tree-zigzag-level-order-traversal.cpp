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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        if(root == NULL)return {};

        vector<vector<int>>arr;

        stack<TreeNode*>s1;
        stack<TreeNode*>s2;    

        s1.push(root);

        while(s1.size() > 0 || s2.size() > 0)
        {
            vector<int>odd_level;
            vector<int>even_level;

            while(s1.size() > 0)
            {
                TreeNode* node = s1.top();  s1.pop();

                odd_level.push_back(node->val);

                if(node->left)s2.push(node->left);
                if(node->right)s2.push(node->right);
            }

            while(s2.size() > 0)
            {
                TreeNode* node = s2.top();  s2.pop();

                even_level.push_back(node->val);

                if(node->right)s1.push(node->right);
                if(node->left)s1.push(node->left);
            }

            if(odd_level.size() > 0)arr.push_back(odd_level);
            if(even_level.size() > 0)arr.push_back(even_level);
        }

        return arr;
    }
};