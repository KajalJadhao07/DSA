/*A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
The path sum of a path is the sum of the node's values in the path.*/

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

int getPathSum(Node* root, int& maxSum){
    if(root == NULL){
        return 0;
    }
    int lh = max(0, getPathSum(root -> left, maxSum));
    int rh = max(0, getPathSum(root -> right, maxSum));
    
    maxSum = max(maxSum, root->data + lh + rh);
    return root->data + max(lh, rh);
};

int findmaxPathSum(Node* root){
    int maxSum = INT_MIN;
    getPathSum(root, maxSum);
    return maxSum;
};

int main() {
    Node* root = new Node(-10);
    root -> left = new Node(9);
    root -> right = new Node(20);
    root -> right -> left = new Node(15);
    root -> right -> right = new Node(7);
    
    int maxSum = findmaxPathSum(root);
    cout<<"Max Path Sum of Binary Tree is: "<<maxSum;

    return 0;
}