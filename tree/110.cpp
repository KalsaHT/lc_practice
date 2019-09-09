#include "tree.h"
#include<iostream>
#include<cmath>

using namespace std;

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        bool result = true;
        height(root, result);
        return result;     
    }

    int height(TreeNode* node, bool& result){
        if(node == NULL) return 0;
        int leftheight = height(node->left, result);
        int rightheight = height(node->right, result);
        if(abs(leftheight - rightheight)>1) result = false;
        return 1 + max(leftheight, rightheight);
    }
};



void p(bool& r){
    r = false;
}

int main(){
    bool r = true;
    p(r);
    cout<<r<<endl;
    return -1;
}