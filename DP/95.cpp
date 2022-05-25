/*
 * @Author: httermin
 * @Date: 2019-10-16 19:56:59
 */

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include<vector>

using namespace std;

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return {};
        return genTree(1, n);
    }

    vector<TreeNode*> genTree(int start, int end){
        if(start > end) return {nullptr};
        vector<TreeNode*> result;
        for(int i=start; i<=end; i++){
            auto left = genTree(start, i-1);
            auto right = genTree(i+1, end);
            for(auto a:left){
                for(auto b:right){
                    TreeNode *node = new TreeNode(i);
                    node->left = a;
                    node->right = b;
                    result.push_back(node);
                }
            }
        }
        return result;
    }
};