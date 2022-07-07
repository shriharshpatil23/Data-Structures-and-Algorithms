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
    int maxLevelSum(TreeNode* root) {
        if(root==NULL)  return 0;
        queue<TreeNode * > q;
        q.push(root);
        int ans_sum = INT_MIN;
        int ans_level;
        int level = 0;
        while(!q.empty()){
            int k = q.size();
            int sum  =0;
            level++;
            while(k--){
                TreeNode * node = q.front();
                q.pop();
                sum += node->val;
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
           if(sum>ans_sum){
               ans_sum = sum;
               ans_level = level;
           }
        }
        return ans_level;
    }
};