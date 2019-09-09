#include<iostream>
#include "math.h"
#include<vector>    

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(dividend == INT_MIN && divisor == 1) return INT_MIN;

        long long result=0;
        int is_positive_dividend = dividend>0 ? 1:0;
        int is_positive_divisor = divisor>0 ? 1:0;
        
        long long dividend_ = labs(dividend);
        long long divisor_ = labs(divisor);

        long long i = 1;
        // cout<<dividend_<<endl;

        vector<long long> lists;
        lists.push_back(divisor_);
        while(dividend_ >= divisor_){
            divisor_ += divisor_;
            lists.push_back(divisor_);
            i += i;
            // cout<<i<<endl;
        }
        
        int sum= 0;

        for(int j=lists.size()-1; j>=0; j--){
            
            if(sum + lists[j] <= dividend_){
                // cout<<i<<endl;
                // cout<<lists[j]<<endl;
                result += i;
                sum += lists[j];
                cout<<result<<endl;
            }
            i >>= 1;
            // cout<<i<<endl;

        }

        // cout<<result<<endl;
        if(is_positive_dividend + is_positive_divisor == 1) return -1*result;
        return result;

    }
};

class Solution2 {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        int res = 0;
        while (dvd >= dvs) { 
            long long temp = dvs, multiple = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            res += multiple;
        }
        return sign == 1 ? res : -res; 
    }
};

int main(){

    int a = -2147483648;
    int b = 2;
    // cout<<labs(a)<<endl;

    Solution2 s;
    
    // cout<<labs(a)<<endl;
    int result = s.divide(a, b);
    cout<<result;
    return -1;
}