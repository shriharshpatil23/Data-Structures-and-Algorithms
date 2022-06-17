/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        int cnt;

    void dfs(TreeNode *root, TreeNode *prev, set<TreeNode*> &s)
    {
        if (root != NULL)
        {
            dfs(root->left, root, s);
            dfs(root->right, root, s);

            if (prev == NULL && s.find(root) == s.end() 
                || s.find(root->left) == s.end() || s.find(root->right) == s.end())
            {
                cnt++;
                s.insert(root);
                s.insert(prev);
                s.insert(root->left);
                s.insert(root->right);
            }
        }
    }

    int minCameraCover(TreeNode *root)
    {
        if (root == NULL) return NULL;

        set<TreeNode*> s;
        s.insert(NULL);
        cnt = 0;
        dfs(root, NULL, s);
        return cnt;
    }
};