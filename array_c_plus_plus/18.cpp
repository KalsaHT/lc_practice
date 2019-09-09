#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> tmp(4);

        int length = nums.size();
        int target2 = 0;

        for(int i=0; i<length-3; i++){
            tmp[0] = nums[i];
            // cout<<tmp[0]<<endl;
            
            for(int j=i+1; j<length-2; j++){
                tmp[1] = nums[j];
                target2 = target - tmp[0] - tmp[1];
                // cout<<tmp[1]<<endl;
                for(int m=j+1, n=length-1; m<n; ){
                    // cout<<nums[m]<<" "<<nums[n]<<endl;
                    if(nums[m] + nums[n] == target2){
                        tmp[2] = nums[m++];
                        tmp[3] = nums[n--];
                        
                        while(m<n && nums[m] == nums[m-1]) m++;
                        while(m<n && nums[n] == nums[n+1]) n--;
                        result.push_back(tmp);
                    }else if(m<n && nums[m] + nums[n] < target2){
                        m++;
                    }else{
                        n--;
                    } 

                }
                while(j<length-2 && nums[j]==nums[j+1]) j++;
            }
            while(i<length-3 && nums[i] == nums[i+1]) i++;
        }
        return result;
    }
};

int main(){
    int a[] = {3,-1,-2,-2,-4,0,2};
    vector<int> v(a, a+7);
    Solution s;
    vector<vector<int> > r = s.fourSum(v, 6);
    cout<<r.size();
    for(int i=0; i<r.size(); i++){
        for(int j=0; j<r[i].size(); j++){
            cout<<r[i][j]<<" ";
        }
        cout<<" "<<endl;
    }

    return -1;
}