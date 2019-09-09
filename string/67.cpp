#include "string"
#include<iostream>
using namespace std;

// class Solution {
// public:
//     string addBinary(string a, string b) {
//         if(a=="") return b;
//         if(b=="") return a;

//         string max_ = a>b ? a:b;
//         string min_ = a>b ? b:a;
        
//         int i = min_.size();

//         char t1 = min_[i];
//         char t2 = max_[i];
//         char t3[] = "0";

//         while(i>=0){
//             if (t1 == '1' && t2 == "1" && t3 == "1"){}
//         }
//     }
// };


int main(){
    string c="101101";
    cout<<c[0] - '0'<<endl;
    return 0;
}