#include <iostream>
#include <queue>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

        node(int d){
            data = d;
            left = right = NULL;
        }
};

void inorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);

}

void preorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";

}

node* insertIntoBST(node* root, int data){
    //base case
    if(root == NULL){
        root = new node(data);
        return root;
    }
    if(data > root->data){
        //right part mai insert karna h
        root->right = insertIntoBST(root->right, data);
    } else {
        //left part mai inserrt karna h
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

bool searchInBst(node* root, int data){
    if(root == NULL){return false;}
    if(root->data == data){return true;}
    if(root->data < data){ return searchInBst(root->left, data);}
    else {searchInBst(root->right, data);}
}

void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}

void takeInput(node* &root){
    int data;
    cin >> data;
    while(data != -1){
        root = insertIntoBST(root, data);
        cin >> data;
    }
}
int main(){

   node* root = NULL;
   cout << "Enter data to create BST" << endl;
   takeInput(root);
   cout << "Printing BST" << endl;
   levelOrderTraversal(root);
   cout << "printing preorder" << endl;
   preorder(root);
   cout << endl << "printing postorder" << endl;
   postorder(root);
   cout << endl << "printing inorder" << endl;
   inorder(root);

    return 0;
}