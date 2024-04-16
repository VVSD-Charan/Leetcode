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
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* node = new TreeNode(val);
            node->left = root;

            return node;
        }

        depth = depth - 1;
        queue<TreeNode*>q;      q.push(root);

        while(q.size())
        {
            int nodes = q.size();

            while(nodes--)
            {
                TreeNode* node = q.front();     q.pop();

                if(depth == 1)
                {
                    TreeNode* l = node->left;
                    TreeNode* r = node->right;

                    TreeNode* new_l = new TreeNode(val);
                    TreeNode* new_r = new TreeNode(val);

                    node->left = new_l;
                    node->right = new_r;
                    new_l->left = l;
                    new_r->right = r;
                }

                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }

            depth = depth - 1;
        }

        return root;
    }
};