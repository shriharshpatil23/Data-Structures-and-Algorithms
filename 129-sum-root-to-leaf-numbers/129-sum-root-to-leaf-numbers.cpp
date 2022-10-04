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
    void helper(TreeNode * root,vector<string>&vec,string s){
        if(root==NULL)  return;
        
        string tmp = to_string(root->val);
        char value = tmp[0];
        s.push_back(value);
        if(root->left==NULL && root->right==NULL)   vec.push_back(s);
        
        helper(root->left,vec,s);
        helper(root->right,vec,s);
    }
    int sumNumbers(TreeNode* root) {
        vector<string>vec;
        helper(root,vec,"");
        int ans = 0;
        for(auto x : vec){
            cout<<x<<endl;
        }
        for(auto x : vec){
            if(x.size()>0)  ans += stoi(x);
        }
        return ans;
    }
};