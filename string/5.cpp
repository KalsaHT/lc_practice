/*
 * @Author: httermin
 * @Date: 2019-09-09 23:37:52
 */
#include<string>
#include<iostream>
#include<vector>

using namespace std;

class Solution5{
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxBegin = 0;
        int maxLen = 1;
        bool table[1000][1000] = {false};

        for (int i = 0; i < n; i++) {
            table[i][i] = true;
        }

        for (int i = 0; i < n-1; i++) {
                if (s[i] == s[i+1]) {
                table[i][i+1] = true;
                maxBegin = i;
                maxLen = 2;
            }
        }
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i < n-len+1; i++) {
                int j = i+len-1;
                if (s[i] == s[j] && table[i+1][j-1]) {
                    table[i][j] = true;
                    maxBegin = i;
                    maxLen = len;
                }
            }
        }
        return s.substr(maxBegin, maxLen);
    }
};

class Solution {
    //dynamic progame
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 0) return s;
        bool table[n][n]={false};
        
        int maxLens = 1, begin=0;

        //initialize diagonal line and t[i][i+1]
        for (int i=0; i<n; i++){
            table[i][i] = true;
            if(i < n-1){
                if(s[i] == s[i+1]){
                    table[i][i+1] = true;
                    maxLens = 2;
                    begin = i;
                }
            }
        }
        
        int j;
        // start with length 3
        for(int lens=3; lens<=n; lens++){
            for(int i=0; i<n + 1-lens; i++){
                j = i  + lens - 1;
                // cout<<j<<" "<<i<<endl;

                if(s[i] == s[j] && table[i+1][j-1]){
                    table[i][j] = true;
                    begin = i;
                    maxLens = lens;
                    }
            }
        }
        return s.substr(begin, maxLens);
        
    }
};

class Solution4 {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int end = 0;
        
        int len1;
        int len2;
        int len;
        for(int i=0; i<s.size(); i++){
            len1 = getLongestLength(s, i, i);
            len2 = getLongestLength(s, i, i+1);
            len = max(len1, len2);
            
            if(len > (end - start + 1)){
                end = i + len/2;
                start = end - len + 1;
                cout<<start<<" "<<len<<" "<<i<<" "<<end<<endl;
            }
        }
        cout<<start<<" "<<end<<endl;
        return s.substr(start, end - start + 1);
    }

    int getLongestLength(string s, int left, int right){
        
        while(left>=0 && right<s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        return right - left - 1;
    }
};

class Solution2 {
public:
    string longestPalindrome(string s) {
        string new_string = setString(s);
        vector<int> v;
        v.push_back(0);

        int mx=0, id=0;

        for(int i=1; i<new_string.size(); i++){
            
            v[i] = mx>i ? min(v[2*id - i], mx-i):1;
            while(new_string[i+v[i]] == new_string[i-v[i]]) v[i]++;

            //更新 mx id
            if(i+v[i]>mx){
                mx = i+v[i];
                id = i;
            }
        }
        
        int max_len = 0;
        int po = 0;
        for(int i=0; i<v.size(); i++){
            po = max_len>v[i] ? po:i;
            max_len = max(max_len, v[i]);
        }
        return s.substr((po-max_len)/2, max_len);
    }

    string setString(string s){
        string new_string = "$#";
        for(int i=0; i<s.size(); i++){
            new_string = new_string + s[i] + '#';
        }
        new_string += '^';
        return new_string;
    }
};
class Solution3 {  
public:  
    string longestPalindrome(string s) {  
        const int len = s.size();  
        if(len <= 1)return s;  
        //Manncher算法 ，o（n）  
        string str = preProcess(s);  
        int n = str.size(), id = 0, mx = 0;  
        vector<int>p(n, 0);  
        for(int i = 1; i < n-1; i++)  
        {  
            p[i] = mx > i ? min(p[2*id-i], mx-i) : 1;  
            //if(mx <= i || (mx > i && p[2*id-i] == mx - i)) //根据正文斜体部分的注释，这里可要可不要  
            while(str[i+p[i]] == str[i-p[i]])p[i]++;  
            if(i + p[i] > mx)  
            {  
                mx = i + p[i];  
                id = i;  
            }  
        }  
           
        //遍历p，寻找最大回文长度  
        int maxLen = 0, index = 0;  
        for(int i = 1; i < n-1; i++)  
            if(p[i] > maxLen)  
            {  
                maxLen = p[i];  
                index = i;  
            }  
        cout<<maxLen<<endl;
        return s.substr((index - maxLen)/2, maxLen-1);  
    }  
    //预处理字符串，abc预处理后变成$#a#b#c#^  
    string preProcess(const string &s)  
    {  
        int n = s.size();  
        string res;  
        res.push_back('$');//把$放到字符串头部  
        res.push_back('#');//以#作为原来字符串中每个字符的间隔  
        for(int i = 0; i < n; i++)  
        {  
            res.push_back(s[i]);  
            res.push_back('#');  
        }  
        res.push_back('^');//以^作为字符串的结尾  
        return res;  
    }  
};  

int main(){
    string s = "ccc";
    Solution ss;
    cout<<ss.longestPalindrome(s)<<endl;
    return -1;
}