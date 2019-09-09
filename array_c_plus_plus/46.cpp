#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() <= 1){
            result.push_back(nums);
            return result;
        } 
        vector<int> tmp;   
        dfs(result, nums, tmp);
        return result;     

    }
    void dfs(vector<vector<int>>& result, vector<int> num, vector<int> tmp){
        if(num.size() == 2){
            tmp.push_back(num[0]);
            tmp.push_back(num[1]);
            result.push_back(tmp);

            tmp[tmp.size()-2] = num[1];
            tmp[tmp.size()-1] = num[0];
            result.push_back(tmp);
            return;
        }else{
            for(int i=0; i<num.size(); i++){
                tmp.push_back(num[i]);
                vector<int> num2;
                for(int j=0; j<num.size();j++){
                    if(j!=i) num2.push_back(num[j]);
                }
                dfs(result, num2, tmp);
                tmp.erase(tmp.end()-1);
            }
        }
    }
};
class Solution2 {
public:
    vector<vector<int> > permute(vector<int> &num) {
	    vector<vector<int> > result;
	    
	    permuteRecursive(num, 0, result);
	    return result;
    }
    
    // permute num[begin..end]
    // invariant: num[0..begin-1] have been fixed/permuted
	void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)	{
		if (begin >= num.size()) {
		    // one permutation instance
		    result.push_back(num);
		    return;
		}
		
		for (int i = begin; i < num.size(); i++) {
		    swap(num[begin], num[i]);
		    permuteRecursive(num, begin + 1, result);
		    // reset
		    swap(num[begin], num[i]);
		}
    }
};

int main(){
    int a[] = {1, 2, 3, 4};
    vector<int> v(a, a+4);
    Solution s;
    
    vector<vector<int>> result = s.permute(v);
    cout<<result.size()<<endl;
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            cout<<result[i][j]<<" ";
        }
    cout<<" "<<endl;
}
    return -1;
}