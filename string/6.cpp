#include<string>
#include<iostream>
#include<vector>    

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;

        vector<int> ass(1, 0);

        string new_string = "";
        new_string += s[0];

        int n = s.size();

        int num_zig = 3+(numRows-3)*2 + 1;
        int tmp = num_zig;

        while(num_zig < n){
            new_string += s[num_zig];
            ass.push_back(num_zig);
            num_zig += tmp;
        }
        
        for(int i=1; i<numRows; i++){
            int num_zig = 3+(numRows-i-3)*2;
            for(int j=0; j<ass.size(); j++){
                int add1 = 0;
                add1 = ass[j] + 1;
                ass[j] = add1;
                
                if(add1<n) new_string += s[add1];

                if(i != numRows-1){
                    int add2 = ass[j] + num_zig + 1;
                    if(add2<n) new_string += s[add2];
                }
            }
        }
        return new_string;
    }
};

int main(){
    string s = "";
    Solution ss;
    cout<<ss.convert(s, 4)<<endl; //PAHNAPLSIIGYIR
    return -1;
}