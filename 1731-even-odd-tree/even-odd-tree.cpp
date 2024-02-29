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

    bool isIncreasing(vector<int>&arr)
    {
        for(int i = 1 ; i < arr.size() ; i++)
        {
            if(arr[i] <= arr[i-1])return false;
        }
        return true;
    }

     bool isDecreasing(vector<int>&arr)
    {
        for(int i = 1 ; i < arr.size() ; i++)
        {
            if(arr[i] >= arr[i-1])return false;
        }
        return true;
    }

public:
    bool isEvenOddTree(TreeNode* root) 
    {
        if(root == NULL)return true;

        int current_level = 1;
        queue<TreeNode*>q;  q.push(root);

        while(q.size() > 0)
        {
            int nodes = q.size();
            vector<int>arr;
            while(nodes--)
            {
                TreeNode* node = q.front(); q.pop();
                arr.push_back(node->val);

                if((current_level % 2) != (node->val % 2))return false;

                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }

            bool isValid = false;
            if(current_level & 1)
            {
                isValid = isIncreasing(arr);
            }
            else
            {
                isValid = isDecreasing(arr);
            }

            if(!isValid)return false;
            current_level = current_level + 1;
        }    

        return true;
    }
};