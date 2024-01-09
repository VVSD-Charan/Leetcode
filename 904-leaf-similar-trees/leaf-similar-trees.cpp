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

    void dfs(TreeNode* root,vector<int>&arr)
    {
        if(root == NULL)return;

        if(root->left == NULL && root->right == NULL){
            arr.push_back(root->val);
            return;
        }

        dfs(root->left,arr);
        dfs(root->right,arr);
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>arr1;
        vector<int>arr2;

        dfs(root1,arr1);
        dfs(root2,arr2);

        if(arr1.size() != arr2.size())return false;

        for(int i = 0 ; i < arr1.size() ; i++)
        {
            if(arr1[i] != arr2[i])return false;
        }

        return true;
    }
};