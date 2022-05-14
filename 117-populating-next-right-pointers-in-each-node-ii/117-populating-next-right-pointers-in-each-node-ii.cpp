/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)  return root;
        
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            Node* n = new Node();
            while(sz-->0){
                Node * x = q.front();
                q.pop();
                n->next=x;
                n=n->next;
                
                if(x->left)  q.push(x->left);
                if(x->right) q.push(x->right);
            }
            
        }
        return root;
    }
};