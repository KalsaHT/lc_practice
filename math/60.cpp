#include<vector>
#include<iostream>
#include<string>

using namespace std; 

class Solution {
public:
    int s1 = 1;
    string getPermutation(int n, int k) {
        string result="";
        vector<string> v(n);
        for(int i=0; i<n; i++) v[i]=(char)(i+1 + '0');
        if(n == 1) return "1";
        int sn=1, tmp=n;
        while(tmp > 0) sn *= tmp--;
        rec(result, v, n, k, sn);
        return result;

    }
    void rec(string& result, vector<string> v, int n, int k, int sn){
        if(n == 2){
            result = result + v[k/2];
            v.erase(v.begin() + k/2);
            result = result + v[0];
            return;
        }else{
            int sn1 = sn / n,  posi = k/sn1, res = k%sn1;
            if(res == 0) posi--, res=sn1; 
            result = result + v[posi];
            v.erase(v.begin() + posi);
            rec(result, v, n-1, res, sn1);
        }
    }
};


int main(){ 
    int n = 3;
    int k = 6;
    Solution s;
    string result = s.getPermutation(n, k);
    cout<<result<<endl;
    return -1;
}
