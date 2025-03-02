#include <iostream>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            this->data=val;
            this->left=NULL;
            this->right=NULL;

        }
};

Node* createTree(){
    cout<<"Enter the value:"<<endl;

    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }

    Node* root = new Node(data);
    cout<<"Left of node "<<root->data<<endl;
    root->left=createTree();
    cout<<"Right of node "<<root->data<<endl;
    root->right=createTree();

    return root;
}
//Pre Order Tree -NLR
void preOrderTraversal(Node* root){
    if(root == NULL){
        return ;
    }

    cout<<root->data<<" ";

    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

//In Order Tree - LNR
void InOrderTraversal(Node* root){
    if(root == NULL){
        return ;
    }

    InOrderTraversal(root->left);
    cout<<root->data<<" ";
    InOrderTraversal(root->right);
}

//Post Order Tree - LNR
void PostOrderTraversal(Node* root){
    if(root == NULL){
        return ;
    }

    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout<<root->data<<" ";
}

void levelOrderTraversal(Node* root){
    queue<Node *>q;
    q.push(root);
    q.push(NULL);

    while(q.size() > 1){
        Node* front = q.front();
        q.pop();
        if(front == NULL){
            cout<<endl;
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
    cout<<endl;
}

int main(){
    Node *root = createTree();

    levelOrderTraversal(root);
    cout<<"Pre Order Tree: ";
    preOrderTraversal(root);
    cout<<endl;

    cout<<"In Order Tree: ";
    InOrderTraversal(root);
    cout<<endl;

    cout<<"Post Order Tree: ";
    PostOrderTraversal(root);
    cout<<endl;
return 0;
}