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
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        queue<TreeNode *>q;
        q.push(root);
        q.push(NULL);
        int ans=1;
        while(q.size() > 1){
            TreeNode* front = q.front();
            q.pop();
            if(front == NULL){
                ans++;
                q.push(NULL);
            }

            else{
                if(front->left != NULL){
                    q.push(front->left);
                }
                if(front->right != NULL){
                    q.push(front->right);
                }
            }
        }
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }

        int left = diameterOfBinaryTree(root->left);
        int right = diameterOfBinaryTree(root->right);
        int both = height(root->left)+height(root->right);
        int ans = max(left,max(right,both));
        return ans;
    }
};