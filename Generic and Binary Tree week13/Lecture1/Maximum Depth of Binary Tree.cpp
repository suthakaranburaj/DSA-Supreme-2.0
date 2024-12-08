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
    queue<Node *>q;
    q.push(root);
    q.push(NULL);
    int ans=1;
    while(q.size() > 1){
        Node* front = q.front();
        q.pop();
        if(front == NULL){
            ans++;
            q.push(NULL);
        }

        else{
            cout<<front->data<<" ";
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