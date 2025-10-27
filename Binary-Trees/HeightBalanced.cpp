/*A height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differs by more than one.*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

int check(Node* curr){
    if(curr == NULL){
        return 0;
    }
    
    int lh = check(curr -> left);
    if(lh == -1){
        return -1;
    }
    
    int rh = check(curr -> right);
    if(rh == -1){
        return -1;
    }
    
    if(abs(lh-rh) > 1){
        return -1;
    }
    
    return 1+ max(rh,lh);
};

bool HeightBalanced (Node* root){
    return check(root) != -1;
};

int main() {
    Node* root = new Node(1);
    root -> left = new Node(2);
    root-> left -> left = new Node(3);
    root -> left -> right = new Node(4);
    root -> right = new Node(5);
    root -> right -> left = new Node(6);
    
    cout<< "The tree is height balanced: "<<endl;
    bool ans = HeightBalanced(root);
    cout<< ans;
    return 0;
}