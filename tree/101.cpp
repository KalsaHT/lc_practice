#include<iostream>
#include<vector>
#include "tree.h"

using namespace std;

class Solution { //使用对称
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        if(root->left==NULL && root->right==NULL) return true;
        vector<TreeNode*> l;
        l.push_back(root);
        bool stop = false;
        bool symmetric;
        while(stop){
            symmetric = _isSymmetric(l);
            if(!symmetric){
                stop = true;
            } else{
                vector<TreeNode*> tmp;
                TreeNode* t;
                for(int i=0; i<l.size(); i++){
                    t = l[i];
                    if(t != NULL){
                        tmp.push_back(t->left);
                        tmp.push_back(t->right);
                    }
                l = tmp;
                }
            }
            int null_num=0;
            TreeNode* t2;
            for(int i=0; i<l.size(); i++){
                t2 = l[i];
                if(!t2) null_num++;
            }
            if(null_num == l.size()) stop=true;
        }
        return symmetric;
    }

    bool _isSymmetric(vector<TreeNode*> l){
        int size = l.size();
        if(size == 1) return true;
        bool result=true;
        for(int i=0; i<size/2; i++){
            if(l[i]->val != l[size-i]->val) result = false;
        }
        return result;
    }
};

class Solution2 { // 使用两个队列
public:
    bool isSymmetric(TreeNode *root) {
        TreeNode *left, *right;
        if (!root)
            return true;
        
        queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        while (!q1.empty() && !q2.empty()){
            left = q1.front();
            q1.pop();
            right = q2.front();
            q2.pop();
            if (NULL == left && NULL == right)
                continue;
            if (NULL == left || NULL == right)
                return false;
            if (left->val != right->val)
                return false;
            q1.push(left->left);
            q1.push(left->right);
            q2.push(right->right);
            q2.push(right->left);
        }
        return true;
    }
};


int main(){
    int a[] = {1, 2, 2, NULL, 3, NULL, 3};
    vector<int> v(a, a+7);
    TreeNode* root = new TreeNode(0);
    create_tree(root, v);
    // cout<<root->val<<endl;
    // tralevel_cout(root);
    // if(root->left==NULL) cout<<1;
    // cout<<root->left->val;
    // cout<<root->val<<endl;
    Solution2 s;
    bool sy = s.isSymmetric(root);
    cout<<sy<<endl;
    return -1;
}

