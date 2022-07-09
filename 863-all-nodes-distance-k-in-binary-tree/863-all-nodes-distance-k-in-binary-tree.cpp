/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void createParent (TreeNode * root, map<TreeNode *, TreeNode *> &m){
        if(root==NULL)  return ;
        queue<TreeNode*> q;
        q.push(root);
        m[root]=NULL;
        while(!q.empty()){
            TreeNode * front = q.front();
            q.pop();
            if(front->left){
                q.push(front->left);
                m[front->left]=front;
            }
            
            if(front->right){
                q.push(front->right);
                m[front->right]=front;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode *, TreeNode *> m;
        map<TreeNode *, bool> vis;
        createParent(root,m);
        vector<int> ans;
        queue<TreeNode *> q;
        q.push(target);
        vis[target]=true;
        int dist = 0;
        while(!q.empty() && k){
            int sz = q.size();
            bool flag = 0;
            while(sz--){
                TreeNode * front = q.front();
                q.pop();
                
                if(front->left && vis[front->left]==false){
                    flag = true;
                    q.push(front->left);
                    vis[front->left]=true;
                }
                if(front->right && vis[front->right]==false){
                    flag = true;
                    q.push(front->right);
                    vis[front->right]=true;
                }
                if(m[front]&&vis[m[front]]==false){
                    flag = true;
                    q.push(m[front]);
                    vis[m[front]]=true;
                }
            }
            
            k --;
    //        if(flag)    dist++;
            
            // if(dist == k){
            //     while(!q.empty()){
            //         ans.push_back(q.front()->val);
            //         q.pop();
            //     }
            // }
        }
            while(!q.empty()){
                    ans.push_back(q.front()->val);
                    q.pop();
                }
        return ans;
    }
};