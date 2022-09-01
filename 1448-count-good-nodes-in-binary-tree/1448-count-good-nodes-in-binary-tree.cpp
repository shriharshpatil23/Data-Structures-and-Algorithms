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
    //------ Solution 1 : ------------//
//     int helper(TreeNode * root , int mx){
//         if(root==NULL)  return 0;
        
//         int cnt = 0;
//         if(root->val >= mx) cnt++;
//         int curr_max = max(root->val,mx);
//         cnt += helper(root->left,curr_max);
//         cnt += helper(root->right,curr_max);
        
//         return  cnt;
    
//     }
    // --------Solution 2 : -----------//
    
    
//     int ans = 0;
//     void preOrder(TreeNode * root, int max){
//         if(root==NULL)  return;
        
//         if(root->val >= max)    ans++ , max = root->val;
//         preOrder(root->left,max);
//         preOrder(root->right,max);
//     }
    
    // -------------- Solution 3 : ------------//
    
    
    int helper(TreeNode * root, int mx){
        if(root==NULL)  return 0;
        
        if(root->val>=mx){
            return 1 + helper(root->left,root->val)+helper(root->right,root->val);
        }
        return helper(root->left,mx)+helper(root->right,mx);
    }
    
    int goodNodes(TreeNode* root) {
        // return helper(root,INT_MIN);         // Sol : 1
        // preOrder(root,INT_MIN);              // Sol : 2
        // return ans;
        return helper(root,INT_MIN);            // Sol : 3
    }
};