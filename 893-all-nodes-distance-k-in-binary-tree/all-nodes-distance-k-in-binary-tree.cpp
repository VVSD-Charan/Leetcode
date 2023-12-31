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

    void dfs(TreeNode* root,map<int,TreeNode*>&parent)
    {
        if(root == NULL)return;

        if(root->left)parent[root->left->val]=root;
        if(root->right)parent[root->right->val]=root;

        dfs(root->left,parent);
        dfs(root->right,parent);
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        if(root == NULL || target == NULL)return {};

        map<int,TreeNode*>parent;
        set<int>s;  s.insert(target->val);
        parent[root->val] = NULL;
        dfs(root,parent);

        queue<TreeNode*>q;  q.push(target);

        while(q.size())
        {
            int nodes = q.size();
            vector<int>arr;

            while(nodes--)
            {
                TreeNode* node = q.front(); q.pop();
                arr.push_back(node->val);

                if(node->left && s.find(node->left->val) == s.end())
                {
                    s.insert(node->left->val);
                    q.push(node->left);
                }

                if(node->right && s.find(node->right->val) == s.end())
                {
                    s.insert(node->right->val);
                    q.push(node->right);
                }

                if(parent[node->val] && s.find(parent[node->val]->val) == s.end())
                {
                    s.insert(parent[node->val]->val);
                    q.push(parent[node->val]);
                }
            }

            if(k == 0)return arr;
            k--;
        }

        return {};
    }
};