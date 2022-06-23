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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)    return ans;
        queue<TreeNode * > q;
        q.push(root);
        vector<int> curr;
        while(!q.empty()){
            int k = q.size();
            while(k--){
                TreeNode * node = q.front();
                q.pop();
                curr.push_back(node->val);
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(curr);
            curr={};
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};