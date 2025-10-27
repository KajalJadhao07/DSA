/*Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
The length of a path between two nodes is represented by the number of edges between them.*/

#include <iostream>
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

int findMax(Node* root, int& dia){
    if(root == NULL){
        return 0;
    }
    int lh = findMax(root -> left, dia);
    int rh = findMax(root -> right, dia);
    
    dia = max(dia, lh+rh);
    return 1+max(lh,rh);
};

int DiameterOfBT(Node* root){
    int dia =0;
    findMax(root, dia);
    return dia;
};

int main() {
    // Write C++ code here
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    
    int diameter = DiameterOfBT(root);
    cout<<"Diameter of Binary Tree is: "<<diameter;

    return 0;
}