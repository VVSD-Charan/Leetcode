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

    bool validate(TreeNode* root,long mini,long maxi)
    {
        if(root == NULL)return true;
        if(root->val <= mini || root->val >= maxi)return false;

        bool l = validate(root->left,mini,(long)root->val);
        bool r = validate(root->right,(long)root->val,maxi);

        return (l && r);
    }

public:
    bool isValidBST(TreeNode* root) 
    {
        long max_possib = LONG_MAX;
        long min_possib = LONG_MIN;

        return validate(root,min_possib,max_possib);
    }
};