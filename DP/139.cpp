/*
 * @Author: httermin
 * @Date: 2019-09-25 11:27:52
 */

#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    // bool wordBreak(string s, vector<string>& wordDict){

    //     vector<bool> dp(s.size()+1, false);
    //     dp[0] = true;
    //     for(int i=1; i<=s.size(); i++){
    //         for(int j=i-1; j>=0; j--){
    //             if(dp[j]){
    //                 // cout<<i<<" "<<j<<endl;
                    
    //                 string tmp = s.substr(j, i-j);
    //                 // cout<<tmp<<endl;
    //                 if(find(wordDict.begin(), wordDict.end(), tmp) != wordDict.end()){
    //                     // cout<<tmp<<endl;
    //                     dp[i] = true;
    //                     break;
    //                 }
    //             }
    //         }
    //     }
    //     return dp[s.size()];
    // }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordDictSet(wordDict.begin(), wordDict.end());
        // return 1;
        return canBrk(0,s,wordDictSet);    
    }
    bool canBrk(int start, string& s, unordered_set<string>& wordDict) {
        int n = s.size();
        if(start == n) return 1;
        string sub;
        cout<<sub<<endl;
        for(int i = start; i<n; i++) if(wordDict.count(sub+=s[i]) && canBrk(i+1,s,wordDict)) return 1;
        return 0;
    }
};

int main(){
    string s = "catsanddog";
    string a1[] = {"cats", "dog", "sand", "and", "cat", "dfee"};

    vector<string> tmp(a1, a1+6);
    Solution ss;
    cout<<ss.wordBreak(s, tmp)<<endl;
    return -1;
}