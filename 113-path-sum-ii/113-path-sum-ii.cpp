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
    void helper(TreeNode * root,int sum,vector<int> &tmp,vector<vector<int>>&ans){
        if(root==NULL ) return;
        
        tmp.push_back(root->val);
        if(root->val==sum && root->left==NULL && root->right==NULL){
            ans.push_back(tmp);
        }
        
        helper(root->left,sum-root->val,tmp,ans);
        helper(root->right,sum-root->val,tmp,ans);
        tmp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> tmp;
        helper(root,targetSum,tmp,ans);
        return ans;
    }
};