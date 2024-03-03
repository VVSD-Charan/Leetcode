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

    // pairs => {sum below subtree , total nodes before subtree }

    pair<int,int> dfs(TreeNode* root,int &nodes)
    {
        if(root == NULL)return {0,0};

        pair<int,int>left = dfs(root->left,nodes);
        pair<int,int>right = dfs(root->right,nodes);

        int total_sum = left.first + right.first + root->val;
        int total_count = left.second + right.second + 1;

        int average = (total_sum / total_count);
        nodes = nodes + (root->val == average);

        return {total_sum,total_count};
    }

public:
    int averageOfSubtree(TreeNode* root) 
    {
        int total_nodes = 0;
        pair<int,int>p = dfs(root,total_nodes);

        return total_nodes;    
    }
};