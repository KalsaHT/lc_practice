/*
 * @Author: httermin
 * @Date: 2019-09-09 23:37:52
 */
#include "string"
#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int length = s.size();
        if(length%2 != 0) return false;
        stack<char> parent;
        for(int i=0;i<s.size();i++){
            switch(s[i]){
            case '(':parent.push(s[i]);break;
            case '[':parent.push(s[i]);break;
            case '{':parent.push(s[i]);break;
            case ')':if(parent.empty() || parent.top()!='(') return false; else parent.pop();break;
            case ']':if(parent.empty() || parent.top()!='[') return false; else parent.pop();break;
            case '}':if(parent.empty() || parent.top()!='{') return false; else parent.pop();break;
            default:;
            }
        }
        return parent.empty();
    }
};


int main(){
    string s = "{}[]([{}])";
    stack<char> parent;
    for (int i=0; i<s.size(); i++){
        switch(s[i]){
            case '(':
            case '[':
            case '{':parent.push(s[i]);break;
        }
    }

    Solution ss;
    cout<<ss.isValid(s)<<endl;
    return -1;
}