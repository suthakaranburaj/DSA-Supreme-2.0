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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p ) return p;
        if(root == NULL) return NULL;
        if(root == q) return q;

        TreeNode* leftAns = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);

        if(leftAns == NULL && rightAns == NULL){
            return NULL;
        }
        else if(rightAns != NULL && leftAns == NULL){
            return rightAns;
        }
        else if(rightAns == NULL && leftAns != NULL){
            return leftAns;
        }

        return root;
    }
};