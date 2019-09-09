#include<iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n == 1) return x;
        if(n < 0){
            x = 1 / x;
            n = -1*n;
        }

        int t = n / 2;
        double result = myPow(x, t);
        if(n % 2 == 0) return result*result;
        return result*result*x;
    }
};

int main(){
    double x = 2.0;
    Solution s;
    double result = s.myPow(x, -10000);
    cout<<result<<endl;
    return -1;
}