#include<iostream>

using namespace std;

class Solution {
public:
    double Power(double base, int exponent) {
    	double result=1;
        bool isPositive = exponent>0 ? true:false;
        
        exponent *= isPositive ? 1:-1;
        
        while(exponent>0){
            result *= base;
            exponent--;
        }
        if(!isPositive) result = 1/result;
        return result;
    }
};

int main(){
    int base = 2;
    int exponent = -3;
    Solution s;
    cout<<s.Power(base, exponent);
    return -1;
}