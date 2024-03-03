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

    void getInorder(TreeNode* root,vector<int>&arr)
    {
        if(root == NULL)return;

        getInorder(root->left,arr);
        arr.push_back(root->val);
        getInorder(root->right,arr);
    }

public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        vector<int>arr1,arr2;
        getInorder(root1,arr1);
        getInorder(root2,arr2);

        vector<int>arr;
        int i = 0;
        int j = 0;

        while(i < arr1.size() && j < arr2.size())
        {
            if(arr1[i] > arr2[j])
            {
                arr.push_back(arr2[j++]);
            }
            else
            {
                arr.push_back(arr1[i++]);
            }
        }    

        while(i < arr1.size())
        {
            arr.push_back(arr1[i++]);
        }

        while(j < arr2.size())
        {
            arr.push_back(arr2[j++]);
        }

        return arr;
    }
};