#include<string>
#include<queue>
#include<iostream>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int i = 0; 
        int j = s.size()-1;
        while(i < j){
            while(!isVowels(s[i])&&i<j) i++;
            while(!isVowels(s[j])&&i<j) j--;
            if(i<j) swap(s[i++], s[j--]);
        }
        return s;
    }
    
    bool isVowels(char c){
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};

int main(){
    string s="leetcode";
    Solution ss;
    cout<<ss.reverseVowels(s)<<endl;
    return -1;
}