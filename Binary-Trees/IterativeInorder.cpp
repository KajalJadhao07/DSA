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


void IterativeInOrderTraversal (Node* root){
    if(root == nullptr){
        return;
    }
    
    vector<int>ans;
    Node* curr = root;
    stack<Node*> stk;

    while(curr != nullptr || !stk.empty()){
        while(curr != NULL){
            stk.push(curr);
            curr = curr->left;
        }
        
        curr = stk.top();
        stk.pop();
        ans.push_back(curr -> data);
        
        curr = curr -> right;
        

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

    cout << "Iterative Inorder traversal: "<<endl;
    IterativeInOrderTraversal(root);
    cout << endl;

    return 0;
}