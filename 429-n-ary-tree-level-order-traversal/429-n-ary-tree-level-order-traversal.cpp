/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root==NULL)  return ans;
        queue<Node *> q;
        q.push(root);
        while(!q.empty()){
            int k = q.size();
            vector<int> tmp;
            while(k--){
                Node * fr = q.front();
                q.pop();
                tmp.push_back(fr->val);
                for(auto x : fr->children){
                    if(x)  q.push(x);
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};