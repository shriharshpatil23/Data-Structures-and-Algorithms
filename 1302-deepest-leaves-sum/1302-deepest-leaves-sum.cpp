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
    
   
    int deepestLeavesSum(TreeNode* root) {
       int sum = 0 ,i;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            for( i=q.size()-1 , sum =0 ; i>=0;--i){
                TreeNode* node = q.front();
                q.pop();
                sum = sum + node->val;
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return sum;
    }
};