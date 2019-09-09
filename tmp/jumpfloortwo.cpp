#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int jumpFloorII(int number) {
        if(number == 0) return 0;
        if(number == 1) return 1;
        if(number == 2) return 2;

        vector<int> v;
        v.push_back(1);
        v.push_back(2);

        int result = 0;
        int last = 2;
        while(number > 2){
            result = 0;
            for(int i=0; i<v.size(); i++){
                result += v[i];
            }
            result++;
            v.push_back(result);
            number --;
        }
        return result;
    }
};

class Solution2 {
public:
    int jumpFloorII(int number) {
        if(number == 0) return 0;
        if(number == 1) return 1;
        if(number == 2) return 2;


        int result = 0;
        int last = 2;
        while(number > 2){
            result = last*2;
            last = result;
            number--;
        }
        return result;
    }
};

int main(){
    int number = 15;
    Solution ss;
    cout<<ss.jumpFloorII(number)<<endl;
    Solution2 ss2;
    cout<<ss2.jumpFloorII(number);
    return -1;
}