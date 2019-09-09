#include "tree.h"
#include<iostream>
#include<cmath>

using namespace std;

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL) return 1 + minDepth(root->right);
        if(root->right == NULL) return 1 + minDepth(root->left);
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        return 1 + min(left, right);
    }
};