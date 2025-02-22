#include <iostream>
#include <vector>
#include <math.h>
#include<queue>

using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            this->data = val;
            this->left=NULL;
            this->right = NULL;
        }

};
Node* insertIntoBST(Node* root,int data){
    if (root == NULL) {
        return new Node(data); // Fix: Create a new node when root is NULL
    }

    if(data > root->data){
        root->right = insertIntoBST(root->right,data);
    }
    else{
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}

void createBST(Node* &root){
    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;

    while(data!=-1){
        root= insertIntoBST(root,data);
        cout<<"Enter the data: "<<endl;
        cin>>data;
    }

}



Node* levelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }


    }
}

void preOrder(Node* root){
    if(root == NULL){
        return ;
    }

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void InOrder(Node* root){
    if(root == NULL){
        return ;
    }

    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}
void postOrder(Node* root){
    if(root == NULL){
        return ;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

Node* minVal(Node* root){
    if(root == NULL){
        cout<<"No min value found !";
        return NULL;
    }

    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }

    return temp;
}
int main(){

    Node* root = NULL;
    createBST(root);
    levelOrderTraversal(root);
    cout<<endl;
    cout<<"PreOrder : ";
    preOrder(root);
    cout<<endl;
    cout<<"InOrder : ";
    InOrder(root);
    cout<<endl;
    cout<<"Post Order : ";
    postOrder(root);
    cout<<endl;
    cout<<"Min value : ";
    Node* minValue = minVal(root);
    if(minVal == NULL)
    {
        cout<<"NO min val found : "<<endl;
    }
    else{
        cout<<minValue->data<<endl;
    }


return 0;
}

//30 20 25 35 10 15 55 50 -1