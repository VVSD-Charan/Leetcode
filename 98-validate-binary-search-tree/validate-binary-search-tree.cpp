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

    bool validate(TreeNode* root,long long mini,long long maxi)
    {
        if(root == NULL)return true;
        if(root->val <= mini || root->val >= maxi)return false;

        bool l = validate(root->left,mini,(long long)root->val);
        bool r = validate(root->right,(long long)root->val,maxi);

        return (l && r);
    }

public:
    bool isValidBST(TreeNode* root) 
    {
        long long max_possib = LLONG_MAX;
        long long min_possib = LLONG_MIN;

        return validate(root,min_possib,max_possib);
    }
};