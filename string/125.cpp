#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // remove punctuation
        remove_punc(s);
        // lower case
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        // cout<<s<<endl;
        int lenght = s.size();
        for(int i=0; i<lenght/2; i++){
            if(s[i] != s[lenght-i-1]) return false;
        }
        return true;
    }

    void remove_punc(string& s){
        for(int i=0, len=s.size();i<len; i++){
            if(ispunct(s[i]) || s[i]==' '){
                s.erase(i, 1);
                i--;
                len = s.size();
            }
        }
    }
};


int main(){
    string s = "race a car";
    Solution ss;
    bool result = ss.isPalindrome(s);
    cout<<result<<endl;
    return -1;
}