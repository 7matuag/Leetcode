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
    TreeNode *solve(int i,int j,vector<int>& inorder,vector<int>& postorder,int &k){
        if(i>j){
            return NULL;
        }
        TreeNode *root=new TreeNode(postorder[k--]);
        int itr=i;
        while(itr<=j){
            if(inorder[itr]==root->val){
                break;
            }
            itr++;
        }
        root->right=solve(itr+1,j,inorder,postorder,k);
        root->left=solve(i,itr-1,inorder,postorder,k);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size()-1;
        return solve(0,n,inorder,postorder,n);
    }
};
