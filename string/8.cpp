#include <string>
#include <iostream>
#include "math.h"
#include "stdlib.h"

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int index = 0;
        while(str[index] == ' ') index++;
        int positive = 1;
        if(index < str.size() && str[index] == '-'){
            positive = -1;
            index++;
        }else if(index < str.size() && str[index] == '+'){
            positive = 1;
            index++;
        }
        int res = 0;
        while(index<str.size()){
            if(str[index]<'0' || str[index] > '9') {
                return positive*res;
            }
            int digit = str[index] - '0';
            int tmp1 = res*10;
            int tmp2 = tmp1 + digit;
            // cout<<tmp1<<" "<<tmp2<<endl;
            if(tmp1/10 != res || tmp2 < 0){
                if(positive>0) return INT_MAX;
                return INT_MIN;
            }
            res = tmp2;
            index++;
        }
        return positive*res;
    }
};

int main(){
    string s = "123";
    Solution ss;
    int result = ss.myAtoi(s);

    cout<<result;
    return -1;
}