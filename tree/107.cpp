#include "tree.h"
#include<vector>
#include<stack>
#include<queue>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<vector<int> > result;
        stack<vector<int> > result_tmp;
        if(!root) return result;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            vector<int> tmp;
            queue<TreeNode*> que_tmp;
            while(!que.empty()){
                TreeNode* node;
                node = que.front();
                tmp.push_back(node->val);
                que.pop();
                if(node->left != NULL) que_tmp.push(node->left);
                if(node->right != NULL) que_tmp.push(node->right);
            }
            while(!que_tmp.empty()){
                que.push(que_tmp.front());
                que_tmp.pop();
            }
            result_tmp.push(tmp);
        }
        while(!result_tmp.empty()){
            result.push_back(result_tmp.top());
            result_tmp.pop();
        }
        return result;
    }
};


int main(){
    // int a[] = {3,9,20,nullptr,nullptr,15,7};
    // vector<int> t(a, a+7);
    // TreeNode* root = new TreeNode(0);
    // create_tree(root, t);
    // tralevel_cout(root);
    // Solution s;
    // vector<vector<int> > result = s.levelOrderBottom(root);
    // cout<<result.size()<<endl;
    // cout<<result[0].size()<<endl;
    // cout<<result[1].size()<<endl;
    // cout<<result[2].size()<<endl;
    // for(int i=0; i<result.size(); i++){
    //     for(int j=0; j<result[i].size(); j++){
    //         cout<<result[i][j]<<" ";
    //     }
    //     cout<<" "<<endl;
    // }
    return -1;
}