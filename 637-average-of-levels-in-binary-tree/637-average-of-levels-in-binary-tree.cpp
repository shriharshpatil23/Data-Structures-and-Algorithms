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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            double sum = (double)0;
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode * fr = q.front();
                q.pop();
                sum += (double)fr->val;
                if(fr->left)    q.push(fr->left);
                if(fr->right)   q.push(fr->right);
            }
            sum /=n;
            ans.push_back(sum);
        }
        return ans;
    }
};