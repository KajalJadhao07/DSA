#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};


void IterativePreOrderTraversal (Node* root){
    if(root == nullptr){
        return;
    }
    
    vector<int>ans;
    stack<Node*> stk;
    stk.push(root);

    while(!stk.empty()){
        Node* curr = stk.top();
        stk.pop();
        
        ans.push_back(curr->data);
        
        if(curr -> right != NULL){
            stk.push(curr -> right);
        }
        
        if( curr -> left != NULL){
            stk.push(curr -> left);
        }

    }
    
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}



int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);

    cout << "PreOrder traversal: "<<endl;
    IterativePreOrderTraversal(root);
    cout << endl;

    return 0;
}