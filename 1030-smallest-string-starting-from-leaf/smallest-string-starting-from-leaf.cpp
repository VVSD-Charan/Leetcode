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

    void dfs(TreeNode* root,string &str,string &ans)
    {
        if(root == NULL)return;

        if(root->left == NULL && root->right == NULL){
            string temp = str;
            reverse(temp.begin(),temp.end());

            if(ans == "" || ans > temp){
                ans = temp;
            }
            return;
        }

        if(root->left){
            str.push_back('a'+root->left->val);
            dfs(root->left,str,ans);
            str.pop_back();
        }

        if(root->right){
            str.push_back('a'+root->right->val);
            dfs(root->right,str,ans);
            str.pop_back();
        }
    }

    string smallestFromLeaf(TreeNode* root) 
    {
        string str = "";
        string ans = "";

        str.push_back(root->val + 'a');
        dfs(root,str,ans);

        return ans;
    }
};