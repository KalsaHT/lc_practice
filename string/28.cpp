#include "string"
#include<iostream>
#include "vector"

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "") return 0;
        if(haystack == "") return -1;
        if(haystack.size()<needle.size()) return -1;
        
        int i=0;
        int j=0;

        for(int i=0; i <= (haystack.size() - needle.size()); i++){
            int tmp = i;
            if(haystack[tmp] == needle[0]){
                while(j < needle.size() && haystack[tmp++] == needle[j++]); // vector[i++] ,先抽取向量中内容后， i再加1
                if(j == needle.size() && haystack[tmp-1] == needle[j-1]) return (tmp - j); else j=0;
            }
        }
        return -1;
    }
};

int main(){
    int ai[5] = {0, 1, 2, 3, 4};
    vector<int> v(ai, ai+5);
    string s1 = "aaa";
    string s2 = "aaaa";
    
    Solution s;
    cout<<s.strStr(s1, s2)<<endl;
    return -1;
}