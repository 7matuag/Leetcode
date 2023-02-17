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
    void solve(TreeNode* root,int &temp,int &ans){
        if(!root){
            return ;
        }
        solve(root->left,temp,ans);
        if(temp!=-1){
            ans=min(ans,root->val-temp);
        }
        temp=root->val;
        solve(root->right,temp,ans);
    }
    int minDiffInBST(TreeNode* root) {
        int ans=INT_MAX,temp=-1;
        solve(root,temp,ans);
        return ans;
    }
};
