#include "tree.h"
#include<vector>

using namespace std;


class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        if(nums.size() == 1){
            return new TreeNode(nums[0]);
        }
        TreeNode* root;
        int middle = nums.size() / 2;
        root->val = nums[middle];

        vector<int> leftnum(nums.begin(), nums.begin()+middle);
        vector<int> rightnum(nums.begin()+middle+1, nums.end());

        root->left = sortedArrayToBST(leftnum);
        root->right = sortedArrayToBST(rightnum);

        return root;
    }

    // void setval(TreeNode* parent, vector<int>& num){
    //     if(num.size() == 0) return NULL;
    //     if(num.size() == 1){
    //         parent->val = num[0];
    //         return;
    //     }
    //     int posi = num.size() / 2;
    //     parent->val = num[posi];

    //     setval(parent->left, leftnum);
    //     setval(parent->right, rightnum);
    // }
};