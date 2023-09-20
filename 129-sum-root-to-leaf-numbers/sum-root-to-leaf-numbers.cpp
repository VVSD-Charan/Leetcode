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

    int dfs(TreeNode* root,int sum)
    {
        if(root->left == NULL && root->right == NULL)return sum;

        int total_sum = 0;

        if(root->left)
        {
            total_sum += dfs(root->left,sum*10 + root->left->val);
        }
        if(root->right)
        {
            total_sum += dfs(root->right,sum*10 + root->right->val);
        }

        return total_sum;
    }

public:
    int sumNumbers(TreeNode* root) 
    {
        return dfs(root,root->val);    
    }
};