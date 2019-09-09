#include<vector>
#include<hash_map>

using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        hash_map<int, int> mymap;
        for(int i=0; i<nums.size(); i++){
            mymap[nums[i]]++;
        }
        
    }
};