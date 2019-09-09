#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > result;
        vector<int> tmp;
        dfs(result, candidates, tmp, target, 0);
        return result;
             
    }
    //深度优先
    void dfs(vector<vector<int>>& result, vector<int>& candidates, vector<int> tmp, int target, int idx){
        if(target == 0){
            result.push_back(tmp);
        } else if(target < 0){
            return;
        } else{
            for(int i=idx; i<candidates.size(); i++){
                // cout<<i<<endl;
                tmp.push_back(candidates[i]);
                // for(int j=0; j<tmp.size(); j++) cout<<tmp[j];
                // cout<<" "<<endl;
                dfs(result, candidates, tmp, target - candidates[i], i+1);
                tmp.erase(tmp.end()-1);
            }
        }
    }
};

int main(){
    int a[] = {2, 3, 4, 7};
    vector<int> v(a, a+4);
    Solution s;
    
    vector<vector<int>> result = s.combinationSum(v, 7);
    // cout<<result.size()<<endl;
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            cout<<result[i][j]<<" ";
        }
    cout<<" "<<endl;
}
    return -1;
}