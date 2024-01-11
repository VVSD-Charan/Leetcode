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

    int dfs(TreeNode* root,int max_val,int min_val,int max_diff){
        if(root == NULL)return max_diff;

        max_diff = max(max_diff,max(abs(max_val - root->val),abs(min_val - root->val)));

        max_val = max(max_val, root->val);
        min_val = min(min_val , root->val);

        int left_diff = dfs(root->left,max_val,min_val,max_diff);
        int right_diff = dfs(root->right,max_val,min_val,max_diff);

        return max(left_diff,right_diff);
    }

public:
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root,root->val,root->val,0);
    }
};