#include<iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return true;
        int high = num / 2;
        int low = 0;
        while(low <= high){
            long mid = (high + low) / 2;
            long result = mid*mid;
            if(result == num) return true;
            if(result>num) high=mid-1;
            if(result<num) low = mid+1;

        }
        return false;
    }
};

int main(){
    int i = 808201;
    Solution s;
    cout<<s.isPerfectSquare(i)<<endl;
    return -1;
}