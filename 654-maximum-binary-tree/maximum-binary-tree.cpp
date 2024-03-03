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

    int getMax(vector<int>&arr,int i,int j)
    {
        int max_index = i;

        for(int x = i + 1 ; x <= j ; x++)
        {
            if(arr[x] > arr[max_index])
            {
                max_index = x;
            }
        }

        return max_index;
    }

    TreeNode* construct(vector<int>&nums,int i,int j)
    {
        if(i > j)return NULL;

        int maximum_index = getMax(nums,i,j);
        TreeNode* current_root = new TreeNode(nums[maximum_index]);

        current_root->left = construct(nums,i,maximum_index-1);
        current_root->right = construct(nums,maximum_index+1,j);

        return current_root;
    }

public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        return construct(nums,0,nums.size()-1);    
    }
};