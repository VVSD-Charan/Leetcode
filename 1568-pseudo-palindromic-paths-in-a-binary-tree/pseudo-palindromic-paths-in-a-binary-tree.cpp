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

    int isPalindrome(vector<int>&freq)
    {
        int odd = 0;

        for(int i = 1 ; i <= 10 ; i++)
        {
            odd += (freq[i] % 2);
        }

        if(odd > 1)return 0;
        return true;
    }

    int dfs(TreeNode* root,vector<int>&freq)
    {
        if(root->left == NULL && root->right == NULL)
        {
            return isPalindrome(freq);
        }

        int ans = 0;

        if(root->left)
        {
            freq[root->left->val]++;
            ans += dfs(root->left,freq);

            freq[root->left->val]--;
        }

        if(root->right)
        {
            freq[root->right->val]++;
            ans += dfs(root->right,freq);

            freq[root->right->val]--;
        }

        return ans;
    }

public:
    int pseudoPalindromicPaths (TreeNode* root) 
    {
        vector<int>freq(11,0);
        freq[root->val]++;

        return dfs(root,freq);    
    }
};