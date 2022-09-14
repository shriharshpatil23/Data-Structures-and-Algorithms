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
    void helper(TreeNode * root, TreeNode *parent,TreeNode * grandParent,int &sum){
        if(root==NULL)  return;
        
        // cout<<root->val<<endl;
        if(grandParent!= NULL && (grandParent->val)%2==0){
            sum+=root->val;
        }
        helper(root->left,root,parent,sum);
        helper(root->right,root,parent,sum);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int sum =0;
        helper(root,NULL,NULL,sum);
        return sum;
    }
};