#include <iostream>
#include <queue>
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


void BFS(Node* root){
    if(root == nullptr){
        return;
    }
    
    vector<vector<int>>ans;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int>level;
        for(int i=0; i<size; i++){
            Node* current = q.front();
            q.pop();
            
            if(current -> left != NULL){
                q.push(current->left);
            }
            if(current -> right != NULL){
                q.push(current -> right);
            }
            
            level.push_back(current -> data);
        }
        ans.push_back(level);

    }
    
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
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

    cout << "BFS traversal: "<<endl;
    BFS(root);
    cout << endl;

    return 0;
}