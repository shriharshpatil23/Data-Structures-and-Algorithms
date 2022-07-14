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
    
    TreeNode* buildtree_helper(vector<int>& preorder, vector<int>& inorder, int& rootIdx, int left, int right) {
        if (left > right) return NULL;
        int pivot = left;  // find the root from inorder
        while(inorder[pivot] != preorder[rootIdx]) pivot++;
        
        rootIdx++;
        TreeNode* newNode = new TreeNode(inorder[pivot]);
        newNode->left = buildtree_helper(preorder, inorder, rootIdx, left, pivot-1);
        newNode->right = buildtree_helper(preorder, inorder, rootIdx, pivot+1, right);
        return newNode;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIdx = 0;
     //   int end = inorder.size()-1;
        return buildtree_helper(preorder,inorder,rootIdx,0,inorder.size()-1);
    }
};