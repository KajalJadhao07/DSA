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


void PreInPostTraversal (Node* root){
    if(root == nullptr){
        return;
    }
    
    vector<int>pre, in, post;
    stack<pair<Node*,int>> stk;
    stk.push({root, 1});
    

    while(!stk.empty()){
        auto it = stk.top();
        stk.pop();
        
        if(it.second == 1){
            pre.push_back(it.first -> data);
            it.second++;
            stk.push(it);
            if(it.first -> left != NULL){
                stk.push({it.first->left, 1});
            }
        }else if(it.second == 2){
            in.push_back(it.first -> data);
            it.second++;
            stk.push(it);
            if(it.first -> right != NULL){
                stk.push({it.first -> right, 1});
            }
        }else{
            post.push_back(it.first -> data);
        }
        

    }
    cout << "Preorder Traversal"<<endl;
    for(int i=0; i<pre.size(); i++){
        cout << pre[i] << " ";
    }
    cout << endl;
    cout << "Inorder Traversal" << endl;
    for(int i=0; i<in.size(); i++){
        cout << in[i] << " ";
    }
    cout << endl;
    cout << "Postorder Traversal" << endl;
    for(int i=0; i<post.size(); i++){
        cout << post[i] << " ";
    }
}



int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);

    PreInPostTraversal(root);
    cout << endl;

    return 0;
}