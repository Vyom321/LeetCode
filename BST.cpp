#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        val = data;
        left = right = nullptr;
    }
};
class BST{
    private:
    Node* root;
    Node* insert(Node* node , int val){
        if(node == nullptr){
            return new Node(val);
        }
        if(val<node->data){
            node->left = insert(node->left,val);
        }else if(val>node->data){
            node->right = insert(node->right, val);
        }
    }
    bool search(Node* node,int key){
        if(node==nullptr){
            return false;
        }if(node->data == key){
            return true;
        }if(key<node->data){
            return search(node->left , key);
        }else{
            return search(node->right,key);
        }
    }
    Node* findnode(Node* node){
        while(node && node->left){   // Keep moving to the left child of the node until you reach the leftmost node end tk chalega 1 dmm.
            node = node->left;
        }
        return node;
    }
    Node* delteNode(Node* node , int key){
        if(node==NULL){
            return node;
        }
        if(key<node->data){
            node->left = delteNode(node->left,key);
        }else if(key>node->data){
            node->right = delteNode(node->right,key);
        }
        else{
            if(!node->left){
                Node* temp = node->right;
                delete node;
                return temp;
            }else if(!node->right){
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findnode(node->right);
            node->data = temp->data;
            node->right = delteNode(node->right , temp->data);
        }
        return node;
    }
    void inorder(Node* node) {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
public:
BST(){
    root = nullptr;

}
void insert(int value) {
        root = insert(root, value);
    }

    bool search(int key) {
        return search(root, key);
    }

    void deleteValue(int key) {
        root = delteNode(root, key);
    }

    void displayInorder() {
        inorder(root);
        cout << endl;
    }
};
int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    cout << "In-order traversal: ";
    tree.displayInorder();

    cout << "Search 40: " << (tree.search(40) ? "Found" : "Not Found") << endl;
    cout << "Delete 40\n";
    tree.deleteValue(40);
    cout << "In-order traversal after deletion: ";
    tree.displayInorder();

    return 0;
}