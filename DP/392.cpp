/*
 * @Author: httermin
 * @Date: 2019-09-18 15:19:41
 */

#include <vector>
#include<iostream>
#include <algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        string tmp = t;
        int lastposi = 0;
        for (int i = 0; i < s.size(); i++)
        {   
            
            char c = s[i];
            int posi = findChar(c, tmp);
            
            if(posi != -1){
                tmp = t.substr(lastposi + posi + 1, t.size() - i - posi - 1);
                lastposi = lastposi + posi + 1;
                // cout<<tmp<<endl;
                // cout<<lastposi<<" "<<posi<<endl;
            }else{
                return false;
            }
        }
        
        return true;
    }

    int findChar(char c, string t){
        for (int i=0; i<t.size(); i++){

            if (c == t[i])
            {
                // cout<<c<<" "<<t[i]<<endl;
                return i;
            }
            
        }
        return -1;
    }
};

int main(){
    string s1 = "axc";
    string s2 = "ahbgdc";
    Solution solu;
    cout<<solu.isSubsequence(s1, s2)<<endl;
    return -1;
}