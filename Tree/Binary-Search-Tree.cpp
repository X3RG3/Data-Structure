#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int val){
    if(!root) return new Node(val);

    if(val < root->data){
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }

    return root;
}

bool search(Node* root, int value){
    if(!root) return false;

    if(root->data == value) return true;

    if(value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

void inorder(Node* root){
    if(root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}



int main(){

    Node* root = nullptr;
    int values[]={2,5,6,2,2,7,4,2};
    for(int i=0; i<7; i++){
        root = insert(root, values[i]);
    }

    cout<<"Inorder :";
    inorder(root);

}