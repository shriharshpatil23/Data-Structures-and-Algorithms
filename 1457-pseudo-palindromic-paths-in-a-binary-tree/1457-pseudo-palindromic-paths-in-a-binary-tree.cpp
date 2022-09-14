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
    int ans = 0;
    bool isPseudoPalindrome(vector<int>arr){
        map<int,int>mp;
            for(auto y : arr) mp[y]++;
            
            int odd = 0;
            for(auto x : mp){
                if(x.second%2==1 && odd==1)   return false;
                
                if(x.second%2==1 && odd==0) odd++;
            }
        return true;
    }
    void helper(TreeNode * root,map<int,int>&mp){
        if(root==NULL)  return;
        
        //path.push_back(root->val);
        mp[root->val]++;
        
        if(root->left==NULL && root->right==NULL){
            int odd = 0;
            for(auto x : mp)    if(x.second%2==1)   odd++;
            
            if(odd==0 || odd==1)    ans++;
        }
            
        helper(root->left,mp);
        helper(root->right,mp);
        mp[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        map<int,int>mp;
        helper(root,mp);
        return ans;
    }
};