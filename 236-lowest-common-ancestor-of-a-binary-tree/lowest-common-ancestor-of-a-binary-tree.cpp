/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

    TreeNode* lca;
    int nodes;

    void dfs(TreeNode* root,TreeNode* p,TreeNode* q,map<int,int>&inorder)
    {
        if(root == NULL || lca != NULL)return;
        if(root->val == p->val || root->val == q->val)
        {
            lca = root;
            return;
        }

        if(inorder[root->val] > inorder[p->val] && inorder[root->val] > inorder[q->val])
        {
            dfs(root->left,p,q,inorder);
        }
        else if(inorder[root->val] < inorder[p->val] && inorder[root->val] < inorder[q->val])
        {
            dfs(root->right,p,q,inorder);
        }
        else
        {
            lca = root;
            return;
        }
    }

    void performInorder(TreeNode* root,map<int,int>&mp)
    {
        if(root == NULL)return;

        performInorder(root->left,mp);
        mp[root->val] = nodes++;
        performInorder(root->right,mp);
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        lca = NULL;
        nodes = 1;

        map<int,int>inorder;  
        performInorder(root,inorder);

        dfs(root,p,q,inorder);  
        return lca;
    }
};