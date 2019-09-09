#include<string>
// #include<unordered_map>
#include<iostream>

using namespace std;


// class Solution {
// public:
//     bool isIsomorphic(string s, string t) {
//         if(s.size()!=t.size()) return false;
//         unordered_map<char, char> mymap1;
//         unordered_map<char, char> mymap2;
//         for(int i=0; i<s.size(); i++){
//             //find
//             if(mymap1.find(s[i])!=mymap1.end() && mymap1[s[i]]!=t[i]) return false;
//             if(mymap2.find(t[i])!=mymap2.end() && mymap2[t[i]]!=s[i]) return false;
//             mymap1[s[i]] = t[i];
//             mymap2[t[i]] = s[i];
//         }
//         return true;
//     }
// };


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256] = {0}, m2[256] = {0}, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            cout<<m1[s[i]]<<endl;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};

int main(){
    string s = "title";
    string t = "paper";
    Solution ss;
    cout<<ss.isIsomorphic(s, t);
    return -1;
}