#include<vector>
#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > result;
        set<vector<int> > set_result;
        vector<int> tmp;
        dfs(set_result, candidates, tmp, target, 0);
        result.assign(set_result.begin(), set_result.end());
        return result;
             
    }
    //深度优先
    void dfs(set<vector<int>>& set_result, vector<int>& candidates, vector<int> tmp, int target, int idx){
        if(target == 0){
            set_result.insert(tmp);
        } else if(target < 0){
            return;
        } else{
            for(int i=idx; i<candidates.size(); i++){
                // cout<<i<<endl;
                tmp.push_back(candidates[i]);
                // for(int j=0; j<tmp.size(); j++) cout<<tmp[j];
                // cout<<" "<<endl;
                dfs(set_result, candidates, tmp, target - candidates[i], i+1);
                tmp.erase(tmp.end()-1);
            }
        }
    }
};

int main(){
    int a[] = {10,1,2,7,6,1,5};
    vector<int> v(a, a+7);
    Solution s;
    
    vector<vector<int>> result = s.combinationSum2(v, 8);
    // cout<<result.size()<<endl;
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            cout<<result[i][j]<<" ";
        }
    cout<<" "<<endl;
}
    return -1;
}