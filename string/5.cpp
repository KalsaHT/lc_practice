#include<string>
#include<iostream>
#include<vector>

using namespace std;

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
class Solution {  
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
    string s = "abba";
    Solution ss;
    cout<<ss.longestPalindrome(s)<<endl;
    return -1;
}