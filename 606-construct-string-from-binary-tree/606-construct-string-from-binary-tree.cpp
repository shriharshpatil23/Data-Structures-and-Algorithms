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
    void helper(TreeNode * root, string &s){
        if(root==NULL)  return ;
        
        string data = to_string(root->val);
        s+= data;
        if(root->left){
            s.push_back('(');
            helper(root->left,s);
            s.push_back(')');   
        }
        if(root->right){
            if(!root->left)  s+="()";
            s.push_back('(');
            helper(root->right,s);
            s.push_back(')');
        }
    }
    string tree2str(TreeNode* root) {
        string s ="";
        helper(root,s);
        return s;
    }
};