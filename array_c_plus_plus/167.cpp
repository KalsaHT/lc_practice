#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        bool stop = false;
        int start = 0;
        int end = numbers.size()-1;
        vector<int> result;
        while(!stop){
            int target_ = target - numbers[start];
            end = find(numbers, target_, start, end);
            if(target_ == numbers[end]){
                result.push_back(start+1);
                result.push_back(end+1);
                stop = true;
            }
            start++;
        }
        return result;
    }

    int find(vector<int>&numbers, int target, int start, int end){
        int i = end;
        for(i; i>start; i--){
            if(numbers[i]==target || numbers[i]<target){
                return i;
            }
        }
        return end;
    }

    vector<int> twoSum2(vector<int>& numbers, int target) {
        
        int l = 0;
        int r = numbers.size() -1;
        while(l < r){
            if(numbers[l] + numbers[r] == target){
                vector<int> res{l+1,r+1};
                return res;
            }
            else if(numbers[l] + numbers[r] > target){
                r--;
            }
            else{
                l++;
            }
        }
    }
};

int main(){
    int a[] = {5, 25, 75};
    vector<int> v(a, a+3);
    Solution s;
    vector<int> result = s.twoSum(v, 100);
    cout<<result[0]<<" "<<result[1]<<endl;

    return -1;
}