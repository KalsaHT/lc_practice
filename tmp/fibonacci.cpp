#include<iostream>

using namespace std;

class Solution1 {
public:
    int Fibonacci(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        return Fibonacci(n-1) + Fibonacci(n-2);
    }
};

class Solution {
public:
    int Fibonacci(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        int f0 = 0;
        int f1 = 1;

        int f = 0;
        while(n>1){
            // cout<<n<<endl;
            f = f0 + f1; 
            cout<<f<<endl;
            f0 = f1;
            f1 = f;
            n--;
        }
        return f;
    }
};

int main(){
    Solution ss;
    cout<<ss.Fibonacci(39);
    return -1;
}