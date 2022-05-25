/*
 * @Author: httermin
 * @Date: 2019-09-18 14:06:49
 */

#include<iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int pre = 2, prepre = 1;
        if(n == 1) return pre;
        if(n == 2) return pre;
        
        int result;
        for(int i=3; i<=n; i++){
            result = prepre + pre;
            prepre = pre;
            pre = result;

        }
        return pre;
    }
};

int main(){
    Solution ss;
    cout<<ss.climbStairs(5)<<endl;
}