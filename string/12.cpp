#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;
// using namespace __gnu_cxx;


class Solution {
public:
    string intToRoman(int num) {
       unordered_map<int, string> my_map;
       my_map[1] = "I";
       my_map[5] = "V";
       my_map[10] = "X";
       my_map[50] = "L";
       my_map[100] = "C";
       my_map[500] = "D";
       my_map[1000] = "M";

       int time = 1;
       string roman = "";
       int res;
       string tmp;
       while(num>0){
           res = num%10;
           num = num/10;
           cout<<res<<endl;
           if(res == 9){
               roman = my_map[time] + my_map[time*10] + roman;
           }else if (res >= 5)
           {
                tmp = my_map[time*5];
                res = res - 5;
                while(res>0){
                    tmp = tmp + my_map[time];
                    res--;
                }
                roman = tmp + roman;
            }else if (res==4)
            {
                roman = my_map[time] + my_map[time*5] + roman;   
            }else
            {
                tmp = "";
                while(res>0){
                    tmp = tmp + my_map[time];
                    res--;
                }
                roman = tmp + roman; 
            }
            time = time*10;
       }
       return roman; 
    }
};

int main(){
    int a = 3999;
    Solution s;
    string result = s.intToRoman(a);
    cout<<result;

    return 0;
}