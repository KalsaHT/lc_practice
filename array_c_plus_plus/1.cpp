#include <vector>
#include<iostream>
#include <algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mymap;
        vector<int> result(2);
        int diff;
        for(int i=0; i<nums.size(); i++){
            diff = target - nums[i];
            if (mymap.find(diff) != mymap.end() && mymap[diff] != i){
                result[1] = i;
                result[0] = mymap[diff];
                return result;
            }else{
                mymap[nums[i]] = i;
            }
        }

        return result;
    }
};

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //sort
        // sort(nums.begin(), nums.end());
        unordered_map<int, int> mymap;
        for(int i=0; i<nums.size(); i++){
            mymap[nums[i]] = i;
        }
        int diff;
        vector<int> result(2);

        for(int i=0; i<nums.size(); i++){
            diff = target - nums[i];
            if (mymap.find(diff) != mymap.end() && mymap[diff] != i){
                result[0] = i;
                result[1] = mymap[diff];
                // cout<<diff<<" "<<i<<" ";
                return result;
            }    
        }

        return result;
    }
};

class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //sort
        // sort(nums.begin(), nums.end());
        int one = -1;
        int two = -1;
        int diff;

        for(int i=0; i<nums.size(); i++){
            diff = target - nums[i];
            for(int j=i+1; j<nums.size(); j++){
                if(nums[j] == diff){
                    
                    one = i;
                    two = j;
                    break;
                    break;
                }
            }
        }
        int myints[] = {one, two};
        vector<int> result(myints, myints+2);
        return result;
    }
};

int main(){
    int A[] = {-1, 1, 3, 2, 4};
    vector<int> nums(A, A+5);
    int target = 6;
    Solution s;
    vector<int> result;
    result = s.twoSum(nums, target);
    for(int i=0; i<2; i++){
        cout<<result[i]<<" ";
    }
    return -1;

}