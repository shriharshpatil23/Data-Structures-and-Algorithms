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
public:
    void helper(TreeNode* original, TreeNode* cloned, TreeNode* target,TreeNode * &ans){
        if(original == NULL)    return;
        
        if(original == target){
            ans = cloned;
            return;
        }
        helper(original->left,cloned->left,target,ans);
        helper(original->right,cloned->right,target,ans);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode *ans = new TreeNode();
        helper(original,cloned,target,ans);
        return ans;
    }
};