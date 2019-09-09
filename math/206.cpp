#include<vector>
#include<iostream>
#include<cmath>
using namespace std;


class Solution2 { // time out of limited
public:
    int countPrimes(int n) {
        vector<int> result;
        for(int i=2; i<n; i++) result.push_back(i);
        int i = 0;
        int len = result.size();
        while(i<len && result[i]<sqrt(n)){
            result = delNums(i, result);
            i++;
            len = result.size();
        }
        return len;
    }
    vector<int> delNums(int posi, vector<int> v){
        int num = v[posi];
        int len = v.size();
        for(int i=len-1; i>posi; i--){
            if(v[i]%num == 0){
                v.erase(v.begin()+i);
            }
        }
        // cout<<posi<<" "<<v.size()<<endl;
        return v;
    }
};


class Solution {
public:
    int countPrimes(int n) {
        bool* result = new bool[n];
        result[2] = true;
        
        for(int i=3; i<n; i++){
            if(i%2 == 0) result[i] = false;else result[i] = true;
        }

        for(int i=3; i<sqrt(n); i++){
            if(result){
                for(int j=i; i*j<n; j++){
                    result[i*j] = false;
                }
            }
        }

        int count = 0;
        for(int i=2; i<n; i++){
            if(result[i]) count++;
        }
        return count;
    }
};

int main(){
    int n=10;
    Solution s;
    cout<<s.countPrimes(n);
    // int a[] = {1,2,3,4};
    // // vector<int> b(a, a+4);
    // // b.erase(b.begin()+2);
    // // cout<<b.size();
    return -1;
}