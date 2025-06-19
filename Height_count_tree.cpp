#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = nullptr;
    }
};
int countNode(Node*root){
    if(root == nullptr){
        return 0;
    }
    return 1+countNode(root->left)+countNode(root->right);
}
int treeHeight(Node*root){
    if(root == nullptr){
        return 0;
    }
    int leftHeight  = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return 1+max(leftHeight,rightHeight);
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(4);
    root->left->left = new Node(5);
    root->left->right = new Node(6);
    root->right->left = new Node(10);
    cout<<"Enter the node: "<<countNode(root)<<endl;
    cout<<"Enter the node: "<<treeHeight(root)<<endl;
    return 0;

}