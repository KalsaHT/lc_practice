#include<vector>
#include<queue>
#include<iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void create_tree(TreeNode* root, vector<int> v){
    int tmp = v[0];
    root->val = tmp;
    queue<TreeNode*> Queue;
    Queue.push(root);
    int i = 1;
    while(!Queue.empty()){
        TreeNode* node = Queue.front();
        Queue.pop();

        if(node->left == NULL){
            TreeNode* leftNode = new TreeNode(v[i]);
            i++;
            node->left = leftNode;
            Queue.push(leftNode);
            if(i == v.size()) break;
        }
        if(node->right == NULL){
            TreeNode* rightNode = new TreeNode(v[i]);
            i++;
            node->right = rightNode;
            Queue.push(rightNode);
            if(i == v.size()) break;
        }
    }
}


void tralevel_cout(TreeNode* root){
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        TreeNode* node = que.front();
        cout<<node->val<<endl;
        que.pop();
        if(node->left!=NULL){
            que.push(node->left);
        }
        if(node->right!=NULL){
            que.push(node->right);
        }
    }
}