#include<string>
#include<iostream>
#include <unordered_map>

using namespace std;

class Solution {
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