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
    void helper(TreeNode * root, vector<string>&vec,string s){
        if(root==NULL)  return;
        
        int val = root->val;
        char c = 'a'+val;
        s.push_back(c);
        
        if(root->left==NULL && root->right==NULL){
            vec.push_back(s);
        }
        
        helper(root->left,vec,s);
        helper(root->right,vec,s);
    }
    string smallestFromLeaf(TreeNode* root) {
        vector<string> vec;
        helper(root,vec,"");
        for(int i=0;i<vec.size();i++){
            reverse(vec[i].begin(),vec[i].end());
        }
        sort(begin(vec),end(vec));
        return vec[0];
    }
};