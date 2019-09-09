#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector< vector<int> > result;
        vector<int> tmp(3);
        //排序
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for(int i=0; i<len-2; i++){
            int num = 0 - nums[i];
            tmp[0] = nums[i];
            for(int j=i+1, k=nums.size()-1; j<k; ){
                if(nums[j] + nums[k] == num){
                    tmp[1] = nums[j++];
                    tmp[2] = nums[k--];
                    result.push_back(tmp);

                    while(j<k && nums[j] == nums[j-1]){
                        j++;
                    }
                    while(j<k && nums[k] == nums[k+1]){
                        k--;
                    }
                }else if(nums[j] + nums[k] < num){
                    j++;
                }else{
                    k--;
                }
            }
            while(i<len-2 && nums[i] == nums[i+1]){
                i++;
            }
        }
        return result;
    }
};
class Solution2{
public:
    vector< vector<int> > threeSum(vector<int> &num) {
        vector<int> numSet(3);
        vector< vector<int> > r;
        // 1.排序
        sort(num.begin(), num.end());
        int sum;
        int len = num.size();
        // 2.拿出第一个数，转化为两数和问题。注意外层循环到倒数第三个数即可
        for(int i = 0; i < len-2; i++) {
            sum = 0 - num[i];
            numSet[0] = num[i];
            // 3.两数和问题
            for(int j = i+1, k = len-1; j < k;) {
                if(num[j] + num[k] == sum) {
                    numSet[1] = num[j++];
                    numSet[2] = num[k--];
                    r.push_back(numSet);
                    // 根据题目要求，跳过重复元素
                    while(j < k && num[j] == num[j-1]) 
                        j++;
                    while(j < k && num[k] == num[k+1])
                        k--;
                }
                else if(num[j] + num[k] < sum)
                    j++;
                else 
                    k--;
            }
            while(i < len-2 && num[i+1] == num[i])
                i++;
        }
        return r;
    }
};
int main(){
    int a[] = {};
    vector<int> v(a, a+0);
    Solution s;
    vector<vector<int>> result = s.threeSum(v);
    for(int i=0; i<result.size(); i++){
        for(int j= 0; j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<" "<<endl;
    }
    return -1;
}