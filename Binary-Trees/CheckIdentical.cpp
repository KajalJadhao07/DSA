/*Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.*/

#include <iostream>
#include<climits>
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

bool isSameTree(Node* p, Node*q){
    if(p == NULL || q == NULL){
        return p == q;
    }
    
    return(p->data == q->data && isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
}

int main() {
    Node* p = new Node(1);
    p -> left = new Node(2);
    p -> right = new Node(3);
    
    Node* q = new Node(1);
    q -> left = new Node(2);
    q -> right = new Node(3);
    
    bool ans = isSameTree(p, q);
    cout<<"The tree is identical: "<<ans;

    return 0;
}