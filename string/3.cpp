/*
 * @Author: httermin
 * @Date: 2019-09-09 23:37:52
 */
#include<string>
#include<iostream>
#include <unordered_map>

using namespace std;

class Solution3 {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mymap;

        int maxLength = 0;
        int startIdx = -1;

        for(int i=0; i<s.size();i++){
            
            if(mymap.find(s[i])!=mymap.end()){
                startIdx = max(mymap[s[i]], startIdx);
                
            }
            cout<<startIdx<<endl;
            mymap[s[i]] = i;
            maxLength = max(maxLength, i - startIdx);
        }
        return maxLength;
    }
};

class SolutionOLD {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mymap;
        unordered_map<char, int>::iterator it;
        
        int max_len = 0;
        int i = -1; 
        for(int j=0; j<s.size(); j++){
            
            it = mymap.find(s[j]);
            if(it != mymap.end()){ // 重复
                i = max(it->second, i);
            }
            
            mymap[s[j]] = j;
            max_len = max(max_len, j-i);
            
        }
        return max_len; 
    }
};

int main(){
    string s = "pwwkew";
    Solution3 ss;
    cout<<ss.lengthOfLongestSubstring(s)<<endl;
    return -1;
}