
#include"tree.h"
using namespace std;


class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size() == 0) return NULL;
        // cout<<pre.size()<<endl;
        TreeNode* root = new TreeNode(pre[0]);
        int posi = find(vin, pre[0]);
        // cout<<""<<posi<<endl;

        if(posi == -1) return NULL;
        
        vector<int> leftpre(pre.begin()+1, pre.begin()+posi);
        vector<int> leftvin(vin.begin(), vin.begin()+posi-1);

        // for(int i=0; i<leftpre.size();i++){
        //     cout<<leftpre[i];
        // }
        // cout<<endl;

        vector<int> rightpre(pre.begin()+posi, pre.end());
        vector<int> rightvin(vin.begin()+posi, vin.end());

        root->left = reConstructBinaryTree(leftpre, leftvin);
        root->right = reConstructBinaryTree(rightpre, rightvin);
        return root;
    }
    int find(vector<int> vin, int val){
        for(int i=1; i<=vin.size(); i++){
            if(vin[i-1] == val) return i;
        }
        return -1;
    } 
};


int main(){
    int a[] = {1,2,4,7,3,5,6,8};
    int b[] = {4,7,2,1,5,3,8,6};
    vector<int> v(a, a+8);
    vector<int> v2(b, b+8);
    Solution ss;
    TreeNode * t;
    t = ss.reConstructBinaryTree(v, v2);
    tralevel_cout(t);
    // // cout<<t->val<<endl;
    return -1;
}