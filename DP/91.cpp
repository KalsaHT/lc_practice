/*
 * @Author: httermin
 * @Date: 2019-09-19 12:04:20
 */

#include<string>
#include<iostream>
#include<vector>

using namespace std;

class Solution2 {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        int lastW = 1;
        if (s.size()<2) return lastW;
        for(int i=1; i< s.size(); i++)
        {   
            int tmp = s[i-1] -'0';
            if(s[i] == '0' && (tmp>2 || tmp == 0)){
                return 0;
            }else if(s[i] == '0'){
                if(lastW > 1) lastW -= 1;
            }else if (atoi(s.substr(i-1, 2).c_str()) <= 26 && tmp != 0)
            {
                lastW += 1;
            }
            cout<<lastW<<" "<<s[i-1]<<endl;

        }
        return lastW;
    }
};

class Solution {
public:
    int numDecodings(string s) {
        int p = 1, pp, n = s.size();
        for(int i=n-1;i>=0;i--) {
            int cur = s[i]=='0' ? 0 : p;
            if(i<n-1 && (s[i]=='1'||s[i]=='2'&&s[i+1]<'7')) cur+=pp;
            pp = p;
            p = cur;
        }
        return s.empty()? 0 : p;   
    }
};

int main(){
    string s = "1212";
    Solution2 ss;
    cout<<ss.numDecodings(s)<<endl;
}