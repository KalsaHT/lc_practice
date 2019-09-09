#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        while(n>1){
            string tmp = "";
            // cout<<result.size()<<endl;
            for(int i=0; i<result.size(); i++){
                int count = 1;
                while(result[i] == result[i+1] && i<result.size()){
                    count++;
                    i++;
                }
                // cout<<count<<endl;
                // cout<<result[i]<<endl;
                // cout<<tmp<<endl;
                tmp = tmp + (char)(count +'0') + result[i];
                // cout<<tmp<<endl;
            }
            // cout<<tmp<<endl;
            result = tmp;
            n--;
        }
        return result;
    }
};

class Solution2
{
public:
    string countAndSay(int n)
    {
        string s = "1";
       for(int i = 1; i < n; ++ i)
        {
           int count = 1;
           string temp = "";
            for(int j = 1; j < s.size(); ++ j)
            {
                if(s[j] == s[j - 1])
                    ++ count;
                else
                {
                    temp = temp + (char)(count + '0') + s[j - 1];
                    count = 1;
                }
            }
            s = temp + (char)(count + '0') + s[s.size() - 1];
        }
        return s;
    }
};


int main(){
    int s=7;
    Solution tmp;
    cout<<tmp.countAndSay(s)<<endl;
    return -1;
}

