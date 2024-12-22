#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <map>

using namespace std;

class Node{
    public:
        Node *left;
        Node *right;
        int data;

        Node(int val){
            this->data=val;
            this->left = NULL;
            this->right=NULL;
        }
};

Node* createtree(){
    cout<<"Enter the Value for the node : "<<endl;
    int val ;
    cin>>val;

    if(val == -1){
        return NULL;
    }

    Node* root = new Node(val);
    cout<<"Entering in left of: "<<val<<endl;
    root->left = createtree();
    cout<<"Entering in right of: "<<val<<endl;
    root->right = createtree();

    return root;
}

void preOrder(Node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<endl;
    preOrder(root->left);
    preOrder(root->right);
}   

void postOrder(Node* root){
    if(root == NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<endl;
}

void inOrder(Node* root){
    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout<<root->data;
    inOrder(root->right);
}

void levelOrderTraversing(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    cout<<endl;
    while(!q.empty()){
        Node* temp =  q.front();
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

void printLeftView(Node* root, int level , vector<int>&leftViewData){
    if(root == NULL){
        return;
    }

    if(level == leftViewData.size()){
        leftViewData.push_back(root->data);
    }

    printLeftView(root->left, level+1,leftViewData);
    printLeftView(root->right,level+1,leftViewData);
}

void printRightView(Node* root , int level, vector<int>&rightViewData){
    if(root==NULL){
        return;
    }

    if(level == rightViewData.size()){
        rightViewData.push_back(root->data);
    }

    printRightView(root->right,level+1,rightViewData);
    printRightView(root->left,level+1,rightViewData);
}

void printTopView(Node* root){

    map<int,int>hd;
    queue<pair<Node*,int>>q;
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node* , int> temp =  q.front();
        q.pop();

        Node* front = temp.first;
        int second = temp.second;

        if(hd.find(second) == hd.end()){
            hd[second] = front->data;
        }

        if(front->left != NULL){
            q.push(make_pair(front->left,second-1));
        }

        if(front->right != NULL){
            q.push(make_pair(front->right,second+1));
        }
    }
    cout<<"Printing Top view"<<endl;
    for(auto i:hd){
        cout<<i.second<<" ";
    }
}

void printBottomView(Node* root){
    map<int,int>hd;
    queue<pair<Node*,int>>q;
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node* , int> temp =  q.front();
        q.pop();

        Node* front = temp.first;
        int second = temp.second;

        hd[second] = front->data;


        if(front->left != NULL){
            q.push(make_pair(front->left,second-1));
        }

        if(front->right != NULL){
            q.push(make_pair(front->right,second+1));
        }
    }
    cout<<"Printing Bottom view"<<endl;
    for(auto i:hd){
        cout<<i.second<<" ";
    }
}

//boundry Traversal

void leftBoundary(Node* root){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        return;
    }
    cout<<root->data<<" ";
    if(root->left != NULL){
        leftBoundary(root->left);
    }
    else{
        leftBoundary(root->right);
    }
}
void rightBoundary(Node* root){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        return;
    }
    if(root->right != NULL){
        rightBoundary(root->right);
    }
    else{
        rightBoundary(root->left);
    }
    cout<<root->data<<" ";

}
void leafBoundary(Node* root){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        cout<<root->data<<" ";
    }
    leafBoundary(root->left);
    leafBoundary(root->right);

}
void BoundaryTraversal(Node* root){
    if(root== NULL)return;
    cout<<root->data<<" ";
    leftBoundary(root->left);
    leafBoundary(root->left);
    leafBoundary(root->right);
    rightBoundary(root->right);
}


int main(){
    Node* root = createtree();
    levelOrderTraversing(root);

    //Left view
    cout<<"Printing Left View : "<<endl;
    vector<int>leftViewData;
    printLeftView(root,0,leftViewData);
    for(auto i : leftViewData){
        cout<<i<<" ";
    }

    //Right view
    cout<<endl;
    cout<<"Printing right View : "<<endl;
    vector<int>rightViewData;
    printRightView(root,0,rightViewData);
    for(auto i : rightViewData){
        cout<<i<<" ";
    }

    //Top view 
    cout<<endl;
    printTopView(root);

    cout<<endl;
    printBottomView(root);

    cout<<endl;
    cout<<"Boundary Traversal : ";
    BoundaryTraversal(root);

return 0;
}

//10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1